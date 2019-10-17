// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_LOG_NET_LOG_H_
#define NET_LOG_NET_LOG_H_

#include <string>
#include <vector>

#include "base/atomicops.h"
#include "base/compiler_specific.h"
#include "base/macros.h"
#include "base/strings/string16.h"
#include "base/synchronization/lock.h"
#include "base/time/time.h"
#include "build/build_config.h"
#include "net/base/net_export.h"
#include "net/log/net_log_capture_mode.h"
#include "net/log/net_log_entry.h"
#include "net/log/net_log_event_type.h"
#include "net/log/net_log_parameters_callback.h"
#include "net/log/net_log_source.h"
#include "net/log/net_log_source_type.h"
#include "starboard/types.h"

namespace base {
class Value;
}

namespace net {

// NetLog is the destination for log messages generated by the network stack.
// Each log message has a "source" field which identifies the specific entity
// that generated the message (for example, which URLRequest or which
// SpdySession).
//
// To avoid needing to pass in the "source ID" to the logging functions, NetLog
// is usually accessed through a NetLogWithSource, which will always pass in a
// specific source ID.
//
// All methods are thread safe, with the exception that no NetLog or
// NetLog::ThreadSafeObserver functions may be called by an observer's
// OnAddEntry() method.  Doing so will result in a deadlock.
//
// For a broader introduction see the design document:
// https://sites.google.com/a/chromium.org/dev/developers/design-documents/network-stack/netlog
class NET_EXPORT NetLog {
 public:

  // An observer that is notified of entries added to the NetLog. The
  // "ThreadSafe" prefix of the name emphasizes that this observer may be
  // called from different threads then the one which added it as an observer.
  class NET_EXPORT ThreadSafeObserver {
   public:
    // Constructs an observer that wants to see network events, with
    // the specified minimum event granularity.  A ThreadSafeObserver can only
    // observe a single NetLog at a time.
    //
    // Observers will be called on the same thread an entry is added on,
    // and are responsible for ensuring their own thread safety.
    //
    // Observers must stop watching a NetLog before either the observer or the
    // NetLog is destroyed.
    ThreadSafeObserver();

    // Returns the capture mode for events this observer wants to
    // receive. It is only valid to call this while observing a NetLog.
    NetLogCaptureMode capture_mode() const;

    // Returns the NetLog being watched, or nullptr if there is none.
    NetLog* net_log() const;

    // This method is called whenever an entry (event) was added to the NetLog
    // being watched.
    //
    // OnAddEntry() is invoked on the thread which generated the NetLog entry,
    // which may be different from the thread that added this observer.
    //
    // Whenever OnAddEntry() is invoked, the NetLog's mutex is held. The
    // consequences of this are:
    //
    //   * OnAddEntry() will never be called concurrently -- implementations
    //     can rely on this to avoid needing their own synchronization.
    //
    //   * It is illegal for an observer to call back into the NetLog, or the
    //     observer itself, as this can result in deadlock or violating
    //     expectations of non re-entrancy into ThreadSafeObserver.
    virtual void OnAddEntry(const NetLogEntry& entry) = 0;

   protected:
    virtual ~ThreadSafeObserver();

   private:
    friend class NetLog;

    void OnAddEntryData(const NetLogEntryData& entry_data);

    // Both of these values are only modified by the NetLog.
    NetLogCaptureMode capture_mode_;
    NetLog* net_log_;

    DISALLOW_COPY_AND_ASSIGN(ThreadSafeObserver);
  };

  NetLog();
  virtual ~NetLog();

  // Emits a global event to the log stream, with its own unique source ID.
  void AddGlobalEntry(NetLogEventType type);
  void AddGlobalEntry(NetLogEventType type,
                      const NetLogParametersCallback& parameters_callback);

  // Returns a unique ID which can be used as a source ID.  All returned IDs
  // will be unique and greater than 0.
  uint32_t NextID();

  // Returns true if there are any observers attached to the NetLog. This can be
  // used as an optimization to avoid emitting log entries when there is no
  // chance that the data will be consumed.
  bool IsCapturing() const;

  // Adds an observer and sets its log capture mode.  The observer must not be
  // watching any NetLog, including this one, when this is called.
  //
  // CAUTION: Think carefully before introducing a dependency on the
  // NetLog. The order, format, and parameters in NetLog events are NOT
  // guaranteed to be stable. As such, building a production feature that works
  // by observing the NetLog is likely inappropriate. Just as you wouldn't build
  // a feature by scraping the text output from LOG(INFO), you shouldn't do
  // the same by scraping the logging data emitted to NetLog. Support for
  // observers is an internal detail mainly used for testing and to write events
  // to a file. Please consult a //net OWNER before using this outside of
  // testing or serialization.
  void AddObserver(ThreadSafeObserver* observer,
                   NetLogCaptureMode capture_mode);

  // Sets the log capture mode of |observer| to |capture_mode|.  |observer| must
  // be watching |this|.  NetLog implementations must call
  // NetLog::OnSetObserverCaptureMode to update the observer's internal state.
  void SetObserverCaptureMode(ThreadSafeObserver* observer,
                              NetLogCaptureMode capture_mode);

  // Removes an observer.
  //
  // For thread safety reasons, it is recommended that this not be called in
  // an object's destructor.
  void RemoveObserver(ThreadSafeObserver* observer);

  // Converts a time to the string format that the NetLog uses to represent
  // times.  Strings are used since integers may overflow.
  static std::string TickCountToString(const base::TimeTicks& time);

  // Returns a C-String symbolic name for |event_type|.
  static const char* EventTypeToString(NetLogEventType event_type);

  // Returns a dictionary that maps event type symbolic names to their enum
  // values.
  static std::unique_ptr<base::Value> GetEventTypesAsValue();

  // Returns a C-String symbolic name for |source_type|.
  static const char* SourceTypeToString(NetLogSourceType source_type);

  // Returns a dictionary that maps source type symbolic names to their enum
  // values.
  static std::unique_ptr<base::Value> GetSourceTypesAsValue();

  // Returns a C-String symbolic name for |event_phase|.
  static const char* EventPhaseToString(NetLogEventPhase event_phase);

  // Creates a NetLogParametersCallback that encapsulates a single bool.
  // Warning: |name| must remain valid for the life of the callback.
  static NetLogParametersCallback BoolCallback(const char* name, bool value);

  // Warning: |name| must remain valid for the life of the callback.
  static NetLogParametersCallback IntCallback(const char* name, int value);

  // Creates a NetLogParametersCallback that encapsulates a single int64_t.  The
  // callback will return the value as a StringValue, since IntegerValues
  // only support 32-bit values.
  // Warning: |name| must remain valid for the life of the callback.
  static NetLogParametersCallback Int64Callback(const char* name,
                                                int64_t value);

  // Creates a NetLogParametersCallback that encapsulates a single UTF8 string.
  // Takes
  // |value| as a pointer to avoid copying, and emphasize it must be valid for
  // the life of the callback.  |value| may not be NULL.
  // Warning: |name| and |value| must remain valid for the life of the callback.
  static NetLogParametersCallback StringCallback(const char* name,
                                                 const std::string* value);
  static NetLogParametersCallback StringCallback(const char* name,
                                                 const char* value);

  // Same as above, but takes in a UTF16 string.
  static NetLogParametersCallback StringCallback(const char* name,
                                                 const base::string16* value);

 private:
  friend class NetLogWithSource;

  void AddEntry(NetLogEventType type,
                const NetLogSource& source,
                NetLogEventPhase phase,
                const NetLogParametersCallback* parameters_callback);

  // Called whenever an observer is added or removed, to update
  // |has_observers_|. Must have acquired |lock_| prior to calling.
  void UpdateIsCapturing();

  // Returns true if |observer| is watching this NetLog. Must
  // be called while |lock_| is already held.
  bool HasObserver(ThreadSafeObserver* observer);

  // |lock_| protects access to |observers_|.
  base::Lock lock_;

  // Last assigned source ID.  Incremented to get the next one.
  base::subtle::Atomic32 last_id_;

  // |is_capturing_| will be 0 when there are no observers watching the NetLog,
  // 1 otherwise. Note that this is stored as an Atomic32 rather than a boolean
  // so it can be accessed without needing a lock.
  base::subtle::Atomic32 is_capturing_;

  // |observers_| is a list of observers, ordered by when they were added.
  // Pointers contained in |observers_| are non-owned, and must
  // remain valid.
  //
  // |lock_| must be acquired whenever reading or writing to this.
  //
  // In practice |observers_| will be very small (<5) so O(n)
  // operations on it are fine.
  std::vector<ThreadSafeObserver*> observers_;

  DISALLOW_COPY_AND_ASSIGN(NetLog);
};

// Creates a base::Value() to represent the byte string |raw| when adding it to
// the NetLog.
//
// When |raw| is an ASCII string, the returned value is a base::Value()
// containing that exact string. Otherwise it is represented by a
// percent-escaped version of the original string, along with a special prefix.
//
// This wrapper exists because base::Value strings are required to be UTF-8.
// Often times NetLog consumers just want to log a std::string, and that string
// may not be UTF-8.
NET_EXPORT base::Value NetLogStringValue(base::StringPiece raw);

// Creates a base::Value() to represent the octets |bytes|. This should be
// used when adding binary data (i.e. not an ASCII or UTF-8 string) to the
// NetLog. The resulting base::Value() holds a copy of the input data.
//
// This wrapper must be used rather than directly adding base::Value parameters
// of type BINARY to the NetLog, since the JSON writer does not support
// serializing them.
//
// This wrapper encodes |bytes| as a Base64 encoded string.
NET_EXPORT base::Value NetLogBinaryValue(const void* bytes, size_t length);

// Creates a base::Value() to represent integers, including 64-bit ones.
// base::Value() does not directly support 64-bit integers, as it is not
// representable in JSON.
//
// These wrappers will return values that are either numbers, or a string
// representation of their decimal value, depending on what is needed to ensure
// no loss of precision when de-serializing from JavaScript.
NET_EXPORT base::Value NetLogNumberValue(int64_t num);
NET_EXPORT base::Value NetLogNumberValue(uint64_t num);

}  // namespace net

#endif  // NET_LOG_NET_LOG_H_

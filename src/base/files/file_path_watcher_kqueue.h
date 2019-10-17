// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
#define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_

#include <sys/event.h>

#include <memory>
#include <vector>

#include "base/files/file_descriptor_watcher_posix.h"
#include "base/files/file_path.h"
#include "base/files/file_path_watcher.h"
#include "base/macros.h"
#include "starboard/types.h"

namespace base {

// Mac-specific file watcher implementation based on kqueue.
// The Linux and Windows versions are able to detect:
// - file creation/deletion/modification in a watched directory
// - file creation/deletion/modification for a watched file
// - modifications to the paths to a watched object that would affect the
//   object such as renaming/attibute changes etc.
// The kqueue implementation will handle all of the items in the list above
// except for detecting modifications to files in a watched directory. It will
// detect the creation and deletion of files, just not the modification of
// files. It does however detect the attribute changes that the FSEvents impl
// would miss.
class FilePathWatcherKQueue : public FilePathWatcher::PlatformDelegate {
 public:
  FilePathWatcherKQueue();
  ~FilePathWatcherKQueue() override;

  // FilePathWatcher::PlatformDelegate overrides.
  bool Watch(const FilePath& path,
             bool recursive,
             const FilePathWatcher::Callback& callback) override;
  void Cancel() override;

 private:
  class EventData {
   public:
    EventData(const FilePath& path, const FilePath::StringType& subdir)
        : path_(path), subdir_(subdir) { }
    FilePath path_;  // Full path to this item.
    FilePath::StringType subdir_;  // Path to any sub item.
  };

  typedef std::vector<struct kevent> EventVector;

  // Called when data is available in |kqueue_|.
  void OnKQueueReadable();

  // Returns true if the kevent values are error free.
  bool AreKeventValuesValid(struct kevent* kevents, int count);

  // Respond to a change of attributes of the path component represented by
  // |event|. Sets |target_file_affected| to true if |target_| is affected.
  // Sets |update_watches| to true if |events_| need to be updated.
  void HandleAttributesChange(const EventVector::iterator& event,
                              bool* target_file_affected,
                              bool* update_watches);

  // Respond to a move or deletion of the path component represented by
  // |event|. Sets |target_file_affected| to true if |target_| is affected.
  // Sets |update_watches| to true if |events_| need to be updated.
  void HandleDeleteOrMoveChange(const EventVector::iterator& event,
                                bool* target_file_affected,
                                bool* update_watches);

  // Respond to a creation of an item in the path component represented by
  // |event|. Sets |target_file_affected| to true if |target_| is affected.
  // Sets |update_watches| to true if |events_| need to be updated.
  void HandleCreateItemChange(const EventVector::iterator& event,
                              bool* target_file_affected,
                              bool* update_watches);

  // Update |events_| with the current status of the system.
  // Sets |target_file_affected| to true if |target_| is affected.
  // Returns false if an error occurs.
  bool UpdateWatches(bool* target_file_affected);

  // Fills |events| with one kevent per component in |path|.
  // Returns the number of valid events created where a valid event is
  // defined as one that has a ident (file descriptor) field != -1.
  static int EventsForPath(FilePath path, EventVector *events);

  // Release a kevent generated by EventsForPath.
  static void ReleaseEvent(struct kevent& event);

  // Returns a file descriptor that will not block the system from deleting
  // the file it references.
  static uintptr_t FileDescriptorForPath(const FilePath& path);

  static const uintptr_t kNoFileDescriptor = static_cast<uintptr_t>(-1);

  // Closes |*fd| and sets |*fd| to -1.
  static void CloseFileDescriptor(uintptr_t* fd);

  // Returns true if kevent has open file descriptor.
  static bool IsKeventFileDescriptorOpen(const struct kevent& event) {
    return event.ident != kNoFileDescriptor;
  }

  static EventData* EventDataForKevent(const struct kevent& event) {
    return reinterpret_cast<EventData*>(event.udata);
  }

  EventVector events_;
  FilePathWatcher::Callback callback_;
  FilePath target_;
  int kqueue_;

  // Throughout the lifetime of this, OnKQueueReadable() will be called when
  // data is available in |kqueue_|.
  std::unique_ptr<FileDescriptorWatcher::Controller> kqueue_watch_controller_;

  DISALLOW_COPY_AND_ASSIGN(FilePathWatcherKQueue);
};

}  // namespace base

#endif  // BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_



// Copyright 2019 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// clang-format off

// This file has been auto-generated by bindings/code_generator_cobalt.py. DO NOT MODIFY!
// Auto-generated from template: bindings/v8c/templates/interface.cc.template

#include "cobalt/bindings/shared/idl_conditional_macros.h"

#include "cobalt/bindings/testing/v8c_callback_function_interface.h"

#include "base/trace_event/trace_event.h"
#include "cobalt/base/polymorphic_downcast.h"
#include "cobalt/script/global_environment.h"
#include "cobalt/script/script_value.h"
#include "cobalt/script/value_handle.h"
#include "cobalt/bindings/testing/arbitrary_interface.h"
#include "cobalt/bindings/testing/v8c_arbitrary_interface.h"

#include "v8c_gen_type_conversion.h"

#include "cobalt/script/callback_interface_traits.h"
#include "cobalt/script/v8c/v8c_array_buffer.h"
#include "cobalt/script/v8c/v8c_array_buffer_view.h"
#include "cobalt/script/v8c/callback_function_conversion.h"
#include "cobalt/script/v8c/conversion_helpers.h"
#include "cobalt/script/v8c/entry_scope.h"
#include "cobalt/script/v8c/helpers.h"
#include "cobalt/script/v8c/native_promise.h"
#include "cobalt/script/v8c/type_traits.h"
#include "cobalt/script/v8c/v8c_typed_arrays.h"
#include "cobalt/script/v8c/v8c_data_view.h"
#include "cobalt/script/v8c/v8c_callback_function.h"
#include "cobalt/script/v8c/v8c_callback_interface_holder.h"
#include "cobalt/script/v8c/v8c_engine.h"
#include "cobalt/script/v8c/v8c_exception_state.h"
#include "cobalt/script/v8c/v8c_global_environment.h"
#include "cobalt/script/v8c/v8c_property_enumerator.h"
#include "cobalt/script/v8c/v8c_value_handle.h"
#include "cobalt/script/v8c/wrapper_private.h"
#include "cobalt/script/v8c/common_v8c_bindings_code.h"
#include "v8/include/v8.h"


namespace {
using cobalt::bindings::testing::CallbackFunctionInterface;
using cobalt::bindings::testing::V8cCallbackFunctionInterface;
using cobalt::bindings::testing::ArbitraryInterface;
using cobalt::bindings::testing::V8cArbitraryInterface;
using cobalt::script::CallbackInterfaceTraits;
using cobalt::script::GlobalEnvironment;
using cobalt::script::ScriptValue;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandleHolder;
using cobalt::script::Wrappable;

using cobalt::script::v8c::EntryScope;
using cobalt::script::v8c::EscapableEntryScope;
using cobalt::script::v8c::FromJSValue;
using cobalt::script::v8c::kConversionFlagClamped;
using cobalt::script::v8c::kConversionFlagNullable;
using cobalt::script::v8c::kConversionFlagObjectOnly;
using cobalt::script::v8c::kConversionFlagRestricted;
using cobalt::script::v8c::kConversionFlagTreatNullAsEmptyString;
using cobalt::script::v8c::kConversionFlagTreatUndefinedAsEmptyString;
using cobalt::script::v8c::kNoConversionFlags;
using cobalt::script::v8c::NewInternalString;
using cobalt::script::v8c::ToJSValue;
using cobalt::script::v8c::TypeTraits;
using cobalt::script::v8c::V8cExceptionState;
using cobalt::script::v8c::V8cGlobalEnvironment;
using cobalt::script::v8c::V8cPropertyEnumerator;
using cobalt::script::v8c::WrapperFactory;
using cobalt::script::v8c::WrapperPrivate;
}  // namespace

namespace cobalt {
namespace bindings {
namespace testing {


namespace {

const int kInterfaceUniqueId = 6;








void DummyConstructor(const v8::FunctionCallbackInfo<v8::Value>& info) {
  V8cExceptionState exception(info.GetIsolate());
  exception.SetSimpleException(
      script::kTypeError, "CallbackFunctionInterface is not constructible.");
}



void callbackAttributeAttributeGetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  script::v8c::shared_bindings::AttributeGetterImpl<CallbackFunctionInterface,
                                                    V8cCallbackFunctionInterface>(
                    info,
                    false,
                    false,
                    [](v8::Isolate* isolate, CallbackFunctionInterface* impl,
                       cobalt::script::ExceptionState& exception_state,
                       v8::Local<v8::Value>& result_value) {
  
      ToJSValue(isolate,
              impl->callback_attribute(),
              &result_value);

  });
}

void callbackAttributeAttributeSetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  script::v8c::shared_bindings::AttributeSetterImpl<CallbackFunctionInterface, V8cCallbackFunctionInterface>(info,
                    false,
                    false,
                    [](v8::Isolate* isolate, CallbackFunctionInterface* impl,
                       V8cExceptionState& exception_state,
                       v8::Local<v8::Value>& result_value,
                       v8::Local<v8::Value> v8_value) {
  TypeTraits<CallbackFunctionInterface::VoidFunction >::ConversionType value;
  FromJSValue(isolate, v8_value, kNoConversionFlags, &exception_state,
              &value);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->set_callback_attribute(value);
result_value = v8::Undefined(isolate);
  return;
});
}


void nullableCallbackAttributeAttributeGetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  script::v8c::shared_bindings::AttributeGetterImpl<CallbackFunctionInterface,
                                                    V8cCallbackFunctionInterface>(
                    info,
                    false,
                    false,
                    [](v8::Isolate* isolate, CallbackFunctionInterface* impl,
                       cobalt::script::ExceptionState& exception_state,
                       v8::Local<v8::Value>& result_value) {
  
      ToJSValue(isolate,
              impl->nullable_callback_attribute(),
              &result_value);

  });
}

void nullableCallbackAttributeAttributeSetter(
    const v8::FunctionCallbackInfo<v8::Value>& info) {
  script::v8c::shared_bindings::AttributeSetterImpl<CallbackFunctionInterface, V8cCallbackFunctionInterface>(info,
                    false,
                    false,
                    [](v8::Isolate* isolate, CallbackFunctionInterface* impl,
                       V8cExceptionState& exception_state,
                       v8::Local<v8::Value>& result_value,
                       v8::Local<v8::Value> v8_value) {
  TypeTraits<CallbackFunctionInterface::VoidFunction >::ConversionType value;
  FromJSValue(isolate, v8_value, (kConversionFlagNullable), &exception_state,
              &value);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->set_nullable_callback_attribute(value);
result_value = v8::Undefined(isolate);
  return;
});
}



void takesFunctionThatReturnsStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();
  if (!script::v8c::shared_bindings::object_implements_interface(V8cCallbackFunctionInterface::GetTemplate(isolate), isolate, object)) {
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  CallbackFunctionInterface* impl =
          script::v8c::shared_bindings::get_impl_from_object<
             CallbackFunctionInterface>(object);
  if (!impl) {
    return;
  }
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<CallbackFunctionInterface::FunctionThatReturnsString >::ConversionType cb;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &cb);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->TakesFunctionThatReturnsString(cb);
result_value = v8::Undefined(isolate);

}



void takesFunctionWithNullableParametersMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();
  if (!script::v8c::shared_bindings::object_implements_interface(V8cCallbackFunctionInterface::GetTemplate(isolate), isolate, object)) {
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  CallbackFunctionInterface* impl =
          script::v8c::shared_bindings::get_impl_from_object<
             CallbackFunctionInterface>(object);
  if (!impl) {
    return;
  }
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<CallbackFunctionInterface::FunctionWithNullableParameters >::ConversionType cb;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &cb);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->TakesFunctionWithNullableParameters(cb);
result_value = v8::Undefined(isolate);

}



void takesFunctionWithOneParameterMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();
  if (!script::v8c::shared_bindings::object_implements_interface(V8cCallbackFunctionInterface::GetTemplate(isolate), isolate, object)) {
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  CallbackFunctionInterface* impl =
          script::v8c::shared_bindings::get_impl_from_object<
             CallbackFunctionInterface>(object);
  if (!impl) {
    return;
  }
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<CallbackFunctionInterface::FunctionWithOneParameter >::ConversionType cb;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &cb);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->TakesFunctionWithOneParameter(cb);
result_value = v8::Undefined(isolate);

}



void takesFunctionWithSeveralParametersMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();
  if (!script::v8c::shared_bindings::object_implements_interface(V8cCallbackFunctionInterface::GetTemplate(isolate), isolate, object)) {
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  CallbackFunctionInterface* impl =
          script::v8c::shared_bindings::get_impl_from_object<
             CallbackFunctionInterface>(object);
  if (!impl) {
    return;
  }
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<CallbackFunctionInterface::FunctionWithSeveralParameters >::ConversionType cb;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &cb);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->TakesFunctionWithSeveralParameters(cb);
result_value = v8::Undefined(isolate);

}



void takesVoidFunctionMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Isolate* isolate = info.GetIsolate();
  v8::Local<v8::Object> object = info.Holder();
  if (!script::v8c::shared_bindings::object_implements_interface(V8cCallbackFunctionInterface::GetTemplate(isolate), isolate, object)) {
    return;
  }
  V8cExceptionState exception_state{isolate};
  v8::Local<v8::Value> result_value;

  CallbackFunctionInterface* impl =
          script::v8c::shared_bindings::get_impl_from_object<
             CallbackFunctionInterface>(object);
  if (!impl) {
    return;
  }
  const size_t kMinArguments = 1;
  if (info.Length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return;
  }
  // Non-optional arguments
  TypeTraits<CallbackFunctionInterface::VoidFunction >::ConversionType cb;
  DCHECK_LT(0, info.Length());
  v8::Local<v8::Value> non_optional_value0 = info[0];
  FromJSValue(isolate,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &cb);
  if (exception_state.is_exception_set()) {
    return;
  }

  impl->TakesVoidFunction(cb);
result_value = v8::Undefined(isolate);

}



void InitializeTemplate(v8::Isolate* isolate) {
  // https://heycam.github.io/webidl/#interface-object
  // 3.6.1. Interface object
  //
  // The interface object for a given interface is a built-in function object.
  // It has properties that correspond to the constants and static operations
  // defined on that interface, as described in sections 3.6.6 Constants and
  // 3.6.8 Operations.
  //
  // If the interface is declared with a [Constructor] extended attribute,
  // then the interface object can be called as a constructor to create an
  // object that implements that interface. Calling that interface as a
  // function will throw an exception.
  //
  // Interface objects whose interfaces are not declared with a [Constructor]
  // extended attribute will throw when called, both as a function and as a
  // constructor.
  //
  // An interface object for a non-callback interface has an associated object
  // called the interface prototype object. This object has properties that
  // correspond to the regular attributes and regular operations defined on
  // the interface, and is described in more detail in 3.6.3 Interface
  // prototype object.
  v8::Local<v8::FunctionTemplate> function_template =
      v8::FunctionTemplate::New(
          isolate,
          DummyConstructor,
          v8::Local<v8::Value>(),
          v8::Local<v8::Signature>(),
          0);
  function_template->SetClassName(NewInternalString(isolate, "CallbackFunctionInterface"));
  function_template->ReadOnlyPrototype();

  v8::Local<v8::ObjectTemplate> prototype_template = function_template->PrototypeTemplate();
  v8::Local<v8::ObjectTemplate> instance_template = function_template->InstanceTemplate();
  instance_template->SetInternalFieldCount(WrapperPrivate::kInternalFieldCount);

  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  global_environment->AddInterfaceData(kInterfaceUniqueId, function_template);


  // https://heycam.github.io/webidl/#es-constants
  // 3.6.6. Constants
  //
  // For each exposed constant defined on an interface A, there must be a
  // corresponding property. The property has the following characteristics:

  // https://heycam.github.io/webidl/#es-attributes
  // 3.6.7. Attributes
  //
  // For each exposed attribute of the interface there must exist a
  // corresponding property. The characteristics of this property are as
  // follows:
  {

    script::v8c::shared_bindings::set_property_for_nonconstructor_attribute(
                  isolate,
    // The property has attributes { [[Get]]: G, [[Set]]: S, [[Enumerable]]:
    // true, [[Configurable]]: configurable }, where: configurable is false if
    // the attribute was declared with the [Unforgeable] extended attribute and
    // true otherwise;
                  true,
                  true,
                  false,
                  false,
                  function_template,
                  instance_template,
                  prototype_template,
                  "callbackAttribute"
                  ,callbackAttributeAttributeGetter
                  ,callbackAttributeAttributeSetter
                  );

  }
  {

    script::v8c::shared_bindings::set_property_for_nonconstructor_attribute(
                  isolate,
    // The property has attributes { [[Get]]: G, [[Set]]: S, [[Enumerable]]:
    // true, [[Configurable]]: configurable }, where: configurable is false if
    // the attribute was declared with the [Unforgeable] extended attribute and
    // true otherwise;
                  true,
                  true,
                  false,
                  false,
                  function_template,
                  instance_template,
                  prototype_template,
                  "nullableCallbackAttribute"
                  ,nullableCallbackAttributeAttributeGetter
                  ,nullableCallbackAttributeAttributeSetter
                  );

  }

  // https://heycam.github.io/webidl/#es-operations
  // 3.6.8. Operations
  //
  // For each unique identifier of an exposed operation defined on the
  // interface, there must exist a corresponding property, unless the effective
  // overload set for that identifier and operation and with an argument count
  // of 0 has no entries.
  //
  // The characteristics of this property are as follows:
  {
    // The name of the property is the identifier.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "takesFunctionThatReturnsString");

    // The property has attributes { [[Writable]]: B, [[Enumerable]]: true,
    // [[Configurable]]: B }, where B is false if the operation is unforgeable
    // on the interface, and true otherwise.
    bool B = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        B ? v8::None : (v8::ReadOnly | v8::DontDelete));

    v8::Local<v8::FunctionTemplate> method_template =
        v8::FunctionTemplate::New(isolate, takesFunctionThatReturnsStringMethod);
    method_template->RemovePrototype();
    method_template->SetLength(1);

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        Set(name, method_template);

    // The value of the property is the result of creating an operation function
    // given the operation, the interface, and the relevant Realm of the object
    // that is the location of the property.

    // Note: that is, even if an includes statement was used to make an
    // operation available on the interface, we pass in the interface which
    // includes the interface mixin, and not the interface mixin on which the
    // operation was originally declared.
  }
  {
    // The name of the property is the identifier.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "takesFunctionWithNullableParameters");

    // The property has attributes { [[Writable]]: B, [[Enumerable]]: true,
    // [[Configurable]]: B }, where B is false if the operation is unforgeable
    // on the interface, and true otherwise.
    bool B = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        B ? v8::None : (v8::ReadOnly | v8::DontDelete));

    v8::Local<v8::FunctionTemplate> method_template =
        v8::FunctionTemplate::New(isolate, takesFunctionWithNullableParametersMethod);
    method_template->RemovePrototype();
    method_template->SetLength(1);

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        Set(name, method_template);

    // The value of the property is the result of creating an operation function
    // given the operation, the interface, and the relevant Realm of the object
    // that is the location of the property.

    // Note: that is, even if an includes statement was used to make an
    // operation available on the interface, we pass in the interface which
    // includes the interface mixin, and not the interface mixin on which the
    // operation was originally declared.
  }
  {
    // The name of the property is the identifier.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "takesFunctionWithOneParameter");

    // The property has attributes { [[Writable]]: B, [[Enumerable]]: true,
    // [[Configurable]]: B }, where B is false if the operation is unforgeable
    // on the interface, and true otherwise.
    bool B = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        B ? v8::None : (v8::ReadOnly | v8::DontDelete));

    v8::Local<v8::FunctionTemplate> method_template =
        v8::FunctionTemplate::New(isolate, takesFunctionWithOneParameterMethod);
    method_template->RemovePrototype();
    method_template->SetLength(1);

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        Set(name, method_template);

    // The value of the property is the result of creating an operation function
    // given the operation, the interface, and the relevant Realm of the object
    // that is the location of the property.

    // Note: that is, even if an includes statement was used to make an
    // operation available on the interface, we pass in the interface which
    // includes the interface mixin, and not the interface mixin on which the
    // operation was originally declared.
  }
  {
    // The name of the property is the identifier.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "takesFunctionWithSeveralParameters");

    // The property has attributes { [[Writable]]: B, [[Enumerable]]: true,
    // [[Configurable]]: B }, where B is false if the operation is unforgeable
    // on the interface, and true otherwise.
    bool B = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        B ? v8::None : (v8::ReadOnly | v8::DontDelete));

    v8::Local<v8::FunctionTemplate> method_template =
        v8::FunctionTemplate::New(isolate, takesFunctionWithSeveralParametersMethod);
    method_template->RemovePrototype();
    method_template->SetLength(1);

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        Set(name, method_template);

    // The value of the property is the result of creating an operation function
    // given the operation, the interface, and the relevant Realm of the object
    // that is the location of the property.

    // Note: that is, even if an includes statement was used to make an
    // operation available on the interface, we pass in the interface which
    // includes the interface mixin, and not the interface mixin on which the
    // operation was originally declared.
  }
  {
    // The name of the property is the identifier.
    v8::Local<v8::String> name = NewInternalString(
        isolate,
        "takesVoidFunction");

    // The property has attributes { [[Writable]]: B, [[Enumerable]]: true,
    // [[Configurable]]: B }, where B is false if the operation is unforgeable
    // on the interface, and true otherwise.
    bool B = true;
    v8::PropertyAttribute attributes = static_cast<v8::PropertyAttribute>(
        B ? v8::None : (v8::ReadOnly | v8::DontDelete));

    v8::Local<v8::FunctionTemplate> method_template =
        v8::FunctionTemplate::New(isolate, takesVoidFunctionMethod);
    method_template->RemovePrototype();
    method_template->SetLength(1);

    // The location of the property is determined as follows:
    // Otherwise, the property exists solely on the interface's interface
    // prototype object.
    prototype_template->
        Set(name, method_template);

    // The value of the property is the result of creating an operation function
    // given the operation, the interface, and the relevant Realm of the object
    // that is the location of the property.

    // Note: that is, even if an includes statement was used to make an
    // operation available on the interface, we pass in the interface which
    // includes the interface mixin, and not the interface mixin on which the
    // operation was originally declared.
  }

  // https://heycam.github.io/webidl/#es-stringifier
  // 3.6.8.2. Stringifiers
  prototype_template->Set(
      v8::Symbol::GetToStringTag(isolate),
      NewInternalString(isolate, "CallbackFunctionInterface"),
      static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontEnum));





}

}  // namespace


v8::Local<v8::Object> V8cCallbackFunctionInterface::CreateWrapper(
    v8::Isolate* isolate, const scoped_refptr<Wrappable>& wrappable) {
  EscapableEntryScope entry_scope(isolate);
  v8::Local<v8::Context> context = isolate->GetCurrentContext();

  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  if (!global_environment->HasInterfaceData(kInterfaceUniqueId)) {
    InitializeTemplate(isolate);
  }
  v8::Local<v8::FunctionTemplate> function_template = global_environment->GetInterfaceData(kInterfaceUniqueId);

  DCHECK(function_template->InstanceTemplate()->InternalFieldCount() == WrapperPrivate::kInternalFieldCount);
  v8::Local<v8::Object> object = function_template->InstanceTemplate()->NewInstance(context).ToLocalChecked();
  DCHECK(object->InternalFieldCount() == WrapperPrivate::kInternalFieldCount);

  // This |WrapperPrivate|'s lifetime will be managed by V8.
  new WrapperPrivate(isolate, wrappable, object);
  return entry_scope.Escape(object);
}


v8::Local<v8::FunctionTemplate> V8cCallbackFunctionInterface::GetTemplate(v8::Isolate* isolate) {
  V8cGlobalEnvironment* global_environment = V8cGlobalEnvironment::GetFromIsolate(isolate);
  if (!global_environment->HasInterfaceData(kInterfaceUniqueId)) {
    InitializeTemplate(isolate);
  }
  return global_environment->GetInterfaceData(kInterfaceUniqueId);
}


}  // namespace testing
}  // namespace bindings
}  // namespace cobalt



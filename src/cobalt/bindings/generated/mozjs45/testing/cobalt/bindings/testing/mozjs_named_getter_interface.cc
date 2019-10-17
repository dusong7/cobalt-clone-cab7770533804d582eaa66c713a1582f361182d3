

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
// Auto-generated from template: bindings/mozjs45/templates/interface.cc.template

#include "cobalt/bindings/shared/idl_conditional_macros.h"

#include "cobalt/bindings/testing/mozjs_named_getter_interface.h"

#include "base/trace_event/trace_event.h"
#include "cobalt/base/polymorphic_downcast.h"
#include "cobalt/script/global_environment.h"
#include "cobalt/script/script_value.h"
#include "cobalt/script/value_handle.h"

#include "mozjs_gen_type_conversion.h"

#include "base/lazy_instance.h"
#include "cobalt/script/exception_state.h"
#include "cobalt/script/mozjs-45/callback_function_conversion.h"
#include "cobalt/script/mozjs-45/conversion_helpers.h"
#include "cobalt/script/mozjs-45/mozjs_array_buffer.h"
#include "cobalt/script/mozjs-45/mozjs_array_buffer_view.h"
#include "cobalt/script/mozjs-45/mozjs_callback_function.h"
#include "cobalt/script/mozjs-45/mozjs_data_view.h"
#include "cobalt/script/mozjs-45/mozjs_exception_state.h"
#include "cobalt/script/mozjs-45/mozjs_global_environment.h"
#include "cobalt/script/mozjs-45/mozjs_property_enumerator.h"
#include "cobalt/script/mozjs-45/mozjs_typed_arrays.h"
#include "cobalt/script/mozjs-45/mozjs_user_object_holder.h"
#include "cobalt/script/mozjs-45/mozjs_value_handle.h"
#include "cobalt/script/mozjs-45/native_promise.h"
#include "cobalt/script/mozjs-45/proxy_handler.h"
#include "cobalt/script/mozjs-45/type_traits.h"
#include "cobalt/script/mozjs-45/wrapper_factory.h"
#include "cobalt/script/mozjs-45/wrapper_private.h"
#include "cobalt/script/property_enumerator.h"
#include "cobalt/script/sequence.h"
#include "third_party/mozjs-45/js/src/jsapi.h"
#include "third_party/mozjs-45/js/src/jsfriendapi.h"


namespace {
using cobalt::bindings::testing::NamedGetterInterface;
using cobalt::bindings::testing::MozjsNamedGetterInterface;
using cobalt::script::CallbackInterfaceTraits;
using cobalt::script::GlobalEnvironment;
using cobalt::script::ScriptValue;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandle;
using cobalt::script::ValueHandleHolder;
using cobalt::script::Wrappable;

using cobalt::script::CallbackFunction;
using cobalt::script::CallbackInterfaceTraits;
using cobalt::script::ExceptionState;
using cobalt::script::Wrappable;
using cobalt::script::mozjs::FromJSValue;
using cobalt::script::mozjs::InterfaceData;
using cobalt::script::mozjs::MozjsCallbackFunction;
using cobalt::script::mozjs::MozjsExceptionState;
using cobalt::script::mozjs::MozjsGlobalEnvironment;
using cobalt::script::mozjs::MozjsPropertyEnumerator;
using cobalt::script::mozjs::MozjsUserObjectHolder;
using cobalt::script::mozjs::ProxyHandler;
using cobalt::script::mozjs::ToJSValue;
using cobalt::script::mozjs::TypeTraits;
using cobalt::script::mozjs::WrapperFactory;
using cobalt::script::mozjs::WrapperPrivate;
using cobalt::script::mozjs::kConversionFlagClamped;
using cobalt::script::mozjs::kConversionFlagNullable;
using cobalt::script::mozjs::kConversionFlagRestricted;
using cobalt::script::mozjs::kConversionFlagTreatNullAsEmptyString;
using cobalt::script::mozjs::kConversionFlagTreatUndefinedAsEmptyString;
using cobalt::script::mozjs::kConversionFlagObjectOnly;
using cobalt::script::mozjs::kNoConversionFlags;
}  // namespace

namespace cobalt {
namespace bindings {
namespace testing {


namespace {


bool IsSupportedNamedProperty(JSContext* context, JS::HandleObject object,
                              const std::string& property_name) {
  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  return impl->CanQueryNamedProperty(property_name);
}

void EnumerateSupportedNames(JSContext* context, JS::HandleObject object,
                             JS::AutoIdVector* properties) {
  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  MozjsPropertyEnumerator enumerator(context, properties);
  impl->EnumerateNamedProperties(&enumerator);
}

bool GetNamedProperty(
    JSContext* context, JS::HandleObject object, JS::HandleId id,
    JS::MutableHandleValue vp) {
  JS::RootedValue id_value(context);
  if (!JS_IdToValue(context, id, &id_value)) {
    NOTREACHED();
    return false;
  }

  MozjsExceptionState exception_state(context);
  JS::RootedValue result_value(context);

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  std::string property_name;
  FromJSValue(context, id_value, kNoConversionFlags, &exception_state,
              &property_name);
  if (exception_state.is_exception_set()) {
    // The ID should be an integer or a string, so we shouldn't have any
    // exceptions converting to string.
    NOTREACHED();
    return false;
  }

  if (!exception_state.is_exception_set()) {
    ToJSValue(context,
              impl->NamedGetter(property_name),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    vp.set(result_value);
  }
  return !exception_state.is_exception_set();
}



bool SetNamedProperty(
  JSContext* context, JS::HandleObject object, JS::HandleId id,
  JS::MutableHandleValue vp, JS::ObjectOpResult& object_op_result) {
  JS::RootedValue id_value(context);
  if (!JS_IdToValue(context, id, &id_value)) {
    NOTREACHED();
    return false;
  }
  MozjsExceptionState exception_state(context);
  JS::RootedValue result_value(context);

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  std::string property_name;
  FromJSValue(context, id_value, kNoConversionFlags, &exception_state,
              &property_name);
  if (exception_state.is_exception_set()) {
    // The ID should be an integer or a string, so we shouldn't have any
    // exceptions converting to string.
    NOTREACHED();
    return false;
  }
  TypeTraits<std::string >::ConversionType value;
  FromJSValue(context, vp, kNoConversionFlags,
              &exception_state, &value);
  if (exception_state.is_exception_set()) {
    return false;
  }

  impl->NamedSetter(property_name, value);
  result_value.set(JS::UndefinedHandleValue);

  if (!exception_state.is_exception_set()) {
    return object_op_result.succeed();
  } else {
    return false;
  }
}



bool DeleteNamedProperty(JSContext* context, JS::HandleObject object,
                         const std::string& property_name) {
  MozjsExceptionState exception_state(context);
  JS::RootedValue result_value(context);

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();

  impl->NamedDeleter(property_name);
  result_value.set(JS::UndefinedHandleValue);
  return !exception_state.is_exception_set();
}





class MozjsNamedGetterInterfaceHandler : public ProxyHandler {
 public:
  MozjsNamedGetterInterfaceHandler()
      : ProxyHandler(indexed_property_hooks, named_property_hooks) {}

 private:
  static NamedPropertyHooks named_property_hooks;
  static IndexedPropertyHooks indexed_property_hooks;
};

ProxyHandler::NamedPropertyHooks
MozjsNamedGetterInterfaceHandler::named_property_hooks = {
  IsSupportedNamedProperty,
  EnumerateSupportedNames,
  GetNamedProperty,
  SetNamedProperty,
  DeleteNamedProperty,
};

ProxyHandler::IndexedPropertyHooks
MozjsNamedGetterInterfaceHandler::indexed_property_hooks = {
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
};

static base::LazyInstance<MozjsNamedGetterInterfaceHandler>::DestructorAtExit
    proxy_handler;

bool DummyConstructor(JSContext* context, unsigned int argc, JS::Value* vp) {
  MozjsExceptionState exception(context);
  exception.SetSimpleException(
      script::kTypeError, "NamedGetterInterface is not constructible.");
  return false;
}

bool HasInstance(JSContext *context, JS::HandleObject type,
                 JS::MutableHandleValue vp, bool *success) {
  JS::RootedObject global_object(
      context, JS_GetGlobalForObject(context, type));
  DCHECK(global_object);

  JS::RootedObject prototype(
      context, MozjsNamedGetterInterface::GetPrototype(context, global_object));

  // |IsDelegate| walks the prototype chain of an object returning true if
  // .prototype is found.
  bool is_delegate;
  if (!IsDelegate(context, prototype, vp, &is_delegate)) {
    *success = false;
    return false;
  }

  *success = is_delegate;
  return true;
}

const JSClass instance_class_definition = {
    "NamedGetterInterface",
    0 | JSCLASS_HAS_PRIVATE,
    NULL,  // addProperty
    NULL,  // delProperty
    NULL,  // getProperty
    NULL,  // setProperty
    NULL,  // enumerate
    NULL,  // resolve
    NULL,  // mayResolve
    &WrapperPrivate::Finalizer,  // finalize
    NULL,  // call
    NULL,  // hasInstance
    NULL,  // construct
    &WrapperPrivate::Trace,  // trace
};

const JSClass prototype_class_definition = {
    "NamedGetterInterfacePrototype",
};

const JSClass interface_object_class_definition = {
    "NamedGetterInterfaceConstructor",
    0,
    NULL,  // addProperty
    NULL,  // delProperty
    NULL,  // getProperty
    NULL,  // setProperty
    NULL,  // enumerate
    NULL,  // resolve
    NULL,  // mayResolve
    NULL,  // finalize
    NULL,  // call
    &HasInstance,
    NULL,
};


bool fcn_namedDeleter(
    JSContext* context, uint32_t argc, JS::Value *vp) {
  JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  // Compute the 'this' value.
  JS::RootedValue this_value(context, JS_ComputeThis(context, vp));
  // 'this' should be an object.
  JS::RootedObject object(context);
  if (JS_TypeOfValue(context, this_value) != JSTYPE_OBJECT) {
    return false;
  }
  if (!JS_ValueToObject(context, this_value, &object)) {
    NOTREACHED();
    return false;
  }
  const JSClass* proto_class =
      MozjsNamedGetterInterface::PrototypeClass(context);
  if (proto_class == JS_GetClass(object)) {
    // Simply returns true if the object is this class's prototype object.
    // There is no need to return any value due to the object is not a platform
    // object. The execution reaches here when Object.getOwnPropertyDescriptor
    // gets called on native object prototypes.
    return true;
  }

  MozjsGlobalEnvironment* global_environment =
      static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<NamedGetterInterface>())) {
    MozjsExceptionState exception(context);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return false;
  }
  MozjsExceptionState exception_state(context);
  JS::RootedValue result_value(context);

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  const size_t kMinArguments = 1;
  if (args.length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return false;
  }
  // Non-optional arguments
  TypeTraits<std::string >::ConversionType name;

  DCHECK_LT(0, args.length());
  JS::RootedValue non_optional_value0(
      context, args[0]);
  FromJSValue(context,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &name);
  if (exception_state.is_exception_set()) {
    return false;
  }

  impl->NamedDeleter(name);
  result_value.set(JS::UndefinedHandleValue);
  return !exception_state.is_exception_set();
}

bool fcn_namedGetter(
    JSContext* context, uint32_t argc, JS::Value *vp) {
  JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  // Compute the 'this' value.
  JS::RootedValue this_value(context, JS_ComputeThis(context, vp));
  // 'this' should be an object.
  JS::RootedObject object(context);
  if (JS_TypeOfValue(context, this_value) != JSTYPE_OBJECT) {
    return false;
  }
  if (!JS_ValueToObject(context, this_value, &object)) {
    NOTREACHED();
    return false;
  }
  const JSClass* proto_class =
      MozjsNamedGetterInterface::PrototypeClass(context);
  if (proto_class == JS_GetClass(object)) {
    // Simply returns true if the object is this class's prototype object.
    // There is no need to return any value due to the object is not a platform
    // object. The execution reaches here when Object.getOwnPropertyDescriptor
    // gets called on native object prototypes.
    return true;
  }

  MozjsGlobalEnvironment* global_environment =
      static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<NamedGetterInterface>())) {
    MozjsExceptionState exception(context);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return false;
  }
  MozjsExceptionState exception_state(context);
  JS::RootedValue result_value(context);

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  const size_t kMinArguments = 1;
  if (args.length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return false;
  }
  // Non-optional arguments
  TypeTraits<std::string >::ConversionType name;

  DCHECK_LT(0, args.length());
  JS::RootedValue non_optional_value0(
      context, args[0]);
  FromJSValue(context,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &name);
  if (exception_state.is_exception_set()) {
    return false;
  }

  if (!exception_state.is_exception_set()) {
    ToJSValue(context,
              impl->NamedGetter(name),
              &result_value);
  }
  if (!exception_state.is_exception_set()) {
    args.rval().set(result_value);
  }
  return !exception_state.is_exception_set();
}

bool fcn_namedSetter(
    JSContext* context, uint32_t argc, JS::Value *vp) {
  JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
  // Compute the 'this' value.
  JS::RootedValue this_value(context, JS_ComputeThis(context, vp));
  // 'this' should be an object.
  JS::RootedObject object(context);
  if (JS_TypeOfValue(context, this_value) != JSTYPE_OBJECT) {
    return false;
  }
  if (!JS_ValueToObject(context, this_value, &object)) {
    NOTREACHED();
    return false;
  }
  const JSClass* proto_class =
      MozjsNamedGetterInterface::PrototypeClass(context);
  if (proto_class == JS_GetClass(object)) {
    // Simply returns true if the object is this class's prototype object.
    // There is no need to return any value due to the object is not a platform
    // object. The execution reaches here when Object.getOwnPropertyDescriptor
    // gets called on native object prototypes.
    return true;
  }

  MozjsGlobalEnvironment* global_environment =
      static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
  WrapperFactory* wrapper_factory = global_environment->wrapper_factory();
  if (!wrapper_factory->DoesObjectImplementInterface(
        object, base::GetTypeId<NamedGetterInterface>())) {
    MozjsExceptionState exception(context);
    exception.SetSimpleException(script::kDoesNotImplementInterface);
    return false;
  }
  MozjsExceptionState exception_state(context);
  JS::RootedValue result_value(context);

  WrapperPrivate* wrapper_private =
      WrapperPrivate::GetFromObject(context, object);
  NamedGetterInterface* impl =
      wrapper_private->wrappable<NamedGetterInterface>().get();
  const size_t kMinArguments = 2;
  if (args.length() < kMinArguments) {
    exception_state.SetSimpleException(script::kInvalidNumberOfArguments);
    return false;
  }
  // Non-optional arguments
  TypeTraits<std::string >::ConversionType name;
  TypeTraits<std::string >::ConversionType value;

  DCHECK_LT(0, args.length());
  JS::RootedValue non_optional_value0(
      context, args[0]);
  FromJSValue(context,
              non_optional_value0,
              kNoConversionFlags,
              &exception_state, &name);
  if (exception_state.is_exception_set()) {
    return false;
  }

  DCHECK_LT(1, args.length());
  JS::RootedValue non_optional_value1(
      context, args[1]);
  FromJSValue(context,
              non_optional_value1,
              kNoConversionFlags,
              &exception_state, &value);
  if (exception_state.is_exception_set()) {
    return false;
  }

  impl->NamedSetter(name, value);
  result_value.set(JS::UndefinedHandleValue);
  return !exception_state.is_exception_set();
}

const JSPropertySpec prototype_properties[] = {
  JS_PS_END
};

const JSFunctionSpec prototype_functions[] = {
  JS_FNSPEC(
      "namedDeleter", fcn_namedDeleter, NULL,
      1, JSPROP_ENUMERATE, NULL),
  JS_FNSPEC(
      "namedGetter", fcn_namedGetter, NULL,
      1, JSPROP_ENUMERATE, NULL),
  JS_FNSPEC(
      "namedSetter", fcn_namedSetter, NULL,
      2, JSPROP_ENUMERATE, NULL),
  JS_FS_END
};

const JSPropertySpec interface_object_properties[] = {
  JS_PS_END
};

const JSFunctionSpec interface_object_functions[] = {
  JS_FS_END
};

const JSPropertySpec own_properties[] = {
  JS_PS_END
};

void InitializePrototypeAndInterfaceObject(
    InterfaceData* interface_data, JSContext* context,
    JS::HandleObject global_object) {
  DCHECK(!interface_data->prototype);
  DCHECK(!interface_data->interface_object);
  DCHECK(JS_IsGlobalObject(global_object));

  JS::RootedObject parent_prototype(
      context, JS_GetObjectPrototype(context, global_object));
  DCHECK(parent_prototype);

  interface_data->prototype = JS_NewObjectWithGivenProto(
    context, &prototype_class_definition, parent_prototype
  );

  JS::RootedObject rooted_prototype(context, interface_data->prototype);
  bool success = JS_DefineProperties(
      context,
      rooted_prototype,
      prototype_properties);

  DCHECK(success);
  success = JS_DefineFunctions(
      context, rooted_prototype, prototype_functions);
  DCHECK(success);

  JS::RootedObject function_prototype(
      context, JS_GetFunctionPrototype(context, global_object));
  DCHECK(function_prototype);

  const char name[] =
      "NamedGetterInterface";

  JSFunction* function = js::NewFunctionWithReserved(
      context,
      DummyConstructor,
      0,
      JSFUN_CONSTRUCTOR,
      name);
  interface_data->interface_object = JS_GetFunctionObject(function);

  // Add the InterfaceObject.name property.
  JS::RootedObject rooted_interface_object(
      context, interface_data->interface_object);
  JS::RootedValue name_value(context);

  js::SetPrototype(context, rooted_interface_object, function_prototype);

  name_value.setString(JS_NewStringCopyZ(context, name));
  success = JS_DefineProperty(
      context, rooted_interface_object, "name", name_value, JSPROP_READONLY,
      NULL, NULL);
  DCHECK(success);

  // Define interface object properties (excluding constants).
  success = JS_DefineProperties(context, rooted_interface_object,
                                interface_object_properties);
  DCHECK(success);

  // Define interface object functions (static).
  success = JS_DefineFunctions(context, rooted_interface_object,
                               interface_object_functions);
  DCHECK(success);

  // Set the Prototype.constructor and Constructor.prototype properties.
  DCHECK(interface_data->interface_object);
  DCHECK(interface_data->prototype);
  success = JS_LinkConstructorAndPrototype(
      context,
      rooted_interface_object,
      rooted_prototype);
  DCHECK(success);
}

inline InterfaceData* GetInterfaceData(JSContext* context) {
  const int kInterfaceUniqueId = 33;
  MozjsGlobalEnvironment* global_environment =
      static_cast<MozjsGlobalEnvironment*>(JS_GetContextPrivate(context));
  // By convention, the |MozjsGlobalEnvironment| that we are associated with
  // will hold our |InterfaceData| at index |kInterfaceUniqueId|, as we asked
  // for it to be there in the first place, and could not have conflicted with
  // any other interface.
  return global_environment->GetInterfaceData(kInterfaceUniqueId);
}

}  // namespace

// static
JSObject* MozjsNamedGetterInterface::CreateProxy(
    JSContext* context, const scoped_refptr<Wrappable>& wrappable) {
  DCHECK(MozjsGlobalEnvironment::GetFromContext(context));
  JS::RootedObject global_object(
      context,
      MozjsGlobalEnvironment::GetFromContext(context)->global_object());
  DCHECK(global_object);

  JSAutoCompartment auto_compartment(context, global_object);
  InterfaceData* interface_data = GetInterfaceData(context);
  JS::RootedObject prototype(context, GetPrototype(context, global_object));
  DCHECK(prototype);
  JS::RootedObject new_object(
      context,
      JS_NewObjectWithGivenProto(
          context, &instance_class_definition, prototype));
  DCHECK(new_object);
  JS::RootedObject proxy(context,
      ProxyHandler::NewProxy(
          context, proxy_handler.Pointer(), new_object, prototype));
  WrapperPrivate::AddPrivateData(context, proxy, wrappable);
  return proxy;
}

// static
const JSClass* MozjsNamedGetterInterface::PrototypeClass(
      JSContext* context) {
  DCHECK(MozjsGlobalEnvironment::GetFromContext(context));
  JS::RootedObject global_object(
      context,
      MozjsGlobalEnvironment::GetFromContext(context)->global_object());
  DCHECK(global_object);

  JS::RootedObject prototype(context, GetPrototype(context, global_object));
  const JSClass* proto_class = JS_GetClass(prototype);
  return proto_class;
}

// static
JSObject* MozjsNamedGetterInterface::GetPrototype(
    JSContext* context, JS::HandleObject global_object) {
  DCHECK(JS_IsGlobalObject(global_object));

  InterfaceData* interface_data = GetInterfaceData(context);
  if (!interface_data->prototype) {
    // Create new prototype that has all the props and methods
    InitializePrototypeAndInterfaceObject(
        interface_data, context, global_object);
  }
  DCHECK(interface_data->prototype);
  return interface_data->prototype;
}

// static
JSObject* MozjsNamedGetterInterface::GetInterfaceObject(
    JSContext* context, JS::HandleObject global_object) {
  DCHECK(JS_IsGlobalObject(global_object));

  InterfaceData* interface_data = GetInterfaceData(context);
  if (!interface_data->interface_object) {
    InitializePrototypeAndInterfaceObject(
        interface_data, context, global_object);
  }
  DCHECK(interface_data->interface_object);
  return interface_data->interface_object;
}

namespace {


}  // namespace


}  // namespace testing
}  // namespace bindings
}  // namespace cobalt



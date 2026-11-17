/**
 * Titanium SDK
 * Copyright TiDev, Inc. 04/07/2022-Present
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "ti.blurview.BlurViewProxy.h"

#include "JSException.h"
#include "TypeConverter.h"


#include "org.appcelerator.titanium.proxy.TiViewProxy.h"

#define TAG "BlurViewProxy"

using namespace v8;

namespace ti {
namespace blurview {
	namespace tiview {


Persistent<FunctionTemplate> BlurViewProxy::proxyTemplate;
Persistent<Object> BlurViewProxy::moduleInstance;
jclass BlurViewProxy::javaClass = NULL;

BlurViewProxy::BlurViewProxy() : titanium::Proxy()
{
}

void BlurViewProxy::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "BlurView"); // use symbol over string for efficiency
	exports->Set(context, nameSymbol, constructor);
	exports->Set(context, constructorSymbol.Get(isolate), constructor);
}

void BlurViewProxy::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}
	if (!moduleInstance.IsEmpty()) {
	    moduleInstance.Reset();
	}

	titanium::TiViewProxy::dispose(isolate);
}

Local<FunctionTemplate> BlurViewProxy::getProxyTemplate(v8::Isolate* isolate)
{
	Local<Context> context = isolate->GetCurrentContext();
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "BlurViewProxy::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("ti/blurview/BlurViewProxy");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "BlurView");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		isolate,
		titanium::TiViewProxy::getProxyTemplate(isolate),
		javaClass,
		nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate), FunctionTemplate::New(isolate, titanium::Proxy::inherit<BlurViewProxy>));

	// Method bindings --------------------------------------------------------

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "backgroundColor"),
		titanium::Proxy::getProperty,
		BlurViewProxy::setter_backgroundColor,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "blurRadius"),
		BlurViewProxy::getter_blurRadius,
		BlurViewProxy::setter_blurRadius,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::DontDelete)
	);

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

Local<FunctionTemplate> BlurViewProxy::getProxyTemplate(v8::Local<v8::Context> context)
{
	return getProxyTemplate(context->GetIsolate());
}

// Methods --------------------------------------------------------------------

// Dynamic property accessors -------------------------------------------------


void BlurViewProxy::setter_backgroundColor(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, backgroundColor wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BlurViewProxy::javaClass, "backgroundColor", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'backgroundColor' with signature '(I)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		MaybeLocal<Number> arg_0 = value->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			jArguments[0].i = NULL;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




	Proxy::setProperty(property, value, args);
}


void BlurViewProxy::getter_blurRadius(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BlurViewProxy::javaClass, "blurRadius", "()I");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'blurRadius' with signature '()I'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jint jResult = (jint)env->CallIntMethodA(javaProxy, methodID, jArguments);


	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Number> v8Result = titanium::TypeConverter::javaIntToJsNumber(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}

void BlurViewProxy::setter_blurRadius(Local<Name> property, Local<Value> value, const PropertyCallbackInfo<void>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		LOGE(TAG, "Failed to get environment, blurRadius wasn't set");
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();

	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(BlurViewProxy::javaClass, "blurRadius", "(I)V");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'blurRadius' with signature '(I)V'";
			LOGE(TAG, error);
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		if (!moduleInstance.IsEmpty()) {
			holder = moduleInstance.Get(isolate);
			if (holder.IsEmpty() || holder->IsNull()) {
				LOGE(TAG, "Couldn't obtain argument holder");
				args.GetReturnValue().Set(v8::Undefined(isolate));
				return;
			}
		} else {
			LOGE(TAG, "Couldn't obtain argument holder");
			args.GetReturnValue().Set(v8::Undefined(isolate));
			return;
		}
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		return;
	}

	jvalue jArguments[1];

	
		if ((titanium::V8Util::isNaN(isolate, value) && !value->IsUndefined()) || value->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
		}
	if (!value->IsNull()) {
		MaybeLocal<Number> arg_0 = value->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			jArguments[0].i = NULL;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		return;
	}
	env->CallVoidMethodA(javaProxy, methodID, jArguments);

	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
	}




}



	} // namespace tiview
} // blurview
} // ti

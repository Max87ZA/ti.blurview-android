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

	// Accessors --------------------------------------------------------------
	Local<String> blurRadius = NEW_SYMBOL(isolate, "blurRadius");
	instanceTemplate->SetAccessor(
		blurRadius,
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	Local<String> mode = NEW_SYMBOL(isolate, "mode");
	instanceTemplate->SetAccessor(
		mode,
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	Local<String> indicator = NEW_SYMBOL(isolate, "indicator");
	instanceTemplate->SetAccessor(
		indicator,
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);
	Local<String> indicatorColor = NEW_SYMBOL(isolate, "indicatorColor");
	instanceTemplate->SetAccessor(
		indicatorColor,
		titanium::Proxy::getProperty,
		titanium::Proxy::onPropertyChanged);

	return scope.Escape(t);
}

Local<FunctionTemplate> BlurViewProxy::getProxyTemplate(v8::Local<v8::Context> context)
{
	return getProxyTemplate(context->GetIsolate());
}

// Methods --------------------------------------------------------------------

// Dynamic property accessors -------------------------------------------------


	} // namespace tiview
} // blurview
} // ti

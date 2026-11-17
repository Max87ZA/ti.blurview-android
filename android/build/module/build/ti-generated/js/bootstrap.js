/**
 * Titanium SDK
 * Copyright TiDev, Inc. 04/07/2022-Present
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * Warning: This file is GENERATED, and should not be modified
 */
var bootstrap = kroll.NativeModule.require("bootstrap"),
	invoker = kroll.NativeModule.require("invoker"),
	Titanium = kroll.binding("Titanium").Titanium;

function moduleBootstrap(moduleBinding) {
	function lazyGet(object, binding, name, namespace) {
		return bootstrap.lazyGet(object, binding,
			name, namespace, moduleBinding.getBinding);
	}

	var module = moduleBinding.getBinding("ti.blurview.TiBlurViewModule")["TiView"];
	var invocationAPIs = module.invocationAPIs = [];
	module.apiName = "TiView";

	function addInvocationAPI(module, moduleNamespace, namespace, api) {
		invocationAPIs.push({ namespace: namespace, api: api });
	}

	addInvocationAPI(module, "TiView", "TiView", "createBlurView");
		if (!("__propertiesDefined__" in module)) {Object.defineProperties(module, {
"BlurView": {
get: function() {
var BlurView =  lazyGet(this, "ti.blurview.BlurViewProxy", "BlurView", "BlurView");
return BlurView;
},
configurable: true
},

});
module.constructor.prototype.createBlurView = function() {
return new module["BlurView"](arguments);
}
}
module.__propertiesDefined__ = true;
return module;

}
exports.bootstrap = moduleBootstrap;

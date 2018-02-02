'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Js_boolean  = require("bs-platform/lib/js/js_boolean.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Textarea");

function make(className, onChange, value, _) {
  var newrecord = component.slice();
  newrecord[/* willReceiveProps */3] = (function () {
      return value;
    });
  newrecord[/* render */9] = (function (param) {
      var send = param[/* send */4];
      return React.createElement("textarea", {
                  className: className,
                  spellCheck: Js_boolean.to_js_boolean(/* true */1),
                  autoFocus: Js_boolean.to_js_boolean(/* true */1),
                  value: param[/* state */2],
                  onChange: (function ($$event) {
                      var value = $$event.target.value;
                      return Curry._1(send, /* HandleChange */[value]);
                    })
                });
    });
  newrecord[/* initialState */10] = (function () {
      return value;
    });
  newrecord[/* reducer */12] = (function (action, _) {
      var value = action[0];
      Curry._1(onChange, value);
      return /* Update */Block.__(0, [value]);
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */

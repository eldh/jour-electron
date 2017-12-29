'use strict';

var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Input");

function make($staropt$star, onChange, value, _) {
  var styles = $staropt$star ? $staropt$star[0] : /* [] */0;
  var newrecord = component.slice();
  newrecord[/* willReceiveProps */3] = (function () {
      return value;
    });
  newrecord[/* render */9] = (function (param) {
      var className = Glamor.css(/* :: */[
            Glamor.background("rgb(37, 37, 37)"),
            /* :: */[
              Glamor.padding("5px"),
              /* :: */[
                Glamor.border("1px rgb(75, 75, 75) solid"),
                styles
              ]
            ]
          ]);
      return React.createElement("input", {
                  className: className,
                  type: "text",
                  value: param[/* state */2],
                  onChange: Curry._1(param[/* reduce */1], (function (e) {
                          return /* HandleChange */[e];
                        }))
                });
    });
  newrecord[/* initialState */10] = (function () {
      return value;
    });
  newrecord[/* reducer */12] = (function (action, _) {
      return Curry._1(onChange, action[0].target.value);
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */

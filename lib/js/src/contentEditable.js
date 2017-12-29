'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("ContentEditable");

function setRef(theRef, param) {
  param[/* state */2][/* myRef */1][0] = (theRef == null) ? /* None */0 : [theRef];
  return /* () */0;
}

function make($staropt$star, onChange, $staropt$star$1, _) {
  var styles = $staropt$star ? $staropt$star[0] : /* [] */0;
  var html = $staropt$star$1 ? $staropt$star$1[0] : "";
  var newrecord = component.slice();
  newrecord[/* willReceiveProps */3] = (function (param) {
      var state = param[/* state */2];
      var match = +(html === state[/* html */0]);
      if (match !== 0) {
        return /* record */[
                /* html */html,
                /* myRef */state[/* myRef */1]
              ];
      } else {
        return state;
      }
    });
  newrecord[/* render */9] = (function (param) {
      var className = Glamor.css(styles);
      return React.createElement("div", {
                  ref: Curry._1(param[/* handle */0], setRef),
                  className: className,
                  contentEditable: true,
                  onInput: Curry._1(param[/* reduce */1], (function () {
                          return /* HandleChange */0;
                        })),
                  dangerouslySetInnerHTML: {
                    __html: param[/* state */2][/* html */0]
                  }
                });
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* html */html,
              /* myRef */[/* None */0]
            ];
    });
  newrecord[/* reducer */12] = (function (_, state) {
      var match = state[/* myRef */1][0];
      if (match) {
        Curry._1(onChange, match[0].innerHTML);
      }
      return /* Update */Block.__(0, [state]);
    });
  return newrecord;
}

exports.component = component;
exports.setRef    = setRef;
exports.make      = make;
/* component Not a pure module */

'use strict';

var S           = require("./s.js");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("AppContainer");

var className = Glamor.css(/* :: */[
      Glamor.paddingTop(S.constants[/* headerHeight */0]),
      /* :: */[
        Glamor.backgroundColor("#0a0a0a"),
        /* [] */0
      ]
    ]);

function make(children) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return ReasonReact.createDomElement("div", {
                  className: className
                }, children);
    });
  return newrecord;
}

exports.component = component;
exports.className = className;
exports.make      = make;
/* component Not a pure module */

'use strict';

var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Pre");

function make($staropt$star, children) {
  var styles = $staropt$star ? $staropt$star[0] : /* [] */0;
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      var className = Glamor.css(/* :: */[
            Glamor.whiteSpace("pre-wrap"),
            styles
          ]);
      return React.createElement("div", {
                  className: className
                }, children);
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */

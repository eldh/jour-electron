'use strict';

var H           = require("./h.js");
var $$Date      = require("./date.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var className = Glamor.css(/* :: */[
      Glamor.width("100vw"),
      /* :: */[
        Glamor.height("40px"),
        /* [] */0
      ]
    ]);

var component = ReasonReact.statelessComponent("PostHeader");

function make(post, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: className
                }, H.se($$Date.format(/* DMY */1, post[/* date */0])));
    });
  return newrecord;
}

exports.className = className;
exports.component = component;
exports.make      = make;
/* className Not a pure module */

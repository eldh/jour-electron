'use strict';

var H           = require("./h.js");
var $$Date      = require("./date.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var PreText     = require("./preText.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var base_000 = Glamor.flexGrow("1");

var base_001 = /* :: */[
  Glamor.padding("20px"),
  /* [] */0
];

var base = /* :: */[
  base_000,
  base_001
];

var component = ReasonReact.statelessComponent("DiaryRow");

function make(date, onClick, post, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      var textColor;
      if (post) {
        var match = $$Date.equals(post[0][/* date */0], date);
        textColor = match !== 0 ? "white" : "#6f6f6f";
      } else {
        textColor = "#6f6f6f";
      }
      var tmp;
      if (post) {
        var p = post[0];
        var match$1 = $$Date.equals(p[/* date */0], date);
        tmp = match$1 !== 0 ? H.se(p[/* content */1]) : H.$$null;
      } else {
        tmp = H.$$null;
      }
      return React.createElement("li", {
                  className: Glamor.css(/* :: */[
                        Glamor.color(textColor),
                        base
                      ]),
                  onClick: onClick
                }, React.createElement("div", undefined, H.se($$Date.format(/* DMY */1, date))), ReasonReact.element(/* None */0, /* None */0, PreText.make(/* Some */[/* :: */[
                            Glamor.padding("20px 0"),
                            /* [] */0
                          ]], /* array */[tmp])));
    });
  return newrecord;
}

exports.base      = base;
exports.component = component;
exports.make      = make;
/* base Not a pure module */

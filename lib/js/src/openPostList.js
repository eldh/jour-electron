'use strict';

var H           = require("./h.js");
var S           = require("./s.js");
var $$Date      = require("./date.js");
var $$Array     = require("bs-platform/lib/js/array.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var className = Glamor.css(/* :: */[
      Glamor.position("absolute"),
      /* :: */[
        Glamor.top("0"),
        /* :: */[
          Glamor.left("0"),
          /* :: */[
            Glamor.height("100vh"),
            /* :: */[
              Glamor.maxWidth("400px"),
              /* :: */[
                Glamor.background("rgb(40, 40, 40)"),
                /* :: */[
                  Glamor.color("white"),
                  S.flex
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var component = ReasonReact.statelessComponent("OpenPostList");

function make(posts, date, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: className
                }, date ? H.se($$Date.format(/* YYYYMMDD */0, date[0])) : null, React.createElement("ul", undefined, $$Array.map((function (date) {
                            return React.createElement("li", undefined, H.se($$Date.format(/* YYYYMMDD */0, date)));
                          }), posts)));
    });
  return newrecord;
}

exports.className = className;
exports.component = component;
exports.make      = make;
/* className Not a pure module */

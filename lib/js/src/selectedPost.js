'use strict';

var H                       = require("./h.js");
var $$Date                  = require("./date.js");
var React                   = require("react");
var Glamor                  = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact             = require("reason-react/lib/js/src/ReasonReact.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

var className = Glamor.css(/* :: */[
      Glamor.background("rgba(0, 0, 0, 0.2)"),
      /* :: */[
        Glamor.color("white"),
        /* :: */[
          Glamor.flexDirection("row"),
          /* :: */[
            Glamor.justifyContent("center"),
            /* :: */[
              Glamor.alignContent("center"),
              /* :: */[
                Glamor.alignItems("center"),
                /* :: */[
                  Glamor.flexGrow("1"),
                  /* :: */[
                    Glamor.width("100vw"),
                    /* :: */[
                      Glamor.height("100vh"),
                      /* [] */0
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

function postIsOnDate(date, post) {
  return $$Date.equals(date, post[/* date */0]);
}

var component = ReasonReact.statelessComponent("SelectedPost");

function make(date, posts, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      var match = posts.find((function (param) {
              return $$Date.equals(date, param);
            }));
      var date$1;
      if (match !== undefined) {
        date$1 = match;
      } else {
        throw Caml_builtin_exceptions.not_found;
      }
      return React.createElement("div", {
                  className: className
                }, React.createElement("div", undefined, H.se("Post date is " + $$Date.format(/* DMY */1, date$1))));
    });
  return newrecord;
}

exports.className    = className;
exports.postIsOnDate = postIsOnDate;
exports.component    = component;
exports.make         = make;
/* className Not a pure module */

'use strict';

var S            = require("./s.js");
var $$Date       = require("./date.js");
var Curry        = require("bs-platform/lib/js/curry.js");
var React        = require("react");
var Glamor       = require("bs-glamor/lib/js/src/glamor.js");
var PostHeader   = require("./postHeader.js");
var StoryInput   = require("./storyInput.js");
var ReasonReact  = require("reason-react/lib/js/src/ReasonReact.js");
var DateSwitcher = require("./dateSwitcher.js");

var className = S.css(/* :: */[
      S.flex,
      /* :: */[
        S.center,
        /* :: */[
          /* :: */[
            Glamor.backgroundColor("#0a0a0a"),
            /* :: */[
              Glamor.color("white"),
              /* :: */[
                Glamor.flexGrow("1"),
                /* :: */[
                  Glamor.width("100vw"),
                  /* :: */[
                    Glamor.height("calc(100vh - 40px)"),
                    /* [] */0
                  ]
                ]
              ]
            ]
          ],
          /* [] */0
        ]
      ]
    ]);

function postIsOnDate(date, post) {
  return $$Date.equals(date, post[/* date */0]);
}

var component = ReasonReact.statelessComponent("ComposePost");

function make(fullscreen, updateDate, dateWarning, onChange, post, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: className
                }, dateWarning !== 0 ? ReasonReact.element(/* None */0, /* None */0, DateSwitcher.make((function () {
                              return Curry._1(updateDate, /* () */0);
                            }), /* None */0, /* array */[])) : ReasonReact.element(/* None */0, /* None */0, PostHeader.make(post, fullscreen, /* array */[])), ReasonReact.element(/* None */0, /* None */0, StoryInput.make(onChange, post[/* content */1], /* array */[])));
    });
  return newrecord;
}

exports.className    = className;
exports.postIsOnDate = postIsOnDate;
exports.component    = component;
exports.make         = make;
/* className Not a pure module */

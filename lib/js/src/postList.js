'use strict';

var H           = require("./h.js");
var $$Date      = require("./date.js");
var $$Array     = require("bs-platform/lib/js/array.js");
var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var State       = require("./state.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var Actions     = require("./actions.js");
var DiaryRow    = require("./diaryRow.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var className = Glamor.css(/* :: */[
      Glamor.background("rgba(0, 0, 0, 0.2)"),
      /* :: */[
        Glamor.color("white"),
        /* :: */[
          Glamor.listStyleType("none"),
          /* :: */[
            Glamor.fontFamily("Menlo"),
            /* :: */[
              Glamor.color("#6f6f6f"),
              /* :: */[
                Glamor.width("calc(100% - 26px)"),
                /* :: */[
                  Glamor.maxWidth("600px"),
                  /* :: */[
                    Glamor.paddingLeft("0"),
                    /* :: */[
                      Glamor.margin("auto"),
                      /* :: */[
                        Glamor.minHeight("100vh"),
                        /* [] */0
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]);

var component = ReasonReact.reducerComponent("PostList");

function make(posts, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (self) {
      var getDiaryRow = function (date) {
        return ReasonReact.element(/* Some */[$$Date.format(/* YYYYMMDD */0, date)], /* None */0, DiaryRow.make(date, (function () {
                          var self$1 = self;
                          var date$1 = date;
                          var match = self$1[/* state */2][/* date */0];
                          if (match && $$Date.equals(date$1, match[0])) {
                            return Curry._2(self$1[/* reduce */1], (function () {
                                          return /* SetState */[
                                                  State.emptyPost,
                                                  /* None */0
                                                ];
                                        }), /* () */0);
                          } else {
                            return Actions.getPost((function (post) {
                                          return Curry._2(self$1[/* reduce */1], (function () {
                                                        return /* SetState */[
                                                                post,
                                                                /* Some */[date$1]
                                                              ];
                                                      }), /* () */0);
                                        }), date$1);
                          }
                        }), /* Some */[self[/* state */2][/* post */1]], /* array */[]));
      };
      return React.createElement("ul", {
                  className: className
                }, H.ae($$Array.map(getDiaryRow, posts)));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* date : None */0,
              /* post */State.emptyPost
            ];
    });
  newrecord[/* reducer */12] = (function (action, _) {
      return /* Update */Block.__(0, [/* record */[
                  /* date */action[1],
                  /* post */action[0]
                ]]);
    });
  return newrecord;
}

exports.className = className;
exports.component = component;
exports.make      = make;
/* className Not a pure module */

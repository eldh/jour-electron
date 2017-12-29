'use strict';

var H           = require("./h.js");
var S           = require("./s.js");
var Block       = require("bs-platform/lib/js/block.js");
var React       = require("react");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

function className(fullscreen) {
  return S.css(/* :: */[
              fullscreen !== 0 ? /* :: */[
                  Glamor.height("60px"),
                  /* [] */0
                ] : /* :: */[
                  Glamor.height("40px"),
                  /* [] */0
                ],
              /* :: */[
                S.flex,
                /* :: */[
                  S.center,
                  /* :: */[
                    /* :: */[
                      Glamor.position("fixed"),
                      /* :: */[
                        Glamor.top("0"),
                        /* :: */[
                          Glamor.left("0"),
                          /* :: */[
                            Glamor.backgroundColor("rgb(10, 10, 10)"),
                            /* :: */[
                              Glamor.fontFamily("Menlo"),
                              /* :: */[
                                Glamor.color("#6f6f6f"),
                                /* :: */[
                                  Glamor.width("100vw"),
                                  /* :: */[
                                    Glamor.borderBottom("1px rgba(0, 0, 0, 0.2) solid"),
                                    /* :: */[
                                      Glamor.backgroundColor("#444444"),
                                      /* :: */[
                                        Glamor.cursor("pointer"),
                                        /* :: */[
                                          Glamor.color("#ffffff"),
                                          /* :: */[
                                            Glamor.transition("background-color 0.2s ease"),
                                            /* :: */[
                                              /* Selector */Block.__(1, [
                                                  ":hover",
                                                  /* :: */[
                                                    Glamor.backgroundColor("#449922"),
                                                    /* [] */0
                                                  ]
                                                ]),
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
                          ]
                        ]
                      ]
                    ],
                    /* [] */0
                  ]
                ]
              ]
            ]);
}

var component = ReasonReact.statelessComponent("PostHeader");

function make(onClick, $staropt$star, _) {
  var fullscreen = $staropt$star ? $staropt$star[0] : /* false */0;
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: className(fullscreen),
                  onClick: onClick
                }, H.se("It's a new day. Click to start your next story."));
    });
  return newrecord;
}

exports.className = className;
exports.component = component;
exports.make      = make;
/* component Not a pure module */

'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Glamor      = require("bs-glamor/lib/js/src/glamor.js");
var Textarea    = require("./textarea.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("StoryInput");

var className = Glamor.css(/* :: */[
      Glamor.display("flex"),
      /* :: */[
        Glamor.border("0"),
        /* :: */[
          Glamor.width("calc(100% - 26px)"),
          /* :: */[
            Glamor.maxWidth("600px"),
            /* :: */[
              Glamor.height("calc(100% - 26px)"),
              /* :: */[
                Glamor.color("rgb(200, 200, 200)"),
                /* :: */[
                  Glamor.lineHeight("1.5em"),
                  /* :: */[
                    Glamor.fontSize("14px"),
                    /* :: */[
                      Glamor.padding("13px"),
                      /* :: */[
                        Glamor.borderRadius("0"),
                        /* :: */[
                          Glamor.fontFamily("Menlo"),
                          /* :: */[
                            Glamor.resize("none"),
                            /* :: */[
                              Glamor.background("#0a0a0a"),
                              /* :: */[
                                Glamor.outline("0"),
                                /* :: */[
                                  /* Selector */Block.__(1, [
                                      ":focus",
                                      /* :: */[
                                        Glamor.outline("0"),
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
        ]
      ]
    ]);

function make(onChange, value, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return ReasonReact.element(/* None */0, /* None */0, Textarea.make(className, onChange, value, /* array */[]));
    });
  return newrecord;
}

exports.component = component;
exports.className = className;
exports.make      = make;
/* component Not a pure module */

'use strict';

var List   = require("bs-platform/lib/js/list.js");
var Glamor = require("bs-glamor/lib/js/src/glamor.js");

var flex_000 = Glamor.display("flex");

var flex_001 = /* :: */[
  Glamor.flexDirection("column"),
  /* :: */[
    Glamor.boxSizing("border-box"),
    /* :: */[
      Glamor.position("relative"),
      /* :: */[
        Glamor.display("flex"),
        /* :: */[
          Glamor.alignItems("stretch"),
          /* [] */0
        ]
      ]
    ]
  ]
];

var flex = /* :: */[
  flex_000,
  flex_001
];

var center_000 = Glamor.justifyContent("center");

var center_001 = /* :: */[
  Glamor.alignContent("center"),
  /* :: */[
    Glamor.alignItems("center"),
    /* [] */0
  ]
];

var center = /* :: */[
  center_000,
  center_001
];

function css(l) {
  return Glamor.css(List.concat(l));
}

var constants = /* record */[/* headerHeight */"40px"];

exports.flex      = flex;
exports.center    = center;
exports.css       = css;
exports.constants = constants;
/* flex Not a pure module */

'use strict';

var $$Date       = require("./date.js");
var Block        = require("bs-platform/lib/js/block.js");
var Curry        = require("bs-platform/lib/js/curry.js");
var Event        = require("./event.js");
var State        = require("./state.js");
var Actions      = require("./actions.js");
var PostList     = require("./postList.js");
var Electron     = require("electron");
var ComposePost  = require("./composePost.js");
var ReasonReact  = require("reason-react/lib/js/src/ReasonReact.js");
var AppContainer = require("./appContainer.js");

var component = ReasonReact.reducerComponent("JourApp");

function make() {
  var intervalId = [/* None */0];
  var newrecord = component.slice();
  newrecord[/* didMount */4] = (function (self) {
      var setNow = function () {
        return Curry._2(self[/* reduce */1], (function (now) {
                      return /* SetNow */Block.__(3, [now]);
                    }), $$Date.today(/* () */0));
      };
      intervalId[0] = /* Some */[setInterval(setNow, 1000)];
      Electron.ipcRenderer.on(Event.openDiary, Curry._1(self[/* reduce */1], (function () {
                  return /* ToggleDiary */0;
                })));
      if (self[/* state */2][/* posts */2] === State.emptyPosts) {
        Actions.getPosts(Curry._1(self[/* reduce */1], (function (posts) {
                    return /* SetPosts */Block.__(0, [posts]);
                  })));
      }
      if (self[/* state */2][/* post */1] === State.emptyPost) {
        Actions.getPost(Curry._1(self[/* reduce */1], (function (post) {
                    return /* SetPost */Block.__(1, [post]);
                  })), self[/* state */2][/* initialDate */3]);
      }
      return /* NoUpdate */0;
    });
  newrecord[/* willUnmount */6] = (function () {
      var match = intervalId[0];
      if (match) {
        clearInterval(match[0]);
        return /* () */0;
      } else {
        return /* () */0;
      }
    });
  newrecord[/* render */9] = (function (param) {
      var state = param[/* state */2];
      var reduce = param[/* reduce */1];
      var match = state[/* view */5];
      var content;
      if (match !== 0) {
        content = ReasonReact.element(/* None */0, /* None */0, PostList.make(state[/* posts */2], /* array */[]));
      } else {
        var partial_arg = state[/* post */1][/* date */0];
        content = ReasonReact.element(/* None */0, /* None */0, ComposePost.make(state[/* fullscreen */4], (function (e) {
                    return Curry._2(reduce, (function () {
                                  return /* SetInitialDate */Block.__(2, [$$Date.today(/* () */0)]);
                                }), e);
                  }), 1 - $$Date.equals(state[/* initialDate */3], state[/* now */0]), Curry._1(reduce, (function (param) {
                        var date = partial_arg;
                        var content = param;
                        var post = /* record */[
                          /* date */date,
                          /* content */content
                        ];
                        Actions.savePost(post);
                        return /* SetPost */Block.__(1, [post]);
                      })), state[/* post */1], /* array */[]));
      }
      return ReasonReact.element(/* None */0, /* None */0, AppContainer.make(/* array */[content]));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* now */$$Date.today(/* () */0),
              /* post */State.emptyPost,
              /* posts */State.emptyPosts,
              /* initialDate */$$Date.today(/* () */0),
              /* fullscreen : false */0,
              /* view : Compose */0
            ];
    });
  newrecord[/* reducer */12] = (function (action, state) {
      if (typeof action === "number") {
        if (action) {
          var newrecord = state.slice();
          return /* Update */Block.__(0, [(newrecord[/* fullscreen */4] = 1 - state[/* fullscreen */4], newrecord)]);
        } else {
          var newrecord$1 = state.slice();
          var match = +(state[/* view */5] === /* Diary */1);
          newrecord$1[/* view */5] = match !== 0 ? /* Compose */0 : /* Diary */1;
          return /* Update */Block.__(0, [newrecord$1]);
        }
      } else {
        switch (action.tag | 0) {
          case 0 : 
              var newrecord$2 = state.slice();
              return /* Update */Block.__(0, [(newrecord$2[/* posts */2] = action[0], newrecord$2)]);
          case 1 : 
              var newrecord$3 = state.slice();
              return /* Update */Block.__(0, [(newrecord$3[/* post */1] = action[0], newrecord$3)]);
          case 2 : 
              var newrecord$4 = state.slice();
              return /* Update */Block.__(0, [(newrecord$4[/* initialDate */3] = action[0], newrecord$4)]);
          case 3 : 
              var newrecord$5 = state.slice();
              return /* Update */Block.__(0, [(newrecord$5[/* now */0] = action[0], newrecord$5)]);
          case 4 : 
              var newrecord$6 = state.slice();
              return /* Update */Block.__(0, [(newrecord$6[/* view */5] = action[0], newrecord$6)]);
          
        }
      }
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */

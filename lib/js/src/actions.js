'use strict';

var Curry    = require("bs-platform/lib/js/curry.js");
var Event    = require("./event.js");
var Electron = require("electron");

function getPosts(handle) {
  return Curry._1(handle, Electron.ipcRenderer.sendSync(Event.getPosts, /* () */0));
}

function getPost(handle, date) {
  return Curry._1(handle, Electron.ipcRenderer.sendSync(Event.getPost, date));
}

function handleDiaryOpen(handler) {
  Electron.ipcRenderer.on(Event.openDiary, handler);
  return /* () */0;
}

function savePost(post) {
  Electron.ipcRenderer.send(Event.setPost, post);
  return /* () */0;
}

function removePost(date) {
  Electron.ipcRenderer.send(Event.removePost, date);
  return /* () */0;
}

exports.getPosts        = getPosts;
exports.getPost         = getPost;
exports.handleDiaryOpen = handleDiaryOpen;
exports.savePost        = savePost;
exports.removePost      = removePost;
/* electron Not a pure module */

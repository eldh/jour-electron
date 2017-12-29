'use strict';

var Fs          = require("fs");
var $$Date      = require("./date.js");
var Path        = require("path");
var $$Array     = require("bs-platform/lib/js/array.js");
var Event       = require("./event.js");
var $$String    = require("bs-platform/lib/js/string.js");
var Electron    = require("electron");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

function getDiaryDir() {
  var basePath = Electron.app.getPath("documents");
  var path = Path.join(basePath, ".diary");
  if (!Fs.existsSync(path)) {
    Fs.mkdirSync(path);
  }
  return path;
}

function getFilePathForDate(d) {
  var filename = $$Date.format(/* YYYYMMDD */0, d) + ".md";
  return Path.join(getDiaryDir(/* () */0), filename);
}

function filenameToDate(str) {
  var year = Caml_format.caml_int_of_string($$String.sub(str, 0, 4));
  var month = Caml_format.caml_int_of_string($$String.sub(str, 5, 2));
  var day = Caml_format.caml_int_of_string($$String.sub(str, 8, 2));
  return $$Date.get(year, month, day);
}

function cleanFileList(files) {
  return files.filter((function (f) {
                return +(f !== ".DS_Store");
              }));
}

function getPosts() {
  var files = cleanFileList(Fs.readdirSync(getDiaryDir(/* () */0)));
  return $$Array.map(filenameToDate, files);
}

function savePost(post) {
  var filename = getFilePathForDate(post[/* date */0]);
  Fs.writeFileSync(filename, post[/* content */1]);
  return /* () */0;
}

function removePost(date) {
  var filename = getFilePathForDate(date);
  Fs.unlinkSync(filename);
  return /* () */0;
}

function getPostContent(date) {
  var path = getFilePathForDate(date);
  var match = +Fs.existsSync(path);
  if (match !== 0) {
    return Fs.readFileSync(path, "utf8");
  } else {
    return "";
  }
}

Electron.ipcMain.on(Event.setPost, (function (_, res) {
        try {
          return savePost(res);
        }
        catch (exn){
          console.log("Error saving post");
          return /* () */0;
        }
      }));

Electron.ipcMain.on(Event.removePost, (function (_, res) {
        try {
          return removePost(res);
        }
        catch (exn){
          console.log("Error removing post");
          return /* () */0;
        }
      }));

Electron.ipcMain.on(Event.getPost, (function (e, date) {
        var content;
        try {
          content = getPostContent(date);
        }
        catch (exn){
          console.log("Error fetching post content");
          content = "";
        }
        var post = /* record */[
          /* date */date,
          /* content */content
        ];
        return e.returnValue = post;
      }));

Electron.ipcMain.on(Event.getPosts, (function (e, _) {
        var i;
        try {
          i = getPosts(/* () */0);
        }
        catch (exn){
          console.log("Error fetching posts");
          i = /* array */[];
        }
        return e.returnValue = i;
      }));

var mockPosts = /* [] */0;

exports.mockPosts          = mockPosts;
exports.getDiaryDir        = getDiaryDir;
exports.getFilePathForDate = getFilePathForDate;
exports.filenameToDate     = filenameToDate;
exports.cleanFileList      = cleanFileList;
exports.getPosts           = getPosts;
exports.savePost           = savePost;
exports.removePost         = removePost;
exports.getPostContent     = getPostContent;
/*  Not a pure module */

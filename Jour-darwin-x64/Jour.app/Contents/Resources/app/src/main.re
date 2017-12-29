[@bs.scope "ipcMain"] [@bs.module "electron"] external on : (string, ('a, 'm) => unit) => unit =
  "";

[@bs.scope "app"] [@bs.module "electron"] external getPath : string => string = "";

[@bs.scope "globalShortcut"] [@bs.module "electron"]
external register : (string, unit => unit) => unit =
  "";

let mockPosts: list(State.posts) = [];

let getDiaryDir = () => {
  let basePath = getPath("documents");
  let dirPath = ".diary";
  let path = NodePath.join([|basePath, dirPath|]);
  if (!NodeFs.existsSync(path)) {
    NodeFs.mkdirSync(path);
  };
  path
};

let getFilePathForDate = (d) => {
  let filename = Date.format(Date.YYYYMMDD, d) ++ ".md";
  NodePath.join([|getDiaryDir(), filename|])
};

let filenameToDate = (str: string) => {
  let subStr = String.sub(str);
  let year = int_of_string(subStr(0, 4));
  let month = int_of_string(subStr(5, 2));
  let day = int_of_string(subStr(8, 2));
  let res = Date.get(year, month, day);
  res
};

let cleanFileList = (files: array(string)) => Js_array.filter((f) => f != ".DS_Store", files);

let getPosts = () => {
  let files = cleanFileList(NodeFs.readdirSync(getDiaryDir()));
  Array.map(filenameToDate, files)
};

let savePost = (post: State.post) => {
  let filename = getFilePathForDate(post.date);
  NodeFs.writeFileSync(~filename, ~text=post.content)
};

let removePost = (date: Date.t) => {
  let filename = getFilePathForDate(date);
  NodeFs.unlinkSync(filename)
};

let getPostContent = (date) => {
  let path = getFilePathForDate(date);
  let res = Node_fs.existsSync(path) ? Node_fs.readFileAsUtf8Sync(path) : "";
  res
};

on(
  Event.setPost,
  (_, res: State.post) =>
    try (savePost(res)) {
    | _ => Js.log("Error saving post")
    }
);

on(
  Event.removePost,
  (_, res: Date.t) =>
    try (removePost(res)) {
    | _ => Js.log("Error removing post")
    }
);

on(
  Event.getPost,
  (e: Js.t('a), date: Date.t) => {
    let content =
      try (getPostContent(date)) {
      | _ =>
        Js.log("Error fetching post content");
        ""
      };
    let post: State.post = {date, content};
    e##returnValue#=post
  }
);

on(
  Event.getPosts,
  (e: Js.t('a), _) => {
    let i =
      try (getPosts()) {
      | _ =>
        Js.log("Error fetching posts");
        [||]
      };
    e##returnValue#=i
  }
);
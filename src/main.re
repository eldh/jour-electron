external on : string => ('a => 'm => unit) => unit =
  "" [@@bs.scope "ipcMain"] [@@bs.module "electron"];

external register : string => (unit => unit) => unit =
  "" [@@bs.scope "globalShortcut"] [@@bs.module "electron"];

let mockIndex: list State.index = [];

let getDiaryDir () => {
  let basePath = "/Users/eldh/Documents";
  let dirPath = ".diary";
  NodePath.join [|basePath, dirPath|]
};

let getFilePathForDate d => {
  let filename = Date.format Date.YYYYMMDD d ^ ".md";
  NodePath.join [|getDiaryDir (), filename|]
};

let filenameToDate (str: string) => {
  let subStr = String.sub str;
  let year = int_of_string (subStr 0 4);
  let month = int_of_string (subStr 5 2);
  let day = int_of_string (subStr 8 2);
  let res = Date.get year month day;
  res
};

let cleanFileList (files: array string) => Js_array.filter (fun f => f != ".DS_Store") files;

let getIndex () => {
  let files = cleanFileList (NodeFs.readdirSync (getDiaryDir ()));
  let res = Array.map filenameToDate files;
  res
};

let savePost (post: State.post) => {
  let filename = getFilePathForDate post.date;
  NodeFs.writeFileSync ::filename text::post.content
};

let getPostContent date => {
  let path = getFilePathForDate date;
  let res = Node_fs.existsSync path ? Node_fs.readFileAsUtf8Sync path : "";
  res
};

on
  Event.setPost
  (
    fun _ (res: State.post) =>
      try (savePost res) {
      | _ => Js.log "Error saving post"
      }
  );

on
  Event.getPost
  (
    fun (e: Js.t 'a) (date: Date.t) => {
      let content =
        try (getPostContent date) {
        | _ =>
          Js.log "Error fetching post content";
          ""
        };
      let post: State.post = {date, content};
      e##returnValue#=post
    }
  );

on
  Event.getIndex
  (
    fun (e: Js.t 'a) _ => {
      let i =
        try (getIndex ()) {
        | _ =>
          Js.log "Error fetching index";
          [||]
        };
      e##returnValue#=i
    }
  );
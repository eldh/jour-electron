external on : string => ('a => 'm => unit) => unit =
  "" [@@bs.scope "ipcMain"] [@@bs.module "electron"];

let mockIndex: list Date.t = [];

let getDiaryDir () => {
  let basePath = "/Users/eldh/Documents";
  let dirPath = ".diary";
  NodePath.join [|basePath, dirPath|]
};

let getFilePathForDate d => {
  let filename = Date.format Date.YYYYMMDD d ^ ".md";
  NodePath.join [|getDiaryDir (), filename|]
};

let getIndex () => {
  let files = NodeFs.readdirSync (getDiaryDir ());
  Js.log files;
  mockIndex
};

let savePost (post: State.post) => {
  Js.log post;
  let filename = getFilePathForDate post.date;
  NodeFs.writeFileSync ::filename text::post.content
};

let getPost date => {
  let path = getFilePathForDate date;
  Node_fs.readFileAsUtf8Sync path
};

Event.handleSetPost on (fun _ (res: State.post) => savePost res);

Event.handleGetPost
  on
  (
    fun (e: Js.t 'a) (date: Date.t) =>
      Event.getPostResponse e##sender##send {date, content: getPost date}
  );

Event.handleGetIndex
  on (fun (e: Js.t 'a) _ => Event.getIndexResponse e##sender##send (getIndex ()));

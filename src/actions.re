external on : string => ('a => unit) => unit =
  "" [@@bs.scope "ipcRenderer"] [@@bs.module "electron"];

external send : string => 'a => unit = "" [@@bs.scope "ipcRenderer"] [@@bs.module "electron"];

external sendSync : string => 'a => 'b = "" [@@bs.scope "ipcRenderer"] [@@bs.module "electron"];

let getIndex handle => {
  let v = sendSync Event.getIndex ();
  handle v
};

let getPost handle date => {
  let v = sendSync Event.getPost date;
  handle v
};

let handleDiaryToggle handler => on Event.toggleDiary handler;

let savePost (post: State.post) => send Event.setPost post;
/* let validateResponse res =>
   switch res {
   | Some _res => raise Not_found
   | None => ()
   }; */
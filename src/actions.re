[@bs.scope "ipcRenderer"] [@bs.module "electron"]
external on : (string, 'a => unit) => unit = "";

[@bs.scope "ipcRenderer"] [@bs.module "electron"]
external send : (string, 'a) => unit = "";

[@bs.scope "ipcRenderer"] [@bs.module "electron"]
external sendSync : (string, 'a) => 'b = "";

let getPosts = handle => {
  let v = sendSync(Event.getPosts, ());
  handle(v);
};

let getPost = (handle, date) => {
  let v = sendSync(Event.getPost, date);
  handle(v);
};

let handleDiaryOpen = handler => on(Event.openDiary, handler);

let savePost = (post: State.post) => send(Event.setPost, post);

let removePost = (date: Date.t) => send(Event.removePost, date);
/* let validateResponse res =>
   switch res {
   | Some _res => raise Not_found
   | None => ()
   }; */

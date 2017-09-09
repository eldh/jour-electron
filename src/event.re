type eventName =
  | GetIndex
  | GetIndexResponse
  | SetPost
  | GetPost
  | GetPostResponse;

let s t =>
  switch t {
  | GetIndex => "a"
  | GetIndexResponse => "b"
  | SetPost => "c"
  | GetPost => "d"
  | GetPostResponse => "e"
  };

let getIndex send => send (s GetIndex) ();

let handleGetIndex on (handler: Js.t 'a => unit => unit) => on (s GetIndex) handler;

let getIndexResponse send (index: State.index) => send (s GetIndexResponse) index;

let handleGetIndexResponse on (handler: Js.t 'a => State.index => unit) =>
  on (s GetIndexResponse) handler;

let setPost send (u: State.post) => send (s SetPost) u;

let handleSetPost on (handler: Js.t 'a => State.post => unit) => on (s SetPost) handler;

let getPost send (d: Date.t) => send (s GetPost) d;

let handleGetPost on (handler: Js.t 'a => Date.t => unit) => on (s GetPost) handler;

let getPostResponse send (p: State.post) => send (s GetPostResponse) p;

let handleGetPostResponse on (handler: Js.t 'a => State.post => unit) =>
  on (s GetPostResponse) handler;

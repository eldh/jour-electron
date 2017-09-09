external on : string => ('a => 'm => unit) => unit =
  "" [@@bs.scope "ipcRenderer"] [@@bs.module "electron"];

external send : string => 'm => unit = "" [@@bs.scope "ipcRenderer"] [@@bs.module "electron"];

let getIndex handle => {
  Event.getIndex send;
  Event.handleGetIndexResponse on (fun _ index => handle index)
};

let savePost post => Event.setPost send post;

/* open State; */
/* type state = State.state; */
type componentState = {
  post: State.post,
  index: State.index,
  date: Date.t
};

/* let setDate _id {ReasonReact.state: state} => ReasonReact.Update {...state, date: Date.get ()}; */
type action =
  | SetIndex State.index
  | SetPost string;

let component = ReasonReact.reducerComponent "JourApp";

let emptyPost: State.post = {date: Date.today (), content: ""};

let emptyIndex: State.index = [];

let postIsOnDate date (post: State.post) => Date.equals date post.date;

let make _children => {
  ...component,
  reducer: fun action state =>
    switch action {
    | SetIndex i => ReasonReact.Update {...state, index: i}
    | SetPost content =>
      let post = {...state.post, content};
      savePost post;
      ReasonReact.Update {...state, post}
    },
  initialState: fun () => (
    {index: emptyIndex, date: Date.today (), post: emptyPost}: componentState
  ),
  didMount: fun {reduce} => {
    getIndex (
      fun ind => {
        reduce (fun _ => SetIndex ind) ();
        ()
      }
    );
    ReasonReact.NoUpdate
  },
  render: fun {state, reduce} =>
    <div>
      <ComposePost onChange=(reduce (fun v => SetPost v)) post=state.post />
      <SelectedPost index=state.index date=state.date />
      <PostList index=state.index date=state.date />
    </div>
  /* let isToday = Date.equals (Date.today ()) state.date; */
};

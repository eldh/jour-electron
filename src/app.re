type componentState = {
  post: State.post,
  index: State.index,
  date: Date.t,
  fullscreen: bool,
  diary: bool
};

type action =
  | SetIndex State.index
  | SetPost State.post
  | ToggleDiary
  | ToggleFullscreen;

let component = ReasonReact.reducerComponent "JourApp";

let make _children => {
  let saveAndUpdatePost date content => {
    let post: State.post = {date, content};
    Actions.savePost post;
    SetPost post
  };
  {
    ...component,
    reducer: fun action state =>
      switch action {
      | SetIndex i => ReasonReact.Update {...state, index: i}
      | SetPost post => ReasonReact.Update {...state, post}
      | ToggleDiary => ReasonReact.Update {...state, diary: not state.diary}
      | ToggleFullscreen => ReasonReact.Update {...state, fullscreen: not state.fullscreen}
      },
    initialState: fun () => {
      fullscreen: false,
      diary: false,
      index: State.emptyIndex,
      date: Date.today (),
      post: State.emptyPost
    },
    didMount: fun {reduce, state} => {
      Actions.on Event.toggleDiary (fun _val => reduce (fun _ => ToggleDiary) state);
      if (state.index == State.emptyIndex) {
        Actions.getIndex (fun ind => reduce (fun _ => SetIndex ind) state)
      };
      if (state.post == State.emptyPost) {
        Actions.getPost (fun post => reduce (fun _ => SetPost post) state) state.date
      };
      ReasonReact.NoUpdate
    },
    render: fun {state, reduce} =>
      <AppContainer>
        (
          state.diary ?
            <PostList index=state.index /> :
            <ComposePost
              onChange=(reduce (saveAndUpdatePost state.post.date))
              post=state.post
              fullscreen=state.fullscreen
            />
        )
      </AppContainer>
  }
};
/* Actions.on
     Event.enterFullScreen
     (
       fun () => {
         Js.log "ENTER FULLSCreen";
         reduce (fun _ => SetFullscreen true)
       }
     );
   Actions.on Event.leaveFullScreen (fun () => reduce (fun _ => SetFullscreen false)); */
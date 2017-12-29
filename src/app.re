type view =
  | Compose
  | Diary;

type componentState = {
  now: Date.t,
  post: State.post,
  posts: State.posts,
  initialDate: Date.t,
  fullscreen: bool,
  view
};

type action =
  | SetPosts(State.posts)
  | SetPost(State.post)
  | SetInitialDate(Date.t)
  | SetNow(Date.t)
  | SetView(view)
  | ToggleDiary
  | ToggleFullscreen;

let component = ReasonReact.reducerComponent("JourApp");

let make = (_children) => {
  let intervalId: ref(option(Js_global.intervalId)) = ref(None);
  let saveAndUpdatePost = (date, content) => {
    let post: State.post = {date, content};
    Actions.savePost(post);
    SetPost(post)
  };
  {
    ...component,
    reducer: (action, state) =>
      switch action {
      | SetPosts(i) => ReasonReact.Update({...state, posts: i})
      | SetPost(post) => ReasonReact.Update({...state, post})
      | SetInitialDate(date) => ReasonReact.Update({...state, initialDate: date})
      | SetNow(now) => ReasonReact.Update({...state, now})
      | SetView(view) => ReasonReact.Update({...state, view})
      | ToggleDiary => ReasonReact.Update({...state, view: state.view === Diary ? Compose : Diary})
      | ToggleFullscreen => ReasonReact.Update({...state, fullscreen: ! state.fullscreen})
      },
    initialState: () => {
      fullscreen: false,
      view: Compose,
      posts: State.emptyPosts,
      initialDate: Date.today(),
      now: Date.today(),
      post: State.emptyPost
    },
    didMount: (self) => {
      let setNow = () => {
        self.reduce((now) => SetNow(now), Date.today())
      };
      intervalId := Some(Js_global.setInterval(setNow, 1000 * 1));
      Actions.on(Event.openDiary, self.reduce(() => ToggleDiary));
      if (self.state.posts === State.emptyPosts) {
        Actions.getPosts(self.reduce((posts) => SetPosts(posts)))
      };
      if (self.state.post === State.emptyPost) {
        Actions.getPost(self.reduce((post) => SetPost(post)), self.state.initialDate)
      };
      ReasonReact.NoUpdate
    },
    willUnmount: (_) =>
      switch intervalId^ {
      | Some(t) => Js_global.clearInterval(t)
      | None => ()
      },
    render: ({state, reduce}) => {
      let content =
        switch state.view {
        | Diary => <PostList posts=state.posts />
        | Compose =>
          <ComposePost
            onChange=(reduce(saveAndUpdatePost(state.post.date)))
            updateDate=(
              (e) => {
                reduce((_) => SetInitialDate(Date.today()), e)
              }
            )
            post=state.post
            dateWarning=(!Date.equals(state.initialDate, state.now))
            fullscreen=state.fullscreen
          />
        };
      <AppContainer> content </AppContainer>
    }
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
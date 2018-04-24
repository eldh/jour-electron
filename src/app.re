let component = ReasonReact.statelessComponent("JourApp");

let make = _children => {
  ...component,
  render: (_) =>
    <ElectronState
      render=(
        (~state, ~updateDate, ~setPost) => {
          let content =
            switch state.view {
            | Diary => <PostList posts=state.posts />
            | Compose =>
              <ComposePost
                onChange=(content => setPost({content, date: state.post.date}))
                updateDate
                post=state.post
                dateWarning=(! Date.equals(state.initialDate, state.now))
                fullscreen=state.fullscreen
              />
            };
          <AppContainer> content </AppContainer>;
        }
      )
    />
};
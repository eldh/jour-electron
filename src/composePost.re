open Glamor;

let className =
  S.css [
    S.flex,
    S.center,
    [background "#0a0a0a", color "white", flexGrow "1", width "100vw", height "100vh"]
  ];

let postIsOnDate date (post: State.post) => Date.equals date post.date;

let component = ReasonReact.statelessComponent "ComposePost";

let make ::fullscreen ::onChange post::(post: State.post) _children => {
  ...component,
  render: fun _self =>
    <div className>
      <PostHeader post fullscreen />
      <StoryInput value=post.content onChange />
    </div>
};
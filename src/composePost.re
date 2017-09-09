open Glamor;

let className =
  css [
    background "rgba(0, 0, 0, 0.2)",
    color "white",
    flexDirection "row",
    justifyContent "center",
    alignContent "center",
    alignItems "center",
    flexGrow "1",
    width "100vw",
    height "100vh"
  ];

let postIsOnDate date (post: State.post) => Date.equals date post.date;

let component = ReasonReact.statelessComponent "ComposePost";

let make ::onChange post::(post: State.post) _children => {
  ...component,
  render: fun _self =>
    <div className>
      <div> (H.se ("Current post: " ^ Date.format DMY (Date.today ()))) </div>
      <StoryInput value=post.content onChange />
    </div>
};

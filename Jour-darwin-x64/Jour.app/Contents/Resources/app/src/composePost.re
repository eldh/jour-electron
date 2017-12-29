open Glamor;

let className =
  S.css([
    S.flex,
    S.center,
    [background("#oa0a0a"), color("white"), flexGrow("1"), width("100vw"), height("100vh")]
  ]);

let postIsOnDate = (date, post: State.post) => Date.equals(date, post.date);

let component = ReasonReact.statelessComponent("ComposePost");

let make = (~fullscreen, ~updateDate, ~dateWarning, ~onChange, ~post: State.post, _children) => {
  ...component,
  render: (_self) =>
    <div className>
      (
        dateWarning ?
          <DateSwitcher onClick=((_) => updateDate()) /> : <PostHeader post fullscreen />
      )
      <StoryInput value=post.content onChange />
    </div>
};
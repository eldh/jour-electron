open Glamor;

let className = css([width("100vw"), height("40px")]);

let component = ReasonReact.statelessComponent("PostHeader");

let make = (~post: State.post, _children) => {
  ...component,
  render: _self => <div className> (H.se(Date.format(DMY, post.date))) </div>
};

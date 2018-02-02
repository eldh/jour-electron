open Glamor;

let className = fullscreen =>
  S.css([
    fullscreen ? [height("60px")] : [height("40px")],
    S.flex,
    S.center,
    [
      position("fixed"),
      top("0"),
      left("0"),
      backgroundColor("rgb(10, 10, 10)"),
      fontFamily("Menlo"),
      color("#6f6f6f"),
      width("100vw"),
      borderBottom("1px rgba(0, 0, 0, 0.2) solid")
    ]
  ]);

let component = ReasonReact.statelessComponent("PostHeader");

let make = (~post: State.post, ~fullscreen, _children) => {
  ...component,
  render: _self =>
    <div className=(className(fullscreen))>
      (H.se(Date.format(DMY, post.date)))
    </div>
};

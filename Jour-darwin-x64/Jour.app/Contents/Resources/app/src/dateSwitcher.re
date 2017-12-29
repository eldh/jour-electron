open Glamor;

let className = (fullscreen) =>
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
      borderBottom("1px rgba(0, 0, 0, 0.2) solid"),
      backgroundColor("#444444"),
      cursor("pointer"),
      color("#ffffff"),
      transition("background-color 0.2s ease"),
      Selector(":hover", [backgroundColor("#449922")])
    ]
  ]);

let component = ReasonReact.statelessComponent("PostHeader");

let make = (~onClick, ~fullscreen=false, _children) => {
  ...component,
  render: (_self) =>
    <div className=(className(fullscreen)) onClick>
      (H.se("It's a new day. Click to start your next story."))
    </div>
};
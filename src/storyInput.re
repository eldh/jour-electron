open Glamor;

let component = ReasonReact.statelessComponent "StoryInput";

let make ::styles=[] ::onChange ::value _children => {
  ...component,
  render: fun _self => {
    let styles = [
      display "flex",
      width "100%",
      height "100%",
      background "rgb(37, 37, 37)",
      padding "5px",
      border "1px rgb(75, 75, 75) solid",
      ...styles
    ];
    <ContentEditable styles html=value onChange />
  }
};

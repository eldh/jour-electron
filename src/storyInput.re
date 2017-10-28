open Glamor;

let component = ReasonReact.statelessComponent "StoryInput";

let className =
  css [
    display "flex",
    border "0",
    width "calc(100% - 26px)",
    maxWidth "600px",
    height "calc(100% - 26px)",
    color "rgb(200, 200, 200)",
    lineHeight "1.5em",
    fontSize "14px",
    padding "13px",
    borderRadius "0",
    fontFamily "Menlo",
    resize "none",
    background "#0a0a0a",
    outline "0",
    Selector ":focus" [outline "0"]
  ];

let make ::onChange ::value _children => {
  ...component,
  render: fun _self => <Textarea className value onChange />
};
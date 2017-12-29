open Glamor;

let component = ReasonReact.statelessComponent("Pre");

let make = (~styles=[], children) => {
  ...component,
  render: (_self) => {
    let className = css([whiteSpace("pre-wrap"), ...styles]);
    <div className> (ReasonReact.arrayToElement(children)) </div>
  }
};
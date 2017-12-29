open Glamor;

let component = ReasonReact.statelessComponent("AppContainer");

let className = css([paddingTop(S.constants.headerHeight), backgroundColor("#0a0a0a")]);

let make = (children) => {
  ...component,
  render: (_) => ReasonReact.createDomElement("div", ~props={"className": className}, children)
};

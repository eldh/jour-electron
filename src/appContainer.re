open Glamor;

let component = ReasonReact.statelessComponent "AppContainer";

let className = css [paddingTop "40px", backgroundColor "#0a0a0a"];

let make children => {
  ...component,
  render: fun _ => ReasonReact.createDomElement "div" props::{"className": className} children
};

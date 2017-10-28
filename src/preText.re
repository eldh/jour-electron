open Glamor;

let component = ReasonReact.statelessComponent "Pre";

let make ::styles=[] children => {
  ...component,
  render: fun _self => {
    Js.log "foo";
    let className = css [whiteSpace "pre-wrap", color "white", ...styles];
    <div className> (ReasonReact.arrayToElement children) </div>
  }
};
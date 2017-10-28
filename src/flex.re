open Glamor;

let className = css [width "100vw", height "40px"];

let component = ReasonReact.statelessComponent "PostHeader";

let make post::(post: State.post) _children => {
  ...component,
  render: fun _self => <div className> (H.se (Date.format DMY post.date)) </div>
};

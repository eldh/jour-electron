open Glamor;

let className =
  css [
    background "rgba(0, 0, 0, 0.2)",
    color "white",
    flexDirection "row",
    justifyContent "center",
    alignContent "center",
    alignItems "center",
    flexGrow "1",
    width "100vw",
    height "100vh"
  ];

let postIsOnDate date (post: State.post) => Date.equals date post.date;

let component = ReasonReact.statelessComponent "SelectedPost";

let make date::(date: Date.t) index::(index: State.index) _children => {
  ...component,
  render: fun _self => {
    let date = List.find (Date.equals date) index;
    <div className> <div> (H.se ("Post date is " ^ Date.format DMY date)) </div> </div>
    /* <div> (H.se post.content) </div> */
  }
};

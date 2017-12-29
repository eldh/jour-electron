open Glamor;

let className =
  css([
    background("rgba(0, 0, 0, 0.2)"),
    color("white"),
    flexDirection("row"),
    justifyContent("center"),
    alignContent("center"),
    alignItems("center"),
    flexGrow("1"),
    width("100vw"),
    height("100vh")
  ]);

let postIsOnDate = (date, post: State.post) => Date.equals(date, post.date);

let component = ReasonReact.statelessComponent("SelectedPost");

let make = (~date: Date.t, ~posts: State.posts, _children) => {
  ...component,
  render: (_self) => {
    let date =
      switch (Js_array.find(Date.equals(date), posts)) {
      | None => raise(Not_found)
      | Some(res) => res
      };
    <div className> <div> (H.se("Post date is " ++ Date.format(DMY, date))) </div> </div>
    /* <div> (H.se post.content) </div> */
  }
};

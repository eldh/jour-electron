open Glamor;

let className =
  css([
    position("absolute"),
    top("0"),
    left("0"),
    height("100vh"),
    maxWidth("400px"),
    background("rgb(40, 40, 40)"),
    color("white"),
    ...S.flex
  ]);

let component = ReasonReact.statelessComponent("OpenPostList");

let make = (~posts: State.posts, ~date: option(Date.t), _children) => {
  ...component,
  render: _self =>
    <div className>
      (
        switch (date) {
        | Some(d) => H.se(Date.format(Date.YYYYMMDD, d))
        | None => ReasonReact.nullElement
        }
      )
      <ul>
        (
          ReasonReact.arrayToElement(
            Array.map(
              (date: Date.t) =>
                <li> (H.se(Date.format(Date.YYYYMMDD, date))) </li>,
              posts
            )
          )
        )
      </ul>
    </div>
};

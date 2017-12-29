open Glamor;

type state = {
  date: option(Date.t),
  post: State.post
};

type action =
  | SetState(State.post, option(Date.t));

let className =
  css([
    background("rgba(0, 0, 0, 0.2)"),
    color("white"),
    listStyleType("none"),
    fontFamily("Menlo"),
    color("#6f6f6f"),
    width("calc(100% - 26px)"),
    maxWidth("600px"),
    paddingLeft("0"),
    margin("auto"),
    minHeight("100vh")
  ]);

let component = ReasonReact.reducerComponent("PostList");

let make = (~posts: State.posts, _children) => {
  let getPostForDate = (self, date: Date.t) => {
    let getIt = () => {
      Actions.getPost(
        (post) => {
          self.ReasonReact.reduce((_) => SetState(post, Some(date)), ())
        },
        date
      )
    };
    switch self.state.date {
    | None => getIt()
    | Some(d) =>
      if (Date.equals(date, d)) {
        self.ReasonReact.reduce((_) => SetState(State.emptyPost, None), ())
      } else {
        getIt()
      }
    }
  };
  {
    ...component,
    initialState: () => {date: None, post: State.emptyPost},
    reducer: (action, _state) =>
      switch action {
      | SetState(post, date) => ReasonReact.Update({post, date})
      },
    render: (self) => {
      let getDiaryRow = (date) => {
        <DiaryRow
          key=(Date.format(Date.YYYYMMDD, date))
          date
          post=self.state.post
          onClick=((_) => getPostForDate(self, date))
        />
      };
      <ul className> (H.ae(Array.map(getDiaryRow, posts))) </ul>
    }
  }
};
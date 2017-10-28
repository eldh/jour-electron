open Glamor;

type state = {
  date: option Date.t,
  post: State.post
};

type action =
  | SetBoth State.post (option Date.t);

let className =
  css [
    background "rgba(0, 0, 0, 0.2)",
    color "white",
    listStyleType "none",
    fontFamily "Menlo",
    color "#6f6f6f",
    paddingLeft "0",
    marginLeft "0",
    minHeight "100vh"
  ];

let component = ReasonReact.reducerComponent "PostList";

let make index::(index: State.index) _children => {
  let getPostForDate self (date: Date.t) => {
    let getIt () => {
      Js.log "getIt;";
      Actions.getPost
        (
          fun post => {
            Js.log2 "getPost" post;
            self.ReasonReact.reduce (fun _ => SetBoth post (Some date)) ()
          }
        )
        date
    };
    Js.log2 "switch" self.state.date;
    switch self.state.date {
    | None => getIt ()
    | Some d =>
      Js.log3 date d "dates";
      if (Date.equals date d) {
        Js.log "equals";
        self.ReasonReact.reduce (fun _ => SetBoth State.emptyPost None) ()
      } else {
        getIt ()
      }
    }
  };
  {
    ...component,
    initialState: fun () => {date: None, post: State.emptyPost},
    reducer: fun action state =>
      switch action {
      | SetBoth post date => ReasonReact.Update {post, date}
      },
    render: fun self => {
      let getDiaryRow date => {
        Js.log2 "render" self.state.date;
        <DiaryRow
          key=(Date.format Date.YYYYMMDD date)
          date
          post=self.state.post
          onClick=(fun _ => getPostForDate self date)
        />
      };
      <ul className> (H.ae (Array.map getDiaryRow index)) </ul>
    }
  }
};
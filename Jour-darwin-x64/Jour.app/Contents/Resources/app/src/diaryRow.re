open Glamor;

let base = [flexGrow("1"), padding("20px")];

let component = ReasonReact.statelessComponent("DiaryRow");

let make = (~date: Date.t, ~onClick, ~post: option(State.post)=?, _children) => {
  ...component,
  render: (_self) => {
    let textColor =
      switch post {
      | Some(p) => Date.equals(p.date, date) ? "white" : "#6f6f6f"
      | None => "#6f6f6f"
      };
    <li onClick className=(css([color(textColor), ...base]))>
      <div> (H.se(Date.format(Date.DMY, date))) </div>
      <PreText styles=[padding("20px 0")]>
        (
          switch post {
          | Some(p) => Date.equals(p.date, date) ? H.se(p.content) : H.null
          | None => H.null
          }
        )
      </PreText>
    </li>
  }
};
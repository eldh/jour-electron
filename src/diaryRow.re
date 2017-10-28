open Glamor;

let className = css [flexGrow "1", padding "20px"];

let component = ReasonReact.statelessComponent "DiaryRow";

let make date::(date: Date.t) ::onClick post::(post: option State.post)=? _children => {
  ...component,
  render: fun _self =>
    <li onClick className>
      <div> (H.se (Date.format Date.DMY date)) </div>
      <PreText styles=[padding "20px 0"]>
        (
          switch post {
          | Some p => Date.equals p.date date ? H.se p.content : H.null
          | None => H.null
          }
        )
      </PreText>
    </li>
};
open Glamor;

let className =
  css [
    background "rgba(0, 0, 0, 0.2)",
    color "white",
    flexDirection "row",
    justifyContent "center",
    alignContent "center",
    alignItems "center",
    flexGrow "1"
  ];

let component = ReasonReact.statelessComponent "PostList";

let make date::(date: Date.t) index::(index: State.index) _children => {
  ...component,
  render: fun _self =>
    <div className>
      (H.se ("Date is " ^ Date.format Date.DMY date))
      <ul>
        (
          ReasonReact.arrayToElement (
            Array.of_list (
              List.map
                (fun (date: Date.t) => <li> (H.se (Date.format Date.YYYYMMDD date)) </li>) index
            )
          )
        )
      </ul>
    </div>
};

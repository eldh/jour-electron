open Glamor;

type action =
  | HandleChange ReactEventRe.Form.t;

let component = ReasonReact.reducerComponent "Input";

let make ::styles=[] ::onChange ::value _children => {
  ...component,
  reducer: fun action _state =>
    switch action {
    | HandleChange event =>
      let value = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
      onChange value
    },
  initialState: fun () => value,
  willReceiveProps: fun _self => value,
  render: fun {state, reduce} => {
    let className =
      css [
        background "rgb(37, 37, 37)",
        padding "5px",
        border "1px rgb(75, 75, 75) solid",
        ...styles
      ];
    <input className _type="text" value=state onChange=(reduce (fun e => HandleChange e)) />
  }
};

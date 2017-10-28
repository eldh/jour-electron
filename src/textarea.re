type state = string;

type action =
  | HandleChange string;

let component = ReasonReact.reducerComponent "Textarea";

let handleChange event => {
  let value: string = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value;
  HandleChange value
};

let make ::className ::onChange ::value _children => {
  ...component,
  reducer: fun action _state =>
    switch action {
    | HandleChange value =>
      onChange value;
      ReasonReact.Update value
    },
  initialState: fun () => value,
  willReceiveProps: fun _self => value,
  render: fun {state, reduce} =>
    <textarea
      autoFocus=(Js.Boolean.to_js_boolean true)
      className
      onChange=(reduce handleChange)
      value=state
    />
};

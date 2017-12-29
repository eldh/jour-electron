type state = string;

type action =
  | HandleChange(string);

let component = ReasonReact.reducerComponent("Textarea");

let handleChange = (event) => {
  let value: string = ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value;
  HandleChange(value)
};

let make = (~className, ~onChange, ~value, _children) => {
  ...component,
  reducer: (action, _state) =>
    switch action {
    | HandleChange(value) =>
      onChange(value);
      ReasonReact.Update(value)
    },
  initialState: () => value,
  willReceiveProps: (_self) => value,
  render: ({state, reduce}) =>
    <textarea
      spellCheck=(Js.Boolean.to_js_boolean(true))
      autoFocus=(Js.Boolean.to_js_boolean(true))
      className
      onChange=(reduce(handleChange))
      value=state
    />
};

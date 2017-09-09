open Glamor;

let component = ReasonReact.statelessComponent "Input";

let make date::(date: Date.t) ::onValueChanged ::activeSecond _children => {
  ...component,
  render: fun _self => {
    let styles = [color (activeSecond == date.second ? "rgb(140, 208, 0)" : "rgb(209, 209, 209)")];
    <TextInput value=(string_of_int activeSecond) styles onChange=onValueChanged />
  }
};

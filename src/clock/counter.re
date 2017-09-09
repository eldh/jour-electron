type state = {
  date: Date.t,
  activeSecond: int,
  timerId: option Js.Global.intervalId
};

let setDate _id {ReasonReact.state: state} => ReasonReact.Update {...state, date: Date.now ()};

let setActive (activeSecond: string) {ReasonReact.state: state} =>
  ReasonReact.Update {...state, activeSecond: int_of_string activeSecond};

let component = ReasonReact.statefulComponent "ClockBase";

let make _children => {
  ...component,
  initialState: fun () => {date: Date.now (), timerId: None, activeSecond: 0},
  didMount: fun {state, update} =>
    ReasonReact.SilentUpdate {...state, timerId: Some (Js.Global.setInterval (update setDate) 500)},
  render: fun {state, update} => {
    Js.log state.activeSecond;
    <div>
      <TimeInput
        date=state.date
        activeSecond=state.activeSecond
        onValueChanged=(update setActive)
      />
      <Clock date=state.date />
    </div>
  }
};

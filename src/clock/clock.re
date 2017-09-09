open Glamor;

let className =
  css [
    background "rgba(0, 0, 0, 0.2)",
    color "white",
    flexDirection "row",
    justifyContent "center",
    alignContent "center",
    alignItems "center",
    flexGrow "1",
    width "100%",
    height "100%"
  ];

let range = Array.make 60 0;

let component = ReasonReact.statelessComponent "Clock";

let make date::(date: Date.t) _children => {
  ...component,
  render: fun _self => {
    let createSecond pos _ => <Indicator pos date timeType=Second />;
    let createMinute pos _ => <Indicator pos date timeType=Minute />;
    let createHour pos _ => <Indicator pos date timeType=Hour />;
    let seconds = Array.mapi createSecond range;
    let minutes = Array.mapi createMinute range;
    let hours = Array.mapi createHour range;
    let props = {"className": css [width "80vw", height "80vw"]};
    <div className>
      (ReasonReact.createDomElement "div" ::props hours)
      (ReasonReact.createDomElement "div" ::props minutes)
      (ReasonReact.createDomElement "div" ::props seconds)
    </div>
  }
};

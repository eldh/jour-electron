open Glamor;

type timeVariant =
  | Second
  | Hour
  | Minute;

let getTranslate t =>
  switch t {
  | Minute => "translateY(30px)"
  | Second => "translateY(0)"
  | Hour => "translateY(60px)"
  };

let getColor t =>
  switch t {
  | Minute => "rgb(153, 255, 161)"
  | Second => "rgb(210, 156, 244)"
  | Hour => "rgb(235, 201, 97)"
  };

let getPoint (d: Date.t) t =>
  switch t {
  | Second => d.second
  | Minute => d.minute
  | Hour => (d.hour > 12 ? d.hour - 12 : d.hour) * 60 / 12 + d.minute / 60
  };

let getOpacity d =>
  switch d {
  | 0. => "1"
  | _ => d >= 3. ? "0" : string_of_float ((3. -. d) /. 3.)
  };

let component = ReasonReact.statelessComponent "Indicator";

let make date::(date: Date.t) ::pos timeType::(timeType: timeVariant) _children => {
  ...component,
  render: fun _self => {
    let point = getPoint date timeType;
    let distance =
      float (min (abs (pos - point)) (min (abs (pos + 60 - point)) (abs (pos - (point + 60)))));
    let getReal () => {
      let className =
        css [
          opacity (getOpacity distance),
          transform ("rotate(" ^ string_of_int (pos * 6) ^ "deg)" ^ getTranslate timeType),
          transformOrigin "0 50%",
          color (getColor timeType),
          fontSize "30px",
          width "1%",
          height "50%",
          flexShrink "0",
          marginLeft "1%",
          top "25%",
          left "50%",
          position "absolute",
          textAlign "center"
        ];
      <div className> (ReasonReact.stringToElement "|") </div>
    };
    distance >= 3. ? ReasonReact.nullElement : getReal ()
  }
};

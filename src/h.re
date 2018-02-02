let i = string_of_int;

let se = ReasonReact.stringToElement;

let ae = ReasonReact.arrayToElement;

let null = ReasonReact.nullElement;

let ie = n => se(string_of_int(n));

[@bs.val] external alert : string => unit = "alert";

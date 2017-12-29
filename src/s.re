open Glamor;

let flex = [
  display("flex"),
  flexDirection("column"),
  boxSizing("border-box"),
  position("relative"),
  display("flex"),
  alignItems("stretch")
];

let center = [justifyContent("center"), alignContent("center"), alignItems("center")];

let css = (l) => Glamor.css(List.concat(l));

type constants = {
  headerHeight: string
};
let constants = {
  headerHeight: "40px"
};

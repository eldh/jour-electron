open Glamor;

type state = {
  html: string,
  myRef: ref (option Dom.element)
};

type action =
  | HandleChange;

let component = ReasonReact.reducerComponent "ContentEditable";

let setRef theRef {ReasonReact.state: state} => state.myRef := Js.Null.to_opt theRef;

let make ::styles=[] ::onChange ::html="" _children => {
  ...component,
  reducer: fun action state =>
    switch action {
    | HandleChange =>
      switch !state.myRef {
      | None => ()
      | Some theRef =>
        let obj = ReactDOMRe.domElementToObj theRef;
        let html = obj##innerHTML;
        onChange html
      };
      ReasonReact.Update state
    },
  initialState: fun () => {html, myRef: ref None},
  willReceiveProps: fun {state} => html == state.html ? {...state, html} : state,
  render: fun {state, reduce, handle} => {
    let className = css styles;
    <div
      ref=(handle setRef)
      contentEditable=Js.true_
      className
      dangerouslySetInnerHTML={"__html": state.html}
      onInput=(reduce (fun _ => HandleChange))
    />
  }
};

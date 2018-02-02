open Glamor;

type state = {
  html: string,
  myRef: ref(option(Dom.element))
};

type action =
  | HandleChange;

let component = ReasonReact.reducerComponent("ContentEditable");

let setRef = (theRef, {ReasonReact.state}) =>
  state.myRef := Js.Nullable.to_opt(theRef);

let make = (~styles=[], ~onChange, ~html="", _children) => {
  ...component,
  reducer: (action, state) =>
    switch (action) {
    | HandleChange =>
      switch (state.myRef^) {
      | None => ()
      | Some(theRef) =>
        let obj = ReactDOMRe.domElementToObj(theRef);
        let html = obj##innerHTML;
        onChange(html);
      };
      ReasonReact.Update(state);
    },
  initialState: () => {html, myRef: ref(None)},
  willReceiveProps: ({state}) => html == state.html ? {...state, html} : state,
  render: ({state, send, handle}) => {
    let className = css(styles);
    <div
      ref=(handle(setRef))
      contentEditable=Js.true_
      className
      dangerouslySetInnerHTML={"__html": state.html}
      onInput=((_) => send(HandleChange))
    />;
  }
};

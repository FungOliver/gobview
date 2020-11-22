open Js_of_ocaml;
open State;

[@react.component]
let make = (~state, ~dispatch) => {
  let show_info = a => dispatch @@ Set_id(a);

  /*
   * Don't remove the underscore at the end of `show_info_`.
   * Otherwise, the function is mapped as `show`.
   */
  Js.(Unsafe.global##.show_info_ := wrap_callback(show_info));

  let dot =
    State.inspect_opt(state)
    |> (s => Option.bind(s, Inspect.function_opt))
    |> (f => Option.bind(f, Inspect.Function.dot_opt));

  <>
    <NodeViewFuncList dispatch pdata={state.pdata} />
    {switch (dot) {
     | Some(dot) => <Graphviz dot={dot |> Js_of_ocaml.Js.string} />
     | _ => React.null
     }}
  </>;
};

open Batteries;
module Message = GvMessages.Message;

[@react.component]
let make = (~warnings, ~dispatch) => {
  <div className="filebox">
    <h3>
      {(List.length(warnings) == 0 ? "No warnings found!" : "Warnings")
       |> React.string}
    </h3>
    <ul>
      {warnings
       |> List.map(w => (Message.to_string(w), Message.location(w)))
       |> List.mapi((i, (text, loc)) => {
            let onClick =
              loc
              |> Option.map((loc, _) =>
                   dispatch @@ `InspectLine(GvInspect.Line.of_location(loc))
                 );
            <li className="cursor warnitem" key={string_of_int(i)} ?onClick>
              {text |> React.string}
            </li>;
          })
       |> React.list}
    </ul>
  </div>;
};

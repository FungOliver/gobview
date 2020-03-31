type action =
  | Increment
  | Decrement;

let z = Parse.parse(Parse.xml_data);

let reducer = (state, action) =>
  switch (action) {
  | Increment => state + 1
  | Decrement => state - 1
  };

let space = {
  " " |> React.string;
};


[@react.component]
let make = (~name="Billy", ~children=?) => {
  let (count, setCount) = React.useState(() => 0);
  let (state, dispatch) = React.useReducer(reducer, 0);

  <div>
    <UseEffect count />
    <p> {"Hallo " ++ (Parse.extract(z)) |> React.string}</p>
    <p> {"Hellllo from GreetingReason " ++ name |> React.string} </p>
    <button
      onClick={_ => {
        print_endline("Click!");
        setCount(c => c + 1);
      }}>
      {"Count: " ++ string_of_int(count) |> React.string}
    </button>
    space
    <button onClick={_ => dispatch @@ Decrement}>
      {"Dec" |> React.string}
    </button>
    space
    <span> {string_of_int(state) |> React.string} </span>
    space
    <button onClick={_ => dispatch @@ Increment}>
      {"Inc" |> React.string}
    </button>
    space
    {switch (children) {
     | Some(c) => <div> c </div>
     | None => React.null
     }}
  </div>;
};

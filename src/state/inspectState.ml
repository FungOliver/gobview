module File = struct
  type t = { name : string; path : string; code : string option }
end

module Func = struct
  type t = {
    name : string;
    file_name : string;
    file_path : string;
    dot : string option;
  }
end

type file = File.t

type func = Func.t

type t = File of file | Func of func

let from_cil_location l p =
  let files =
    Parse.get_files p
    |> List.filter (fun f -> Parse.file_to_name f = l.Cil.file)
  in
  match files with
  | f :: _ ->
      let name = Parse.file_to_name f in
      let path = Parse.file_to_path f in
      Some (File { name; path; code = None })
  | _ -> None

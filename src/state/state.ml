open Batteries

module SelectedSidebar = struct
  type t = Nodes | Globals
end

type selected_sidebar = SelectedSidebar.t

module SelectedPanel = struct
  type t = Warnings | DeadCode | Parameters | Statistics
end

type selected_panel = SelectedPanel.t

type display = GvDisplay.t

type inspect = GvInspect.t

type t = {
  cil : Cil.file;
  goblint : GvGoblint.solver_state;
  warnings : GvMessages.t;
  meta : Yojson.Safe.t;
  stats : Stats.t * Gc.stat;
  display : display option;
  inspect : inspect option;
  selected_sidebar : selected_sidebar;
  selected_panel : selected_panel option;
  search : Search.t;
}

let default =
  {
    cil = Cil.dummyFile;
    goblint = GvGoblint.empty;
    warnings = [];
    meta = `Null;
    stats = (Stats.top, Gc.quick_stat ());
    display = None;
    inspect = None;
    selected_sidebar = SelectedSidebar.Nodes;
    selected_panel = None;
    search = Search.default;
  }

let make ~cil ~goblint ~warnings ~meta ~stats () =
  { default with cil; goblint; warnings; meta; stats }

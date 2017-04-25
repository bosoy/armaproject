private ["_side", "_grp"];
_side = _this select 0;
_side_str = switch (_side) do {case "EAST": {east};case "WEST": {west};case "GUER": {resistance};case "CIV": {civilian};};
_grp = createGroup _side_str;
_grp setVariable ["gr_a", 1];
_grp setVariable ["X_CREATED", time + 120];
_grp

private ["_found_empty","_grp","_i","_side","_side_str","_this","_tmp_grp","_tmp_grp_a","_tmp_time","_x"];
_side = _this select 0;
_side_str = switch (_side) do {case "EAST": {east};case "WEST": {west};case "GUER": {resistance};case "CIV": {civilian};};
_grp = createGroup _side_str;
_grp setVariable ["X_CREATED", time + 120];
_grp

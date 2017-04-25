/*
mando_remotes.sqf v1.0
July 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

mando_remote_w         = objNull;
mando_remote_e         = objNull;
mando_remote_r         = objNull;
mando_remote_c         = objNull;

mando_remote_targets_w = [];
mando_remote_targets_e = [];
mando_remote_targets_r = [];
mando_remote_targets_c = [];

[]execVM mando_missile_path+"mando_remotes_w.sqf";
[]execVM mando_missile_path+"mando_remotes_e.sqf";
[]execVM mando_missile_path+"mando_remotes_r.sqf";

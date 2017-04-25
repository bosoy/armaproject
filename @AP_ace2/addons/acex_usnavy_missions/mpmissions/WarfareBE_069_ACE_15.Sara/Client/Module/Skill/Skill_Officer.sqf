/*
	Script: Officer Skill System by Benny.
	Description: Add special skills to the defined officer.
*/
Private ['_array','_exist','_skip','_tent','_toWorld','_type','_z'];


private ["_x","_skip","_array","_toWorld","_tent","_type","_exist"];
_type = Format ["WFBE_%1FARP",sideJoinedText] Call GetNamespace;
_exist = WF_Logic getVariable Format ["%1MASH",sideJoinedText];
if !(isNull _exist) then {deleteVehicle _exist};

WFBE_SK_V_LastUse_MASH = time;

_skip = false;
for [{_z = 0},{_z < 7},{_z = _z + 1}] do {
	sleep 0.5;
	player playMove "AinvPknlMstpSlayWrflDnon_medic";
	sleep 0.5;
	waitUntil {animationState player == "ainvpknlmstpslaywrfldnon_amovpknlmstpsraswrfldnon" || !alive player || vehicle player != player};
	if (!alive player || vehicle player != player) exitWith {_skip = true};
};

if (!_skip) then {
	_array = [((player worldToModel (getPos player)) select 0),((player worldToModel (getPos player)) select 1) + 10];
	_toWorld = player modelToWorld _array;
	_tent = _type createVehicle _toWorld;
	WF_Logic setVariable [Format["%1MASH",sideJoinedText],_tent,true];
} else {
	WF_Logic setVariable [Format["%1MASH",sideJoinedText],objNull,true];
};
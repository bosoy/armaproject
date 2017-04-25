
private ["_locations","_sideID","_names","_skip","_curSel","_display","_map","_sorted"];
disableSerialization;

MenuAction = -1;
mouseButtonUp = -1;

_display = _this select 0;
_map = _display DisplayCtrl 19002;

if (isNull currentMission) then {ctrlSetText [19007,Format [localize "STR_WF_CurrentMission","N/A"]]} else {ctrlSetText [19007,Format [localize "STR_WF_CurrentMission",currentMission getVariable "name"]];};

_names = [];
_locations = [];
{_sideID = _x getVariable "sideID"; if (_sideID != sideID) then {_locations = _locations + [_x]}} forEach towns;
_sorted = [player,_locations] Call SortByDistance;
{_names = _names + [_x getVariable "name"]} forEach _sorted;

{lbAdd[19005,_x]} forEach _names;
if (count _sorted > 0) then {
	lbSetCurSel[19005,0];
	_map CtrlMapAnimAdd [2,.140,GetPos (_sorted select 0)];
	CtrlMapAnimCommit _map;
};

while {alive player && dialog} do {
	sleep 0.1;
	if (Side player != sideJoined) exitWith {closeDialog 0};
	if (!dialog) exitWith {};
	
	//--- Accept Mision.
	if (MenuAction == 1) then {
		MenuAction = -1;
		_skip = false;
		if (!isNil "townTask") then {if (taskState townTask == "Succeeded") then {["TownRemove",currentMission] Call TaskSystem;currentMission = objNull}}	;
		if (!isNull currentMission) then {hint (localize "STR_WF_Mission_Running");_skip = true};
		if (!_skip) then {
			_curSel = lbCurSel (19005);
			currentMission = _sorted select _curSel;
			ctrlSetText [19007,Format [localize "STR_WF_CurrentMission",currentMission getVariable "name"]];
			//--- Task System.
			["TownAdd",currentMission] Spawn TaskSystem;
		};
	};
	
	//--- Abort Mision.
	if (MenuAction == 2) then {
		MenuAction = -1;
		if (!isNull currentMission) then {
			["TownRemove",currentMission] Call TaskSystem;
			ctrlSetText [19007,Format [localize "STR_WF_CurrentMission","N/A"]];
			currentMission = objNull;
			hint (localize "STR_WF_Mission_Abort");
		};
	};
	
	//--- Other Town selected.
	if (MenuAction == 101) then {
		MenuAction = -1;
		_curSel = lbCurSel (19005);
		CtrlMapAnimClear _map;
		_map CtrlMapAnimAdd [2,.140,GetPos (_sorted select _curSel)];
		CtrlMapAnimCommit _map;
	};
};
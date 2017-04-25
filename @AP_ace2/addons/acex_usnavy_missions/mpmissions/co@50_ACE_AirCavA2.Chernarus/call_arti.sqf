private ["_oldpos", "_dlg", "_fcDialog", "_pos"];
if (!ari_available) exitWith {
	[playerSide,"HQ"] sideChat "Artillery currently not available...";
};

ari_type = "";

disableSerialization;

_oldpos = position AriTarget;
_dlg = createDialog "XD_ArtilleryDialog";
_fcDialog = uiNamespace getVariable "D_ARTI_DISP";

onMapSingleClick "AriTarget setpos _pos;""arti_target"" setMarkerPos _pos;";

waitUntil {ari_type != "" || !dialog || !alive player};

//onMapSingleClick "";
if (!alive player) exitWith {
	if (dialog) then {
		closeDialog 77899;
	};
	AriTarget setpos _oldpos;
	"arti_target" setMarkerPos _oldpos;
};
if (ari_type != "") then {
	player sideChat format ["Crossroad, requesting %1 strike at %2 north, %3 west!", ari_type, position AriTarget select 1, position AriTarget select 0];
	sleep 2;
	[playerSide,"HQ"] sideChat "This is first artillery, roger.";
	sleep 5;
	[playerSide,"HQ"] sideChat format ["First artillery executing %1 strike", ari_type];
	publicVariable "ari_type";
	if (X_SPE) then {
		ari_type execVM "x_arifire.sqf";
	};
} else {
	AriTarget setpos _oldpos;
	"arti_target" setMarkerPos _oldpos;
};
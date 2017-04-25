#include "script_component.hpp"

private ["_selection", "_cLBCameras", "_selectedIndex", "_newIndex"];

disableSerialization;

_selection = _this;

_cLBCameras = _selection select 0;
_selectedIndex = _selection select 1;

if ((_selectedIndex == -1) || {(lbCurSel _cLBCameras == GVAR(camSelLast))}) exitWith {};

_newIndex = _selectedIndex;
switch (_selectedIndex) do {
	case 5: { // separator
		_newIndex = GVAR(camSelLast);
	};
	case 6: { // Special for toggling missile camera
		GVAR(UseMissileCam) = abs (GVAR(UseMissileCam) - 1);
		_newIndex = GVAR(camSelLast);
	};
	case 7: { // Special for toggling NVG
		GVAR(UseNVG) = abs (GVAR(UseNVG) - 1);
		if (GVAR(UseNVG) == 1) then {
			GVAR(NVGMode) = 0;
			GVAR(OldNVGMode) = -5;
		};
		_newIndex = GVAR(camSelLast);
	};
	case 8: { // Special for toggling tags
		GVAR(Tags) = abs (GVAR(Tags) - 1);
		GVAR(TogTagsParams) = [(GVAR(Tags) == 1), (GVAR(cameras) select GVAR(cameraIdx))];
		_newIndex = GVAR(camSelLast);
	};
	case 9: { // Special for toggling AI filter
		GVAR(AIfilter) = abs (GVAR(AIfilter) - 1);
		_newIndex = GVAR(camSelLast);
		GVAR(NeedUpdateLB) = true; // Request listbox update
	};
	case 10: { // Special for toggling Unknown (Dead) Players
		if (!GVAR(RemoveDeadFilter)) then {
			GVAR(DeadFilter) = abs (GVAR(DeadFilter) - 1);
			GVAR(NeedUpdateLB) = true; // Request listbox update
		};
		_newIndex = GVAR(camSelLast);
	};
};

if (_newIndex != GVAR(camSelLast)) then {
	// Selected another camera - disable dropped cam
	GVAR(DroppedCamera) = false;
};

GVAR(NewCameraIdx) = _newIndex;
GVAR(camSelLast) = _newIndex; //immediately capture the last selected camera index

true
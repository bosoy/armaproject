// Sat View  by Vienna
#define THIS_FILE "SatellitenPos.sqf"
#include "x_setup.sqf"
private "_ok";

_ok = true;

switch (_this) do {
	case "N" : {GVAR(SatellitenPos_Y) = GVAR(SatellitenPos_Y) + 50};
	case "S" : {GVAR(SatellitenPos_Y) = GVAR(SatellitenPos_Y) - 50};
	case "W" : {GVAR(SatellitenPos_X) = GVAR(SatellitenPos_X) - 50};
	case "E" : {GVAR(SatellitenPos_X) = GVAR(SatellitenPos_X) + 50};
	case "X" : {GVAR(SatellitenPos_X) = GVAR(SatellitenPos_XC); GVAR(SatellitenPos_Y) = GVAR(SatellitenPos_YC)};
	case "ZE": {GVAR(SatellitenZoom) = 0.10};
	case "ZA": {GVAR(SatellitenZoom) = 0.27};
	default {
		PARAMS_2(GVAR(SatellitenPos_XC),GVAR(SatellitenPos_YC));
		GVAR(SatellitenPos_X) = GVAR(SatellitenPos_XC);
		GVAR(SatellitenPos_Y) = GVAR(SatellitenPos_YC) - 0.9;
		GVAR(SatellitenZoom) = 0.27;
		titleCut [(localize "STR_DOM_MISSIONSTRING_77"),"Black out"];
		sleep 1;
		GVAR(SatellitenCamera) = "camera" camCreate [GVAR(SatellitenPos_X),GVAR(SatellitenPos_Y),530];
		GVAR(SatellitenCamera) cameraEffect ["internal", "back"];
		showCinemaBorder false;
		GVAR(SatellitenCamera) camSetTarget [GVAR(SatellitenPos_X),GVAR(SatellitenPos_Y) + 5,-99999];
		GVAR(SatellitenCamera) camSetFOV GVAR(SatellitenZoom);
		GVAR(SatellitenCamera) camCommit 0;
		waitUntil {camCommitted GVAR(SatellitenCamera)};
		sleep 1;
		createDialog "SAT_Satellitenbild";
		titleCut[(localize "STR_DOM_MISSIONSTRING_77"),"Black in"];
		waitUntil {!GVAR(satcam_dialog_open) || !alive player};
		if (alive player) then {
			titleCut[(localize "STR_DOM_MISSIONSTRING_78"),"Black out"];
			sleep 1;
		} else {
			if (GVAR(satcam_dialog_open)) then {closeDialog 0};
		};
		GVAR(SatellitenCamera) cameraEffect ["terminate", "back"];
		camDestroy GVAR(SatellitenCamera);
		
#ifdef __CO__
		camUseNVG false;
#endif
#ifdef __OA__
		false setCamUseTI 1;
#endif
		if (alive player) then {
			titleCut[(localize "STR_DOM_MISSIONSTRING_78"),"Black in"];
		};
		_ok = false
	}
};

if (_ok) then {
	GVAR(SatellitenCamera) camSetPos [GVAR(SatellitenPos_X),GVAR(SatellitenPos_Y),530];
	GVAR(SatellitenCamera) camSetTarget [GVAR(SatellitenPos_X),GVAR(SatellitenPos_Y) + 5,-99999];
	GVAR(SatellitenCamera) camSetFOV GVAR(SatellitenZoom);
	GVAR(SatellitenCamera) camCommit 0;
	//waitUntil {camCommitted GVAR(SatellitenCamera)};
};
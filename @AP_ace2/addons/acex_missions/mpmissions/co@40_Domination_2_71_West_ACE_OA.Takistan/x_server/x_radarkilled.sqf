// by Xeno
#define THIS_FILE "x_radarkilled.sqf"
#include "x_setup.sqf"
private ["_radar", "_posrad", "_dirrad", "_typerad"];
if (!isServer) exitWith {};

PARAMS_1(_radar);
_posrad = position _radar;
_dirrad = direction _radar;
_posrad set [2,0];
_typerad = typeOf _radar;
deleteVehicle _radar;
GVAR(banti_airdown) = true;

GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TellBaseRadarDown",true];

[_posrad, _dirrad, _typerad] spawn {
	private ["_posrad", "_dirrad", "_typerad", "_radar"];
	PARAMS_3(_posrad,_dirrad,_typerad);
	sleep (1200 + (random 1200));
	_radar = createVehicle [_typerad, _posrad, [], 0, "NONE"];
	_radar setDir _dirrad;
	_radar setPos _posrad;
	GVAR(banti_airdown) = false;
	_radar addEventHandler ["killed", FUNC(radarkilled)];
	GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TellBaseRadarUpAgain",true];
};
//fnc_getIn.sqf
#include "script_component.hpp"
disableSerialization;

PARAMS_3(_plane,_pos,_player);

if (player == _player) then {
	_isHud = getNumber(configFile >> "CfgVehicles" >> typeOf _plane >> "ACE_HUD_ENABLED");
	if(_isHud == 1) then {
		GVAR(ccip_plane) = _plane;
		_hudDisplay = (uiNamespace getVariable "ACE_HUD_RSC");
		if(!isNil "_hudDisplay") then {
			_hudDisplay closeDisplay 1;
		};
		93563 cutRsc ["ace_ccip_hud_dialog", "PLAIN"];
	};
};

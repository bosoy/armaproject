/* ace_sys_overheating | Barrel Temperature for Static weapons | (c) 2011 rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define ACE_TEXT_ORANGE(Text) ("<t color='#ffa500'>" + ##Text + "</t>")

PARAMS_1(_vehicle);

if (!isNil {_vehicle getVariable QGVAR(jammed)}) then {
	_s = _vehicle addaction [ACE_TEXT_ORANGE(localize "STR_ACE_JAMCLEARACT"), QPATHTO_F(action_unjam_static)];
	_vehicle setVariable [QGVAR(aid),_s,true];
	[_vehicle] spawn FUNC(jam_static_loop);
};
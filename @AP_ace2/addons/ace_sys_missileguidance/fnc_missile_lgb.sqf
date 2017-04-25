////////////////////////////////////////////
//  ACE LGB Guidance Thread  			//
////////////////////////////////////////////
// By Nou, integrated by jaynus
#include "script_component.hpp"

private["_handle"];
PARAMS_4(_vehicle,_projectile,_isPlayer,_laserCode);

TRACE_1("", _this);
if !(_isPlayer) exitWith {};
_handle = [ace_sys_missileguidance_fnc_missile_lgb_track, 0.01, [_projectile, _laserCode, time, 0, _bomb]] call cba_fnc_addPerFrameHandler;
_handle
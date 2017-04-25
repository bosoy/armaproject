// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_velocity","_damage", "_fallStanding", "_dirIndex", "_selectedAnimArray",
	"_rand", "_adat", "_playAnim", "_knockOutTime"];

PARAMS_3(_unit,_energy,_direction);
DEFAULT_PARAM(3,_force_fall,false);

// dont knock them over if any of these conditions met
if !(alive _unit) exitWith { false };
if (vehicle _unit != _unit) exitWith { false };
if (surfaceIsWater (position _unit)) exitWith { false };
if (_unit call FUNC(isUncon)) exitWith { false };
_adat = _unit call CBA_fnc_getUnitAnim;
EXPLODE_2_PVT(_adat,_anim,_speed);
if (_anim == "prone") exitWith { false };
if (!GVAR(fall_on_impact_while_standing) && {_speed == "stop"}) exitWith { false };

_abort = false;
if (_energy < ALWAYS_FALL_THRESHOLD && {!_force_fall}) then {
	if (_energy < RANDOM_FALL_THRESHOLD) exitWith { TRACE_2("Fall-Energy-Abort",_unit,RANDOM_FALL_CHANCE); _abort = true };
	_rand = random(100);
	if (_rand > RANDOM_FALL_CHANCE) then { TRACE_3("Fall-Random-Abort",_unit,_rand,RANDOM_FALL_CHANCE); _abort = true };
};
if (_abort && {!_force_fall}) exitWith { false };
_unit setVariable ["ace_w_falling", true];

// Determine needed animation
//_playAnim = "ActsPercMrunSlowWrflDf_TumbleOver";
_playAnim = switch (_speed) do {
	case "stop":   { "AmovPercMsprSlowWrflDF_AmovPpneMstpSrasWrflDnon" };
	case "slow":   { "AmovPercMrunSlowWrflDF_AmovPpneMstpSrasWrflDnon" };
	case "normal": { "AmovPercMrunSlowWrflDF_AmovPpneMstpSrasWrflDnon" };
	// Fast :-D
	default { "ActsPercMrunSlowWrflDf_TumbleOver" };
};

/* Should be based on direction the bullet is coming from, if possible
TODO: Bullet fired from behind -> fall forward
TODO: Bullet fired from front -> fall backwards
BUG: Currently bullet fired from front also makes you fall forward, which does not sound plausible
EVAL: Also needs to make sure that there are no object where the player could fall into due to the anim and get killed
EVAL: Needs appropriate animations
*/

// Fall!
// TODO: Bullet Direction -> Direction of fall etc.
// pick which set of animations to play
// _selectedAnimArray = if(_anim == "kneel") then { GVAR(anims_kneel) } else { GVAR(anims_standing) };
// finally, find our reldir and do it.
// if (_direction < 0) then { ADD(_direction,360) };

_knockOutTime = KNOCK_OUT_TIME_BASE * (_energy / FALL_ENERGY_DIV);
//[_unit, _knockOutTime] spawn ace_fx_fnc_knockout;

TRACE_2("PlayAnim",_unit,_playAnim);
_unit playMoveNow _playAnim;

// Monitor fall
[_unit, _knockOutTime] spawn {
	PARAMS_2(_unit,_knockOutTime);
	sleep _knockOutTime;
	_unit setVariable ["ace_w_falling", false];
};

true;

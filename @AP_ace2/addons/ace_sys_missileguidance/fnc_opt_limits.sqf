// Guidance limits enforcer by zGuba (c) 2009
// Input: [vehicle, type of vehicle, weapon direction,missile on the way,[initial vectors dir and up]]
// Output: [guidance vector [n,n,n], limits exceeded (t/f), weapon direction (string), guidance direction (string)]

#include "script_component.hpp"

#define __cfg getNumber (_turret >> QGVAR(limitsOn))

#define __launcharray_ok isArray (_turret >> QGVAR(limits))
#define __trackarray_ok isArray (_turret >> QGVAR(tracklimits))

#define __launcharray getArray (_turret >> QGVAR(limits))
#define __trackarray getArray (_turret >> QGVAR(tracklimits))

private
[
	"_startVectors",
	"_vectorDir","_vectorUp",
	"_vectorWM","_worldDirM","_worldUpM",
	"_outputMH","_outputMV","_outputM","_output",
	"_limitArray","_limitS","_limitN","_limitW","_limitE",
	"_limitsHR","_limitsVR",
	"_exceeded","_vectorText","_outputText"
];

PARAMS_5(_vehicle,_vType,_vector,_track,_turret);

_vectorDir = vectorDir _vehicle;
_vectorUp = vectorUp _vehicle;

_vectorWM = [_vector, _vectorDir, _vectorUp] call FUNC(mat_turnvecdirup);

_vectorWMH = (_vectorWM select 0) atan2 (_vectorWM select 1);
_vectorWMV = (_vectorWM select 2) atan2 1;

_exceeded = false;

if ((!_track && {__launcharray_ok}) || {(_track && {__trackarray_ok})}) then {
	if (_track) then { // Platform's deviation from initial situation
		_startVectors = _this select 5;
		_startVectorDir = _startVectors select 0;
		_startVectorUp = _startVectors select 1;

		_limitArray = __trackarray;
		_limitT = _limitArray select 0;
		_limitB = _limitArray select 1;

		_vectorDirVsOldDir = abs(acos([_vectorDir,_startVectorDir] call ACE_fnc_dotProduct));
		_vectorUpVsOldUp = abs(acos([_vectorUp,_startVectorUp] call ACE_fnc_dotProduct));

		if ((_vectorDirVsOldDir > _limitT) || {(_vectorUpVsOldUp > _limitB)}) then {
			_exceeded = true;
		};

		TRACE_4("Tracking check",_limitArray,_vectorDirVsOldDir,_vectorUpVsOldUp,_exceeded);
	} else { // Seeker/tracker limits
		_limitArray = __launcharray;
		_limitT = _limitArray select 0;
		_limitB = _limitArray select 1;
	//	_offsetV = _limitArray select 2;
	//	_offsetH = _limitArray select 3;

		// ToDo: turn vectorDir via offset.

		_vectorVsVectorDir = abs(acos([_vector,_vectorDir] call ACE_fnc_dotProduct));
		_vectorUpVsWorldUp = abs(acos([_vectorUp,[0,0,1]] call ACE_fnc_dotProduct));

		if ((_vectorVsVectorDir > _limitT) || (_vectorUpVsWorldUp > _limitB)) then {
			_exceeded = true;
		};

		TRACE_4("Launch check",_limitArray,_vectorDirVsOldDir,_vectorUpVsWorldUp,_exceeded);
	};
};

//_vectorText = format ["%1°H %2°V",round (_vectorWMH), round (_vectorWMV)];
//_outputText = format ["%1°H %2°V",round (_outputMH), round (_outputMV)];

[_vector,_exceeded," "," "]

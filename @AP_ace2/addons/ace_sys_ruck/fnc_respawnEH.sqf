//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

if ( isNil QGVAR(RuckPersist) ) then {
	_unit setvariable ["ACE_RuckMagContents", []];
	_unit setvariable ["ACE_RuckWepContents", []];
	_unit setvariable ["ACE_weapononback", "", true];
}

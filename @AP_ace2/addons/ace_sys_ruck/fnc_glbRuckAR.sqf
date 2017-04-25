//#define DEBUG_MODE_FULL
#include "script_component.hpp"

/* Global Ruck Add/Remove
	Used to control placeholder rucks on dead bodies.
	Ruck contents variable handling should be done elsewhere.
*/
PARAMS_3(_body,_ruckNam,_take);

if (_take) then {
	if (_body hasWeapon _ruckNam) then {
		_body removeWeapon _ruckNam;
	};
} else {
	if !(_body hasWeapon _ruckNam) then {
		_body addWeapon _ruckNam;
	};
};
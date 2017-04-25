///////////////////////////////////////////
//  ACE Optical Missile Guidance Thread  //
///////////////////////////////////////////
// SACLOS method - missile tries to stay in gunner's LOS to target
// by q1184
// zGuba
// Sickboy
// Rocko

//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgAmmo" >> _ammoType
#define __TRACKINTERVAL 0.025

#define EXCEED_SPEED 70
#define EXCEED_DIST 1000


if (isDedicated || {!isNil QGVAR(missile_saclos_fsm_only)}) then {
	_handle = [
		_this, /* parameters */
		FUNC(saclos_exit_condition),
		FUNC(saclos_run_code),
		FUNC(saclos_init_code),
		FUNC(saclos_exit_condition),
		GVAR(saclos_private_variables),
		FUNC(saclos_run_condition)
	] execFSM cba_common_delayless_loop;
} else {
	_handle = [
		FUNC(saclos_run_code),
		_this, /* parameters */
		0, /* delay	*/
		FUNC(saclos_init_code),
		FUNC(saclos_exit_code),
		FUNC(saclos_run_condition),
		FUNC(saclos_exit_condition),
		GVAR(saclos_private_variables)
	] call cba_common_fnc_addPerFrameHandlerLogic;
};

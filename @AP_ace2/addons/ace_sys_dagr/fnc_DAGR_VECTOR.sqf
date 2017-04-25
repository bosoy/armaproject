#include "script_component.hpp"

if !(local player) exitwith {};
NODAGRDISPLAY = true;
DAGRCOMPATRF = ["ACE_Rangefinder_OD", "Binocular_Vector", "Laserdesignator"];
private "_fnc_dagr";
_fnc_dagr = {
	PARAMS_2(_target,_detected);
	if ((currentWeapon player) in DAGRCOMPATRF && {alive player} && {!DAGR_EMPTYVECTOR} && {!isNull _target}) then {
		DAGRLAZPOS = getPosASL _target;
		DAGRLAZDIST = (getPosASL player) distance DAGRLAZPOS;
		DAGRLAZDIST = floor (DAGRLAZDIST/EMP_RF_ACC)*EMP_RF_ACC;
		//DAGRLazHeading = player weaponDirection (currentWeapon player);
		DAGRLazHeading = vectorDir _target;
		NODAGRDISPLAY = false;
	};
};

["ace_sys_rangefinder_Lazing", _fnc_dagr] call CBA_fnc_addEventHandler;

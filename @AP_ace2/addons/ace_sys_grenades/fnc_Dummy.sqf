//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_dummy","_pos","_vel","_vDirUp", "_params"];

#define __dummyPos getArray (configFile >> "CfgWorlds" >> worldname >> "centerPosition")
#define __dummyPosSet [__dummyPos select 0, __dummyPos select 1, 3000];

PARAMS_4(_object,_grenadeType,_ammo,_unit);

_dummy_grenade = switch (true) do {
	case (_ammo == "G_40mm_HE"): { "ACE_Grenade_VOG25_Dummy" };
	case (_ammo == "ACE_G40mm_HE_VOG25P"): { "ACE_Grenade_VOG25P_Dummy" };
	case (_ammo in ["ACE_G_40mm_HEDP","ACE_G_40mm_HE"]): { "ACE_Grenade_M433_Dummy" };
};

_pos = getPos _object;
_vel = velocity _object;
_vDirUp = [vectorDir _object,vectorUp _object];
_object setPos __dummyPosSet;

_dummy = _dummy_grenade createVehicle [(_pos select 0)+((_vel select 0)*.005),(_pos select 1)+((_vel select 1)*.005),(_pos select 2)+((_vel select 2)*.005)];
_dummy setPosASL (getPosASL _dummy);
_params = [_dummy, _vDirUp, _vel];
// if !(isServer) then { PUSH(_params,true) };
[QGVAR(dumm), _params] call CBA_fnc_globalEvent; // Grenade objects setPos are synced, but velocity+vdir aren't synced over the net...

switch (toUpper _grenadeType) do {
	case "M203": {
		[_object, _dummy, _grenadeType,_unit] spawn FUNC(M203); // M433, M406, M918
	};
	case "GP25": {
		switch (_ammo) do {
			TRACE_1("GP25",_ammo);
			case "ACE_G40mm_HE_VOG25P": { [_object, _dummy, _unit] spawn FUNC(VOG25P); }; // VOG 25 P
			//case "ACE_Grenade_40mm_HEDP": { [_object,_dummy,_grenadeType] spawn FUNC(VOG25); };
			case "G_40mm_HE": { [_object,_dummy,_grenadeType, _unit] spawn FUNC(VOG25); }; // VOG 25
		};
		[_object,_dummy] spawn COMPILE_FILE(VOG25Timer);
	};
};

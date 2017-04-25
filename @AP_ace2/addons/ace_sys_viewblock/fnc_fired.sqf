/* ace_sys_viewblock (.pbo) | (c) 2008, 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __sim getText(configFile >> "CfgAmmo" >> _ammo >> "ACE_simulation")
#define __vel (velocity _smokeshell call ACE_fnc_magnitude)
#define __TTL getNumber(configFile >> "CfgAmmo" >> _ammo >> "timeToLive")
#define __windStrength (call FUNC(winddir)) select 1

_this spawn {
	private["_ammo","_smokeshell","_stop","_ace_viewblock","_ace_ViewblockType","_pos"];
	_ammo = _this select 4;
	_smokeshell = _this select 6;

	TRACE_2("",_smokeshell,_ammo);
	_stop = false;
	while { alive _smokeshell && {!isNull _smokeshell} && {!_stop} } do {
		sleep .05;
		if (__vel < 0.2) then {
			_stop = true;
			TRACE_1("Stopped","");
		};
		_pos = getPosATL _smokeshell;
		TRACE_2("Pos Vel", _pos,__vel);
	};
	if (typeName _pos != "ARRAY") exitWith { false };

	if (__sim == "shotWP") then {
		_pos = position _smokeshell;
	};

	_ace_ViewblockType = switch (true) do {
		case (__sim == "shotWP"): {"ACE_Viewblock_InvWPxWP"};
		case (__windStrength <= .66): {"ACE_Viewblock_Inv5x5"};
		case (__windStrength <= .72): {"ACE_Viewblock_Inv6x6"};
		case (__windStrength <= 1.75): {"ACE_Viewblock_Inv7x7"};
		case (__windStrength <= 2.57): {"ACE_Viewblock_Inv8x8"};
		default {"ACE_Viewblock_Inv10x10"};
	};

	#ifdef DEBUG_MODE_FULL
		_ace_ViewblockType = "ACE_Viewblock_Vis10x10";
		TRACE_5("",_stop,_ace_ViewblockType,_pos,_smokeshell,__TTL);
		[_ace_ViewblockType, _pos, _smokeshell, __TTL] spawn FUNC(viewblock);
	#else
		// also send to clients because nowadays there can be quite some ai on clients, ie cause of RTE etc,    !!!!!!!not true anymore, for a long time....!!!!!!!
		// fired_veh is set to local only, and other smokeshell fired events are local only too.
		[QGVAR(viewb), [_ace_ViewblockType, _pos, _smokeshell, __TTL]] call ACE_fnc_clientToServerEvent;
	#endif
};

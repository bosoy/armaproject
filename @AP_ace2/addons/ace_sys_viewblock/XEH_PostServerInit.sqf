//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

if (!isNil QGVAR(blockgrass)) then {
	GVAR(aivbobjs) = [];
	GVAR(aivbobjscounter) = 0;
	FUNC(createAIVB) = {
		private ["_pos", "_vbobj", "_oldvo"];
		_pos = position _this;
		#ifndef DEBUG_MODE_FULL
		_vbobj = "ACE_Viewblock_ProneInGrass" createVehicleLocal _pos;
		#else
		_vbobj = "ACE_Viewblock_ProneInGrass_Debug" createVehicleLocal _pos;
		#endif
		_vbobj setDir (direction _this);
		_vbobj setPos _pos;
		TRACE_1("createAIVB",_vbobj);
		_oldvo = _this getVariable [QGVAR(aivbobj), objNull];
		TRACE_1("createAIVB",_oldvo);
		if (!isNull _oldvo) then {deleteVehicle _oldvo};
		_this setVariable [QGVAR(aivbobj), _vbobj];
		GVAR(aivbobjs) set [count GVAR(aivbobjs), _vbobj];
		_vbobj setVariable [QGVAR(user), _this];
		
		INC(GVAR(aivbobjscounter));
		if (GVAR(aivbobjscounter) > 100) then {
			GVAR(aivbobjscounter) = 0;
			{
				if (!isNull _x) then {
					if (isNull {_x getVariable [QGVAR(user), objNull]}) then {
						GVAR(aivbobjs) set [_forEachIndex, objNull];
					};
				};
			} forEach GVAR(aivbobjs);
			GVAR(aivbobjs) = GVAR(aivbobjs) - [objNull];
		};
	};
	
	FUNC(deleteAIVB) = {
		private ["_oldvo"];
		_oldvo = _this getVariable [QGVAR(aivbobj), objNull];
		TRACE_1("deleteAIVB",_oldvo);
		if (!isNull _oldvo) then {deleteVehicle _oldvo};
		GVAR(aivbobjs) = GVAR(aivbobjs) - [objNull];
	};
	
	FUNC(moveAIVB) = {
		private ["_vbobj"];
		_vbobj = _this getVariable [QGVAR(aivbobj), objNull];
		TRACE_1("moveAIVB",_vbobj);
		if (isNull _vbobj) exitWith {};
		_vbobj setDir (direction _this);
		_vbobj setPos (position _this);
	};
	
	[QGVAR(createaivb), {_this call FUNC(createAIVB)}] call ACE_fnc_addClientToServerEventhandler;
	[QGVAR(delaivb), {_this call FUNC(deleteAIVB)}] call ACE_fnc_addClientToServerEventhandler;
	[QGVAR(moveaivb), {_this call FUNC(moveAIVB)}] call ACE_fnc_addClientToServerEventhandler;
};

ADDON = true;
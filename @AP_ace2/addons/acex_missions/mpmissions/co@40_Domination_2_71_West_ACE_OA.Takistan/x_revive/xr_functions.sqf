// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_revive\xr_functions.sqf"
#include "xr_macros.sqf"

// create a global marker, returns created marker
// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call FUNC(CreateMarkerGlobal);
FUNCXR(CreateMarkerGlobal) = {
	private ["_m_name","_m_pos","_m_shape","_m_col","_m_size","_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
	PARAMS_5(_m_name,_m_pos,_m_shape,_m_col,_m_size);
	_m_text = (if (count _this > 5) then {_this select 5} else {""});
	_m_dir = (if (count _this > 6) then {_this select 6} else {-888888});
	_m_type = (if (count _this > 7) then {_this select 7} else {""});
	_m_brush = (if (count _this > 8) then {_this select 8} else {""});
	_m_alpha = (if (count _this > 9) then {_this select 9} else {0});
	
	_marker = createMarker [_m_name, _m_pos];
	if (_m_shape != "") then {_marker setMarkerShape _m_shape};
	if (_m_col != "") then {_marker setMarkerColor _m_col};
	if (count _m_size > 0) then {_marker setMarkerSize _m_size};
	if (_m_text != "") then {_marker setMarkerText _m_text};
	if (_m_dir != -888888) then {_marker setMarkerDir _m_dir};
	if (_m_type != "") then {_marker setMarkerType _m_type};
	if (_m_brush != "") then {_marker setMarkerBrush _m_brush};
	if (_m_alpha != 0) then {_marker setMarkerAlpha _m_alpha};
	_marker
};

// create a local marker, returns created marker
// parameters: marker name, marker pos, marker shape, marker color, marker size;(optional) marker text, marker dir, marker type, marker brush
// example: ["my marker",  position player, "Dot", "ColorBlue", [0.5,0.5]] call FUNCXR(CreateMarkerLocal);
FUNCXR(CreateMarkerLocal) = {
	private ["_m_name","_m_pos","_m_shape","_m_col","_m_size","_m_text","_m_dir","_m_type","_m_brush","_m_alpha"];
	PARAMS_5(_m_name,_m_pos,_m_shape,_m_col,_m_size);
	_m_text = (if (count _this > 5) then {_this select 5} else {""});
	_m_dir = (if (count _this > 6) then {_this select 6} else {-888888});
	_m_type = (if (count _this > 7) then {_this select 7} else {""});
	_m_brush = (if (count _this > 8) then {_this select 8} else {""});
	_m_alpha = (if (count _this > 9) then {_this select 9} else {0});
	
	_marker = createMarkerLocal [_m_name, _m_pos];
	if (_m_shape != "") then {_marker setMarkerShapeLocal _m_shape};
	if (_m_col != "") then {_marker setMarkerColorLocal _m_col};
	if (count _m_size > 0) then {_marker setMarkerSizeLocal _m_size};
	if (_m_text != "") then {_marker setMarkerTextLocal _m_text};
	if (_m_dir != -888888) then {_marker setMarkerDirLocal _m_dir};
	if (_m_type != "") then {_marker setMarkerTypeLocal _m_type};
	if (_m_brush != "") then {_marker setMarkerBrushLocal _m_brush};
	if (_m_alpha != 0) then {_marker setMarkerAlphaLocal _m_alpha};
	_marker
};

FUNCXR(DirTo) = {
	/************************************************************
		Direction To
		By Andrew Barron

	Parameters: [object or position 1, object or position 2]

	Returns the compass direction from object/position 1 to
	object/position 2. Return is always >=0 <360.

	Example: [player, getpos dude] call BIS_fnc_dirTo
	************************************************************/
	private ["_pos1","_pos2","_ret"];
	PARAMS_2(_pos1,_pos2);

	if (typename _pos1 == "OBJECT") then {_pos1 = getPosAsl _pos1};
	if (typename _pos2 == "OBJECT") then {_pos2 = getPosAsl _pos2};

	_ret = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
	if (_ret < 0) then {_ret = _ret + 360};
	_ret
};

FUNCXR(getUnitStance) = {
	private ["_unit", "_selz"];
	_unit = _this;
	if (isNull _unit) exitWith {""};
	if (vehicle _unit != _unit) exitWith {""};
	_selz = (_unit selectionPosition "neck") select 2;
	if (_selz == 0) exitWith {""};
	if (_selz > 1.4) exitWith {"stand"};
	if (_selz > 0.8) exitWith {"kneel"};
	"prone"
};

FUNCXR(handlenet) = {
	__TRACE_1("handlenet","_this");
	switch (_this select 1) do {
		case 100: {if (local (_this select 0)) then {
			__TRACE("FUNCXR(handlenet) Die case 100");
			(_this select 0) playActionNow "Die"
		}};
		case 101: {(_this select 0) switchmove "AmovPpneMstpSnonWnonDnon_healed";(_this select 0) playMoveNow "AmovPpneMstpSnonWnonDnon_healed";if (local (_this select 0)) then {
			__TRACE("FUNCXR(handlenet) Die case 101");
			(_this select 0) playActionNow "Die"
		}};
		case 102: {(_this select 0) switchmove "AmovPpneMstpSnonWnonDnon_healed";(_this select 0) playMoveNow "AmovPpneMstpSnonWnonDnon_healed"};
		case 103: {(_this select 0) switchmove "";if (local (_this select 0)) then {(_this select 0) moveInCargo (_this select 2)}};
		case 104: {if (local (_this select 0)) then {unassignVehicle (_this select 0)}};
		case 105: {(_this select 0) switchmove ""};
	};
};

FUNCXR(handlenet2) = {
	__TRACE_1("handlenet2","_this");
	switch (_this select 1) do {
		case 100: {if (local (_this select 0)) then {(_this select 0) playActionNow "Die"}};
		case 104: {if (local (_this select 0)) then {unassignVehicle (_this select 0)}};
	};
};

if (!isDedicated) then {
	FUNCXR(dohandleheal) = {
		__pSetVar [QGVARXR(overall), 0];
		__pSetVar [QGVARXR(head_hit), 0];
		__pSetVar [QGVARXR(body), 0];
		__pSetVar [QGVARXR(hands), 0];
		__pSetVar [QGVARXR(legs), 0];
	};

	FUNCXR(HandleHeal) = {
		private ["_healed", "_healer", "_healercanheal"];
		PARAMS_2(_healed,_healer,_healercanheal);
		if (_healercanheal) then {
			if (alive _healed && {alive _healer}) then {
				if (local _healed) then {
					call FUNCXR(dohandleheal);
				} else {
					[QGVARXR(doHandleHeal), [_healed]] call d_fnc_NetCallEventSTO;
				};
			};
		};
		false
	};
};
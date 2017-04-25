Private ["_han","_hasAction","_start","_state","_status","_unit"];
_unit = _this select 0;
_start = time;
_state = "";

if (isPlayer _unit) then {
	[_unit] Spawn ISIS_Effects;
};

_han = [nil, _unit, rPLAYACTION, "agonyStart"] call RE;
sleep 3;
_han = [nil, _unit, rPLAYACTION, "GestureNod"] call RE;

//--- Add action to west or east units.
if (side _unit == west || side _unit == east) then {
	_hasAction = _unit getVariable 'hasAction';
	if (isNil '_hasAction') then {_hasAction = false};
	if !(_hasAction) then {
		WFBE_ISIS_AddAction = [(side _unit),'CLTFNCISIS_ADDACTION',_unit];
		publicVariable 'WFBE_ISIS_AddAction';
		if (isHostedServer || local player) then {[(side _unit),'CLTFNCISIS_ADDACTION',_unit] Spawn HandlePVF};
	};
};

while {true} do {
	sleep 0.7;
	
	_status = _unit getVariable "stunned";
	if (isNil '_status' || !(alive _unit)) exitWith {_unit removeAllEventHandlers "handleDamage"};
	if !(_status) exitWith {
		_han = [nil, _unit, rPLAYACTION, "GestureNod"] call RE;
	};
	
	if ((time - _start > 15 || _state != animationState _unit)) then {
		_start = time;
		if (((animationState _unit) == "AinjPpneMstpSnonWnonDnon") || ((animationState _unit) == "AinjPpneMstpSnonWrflDnon")) then {
			_han = [nil, _unit, rPLAYACTION, "GestureNod"] call RE;
			_state = animationState _unit;
			_han = [nil, _unit, rPLAYACTION, ("GestureSpasm"+ (str floor random 7))] call RE;
		};
		if (((animationState _unit) == "AinjPpneMstpSnonWrflDnon_injuredHealed") || ((animationState _unit) == "AinjPpneMstpSnonWnonDnon_injuredHealed")) then {
			_han = [nil, _unit, rPLAYACTION, "GestureNod"] call RE;
			_state = animationState _unit;
			_han = [nil, _unit, rPLAYACTION, ("GestureSpasm"+ (str floor random 7))] call RE;
		};
	};

	_unit setDamage (getDammage _unit + 0.002);
};

_han = [nil, _unit, rPLAYACTION, "agonyStop"] call RE;

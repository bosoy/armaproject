Private ['_airCoef','_artCoef','_cts','_distanceMin','_heaCoef','_healTime','_i','_ligCoef','_name','_nearIsDP','_nearIsRT','_nearIsSP','_repairRange','_spType','_supportRange','_supports','_typeRepair','_veh'];
_veh = _this select 0;
_supports = _this select 1;
_typeRepair = _this select 2;
_spType = _this select 3;
_supportRange = 'WFBE_SUPPORTRANGE' Call GetNamespace;
_repairRange = 'WFBE_REPAIRTRUCKRANGE' Call GetNamespace;

//--- Retrieve Informations.
_name = [typeOf _veh, 'displayName'] Call GetConfigInfo;
_healTime = 'WFBE_SUPPORTHEALTIME' Call GetNamespace;

//--- SP?
_nearIsSP = false;
_nearIsDP = false;
_nearIsRT = false;
{
	if ((typeOf _x) == _spType) then {_nearIsSP = true};
	if ((typeOf _x) in WFDEPOT) then {_nearIsDP = true};
	if ((typeOf _x) in _typeRepair) then {_nearIsRT = true};
} forEach _supports;

//--- Coefficient Vary depending on the support type.
_airCoef = 1;
_artCoef = 1;
_heaCoef = 1;
_ligCoef = 1;
if (_nearIsRT) then {
	_airCoef = 2.8;
	_artCoef = 2.4;
	_heaCoef = 2.2;
	_ligCoef = 2.0;
};
if (_nearIsDP) then {
	_airCoef = 2.3;
	_artCoef = 2.1;
	_heaCoef = 1.9;
	_ligCoef = 1.7;
};
if (_nearIsSP) then {
	_airCoef = 1.8;
	_artCoef = 1.6;
	_heaCoef = 1.4;
	_ligCoef = 1.2;
};

//--- Class Malus.
if (_veh isKindOf 'Air') then {_healTime = round(_healTime * (_airCoef + getDammage _veh))};
if (_veh isKindOf 'StaticWeapon') then {_healTime = round(_healTime * (_artCoef + getDammage _veh))};
if (_veh isKindOf 'Tank') then {_healTime = round(_healTime * (_heaCoef + getDammage _veh))};
if (_veh isKindOf 'Car' || _veh isKindOf 'Motorcycle') then {_healTime = round(_healTime * (_ligCoef + getDammage _veh))};

//--- Inform the player.
hint parseText(Format[localize "STR_WF_Healing",_name,_healTime]);

//--- Make sure that we still have something as a support.
_cts = 0;
_i = 0;
while {true} do {
	sleep 1;
	
	//--- Check the distance & alive.
	_cts = 0;
	{
		_distanceMin = if ((typeOf _x) in _typeRepair) then {_repairRange} else {_supportRange};
		if ((alive _x) && ((_veh distance _x) < _distanceMin)) then {_cts = _cts + 1};
	} forEach _supports;
	
	_i = _i + 1;
	
	if (_cts == 0 || !(alive _veh) || (getPos _veh) select 2 > 2) exitWith {hint parseText(Format[localize "STR_WF_Heal_Failed",_name])};
	if (_i >= _healTime) exitWith {hint parseText(Format[localize "STR_WF_Heal_Success",_name])};
};

//--- Heal the damages?
if (_cts != 0) then {
	if (_veh isKindOf "Man") then {
		_veh setDammage 0;
		if (paramAceWounds) then
		{
			_veh call ace_sys_wounds_fnc_RemoveBleed;
			_veh call ace_sys_wounds_fnc_RemovePain;
			_vel call ace_sys_wounds_fnc_RemoveUncon;
		};
	} else {
		_crews = crew _veh;
		if (count _crews > 0) then {
			{
				_x setDammage 0;
				if (paramAceWounds) then
				{
					_x call ace_sys_wounds_fnc_RemoveBleed;
					_x call ace_sys_wounds_fnc_RemovePain;
					_x call ace_sys_wounds_fnc_RemoveUncon;
				};
			} forEach _crews
		};
	};
};
private ["_unit", "_defaultWeap", "_defaultAmmo"];

_unit = _this;

_defaultWeap = Format ["WFBE_%1DEFAULTWEAPONS",sideJoinedText] Call GetNamespace;
_defaultAmmo = Format ["WFBE_%1DEFAULTAMMO",sideJoinedText] Call GetNamespace;

if (paramAceWounds) then
{
	_defaultAmmo = _defaultAmmo + [ 'ACE_Bandage', 'ACE_Bandage', 'ACE_Morphine', 'ACE_Morphine' ];
	if(getNumber(configFile >> "CfgVehicles" >> (typeOf _unit) >> "attendant") == 1) then
	{
		_defaultAmmo = _defaultAmmo + [ 'ACE_Epinephrine', 'ACE_Epinephrine', 'ACE_Medkit', 'ACE_Medkit' ];
	};
};

[_unit,_defaultWeap,_defaultAmmo] Call EquipLoadout;
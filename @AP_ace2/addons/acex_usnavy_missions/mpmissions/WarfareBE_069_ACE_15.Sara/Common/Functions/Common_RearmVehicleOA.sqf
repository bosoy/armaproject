Private['_amount','_config','_get','_isAir','_isArtillery','_magazines','_side','_turrets','_type','_vehicle'];

_vehicle = _this select 0;
_side = _this select 1;
_type = typeOf _vehicle;
_isAir = if (_vehicle isKindOf "Air") then {true} else {false};

/* Clear the vehicle */
_vehicle setVehicleAmmo 0;

/* Reload all turrets */
_turrets = [];
_config = configFile >> 'CfgVehicles' >> typeOf _vehicle >> 'Turrets';
_turrets = [_config] call GetTurretsMags;
[_vehicle,_turrets] Call SetTurretsMags;
/* Reload the driver (Special) */
_magazines = [configFile >> 'CfgVehicles' >> typeOf _vehicle] call GetVehicleMags;
{_vehicle addMagazineTurret[_x,[-1]]} forEach _magazines;

reload _vehicle;

/* CM Parameter */
if (paramCounterMeasures && _vehicle isKindOf 'Air') then {
	_amount = if (_vehicle isKindOf 'Plane') then {'WFBE_COUNTERMEASUREPLANES' Call GetNamespace} else {'WFBE_COUNTERMEASURECHOPPERS' Call GetNamespace};
	_vehicle setVariable ['FlareCount', _amount];
};

/* Are we dealing with an artillery unit ? */
_isArtillery = -1;
if (_side == west || _side == east) then {_isArtillery = [_type,_side] Call IsArtillery};
if (_isArtillery != -1) then {[_vehicle,_isArtillery,_side] Call EquipArtillery};

/* Balanced Unit */
if (_type in ('WFBE_BALANCEDUNITS' Call GetNamespace) && paramBalancing) then {[_vehicle] Call BalanceInit};

/* EASA Module */
if (paramEASA) then {
	if (_type in ('WFBE_EASA_Vehicles' Call GetNamespace)) then {
		_get = _vehicle getVariable 'WFBE_EASA_Setup';
		if !(isNil '_get') then {[_vehicle,0] Call EASA_Equip};
	};
};

/* Mando Missiles - Reload Flares */
if (paramMandoMissiles && _isAir) then {
	_var = _vehicle getVariable "mando_maxflares";
	if !(isNil "_var") then	{
		_vehicle setVariable ["mando_flaresleft", _var, true];
		call mando_update_flares;
	};
};
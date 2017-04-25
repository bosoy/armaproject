private ["_indexWeapons", "_indexMagazines", "_indexOnBack", "_indexRuckWeapons", "_indexRuckMags", "_indexPrimary", "_indexSecondary", "_indexSidearm", "_typesIFAK", "_filterNames", "_primary", "_secondary", "_sidearm", "_misc", "_magazine", "_all", "_primaryBackpack", "_secondaryBackpack", "_sidearmBackpack", "_miscBackpack", "_allBackpack", "_currentGear", "_currentWeaponUIState", "_currentMagazineUIState", "_getCompatibleMagazines", "_weapon", "_weaponMags", "_mags", "_muzzles", "_getItemDataByConfigType", "_data", "_configType", "_item", "_W", "_getItemDataByFilterType", "_filter", "_get", "_inventoryToGear", "_ret", "_unit", "_backwep", "_current", "_ruckmags", "_ruckweapons", "_safeArray", "_getItemCost", "_itemName", "_getItemWeight", "_getRuckItemsVolume", "_gear", "_volume", "_getGearCost", "_price", "_cost", "_getGearWeight", "_weight", "_totalWeight", "_fillInBlankImages", "_i", "_renderGear", "_pic", "_itemIndex", "_specialIndex", "_mainMagIndex", "_sideMagIndex", "_ifakCount", "_isIFAK", "_wob", "_weaponUIState", "_magazineUIState", "_magazineSpace", "_forEachIndex", "_getItemCountByType", "_count", "_itemType", "_countThisOne", "_renderRuckContents", "_u", "_capacity", "_getGearRuck", "_getMagazineCountByPool", "_handgunpool", "_addMagazineToGear", "_magCount", "_magLimit", "_magSize", "_oldMagazines", "_applyGearToUnit", "_maybeRuck", "_addItemToRuck", "_ruck", "_size", "_added", "_packable", "_currentUnit", "_initialCost", "_updateGear", "_updateMainList", "_updateSecondaryList", "_updateUnit", "_backpackSelected", "_selectedWeapon", "_currentFilter", "_defaultWeap", "_defaultAmmo", "_defaultLoadoutCost", "_lbSelChanged", "_mainCommand", "_inventoryClick", "_gearAction", "_weaponList", "_magazineList", "_funds", "_respawnCost", "_mag", "_ruckIndex", "_ruckItemClass", "_ruckItem", "_add", "_itemCount", "_temp", "_respawnPenalty","_divisor"];

_indexWeapons = 0;
_indexMagazines = 1;
_indexOnBack = 2;
_indexRuckWeapons = 3;
_indexRuckMags = 4;
_indexPrimary = 5;
_indexSecondary = 6;
_indexSidearm = 7;
_typesIFAK = [ "ACE_Morphine", "ACE_Bandage", "ACE_Epinephrine" ];
_filterNames = [ "all", "primary", "secondary", "sidearm", "misc" ];

_primary = +(WF_Logic getVariable 'primaryClasses');
_secondary = +(WF_Logic getVariable 'secondaryClasses');
_sidearm = +(WF_Logic getVariable 'sidearmClasses');
_misc = +(WF_Logic getVariable 'miscClasses');
_magazine = +(WF_Logic getVariable 'magazineClasses');

_all = _primary + _secondary + _sidearm + _misc;

_primaryBackpack = [];
_secondaryBackpack = [];
_sidearmBackpack = _sidearm;
_miscBackpack = _misc + _magazine;
_allBackpack = _misc + _sidearm + _magazine;

// Gear Array.  Many methods use this format.  It is:
// 0: Weapons
// 1: Magazines
// 2: ACE weapon on back
// 3: Weapons in rucksack as a sequence of doubles: [ item, quantity ]
// 4: Magazines in rucksack as a sequence of doubles: [ item, quantity ]
// 5: Current primary weapon
// 6: Current secondary weapon
// 7: Current sidearm
_currentGear = [ [], [], "", [], [], "", "", "" ];

// The following twe are arrays of doubles.  Each double is [id, index] that maps
// UI controls to gear in the _currentGear structure.
//
// id: Control ID of a control in the gear dialog.
// index: index into the magazine or weapon array in _currentGear that corresponds to the
// weapon or magazine represented by the control in question.
_currentWeaponUIState = [];
_currentMagazineUIState = [];

// Given a weapon class, get the magazines that will fit in it.
_getCompatibleMagazines =
{
	private ["_weapon","_weaponMags","_mags","_muzzles","_supportedMags","_csw"];
	
	_weapon = _this;
	_weaponMags = [];
	_supportedMags = _magazine + _misc;
	
	_csw = "";
	
	if(isText(configFile >> "CfgWeapons" >> _weapon >> "ace_crewmgtype")) then
	{
		_csw = getText(configFile >> "CfgWeapons" >> _weapon >> "ace_crewmgtype");
	};
	
	if(_csw == "" && isText(configFile >> "CfgWeapons" >> _weapon >> "ace_crewtripodtype")) then
	{
		_csw = getText(configFile >> "CfgWeapons" >> _weapon >> "ace_crewtripodtype");
	};
	
	if(_csw != "") then
	{
		_mags = getArray(configFile >> "CfgVehicles" >> _csw >> "ace_crewdummymags");
		if(!isNil "_mags") then
		{
			{
				if(!(_x in _weaponMags) && _x in _supportedMags) then
				{
					_weaponMags = _weaponMags + [ _x ];
				};
			} forEach(_mags);
		};
	}
	else
	{
		// Disposable weapons have no magazines.
		if(getNumber(configFile >> "CfgWeapons" >> _weapon >> "ace_disposable") != 1) then
		{
			// Main muzzle magazines...
			_mags = getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines");
			if (!isNil "_mags") then
			{
				{
					if(!(_x in _weaponMags) && _x in _supportedMags) then
					{
						_weaponMags = _weaponMags + [ _x ];
					};
				} forEach(_mags);
			};
			
			_muzzles = getArray (configFile >> "CfgWeapons" >> _weapon >> "muzzles");
			if(!isNil "_muzzles") then
			{
				{
					if ((typeName _x) == "STRING") then
					{
						_mags = getArray (configFile >> "CfgWeapons" >> _weapon >> _x >> "magazines");
						if (!isNil "_mags") then
						{
							{
								if(!(_x in _weaponMags) && _x in _supportedMags) then
								{
									_weaponMags = _weaponMags + [_x];
								};
							} forEach(_mags);
						};
					};
				} forEach(_muzzles);
			};
		};
	};
	_weaponMags
};

// arg 0: item class
// arg 1: true if weapon, false if magazine
// returns item data
_getItemDataByConfigType =
{
	private ["_data", "_configType", "_item"];
	
	_item = _this select 0;
	_configType = _this select 1;
	_data = nil;
	if(_configType) then
	{
		_data = (_item+'_W') Call GetNamespace;
	};
	if(isNil "_data") then
	{
		_data = _item Call GetNamespace;
	};
	_data
};

// arg 0: item class
// arg 1: filter type e.g. "all" or "sidearm"
// returns item data
_getItemDataByFilterType =
{
	private [ "_item", "_filter", "_get" ];
	
	_item = _this select 0;
	_filter = _this select 1;
	
	if (_filter == 'secondary' || _filter == 'all') then {
		_get = (_item+'_W') Call GetNamespace;
		if (isNil '_get') then {
			_get = _item Call GetNamespace;
		};
	} else {
		_get = _item Call GetNamespace;
	};
	_get
};

// Argument 0: a unit
//
// Takes that unit's inventory and returns a gear array from it (see above).
_inventoryToGear = {
	private ["_ret","_unit","_backwep","_get","_current","_ruckmags","_ruckweapons","_temp"];
	
	_unit = _this select 0;
	
	_ret = [ [], [], "", [], [], "", "", "" ];
	
	_backwep = _unit getVariable "ACE_weapononback";
	if (!isNil "_backwep") then
	{
		if ((typeName _backwep) == "STRING") then
		{
			_ret set [ _indexOnBack, _backwep ];
		};
	};
	
	_temp = [];
	{
		_get = [ _x, true ] call _getItemDataByConfigType;
		if(!isNil "_get") then
		{
			_temp = _temp + [_x];
		};
	} forEach(weapons _unit);
	_ret set [ _indexWeapons, _temp ];
	
	_temp = [];
	{
		_get = [ _x, false ] call _getItemDataByConfigType;
		if(!isNil "_get") then
		{
			_temp = _temp + [_x];
		};
	} forEach(magazines _unit);
	_ret set [ _indexMagazines, _temp ];
	
	_get = [ primaryWeapon _unit, true ] call _getItemDataByConfigType;
	if(!isNil "_get") then
	{
		_ret set [ _indexPrimary, primaryWeapon _unit ];
	}
	else
	{
		_ret set [ _indexPrimary, "" ];
	};
	
	_get = [ secondaryWeapon _unit, true ] call _getItemDataByConfigType;
	if(!isNil "_get") then
	{
		_ret set [ _indexSecondary, secondaryWeapon _unit ];
	}
	else
	{
		_ret set [ _indexSecondary, "" ];
	};
	
	{
		if (_x in _sidearm) exitWith
		{
			_ret set [ _indexSidearm, _x ];
		};
	} forEach(_ret select _indexWeapons);
	
	if ([_unit] call ACE_fnc_HasRuck) then {
		_ruckmags = _unit getVariable "ACE_RuckMagContents";
		_ruckweapons = _unit getVariable "ACE_RuckWepContents";
		if(!isNil "_ruckweapons") then
		{
			_temp = [];
			{
				_get = [ _x select 0, true ] call _getItemDataByConfigType;
				if(!isNil "_get") then
				{
					_temp = _temp + [_x];
				};
			} forEach(_ruckweapons);
			_ret set [ _indexRuckWeapons, _temp ];
		};
		if(!isNil "_ruckmags") then
		{
			_temp = [];
			{
				_get = [ _x select 0, false ] call _getItemDataByConfigType;
				if(!isNil "_get") then
				{
					_temp = _temp + [_x];
				};
			} forEach(_ruckmags);
			_ret set [ _indexRuckMags, _temp ];
		};
	};
	
	_ret
};

// Get an item's cost.
// Arguments [ item-name, is-weapon ]
// is-weapon is true for weapons or false for magazines
_getItemCost =
{
	private ["_itemName", "_configType","_ret","_get"];
	_itemName = _this select 0;
	_configType = _this select 1;
	_get = [ _itemName, _configType] call _getItemDataByConfigType;
	_ret = 0;
	if(!isNil "_get") then
	{
		_ret = _get select QUERYGEARCOST;
	};
	_ret
};

// Get an item's weight
// Arguments [ item-name, config-type ]
// config-type is usually CfgWeapons or CfgMagazines.
_getItemWeight =
{
	private ["_itemName", "_configType","_ret"];
	_itemName = _this select 0;
	_configType = _this select 1;
	_ret = getNumber (configFile >> _configType >> _itemName >> "ACE_Weight");
	_ret
};

// arg: gear array
// returns: total volume of gear in ruck sack
_getRuckItemsVolume =
{
	private ["_gear", "_volume"];
	
	_gear = _this;
	_volume = 0;
	
	{
		_volume = _volume +
			(getNumber(configFile >> "CfgWeapons" >> (_x select 0) >> "ACE_size") * (_x select 1));
	} forEach(_gear select _indexRuckWeapons);
	
	{
		_volume = _volume +
			(getNumber(configFile >> "CfgMagazines" >> (_x select 0) >> "ACE_size") * (_x select 1));
	} forEach(_gear select _indexRuckMags);
	_volume
};

// Takes a gear array for an argument and returns its cost.
_getGearCost =
{
	private ["_gear","_get","_price","_cost"];
	
	_gear = _this;
	_price = 0;
	
	{
		_cost = [_x, true] call _getItemCost;
		if(!isNil "_cost") then
		{
			_price = _price + _cost;
		};
	} forEach(_gear select _indexWeapons);
	
	{
		_cost = [_x, false] call _getItemCost;
		if(!isNil "_cost") then
		{
			_price = _price + _cost;
		};
	} forEach(_gear select _indexMagazines);
	
	if((_gear select _indexOnBack) != "") then
	{
		_cost = [_gear select _indexOnBack, true] call _getItemCost;
		if(!isNil "_cost") then
		{
			_price = _price + _cost;
		};
	};
	
	{
		_cost = [_x select 0, true] call _getItemCost;
		if(!isNil "_cost") then
		{
			_price = _price + (_cost * (_x select 1));
		};
	} forEach(_gear select _indexRuckWeapons);
	
	{
		_cost = [_x select 0, false] call _getItemCost;
		if(!isNil "_cost") then
		{
			_price = _price + (_cost * (_x select 1));
		};
	} forEach(_gear select _indexRuckMags);
	_price
};

// Takes a gear array for an argument and returns its totalweight.
_getGearWeight =
{
	private ["_gear","_get","_weight","_totalWeight"];
	
	_gear = _this;
	_totalWeight = 0;
	
	{
		_weight = [_x, "CfgWeapons"] call _getItemWeight;
		if(!isNil "_weight") then
		{
			_totalWeight = _totalWeight + _weight;
		};
	} forEach(_gear select _indexWeapons);
	
	{
		_weight = [_x, "CfgMagazines"] call _getItemWeight;
		if(!isNil "_weight") then
		{
			_totalWeight = _totalWeight + _weight;
		};
	} forEach(_gear select _indexMagazines);
	
	_weight = [_gear select _indexOnBack, "CfgWeapons"] call _getItemWeight;
	if(!isNil "_weight") then
	{
		_totalWeight = _totalWeight + _weight;
	};
	
	{
		_weight = [_x select 0, "CfgWeapons"] call _getItemWeight;
		if(!isNil "_weight") then
		{
			_totalWeight = _totalWeight + (_weight * (_x select 1));
		};
	} forEach(_gear select _indexRuckWeapons);
	
	{
		_weight = [_x select 0, "CfgMagazines"] call _getItemWeight;
		if(!isNil "_weight") then
		{
			_totalWeight = _totalWeight + (_weight * (_x select 1));
		};
	} forEach(_gear select _indexRuckMags);
	_totalWeight
};

// Fill in base blank-slot images to the UI
_fillInBlankImages =
{
	ctrlSetText [107, "\ca\ui\data\ui_gear_gun_gs.paa"];
	ctrlSetText [108, "\ca\ui\data\ui_gear_sec_gs.paa"];
	
	for "_i" from 109 to 120 do
	{
		ctrlSetText [_i, "\ca\ui\data\ui_gear_mag_gs.paa"];
	};
	
	ctrlSetText [121, "\ca\ui\data\ui_gear_hgun_gs.paa"];
	
	for "_i" from 122 to 129 do
	{
		ctrlSetText [_i, "\ca\ui\data\ui_gear_hgunmag_gs.paa"];
	};
	
	for "_i" from 130 to 131 do
	{
		ctrlSetText [_i, "\ca\ui\data\ui_gear_eq_gs.paa"];
	};
	
	for "_i" from 134 to 145 do
	{
		ctrlSetText [_i, "\ca\ui\data\ui_gear_eq_gs.paa"];
	};
	
	ctrlSetText [90020, "\ca\ui\data\ui_gear_gun_gs.paa"];
	ctrlSetText [90104, "\x\ace\addons\sys_wounds\data\equip\m_morphine_ca.paa"];
	ctrlSetText [90105, "\x\ace\addons\sys_wounds\data\equip\m_bandage_ca.paa"];
	ctrlSetText [90106, "\x\ace\addons\sys_wounds\data\equip\m_epi_ca.paa"];
};

// Takes a gear array and renders it to the UI
// Returns an array of 2 arrays.  The 2 arrays returned are of the format of
// _currentWeaponUIState and _currentMagazineUIState respectively.  See top of file
// for details.
_renderGear = 
{
	private ["_gear","_get","_pic","_itemIndex","_specialIndex","_mainMagIndex","_sideMagIndex","_ifakCount","_item","_isIFAK","_wob",
		"_weight","_weaponUIState", "_magazineUIState","_magazineSpace"];
	_gear = _this;
	
	call _fillInBlankImages;
	
	_specialIndex = 0;
	_mainMagIndex = 0;
	_sideMagIndex = 0;
	_itemIndex = 0;
	_ifakCount = [ 0, 0, 0 ];
	_isIFAK = false;
	_weaponUIState = [];
	_magazineUIState = [];
	
	{
		_get = [_x, true] call _getItemDataByConfigType;
		if (!isNil "_get") then
		{
			_pic = _get select QUERYGEARPICTURE;
			if((_get select QUERYGEARTYPE) == "Item" && _itemIndex < 12) then
			{
				ctrlSetText [134+_itemIndex, _pic];
				_weaponUIState = _weaponUIState + [ [134+_itemIndex, _forEachIndex] ];
				_itemIndex = _itemIndex + 1;
			}
			else
			{
				if (_x == (_gear select _indexPrimary)) then
				{
					ctrlSetText [107, _pic];
					_weaponUIState = _weaponUIState + [ [107, _forEachIndex] ];
				}
				else
				{
					if(_x == (_gear select _indexSecondary)) then
					{
						_weaponUIState = _weaponUIState + [ [108, _forEachIndex] ];
						ctrlSetText [108, _pic];
					}
					else
					{
						if(_x == (_gear select _indexSidearm)) then
						{
							_weaponUIState = _weaponUIState + [ [121, _forEachIndex] ];
							ctrlSetText [121, _pic];
						}
						else
						{
							ctrlSetText [130+_specialIndex, _pic];
							_weaponUIState = _weaponUIState + [ [130+_specialIndex, _forEachIndex] ];
							_specialIndex = _specialIndex + 1;
						};
					};
				};
			};
		};
	} forEach(_gear select _indexWeapons);
	
	{
		_get = [_x, false] call _getItemDataByConfigType;
		if (!isNil "_get") then
		{
			_item = _x;
			_isIFAK = false;
			{
				if(_x == _item &&
					(_ifakCount select _forEachIndex) < 2) exitWith
				{
					_ifakCount set [_forEachIndex, (_ifakCount select _forEachIndex) + 1];
					_isIFAK = true;
				};
			} forEach(_typesIFAK);
			
			if(!_isIFAK) then
			{
				_pic = _get select QUERYGEARPICTURE;
				_magazineSpace = _get select QUERYGEARSPACE;
				if(_magazineSpace < 1) then
				{
					_magazineSpace = 1;
				};
				if(!(_get select QUERYGEARHANDGUNPOOL)) then
				{
					if((_mainMagIndex + _magazineSpace) <= 12) then
					{
						ctrlSetText [109+_mainMagIndex, _pic];
						_magazineUIState = _magazineUIState + [ [109+_mainMagIndex, _forEachIndex] ];
						_mainMagIndex = _mainMagIndex + 1;
						
						_magazineSpace = _magazineSpace - 1;
						while { _magazineSpace > 0 } do
						{
							ctrlSetText [109+_mainMagIndex, ""];
							_magazineSpace = _magazineSpace - 1;
							_mainMagIndex = _mainMagIndex + 1;
						};
					};
				}
				else
				{
					if((_sideMagIndex + _magazineSpace) <= 8) then
					{
						ctrlSetText [122+_sideMagIndex, _pic];
						_magazineUIState = _magazineUIState + [ [122+_sideMagIndex, _forEachIndex] ];
						_sideMagIndex = _sideMagIndex + 1;
						
						_magazineSpace = _magazineSpace - 1;
						while { _magazineSpace > 0 } do
						{
							ctrlSetText [122+_sideMagIndex, ""];
							_magazineSpace = _magazineSpace - 1;
							_sideMagIndex = _sideMagIndex + 1;
						};
					};
				};
			};
		};
	} forEach(_gear select _indexMagazines);
	
	{
		ctrlSetText [90107 + _forEachIndex, str _x];
	} forEach(_ifakCount);
	
	_wob = _gear select _indexOnBack;
	
	if(!isNil "_wob" && _wob != '') then
	{
		_get = [_wob, true] call _getItemDataByConfigType;
		ctrlSetText [90020, _get select QUERYGEARPICTURE];
	};
	
	_weight = _gear call _getGearWeight;
	ctrlSetText [90009, format ["%1 kg", _weight]];
	
	[ _weaponUIState, _magazineUIState ]
};

// Given a gear array, get the number of "special" items (binocs, rangefinder, etc.) in it.
// arg0: gear array
// arg1: type of item e.g. "Special"
// returns: number of that type contained in gear array.
_getItemCountByType =
{
	private [ "_gear", "_count", "_get", "_itemType", "_countThisOne" ];
	
	_gear = _this select 0;
	_itemType = _this select 1;
	
	_count =
	{
		_countThisOne = false;
		_get = [ _x, true ] call _getItemDataByConfigType;
		if (!isNil "_get" && (_get select QUERYGEARTYPE) == _itemType) then
		{
			_countThisOne = true;
		}
		else
		{
			_countThisOne = false;
		};
		_countThisOne
	} count (_gear select _indexWeapons);
	_count
};

_renderRuckContents =
{
	private [ "_gear", "_get", "_i", "_u", "_capacity", "_volume" ];
	_gear = _this;
	
	lnbClear 3701;
	_i = 0;
	_u = 0;
	_volume = 0;
	{
		_get = [ _x select 0, true ] call _getItemDataByConfigType;
		if (!isNil "_get") then
		{
			lnbAddRow [3701,[str (_x select 1) + "x",(_get select QUERYGEARLABEL)]];
			lnbSetPicture [3701,[_i,0],_get select QUERYGEARPICTURE];
			lnbSetData [3701,[_i,0],"CfgWeapons"];
			lnbSetValue [3701,[_i,0],_u];
			_i = _i + 1;
			_u = _u + 1;
			_volume = _volume + getNumber(configFile >> "CfgWeapons" >> (_x select 0) >> "ACE_size") * (_x select 1);
		};
	} forEach(_gear select _indexRuckWeapons);
	
	_u = 0;
	{
		_get = [ _x select 0, false ] call _getItemDataByConfigType;
		if (!isNil "_get") then
		{
			lnbAddRow [3701,[str (_x select 1) + "x",(_get select QUERYGEARLABEL)]];
			lnbSetPicture [3701,[_i,0],_get select QUERYGEARPICTURE];
			lnbSetData [3701,[_i,0],"CfgMagazines"];
			lnbSetValue [3701,[_i,0],_u];
			_i = _i + 1;
			_u = _u + 1;
			_volume = _volume + getNumber(configFile >> "CfgMagazines" >> (_x select 0) >> "ACE_size") * (_x select 1);
		};
	} forEach(_gear select _indexRuckMags);
	
	_capacity = getNumber(configFile >> "CfgWeapons" >> (_gear call _getGearRuck) >> "ACE_PackSize");
	ctrlSetText [90000, format [localize "STR_WF_Ruck_Space_Free", _capacity - _volume]];
};

// arg0: gear array
// arg1: true if we are looking at handgun magazines
// returns number of magazines slots consumed (taking magazine size into account)
// in handgun pool or main pool (according to arg1)
_getMagazineCountByPool =
{
	private [ "_gear", "_get", "_handgunpool", "_count", "_isIFAK", "_ifakCount", "_item" ];
	
	_gear = _this select 0;
	_handgunpool = _this select 1;
	_count = 0;
	_ifakCount = [ 0, 0, 0 ];
	
	{
		_isIFAK = false;
		_item = _x;
		{
			if(_x == _item &&
				(_ifakCount select _forEachIndex) < 2) exitWith
			{
				_ifakCount set [_forEachIndex, (_ifakCount select _forEachIndex) + 1];
				_isIFAK = true;
			};
		} forEach(_typesIFAK);
		
		if (!_isIFAK) then
		{
			_get = [_item, false] call _getItemDataByConfigType;
			if((_handgunpool && (_get select QUERYGEARHANDGUNPOOL)) ||
				(!_handgunpool && !(_get select QUERYGEARHANDGUNPOOL))) then
			{
				if((_get select QUERYGEARSPACE) == 0) then
				{
					_count = _count + 1;
				}
				else
				{
					_count = _count + (_get select QUERYGEARSPACE);
				};
			};
		};
	} forEach(_gear select _indexMagazines);
	_count
};

// arg0: gear array
// arg1: magazine to add
// arg2: (optional) item data on the magazine we are adding.
// Will only succeed if the magazine fits.
_addMagazineToGear =
{
	private [ "_gear", "_magazine", "_get", "_magCount", "_magLimit", "_magSize", "_oldMagazines" ];
	
	_gear = _this select 0;
	_magazine = _this select 1;
	
	if ((count _this) >= 3) then
	{
		_get = _this select 2;
	}
	else
	{
		_get = [_magazine, false] call _getItemDataByConfigType;
	};
	
	// Add magazines to a temporary copy of the gear array, and see if it's too much.
	// This handles the IFAK stuff (infantry first aid kit) for us.
	_oldMagazines = _gear select _indexMagazines;
	_gear set [_indexMagazines,
			_oldMagazines + [ _magazine ] ];
	_magCount = [ _gear, _get select QUERYGEARHANDGUNPOOL] call _getMagazineCountByPool;
	_magLimit = if(_get select QUERYGEARHANDGUNPOOL) then { 8 } else { 12 };
	
	// DEBUG
	diag_log format ["WFBE (AceGear): magCount: %1 magLimit: %2 mag: ", _magCount, _magLimit, _magazine ];
	
	if(_magCount > _magLimit) then
	{
		// Doesn't fit; revert back
		_gear set [ _indexMagazines, _oldMagazines ];
	};
};

// arg0: unit
// arg1: gear array
// equip that gear to the unit.
_applyGearToUnit =
{
	private ["_gear","_unit","_muzzles"];
	
	_unit = _this select 0;
	_gear = _this select 1;
	
	removeAllWeapons _unit;
	removeAllItems _unit;
	removeBackpack _unit;
	{_unit addMagazine _x} foreach (_gear select _indexMagazines);
	{_unit addWeapon _x} foreach (_gear select _indexWeapons);
	if (primaryWeapon _unit != "") then 
	{
		_unit selectWeapon (primaryWeapon _unit);
		_muzzles = getArray(configFile>>"cfgWeapons" >> primaryWeapon _unit >> "muzzles");
		_unit selectWeapon (_muzzles select 0);
	};
	
	_safeArray = _gear select _indexRuckMags;
	_unit setVariable ["ACE_RuckMagContents", +_safeArray];
	_safeArray = _gear select _indexRuckWeapons;
	_unit setVariable ["ACE_RuckWepContents", +_safeArray];
	
	if((_gear select _indexOnBack) != "") then
	{
		_unit setVariable ["ACE_weapononback", _gear select _indexOnBack];
	}
	else
	{
		_unit setVariable ["ACE_weapononback", ""];
	};
};

// arg: gear array
// returns: rucksack in gear or ""
_getGearRuck =
{
	private ["_gear","_maybeRuck"];
	
	_gear = _this;
	_maybeRuck = _gear select _indexSecondary;
	if(!isNumber(configFile >> "CfgWeapons" >> _maybeRuck >> "ACE_PackSize")) then
	{
		_maybeRuck = _gear select _indexOnBack;
		if(isClass(configFile >> "CfgWeapons" >> _maybeRuck)) then
		{
			if(!isNumber(configFile >> "CfgWeapons" >> _maybeRuck >> "ACE_PackSize")) then
			{
				_maybeRuck = "";
			};
		}
		else
		{
			_maybeRuck = "";
		};
	};
	_maybeRuck
};

// arg 0: item
// arg 1: config type (CfgWeapons, etc.)
// arg 2: gear array
_addItemToRuck =
{
	private [ "_item", "_gear", "_configType", "_ruck", "_capacity", "_size", "_added", "_packable" ];
	
	_item = _this select 0;
	_configType = _this select 1;
	_gear = _this select 2;
	_packable = true;
	
	if(getNumber(configFile >> _configType >> _item >> "ACE_NoPack") == 1 ||
		getNumber(configFile >> _configType >> _item >> "ACE_disposable") == 1) then
	{
		_packable = false;
	};
	
	_ruck = _gear call _getGearRuck;
	_capacity = 0;
	if(_ruck != "") then
	{
		_capacity = getNumber(configFile >> "CfgWeapons" >> _ruck >> "ACE_PackSize");
	};
	_size = getNumber(configFile >> _configType >> _item >> "ACE_size");
	_size = _size + (_gear call _getRuckItemsVolume);
	if(_packable && _size <= _capacity) then
	{
		if(_configType == "CfgWeapons") then
		{
			_added = false;
			{
				if((_x select 0) == _item) exitWith
				{
					_added = true;
					_x set [1, (_x select 1) + 1];
				};
			} forEach(_gear select _indexRuckWeapons);
			if(!_added) then
			{
				_gear set [_indexRuckWeapons,
					(_gear select _indexRuckWeapons) +
					[ [ _item, 1 ] ] ];
			};
		}
		else
		{
			_added = false;
			{
				if((_x select 0) == _item) exitWith
				{
					_added = true;
					_x set [1, (_x select 1) + 1];
				};
			} forEach(_gear select _indexRuckMags);
			if(!_added) then
			{
				_gear set [_indexRuckMags,
					(_gear select _indexRuckMags) +
					[ [ _item, 1 ] ] ];
			};
		};
	};
};

_currentUnit = 0;
{
	if(isPlayer _x) exitWith
	{
		_currentUnit = _forEachIndex;
	};
} forEach(units group player);

_currentGear = [player] call _inventoryToGear;
_initialCost = _currentGear call _getGearCost;
_updateGear = true;
_updateMainList = true;
_updateSecondaryList = true;
_updateUnit = true;
_backpackSelected = false;
_selectedWeapon = '';
_currentMagazineUIState = [];
_currentWeaponUIState = [];
_currentFilter = 0;
_updateCosts = true;

_defaultWeap = Format ["WFBE_%1DEFAULTWEAPONS",sideJoinedText] Call GetNamespace;
_defaultAmmo = Format ["WFBE_%1DEFAULTAMMO",sideJoinedText] Call GetNamespace;

if (paramAceWounds) then
{
	_defaultAmmo = _defaultAmmo + [ 'ACE_Morphine', 'ACE_Morphine', 'ACE_Bandage', 'ACE_Bandage' ];
	if(getNumber(configFile >> "CfgVehicles" >> (typeOf player) >> "attendant") == 1) then
	{
		_defaultAmmo = _defaultAmmo + [ 'ACE_Epinephrine', 'ACE_Epinephrine', 'ACE_Medkit', 'ACE_Medkit' ];
	};
};

_defaultLoadoutCost = [ _defaultWeap, _defaultAmmo, "", [], [], "", "", "" ] call _getGearCost;

WF_Logic setVariable ['InventoryClick',-1];
WF_Logic setVariable ['lbMainAction',''];
WF_Logic setVariable ['lbChange',false];
WF_Logic setVariable ['WF_Gear_Action',""];

call _fillInBlankImages;

// And now the main UI loop.
while {alive player && dialog} do {
	_lbSelChanged = WF_Logic getVariable 'lbChange';
	_mainCommand = WF_Logic getVariable 'lbMainAction';
	_inventoryClick = WF_Logic getVariable 'InventoryClick';
	_gearAction = WF_Logic getVariable 'WF_Gear_Action';
	
	if (_lbSelChanged) then
	{
		WF_Logic setVariable ['lbChange',false];
		_weaponList = call compile format ["_%1%2", _filterNames select _currentFilter,
			if(_backpackSelected) then { "Backpack" } else { "" }];
		_selectedWeapon = _weaponList select lnbValue [3700, [lnbCurSelRow 3700, 0]];
		_get = [_selectedWeapon, _filterNames select _currentFilter] call _getItemDataByFilterType;
		_configType = _get select QUERYGEARCLASS;
		
		if(!_backpackSelected) then
		{
			_weight = getNumber(configFile >> _configType >> _selectedWeapon >> "ACE_weight");
			ctrlSetText [ 90005, format [ "%1 kg", _weight ]];
			_updateSecondaryList = true;
		};
	};
	
	if (_inventoryClick != -1) then
	{
		WF_Logic setVariable ['InventoryClick',-1];
		if(_inventoryClick == 90020) then
		{
			_currentGear set [_indexOnBack, ""];
			_updateGear = true;
		}
		else
		{
			{
				if(_inventoryClick == (_x select 0)) exitWith
				{
					_weapon = (_currentGear select _indexWeapons) select (_x select 1);
					
					if (_weapon == (_currentGear select _indexPrimary)) then
					{
						_currentGear set [_indexPrimary, ""];
					};
					if (_weapon == (_currentGear select _indexSecondary)) then
					{
						_currentGear set [_indexSecondary, ""];
					};
					if (_weapon == (_currentGear select _indexSidearm)) then
					{
						_currentGear set [_indexSidearm, ""];
					};
					if (_weapon == (_currentGear select _indexOnBack)) then
					{
						_currentGear set [_indexOnBack, ""];
					};
					
					(_currentGear select _indexWeapons) set [_x select 1, 0];
					_currentGear set [_indexWeapons,
						(_currentGear select _indexWeapons) - [ 0 ]];
				};
			} forEach(_currentWeaponUIState);
		};
		
		{
			if(_inventoryClick == (_x select 0)) exitWith
			{
				(_currentGear select _indexMagazines) set [_x select 1, 0];
				_currentGear set [_indexMagazines,
					(_currentGear select _indexMagazines) - [ 0 ]];
			};
		} forEach(_currentMagazineUIState);
		
		// If ruck was removed, remove contents too.
		if ((_currentGear call _getGearRuck) == "") then
		{
			_currentGear set [_indexRuckWeapons, []];
			_currentGear set [_indexRuckMags, []];
			if(_backpackSelected) then
			{
				_backpackSelected = false;
				_updateSecondaryList = true;
			};
		};
		_updateGear = true;
	};
	
	if (_mainCommand != '') then
	{
		WF_Logic setVariable ['lbMainAction',''];
		_weaponList = call compile format ["_%1%2", _filterNames select _currentFilter,
			if(_backpackSelected) then { "Backpack" } else { "" }];
		if (_selectedWeapon != '') then
		{
			_magazineList = _selectedWeapon call _getCompatibleMagazines;	
		}
		else
		{
			_magazineList = [];
		};
		
		switch (_mainCommand) do
		{
			case 'unitPlus': {
				_currentUnit = _currentUnit + 1;
				if(_currentUnit >= (count units group player)) then
				{
					_currentUnit = 0;
				};
				_updateUnit = true;
			};
			
			case 'unitMinus': {
				_currentUnit = _currentUnit - 1;
				if(_currentUnit < 0) then
				{
					_currentUnit = (count units group player) - 1;
				};
				_updateUnit = true;
			};
			
			case 'filterPlus': {
				_currentFilter = _currentFilter + 1;
				if(_currentFilter >= 5) then
				{
					_currentFilter = 0;
				};
				ctrlSetText [148, format ["\ca\ui\data\igui_gear_filter_%1_ca.paa",
					_currentFilter+1]];
				_updateMainList = true;
			};
			
			case 'filterMinus': {
				_currentFilter = _currentFilter - 1;
				if(_currentFilter < 0) then
				{
					_currentFilter = 4;
				};
				ctrlSetText [148, format ["\ca\ui\data\igui_gear_filter_%1_ca.paa",
					_currentFilter+1]];
				_updateMainList = true;
			};
			
			case 'buy': {
				_funds = call GetPlayerFunds;
				_cost = (_currentGear call _getGearCost) - _initialCost;
				if(_funds >= _cost) then
				{
					(-_cost) Call ChangePlayerFunds;
					_unit = (units group player) select _currentUnit;
					if(isNil "_unit" || !alive _unit) then
					{
						_currentUnit = 0;
						_updateUnit = true;
					}
					else
					{
						[ _unit, _currentGear] call _applyGearToUnit;
						if (isPlayer _unit) then
						{
							respawnGearCost = _respawnCost;
							respawnWeapons = _currentGear select _indexWeapons;
							respawnAmmo = _currentGear select _indexMagazines;
							respawnWeaponOnBack = _currentGear select _indexOnBack;
							respawnAceRuckContents = [ _currentGear select _indexRuckWeapons,
								_currentGear select _indexRuckMags ];
						};
						_initialCost = (_currentGear call _getGearCost);
						_updateGear = true;
					};
				}
				else
				{
					hint parseText(Format [localize "STR_WF_Funds_Missing_Gear",_cost - _funds]);
				};
			};
			
			case 'addMagazine': {
				if(!_backpackSelected) then 
				{
					_mag = _magazineList select lnbValue [3701, [lnbCurSelRow 3701, 0]];
					[ _currentGear, _mag ] call _addMagazineToGear;
					_updateGear = true;
				}
				else
				{
					// A double click in ruck mode actually means remove from inventory.
					_ruckIndex = lnbValue [3701, [lnbCurSelRow 3701, 0]];
					_ruckItemClass = lnbData [3701, [lnbCurSelRow 3701, 0]];
					
					if(_ruckItemClass == "CfgWeapons") then
					{
						_ruckItem = (_currentGear select _indexRuckWeapons) select _ruckIndex;
						if((_ruckItem select 1) > 1) then
						{
							_ruckItem set [1, (_ruckItem select 1) - 1];
						}
						else
						{
							(_currentGear select _indexRuckWeapons) set [_ruckIndex, 0];
							_currentGear set [_indexRuckWeapons,
								(_currentGear select _indexRuckWeapons) - [ 0 ]];
						};
					}
					else
					{
						_ruckItem = (_currentGear select _indexRuckMags) select _ruckIndex;
						if((_ruckItem select 1) > 1) then
						{
							_ruckItem set [1, (_ruckItem select 1) - 1];
						}
						else
						{
							(_currentGear select _indexRuckMags) set [_ruckIndex, 0];
							_currentGear set [_indexRuckMags,
								(_currentGear select _indexRuckMags) - [ 0 ]];
						};
					};
					_updateSecondaryList = true;
					_updateCosts = true;
				};
			};
			
			case 'addMainItem': {
				_weapon = _weaponList select lnbValue [3700, [lnbCurSelRow 3700, 0]];
				_get = [_weapon, _filterNames select _currentFilter] call _getItemDataByFilterType;
				
				if ((_get select QUERYGEARCLASS) == "CfgMagazines") then
				{
					if(_backpackSelected) then
					{
						[_weapon, "CfgMagazines", _currentGear] call _addItemToRuck;
						_updateSecondaryList = true;
						_updateCosts = true;
					}
					else
					{
						[_currentGear, _weapon, _get] call _addMagazineToGear;
						_updateGear = true;
					};
				}
				else
				{
					if(_backpackSelected) then
					{
						[_weapon, "CfgWeapons", _currentGear] call _addItemToRuck;
						_updateSecondaryList = true;
						_updateCosts = true;
					}
					else
					{
						_add = false;
						if (_weapon in _primary) then
						{
							if ((_currentGear select _indexPrimary) != '') then
							{
								_currentGear set [ _indexWeapons,
									(_currentGear select _indexWeapons) - [ _currentGear select _indexPrimary ] ];
							};
							_currentGear set [_indexPrimary, _weapon];
							_add = true;
						}
						else
						{
							if (_weapon in _secondary) then
							{
								if ((_currentGear select _indexSecondary) != '') then
								{
									_currentGear set [ _indexWeapons,
										(_currentGear select _indexWeapons) - [ _currentGear select _indexSecondary ] ];
								};
								_currentGear set [_indexSecondary, _weapon];
								_add = true;
							}
							else
							{
								if (_weapon in _sidearm) then
								{
									if ((_currentGear select _indexSidearm) != '') then
									{
										_currentGear set [ _indexWeapons,
											(_currentGear select _indexWeapons) - [ _currentGear select _indexSidearm ] ];
									};
									_currentGear set [_indexSidearm, _weapon];
									_add = true;
								}
								else
								{
									if ((_get select QUERYGEARTYPE) == "Special") then
									{
										_itemCount = [_currentGear, "Special"] call _getItemCountByType;
										if(_itemCount < 2) then
										{
											_add = true;
										};
									};
									
									if((_get select QUERYGEARTYPE) == "Item") then
									{
										_itemCount = [_currentGear, "Item"] call _getItemCountByType;
										if(_itemCount < 12) then
										{
											_add = true;
										};
									};
								};
							};
						};
						
						if(_add) then
						{
							_currentGear set [ _indexWeapons,
								(_currentGear select _indexWeapons) + [ _weapon ]];
							_updateGear = true;
						};
					};
				};
			};
		};
	};
	
	if(_gearAction != "") then
	{
		WF_Logic setVariable ["WF_Gear_Action",""];
		switch(_gearAction) do
		{
			case 'backpack': {
				if(_backpackSelected) then
				{
					_backpackSelected = false;
					_updateSecondaryList = true;
					_updateMainList = true;
				}
				else
				{
					if((_currentGear call _getGearRuck) != "") then
					{
						_backpackSelected = true;
						_updateSecondaryList = true;
						_updateMainList = true;
					};
				};
			};
			
			case 'reload': {
				if(!isNil "respawnWeapons") then
				{
					_currentGear set [_indexWeapons, respawnWeapons];
					_currentGear set [_indexMagazines, respawnAmmo];
					_currentGear set [_indexOnBack, respawnWeaponOnBack];
					_currentGear set [_indexRuckWeapons, respawnAceRuckContents select 0];
					_currentGear set [_indexRuckMags, respawnAceRuckContents select 1];
				}
				else
				{
					_currentGear set [_indexWeapons, Format ["WFBE_%1DEFAULTWEAPONS",sideJoinedText] Call GetNamespace];
					_currentGear set [_indexMagazines, Format ["WFBE_%1DEFAULTAMMO",sideJoinedText] Call GetNamespace];
					_currentGear set [_indexOnBack, ""];
					_currentGear set [_indexRuckWeapons, []];
					_currentGear set [_indexRuckMags, []];
				};
				
				{
					if(_x in _primary) then
					{
						_currentGear set [_indexPrimary, _x];
					};
					
					if(_x in _secondary) then
					{
						_currentGear set [_indexSecondary, _x];
					};
					
					if(_x in _sidearm) then
					{
						_currentGear set [_indexSidearm, _x];
					};
				} forEach(_currentGear select _indexWeapons);
				
				_updateGear = true;
			};
			
			case 'clear': {
				_currentGear = [ [], [], "", [], [], "", "", "" ];
				_updateGear = true;
			};
			
			case 'primary_onback': {
				if ((_currentGear select _indexPrimary) != '') then
				{
					_weapon = _currentGear select _indexPrimary;
					_currentGear set [ _indexWeapons,
						(_currentGear select _indexWeapons) - [ _currentGear select _indexPrimary ] ];
					_currentGear set [_indexPrimary, ""];
					_currentGear set [_indexOnBack, _weapon];
					_updateGear = true;
				};
			};
			
			case 'secondary_onback': {
				if ((_currentGear select _indexSecondary) != '') then
				{
					_weapon = _currentGear select _indexSecondary;
					_currentGear set [ _indexWeapons,
						(_currentGear select _indexWeapons) - [ _currentGear select _indexSecondary ] ];
					_currentGear set [_indexSecondary, ""];
					_currentGear set [_indexOnBack, _weapon];
					_updateGear = true;
				};
			};
		};
	};
	
	if (_updateUnit) then
	{
		_unit = (units group player) select _currentUnit;
		_backpackSelected = false;
		_currentGear = [_unit] call _inventoryToGear;
		_updateGear = true;
		_updateMainList = true;
		_updateSecondaryList = true;
		ctrlSetText [101, format ["[%1] " + name _unit, _currentUnit]];
		_initialCost = _currentGear call _getGearCost;
		_updateUnit = false;
	};
	
	if (_updateGear) then
	{
		_temp = _currentGear call _renderGear;
		_currentWeaponUIState = _temp select 0;
		_currentMagazineUIState = _temp select 1;
		_updateGear = false;
		_updateCosts = true;
	};
	
	if(_updateCosts) then 
	{
		_updateCosts = false;
		_cost = _currentGear call _getGearCost;
		ctrlSetText [152, format [localize "STR_WF_Cost", _cost - _initialCost]];
		ctrlSetText [150, format [localize "STR_WF_Cash", call GetPlayerFunds]];
		
		_respawnCost = _cost - _defaultLoadoutCost;
		if(_respawnCost < 0) then
		{
			_respawnCost = 0;
		};
		
		_respawnPenalty = 'WFBE_RESPAWNPENALTY' Call GetNamespace;
	
		if (isPlayer (units group player select _currentUnit) && _respawnPenalty in [2,3,4,5]) then 
		{
			_divisor = 1;
			switch (_respawnPenalty) do 
			{
				case 3: {_divisor = 2};
				case 4: {_divisor = 4};
			};
			ctrlSetText [151, format [localize "STR_WF_Respawn_Cost", round (_respawnCost / _divisor) ]];
		}
		else
		{
			ctrlSetText [151, ""];
		};
	};
	
	if(_updateMainList) then
	{
		lnbClear 3700;
		_weaponList = call compile format ["_%1%2", _filterNames select _currentFilter,
			if(_backpackSelected) then { "Backpack" } else { "" }];
		[_weaponList, _filterNames select _currentFilter, 3700] call UIGearFillList;
		_updateMainList = false;
		_selectedWeapon = "";
		_updateSecondaryList = true;
	};
	
	if(_updateSecondaryList) then
	{	
		lnbClear 3701;
		if (_backpackSelected) then
		{
			_currentGear call _renderRuckContents;
			ctrlSetText [90009, format ["%1 kg", _currentGear call _getGearWeight]];
		}
		else
		{
			ctrlSetText [90000,localize "STR_WF_Magazines"];
			ctrlSetText [90005, ""];
			ctrlSetText [90007, ""];
			if (_selectedWeapon != '') then
			{
				_magazineList = _selectedWeapon call _getCompatibleMagazines;
				[_magazineList, "magazine", 3701] call UIGearFillList;
			};
		};
		_updateSecondaryList = false;
	};
	sleep 0.05;
};

WF_Logic setVariable ['InventoryClick',nil];
WF_Logic setVariable ['lbMainAction',nil];
WF_Logic setVariable ['lbChange',nil];
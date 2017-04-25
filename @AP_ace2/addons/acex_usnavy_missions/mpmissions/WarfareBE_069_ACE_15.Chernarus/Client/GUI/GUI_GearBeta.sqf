/* Important, use +array if you plan to use Setters */


private ["_backpack","_get","_u","_unitBP","_inRange","_sideID","_nObjects","_nObject","_unitList",
"_text","_amount","_val","_val2","_ainumber","_txt","_type","_check","_updateFiller","_manageBackpack",
"_list","_id","_changed","_currentMags","_currentRow","_currentData","_currentValue","_currentItem",
"_skip","_backpackloadout","_bpcost","_get2","_oldMags","_currentMagazines","_slist","_index",
"_currentWeapons","_displayInv","_arrayType","_arrayAmount","_currentBPRow","_currentBPValue",
"_currentBPItem","_hasSpace","_updateBackpack","_zt","_currentSpecialCost","_currentSpecials",
"_currentItems","_currentUpgrades","_getnum","_currentPrimary","_currentPrimaryCost","_currentSecondary",
"_currentSecondaryCost","_currentSidearm","_currentSidearmCost","_cwep","_x","_tempWeapons",
"_tempItems","_tempMags","_tempSpecs","_currentBackpackLoadout","_currentBackpackLoadoutAmount",
"_tfil","_currentMagValue","_currentMag","_currentBPItemValue","_itemAmount","_currentUnit","_updateUnit",
"_currentCost","_sideGear","_found","_show","_data","_inventorySlots","_sidearmInventorySlots",
"_miscItemSlots","_cost","_slot","_upgradeCost","_currentBackpackLoadoutCost","_currentBackpackLoadoutPictures",
"_currentBackpackLoadoutNames","_currentBackpackLoadoutUpgrades","_currentBackpackLoadoutAllowed",
"_temp","_weaps","_add","_funds","_template","_templateCosts","_templatePictures","_templateNames",
"_templateMags","_templateItems","_templateSpecs","_templateUpgrades","_templateAllowed","_cAllow",
"_desc","_pict","_upgr","_addin","_filler","_mainAction","_inventoryClick","_unitSwap","_actionSE",
"_lastFiller","_primary","_secondary","_sidearm","_misc","_magazine","_returnProperBag","_listbp",
"_all","_lb","_lbm","_primaryIDC","_secondaryIDC","_sidearmIDC","_specialIDC","_display","_totalWeapons",
"_fillerIDC","_fillerTypes","_old","_disp","_buildings","_getpp","_isPrimAllowTwo","_getss","_isSecoAllowTwo",
"_sskip","_query","_pallow","_sallow","_secondarySlotIDC"];

_primary = +(WF_Logic getVariable 'primaryClasses');
_secondary = +(WF_Logic getVariable 'secondaryClasses');
_sidearm = +(WF_Logic getVariable 'sidearmClasses');
_misc = +(WF_Logic getVariable 'miscClasses');
_magazine = +(WF_Logic getVariable 'magazineClasses');

_template = +(WF_Logic getVariable 'templateClasses');
_templateCosts = +(WF_Logic getVariable 'templateCosts');
_templatePictures = +(WF_Logic getVariable 'templatePictures');
_templateNames = +(WF_Logic getVariable 'templateNames');	
_templateMags = +(WF_Logic getVariable 'templateMags');
_templateItems = +(WF_Logic getVariable 'templateItems');
_templateSpecs = +(WF_Logic getVariable 'templateSpecs');
_templateUpgrades = +(WF_Logic getVariable 'templateUpgrades');
_templateAllowed = +(WF_Logic getVariable 'templateAllowed');

_currentUnit = player;
_secondarySlotIDC = 3501;

_returnProperBag = {
	Private ['_bag'];
	_bag = _this select 0;
	
	if (_bag in ['US_Assault_Pack_Ammo_EP1','US_Assault_Pack_AmmoSAW_EP1','US_Assault_Pack_AT_EP1','US_Assault_Pack_Explosives_EP1']) then {_bag = 'US_Assault_Pack_EP1'};
	if (_bag in ['US_Patrol_Pack_Ammo_EP1','US_Patrol_Pack_Specops_EP1']) then {_bag = 'US_Patrol_Pack_EP1'};
	if (_bag in ['US_Backpack_AmmoMG_EP1','US_Backpack_AT_EP1','US_Backpack_Specops_EP1']) then {_bag = 'US_Backpack_EP1'};
	if (_bag in ['TK_ALICE_Pack_Explosives_EP1','TK_ALICE_Pack_AmmoMG_EP1','TKA_ALICE_Pack_Ammo_EP1','TKG_ALICE_Pack_AmmoAK47_EP1','TKG_ALICE_Pack_AmmoAK74_EP1']) then {_bag = 'TK_ALICE_Pack_EP1'};
	if (_bag in ['TK_Assault_Pack_RPK_EP1','TKA_Assault_Pack_Ammo_EP1']) then {_bag = 'TK_Assault_Pack_EP1'};
	if (paramDLCBAF) then {if (_bag in ['BAF_AssaultPack_ARAmmo','BAF_AssaultPack_MGAmmo','BAF_AssaultPack_ATAmmo','BAF_AssaultPack_HATAmmo','BAF_AssaultPack_Special','BAF_AssaultPack_FAC','BAF_AssaultPack_HAAAmmo','BAF_AssaultPack_LRRAmmo']) then {_bag = 'BAF_AssaultPack_RifleAmmo'}};
	
	_bag
};

/* Backpack management - Init */
_backpackloadout = [];
_backpack = [];

_currentBackpackLoadout = [];
_currentBackpackLoadoutAmount = [];
_currentBackpackLoadoutCost = [];
_currentBackpackLoadoutPictures = [];
_currentBackpackLoadoutNames = [];
_currentBackpackLoadoutUpgrades = [];
_currentBackpackLoadoutAllowed = [];
_unitBP = "";
_bpcost = 0;
_listbp = 'WFBE_BACKPACKS' Call GetNamespace;
if !(WF_A2_Vanilla) then {
	_u = 0;
	_backpack = _magazine;
	{
		_get = '_x' Call GetNamespace;
		if ((_get select QUERYGEARTYPE) == 'CfgMagazines') then {
			_backpack = _backpack + [_x];
		};
		_u = _u + 1;
	} forEach _misc;
	
	if !(isNull (unitBackpack _currentUnit)) then {
		_unitBP = typeOf (unitBackpack _currentUnit);
		_unitBP = [_unitBP] Call _returnProperBag;
	};
};

_all = _primary + _secondary + _sidearm + _misc;

WF_Logic setVariable ['lbChange',false];
WF_Logic setVariable ['lbMainAction',''];
WF_Logic setVariable ['InventoryClick',-1];
WF_Logic setVariable ['WF_GEAR_Swap',false];
WF_Logic setVariable ['WF_Gear_Action',''];

primClicked = false;
secoClicked = false;
sideClicked = false;
deleteLoadout = false;
saveLoadout = false;
buyLoadout = false;
_displayInv = false;
_updateUnit = true;
_updateFiller = false;
_manageBackpack = false;
_updateBackpack = false;

disableSerialization;
_lb = 3700;
_lbm = 3701;
_primaryIDC = 3500;
_secondaryIDC = 3501;
_sidearmIDC = 3502;
_specialIDC = 3535;
_display = _this select 0;

_totalWeapons = count _primary + count _secondary + count _sidearm;

_fillerIDC = [3400,3401,3402,3403,3404,3405];
_fillerTypes = ['template','all','primary','secondary','sidearm','misc'];
_inventorySlots = [];
_lastFiller = 'nil';
_id = _fillerTypes find 'primary';
_list = [];
_miscItemSlots = [];
_sidearmInventorySlots = [];
(_display DisplayCtrl (_fillerIDC select _id)) ctrlSetTextColor [0.7, 1, 0.7, 1];

_currentItem = '';
_currentMags = [];
_currentData = '';
_currentValue = '';
_currentCost = 0;
_cost = 0;

_currentPrimary = '';
_currentSecondary = '';
_currentSidearm = '';
_currentPrimaryCost = 0;
_currentSecondaryCost = 0;
_currentSidearmCost = 0;
_currentSpecialCost = 0;

_old = '';

_currentWeapons = [];
_currentSpecials = [];
_currentItems = [];
_currentMagazines = [];

_disp = (findDisplay 16000) displayAddEventHandler ['KeyDown','_this Call WF_Gear_Hotkeys'];

//--- Fill the available units list.
_unitList = [];
_buildings = (sideJoinedText) Call GetSideStructures;
_i = 0;
{
	_check = ['BARRACKSTYPE',_buildings,'WFBE_PURCHASEGEARRANGE' Call GetNamespace,sideJoined,_x] Call BuildingInRange;
	_inRange = if (isNull _check) then {false} else {true};
	
	if (!_inRange) then {
		_nObjects = nearestObjects [_x, WFCAMP, 25];
		_nObject = if (count _nObjects > 0) then {_nObjects select 0} else {objNull};
		if !(isNull _nObject) then {
			_sideID = _nObject getVariable "sideID";
			if !(isNil "_sideID") then {
				if (_sideID == sideID) then {_inRange = true};
			};
		};
	};
	
	if (_inRange) then {
		_txt = (_x) Call GetAIDigit;
		_unitList = _unitList + [_x];

		_type = [typeOf _x, 'displayName'] Call GetConfigInfo;
		lbAdd [3854,Format["[%1] %2 (%3)",_txt,name _x,_type]];
		
		if (_currentUnit == _x) then {lbSetCurSel[3854,_i]};
		_i = _i + 1;
	};
} forEach units(group player);

while {alive player && dialog} do {
	if (Side player != sideJoined) exitWith {closeDialog 0};
	if (!dialog) exitWith {};
	
	//--- Something changed since the last time?
	_filler = WF_Logic getVariable 'filler';
	_changed = WF_Logic getVariable 'lbChange';
	_mainAction = WF_Logic getVariable 'lbMainAction';
	_inventoryClick = WF_Logic getVariable 'InventoryClick';
	_unitSwap = WF_Logic getVariable 'WF_GEAR_Swap';
	_actionSE = WF_Logic getVariable 'WF_Gear_Action';

	//--- Filter Changed.
	if (_filler != _lastFiller || _updateFiller) then {
		_updateFiller = false;
		_manageBackpack = false;
		_list = Call Compile Format ['_%1',_filler];
		lnbClear _lb;
		if (_filler != 'template') then {
			[_list,_filler,_lb] Call UIGearFillList;
		} else {
			[_templateCosts,_templateNames,_templatePictures,_templateUpgrades,_templateAllowed,_filler,_lb] Call UIGearFillTemplateList;
		};
		_id = _fillerTypes find _filler;
		{(_display displayCtrl _x) ctrlSetTextColor [1, 1, 1, 1]} forEach _fillerIDC;
		(_display displayCtrl (_fillerIDC select _id)) ctrlSetTextColor [0.7, 1, 0.7, 1];
		//--- Update the list since the filler changed.
		_changed = true;
	};
	
	//--- List Selection Changed.
	if (_changed) then {
		if !(_manageBackpack) then {
			WF_Logic setVariable ['lbChange',false];
			_currentRow = lnbCurSelRow _lb;
			_currentData = lnbData[_lb,[_currentRow,0]];
			_currentValue = lnbValue[_lb,[_currentRow,0]];
			_currentItem = _list select _currentValue;
			lnbClear _lbm;
			_get = [];
			
			/* Get */
			if (_filler != 'template') then {
				if (_filler == 'secondary' || _filler == 'all') then {
					_get = (_currentItem+'_W') Call GetNamespace;
					if (isNil '_get') then {
						_get = _currentItem Call GetNamespace;
					};
				} else {
					_get = _currentItem Call GetNamespace;
				};

				if !(isNil '_get') then {
					_currentMags = _get select QUERYGEARMAGAZINES;
					if (typeName _currentMags != 'SCALAR') then {
						if (count _currentMags > 0) then {
							[_currentMags,'magazine',_lbm] Call UIGearFillList;
						};
					};
				};
			};
		};
		WF_Logic setVariable ['lbChange',false];
	};
	
	//--- Player have clicked on one of the listbox.
	if (_mainAction != '') then {
		switch (_mainAction) do {
			case 'addWeapon': {
				_skip = true;
				_sskip = false;
				_get = [];
				
				if (_filler != 'template') then {
					_get = (_currentItem+"_W") Call GetNamespace;
					if (isNil '_get') then {
						_get = _currentItem Call GetNamespace;
					};
				};
				
				
				_tfil = if (_manageBackpack) then {'backpack'} else {_filler};
				if (_tfil == 'primary' || _tfil == 'secondary' || _tfil == 'sidearm' || _tfil == 'all') then {
					if (_currentItem in _misc) then {_skip = false;_currentValue = _currentValue - _totalWeapons};
					if (_skip) then {
						_slist = Call Compile Format ['_%1',_currentData];
						_index = _slist find _currentItem;
						if (_index != -1) then {
							if (_filler == 'all') then {
								if (_currentItem in _primary) then {_currentData = 'primary'} else {
									if (_currentItem in _secondary) then {_currentData = 'secondary'} else {
										if (_currentItem in _sidearm) then {_currentData = 'sidearm'};
									};
								};
							};
							
							/* Handle the extended inventory system if disabled */
							_isSecoAllowTwo = true;
							_isPrimAllowTwo = true;
							if (paramExtendedInventory && (_tfil == 'primary' || _tfil == 'secondary' || _tfil == 'all')) then {
								_getpp = [];
								_getss = [];
								
								_query = if (_currentData == 'primary') then {_currentItem} else {_currentPrimary};
								if (_query != '') then {
									_getpp = (_query+"_W") Call GetNamespace;
									if (isNil '_getpp') then {
										_getpp = _query Call GetNamespace;
									};
								};
								if (_query != '') then {_isPrimAllowTwo = _getpp select QUERYGEARALLOWTWO};
								
								_query = if (_currentData == 'secondary') then {_currentItem} else {_currentSecondary};
								if (_query != '') then {
									_getss = (_query+"_W") Call GetNamespace;
									if (isNil '_getss') then {
										_getss = _query Call GetNamespace;
									};
								};
								if (_query != '') then {_isSecoAllowTwo = _getss select QUERYGEARALLOWTWO};

								if (!_isSecoAllowTwo && !_isPrimAllowTwo) then {
									_sskip = true;
									hint parseText (localize 'STR_WF_Gear_AllowTwo');
								};
							};
							
							if !(_sskip) then {
							if (_currentData == 'secondary') then {
								if (_currentItem in _listbp) then {
									_unitBP = _currentItem;
								};
								_backpackloadout = [[],[]];
								_bpcost = 0;
							};
							Call Compile Format ['_old = _current%1;_currentWeapons = _currentWeapons - [_current%1]; _current%1Cost = %2; _current%1 = "%3";ctrlSetText[_%1IDC,"%4"]',_currentData,_get select QUERYGEARCOST,_currentItem,_get select QUERYGEARPICTURE];
							//--- New Magazines.
							_currentMags = _get select QUERYGEARMAGAZINES;
							//--- Old Magazines.
							_get2 = (_old+"_W") Call GetNamespace;
							if (isNil '_get2') then {
								_get2 = _old Call GetNamespace;
							};
							if !(isNil '_get2') then {
								if (typeName (_get2 select QUERYGEARMAGAZINES) != 'SCALAR' && typeName (_get select QUERYGEARMAGAZINES) != 'SCALAR') then {
									_oldMags = _get2 select QUERYGEARMAGAZINES;
									_currentMagazines = [_currentMags select 0,_oldMags,_currentMagazines] Call ReplaceInventoryAmmo;
								};
							};
						};
						};
						if (!_sskip) then {
						_currentWeapons = _currentWeapons + [_currentItem];
						_displayInv = true;
					};
				};
				};
				if (_tfil == 'backpack') then {
					_currentBPRow = lnbCurSelRow _lb;
					_currentBPValue = lnbValue[_lb,[_currentBPRow,0]];
					_currentBPItem = _backpack select _currentBPValue;
					
					_hasSpace = [_unitBP,_backpackloadout,_currentBPItem] Call BackpackHasSpace;
					
					if (_hasSpace) then {
						_id = (_backpackloadout select 0) find _currentBPItem;
						if (_id == -1) then {
							_arrayType = (_backpackloadout select 0) + [_currentBPItem];
							_arrayAmount = (_backpackloadout select 1) + [1];
							_backpackloadout set[0, _arrayType];
							_backpackloadout set[1, _arrayAmount];
						} else {
							_arrayAmount = (_backpackloadout select 1) set [_id,((_backpackloadout select 1) select _id)+1];
						};
					};
					
					_updateBackpack = true;
				};
				if (_filler == 'misc' || !_skip) then {
					_type = _get select QUERYGEARTYPE;
					if (_type == 'CfgMagazines') then {
						_currentMagazines = [_currentMagazines,_currentItem] Call UIAddMagazine;
						_displayInv = true;
					};
					if (_type == 'Special' && count _currentSpecials < 3 && !(_currentItem in _currentSpecials)) then {
						_currentSpecials = _currentSpecials + [_currentItem];
						_currentSpecialCost = 0;
						_u = 0;
						{
							_zt = _x Call GetNamespace;
							ctrlSetText[_specialIDC + _u,_zt select QUERYGEARPICTURE];
							_currentSpecialCost = _currentSpecialCost + (_zt select QUERYGEARCOST);
							_u = _u + 1;
						} forEach _currentSpecials;
						_displayInv = true;
					};
					if (_type == 'Item') then {
						if (!(_currentItem in _currentItems)) then {
							_currentItems = [_currentItems,_currentItem] Call UIAddItem;
							_displayInv = true;
						};
					};
				};
				if (_tfil == 'template') then {
					_tempWeapons = _template select _currentValue;
					_tempItems = _templateItems select _currentValue;
					_tempMags = _templateMags select _currentValue;
					_tempSpecs = _templateSpecs select _currentValue;
					_currentPrimary = '';
					_currentSecondary = '';
					_currentSidearm = '';
					_currentPrimaryCost = 0;
					_currentSecondaryCost = 0;
					_currentSidearmCost = 0;
					_getnum = 0;
					_currentWeapons = [];
					_currentItems = [];
					_backpackloadout = [[],[]];
					{
						if (typeName _x == 'STRING') then {_currentItems = _currentItems + [_x]};
						if (typeName _x == 'ARRAY') then {_backpackloadout = _x};
					} forEach _tempItems;
					_bpcost = 0;
					
					if (count (_backpackloadout select 0) > 0) then {
						_getnum = getNumber(configFile >> 'CfgVehicles' >> typeOf _currentUnit >> 'canCarryBackPack');
						if (_getnum == 1) then {
							_u = 0;
							_currentUpgrades = (sideJoinedText) Call GetSideUpgrades;
							{
								_get = _x Call GetNamespace;
								if !(isNil '_get') then {
									if ((_currentUpgrades select 13) >= (_get select QUERYGEARUPGRADE)) then {
										_bpcost = _bpcost + ((_get select QUERYGEARCOST)*((_backpackloadout select 1) select _u));
									};
								};
								_u = _u + 1;
							} forEach (_backpackloadout select 0);
						};
					};
					_currentBackpackLoadout = (_backpackloadout select 0);
					_currentBackpackLoadoutAmount = (_backpackloadout select 1);
					{
						_cwep = _x;
						_get = (_x+"_W") Call GetNamespace;
						if (isNil '_get') then {
							_get = _x Call GetNamespace;
						};
						
						if (({_x == _cwep} count _primary) > 0) then {_currentWeapons = _currentWeapons + [_x];_currentPrimary = _x;_currentPrimaryCost = _get select QUERYGEARCOST;ctrlSetText[_primaryIDC,_get select QUERYGEARPICTURE]} else {
							if (({_x == _cwep} count _secondary) > 0) then {_currentWeapons = _currentWeapons + [_x];_currentSecondary = _x;_currentSecondaryCost = _get select QUERYGEARCOST;ctrlSetText[_secondaryIDC,_get select QUERYGEARPICTURE]} else {
								if (({_x == _cwep} count _sidearm) > 0) then {_currentWeapons = _currentWeapons + [_x];_currentSidearm = _x;_currentSidearmCost = _get select QUERYGEARCOST;ctrlSetText[_sidearmIDC,_get select QUERYGEARPICTURE]};
							};
						};
					} forEach _tempWeapons;
					if (_currentPrimary == '') then  {ctrlSetText [_primaryIDC,'\ca\ui\data\ui_gear_gun_gs.paa']};
					if (_currentSecondary == '') then  {ctrlSetText [_secondaryIDC,'\ca\ui\data\ui_gear_sec_gs.paa']};
					if (_currentSidearm == '') then  {ctrlSetText [_sidearmIDC,'\ca\ui\data\ui_gear_hgun_gs.paa']};
					if (_currentSecondary in _listbp && _getnum == 1) then {_unitBP = _currentSecondary} else {_unitBP = ""};
					_currentMagazines = _tempMags;
					_currentSpecials = _tempSpecs;
					_currentSpecialCost = 0;
					for [{_x = 0},{_x < 2},{_x = _x + 1}] do {ctrlSetText[_specialIDC + _x,'\Ca\UI\Data\ui_gear_eq_gs.paa']};
					_u = 0;
					{
						_get = _x Call GetNamespace;
						_currentSpecialCost = _currentSpecialCost + (_get select QUERYGEARCOST);
						ctrlSetText[_specialIDC + _u,_get select QUERYGEARPICTURE];
						_u = _u + 1;
					} forEach _currentSpecials;
					_displayInv = true;
				};
			};

			case 'addMagazine': {
				if !(_manageBackpack) then {
					_currentMagValue = lnbValue[_lbm,[lnbCurSelRow _lbm,0]];
					_currentMag = _currentMags select _currentMagValue;
					_currentMagazines = [_currentMagazines,_currentMag] Call UIAddMagazine;
					_displayInv = true;
				} else {
					_currentBPItemValue = lnbValue[_lbm,[lnbCurSelRow _lbm,0]];
					//--- todo find
					_arrayType = _backpackloadout select 0;
					_arrayAmount = _backpackloadout select 1;
					_itemAmount = _arrayAmount select _currentBPItemValue;
					if ((_itemAmount -1) <= 0) then {
						_arrayType set [_currentBPItemValue, 'nil'];
						_arrayAmount set [_currentBPItemValue, 'nil'];
						_arrayType = _arrayType - ['nil'];
						_arrayAmount = _arrayAmount - ['nil'];
					} else {
						_arrayAmount set [_currentBPItemValue, (_arrayAmount select _currentBPItemValue)-1];
					};
					_backpackloadout set [0, _arrayType];
					_backpackloadout set [1, _arrayAmount];
					_updateBackpack = true;
				};
			};
		};
		WF_Logic setVariable ['lbMainAction',''];
	};
	
	//--- Remove a weapon by clicking on it.
	if (primClicked) then {primClicked = false;if (_currentPrimary != '') then  {ctrlSetText [_primaryIDC,'\ca\ui\data\ui_gear_gun_gs.paa'];_index = _primary find _currentPrimary;_currentPrimaryCost = 0;_currentWeapons = _currentWeapons - [_currentPrimary];_currentPrimary = '';_displayInv = true}};
	if (secoClicked) then {secoClicked = false;if (_currentSecondary != '') then  {ctrlSetText [_secondaryIDC,'\ca\ui\data\ui_gear_sec_gs.paa'];_index = _secondary find _currentSecondary;_currentSecondaryCost = 0;_currentWeapons = _currentWeapons - [_currentSecondary];_currentSecondary = '';_displayInv = true;_backpackloadout = [[],[]];_bpcost = 0;_unitBP = ""}};
	if (sideClicked) then {sideClicked = false;if (_currentSidearm != '') then  {ctrlSetText [_sidearmIDC,'\ca\ui\data\ui_gear_hgun_gs.paa'];_index = _sidearm find _currentSidearm;_currentSidearmCost = 0;_currentWeapons = _currentWeapons - [_currentSidearm];_currentSidearm = '';_displayInv = true}};

	if (_unitSwap) then {
		WF_Logic setVariable ['WF_GEAR_Swap',false];
		if (count _unitList > 0) then {_currentUnit = _unitList select (lbCurSel 3854)} else {_currentUnit = player};
		_updateUnit = true;
	};
	
	if (_updateUnit) then {
		_currentWeapons = weapons _currentUnit;
		_currentCost = 0;
		_unitBP = "";
		if !(isNull(unitBackpack _currentUnit)) then {
			_unitBP = typeOf(unitBackpack _currentUnit);
			_unitBP = [_unitBP] Call _returnProperBag;
			_currentWeapons = _currentWeapons + [_unitBP];
			
			//--- Retrieve the backpack content cost.
			_backpackloadout = getMagazineCargo (unitBackPack _currentUnit);
			_currentCost = _currentCost - _bpcost;
			_bpcost = 0;
			if (count (_backpackloadout select 0) > 0) then {
				_u = 0;
				_currentUpgrades = (sideJoinedText) Call GetSideUpgrades;
				{
					_get = _x Call GetNamespace;
					if !(isNil '_get') then {
						if ((_currentUpgrades select 13) >= (_get select QUERYGEARUPGRADE)) then {
							_bpcost = _bpcost + ((_get select QUERYGEARCOST)*((_backpackloadout select 1) select _u));
						};
					};
					_u = _u + 1;
				} forEach (_backpackloadout select 0);
			};
			_currentCost = _currentCost + _bpcost;
		};
		
		_get = getNumber(configFile >> 'CfgVehicles' >> typeOf _currentUnit >> 'canCarryBackPack');
		_show = if (_get == 1) then {true} else {false};
		ctrlShow [3802,_show];
		
		if (_manageBackpack) then {_updateFiller = true};
		
		_currentSpecials = [];
		_currentItems = [];
		_currentMagazines = magazines _currentUnit;
		
		_currentPrimary = '';
		_currentSecondary = '';
		_currentSidearm = '';

		_sideGear = _currentWeapons;
		{if (!(_x in _all)) then {_sideGear = _sideGear - [_x]}} forEach _currentWeapons;
		_currentWeapons = _sideGear;
		
		_sideGear = _currentMagazines;
		{if (!(_x in _misc) && !(_x in _magazine)) then {_sideGear = _sideGear - [_x]}} forEach _currentMagazines;
		_currentMagazines = _sideGear;
		
		_currentPrimaryCost = 0;
		_currentSecondaryCost = 0;
		_currentSidearmCost = 0;
		_currentSpecialCost = 0;

		ctrlSetText [_primaryIDC,'\ca\ui\data\ui_gear_gun_gs.paa'];
		ctrlSetText [_secondaryIDC,'\ca\ui\data\ui_gear_sec_gs.paa'];
		ctrlSetText [_sidearmIDC,'\ca\ui\data\ui_gear_hgun_gs.paa'];
		ctrlSetText [3535,'\Ca\UI\Data\ui_gear_eq_gs.paa'];
		ctrlSetText [3536,'\Ca\UI\Data\ui_gear_eq_gs.paa'];
		
		{
			_cwep = _x;
			_get = (_cwep+"_W") Call GetNamespace;
			if (isNil '_get') then {
				_get = _cwep Call GetNamespace;
			};
			
			if !(isNil '_get') then {
				_found = false;
				_index = {_x == _cwep} count _primary;
				if (_index > 0) then {_currentPrimary = _cwep;_currentPrimaryCost = _get select QUERYGEARCOST;ctrlSetText[_primaryIDC,_get select QUERYGEARPICTURE];_found = true};
				if !(_found) then {
					_index = {_x == _cwep} count _secondary;
					if (_index > 0) then {_currentSecondary = _cwep;_currentSecondaryCost = _get select QUERYGEARCOST;ctrlSetText[_secondaryIDC,_get select QUERYGEARPICTURE];_found = true};
					if !(_found) then {
						_index = {_x == _cwep} count _sidearm;
						if (_index > 0) then {_currentSidearm = _cwep;_currentSidearmCost = _get select QUERYGEARCOST;ctrlSetText[_sidearmIDC,_get select QUERYGEARPICTURE];_found = true};
						if !(_found) then {
							_index = {_x == _cwep} count _misc;
							if (_index > 0) then {
								switch (_get select QUERYGEARTYPE) do {
									case 'Special': {
										_currentSpecials = _currentSpecials + [_x];
										_currentSpecialCost = _currentSpecialCost + (_get select QUERYGEARCOST);
										_u = 0;
										{
											_zt = _x Call GetNamespace;
											ctrlSetText[_specialIDC + _u,_zt select QUERYGEARPICTURE];
											_u = _u + 1;
										} forEach _currentSpecials;
									};
									case 'Item': {
										_currentItems = _currentItems + [_x];
									};
								};
							};
						};
					};
				};
			};
		} forEach _currentWeapons;

		_currentWeapons = _currentWeapons - _misc;
		_data = [_currentMagazines,_currentItems] Call DisplayInventory;
		_inventorySlots = _data select 0;
		_sidearmInventorySlots = _data select 1;
		_miscItemSlots = _data select 2;
		_currentCost = _currentCost + (_data select 3) + _currentPrimaryCost + _currentSecondaryCost + _currentSidearmCost + _currentSpecialCost;
		_cost = 0;
		_updateUnit = false;
	};
	
	//--- Remove a magazine by clicking on it.
	if (_inventoryClick != -1) then {
		//--- Main Inventory.
		if (_inventoryClick > 3502 && _inventoryClick < 3515) then {
			_slot = _inventoryClick - 3503;
			if (_slot < Count _inventorySlots) then {
				_index = _currentMagazines find (_inventorySlots Select _slot);
				if (_index != -1) then {_currentMagazines = [_currentMagazines,_index] Call ReplaceArray};
			};
		};
		//--- Handgun Inventory
		if (_inventoryClick > 3514 && _inventoryClick < 3523) then {
			_slot = _inventoryClick - 3515;
			if (_slot < Count _sidearmInventorySlots) then {
				_index = _currentMagazines find (_sidearmInventorySlots Select _slot);
				if (_index != -1) then {_currentMagazines = [_currentMagazines,_index] Call ReplaceArray};
			};
		};
		//--- Misc Inventory
		if (_inventoryClick > 3522 && _inventoryClick < 3535) then {
			_slot = _inventoryClick - 3523;
			if (_slot < Count _miscItemSlots) then {
				_index = _currentItems find (_miscItemSlots Select _slot);
				if (_index != -1) then {_currentItems = [_currentItems,_index] Call ReplaceArray};
			};
		};
		//--- Remove a special item.
		if (_inventoryClick == 3535 || _inventoryClick == 3536) then {
			_slot = _inventoryClick - 3535;
			if (_slot < Count _currentSpecials) then {
				_currentSpecialCost = 0;
				_currentSpecials = _currentSpecials - [_currentSpecials select _slot];
				for [{_x = 0},{_x < 2},{_x = _x + 1}] do {ctrlSetText[_specialIDC + _x,'\Ca\UI\Data\ui_gear_eq_gs.paa']};
				_u = 0;
				{
					_get = _x Call GetNamespace;
					_currentSpecialCost = _currentSpecialCost + (_get select QUERYGEARCOST);
					ctrlSetText[_specialIDC + _u,_get select QUERYGEARPICTURE];
					_u = _u + 1;
				} forEach _currentSpecials;				
			};
		};
		WF_Logic setVariable ['InventoryClick',-1];
		_displayInv = true;
	};
	
	//--- Custom UA.
	if (_actionSE != '') then {
		switch (_actionSE) do {
			case 'reload': {
				if !(isNil 'respawnWeapons') then {
					_currentPrimary = '';
					_currentSecondary = '';
					_currentSidearm = '';
					_currentPrimaryCost = 0;
					_currentSecondaryCost = 0;
					_currentSidearmCost = 0;
					_currentWeapons = [];
					_currentItems = [];
					_currentSpecials = [];
					_backpackloadout = [[],[]];
					
					{
						_cwep = _x;
						_get = (_cwep+"_W") Call GetNamespace;
						if (isNil '_get') then {
							_get = _cwep Call GetNamespace;
						};
						
						if !(isNil '_get') then {
							_index = {_x == _cwep} count _primary;
							if (_index > 0) then {_currentWeapons = _currentWeapons + [_x];_currentPrimary = _x;_currentPrimaryCost = _get select QUERYGEARCOST;ctrlSetText[_primaryIDC,_get select QUERYGEARPICTURE]} else {
								_index = {_x == _cwep} count _secondary;
								if (_index > 0) then {_currentWeapons = _currentWeapons + [_x];_currentSecondary = _x;_currentSecondaryCost = _get select QUERYGEARCOST;ctrlSetText[_secondaryIDC,_get select QUERYGEARPICTURE]} else {
									_index = {_x == _cwep} count _sidearm;
									if (_index > 0) then {_currentWeapons = _currentWeapons + [_x];_currentSidearm = _x;_currentSidearmCost = _get select QUERYGEARCOST;ctrlSetText[_sidearmIDC,_get select QUERYGEARPICTURE]} else {
										_index = {_x == _cwep} count _misc;
										if (_index > 0) then {
											switch (_get select QUERYGEARTYPE) do {
												case 'Special': {
													_currentSpecials = _currentSpecials + [_x];
												};
												case 'Item': {
													_currentItems = _currentItems + [_x];
												};
											};
										};
									};
								};
							};
						};
					} forEach respawnWeapons;
					
					if !(isNil 'respawnBagContent') then {
						if (count (respawnBagContent select 0) > 0) then {
							_backpackloadout = [respawnBagContent select 0,respawnBagContent select 1];
							_bpcost = 0;
							
							if (count (_backpackloadout select 0) > 0) then {
								_u = 0;
								_currentUpgrades = (sideJoinedText) Call GetSideUpgrades;
								{
									_get = _x Call GetNamespace;
									if !(isNil '_get') then {
										if ((_currentUpgrades select 13) >= (_get select QUERYGEARUPGRADE)) then {
											_bpcost = _bpcost + ((_get select QUERYGEARCOST)*((_backpackloadout select 1) select _u));
										};
									};
									_u = _u + 1;
								} forEach (_backpackloadout select 0);
							};
							_currentBackpackLoadout = (_backpackloadout select 0);
							_currentBackpackLoadoutAmount = (_backpackloadout select 1);
						};
					};
					
					if (_currentSecondary in _listbp) then {
						_unitBP = _currentSecondary;
					};
					
					if (_currentPrimary == '') then  {ctrlSetText [_primaryIDC,'\ca\ui\data\ui_gear_gun_gs.paa']};
					if (_currentSecondary == '') then  {ctrlSetText [_secondaryIDC,'\ca\ui\data\ui_gear_sec_gs.paa']};
					if (_currentSidearm == '') then  {ctrlSetText [_sidearmIDC,'\ca\ui\data\ui_gear_hgun_gs.paa']};
					
					_currentMagazines = respawnAmmo;
					_currentSpecialCost = 0;
					
					for [{_x = 0},{_x < 2},{_x = _x + 1}] do {ctrlSetText[_specialIDC + _x,'\Ca\UI\Data\ui_gear_eq_gs.paa']};
					
					_u = 0;
					{
						_get = _x Call GetNamespace;
						_currentSpecialCost = _currentSpecialCost + (_get select QUERYGEARCOST);
						ctrlSetText[_specialIDC + _u,_get select QUERYGEARPICTURE];
						_u = _u + 1;
					} forEach _currentSpecials;

					_displayInv = true;
				};
			};
			case 'clear': {
				_currentPrimary = '';
				_currentSecondary = '';
				_currentSidearm = '';
				_unitBP = "";
				_currentPrimaryCost = 0;
				_currentSecondaryCost = 0;
				_currentSidearmCost = 0;
				_currentSpecialCost = 0;
				_bpcost = 0;
				_currentWeapons = [];
				_currentItems = [];
				_currentSpecials = [];
				_currentMagazines = [];
				ctrlSetText [_primaryIDC,'\ca\ui\data\ui_gear_gun_gs.paa'];
				ctrlSetText [_secondaryIDC,'\ca\ui\data\ui_gear_sec_gs.paa'];
				ctrlSetText [_sidearmIDC,'\ca\ui\data\ui_gear_hgun_gs.paa'];
				for [{_x = 0},{_x < 2},{_x = _x + 1}] do {ctrlSetText[_specialIDC + _x,'\Ca\UI\Data\ui_gear_eq_gs.paa']};
				_displayInv = true;
			};
			case 'backpack': {
				if (_unitBP != "") then {
					lnbClear _lb;
					[_backpack,'backpack',_lb] Call UIGearFillList;
					_manageBackpack = true;
					_updateBackpack = true;
				};
			};
		};
		WF_Logic setVariable ['WF_Gear_Action',''];
	};
	
	//--- Show inventory (Icons).
	if (_displayInv) then {
		_displayInv = false;
		_upgradeCost = _currentSpecialCost;
		_data = [_currentMagazines,_currentItems] Call DisplayInventory;
		_inventorySlots = _data select 0;
		_sidearmInventorySlots = _data select 1;
		_miscItemSlots = _data select 2;
		_upgradeCost = _upgradeCost + (_data select 3);
		if (_currentPrimary != '') then  {_upgradeCost = _upgradeCost + _currentPrimaryCost};
		if (_currentSecondary != '') then  {_upgradeCost = _upgradeCost + _currentSecondaryCost};
		if (_currentSidearm != '') then  {_upgradeCost = _upgradeCost + _currentSidearmCost};
		if !(_currentSecondary in _listbp) then {_unitBP = ""};
		_cost = (_upgradeCost+_bpcost) - _currentCost;
	};
	
	//--- Update the backpack
	if (_updateBackpack) then {
		_updateBackpack = false;
		
		_currentBackpackLoadout = [];
		_currentBackpackLoadoutAmount = [];
		_currentBackpackLoadoutCost = [];
		_currentBackpackLoadoutPictures = [];
		_currentBackpackLoadoutNames = [];
		_currentBackpackLoadoutUpgrades = [];
		_currentBackpackLoadoutAllowed = [];
		_u = 0;
		_cost = _cost - _bpcost;
		_bpcost = 0;
		if (count (_backpackloadout select 0) > 0) then {
			_currentUpgrades = (sideJoinedText) Call GetSideUpgrades;
			{
				_get = _x Call GetNamespace;
				if !(isNil '_x') then {
					if ((_currentUpgrades select 13) >= (_get select QUERYGEARUPGRADE)) then {
						_currentBackpackLoadout = _currentBackpackLoadout + [_x];
						_currentBackpackLoadoutAmount = _currentBackpackLoadoutAmount + [(_backpackloadout select 1) select _u];
						_currentBackpackLoadoutCost = _currentBackpackLoadoutCost + [_get select QUERYGEARCOST];
						_bpcost = _bpcost + ((_get select QUERYGEARCOST)*((_backpackloadout select 1) select _u));
						_currentBackpackLoadoutPictures = _currentBackpackLoadoutPictures + [_get select QUERYGEARPICTURE];
						_currentBackpackLoadoutNames = _currentBackpackLoadoutNames + [str((_backpackloadout select 1) select _u)+"x "+(_get select QUERYGEARLABEL)];
						_currentBackpackLoadoutUpgrades = _currentBackpackLoadoutUpgrades + [_get select QUERYGEARUPGRADE];
						_currentBackpackLoadoutAllowed = _currentBackpackLoadoutAllowed + [_get select QUERYGEARALLOWED];
					};
				};
				_u = _u + 1;
			} forEach (_backpackloadout select 0);
		};
		_cost = _cost + _bpcost;
		lnbClear _lbm;
		[_currentBackpackLoadoutCost,_currentBackpackLoadoutNames,_currentBackpackLoadoutPictures,_currentBackpackLoadoutUpgrades,_currentBackpackLoadoutAllowed,'backpack',_lbm] Call UIGearFillTemplateList;
	};
	
	//--- Buy a loadout.
	if (buyLoadout) then {
		buyLoadout = false;
		_funds = Call GetPlayerFunds;
		if (_funds >= _cost) then {
			(-_cost) Call ChangePlayerFunds;
			//--- Player's respawn loadout.
			if (_currentUnit == player && (vehicleVarName player == clientIdentification)) then {
				respawnWeapons = _currentWeapons + _currentSpecials + _currentItems;
				respawnAmmo = _currentMagazines;
				if (_unitBP != '') then {
					respawnBag = _unitBP;
					respawnBagContent = [_currentBackpackLoadout,_currentBackpackLoadoutAmount];
				} else {
					respawnBag = nil;
					respawnBagContent = [[],[]];
				};
			};
			
			/* Equip the core before the backpack */
			_weaps = _currentWeapons;
			if !(WF_A2_Vanilla) then {
				_temp = _weaps;
				{
					if (_x in _listbp) then {_temp = _temp - [_x]};
				} forEach _weaps;
				_weaps = _temp;
			};
			[_currentUnit,(_weaps + _currentSpecials + _currentItems),_currentMagazines] Call EquipLoadout;
			
			/* Equip backpack if needed */
			if !(WF_A2_Vanilla) then {				
				if (_unitBP != "" || !isNull (unitBackpack _currentUnit)) then {
					_add = true;
					if ((_unitBP == "" && !isNull (unitBackpack _currentUnit)) || (_unitBP != "" && !isNull (unitBackpack _currentUnit))) then {removeBackpack _currentUnit;};
					if !(isNull (unitBackpack _currentUnit)) then {
						if (typeOf (unitBackpack _currentUnit) == _unitBP) then {_add = false};
					};
						
					if (_add && _unitBP != "") then {
						_currentUnit addBackpack _unitBP;
					};
					
					[unitBackpack _currentUnit,[_currentBackpackLoadout,_currentBackpackLoadoutAmount]] Call EquipBackpack;
				};
			};
			_data = [_currentMagazines,_currentItems] Call DisplayInventory;
			_inventorySlots = _data select 0;
			_sidearmInventorySlots = _data select 1;
			_miscItemSlots = _data select 2;
			_currentCost = (_data select 3) + _currentPrimaryCost + _currentSecondaryCost + _currentSidearmCost + _currentSpecialCost + _bpcost;
			respawnGearCost = _currentCost;
			_cost = 0;
		} else {
			hint parseText(Format [localize "STR_WF_Funds_Missing_Gear",_cost - _funds]);
		};
	};
	
	//--- Remove an existing template.
	if (deleteLoadout) then {
		deleteLoadout = false;
		//--- Behave only on template filler.
		if (_filler == 'template') then {
			_currentRow = lnbCurSelRow _lb;
			_currentValue = lnbValue[_lb,[_currentRow,0]];
			//--- Update the templates.
			_template set [_currentValue, "DELETE"];
			_template = _template - ["DELETE"];
			WF_Logic setVariable["templateClasses",_template];
			_templateCosts set [_currentValue, "DELETE"];
			_templateCosts = _templateCosts - ["DELETE"];
			WF_Logic setVariable["templateCosts",_templateCosts];
			_templatePictures set [_currentValue, "DELETE"];
			_templatePictures = _templatePictures - ["DELETE"];
			WF_Logic setVariable["templatePictures",_templatePictures];
			_templateNames set [_currentValue, "DELETE"];
			_templateNames = _templateNames - ["DELETE"];
			WF_Logic setVariable["templateNames",_templateNames];
			_templateMags set [_currentValue, "DELETE"];
			_templateMags = _templateMags - ["DELETE"];
			WF_Logic setVariable["templateMags",_templateMags];
			_templateItems set [_currentValue, "DELETE"];
			_templateItems = _templateItems - ["DELETE"];
			WF_Logic setVariable["templateItems",_templateItems];
			_templateSpecs set [_currentValue, "DELETE"];
			_templateSpecs = _templateSpecs - ["DELETE"];
			WF_Logic setVariable["templateSpecs",_templateSpecs];
			_templateUpgrades set [_currentValue, "DELETE"];
			_templateUpgrades = _templateUpgrades - ["DELETE"];
			WF_Logic setVariable["templateUpgrades",_templateUpgrades];
			_templateAllowed set [_currentValue, "DELETE"];
			_templateAllowed = _templateAllowed - ["DELETE"];
			WF_Logic setVariable["templateAllowed",_templateAllowed];
			_updateFiller = true;
		};
	};
	
	if (saveLoadout) then {
		saveLoadout = false;
		//--- Behave only on template filler.
		if (_filler == 'template') then {
			//--- Update the templates.
			_desc = '';
			_pict = '';
			_temp = [];
			_cAllow = true;
			_upgr = 0;
			_pallow = true;
			_sallow = true;

			if (_currentPrimary != '') then {
				_get = _currentPrimary Call GetNamespace;
				_temp = _temp + [_currentPrimary];
				_desc = _desc + (_get select QUERYGEARLABEL);
				_pict = (_get select QUERYGEARPICTURE);
				if !(_get select QUERYGEARALLOWED) then {_cAllow = false};
				_upgr = _get select QUERYGEARUPGRADE;
				_pallow = _get select QUERYGEARALLOWTWO;
			};
			if (_currentSecondary != '') then {
				_get = (_currentSecondary+"_W") Call GetNamespace;
				if (isNil '_get') then {
					_get = _currentSecondary Call GetNamespace;
				};
				_temp = _temp + [_currentSecondary];
				if (_desc != '') then { _desc = _desc + "/"};
				//--- Needless to check if the primary is prohibed.
				_desc = _desc + (_get select QUERYGEARLABEL);
				if (_pict == '') then {_pict = _get select QUERYGEARPICTURE};
				if (_cAllow) then {if !(_get select QUERYGEARALLOWED) then {_cAllow = false}};
				if ((_get select QUERYGEARUPGRADE) > _upgr) then {_upgr = (_get select QUERYGEARUPGRADE)};
				_sallow = _get select QUERYGEARALLOWTWO;
			};
			if (_currentSidearm != '') then {
				_get = _currentSidearm Call GetNamespace;
				_temp = _temp + [_currentSidearm];
				if (_desc != '') then { _desc = _desc + "/"};
				//--- Needless to check if the secondary is prohibed.
				_desc = _desc + (_get select QUERYGEARLABEL);
				if (_pict == '') then {_pict = _get select QUERYGEARPICTURE};
				if (_cAllow) then {if !(_get select QUERYGEARALLOWED) then {_cAllow = false}};
				if ((_get select QUERYGEARUPGRADE) > _upgr) then {_upgr = (_get select QUERYGEARUPGRADE)};
			};
			//--- Handle Backpack Content.
			_addin = [_currentItems];
			if (_unitBP != '') then {
				_extra = [_currentBackpackLoadout,_currentBackpackLoadoutAmount];
				_addin = [_currentItems + [_extra]];
			};
			if (_pallow || _sallow || !paramExtendedInventory) then {
			_template = _template + [_temp];
			WF_Logic setVariable["templateClasses",_template];
			_templateCosts = _templateCosts + [(_cost + _currentCost)];
			WF_Logic setVariable["templateCosts",_templateCosts];
			_templatePictures = _templatePictures + [_pict];
			WF_Logic setVariable["templatePictures",_templatePictures];
			_templateNames = _templateNames + [_desc];
			WF_Logic setVariable["templateNames",_templateNames];
			_templateMags = _templateMags + [_currentMagazines];
			WF_Logic setVariable["templateMags",_templateMags];
				_templateItems = _templateItems + _addin;
			WF_Logic setVariable["templateItems",_templateItems];
			_templateSpecs = _templateSpecs + [_currentSpecials];
			WF_Logic setVariable["templateSpecs",_templateSpecs];
			_templateUpgrades = _templateUpgrades + [_upgr];
			WF_Logic setVariable["templateUpgrades",_templateUpgrades];
			_templateAllowed = _templateAllowed + [_cAllow];
			WF_Logic setVariable["templateAllowed",_templateAllowed];
			_updateFiller = true;
			} else {
				hint parseText (localize 'STR_WF_Gear_AllowTwo');
		};
	};
	};
	
	//--- Loadout Cost.
	ctrlSetText[3850,Format[localize 'STR_WF_Cost',_cost]];
	//--- Player's Cash.
	ctrlSetText[3851,Format["%1 $ %2.",localize 'STR_WF_CashLabel',Call GetPlayerFunds]];
	
	_lastFiller = _filler;
	sleep 0.05;
};

//--- Variables destruction.
WF_Logic setVariable ['lbChange',nil];
WF_Logic setVariable ['lbMainAction',nil];
WF_Logic setVariable ['InventoryClick',nil];
WF_Gear_Hotkeys = nil;
primClicked = nil;
secoClicked = nil;
sideClicked = nil;
buyLoadout = nil;
saveLoadout = nil;
deleteLoadout = nil;

(findDisplay 16000) displayRemoveEventHandler ['KeyDown',_disp];

private ["_i","_break","_currentIDC","_type","_val","_con","_extra","_currentCost","_skip","_cpt","_size","_txt","_queu","_params","_funds","_currentRow","_currentValue","_unit","_currentUnit","_update","_driver","_updateDetails","_gunner","_commander","_factSel","_closest","_updateMap","_isLocked","_listUnits","_IDCS","_updateList","_nObjects","_sorted","_buildings","_factories","_countAlive","_nearest","_nearTown","_maxOut","_show","_c","_color","_slots","_isInfantry","_utype","_lastCheck","_value","_lastSel","_lastType","_disabledColor","_display","_enabledColor","_IDCLock","_IDCSVehi","_listBox","_comboFaction","_map","_mbu","_status","_statusLabel","_statusVals","_fillList","_changeFactionCombo"];
disableSerialization;

//--- Init.
MenuAction = -1;

_listUnits = [];

_closest = objNull;
_commander = false;
_extracrew = false;
_countAlive = 0;
_currentCost = 0;
_currentIDC = 0;
_disabledColor = [0.4, 0.4, 0.4, 1];
_display = _this select 0;
_driver = false;
_enabledColor = [1, 1, 1, 0.75];
_gunner = false;
_IDCLock = 12023;
_IDCS = [12005,12006,12007,12008,12020,12021];
_IDCSVehi = [12012,12013,12014,12041];
_isInfantry = false;
_isLocked = true;
_lastCheck = 0;
_lastSel = -1;
_lastType = 'nil';
_listBox = 12001;
_comboFaction = 12026;
_map = _display displayCtrl 12015;
_sorted = [];
_type = 'nil';
_update = true;
_updateDetails = true;
_updateList = true;
_updateMap = true;
_val = 0;
_mbu = 'WFBE_MAXGROUPSIZE' Call GetNamespace;

ctrlSetText[12025,localize 'STR_WF_Faction' + ":"];

//--- Get the closest Factory Type in range.
_break = false;
_status = [barracksInRange,lightInRange,heavyInRange,aircraftInRange,depotInRange,hangarInRange];
_statusLabel = ['Barracks','Light','Heavy','Aircraft','Depot','Airport'];
_statusVals = [0,1,2,3,4,3];
for [{_i = 0},{(_i < 6) && !_break},{_i = _i + 1}] do {
	if (_status select _i) then {
		_break = true;
		_currentIDC = _IDCS select _i;
		_type = _statusLabel select _i;
		_val = _statusVals select _i;
	};
};

if (_type == 'nil') exitWith {closeDialog 0};

//--- Destroy local variables.
_break = nil;
_status = nil;
_statusLabel = nil;
_statusVals = nil;

//--- Enable the current IDC.
_IDCS = _IDCS - [_currentIDC];
{
	_con = _display DisplayCtrl _x;
	_con ctrlSetTextColor [0.4, 0.4, 0.4, 1];
} forEach _IDCS;

//--- Loop.
while {alive player && dialog} do {
	//--- Nothing in range? exit!.
	if (!barracksInRange && !lightInRange && !heavyInRange && !aircraftInRange && !hangarInRange && !depotInRange) exitWith {closeDialog 0};
	if (side player != sideJoined || !dialog) exitWith {closeDialog 0};
	
	//--- Purchase.
	if (MenuAction == 1) then {
		MenuAction = -1;
		_currentRow = lnbCurSelRow _listBox;
		_currentValue = lnbValue[_listBox,[_currentRow,0]];
		_unit = _listUnits select _currentValue;
		_currentUnit = _unit Call GetNamespace;
		_currentCost = _currentUnit select QUERYUNITPRICE;
		_cpt = 1;
		if !(_isInfantry) then {
			_extra = 0;
			if (_driver) then {_extra = _extra + 1};
			if (_gunner) then {_extra = _extra + 1};
			if (_commander) then {_extra = _extra + 1};
			if (_extracrew) then {_extra = _extra + ((_currentUnit select QUERYUNITCREW) select 3)};
			_currentCost = _currentCost + (('WFBE_CREWCOST' Call GetNamespace) * _extra);
		};
		if ((_currentRow) != -1) then {
			_funds = Call GetPlayerFunds;
			_skip = false;
			if (_funds < _currentCost) then {_skip = true;hint parseText(Format[localize 'STR_WF_Funds_Missing',_currentCost - _funds,_currentUnit select QUERYUNITLABEL])};
			if !(_skip) then {
				_size = Count ((Units (group player)) Call GetLiveUnits);
				//--- Get the infantry limit based off the infantry upgrade.
				_realSize = ((sideJoined) Call GetSideUpgrades) select 0;
				switch (_realSize) do {
					case 0: {_realSize = round(_mbu / 4)};
					case 1: {_realSize = round(_mbu / 4)*2};
					case 2: {_realSize = round(_mbu / 4)*3};
					case 3: {_realSize = _mbu};
					default {_realSize = _mbu};
				};
				if (_isInfantry) then {if ((unitQueu + _size + 1) > _realSize) then {_skip = true;hint parseText(Format [localize 'STR_WF_MaxGroup',_realSize])}};

				if (!_isInfantry && !_skip) then {
					_cpt = 0;
					if (_driver) then {_cpt = _cpt + 1};
					if (_gunner) then {_cpt = _cpt + 1};
					if (_commander) then {_cpt = _cpt + 1};
					if (_extracrew) then {_cpt = _cpt + ((_currentUnit select QUERYUNITCREW) select 3)};
					if ((unitQueu + _size + _cpt) > _realSize && _cpt != 0) then {_skip = true;hint parseText(Format [localize 'STR_WF_MaxGroup',_realSize])};
				};
			};
			if !(_skip) then {
				//--- Check the max queu.
				if ((Format["WFBE_C_QUEUE_%1",_type] Call GetNamespace) < (Format["WFBE_C_QUEUE_%1_MAX",_type] Call GetNamespace)) then {
					[Format["WFBE_C_QUEUE_%1",_type],(Format["WFBE_C_QUEUE_%1",_type] Call GetNamespace)+1,true] Call SetNamespace;
					
				_queu = _closest getVariable 'queu';
				_txt = parseText(Format [localize 'STR_WF_BuyEffective',_currentUnit select QUERYUNITLABEL]);
				if (!isNil '_queu') then {if (count _queu > 0) then {_txt = parseText(Format [localize 'STR_WF_Queu',_currentUnit select QUERYUNITLABEL])}};
				hint _txt;
					_params = if (_isInfantry) then {[_closest,_unit,[],_type,_cpt]} else {[_closest,_unit,[_driver,_gunner,_commander,_extracrew,_isLocked],_type,_cpt]};
				_params Spawn BuildUnit;
				-(_currentCost) Call ChangePlayerFunds;
				} else {
					hint parseText(Format [localize 'STR_WF_Queu_Max',Format["WFBE_C_QUEUE_%1_MAX",_type] Call GetNamespace]);
			};
		};
	};
	};
	
	//--- Tabs selection.
	if (MenuAction == 101) then {MenuAction = -1;if (barracksInRange) then {_currentIDC = 12005;_type = 'Barracks';_val = 0;_update = true}};
	if (MenuAction == 102) then {MenuAction = -1;if (lightInRange) then {_currentIDC = 12006;_type = 'Light';_val = 1;_update = true}};
	if (MenuAction == 103) then {MenuAction = -1;if (heavyInRange) then {_currentIDC = 12007;_type = 'Heavy';_val = 2;_update = true}};
	if (MenuAction == 104) then {MenuAction = -1;if (aircraftInRange) then {_currentIDC = 12008;_type = 'Aircraft';_val = 3;_update = true}};
	if (MenuAction == 105) then {MenuAction = -1;if (depotInRange) then {_currentIDC = 12020;_type = 'Depot';_val = 4;_update = true}};
	if (MenuAction == 106) then {MenuAction = -1;if (hangarInRange) then {_currentIDC = 12021;_type = 'Airport';_val = 3;_update = true}};
	
	//--- driver-gunner-commander icons.
	if (MenuAction == 201) then {MenuAction = -1;_driver = if (_driver) then {false} else {true};_updateDetails = true};
	if (MenuAction == 202) then {MenuAction = -1;_gunner = if (_gunner) then {false} else {true};_updateDetails = true};
	if (MenuAction == 203) then {MenuAction = -1;_commander = if (_commander) then {false} else {true};_updateDetails = true};
	if (MenuAction == 204) then {MenuAction = -1;_extracrew = if (_extracrew) then {false} else {true};_updateDetails = true};
	
	//--- Factory DropDown list value has changed.
	if (MenuAction == 301) then {MenuAction = -1;_factSel = lbCurSel 12018;_closest = _sorted select _factSel;_updateMap = true};
	
	//--- Selection change, we update the details.
	if (MenuAction == 302) then {MenuAction = -1;_updateDetails = true};
	
	//--- Faction Filter changed.
	if (MenuAction == 303) then {MenuAction = -1;_update = true;[Format["WFBE_%1%2CURRENTFACTIONSELECTED",sideJoinedText,_type],(lbCurSel _comboFaction),true] Call SetNamespace};
	
	//--- Lock icon.
	if (MenuAction == 401) then {MenuAction = -1;_isLocked = if (_isLocked) then {false} else {true};_updateDetails = true};
	
	//--- Player funds.
	ctrlSetText [12019,Format [localize 'STR_WF_Cash',Call GetPlayerFunds]];
	
	//--- Update tabs.
	if (_update) then {
		_listUnits = Format ['WFBE_%1%2UNITS',sideJoinedText,_type] Call GetNamespace;

		[_comboFaction,_type] Call UIChangeComboBuyUnits;
		[_listUnits,_type,_listBox,_val] Call UIFillListBuyUnits;
		
		//--- Update tabs icons.
		_IDCS = [12005,12006,12007,12008,12020,12021];
		_IDCS = _IDCS - [_currentIDC];
		_con = _display DisplayCtrl _currentIDC;
		_con ctrlSetTextColor [0.75,0.75,0.75,1];
		{_con = _display DisplayCtrl _x;_con ctrlSetTextColor [0.4, 0.4, 0.4, 1]} forEach _IDCS;
		
		_update = false;
		_updateList = true;
		_updateDetails = true;
	};
	
	//--- Update factories.
	if (_updateList) then {
		switch (_type) do {
			//--- Specials.
			case 'Depot': {
				_nObjects = nearestObjects [(vehicle player), WFDEPOT,('WFBE_TOWNPURCHASERANGE' Call GetNamespace)];
				_closest = if (count _nObjects > 0) then {_nObjects select 0} else {objNull};
				_sorted = [_closest];
			};
			case 'Airport': {
				_sorted = [(vehicle player),Airfields] Call SortByDistance;
				_closest = _sorted select 0;
				_sorted = [_closest];
			};
			//--- Factories
			default {
				_buildings = (sideJoinedText) Call GetSideStructures;
				_factories = [sideJoined,Format ['WFBE_%1%2TYPE',sideJoinedText,_type] Call GetNamespace,_buildings] Call GetFactories;
				_sorted = [(vehicle player),_factories] Call SortByDistance;
				_closest = _sorted select 0;
				_countAlive = count _factories;
			};
		};

		//--- Refresh the Factory DropDown list.
		lbClear 12018;
		{
			_nearest = [_x,towns] Call SortByDistance;
			_nearTown = (_nearest select 0) getVariable 'name';
			_txt = _type + ' ' + _nearTown + ' ' + str (round((vehicle player) distance _x)) + 'M';
			lbAdd[12018,_txt];
		} forEach _sorted;
		lbSetCurSel [12018,0];
		
		_updateList = false;
		_updateMap = true;
	};
	
	//--- Display Factory Queu.
	_queu = _closest getVariable "queu";
	_value = if (isNil '_queu') then {0} else {count (_closest getVariable "queu")};
	ctrlSetText[12024,Format[localize 'STR_WF_Queued',str _value]];
	
	//--- List selection changed.
	if (_updateDetails) then {
		_currentRow = lnbCurSelRow _listBox;
		//--- Our list is not empty.
		if (_currentRow != -1) then {
			_currentValue = lnbValue[_listBox,[_currentRow,0]];
			_unit = _listUnits select _currentValue;
			_currentUnit = _unit Call GetNamespace;
			ctrlSetText [12009,_currentUnit select QUERYUNITPICTURE];
			ctrlSetText [12033,_currentUnit select QUERYUNITFACTION];
			ctrlSetText [12035,str (_currentUnit select QUERYUNITTIME)];
			_currentCost = _currentUnit select QUERYUNITPRICE;
			
			_isInfantry = if (_unit isKindOf 'Man') then {true} else {false};
			
			//--- Update driver-gunner-commander icons.
			if !(_isInfantry) then {
				ctrlSetText [12036,"N/A"];
				ctrlSetText [12037,str (getNumber (configFile >> 'CfgVehicles' >> _unit >> 'transportSoldier'))];
				ctrlSetText [12038,str (getNumber (configFile >> 'CfgVehicles' >> _unit >> 'maxSpeed'))];
				ctrlSetText [12039,str (getNumber (configFile >> 'CfgVehicles' >> _unit >> 'armor'))];
				if (_type != 'Depot') then {
					_slots = _currentUnit select QUERYUNITCREW;
					
					if (typeName _slots == "ARRAY") then {
						_hasCommander = _slots select 0;
						_hasGunner = _slots select 1;
						_turretsCount = _slots select 3;
						_extra = 0;
						
						_maxOut = false;
						if (_lastType != _type || _lastSel != _currentRow) then {_maxOut = true};
						
						if (_maxOut) then {
							_driver = true;
							_gunner = true;
							_commander = true;
							_extracrew = false;
						};
						
						if !(_hasGunner) then {_gunner = false};
						
						if !(_hasCommander) then {_commander = false};
						
						if (_turretsCount == 0) then {_extracrew = false};
						
						ctrlShow[_IDCSVehi select 0, true];
						ctrlShow[_IDCSVehi select 1, _hasGunner];
						ctrlShow[_IDCSVehi select 2, _hasCommander];
						ctrlShow[_IDCSVehi select 3, if (_turretsCount == 0) then {false} else {true}];
						
						_c = 0;
						{
							_color = if (_x) then {_enabledColor} else {_disabledColor};
							_con = _display displayCtrl (_IDCSVehi select _c);
							_con ctrlSetTextColor _color;

							_c = _c + 1;
						} forEach [_driver,_gunner,_commander,_extracrew];
						
						if (_driver) then {_extra = _extra + 1};
						if (_gunner) then {_extra = _extra + 1};
						if (_commander) then {_extra = _extra + 1};
						if (_extracrew) then {_extra = _extra + _turretsCount};
						
						//--- Set the 'extra' price.
						_currentCost = _currentCost + (('WFBE_CREWCOST' Call GetNamespace) * _extra);
					} else {//--- Backward compability.
						_c = 0;
						_extra = 0;
						
						//--- Enabled AI by default.
						_extracrew = false;
						_maxOut = false;
						if (_lastType != _type || _lastSel != _currentRow) then {_maxOut = true};
						
						switch (_slots) do {
							case 1: {
								if (_maxOut) then {_driver = true};
								if (_driver) then {_extra = _extra + 1};
								_gunner = false;
								_commander = false;
							};
							case 2: {
								if (_maxOut) then {_driver = true;_gunner = true};
								if (_driver) then {_extra = _extra + 1};
								if (_gunner) then {_extra = _extra + 1};
								_commander = false;
							};
							case 3: {
								if (_maxOut) then {_driver = true;_gunner = true;_commander = true};
								if (_driver) then {_extra = _extra + 1};
								if (_gunner) then {_extra = _extra + 1};
								if (_commander) then {_extra = _extra + 1};					
							};
						};
						
						//--- Show the icons.
						{
							_show = false;
							if (_c < _slots) then {_show = true};
							ctrlShow [_x,_show];
							_c = _c + 1;
						} forEach _IDCSVehi;
						
						//--- Mask extra crew.
						ctrlShow[_IDCSVehi select 3, false];
						
						_i = 0;
						
						//--- Set the icons.
						{
							_color = if (_x) then {_enabledColor} else {_disabledColor};
							_con = _display displayCtrl (_IDCSVehi select _i);
							_con ctrlSetTextColor _color;
							_i = _i + 1;
						} forEach [_driver,_gunner,_commander,_extracrew];

						//--- Set the 'extra' price.
						_currentCost = _currentCost + (('WFBE_CREWCOST' Call GetNamespace) * _extra);
					};
				} else {
					{ctrlShow [_x,false]} forEach (_IDCSVehi);
					_driver = false;
					_gunner = false;
					_commander = false;
					_extracrew = false;
				};
			} else {
				ctrlSetText [12036,Format ["%1/100",(_currentUnit select QUERYUNITSKILL) * 100]];
				ctrlSetText [12037,"N/A"];
				ctrlSetText [12038,"N/A"];
				ctrlSetText [12039,"N/A"];
			
				{ctrlShow [_x,false]} forEach (_IDCSVehi);
				_driver = false;
				_gunner = false;
				_commander = false;
				_extracrew = false;
				
				//--- Display a unit's loadout.
				_weapons = (getArray (configFile >> 'CfgVehicles' >> _unit >> 'weapons')) - ['Put','Throw'];
				_magazines = getArray (configFile >> 'CfgVehicles' >> _unit >> 'magazines');
				
				_classMags = [];
				_classMagsAmount = [];
				_MagsLabel = [];
				
				{
					_findAt = _classMags find _x;
					if (_findAt == -1) then {
						_classMags = _classMags + [_x];
						_classMagsAmount = _classMagsAmount + [1];
						_MagsLabel = _MagsLabel + [[_x,'displayName','CfgMagazines'] Call GetConfigInfo];
					} else {
						_classMagsAmount set [_findAt, (_classMagsAmount select _findAt) + 1];
					};
				} forEach _magazines;
				_txt = "<t color='#A7F04F' shadow='2'>" + (localize 'STR_WF_Weapons') + " :</t><br /> <t color='#D3A119' shadow='2'>{</t>";
				for [{_i = 0},{_i < count _weapons},{_i = _i + 1}] do {
					_txt = _txt + "<t color='#86C8FF' shadow='2'>" + ([(_weapons select _i),'displayName','CfgWeapons'] Call GetConfigInfo) + "</t>";
					if ((_i+1) < count _weapons) then {_txt = _txt + "<t color='#D3A119' shadow='2'>,</t> "}; 
				};
				_txt = _txt + "<t color='#D3A119' shadow='2'>}</t><br /><br />";	
				_txt = _txt + "<t color='#A7F04F' shadow='2'>" + (localize 'STR_WF_Magazines') + " :</t><br /> <t color='#D3A119' shadow='2'>{</t>";
				for [{_i = 0},{_i < count _MagsLabel},{_i = _i + 1}] do {
					_txt = _txt + "<t color='#86C8FF' shadow='2'>" + ((_MagsLabel select _i) + "</t> <t color='#D057F8' shadow='2'>x</t> <t color='#FB7E7E' shadow='2'>" + str (_classMagsAmount select _i)) + "</t>";
					if ((_i+1) < count _MagsLabel) then {_txt = _txt + "<t color='#D3A119' shadow='2'>,</t> "}; 
				};
				_txt = _txt + "<t color='#D3A119' shadow='2'>}</t>";
				
				(_display displayCtrl 12022) ctrlSetStructuredText (parseText _txt);
			};
			
			//--- Lock Icon.
			if !(_isInfantry) then {
				ctrlShow[_IDCLock,true];
				_color = if (_isLocked) then {_enabledColor} else {_disabledColor};
				_con = _display displayCtrl _IDCLock;
				_con ctrlSetTextColor _color;
			} else {
				ctrlShow[_IDCLock,false];
			};

			//--- Long description.
			if !(_isInfantry) then {
				if (isClass (configFile >> 'CfgVehicles' >> _unit >> 'Library')) then {
					_txt = getText (configFile >> 'CfgVehicles' >> _unit >> 'Library' >> 'libTextDesc');
					(_display displayCtrl 12022) ctrlSetStructuredText (parseText _txt);
				} else {
					(_display displayCtrl 12022) ctrlSetStructuredText (parseText '');
				};
			};
			
			ctrlSetText [12034,Format ["$ %1.",_currentCost]];
			_updateDetails = false;
		} else {
			{ctrlSetText [_x , ""]} forEach [12009,12010,12027,12028,12029,12030,12031,12032,12033,12034,12035,12036,12037,12038,12039];
			(_display displayCtrl 12022) ctrlSetStructuredText (parseText '');
		};
	};
	
	//--- Update the Factory Minimap position.
	if (_updateMap) then {
		ctrlMapAnimClear _map;
		_map ctrlMapAnimAdd [2,.075,getPos _closest];
		ctrlMapAnimCommit _map;
		_updateMap = false;
	};
	
	//--- Check that the factories of the current type are still alive.
	_lastCheck = _lastCheck + 0.1;
	if (_lastCheck > 2 && _type != 'Depot' && _type != 'Airport') then {
		_lastCheck = 0;
		_buildings = (sideJoinedText) Call GetSideStructures;
		_factories = [sideJoined,Format ['WFBE_%1%2TYPE',sideJoinedText,_type] Call GetNamespace,_buildings] Call GetFactories;
		if (count _factories != _countAlive) then {_updateList = true};
	};
	
	_lastSel = lnbCurSelRow _listBox;
	_lastType = _type;
	sleep 0.1;
};
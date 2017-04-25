Private ['_add','_currentUpgrades','_filler','_i','_listBox','_listCosts','_listNames','_listPictures','_listUpgrades','_listAllowed','_u'];
_listCosts = _this select 0;
_listNames = _this select 1;
_listPictures = _this select 2;
_listUpgrades = _this select 3;
_listAllowed = _this select 4;
_filler = _this select 5;
_listBox = _this select 6;
_u = 0;
_i = 0;

_currentUpgrades = (sideJoinedText) Call GetSideUpgrades;

{
	if ((_listUpgrades select _u) <= (_currentUpgrades select 13)) then {
		_add = true;
		if (gearRestriction && !gearInRange) then {
			if !(_listAllowed select _u) then {_add = false};
		};
		if (_add) then {
			lnbAddRow [_listBox,['$'+str (_listCosts Select _u),_x]];
			lnbSetPicture [_listBox,[_i,0],_listPictures select _u];
			lnbSetData [_listBox,[_i,0],_filler];
			lnbSetValue [_listBox,[_i,0],_u];
			_i = _i + 1;
		};
	};
	_u = _u + 1;
} forEach _listNames;

lnbSetCurSelRow [_listBox,0]
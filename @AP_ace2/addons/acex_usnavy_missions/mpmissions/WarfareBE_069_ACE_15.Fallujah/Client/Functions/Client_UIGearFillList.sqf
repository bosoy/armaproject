Private ['_add','_currentGearUpgr','_filler','_get','_i','_listBox','_listNames','_u'];
_listNames = _this select 0;
_filler = _this select 1;
_listBox = _this select 2;
_u = 0;
_i = 0;
_get = [];

_currentGearUpgr = ((sideJoinedText) Call GetSideUpgrades) select 13;

{
	/* Get */
	if (_filler == 'secondary' || _filler == 'all') then {
		_get = (_x+'_W') Call GetNamespace;
		if (isNil '_get') then {
			_get = _x Call GetNamespace;
		};
	} else {
		_get = _x Call GetNamespace;
	};
	
	if !(isNil '_get') then {
		if ((_get select QUERYGEARUPGRADE) <= _currentGearUpgr) then {
			_add = true;
			if (paramGearRestriction && !gearInRange) then {
				if !(_get select QUERYGEARALLOWED) then {_add = false};
			};
			if (_add) then {
				lnbAddRow [_listBox,['$'+str (_get Select QUERYGEARCOST),(_get select QUERYGEARLABEL)]];
				lnbSetPicture [_listBox,[_i,0],_get select QUERYGEARPICTURE];
				lnbSetData [_listBox,[_i,0],_filler];
				lnbSetValue [_listBox,[_i,0],_u];
				_i = _i + 1;
			};
		};
	};
	_u = _u + 1;
} forEach _listNames;

lnbSetCurSelRow [_listBox,0]
private ["_get","_limit","_newMagSpace","_newMagSideInv","_mag","_magazines","_size"];
_magazines = _this select 0;
_mag = _this select 1;
_size = 0;
_limit = 12;

_get = _mag Call GetNamespace;
_newMagSpace = _get select QUERYGEARSPACE;
_newMagSideInv = _get select QUERYGEARHANDGUNPOOL;
_limit = if (_newMagSideInv) then {8} else {12};

if (_newMagSideInv) then {
	{
		_get = _x Call GetNamespace;
		
		if !(isNil '_get') then {
			if (_get select QUERYGEARHANDGUNPOOL) then {
				_size = _size + (_get select QUERYGEARSPACE);
			};
		};
	} forEach _magazines;	
} else {
	{
		_get = _x Call GetNamespace;
		
		if !(isNil '_get') then {
			if !(_get select QUERYGEARHANDGUNPOOL) then {
				_size = _size + (_get select QUERYGEARSPACE);
			};
		};
	} forEach _magazines;	
};	

if (_size + _newMagSpace <= _limit) then {_magazines = _magazines + [_mag]};
_magazines
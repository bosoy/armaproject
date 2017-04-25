Private ['_freeSpace','_futureSpace','_get','_limit','_magazines','_newMag','_newMagIsSide','_newMagSpace','_oldMags','_presentMags','_replacement','_rlIndex','_size','_spaceToReduce','_totalToReplace','_z'];
_newMag = _this select 0;
_oldMags = _this select 1;
_magazines = _this select 2;

_presentMags = [];
_replacement = [];
_size = 0;
_spaceToReduce = 0;

_get = _newMag Call GetNamespace;
_newMagSpace = _get select QUERYGEARSPACE;
_newMagIsSide = _get select QUERYGEARHANDGUNPOOL;
_limit = if (_newMagIsSide) then {8} else {12};

{
	Private['_cmag','_ct'];
	_cmag = _x;
	_ct = {_x == _cmag} count _oldMags;
	
	if (_ct > 0) then {
		_get = _cmag Call GetNamespace;
		_presentMags = _presentMags + [_cmag];
		_spaceToReduce = _spaceToReduce + (_get select QUERYGEARSPACE);
	};
} forEach _magazines;

if (_newMagIsSide) then {
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

_totalToReplace = count _presentMags;
_freeSpace = _size - _spaceToReduce;

_futureSpace = _totalToReplace * _newMagSpace;
while {(_futureSpace + _freeSpace) > _limit} do {
	_totalToReplace = _totalToReplace - 1;
	_futureSpace = _totalToReplace * _newMagSpace;
};

for [{_z = 0},{_z < _totalToReplace},{_z = _z + 1}] do {_replacement = _replacement + [_newMag]};

_magazines = (_magazines - _presentMags) + _replacement;

_magazines
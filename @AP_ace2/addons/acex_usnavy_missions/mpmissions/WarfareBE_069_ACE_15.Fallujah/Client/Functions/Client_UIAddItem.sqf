Private ['_items','_limit','_mag','_size'];
_items = _this select 0;
_mag = _this select 1;
_size = 0;
_limit = 12;

{_size = _size + 1} forEach _items;

if (_size + 1 <= _limit) then {_items = _items + [_mag]};

_items
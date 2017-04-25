#include "script_component.hpp"
// Idea: Allow to specify the limits yourself (max items, max submenu's, max menu's)


private ["_info", "_limits", "_i", "_j", "_k", "_l", "_ar", "_c", "_entry", "_items", "_subItems", "_name", "_table", "_labels", "_MenuStructureArray", "_mainItems", "_type"];
_items = []; _subItems = []; _MenuStructureArray = []; _mainItems = [];
_i = 0;
_j = 0;
_k = 0;
_l = 0; // set one higher since the first entry is the collumn headers

PARAMS_1(_ar);
_c = count _ar; // not -1 since we need to keep the limit + 1

_labels = _this select 1;
_info = _this select 2; // ["ace_sys_characters_menu", "Select Character", "ace_sys_characters_menu"];
_type = _this select 3;
if (count _this > 4) then {
	_limits = _this select 4;
} else {
	_limits = [20, 20, 20];
};

_f3 = {
	while { _k < (_limits select 2) && _l < _c } do {
		_entry = _ar select _l;
		_t = 0; {
			if (_t == 0) then {
				_name = format["%1", _entry select _x];
				_t = 1;
			} else {
				_name = format["%1, %2", _name, _entry select _x];
			};
		} forEach _labels;
		_items = _items +
		[
			[ ["Item", _name], ["Action", format["[3, %1] spawn %2", _entry, _info select 0]], ["Close", false] ]
		];
		_k = _k + 1;
		_l = _l + 1;
	};
};

if (_type == 3) exitWith { call _f3; [_MenuStructureArray, _items] };

_f2 = {
	while { _j < (_limits select 1) && _l < _c } do {
		call _f3;
		if (_k > 0) then {
			_name = format["%3_%1_%2", _i, _j, _info select 2];
			_MenuStructureArray = _MenuStructureArray +
			[
				[_name,
					[
					["Caption", format["%2, %1 >", _j, _info select 1]],
					["Items", _items]
					]
			]
			];
			_subItems = _subItems +
			[
				[ ["Item", format["%2, %1 >", _j, _info select 1]], ["SubMenu", _name] ]
			];
		};
		_k = 0;
		_j = _j + 1;
		_items = [];
	};
};

if (_type == 2) exitWith { call _f2; [_MenuStructureArray, _subItems] };

_f1 = {
	while { _i < (_limits select 0) && _l < _c } do {
		call _f2;
		if (_j > 0) then {
			_name = format["%2_%1", _i, _info select 2];
			_MenuStructureArray = _MenuStructureArray +
			[
				[_name,
					[
					["Caption", format["%2, %1 >", _i, _info select 1]],
					["Items", _subItems]
					]
			]
			];
			_mainItems = _mainItems +
			[
				[ ["Item", format["%2, %1 >", _i, _info select 1]], ["SubMenu", _name] ]
			];
		};
		_j = 0;
		_i = _i + 1;
		_subItems = [];
	};
};

call _f1;
[_MenuStructureArray, _mainItems]

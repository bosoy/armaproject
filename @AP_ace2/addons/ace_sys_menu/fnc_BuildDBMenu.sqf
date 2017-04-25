#include "script_component.hpp"
// Idea: Allow to specify the limits yourself (max items, max submenu's, max menu's)


private ["_i", "_j", "_k", "_l", "_ar", "_c", "_entry", "_items", "_subItems", "_name", "_table", "_labels", "_MenuStructureArray", "_mainItems"];
_items = []; _subItems = []; _MenuStructureArray = []; _mainItems = [];
_i = 0;
_j = 0;
_k = 0;
_l = 1; // set one higher since the first entry is the collumn headers

PARAMS_2(_table,_labels);
// Static, just for testing
_ar = _table call SIX_fSqlGet;
_c = count _ar; // not -1 since we need to keep the limit + 1

while { _i < 20 && _l < _c } do {
	while { _j < 20 && _l < _c } do {
		while { _k < 20 && _l < _c } do {
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
				[ ["Item", _name], ["Action", format["[3, '%2', %1] spawn ace_sys_menu_fnc_menuArmaLib", _entry select 0, _table]], ["Close", false] ]
			];
			_k = _k + 1;
			_l = _l + 1;
		};
		if (_k > 0) then {
			_name = format["ace_sys_menu_fnc_menuArmaLib_%1_%2", _i, _j];
			_MenuStructureArray = _MenuStructureArray +
			[
				[_name,
					[
					["Caption", format["Select Record, SubMenu %1 >", _j]],
					["Items", _items]
					]
			]
			];
			_subItems = _subItems +
			[
				[ ["Item", format["Select Record, SubMenu %1 >", _j]], ["SubMenu", _name] ]
			];
		};
		_k = 0;
		_j = _j + 1;
		_items = [];
	};
	if (_j > 0) then {
		_name = format["ace_sys_menu_fnc_menuArmaLib_%1", _i];
		_MenuStructureArray = _MenuStructureArray +
		[
			[_name,
				[
				["Caption", format["Select Record, Menu %1 >", _i]],
				["Items", _subItems]
				]
		]
		];
		_mainItems = _mainItems +
		[
			[ ["Item", format["Select Record, Menu %1 >", _i]], ["SubMenu", _name] ]
		];
	};
	_j = 0;
	_i = _i + 1;
	_subItems = [];
};

[_MenuStructureArray, _mainItems]

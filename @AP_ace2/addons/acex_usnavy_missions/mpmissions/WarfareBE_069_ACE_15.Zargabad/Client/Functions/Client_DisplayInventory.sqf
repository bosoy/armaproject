Private ['_cost','_count','_get','_inventoryGUI','_inventorySlots','_items','_loadout','_misca','_miscInvGUI','_miscItemSlots','_primary','_secondary','_sidearm','_sidearmInvGUI','_sidearmInventorySlots','_slot','_sorted'];
_loadout = _this select 0;
_items = _this select 1;

_inventoryGUI = 3503;
_sidearmInvGUI = 3515;
_miscInvGUI = 3523;

for [{_count = 0},{_count < 12},{_count = _count + 1}] do {CtrlSetText[_inventoryGUI + _count,"\Ca\UI\Data\ui_gear_mag_gs.paa"]};
for [{_count = 0},{_count < 8},{_count = _count + 1}] do {CtrlSetText[_sidearmInvGUI + _count,"\Ca\UI\Data\ui_gear_mag_gs.paa"]};
for [{_count = 0},{_count < 12},{_count = _count + 1}] do {CtrlSetText[_miscInvGUI + _count,"\Ca\UI\Data\ui_gear_eq_gs.paa"]};

_cost = 0;
_slot = 0;
_inventorySlots = [];
_sidearmInventorySlots = [];
_miscItemSlots = [];

_primary = [];
_secondary = [];
_sidearm = [];
_misca = [];

{
	_get = _x Call GetNamespace;

	if !(isNil '_get') then {
		switch (_get select QUERYGEARTYPE) do {
			case 'primary': {_primary = _primary + [_x]};
			case 'secondary': {_secondary = _secondary + [_x]};
			case 'sidearm': {_sidearm = _sidearm + [_x]};
			case 'CfgMagazines': {_misca = _misca + [_x]};
			case 'CfgWeapons': {_misca = _misca + [_x]};
		};
	};

} forEach _loadout;

_sorted = _primary + _secondary + _misca;
_sidearm = _sidearm + _misca;

{
	_get = _x Call GetNamespace;

	if !(isNil '_get') then {
		if (!(_get select QUERYGEARHANDGUNPOOL)) then {
			ctrlSetText[_inventoryGUI + _slot,(_get select QUERYGEARPICTURE)];
			_cost = _cost + (_get select QUERYGEARCOST);
			_slot = _slot + 1;
			_inventorySlots = _inventorySlots + [_x];
			for [{_count = (_get Select QUERYGEARSPACE) - 1},{_count > 0},{_count = _count - 1}] do {
				ctrlSetText[_inventoryGUI + _slot,""];
				_slot = _slot + 1;
				_inventorySlots = _inventorySlots + [""];
			};
		};
	};
} forEach _sorted;

_slot = 0;
	
{
	_get = _x Call GetNamespace;
	
	if !(isNil '_get') then {
		if (_get select QUERYGEARHANDGUNPOOL) then {
			ctrlSetText[_sidearmInvGUI + _slot,(_get select QUERYGEARPICTURE)];
			_cost = _cost + (_get select QUERYGEARCOST);
			_slot = _slot + 1;
			_sidearmInventorySlots = _sidearmInventorySlots + [_x];
			for [{_count = (_get Select QUERYGEARSPACE) - 1},{_count > 0},{_count = _count - 1}] do {
				ctrlSetText[_sidearmInvGUI + _slot,""];
				_slot = _slot + 1;
				_sidearmInventorySlots = _sidearmInventorySlots + [""];
			};
		};
	};
} forEach _sidearm;

_slot = 0;

{
	_get = _x Call GetNamespace;

	if !(isNil '_get') then {
		CtrlSetText[_miscInvGUI + _slot,(_get select QUERYGEARPICTURE)];
		_slot = _slot + 1;
		_miscItemSlots = _miscItemSlots + [_x];
		_cost = _cost + (_get select QUERYGEARCOST);
		for [{_count = (_get Select QUERYGEARSPACE) - 1},{_count > 0},{_count = _count - 1}] do {
			ctrlSetText[_miscInvGUI + _slot,""];
			_slot = _slot + 1;
			_miscItemSlots = _miscItemSlots + [""];
		};
	};
} forEach _items;
	
[_inventorySlots,_sidearmInventorySlots,_miscItemSlots,_cost]
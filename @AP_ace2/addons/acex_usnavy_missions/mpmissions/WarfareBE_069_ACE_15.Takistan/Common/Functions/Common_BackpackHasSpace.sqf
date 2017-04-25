private ["_backpackHasRoom","_bp","_bpContent","_bpItem","_max","_space","_type"];
_bp = _this select 0;
_bpContent = _this select 1;
_bpItem = _this select 2;

_type = _bp;
if (typeName _bp == 'OBJECT') then {_type = typeOf _bp};
_max = getNumber(configFile >> 'CfgVehicles' >> _type >> 'transportMaxMagazines');

_space = 0;
for '_u' from 0 to count(_bpContent select 0)-1 do {
    _space = _space + (ceil (getNumber(configFile >> 'CfgMagazines' >> ((_bpContent select 0) select _u) >> 'type') / 256)) * ((_bpContent select 1) select _u);
};

_backpackHasRoom = if ((ceil(getNumber(configFile >> 'CfgMagazines' >> _bpItem >> 'type') / 256)) + _space > _max) then {false} else {true};
_backpackHasRoom
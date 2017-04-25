#include "script_component.hpp"

//map checker
//run from the xeh, and runs once
//checks mapgridposition against other known 6 digit grids that I compute


//Get position of player
_playerPos = mapGridPosition player;
_pos = getPos player;

_armaGrid = parseNumber _playerPos; //6 digit Arma Grid to check against

//GRID
_x = _pos select 0;
_y = _pos select 1;

//chernarus
_xgrid = floor (_x / 100);
_ygrid = floor ((15360 - _y) / 100);
if (_xgrid < 0) then {_xgrid = _xgrid + 9999;};
if (_ygrid < 0) then {_ygrid = _ygrid + 9999;};
_dagrGrid = _xgrid * 1000 + _ygrid;

if (_dagrGrid == _armaGrid) exitwith {Dagr_Map_Info = "chernarus";};

//utes
_xgrid = floor (_x / 100);
_ygrid = floor ((5120 - _y) / 100);
if (_xgrid < 0) then {_xgrid = _xgrid + 9999;};
if (_ygrid < 0) then {_ygrid = _ygrid + 9999;};
_dagrGrid = _xgrid * 1000 + _ygrid;

if (_dagrGrid == _armaGrid) exitwith {Dagr_Map_Info = "utes";};

//panthera2 & isladuala
_xgrid = floor (_x / 100);
_ygrid = floor ((10240 - _y) / 100);
if (_xgrid < 0) then {_xgrid = _xgrid + 9999;};
if (_ygrid < 0) then {_ygrid = _ygrid + 9999;};
_dagrGrid = _xgrid * 1000 + _ygrid;

if (_dagrGrid == _armaGrid) exitwith {Dagr_Map_Info = "panthera2";};


//namalsk
_xgrid = floor (_x / 100);
_ygrid = floor ((12800 - _y) / 100);
if (_xgrid < 0) then {_xgrid = _xgrid + 9999;};
if (_ygrid < 0) then {_ygrid = _ygrid + 9999;};
_dagrGrid = _xgrid * 1000 + _ygrid;

if (_dagrGrid == _armaGrid) exitwith {Dagr_Map_Info = "namalsk";};

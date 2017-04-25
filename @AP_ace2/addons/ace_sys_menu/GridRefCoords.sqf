#include "script_component.hpp"
comment "Cheetah, 6th of January 2007 - contact: forum www.ofpec.com or cheetah99 [at] hotmail [dot] com";
comment "Modified by Dr_Eyeball to handle position parameter";
comment "Modified v1.02, 21 May 2007";

private ["_pos", "_x", "_upperArray", "_lowerArray", "_numberArray", "_xLeft", "_yLeft", "_s1", "_s2", "_s3", "_s4", "_xCoordB", "_xCoordS", "_yCoordB", "_yCoordS", "_coord"];

if (typeName _this != "array") exitWith { format["Invalid parameter: %1", _this] };
if (count _this != 1) exitWith { format["Invalid parameter: %1", _this] };

// Pass in array of 1 parameter: either position or unit.
if (typeName (_this select 0) == "array") then { // position parameter: [[x,y,z]]
  if (count (_this select 0) == 3) then {
    _pos = _this select 0
  }
    else {
    hint format["GridRefCoords.sqf: Invalid params: %1", _this];
    _pos = [0, 0, 0];
  };
} else { // single unit parameter: [<unit>]
  if ((typeName (_this select 0) == "object") && {(count _this == 1)}) then {
    _pos = getPos (_this select 0);
  }
  else {
    hint format["GridRefCoords.sqf: Invalid params: %1", _this];
    _pos = [0, 0, 0];
  };
};
_xLeft = _pos select 0;
_yLeft = _pos select 1;

_upperArray = ["V", "W", "X", "Y", "Z", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P"];
_lowerArray = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j"];
_numberArray = ["4", "3", "2", "1", "0", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0", "9", "8", "7", "6"];
_numbersArray = ["1", "0", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0", "9"];

_s1 = -10000;
_s2 = -8000;
_s3 = 0;

while { (_xLeft >= _s1) } do {
  if (abs(_xLeft) < _s2) then {
    if (_xLeft > 0) then {
      _xLeft = _xLeft - ((_s3-5) * 2000);
    };
  };

  _s1 = _s1 + 2000;
  _s2 = _s2 + 2000;
  _s3 = _s3 + 1;

};

if (abs(_xLeft) >= 2000) then {
  _xLeft = _xLeft + (abs(_s3-5) * 2000);
  _x = 1;
};
_s4 = (abs(_xLeft) / 200);
_s4 = (_s4 - (_s4 mod 1));
_xCoordB = (_upperArray select (_s3-1));
if (_x == 1) then { _s4 = 9-_s4; };
if (_xCoordB == "Z") then { _s4 = 9-_s4; };
_xCoordS = (_lowerArray select _s4);

_s1 = -9520;
_s2 = -7520;
_s3 = 0;

while { (_yLeft >= _s1) } do {
  if (_yLeft < _s2) then {

  if (_yLeft < 0) then {
    _yLeft = _yLeft + (_s3 * 2000);
    _yLeft = _yLeft * -1;
  }
  else {
    _yLeft = _yLeft - ((_s3-5) * 2000);
    };
  };

  _s1 = _s1 + 2000;
  _s2 = _s2 + 2000;
  _s3 = _s3 + 1;
};
_s4 = ((_yLeft-80) / 200);
_yCoordSIndex = (_s4 - (_s4 mod 1)); if (_yCoordSIndex < 0) then { _yCoordSIndex = 0 }; // range checks
_yCoordBIndex = (_s3-1); if (_yCoordBIndex < 0) then { _yCoordBIndex = 0 }; // range checks
//["GridRefCoords.sqf", format["_yCoordSIndex = %1", _yCoordSIndex]] call fn_DebugAppend;
_yCoordS = (_numbersArray select _yCoordSIndex);
_yCoordB = (_numberArray select _yCoordBIndex);

_coord = format ["%1%2%3%4", _xCoordB,_xCoordS,_yCoordB,_yCoordS];
_coord

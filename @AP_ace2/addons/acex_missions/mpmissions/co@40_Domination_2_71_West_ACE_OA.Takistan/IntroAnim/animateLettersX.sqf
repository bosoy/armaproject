#define THIS_FILE "animateLettersX.sqf"
#include "x_setup.sqf"
private ["_string","_line","_chars","_pre_spaces","_out_chars"];

PARAMS_3(_pre_spaces,_string,_line);

_chars = toArray _string;
_out_chars = [];

for "_i" from 1 to _pre_spaces do {_out_chars set [count _out_chars, " "]};

for "_i" from 0 to ((count _chars) - 1) do {_out_chars set [count _out_chars, toString [_chars select _i]]};

if (count _out_chars < 30) then {for "_i" from ((count _out_chars) + 1) to 30 do {_out_chars set [count _out_chars, " "]}};

[_out_chars, _line] execVM "IntroAnim\animateLetters.sqf";
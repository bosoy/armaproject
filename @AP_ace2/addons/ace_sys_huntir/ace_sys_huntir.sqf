#include "script_component.hpp"

#define __typeWriter_delay 0.05

if ((player call CBA_fnc_getUnitAnim) select 0 == "stand") then {
	player playMove "AmovPercMstpSrasWrflDnon_diary";
};

13521 cutText["","BLACK",0];
createDialog "ace_huntir_cam_dialog_off";
sleep 1;
if (!dialog) exitWith {13521 cutText["","PLAIN",0]; false};
closedialog 0;
createDialog "ace_huntir_cam_dialog_inactive";
uiNameSpace setVariable ["ace_huntir_monitor", findDisplay 18881];

sleep .5;

_t5 = time + 5;
_t10 = time + 10;

while { dialog && {(_t5 > time) || {(_t10 > time && {(count ((position player) nearEntities ["ACE_HuntIR", 2000])) == 0})}} } do {
	_message = "";
	_messageFinal = ["S","e","a","r","c","h","i","n","g",".",".",".",".","."];
	for "_i" from 0 to (count _messageFinal - 1) do {
		_message = _message + (_messageFinal select _i);
		ctrlSetText [1, _message];
		sleep __typeWriter_delay;
	};
};



if (dialog && {_t10 <= time} && {(count ((position player) nearEntities ["ACE_HuntIR", 2000])) == 0}) exitWith {
	ctrlSetText [1, "No GDS System detected"];
	sleep 3;
	closedialog 0;
	13521 cutText["","PLAIN"];
};

if ((count ((position player) nearEntities ["ACE_HuntIR", 2000])) > 0) exitWith {
	_c = 0;
	while { dialog && {_c < 5} } do {
		_message = "";
		_messageFinal = ["C","o","n","n","e","c","t","i","n","g",".",".",".",".","."];
		for "_i" from 0 to (count _messageFinal - 1) do {
			_message = _message + (_messageFinal select _i);
			ctrlSetText [1, _message];
			sleep __typeWriter_delay;
		};
		_c = _c + 1;
	};
	if (!dialog) exitWith { 13521 cutText["","PLAIN",0]; false; };
	[(((position player) nearEntities ["ACE_HuntIR", 2000]) select 0)] spawn FUNC(cam);
};
13521 cutText["","PLAIN"];

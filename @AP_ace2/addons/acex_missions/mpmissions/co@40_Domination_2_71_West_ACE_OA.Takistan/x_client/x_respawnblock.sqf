// by Alex4 (fru)
#define THIS_FILE "x_respawnblock.sqf"
#include "x_setup.sqf"

disableSerialization;

sleep 10;

while {true} do {
	waitUntil {sleep 0.121;!isnull (findDisplay 49)};

	_ctrl = (findDisplay 49) displayCtrl 1010; //respawn control
	//_ctrl ctrlSetEventHandler ["ButtonClick", 'if ((side d_pl_killer == side player) || ((time - d_pl_killer_t) > 20)) then {d_pl_killer = objNull}; if (alive player) then {player SetDamage 1;};'];
	_ctrl ctrlEnable false;
#ifdef __TT__
	_ctrl = (findDisplay 49) displayCtrl 104; // exit control
	_ctrl ctrlEnable false;
#endif

	_enCtrl = [] spawn {
		disableSerialization;
		
		_ctrl = (findDisplay 49) displayCtrl 1010;
		_stext = ctrlText _ctrl;
#ifdef __TT__
		_ctrl2 = (findDisplay 49) displayCtrl 104;
		_stext2 = ctrlText _ctrl2;
#endif
		for "_i" from 10 to 1 step -1 do {
			if (isnull (findDisplay 49)) exitWith {};	
			_text = _stext + format ["(%1)",_i]; _ctrl ctrlSetText _text;
#ifdef __TT__
			_text2 = _stext2 + format ["(%1)",_i]; _ctrl2 ctrlSetText _text2;
#endif
			sleep 1;
		};
		if (!isnull (findDisplay 49)) then {
			_ctrl ctrlSetText _stext; _ctrl ctrlEnable true;
#ifdef __TT__
			_ctrl2 ctrlSetText _stext2; _ctrl2 ctrlEnable true;
#endif
		};
	};

	waitUntil {isNull (findDisplay 49)};
	if (!scriptDone _enCtrl) then {terminate _enCtrl};
};
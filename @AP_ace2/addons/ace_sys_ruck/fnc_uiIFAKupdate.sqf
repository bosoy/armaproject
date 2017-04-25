//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

scopeName "script";
disableSerialization;
PARAMS_1(_unit);
DEFAULT_PARAM(1,_display,displayNull);
DEFAULT_PARAM(2,_trynum,0);
private ["_cntlP", "_cntlC", "_cntlT", "_typesIFAK", "_def", "_ifakcnt", "_x", "_ifakdiff"];

/*
Hide (as if stored {freeing up slots}) medicals items up to the capacity of the IFAK kit / holder and show counts on the gear display instead.
When the display is first opened and as you add medical items, the IFAK will (re)move magazine / items if there is room and track that with the contents array.
When the display is closed, the contents array will be zeroed out as the magazines are readded.
*/

if !(_unit isKindOf "Man") exitWith {};

if ( ! isNil QGVAR(IFAK_inpro) ) then { //single instance
	if ( isNull _display && {_trynum < 3} ) then { //make sure the readd (onUnload event) always runs
		[[_unit,_display,(_trynum + 1)], {_this call FUNC(uiIFAKupdate)}] call cba_common_fnc_directCall;
	};
	breakOut "script";
};
GVAR(IFAK_inpro) = true;

///controls
//pictures
_cntlP = [
        _display displayCtrl ACE_IFAK_1P_IDC,
        _display displayCtrl ACE_IFAK_2P_IDC,
        _display displayCtrl ACE_IFAK_3P_IDC
    ];
//counts
 _cntlC = [
        _display displayCtrl ACE_IFAK_1C_IDC,
        _display displayCtrl ACE_IFAK_2C_IDC,
        _display displayCtrl ACE_IFAK_3C_IDC
    ];
//tooltips
_cntlT = [
        _display displayCtrl ACE_IFAK_1T_IDC,
        _display displayCtrl ACE_IFAK_2T_IDC,
        _display displayCtrl ACE_IFAK_3T_IDC
    ];

_ifak_stuff = _unit call FUNC(detIFAK);
_typesIFAK = _ifak_stuff select 0; //__IFAK_TYPES; //items represented
_namesIFAK = _ifak_stuff select 1; //__IFAK_NAMES;


_def = [0,0,0];
__DEF_GETV(_ifakcnt,_unit,"ACE_IFAK_Contents",_def); //method so set command always works with an assigned array

for "_x" from 0 to ((count _typesIFAK) - 1) do { //for each type
	if (time >= 0.1) then {
		if (isNull _display) then { //readd on unload event
			for "_y" from 1 to (_ifakcnt select _x) do {
				_unit addMagazine (_typesIFAK select _x);
				_ifakcnt set [_x, (_ifakcnt select _x) - 1];
			};

		} else { //remove on all updates
			_ifakdiff = 1 - (_ifakcnt select _x);

			for "_y" from 1 to _ifakdiff do {
				if ( (_typesIFAK select _x) in (magazines _unit) ) then {
					_unit removeMagazine (_typesIFAK select _x);
					_ifakcnt set [_x, (_ifakcnt select _x) + 1];
				};
			};

		};
	};

	if ( ctrlText (_cntlP select _x) == "" ) then {
		(_cntlP select _x) ctrlSetText (getText(__CONF_MAGAZINES >> (_typesIFAK select _x) >> "picture"));
		(_cntlT select _x) ctrlSetTooltip (_namesIFAK select _x);

	};

	(_cntlC select _x) ctrlSetText str(_ifakcnt select _x);
};

//{_x ctrlSetFade 0.5; _x ctrlCommit 0; _x ctrlShow true} forEach (_cntlP + _cntlC);

GVAR(IFAK_inpro) = nil;

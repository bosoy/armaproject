//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

disableSerialization;
PARAMS_1(_display);
private ["_boxCtrl", "_boxSize", "_boxWepAry", "_boxMagAry", "_itm", "_txt", "_pic", "_amt", "_pshd"];
sleep 0.5;
if ( isNil QGVAR(BoxCounting) ) then {
	GVAR(BoxCounting) = true;
	_boxCtrl = _display displayctrl AVAILABLE_ITEMS_IDC;
	_boxSize = lnbSize _boxCtrl select 0;
	_boxWepAry = [];
	_boxMagAry = [];
	for "_x" from 0 to _boxSize-1 do {
		_itm = _boxCtrl lnbData [_x, 1];
		_txt = _boxCtrl lnbText [_x, 1];
		_pic = "\" + (_boxCtrl lnbPicture [_x, 1]); //slash to make compare
		_amt = _boxCtrl lnbText [_x, 0];
		if (_amt != "") then {
			_amt = parseNumber _amt;
			_pshd = [_itm,_amt];
			if ( [_itm,_txt,_pic] call FUNC(lnbWep) ) then {
				PUSH(_boxWepAry,_pshd);
			} else {
				PUSH(_boxMagAry,_pshd);
			};
		};
		//TRACE_2("lastbox",_itm,_amt);
	};
	TRACE_2("lastbox",_itm,_amt);
	TRACE_1("BoxCargo",_boxWepAry);
	TRACE_1("BoxCargo",_boxMagAry);
	GVAR(BoxCargo) = [_boxMagAry,_boxWepAry];
	GVAR(BoxCounting) = nil;
};
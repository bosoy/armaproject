_man = _this select 0;
_id = _this select 2;

_man removeAction as1;
_man removeAction as2;
_man removeAction as3;
_man removeAction as4;

if(helo)then{asf1 = _man addAction [localize "STR_MENUHATT","airSup\sendAttHelo.sqf",[], 50, false, false, "", "_target == player"];};
if(trans)then{asf2 = _man addAction [localize "STR_MENUHTRAN","airSup\sendTrans.sqf",[], 40, false, false, "", "_target == player"];};
asf5 = _man addAction [localize "STR_MENUEXT","airSup\sendFixed.sqf",["exit"], 10, false, false, "", "_target == player"];

if(true)exitWith{};
_man = _this select 1;

_man removeAction as1;
_man removeAction as2;
_man removeAction as3;
_man removeAction as4;
_man removeAction as5;

if(true)exitwith{as0 = _man addAction ["Air Support","airSup\addMenu.sqf",[], 10, false, false, "", "_target == player"];};
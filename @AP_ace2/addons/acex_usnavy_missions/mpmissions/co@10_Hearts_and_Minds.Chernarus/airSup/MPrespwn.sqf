_man = _this select 0;
as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
waitUntil{!alive _man};
waitUntil{alive player};
sleep 0.5;
if(true)exitWith{[player] execVM "airSup\MPrespwn.sqf"};
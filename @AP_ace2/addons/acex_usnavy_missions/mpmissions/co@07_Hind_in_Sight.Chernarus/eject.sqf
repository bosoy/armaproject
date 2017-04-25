_group = _this select 0;
_vehicle = _this select 1;

if ( (typename _group != "GROUP") or (typename _vehicle != "OBJECT") ) exitwith {
	hintSilent "Invalid Parameters parsed";
};

sleep 1;

{
	unassignvehicle _x;
	_x action ["EJECT", _vehicle];
	sleep 0.5;
} foreach units _group;
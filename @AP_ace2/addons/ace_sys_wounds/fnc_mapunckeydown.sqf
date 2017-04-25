private "_r";
if (!isMultiplayer) then {
	_r = !((_this select 1) in ([0x01]+(actionKeys "Teamswitch")));
} else {
	_r = ((_this select 1) != 0x01);
};
_r


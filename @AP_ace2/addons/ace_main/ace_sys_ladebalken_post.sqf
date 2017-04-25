if (isMultiplayer) then {
	// add your ID (arma 2 key) here
	// !!!!!!!!!!!!!!!!!!! ONLY FOR ACE DEVS !!!!!!!!!!!!!!!!!!!!!!!!!!
	// the debug console is only available in MP via interaction menu (right windows key) and when you press ESC at the bottom beside the about link
	// you have to add your UID in two places, here and main\fnc_debugadd.sqf
	// no global var because you know what can happen then
	_uids = ["3048774","499842","1142594","1056450","362372","548038","3163142","1216710","1192002","12670726","2000070","3133958","2683782","3049222","1141825"];
	if ((getPlayerUID player) in _uids) then {
		FUNC(dbc_run) = COMPILE_FILE(fnc_dbcrun);
	};
};


ace_sys_wounds_enabled = true;
ace_sys_spectator_can_exit_spectator = true;


94238 cutText [localize "STR_ACE_TUTORIAL_AIR_REFUELING_TITLE","PLAIN",2];


private "_tanker";

_tanker = objNull;

sleep 2;

(localize "STR_ACE_TUTORIAL_AIR_REFUELING_NOTE") hintC [localize "STR_ACE_TUTORIAL_AIR_REFUELING_G_NOTE", localize "STR_ACE_TUTORIAL_AIR_REFUELING_ENABLE_GPS", localize "STR_ACE_TUTORIAL_AIR_REFUELING_DIFFICULT"];

while { true } do {
	sleep 1;
	{
		if (typeof (vehicle _x) == "ACE_HC130_N") then {
			_tanker = _x;
		};
		if !(isNull _tanker) exitWith {};
	} foreach allunits;
	if !(isNull _tanker) exitWith {};
};

sleep 5;

while { true } do {
	sleep 3;
	hintSilent format[localize "STR_ACE_TUTORIAL_AIR_REFUELING_APPROACH", getPosASL _tanker select 2, speed vehicle _tanker];
};

if (dayornight) then {
	dayornight = false;
	publicVariable "dayornight";
	setDate [date select 0, date select 1, date select 2, 0, 0];
} else {
	dayornight = true;
	publicVariable "dayornight";
	setDate [date select 0, date select 1, date select 2, 9, 0];
};
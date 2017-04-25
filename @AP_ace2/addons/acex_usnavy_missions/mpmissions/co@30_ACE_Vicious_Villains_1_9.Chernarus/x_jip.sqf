[] execVM "intro.sqf";

player setVariable ["BIS_noCoreConversations", true];

private ["_diary3", "_diary2", "_diary1", "_str", "_trigger"];

_diary3 = player createDiaryRecord ["Diary", ["Situation", "The war in South zagoria is coming to an end. The ChDKZ forces are continuously losing ground. Last night their retreat came to an end near the coast. All loyal soldiers have regrouped there and are ready for a last stand. NATO forces immediately surrounded them. Now it's time to end this conflict!"]];
_diary2 = player createDiaryRecord ["Diary", ["Enemy", "The insurgents are defending their last positions. They have regrouped in the forest near the coast and are now awaiting an attack."]];
_diary1 = player createDiaryRecord ["Diary", ["Tasks", "Your tasks are clear. Move into the hostile area and clear the key points in the area in order to destabilize the enemy and to end this war!"]];


if (isNil "staroye_clear") then {
	"staroye_clear" addPublicVariableEventHandler {
		task1 settaskstate "Succeeded";
		hint"Well done! Staroye is clear. Now advance to the east.";
	};
} else {
	task1 settaskstate "Succeeded";
};


if (isNil "in_msta") then {
	"in_msta" addPublicVariableEventHandler {
	};
} else {

};


if (isNil "msta_clear") then {
	"msta_clear" addPublicVariableEventHandler {
		task2 settaskstate "Succeeded";
		hint"Well done! Those guys are winded up. Move further to the east. The rest should be child's play!";
	};
} else {
	task2 settaskstate "Succeeded";
};


if (isNil "officer_clear") then {
	"officer_clear" addPublicVariableEventHandler {
		task3 settaskstate "Succeeded";
		hint"Outstanding! You managed to kill evil Ivan!";
	};
} else {
	task3 settaskstate "Succeeded";
};


if (isNil "in_forest") then {
	"in_forest" addPublicVariableEventHandler {
		hint"We found a small camp in the forest... Looks like they had more bases than we expected...";
	};
} else {

};

if (isNil "in_camp") then {
	"in_camp" addPublicVariableEventHandler {

	};
} else {

};


if (isNil "camp_clear") then {
	"camp_clear" addPublicVariableEventHandler {
		task4 settaskstate "Succeeded";
		hint"Wonderful! With the last enemy camp destroyed the war should be over!";
	};
} else {
	task4 settaskstate "Succeeded";
};

if (isNil "end_done") then {
	"end_done" addPublicVariableEventHandler {

	};
} else {

};

_p = player;
 _primw = primaryWeapon _p;
if (_primw != "") then {
	_p selectWeapon _primw;
	//  Fix for weapons with grenade launcher
	_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
	_p selectWeapon (_muzzles select 0);
};

execVM "x_playerweapons.sqf";
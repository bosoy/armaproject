private ["_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str", "_trigger"];

//execVM "Introcam.sqf";

ace_wounds_prevtime = 360;

mando_getpos = compile preprocessFileLineNumbers "Flashlight\Mando_GetPosture.sqf";
DirToObj = compile loadfile "Flashlight\DirToObj.sqf";
"FlashSender" addPublicVariableEventHandler {(_this select 1) execVM "Flashlight\ShowFlash.sqf";};

ID_flsignals = player addaction ["Flashlight Signals", "Flashlight\FlashLightDialog.sqf", [],5, false, true, "", "vehicle player == player"];

if (player hasWeapon "NVGoggles") then {
	player removeWeapon "NVGoggles";
};

execFSM "fsms\RemoveGoogles.fsm";

"tanks" setMarkerAlphaLocal 0;
"aaunit" setMarkerAlphaLocal 0;
"extraction" setMarkerAlphaLocal 0;
"berezino" setMarkerAlphaLocal 0;

_strp = str player;

if (!(_strp in ["lead_1","delta_1","charlie_1","bravo_1","alpha_1","echo_1"])) then {
	if (player hasWeapon "ItemGPS") then {
		player removeWeapon "ItemGPS";
	};
	if (player hasWeapon "Binocular") then {
		player removeWeapon "Binocular";
	};
} else {
	if (!(player hasWeapon "ItemGPS")) then {
		player addWeapon "ItemGPS";
	};
	if (!(player hasWeapon "Binocular")) then {
		player addWeapon "Binocular";
	};
	if (d_WithAcre == 0) then {
		player addWeapon "ACRE_PRC119";
	};
};

if (_strp in ["charlie_3","charlie_7","delta_3","delta_7","bravo_3","bravo_7","alpha_3","alpha_7","echo_3","echo_7"]) then {
	player removeWeapon "M16A4_ACG_GL";
	player addWeapon "M16A4_GL";
	_primw = primaryWeapon player;
    if (_primw != "") then {
        player selectWeapon _primw;
        // Fix for weapons with grenade launcher
        _muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
        player selectWeapon (_muzzles select 0);
    };
} else {
	/*if (player hasWeapon "m16a4") then {
		player removeWeapon "m16a4";
		player addWeapon "M4A1_Aim_camo";
	};*/
	if (_strp in ["lead_1","alpha_1","bravo_1","charlie_1","delta_1","echo_1"]) then {
		if (player hasWeapon "M9") then {
			player removeWeapon "M9";
			player removeMagazines "15Rnd_9x19_M9";
		};
		player addMagazine "ACE_SSWhite_FG";
		player addMagazine "ACE_SSWhite_FG";
		player addMagazine "ACE_SSRed_FG";
		player addMagazine "ACE_SSRed_FG";
		player addMagazine "ACE_SSGreen_FG";
		player addMagazine "ACE_SSGreen_FG";
		player addMagazine "ACE_SSYellow_FG";
		player addMagazine "ACE_SSYellow_FG";
		player addWeapon "ACE_FlareGun";
	};
};

if (isNil "ammo_clear") then {
	"ammo_clear" addPublicVariableEventHandler {
		"tanks" setMarkerAlphaLocal 1;
		"ammo" setMarkerColorLocal "ColorGreen";
		"aaunit" setMarkerAlphaLocal 1;
		[objNull, ObjNull, task1, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		task1 settaskstate "Succeeded";
		task2 = player createSimpleTask ["obj2"];
		task2 setSimpleTaskDescription ["Intel reports that there is an enemy T90 platoon in <marker name=""tanks"">Polana</marker>.<br/>The tank crews are currently resting in a tent camp somewhere in Polana. Sneak in and try to kill the tank crews first before the enemy takes any notice of you.<br/>Otherwise it will get a bloody attack.<br/>Destroy all T90s!","Main target: Destroy tanks","Main target: Destroy tanks"];
		task2 setSimpleTaskDestination markerpos "tanks";
		task2 settaskstate "Created";

		task3 = player createSimpleTask ["obj3"];
		task3 setSimpleTaskDescription ["Beside the tank platoon in Polana intel also found an AA Tunguska unit in <marker name=""aaunit"">Gorka</marker>.<br/>Destroy all Tungis (we don't know the exact number) so that our air units survive a little bit longer.","Main target: Destroy AA unit","Main target: Destroy AA unit"];
		task3 setSimpleTaskDestination markerpos "aaunit";
		task3 settaskstate "Created";
	};
} else {
	"ammo" setMarkerColorLocal "ColorGreen";
	"tanks" setMarkerAlphaLocal 1;
	"aaunit" setMarkerAlphaLocal 1;
};

if (isNil "t90_clear") then {
	"t90_clear" addPublicVariableEventHandler {
		"tanks" setMarkerColorLocal "ColorGreen";
		[objNull, ObjNull, task2, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		task2 settaskstate "Succeeded";
	};
} else {
	"tanks" setMarkerColorLocal "ColorGreen";
};

if (isNil "tungi_clear") then {
	"tungi_clear" addPublicVariableEventHandler {
		"aaunit" setMarkerColorLocal "ColorGreen";
		[objNull, ObjNull, task3, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		task2 settaskstate "Succeeded";
	};
} else {
	"aaunit" setMarkerColorLocal "ColorGreen";
};

if (isNil "next_phase") then {
	"next_phase" addPublicVariableEventHandler {
		"berezino" setMarkerAlphaLocal 1;
		task4 = player createSimpleTask ["obj4"];
		task4 setSimpleTaskDescription ["As the last task tonight try to make your way back through <marker name=""berezino"">Berezino</marker>.<br/>Clear the city from all enemy presence so that we can take it back.","Main target: Clear Berezino","Main target: Clear Berezino"];
		task4 setSimpleTaskDestination markerpos "berezino";
		task4 settaskstate "Created";
	};
} else {
	"berezino" setMarkerAlphaLocal 1;
};


if (isNil "berezino_clear") then {
	"berezino_clear" addPublicVariableEventHandler {
		"berezino" setMarkerColorLocal "ColorGreen";
		"extraction" setMarkerAlphaLocal 1;
		[objNull, ObjNull, task4, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
		task5 = player createSimpleTask ["obj5"];
		task5 setSimpleTaskDescription ["Now try to reach your <marker name=""extraction"">extraction point</marker>.","Main target: Reach extraction point","Main target: Reach extraction point"];
		task5 setSimpleTaskDestination markerpos "extraction";
		task5 settaskstate "Created";
	};
} else {
	"berezino" setMarkerColorLocal "ColorGreen";
	"extraction" setMarkerAlphaLocal 1;
};

player addEventHandler ["killed",{[_this select 0, _this select 1] execVM "x_scripts\x_checkkill.sqf"}];

[] spawn {
	_endtime = time + 100;
	waitUntil {!(isNil "ace_sys_ruck_fnc_killedEH") || (time >= _endtime)};
	if (!isNil "ace_sys_ruck_fnc_killedEH") then {
		ace_sys_ruck_fnc_killedEH = {};
	};
};

execVM "x_scripts\x_playerweapons.sqf";

if (true) exitWith {};

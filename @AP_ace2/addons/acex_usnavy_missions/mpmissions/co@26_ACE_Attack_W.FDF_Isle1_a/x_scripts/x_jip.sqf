player setVariable ["BIS_noCoreConversations", true];

[] spawn {
	sleep 4;
	playMusic "Ambient08_Reforger";
	titleText ["A t t a c k","PLAIN"];
	sleep 16;
	123 cutRsc ["xx_misc_Xlabel","PLAIN"];
};

if (!isNil "base_clear") then {
	"target1" setMarkerColorLocal "ColorGreen";
	"factory" setMarkerAlphaLocal 1;
	"MAIN Base" setMarkerPosLocal markerPos "new_spawn";
	player setPos markerPos "new_spawn";
} else {
	"base_clear" addPublicVariableEventhandler {
		"target1" setMarkerColorLocal "ColorGreen";
		"factory" setMarkerAlphaLocal 1;
		"MAIN Base" setMarkerPosLocal markerPos "new_spawn";
		hint "Good job...\nThe supply base is ours.\nNow destroy the weapon factory.";
		task2 = player createSimpleTask ["obj2"];
		task2 setSimpleTaskDescription ["Destroy four weapon containers in the enemy <marker name=""factory"">weapon factory</marker> near Tobolsk (two large factory buildings). Be warned, there are a lot of enemy patrols in the area.","Main target: Destroy factory","Main target: Destroy factory"];
		task2 setSimpleTaskDestination markerpos "factory";
		task2 settaskstate "Created";
		task1 settaskstate "Succeeded";
		[objNull, ObjNull, task1, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf";
	};
};

if (!isNil "factory_down") then {
	"factory" setMarkerColorLocal "ColorGreen";
	"target2" setMarkerAlphaLocal 1;
} else {
	"factory_down" addPublicVariableEventhandler {
		"factory" setMarkerColorLocal "ColorGreen";
		"target2" setMarkerAlphaLocal 1;
		hint "The weapon factory is destroyed.\nNow attack Protvino.";
		task3 = player createSimpleTask ["obj3"];
		task3 setSimpleTaskDescription ["Free <marker name=""target2"">Protvino</marker> from all enemy troops.","Main target: Clear Protvino","Main target: Clear Protvino"];
		task3 setSimpleTaskDestination markerpos "target2";
		task3 settaskstate "Created";
		task2 settaskstate "Succeeded";
		[objNull, ObjNull, task2, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf"
	};
};

if (!isNil "main_clear") then {
	"target2" setMarkerColorLocal "ColorGreen";
	"zz3" setMarkerAlphaLocal 1;
} else {
	"main_clear" addPublicVariableEventhandler {
		"target2" setMarkerColorLocal "ColorGreen";
		"zz3" setMarkerAlphaLocal 1;
		hint "Protvino is cleared !!!! Good job.\nProceed to Berezniki.";
		task4 = player createSimpleTask ["obj4"];
		task4 setSimpleTaskDescription ["Free <marker name=""zz3"">Berezniki</marker> from all enemy troops. There might be a lot of resistance on the way there.","Main target: Free Berezniki","Main target: Free Berezniki"];
		task4 setSimpleTaskDestination markerpos "zz3";
		task4 settaskstate "Created";
		task3 settaskstate "Succeeded";
		[objNull, ObjNull, task3, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf"
	};
};

if (rubena_clear) then {
	"zz3" setMarkerColorLocal "ColorGreen";
} else {
	"rubena_clear" addPublicVariableEventHandler {
		"zz3" setMarkerColorLocal "ColorGreen";
		hint "Rubena cleared !!! That's it";
		task4 settaskstate "Succeeded";
		[objNull, ObjNull, task4, "SUCCEEDED"] execVM "CA\Modules\MP\data\scriptCommands\taskHint.sqf"
	};
};

_p = player;
 _primw = primaryWeapon _p;
if (_primw != "") then {
	_p selectWeapon _primw;
	//  Fix for weapons with grenade launcher
	_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
	_p selectWeapon (_muzzles select 0);
};

x_playerspawn = compile preprocessFileLineNumbers "x_scripts\x_playerspawn.sqf";
player addEventHandler ["killed", {[0] call x_playerspawn}];
player addEventHandler ["respawn", {[1] call x_playerspawn;deleteVehicle (_this select 1)}];
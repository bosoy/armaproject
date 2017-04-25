private ["_diary9", "_diary8", "_diary7", "_diary6", "_diary5", "_diary4", "_diary3", "_diary2", "_diary1", "_str", "_trigger"];

[] execVM "intro.sqf";

player setVariable ["BIS_noCoreConversations", true];

if (isNil "AA_1_clear") then {
	"AA_1_clear" addPublicVariableEventHandler {
		"AA" setMarkerColorLocal "ColorGreen";
		task1 settaskstate "Succeeded";
		hint "The AA unit is down!";
	};
} else {
	"AA" setMarkerColorLocal "ColorGreen";
		task1 settaskstate "Succeeded";
};


if (isNil "Target_1_clear") then {
	"Target_1_clear" addPublicVariableEventHandler {
		"Target_1" setMarkerColorLocal "ColorGreen";
		task2 settaskstate "Succeeded";
		hint "The Air Base is clear!";
	};
} else {
	"The Air Base is clear" setMarkerColorLocal "ColorGreen";
		task2 settaskstate "Succeeded";
};


execVM "x_scripts\x_playerinit.sqf";

player addEventHandler ["killed",{[_this select 0, _this select 1] execVM "x_scripts\x_checkkill.sqf"}];

x_repair_service = ["ace_usarmy_sapper","USMC_SoldierS_Engineer"];

if (count x_repair_service > 0) then {
	if ((typeOf player) in x_repair_service) then {
		x_sfunc = compile preprocessFile "x_scripts\x_pservicefunc.sqf";
		d_rep_truck = (
			if (playerSide == east) then {"UralRepair"} else {"MtvrRepair"}
		);
		x_repair_obj = objNull;

		_trigger = createTrigger["EmptyDetector" ,position player];
		_trigger setTriggerArea [0, 0, 0, true];
		_trigger setTriggerActivation ["NONE", "PRESENT", true];
		_trigger setTriggerStatements["call x_sfunc", "rep_actionID = player addAction [""Repair Vehicle"", ""x_scripts\x_repengineer.sqf"",[],-1,false]", "player removeAction rep_actionID"];
	};
	// rep client and server
	rep_array = [];
	XCallRep = {
		private ["_vec"];
		_vec = _this select 0;
		_vec setDamage 0;
		_vec setFuel 1;
	};
	"rep_array" addPublicVariableEventHandler {
		[rep_array select 0] spawn XCallRep;
	};
};

[] spawn {
	_endtime = time + 100;
	waitUntil {!(isNil "ace_sys_ruck_fnc_killedEH") || (time >= _endtime)};
	if (!isNil "ace_sys_ruck_fnc_killedEH") then {
		ace_sys_ruck_fnc_killedEH = {};
	};
};

//execVM "x_scripts\x_playerweapons.sqf";

_p = player;
 _primw = primaryWeapon _p;
if (_primw != "") then {
	_p selectWeapon _primw;
	// Fix for weapons with grenade launcher
	_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
	_p selectWeapon (_muzzles select 0);
};

if (true) exitWith {};
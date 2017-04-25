DAC_Com_Values = [0,0,2];
DAC_Marker = 0;
DAC_Del_PlayerBody = [0,0];
DAC_Dyn_Weather = [300,60,1,0];
DAC_Reduce_Value = [600,650,0];

setTerrainGrid 50;

ace_sys_tracking_markers_enabled = false;
ace_sys_wounds_noai = true;
//ace_wounds_prevtime = 300; // 5 minutes uncon time
ace_sys_spectator_RevShowButtonTime = 150; // after 2 1/2 minutes show button for respawn
ace_sys_wounds_withSpect = true;
ace_sys_aitalk_talkforplayer = true;
ace_sys_wounds_no_rpunish = true;
ace_sys_spectator_no_one_alive = 200;

ace_sys_spectator_RevButtons = ["Respawn Base", "Respawn MHQ"];

x_bike_created = false;
x_immediate_transport = ["ACE_ATV_Honda","MMT_USMC"];

"target2" setMarkerAlphaLocal 0;
"factory" setMarkerAlphaLocal 0;
"zz3" setMarkerAlphaLocal 0;

if (isServer) then {
	X_fnc_arrayPush = compile preprocessFileLineNumbers "x_scripts\x_funcs\x_arrayPush.sqf";
	X_fnc_arrayPushStack = compile preprocessFileLineNumbers "x_scripts\x_funcs\x_arrayPushStack.sqf";
};

X_INIT = false;
X_Server = false; X_Client = false; X_JIP = false;X_SPE = false;

X_MP = isMultiplayer;

if (isServer) then {
	X_Server = true;
	if (!isDedicated) then {
		X_Client = true;X_SPE = true;
	};
	X_INIT = true;
} else {
	X_Client = true;
	if (isNull player) then {
		X_JIP = true;
		[] spawn {waitUntil {!isNull player};X_INIT = true};
	} else {
		X_INIT = true;
	};
};

if (X_Client) then {
	[] spawn {
		waitUntil {!isNull player};
		execVM "tasks_fix.sqf";
	};
	ace_sys_spectator_fnc_rbutton1 = {
		player setDamage 1;
		waitUntil {alive player};
		player setPos (markerPos "MAIN Base");
	};

	ace_sys_spectator_fnc_rbutton2 = {
		player setDamage 1;
		waitUntil {alive player};
		if (!alive x_mobile_resp) then {
			player setPos (markerPos "MAIN Base");
		} else {
			player setPos (markerPos "Mobile HQ");
		};
	};
};

if (isServer) then {
	//execVM "x_scripts\x_serverinit.sqf";
	[rvec, 240,false] execVM "x_respawn_for_bike.sqf";
	[mhq,240] execVM "mobilerrespawn\x_mobilerrespawn.sqf";

	blufor_in = false;
	blufor_in2 = false;
	start_pat = false;
	[] spawn {
		waituntil{!isNil "DAC_Basic_Value"};
		waituntil{DAC_Basic_Value == 1};
		sleep 10;
		[egrp1,3,[z1],6,0,100,[1,1,1],0,false] spawn DAC_fInsertGroup;
		[egrp2,1,[z1],6,0,100,[1,1,1],0,false] spawn DAC_fInsertGroup;
	};
};

DAC_Zone = compile preprocessFileLineNumbers "DAC\Scripts\DAC_Init_Zone.sqf";
DAC_Objects	= compile preprocessFileLineNumbers "DAC\Scripts\DAC_Create_Objects.sqf";
execVM "DAC\DAC_Config_Creator.sqf";

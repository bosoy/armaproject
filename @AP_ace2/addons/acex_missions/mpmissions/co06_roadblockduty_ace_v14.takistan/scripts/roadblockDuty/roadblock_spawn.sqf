//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script spawns different vehicles passing by a roadblock
//////////////////////////////////////////////////////////////////

//INIT
if (!isServer) exitWith{};
private ["_title","_text","_spawn","_end","_go1","_go2","_stop","_arrive","_attack","_rounds","_rnd","_types","_count","_group","_INStypes","_INSgroup","_ENEtypes","_ENEcount","_type","_INStype","_maxN","_debug","_y","_n","_CIVgroup","_trickCar"];

EAST setFriend [WEST, 0];

//Define variables
_debug = 0; //set this to 1 for debug messages
_spawn = getMarkerPos "roadblockduty_spawn";
_end = getMarkerPos "roadblockduty_end";
_go1 = getMarkerPos "roadblockduty_go1";
_go2 = getMarkerPos "roadblockduty_go2";
_stop = getMarkerPos "roadblockduty_stop";
_arrive = getMarkerPos "roadblockduty_arrive";
_attack = getMarkerPos "roadblockduty_attackpos";
_rounds = _this select 0;
if (!isMultiplayer) then {_rounds = 10};

//Define arrays
_types = ["Ikarus_TK_CIV_EP1","Lada1_TK_CIV_EP1","Lada2_TK_CIV_EP1","LandRover_TK_CIV_EP1","VolhaLimo_TK_CIV_EP1","hilux1_civil_3_open_EP1","S1203_TK_CIV_EP1","SUV_TK_CIV_EP1","Ural_TK_CIV_EP1","V3S_Open_TK_CIV_EP1","Volha_1_TK_CIV_EP1","Volha_2_TK_CIV_EP1"];
_count = count _types;

_INStypes = ["TK_INS_Soldier_TL_EP1","TK_INS_Soldier_TL_EP1","TK_INS_Warlord_EP1","TK_INS_Soldier_EP1","TK_INS_Soldier_2_EP1","TK_INS_Soldier_3_EP1","TK_INS_Soldier_4_EP1","TK_INS_Soldier_AT_EP1","TK_INS_Soldier_2_EP1","TK_INS_Soldier_EP1","TK_INS_Soldier_AAT_EP1","TK_INS_Soldier_AR_EP1","TK_INS_Soldier_MG_EP1","TK_INS_Soldier_AA_EP1","TK_INS_Soldier_Sniper_EP1","TK_INS_Soldier_2_EP1","TK_INS_Soldier_EP1","TK_INS_Soldier_MG_EP1","TK_INS_Bonesetter_EP1"];
_INScount = count _INStypes;

_CIVtypes = ["TK_CIV_Worker02_EP1","TK_CIV_Takistani02_EP1","TK_CIV_Worker02_EP1","TK_CIV_Woman01_EP1","TK_CIV_Worker01_EP1","TK_CIV_Takistani03_EP1","TK_CIV_Takistani01_EP1","TK_CIV_Woman03_EP1","TK_CIV_Takistani05_EP1","TK_CIV_Takistani04_EP1","TK_CIV_Takistani06_EP1","TK_CIV_Woman02_EP1"];
_CIVcount = count _CIVtypes;

_ENEtypes = ["LandRover_MG_TK_INS_EP1","LandRover_SPG9_TK_INS_EP1"];
_ENEcount = count _ENEtypes;

//Tutorial hint message
_title  = "<t color='#00ff00' size='1.2' shadow='1' shadowColor='#000000' align='center'>ROADBLOCK DUTY</t><br/><br/>";
_text   = "Vehicles must halt before the roadblock.<br /><br />Use your radio to let them pass once your inspection is complete.";
hintSilent parseText (_title + _text);
sleep random 30;
taskhint ["CURRENT TASK\nRoadblock Duty", [0.80, 0.80, 0, 0.75], "taskNew"];

// Main loop
while {_rounds > 0} do {

  _rnd = floor (random 100);
  //sleep 2000;
  //_rnd = 40;
  
  reezo_roadblockDuty_CLEAR = 0;
  publicVariable "reezo_roadblockDuty_CLEAR";
  if (_debug == 1) then { hint Format["Random value:\n\n%1",_rnd]; sleep 1; };

  // CASE: CIVILIAN VEHICLES
  if (_rnd <= 50) then {
    if (_debug == 1) then { hintSilent "case: civilians" };
  
    /* OLD METHOD
    _type = _types select (floor (random _count));
    _group = createGroup CIVILIAN;
    [_spawn, 0, _type, _group] call bis_fnc_spawnvehicle;
    */
    
    _type = _types select (floor (random _count));
    _CIVcar = createVehicle [_type, _spawn, [], 0, "NONE"];
      
    _CIVgroup = createGroup CIVILIAN;
      
    _maxN = 1 + (floor (random 3));
    
    if (_type == "Ikarus_TK_CIV_EP1" OR _type == "Ural_TK_CIV_EP1") then { _maxN = ((_maxN+2) * 2) };


    for [{_n = 0},{_n < _maxN},{_n = _n + 1}] do {
      _CIVtype = _CIVtypes select (floor (random _CIVcount));
      if (_n == 0) then {
        _CIVtype createUnit [_spawn, _CIVgroup,"this assignasDriver _CIVcar; [this] orderGetIn TRUE;", (random 0.8), "corporal"];
      } else {
        _CIVtype createUnit [_spawn, _CIVgroup,"this assignasCargo _CIVcar; [this] orderGetIn TRUE;", (random 0.8), "private"];
      };
    };

    _CIVgroup setBehaviour "SAFE";

    _CIVgroup addWaypoint [_arrive, 0];
    [_CIVgroup, 0] setWaypointType "MOVE";
    [_CIVgroup, 1] setWaypointSpeed "NORMAL";

    _CIVgroup addWaypoint [_stop, 1];
    [_CIVgroup, 1] setWaypointType "MOVE";
    [_CIVgroup, 1] setWaypointSpeed "NORMAL";
    [_CIVgroup, 1] setWaypointStatements ["true", ""];

    _CIVgroup addWaypoint [_go1, 2];
    [_CIVgroup, 2] setWaypointType "MOVE";
    [_CIVgroup, 2] setWaypointStatements ["reezo_roadblockDuty_CLEAR == 1", ""];
    
    _CIVgroup addWaypoint [_go2, 3];
    [_CIVgroup, 3] setWaypointType "MOVE";

    _CIVgroup addWaypoint [_end, 4];
    [_CIVgroup, 4] setWaypointType "MOVE";
  };
  
  // CASE: CIVILIAN TRICK
  if ((_rnd > 50) && (_rnd <= 80)) then {
    if (_debug == 1) then { hintSilent "case: civilian trick" };  
    
    /* OLD METHOD
    _type = _types select (floor (random _count));
    _group = createGroup EAST;
    [_spawn, 0, _type, _group] call bis_fnc_spawnvehicle;
    */
    
    _type = _types select (floor (random _count));
    _trickCar = createVehicle [_type, _spawn, [], 0, "NONE"];
      
    _INSgroup = createGroup EAST;
    _maxN = 2 + (floor (random 3));
    
    if (_type == "Ikarus_TK_CIV_EP1" OR _type == "Ural_TK_CIV_EP1") then { _maxN = ((_maxN+2) * 2) };

    for [{_n = 0},{_n < _maxN},{_n = _n + 1}] do {
      _INStype = _INStypes select (floor (random _count));
      if (_n == 0) then {
        _INStype createUnit [_spawn, _INSgroup,"officer = this", (random 0.9), "corporal"];      
        officer assignAsDriver _trickCar;
        [officer] orderGetIn true;
        //officer moveinDriver _trickCar;
        _rnd = random 1;
        if (_rnd < 0.5) then { nul0 = [officer,_trickCar,0,50,20,WEST] execVM "scripts\IEDdetect\IEDdetect_triggerman.sqf" };
        } else {
        _INStype createUnit [_spawn, _INSgroup,"insurgent = this", (random 0.9), "private"];
        //insurgent moveinCargo _trickCar;
        insurgent assignAsCargo _trickCar;
        [insurgent] orderGetIn true;
      };
    };

    _rnd = random 1;
      
    if (_rnd < 0.5) then {    
      _INSgroup setCombatMode "YELLOW";
      _INSgroup setBehaviour "AWARE";

      _INSgroup addWaypoint [_arrive, 0];
      //[_INSgroup, 0] setWaypointPosition [_arrive, 0];     
      [_INSgroup, 0] setWaypointType "MOVE";
      [_INSgroup, 0] setWaypointSpeed "NORMAL";
      _INSgroup addWaypoint [_stop, 1];
      [_INSgroup, 1] setWaypointType "MOVE";
      [_INSgroup, 1] setWaypointSpeed "NORMAL";
      _INSgroup addWaypoint [_go1, 2];
      [_INSgroup, 2] setWaypointType "MOVE";
      [_INSgroup, 2] setWaypointSpeed "FULL";
      _INSgroup addWaypoint [_end, 3];
      [_INSgroup, 3] setWaypointType "MOVE";
      [_INSgroup, 3] setWaypointSpeed "FULL";
    } else {
      _INSgroup setCombatMode "YELLOW";
      _INSgroup setBehaviour "COMBAT";

      _INSgroup addWaypoint [_attack,0];
      [_INSgroup, 0] setWaypointType "GETOUT";
      [_INSgroup, 0] setWaypointPosition [_attack, 100];     
      [_INSgroup, 0] setWaypointSpeed "NORMAL";
      [_INSgroup, 0] setWaypointStatements ["true", ""];
      [_INSgroup, 0] setWaypointBehaviour "COMBAT";
      _INSgroup addWaypoint [_attack,1];
      [_INSgroup, 1] setWaypointType "SENTRY";
      [_INSgroup, 1] setWaypointPosition [_attack, 100];     
      [_INSgroup, 1] setWaypointSpeed "NORMAL";
      [_INSgroup, 1] setWaypointStatements ["true", ""];
      [_INSgroup, 1] setWaypointBehaviour "COMBAT";
    };
  };
  
  // CASE: CARBOMB
  if ((_rnd > 80) && (_rnd <= 90)) then {
    if (_debug == 1) then { hintSilent "case: carbomb" };  
    
    _type = _types select (floor (random _count));
    _group = createGroup CIVILIAN;
    _IEDcar = _type createVehicle _spawn;
    _CIVtype = _CIVtypes select (floor (random _CIVcount));
    _triggerman = _group createUnit [_CIVtype, _spawn, [], 0, "NONE"];
    _triggerman assignAsDriver _IEDcar;
    _triggerman moveinDriver _IEDcar;
    nul0 = [_triggerman,_IEDcar,0,60,15,WEST] execVM "scripts\IEDdetect\IEDdetect_triggerman.sqf";
    
    /*[_spawn, 0, _type, _group] call bis_fnc_spawnvehicle;
    
    _nearVEH = _spawn nearObjects ["Car",50];
    for [{_y = 0},{_y < (count _nearVEH)},{_y = _y + 1}] do {
      {
        
      } forEach (units _group);
    };
    */
      
    _group setBehaviour "SAFE";
    //nul0 = [(leader _group)] execVM "scripts\IEDdetect\IEDdetect_carbomb.sqf";

    _group addWaypoint [_arrive, 0];
    [_group, 0] setWaypointType "MOVE";

    _group addWaypoint [_stop, 1];
    [_group, 1] setWaypointType "MOVE";
    [_group, 1] setWaypointSpeed "LIMITED";
    [_group, 1] setWaypointStatements ["true", ""];

    _group addWaypoint [_go1, 2];
    [_group, 2] setWaypointType "MOVE";
    [_group, 2] setWaypointStatements ["reezo_roadblockDuty_CLEAR == 1", ""];
    
    _group addWaypoint [_go2, 3];
    [_group, 3] setWaypointType "MOVE";

    _group addWaypoint [_end, 4];
    [_group, 4] setWaypointType "MOVE";
  };
  
  // CASE: INSURGENT VEHICLES
  if (_rnd > 90) then {
    if (_debug == 1) then { hintSilent "case: enemies" };  
    
    _ENEtype = _ENEtypes select (floor (random _ENEcount));
    _ENEgroup = createGroup EAST;
    [_spawn, 0, _ENEtype, _ENEgroup] call bis_fnc_spawnvehicle;

    _ENEgroup setCombatMode "YELLOW";
    _ENEgroup setBehaviour "COMBAT";
    
    _ENEgroup addWaypoint [_arrive,150,0];
    [_ENEgroup, 0] setWaypointType "SAD";
    [_ENEgroup, 0] setWaypointSpeed "FULL";
    [_ENEgroup, 0] setWayPointBehaviour "COMBAT";
  };

  sleep 120;
  sleep random 300;
  deleteGroup _group;
  deleteGroup _INSgroup;
  deleteGroup _CIVgroup;
  deleteGroup _ENEgroup;
  _rounds = _rounds - 1;
};

// TASK COMPLETED
OBJ_REEZO_ROADBLOCKDUTY setTaskState "SUCCEEDED";
taskhint ["COMPLETED TASK\nRoadblock Duty", [0, 1, 0, 0.75], "taskDone"];

if (true) exitWith{};
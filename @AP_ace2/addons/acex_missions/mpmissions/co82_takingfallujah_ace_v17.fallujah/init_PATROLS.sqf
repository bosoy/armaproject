//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Radio Tower creation script by Pirin
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

_x = 0;
_max = 20;

if (isServer && isMultiplayer) then { _max = paramsArray select 12; };

while {_x != _max} do {

  // get starting spot and range
  _marker = _this select 0;
  _radius = _this select 1;
  _pos = getmarkerpos _marker;
  //_radius = 100;

  // Find a good spot for the spawn (open area, not in trees)
  //_exp = "(1 + meadow) * (1 - forest) * (1 - trees)"; OLD PARAMETER, DOESN'T WORK WELL WITH FALLUJAH
  _exp = "1";
  _prec = 100;
  _bestplace = selectBestPlaces [_pos,_radius,_exp,_prec,1];
  _spot = _bestplace select 0;
  _spot2 = _spot select 0;

  // Create the officer and his escort
  
  _groupname = format["PATROLgrp_%1", _x];
  _groupname = createGroup EAST;
  _patrol1 = format["PATROL1_%1", _x];
  _patrol2 = format["PATROL2_%1", _x];
  _patrol3 = format["PATROL3_%1", _x];
  _patrol4 = format["PATROL4_%1", _x];
  _patrol5 = format["PATROL5_%1", _x];
  _patrol6 = format["PATROL6_%1", _x];

  _happening = random 1;
  if (_happening < 0.70) then {
    _patrol1 = _groupname createUnit ["TK_Soldier_SL_EP1", _spot2, [], 0, "NONE"];
    _patrol2 = _groupname createUnit ["TK_Soldier_AR_EP1", _spot2, [], 0, "NONE"];
    _patrol3 = _groupname createUnit ["TK_Soldier_Medic_EP1", _spot2, [], 0, "NONE"];
    _patrol4 = _groupname createUnit ["TK_Soldier_AT_EP1", _spot2, [], 0, "NONE"];
    _patrol5 = _groupname createUnit ["TK_Soldier_AMG_EP1", _spot2, [], 0, "NONE"];
    _patrol6 = _groupname createUnit [" TK_Soldier_GL_EP1", _spot2, [], 0, "NONE"];
  } else {
    _patrol1 = _groupname createUnit ["TK_INS_Soldier_TL_EP", _spot2, [], 0, "NONE"];
    _patrol2 = _groupname createUnit ["TK_INS_Soldier_AR_EP1", _spot2, [], 0, "NONE"];
    _patrol3 = _groupname createUnit ["TK_INS_Bonesetter_EP1", _spot2, [], 0, "NONE"];
    _patrol4 = _groupname createUnit ["TK_INS_Soldier_AT_EP1", _spot2, [], 0, "NONE"];
    _patrol5 = _groupname createUnit ["TK_INS_Soldier_AA_EP1", _spot2, [], 0, "NONE"];
    _patrol6 = _groupname createUnit ["TK_INS_Soldier_EP1", _spot2, [], 0, "NONE"];
  };
  
  _patrol1 setRank "CORPORAL";

  waituntil {!isnil "bis_fnc_init"};
  [_groupname, _marker, _radius] call bis_fnc_taskPatrol;

  _x = _x + 1;

};

if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_PATROLS COMPLETED";
  sleep 1;
};

if (true) exitWith{};
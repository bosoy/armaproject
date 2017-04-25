//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Radio Tower creation script by Pirin
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

_x = 0;
_max = 20;

if (isServer && isMultiplayer) then { _max = paramsArray select 10; };

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

  // Create the armored unit and his escort
  //_GROUPname = format["ARMORED_%1", _x];
  //_GROUPname = createGroup EAST;

  _skins = ["BMP2_TK_EP1","BMP2_HQ_TK_EP1","BRDM2_TK_EP1","BRDM2_ATGM_TK_EP1","BTR60_TK_EP1","M113_TK_EP1","T34_TK_EP1","T55_TK_EP1","T72_TK_EP1","BTR40_TK_INS_EP1","BTR40_MG_TK_INS_EP1"];
  _rnd = floor (random 11);
  _type = _skins select _rnd;
  _dir = random 360;
  
  waituntil {!isnil "bis_fnc_init"}; 
  [_spot2, _dir, _type, EAST] call bis_fnc_spawnvehicle;
  
  _x = _x + 1;
  
};

if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_ARMORED COMPLETED";
  sleep 1;
};

if (true) exitWith{};
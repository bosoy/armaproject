//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script creates some random civilians around spawn points.
// It is a desperate solution when ALICE does not work.
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

_x = 0;
_max = 50;

if (isMultiplayer) then { _max = paramsArray select 13; };

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
  _skins = ["TK_CIV_Takistani03_EP1","TK_CIV_Takistani04_EP1","TK_CIV_Takistani02_EP1","TK_CIV_Takistani05_EP1","TK_CIV_Takistani01_EP1","TK_CIV_Takistani06_EP1","TK_CIV_Worker02_EP1","TK_CIV_Worker01_EP1","TK_CIV_Woman01_EP1","TK_CIV_Woman02_EP1","TK_CIV_Woman03_EP1"];
  _rnd = floor (random 11);
  _type = _skins select _rnd;

  _unitname = format["civvie_%1", _x];
  _unitname = grpNull createUnit [_type, _spot2, ["dostop this"], 0, "NONE"];

  _x = _x + 1;
  sleep 0.1;
  
};

if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_CIVVIES COMPLETED";
  sleep 1;
};

if (true) exitWith{};
//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Radio Tower creation script by Pirin
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

_x = 0;
_max = 20;

if (isServer && isMultiplayer) then { _max = paramsArray select 11; };

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
  _skins = ["TK_Soldier_Sniper_EP1","TK_Soldier_SniperH_EP1","TK_Soldier_Sniper_Night_EP1","TK_INS_Soldier_Sniper_EP1"];
  _rnd = floor (random 4);
  _type = _skins select _rnd;

  _unitname = format["sniper_%1", _x];
  _unitname = grpNull createUnit [_type, _spot2, [], 0, "NONE"];

  _x = _x + 1;
  
};

if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_SNIPERS COMPLETED";
  sleep 1;
};

if (true) exitWith{};
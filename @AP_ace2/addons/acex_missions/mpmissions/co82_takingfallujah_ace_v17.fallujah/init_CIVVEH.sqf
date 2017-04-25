//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Radio Tower creation script by Pirin
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

_x = 0;
_max = 50;

if (isServer && isMultiplayer) then { _max = paramsArray select 13; };

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
  _skins = ["Ikarus_TK_CIV_EP1","Lada1_TK_CIV_EP1","Lada2_TK_CIV_EP1","LandRover_TK_CIV_EP1","TT650_TK_CIV_EP1","Old_bike_TK_CIV_EP1","Old_moto_TK_Civ_EP1","hilux1_civil_3_open_EP1","S1203_TK_CIV_EP1","SUV_TK_CIV_EP1","UAZ_Unarmed_TK_CIV_EP1","Ural_TK_CIV_EP1","V3S_Open_TK_CIV_EP1","Volha_1_TK_CIV_EP1","Volha_2_TK_CIV_EP1","VolhaLimo_TK_CIV_EP1"];
  _rnd = floor (random 16);
  _type = _skins select _rnd;

  _unitname = format["civveh_%1", _x];
  _unitname = _type createVehicle _spot2;


  _x = _x + 1;
  
};

if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_CIVVEH COMPLETED";
  sleep 1;
};

if (true) exitWith{};
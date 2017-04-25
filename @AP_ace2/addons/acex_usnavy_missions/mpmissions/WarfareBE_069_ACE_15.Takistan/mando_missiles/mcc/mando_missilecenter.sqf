/*
 mando_missilecenter.sqf
 By Mandoble Sep 2009

Purpose:
   Activates an MCC using the provided parameters   
   While you may execute this script directly, it is automatically executed by these in the mcc_types folder with missile and firing parameters predefined for some unit types.

Examples:
*/
private["_launcher", "_posrelcontrol", "_targettypes", "_scanrange", "_scanfreq", "_antimissile", "_missileparams", "_sounds", "_fixeddir", "_missileidx", "_backcolor", "_scanstoload", "_delaysoff", "_delayson","_ok", "_j", "_i"];

MCC_DLGMISSILECENTER	= 21900;
MCC_MAP                 = 21902;
MCC_CONTACTLIST	        = 21903;
MCC_HELP                = 21944;
MCC_NOMAP		= 21906;
MCC_MAPCONTACT		= 21907;
MCC_MAPTARGET		= 21908;
MCC_MAPMCC              = 21941;
MCC_NAVMARK             = 21942;


_launcher      = _this select 0;
_posrelcontrol = _this select 1;
_targettypes   = _this select 2;
_scanrange     = _this select 3;
_scanfreq      = _this select 4;
_antimissile   = _this select 5;
_missileparams = _this select 6;
_sounds        = _this select 7;
_fixeddir      = _this select 8;
_missileidx    = _this select 9;
_backcolor     = _this select 10;
_scanstoload   = _this select 11;


_delaysoff = [0.2,0.2,0.2,0.2];
_delayson = [0.1,0.1,0.1,0.1];


if ((_sounds select 0) != "") then
{
   _launcher say (_sounds select 0);
};


_launcher setVariable ["mando_target", objNull];
_launcher setVariable ["mando_contact", objNull];
_launcher setVariable ["mando_mccstate", 1];

mando_navmark=0;
mando_map=0;

mando_missile_camera=false;
mando_missile_camera_zoom = 1.0;
mando_firemissile=false;
mando_gettarget=false;
mando_getcontact=false;

Sleep 1;
if (isNil "mando_mccmark") then
{
   mando_mccmark = "Logic" createVehicleLocal [0,0,0];
   mando_mccmark setPos [getPos _launcher select 0,getPos _launcher select 1,0];
};

4 cutText["", "BLACK FADED"];
_ok = createDialog "DlgMissileCenter";
if (!_ok) exitWith {hintSilent "MCC Dialog error"};

ctrlShow [MCC_HELP, false];

[_launcher, _posrelcontrol]execVM mando_missile_path+"mcc\mando_missilecentermap.sqf";
[]execVM mando_missile_path+"mcc\mando_trackmissiledata.sqf";


for [{_j=0},{_j < (count _delayson)},{_j=_j+1}] do
{
   for [{_i=0},{_i < 41},{_i=_i+1}] do
   {
      if ((_i != 36) && (_i != 37)) then
      {
         ctrlShow [MCC_MAP+_i, false];
      };
   };
   Sleep (_delaysoff select _j);
   for [{_i=0},{_i < 41},{_i=_i+1}] do
   {
      if ((_i != 36) && (_i != 37)) then
      {
         ctrlShow [MCC_MAP+_i, true];
      };
   };
   Sleep (_delayson select _j);
};

((findDisplay MCC_DLGMISSILECENTER) displayCtrl MCC_MAP) ctrlSetEventHandler ["MouseButtonDown", "_this call mando_mccmousemap"];
onMapSingleClick "true";
/*
for [{_j=21901},{_j < 21945},{_j=_j+1}] do
{
   ((findDisplay 21900) displayCtrl _j) ctrlSetBackgroundColor [0,0,0,0];
};
*/

[_launcher,_targettypes, _scanrange, _scanfreq, _antimissile, _missileparams, _sounds, _fixeddir, _missileidx, _backcolor,_scanstoload, _posrelcontrol]execVM mando_missile_path+"mcc\mando_missilecenterdlg.sqf";
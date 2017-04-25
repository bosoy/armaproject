/*
mando_replacemissile.sqf v2.3
CUSTOMIZED EXAMPLE!!!
July 2008 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY

You may add here more missile types to be replaced by mando ones, as well as change the parameters of already replaced ArmA missile types.
*/

private ["_target", "_type", "_firer", "_missile", "_vel", "_dir", "_up", "_launcher", "_missilebody", "_speedini","_speedmax","_acceleration","_boomrange","_activerange","_modeinit","_cruisealt","_boomscript","_smokescript","_soundrsc","_sounddur","_endurance","_terrainavoidance","_updatefreq","_delayinit", "_controltime","_detectable","_debug","_launchscript","_hagility","_vagility","_accuracy","_intercept", "_scanarch","_scanarcv","_posfire","_vdir","_dir","_vangle","_replaced", "_mode"];

_target = _this select 0;
_type = _this select 1;
_firer = _this select 2;
_missile = objNull;



if (local _firer) then
{
   _replaced = false;
   _missile = nearestObject [_firer, _type];

   if (!((_missile isKindOf "LaserBombCore") || (_missile isKindOf "BombCore") || (_missile isKindOf "RocketCore")) && !isNull _missile) then
   {

   Sleep 0.2;

   _posfire = _firer worldToModel (getPos _missile);
   _vdir = vectorDir _missile;
   _dir = (_vdir select 0) atan2 (_vdir select 1);

   switch (_type) do
   {
      case "M_Javelin_AT":
      {
         _mode = _firer getVariable "mando_javelin_mode";
         if (isNil "_mode") then
         {
            _mode = 0;
         };

         if (_mode == 0) then
         {  
            _launcher         = _firer;
            _missilebody      = _type;
            _speedini         = (speed _missile)/3.6;
            _speedmax         = 250;
            _acceleration     = 100;
            _boomrange        = 0;
            _activerange      = 280;
            _modeinit         = 0;
            _cruisealt        = 100;
            _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
            _smokescript      = "";
            _soundrsc         = "";
            _sounddur         = 29;
            _endurance        = 8;
            _terrainavoidance = false;
            _updatefreq       = 1;
            _delayinit        = 0;
            _controltime      = 0;
            _detectable       = false;
            _debug            = false;
            _launchscript     = "";
            _hagility         = 30;
            _vagility         = 55;
            _accuracy         = 1;
            _intercept        = false;
            _scanarch         = 35;
            _scanarcv         = 85;
 
            _vangle = asin(_vdir select 2);
            _replaced = true;
         }
         else
         {
            _launcher         = _firer;
            _missilebody      = _type;
            _speedini         = (speed _missile)/3.6;
            _speedmax         = 250;
            _acceleration     = 100;
            _boomrange        = 0;
            _activerange      = ((_target distance _firer) - 60) max 500;
            _modeinit         = 1;
            _cruisealt        = 60;
            _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
            _smokescript      = "";
            _soundrsc         = "";
            _sounddur         = 29;
            _endurance        = 8;
            _terrainavoidance = false;
            _updatefreq       = 1;
            _delayinit        = 0;
            _controltime      = 0;
            _detectable       = false;
            _debug            = false;
            _launchscript     = "";
            _hagility         = 30;
            _vagility         = 55;
            _accuracy         = 1;
            _intercept        = false;
            _scanarch         = 35;
            _scanarcv         = 85;
 
            _vangle = asin(_vdir select 2);
            _replaced = true;
         };

         if (_firer isKindOf "Man") then
         {
            if (isPlayer _firer) then
            {
               _replaced = false;             
            };
         };

      };

      case "M_Stinger_AA":
      {

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 200;
         _boomrange        = 5;
         _activerange      = 3000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1l.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 6;
         _terrainavoidance = false;
         _updatefreq       = 999;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 35;
         _scanarcv         = 35;

         _vangle = asin(_vdir select 2);
         _replaced = true;

         if (_firer isKindOf "Man") then
         {
            if (isPlayer _firer) then
            {
               _replaced = false;             
            };
         };
      };

      case "M_Strela_AA":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 200;
         _boomrange        = 5;
         _activerange      = 3000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1l.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 6;
         _terrainavoidance = false;
         _updatefreq       = 999;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 35;
         _scanarcv         = 35;

         _vangle = asin(_vdir select 2);
         _replaced = true;

         if (_firer isKindOf "Man") then
         {
            if (isPlayer _firer) then
            {
               _replaced = false;             
            };
         };

      };

      case "M_Igla_AA":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 200;
         _boomrange        = 5;
         _activerange      = 3000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1l.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 6;
         _terrainavoidance = false;
         _updatefreq       = 999;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 45;
         _scanarcv         = 45;

         _vangle = asin(_vdir select 2);
         _replaced = true;

         if (_firer isKindOf "Man") then
         {
            if (isPlayer _firer) then
            {
               _replaced = false;             
            };
         };

      };

      case "M_9M311_AA":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 900;
         _acceleration     = 200;
         _boomrange        = 5;
         _activerange      = 8000;
         _modeinit         = 2;
         _cruisealt        = 500;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = "";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 6;
         _terrainavoidance = false;
         _updatefreq       = 999;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 45;
         _scanarcv         = 65;

         _vangle = asin(_vdir select 2);
         _replaced = true;
      };


      case "M_Sidewinder_AA":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 600;
         _acceleration     = 250;
         _boomrange        = 10;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 10;
         _terrainavoidance = false;
         _updatefreq       = 999;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 45;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 65;
         _scanarcv         = 65;

         _vangle = 0;
         _replaced = true;
      };

      case "M_Sidewinder_AA_F35":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 600;
         _acceleration     = 250;
         _boomrange        = 10;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 10;
         _terrainavoidance = false;
         _updatefreq       = 999;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 55;
         _vagility         = 55;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 65;
         _scanarcv         = 65;

         _vangle = 0;
         _replaced = true;
      };


      case "M_R73_AA":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 600;
         _acceleration     = 250;
         _boomrange        = 10;
         _activerange      = 4000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 10;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 55;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 85;
         _scanarcv         = 65;
   
         _vangle = 0;
         _replaced = true;
      };

      case "M_Maverick_AT":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 278;
         _acceleration     = 120;
         _boomrange        = 0;
         _activerange      = 8000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 45;
         _vagility         = 45;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 75;
         _scanarcv         = 75;
 
         _vangle = 0;
         _replaced = true;
      };

      case "M_Hellfire_AT":
      {
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 355;
         _acceleration     = 150;
         _boomrange        = 0;
         _activerange      = 850;
         _modeinit         = 1;
         _cruisealt        = 350;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 0.5;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 40;
         _vagility         = 75;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 90;
         _scanarcv         = 90;
 
         _vangle = 0;
         _replaced = true;
      };

      case "M_Ch29_AT":
      {
         Sleep 0.5;
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 278;
         _acceleration     = 120;
         _boomrange        = 0;
         _activerange      = 800;
         _modeinit         = 1;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 2;
         _delayinit        = 0;
         _controltime      = 1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 50;
         _vagility         = 50;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 90;
         _scanarcv         = 90;
 
         _vangle = 0;
         _replaced = true;
      };

      case "M_Vikhr_AT":
      {
         _posfire = _firer worldToModel (getPos _missile);
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 400;
         _acceleration     = 120;
         _boomrange        = 0;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = "";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 20;
         _vagility         = 60;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 20;
         _scanarcv         = 60;
 
         _vangle = 0;
         _replaced = true;
      };

      case "M_AT11_AT":
      {
         _posfire = _firer worldToModel (getPos _missile);
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 300;
         _acceleration     = 120;
         _boomrange        = 0;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = "";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 20;
         _vagility         = 60;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 20;
         _scanarcv         = 60;
 
         _vangle = 0;
         _replaced = true;
         if (_firer isKindOf "Man") then
         {
            if (isPlayer _firer) then
            {
               _replaced = false;             
            };
         };
      };

      case "M_AT10_AT":
      {
         _posfire = _firer worldToModel (getPos _missile);
         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 300;
         _acceleration     = 120;
         _boomrange        = 0;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = "";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 20;
         _vagility         = 60;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 20;
         _scanarcv         = 60;
 
         _vangle = 0;
         _replaced = true;
         if (_firer isKindOf "Man") then
         {
            if (isPlayer _firer) then
            {
               _replaced = false;             
            };
         };
      };


      case "M_TOW_AT":
      {
         _launcher         = _firer;
         _missilebody      = "R_S8T_AT";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 278;
         _acceleration     = 80;
         _boomrange        = 0;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missileheadat2.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_towsmoke.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 6;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 60;
         _scanarcv         = 65;
 
         _vangle = asin(_vdir select 2);
         _replaced = true;
      };

      case "M_GNTHarpoon_LAS":
      {
         _launcher         = _firer;
         _missilebody      = "M_GNTHarpoon_LAS";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 237;
         _acceleration     = 50;
         _boomrange        = 0;
         _activerange      = 600;
         _modeinit         = 0;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 120;
         _terrainavoidance = true;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = true;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 40;
         _vagility         = 40;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 120;
         _scanarcv         = 90;
 
         _vangle = asin(_vdir select 2);
         _replaced = true;
      };


      case "M_GNTR29RM_DLT":
      {
         Sleep 1;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);


         _launcher         = _firer;
         _missilebody      = "M_GNTR29RM_DLT";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 50;
         _boomrange        = 0;
         _activerange      = 2000;
         _modeinit         = 0;
         _cruisealt        = 800;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 120;
         _terrainavoidance = true;
         _updatefreq       = 1;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = true;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 40;
         _vagility         = 40;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 120;
         _scanarcv         = 90;
 
         _vangle = asin(_vdir select 2);
         _replaced = true;
      };

      case "IkaR_F14_AIM54_ir":
      {
         Sleep 0.1;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 800;
         _acceleration     = 200;
         _boomrange        = 10;
         _activerange      = 2000;
         _modeinit         = 1;
         _cruisealt        = 200;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 30;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 2;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 85;
         _scanarcv         = 65;
   
         _vangle = 0;
         _replaced = true;
      };


      case "GLT_AIM120_AA":
      {
         Sleep 0.1;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 800;
         _acceleration     = 150;
         _boomrange        = 5;
         _activerange      = 12000;
         _modeinit         = 1;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "mando_missile1";
         _sounddur         = 29;
         _endurance        = 25;
         _terrainavoidance = false;
         _updatefreq       = 2;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 55;
         _vagility         = 55;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 75;
         _scanarcv         = 75;

         _vangle = 0;
         _replaced = true;
      };

      case "GLT_AIM7_AA":
      {
         Sleep 0.1;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 750;
         _acceleration     = 200;
         _boomrange        = 5;
         _activerange      = 10000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = "";
         _soundrsc         = "mando_missile1";
         _sounddur         = 29;
         _endurance        = 25;
         _terrainavoidance = false;
         _updatefreq       = 2;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 35;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 35;
         _scanarcv         = 35;

         _vangle = 0;
         _replaced = true;
      };

      case "GLT_AGM65_AG":
      {
         Sleep 0.2;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = 100+(speed _missile)/3.6;
         _speedmax         = 278;
         _acceleration     = 120;
         _boomrange        = 0;
         _activerange      = 8000;
         _modeinit         = 2;
         _cruisealt        = 100;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "mando_missile1";
         _sounddur         = 29;
         _endurance        = 30;
         _terrainavoidance = false;
         _updatefreq       = 2;
         _delayinit        = 0;
         _controltime      = 0;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 45;
         _vagility         = 45;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 45;
         _scanarcv         = 75;

         _vangle = 0;
         _replaced = true;
      };

      case "GLT_AGM84_AG":
      {
         Sleep 0.2;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 237;
         _acceleration     = 100;
         _boomrange        = 2;
         _activerange      = 1000;
         _modeinit         = 0;
         _cruisealt        = 80;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 120;
         _terrainavoidance = true;
         _updatefreq       = 2;
         _delayinit        = 1;
         _controltime      = 1;
         _detectable       = true;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 40;
         _vagility         = 40;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 90;
         _scanarcv         = 90;
 
         _vangle = 0;
         _replaced = true;
      };

      case "M_AGM86_AT":
      {
         Sleep 2;
         _posfire = _firer worldToModel (getPos _missile);
         _vdir = vectorDir _missile;
         _dir = (_vdir select 0) atan2 (_vdir select 1);

         _launcher         = _firer;
         _missilebody      = _type;
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 237;
         _acceleration     = 100;
         _boomrange        = 0;
         _activerange      = 1000;
         _modeinit         = 0;
         _cruisealt        = 150;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mando_missilesmoke1a.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 120;
         _terrainavoidance = true;
         _updatefreq       = 2;
         _delayinit        = 1;
         _controltime      = 1;
         _detectable       = true;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 40;
         _vagility         = 45;
         _accuracy         = 1;
         _intercept        = false;
         _scanarch         = 90;
         _scanarcv         = 90;
 
         _vangle = 0;
         _replaced = true;
      };

      case "M_bsg_AA_viper1":
      {
         _launcher         = _firer;
         _missilebody      = "Bo_Mk82";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 100;
         _boomrange        = 5;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mma_bgs_green.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 65;
         _vagility         = 65;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 75;
         _scanarcv         = 75;

         _vangle = 0;
         _replaced = true;
      };

      case "M_bsg_AA_viper2":
      {
         _launcher         = _firer;
         _missilebody      = "Bo_Mk82";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 100;
         _boomrange        = 5;
         _activerange      = 5000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mma_bgs_green.sqf";
         _soundrsc         = "mando_missile1";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 65;
         _vagility         = 65;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 75;
         _scanarcv         = 75;

         _vangle = 0;
         _replaced = true;
      };

      case "M_bsg_AA_lg80":
      {
         _launcher         = _firer;
         _missilebody      = "Bo_Mk82";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 350;
         _acceleration     = 100;
         _boomrange        = 15;
         _activerange      = 7000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mma_bgs_blue.sqf";
         _soundrsc         = "mando_missile1";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 55;
         _vagility         = 65;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 60;
         _scanarcv         = 85;

         _vangle = 0;
         _replaced = true;
      };

      case "M_bsg_AA_cylon":
      {
         _launcher         = _firer;
         _missilebody      = "Bo_Mk82";
         _speedini         = (speed _missile)/3.6;
         _speedmax         = 500;
         _acceleration     = 100;
         _boomrange        = 5;
         _activerange      = 7000;
         _modeinit         = 2;
         _cruisealt        = 50;
         _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
         _smokescript      = mando_missile_path+"exhausts\mma_bgs_red.sqf";
         _soundrsc         = "";
         _sounddur         = 29;
         _endurance        = 15;
         _terrainavoidance = false;
         _updatefreq       = 1;
         _delayinit        = 0.1;
         _controltime      = 0.1;
         _detectable       = false;
         _debug            = false;
         _launchscript     = "";
         _hagility         = 55;
         _vagility         = 35;
         _accuracy         = 1;
         _intercept        = true;
         _scanarch         = 60;
         _scanarcv         = 65;

         _vangle = 0;
         _replaced = true;
      };

      default 
      {
         if (mando_replace_all_missiles) then
         {
            Sleep 0.15;
            _posfire = _firer worldToModel (getPos _missile);
            _vdir = vectorDir _missile;
            _dir = (_vdir select 0) atan2 (_vdir select 1);

            // Generic values for any other missile not listed
            _launcher         = _firer;
            _missilebody      = _type;
            _speedini         = (speed _missile)/3.6;
            _speedmax         = 600;
            _acceleration     = 200;
            _boomrange        = 0;
            if ((getPos _target select 2) > 10) then
            {
               _boomrange = 7;
            };
            _activerange      = 5000;
            _modeinit         = 2;
            _cruisealt        = 50;
            _boomscript       = mando_missile_path+"warheads\mando_missilehead1_nohe.sqf";
            if ((getPos _target select 2) > 10) then
            {
               _boomscript       = mando_missile_path+"warheads\mando_missilehead1a.sqf";
            };
            _smokescript      = "";
            _soundrsc         = "";
            _sounddur         = 29;
            _endurance        = 10;
            _terrainavoidance = false;
            _updatefreq       = 999;
            _delayinit        = 0.2;
            _controltime      = 0.3;
            _detectable       = false;
            _debug            = false;
            _launchscript     = "";
            _hagility         = 45;
            _vagility         = 35;
            _accuracy         = 1;
            _intercept        = true;
            _scanarch         = 65;
            _scanarcv         = 65;

            _vangle = asin(_vdir select 2);
            _replaced = true;
         };
      };
   };

   if (_replaced) then
   {
      _posfire = _firer worldToModel (getPos _missile);
      _vdir = vectorDir _missile;
      _dir = (_vdir select 0) atan2 (_vdir select 1);


      [_missile] spawn
      {
         _missile = _this select 0;
         _missile setPos [60000,60000,60000];
         Sleep 6;
         if (alive _missile) then
         { 
            deleteVehicle _missile;
         };
      };

      _speedini = ((_speedini - (speed _firer)/3.6) min _speedmax) min 300;
      _vangle = asin(_vdir select 2) - asin(vectorDir _firer select 2);
   
      [_launcher, _missilebody, _posfire, _dir, _vangle, _speedini, _speedmax, _acceleration, _target, _boomrange, _activerange, _modeinit, _cruisealt, _boomscript, _smokescript, _soundrsc, _sounddur, _endurance, _terrainavoidance, _updatefreq, _delayinit, _controltime, _detectable, _debug, _launchscript, _hagility, _vagility, _accuracy, _intercept, _scanarch, _scanarcv]execVM mando_missile_path+"mando_missile.sqf";

   };
   
   };


};
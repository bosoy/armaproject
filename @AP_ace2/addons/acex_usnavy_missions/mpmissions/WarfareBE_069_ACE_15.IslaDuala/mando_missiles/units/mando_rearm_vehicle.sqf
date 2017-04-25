mando_update_source_level = 
{
   private["_pos", "_lvl"];
   disableSerialization;

   []spawn
   {
      while {!isNull ((findDisplay 1) displayCtrl 9)} do
      {
         _lvl = mando_rearm_source getVariable "mando_source_level";
         if (isNil "_lvl") then
         {
            _lvl = 0;
         };
         _pos = worldToScreen (mando_rearm_source modelToWorld [0,0,0]);
         if ((count _pos == 2) && (!isNull mando_rearm_source)) then
         {
            if (_lvl > 0) then
            {
               ((findDisplay 1) displayCtrl 11) ctrlSetTextColor [1,1,1,0.5];
            }
            else
            {
               ((findDisplay 1) displayCtrl 11) ctrlSetTextColor [1,0.5,0.5,0.5];
            };
            _pos = [(_pos select 0)-0.17*3/4/2, (_pos select 1)-0.17/2, 0.17*3/4, 0.17];
            ((findDisplay 1) displayCtrl 11) ctrlSetPosition _pos;
            ((findDisplay 1) displayCtrl 11) ctrlCommit 0;
         }
         else
         {
            ((findDisplay 1) displayCtrl 11) ctrlSetTextColor [0,0,0,0];
         };


         ((findDisplay 1) displayCtrl 12) ctrlSetPosition [safeZoneX+safeZoneW-0.05*2*3/4-0.02,safeZoneY+safeZoneH-0.06];
         ((findDisplay 1) displayCtrl 12) ctrlCommit 0;

         ((findDisplay 1) displayCtrl 13) ctrlSetPosition [safeZoneX+safeZoneW-0.05*3/4-0.01, safeZoneY+safeZoneH-0.06];
         ((findDisplay 1) displayCtrl 13) ctrlCommit 0;


         Sleep 0.01;
      };
   };

   while {!isNull ((findDisplay 1) displayCtrl 9)} do
   {
      if (!isNull mando_rearm_source) then
      {
         _lvl = mando_rearm_source getVariable "mando_source_level";
         if (isNil "_lvl") then
         {
            if (alive mando_rearm_source) then
            {
               mando_rearm_source setVariable ["mando_source_level", 100, true];
            }
            else
            {
               mando_rearm_source setVariable ["mando_source_level", 0, true];
            };
         };     
         _lvl = mando_rearm_source getVariable "mando_source_level";
      }
      else
      {
         _lvl = 0;
      };

      if ((_lvl > 0) && (!alive mando_rearm_source)) then
      {
         mando_rearm_source setVariable ["mando_source_level", 0, true];
      };

      _pos = ctrlPosition ((findDisplay 1) displayCtrl 9);
// 0.5 -> 100
      _pos set [2, _lvl*0.7/100];
      ((findDisplay 1) displayCtrl 9) ctrlSetPosition _pos;
      ((findDisplay 1) displayCtrl 9) ctrlCommit 0;
      if (_lvl > 0) then
      {
         ((findDisplay 1) displayCtrl 10) ctrlSetText format["%1%2",_lvl,"%"];
      }
      else
      {
         if (!isNull mando_rearm_source) then
         {
            ((findDisplay 1) displayCtrl 10) ctrlSetText "Weapons source is empty, select another source";
         }
         else
         {
            ((findDisplay 1) displayCtrl 10) ctrlSetText "Click over a weapons source to select it";
         };
      };

      if ((speed mando_rearm_source > 1) || (!alive mando_rearm_source)) then
      {
         mando_rearm_source = objNull;
      };

      if ((isEngineOn mando_rearm_target) || ((speed mando_rearm_target) > 1) || (!alive mando_rearm_target)) then
      {
         closeDialog 1;
      };

      Sleep 0.25;
   };

};

mando_is_gun = 
{
   private["_weapon", "_parent", "_magazines", "_result"];
   _weapon = _this select 0;

   _result = false;
   _parent = inheritsFrom (configFile>>"cfgWeapons" >> _weapon);
   if ((_parent == (configFile>>"cfgWeapons" >> "CannonCore")) || (_parent == (configFile>>"cfgWeapons" >> "MGun"))) then
   {

      _result = true;
   }
   else
   {
      _parent = inheritsFrom _parent;

      if ((_parent == (configFile>>"cfgWeapons" >> "CannonCore")) || (_parent == (configFile>>"cfgWeapons" >> "MGun"))) then
      {
         _result = true;
      };
   };
   _result
};

mando_is_rocket = 
{
   private["_weapon", "_parent", "_magazines", "_result", "_ammo_class"];
   _weapon = _this select 0;
   _magazines = getArray (configFile>>"cfgWeapons" >> _weapon >> "magazines");

   _ammo_class = getText (configFile>>"CfgMagazines" >> (_magazines select 0) >> "ammo");

   _parent = configName (inheritsFrom (configFile>> "CfgAmmo" >> _ammo_class));

   _result = false;
   if ((_parent == "RocketCore") || (_parent == "RocketBase")) then
   {
      _result = true;
   };
   _result
};

mando_is_gun_rocket_ammo = 
{
   private["_magazine", "_ammo_class", "_result"];
   _magazine = _this select 0;
   _ammo_class = getText (configFile>>"CfgMagazines" >> _magazine >> "ammo");

   _result = false;
   if ((_ammo_class isKindOf "BulletBase") || (_ammo_class isKindOf "RocketBase")) then
   {
      _result = true;
   };
   _result;
};

disableSerialization;

private ["_event", "_params", "_display", "_weapon", "_magazine", "_magazines", "_found", "_continue", "_pos","_lvl", "_type"];

_event = _this select 0;
_params = _this select 1;

switch (_event) do
{

   case "onLoad":
   {
      mandotarget_disp_on_old = mandotarget_disp_on;
      mandotarget_disp_on = false;
      cutText["", "PLAIN"];

      _display = _params select 0;

      mando_weapon_confs = [];
      _mando_weapon_confs_temp = [];

      if (!isNil "mando_weapon_master") then
      {
         {
            _pos = ctrlPosition (_display displayCtrl _x);
            _pos set [1, (_pos select 1)+2];
            (_display displayCtrl _x) ctrlSetPosition _pos;
            (_display displayCtrl _x) ctrlCommit 0;
         } forEach [20, 21, 22, 23, 1, 2];
      }
      else
      {
         {
            (_display displayCtrl _x) ctrlEnable false;
         } forEach [20, 21, 22, 23, 1, 2];
      };

      _type = typeOf mando_rearm_target;
      if (_type isKindOf "GLT_Falcon_MR") then
      {
         _type = "GLT_Falcon";
      };

      if (_type isKindOf "RKTTU22M3Base") then
      {
         _type = "GNT_TU22";
      };

      if (_type in mando_av8s) then
      {
         _type = "AV8B";
      };

      if (_type in mando_a10s) then
      {
         _type = "A10";
      };
	 
      if (_type in mando_ah64s) then
      {
         _type = "AH64D";
      };

      if (_type in ["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"]) then
      {
         _type = "GNTSU33";
      };

      if (_type isKindOf "rksl_efa_base") then
      {
         _type = "RKSL_EF2000";
      };

      if (_type in mando_su34s) then
      {
         _type = "Su34";
      };

      if (_type in ["ffaa_ea_ef_CAT","ffaa_ea_ef_CAS","ffaa_ea_ef_CAP"]) then
      {
         _type = "ffaa_ef2000";
      };

      if (_type in mando_f35s) then
      {
         _type = "F35B";
      };

      if (_type in ["GNTB52", "GNTB52u"]) then
      {
         _type = "GNTB52";
      };

	  if (_type in ["Su39","Su39_JDAM"]) then
	  {
		_type = "Su39";
	  };
	  
	  if (_type in ["Su25_CDF","Su25_Ins","Su25_TK_EP1","sy25_ge","Su25_SA_SAR", "Su25_Iraq","ATOW_SU25","CSLA_Su25"]) then
	  {
		_type = "Su25";
	  };
	  
	  if (_type in ["3lb_f22","3lb_f22_jdam","3lb_f22_sdb"]) then
	  {
		_type = "F22";
	  };

	  
      switch (_type) do
      {
         case "A10":
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH64";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_F35";
            _display displayCtrl 1 lbAdd "MaverickLauncher";
            _display displayCtrl 1 lbAdd "Mk82BombLauncher_6";
            _display displayCtrl 1 lbAdd "BombLauncherA10";

_mando_weapon_confs_temp = [
["Normal", ["1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","4Rnd_GBU12", "14Rnd_FFAR"],["GAU8", "MaverickLauncher", "SidewinderLaucher_AH1Z", "BombLauncherA10", "FFARLauncher_14"]],
["Maverick", ["1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","2Rnd_Maverick_A10", "2Rnd_Maverick_A10","14Rnd_FFAR"],["GAU8", "MaverickLauncher", "SidewinderLaucher_AH1Z", "FFARLauncher_14"]],
["Strike", ["1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","6Rnd_Mk82","14Rnd_FFAR"],["GAU8", "MaverickLauncher", "Mk82BombLauncher_6", "FFARLauncher_14"]]
];

if (count (configFile>>"cfgWeapons" >> "CBU87_4Pod") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [
["CBU87/Mk20", ["1350Rnd_30mmAP_A10","CBU87_2","2Rnd_Sidewinder_AH1Z","MK20_4", "28Rnd_FFAR"],["GAU8", "CBU87_2Pod", "SidewinderLaucher_AH1Z", "MK20_4Pod", "FFARLauncher"]],
["CBU87", ["1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","CBU87_4", "28Rnd_FFAR"],["GAU8", "MaverickLauncher", "SidewinderLaucher_AH1Z", "CBU87_4Pod", "FFARLauncher"]],
["CBU87/89", ["1350Rnd_30mmAP_A10","CBU87_4","CBU89_4","28Rnd_FFAR"],["GAU8", "CBU87_4Pod", "CBU89_4Pod","FFARLauncher"]],
["Mk20", ["1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z", "MK20_4", "28Rnd_FFAR"],["GAU8", "MaverickLauncher", "SidewinderLaucher_AH1Z", "MK20_4Pod", "FFARLauncher"]]
];

if (count (configFile>>"cfgWeapons" >> "GLT_GBU53_Launcher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["JDAM",["1350Rnd_30mmAP_A10","GLT_2Rnd_GBU53BIS","2Rnd_Sidewinder_AH1Z","4Rnd_GBU12","14Rnd_FFAR","120Rnd_CMFlare_Chaff_Magazine"],
																	  ["GAU8","GLT_GBU53_Launcher","SidewinderLaucher_AH1Z","BombLauncherA10","FFARLauncher_14","CMFlareLauncher"]]];
};

};

         };

         case "AV8B":
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH64";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_F35";
            _display displayCtrl 1 lbAdd "GLT_SidewinderXLauncher";
            _display displayCtrl 1 lbAdd "GLT_SidewinderLauncher";
            _display displayCtrl 1 lbAdd "GLT_AIM120Launcher";
            _display displayCtrl 1 lbAdd "MaverickLauncher";
            _display displayCtrl 1 lbAdd "GLT_MaverickLauncher";
            _display displayCtrl 1 lbAdd "Mk82BombLauncher_6";
            _display displayCtrl 1 lbAdd "BombLauncher";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_Mk82";
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";


_mando_weapon_confs_temp = [
["Strike", ["300Rnd_25mm_GAU12","6Rnd_Mk82"],["GAU12","Mk82BombLauncher_6"]],
["Air-Air Short Range", ["300Rnd_25mm_GAU12","4Rnd_Sidewinder_AV8B","2Rnd_Sidewinder_AH1Z"],["GAU12","SidewinderLaucher","SidewinderLaucher_AH1Z"]]];

if (count (configFile>>"cfgWeapons" >> "GLT_AIM120_Launcher") > 0) then
{
   _mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Air-Air Medium Range", ["300Rnd_25mm_GAU12","GLT_2Rnd_AIM120","4Rnd_Sidewinder_AV8B", "14Rnd_FFAR"],
																					["GAU12","GLT_AIM120_Launcher","SidewinderLaucher","FFARLauncher_14"]],
														  ["JDAM",["300Rnd_25mm_GAU12","GLT_2Rnd_GBU53BIS","4Rnd_GBU12","120Rnd_CMFlare_Chaff_Magazine"],
																					["GAU12","BombLauncherA10","GLT_GBU53_Launcher","CMFlareLauncher"]]];
};

_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["LGB", ["300Rnd_25mm_GAU12","6Rnd_GBU12_AV8B"],["GAU12","BombLauncher"]],
["SEAD", ["300Rnd_25mm_GAU12","2Rnd_R73","2Rnd_Sidewinder_AH1Z"],["GAU12","R73Launcher_2","SidewinderLaucher_AH1Z"]],
["Maverick", ["300Rnd_25mm_GAU12","2Rnd_Maverick_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z"],["GAU12","MaverickLauncher","SidewinderLaucher_AH1Z"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

if (count (configFile>>"cfgWeapons" >> "CBU87_4Pod") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [
   ["CBU87", ["300Rnd_25mm_GAU12","6Rnd_Mk82", "CBU87_2"],["GAU12","Mk82BombLauncher_6", "CBU87_2Pod"]],
   ["Mk20", ["300Rnd_25mm_GAU12","6Rnd_Mk82", "MK20_2"],["GAU12","Mk82BombLauncher_6", "MK20_2Pod"]]
];
};
         };


         case "AV8B2":
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH64";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_F35";
            _display displayCtrl 1 lbAdd "GLT_SidewinderXLauncher";
            _display displayCtrl 1 lbAdd "GLT_SidewinderLauncher";
            _display displayCtrl 1 lbAdd "GLT_AIM120Launcher";
            _display displayCtrl 1 lbAdd "MaverickLauncher";
            _display displayCtrl 1 lbAdd "GLT_MaverickLauncher";
            _display displayCtrl 1 lbAdd "Mk82BombLauncher_6";
            _display displayCtrl 1 lbAdd "BombLauncher";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_Mk82";
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

// _mando_weapon_confs_temp = [["conf name", [magazines], [weapons]], ...]; 

// _mando_weapon_confs_temp = [["conf name", [magazines], [weapons]], ...]; 

_mando_weapon_confs_temp = [
["Strike", ["300Rnd_25mm_GAU12","6Rnd_Mk82","2Rnd_Sidewinder_AH1Z","14Rnd_FFAR"],["GAU12","Mk82BombLauncher_6","SidewinderLaucher_AH1Z", "FFARLauncher_14"]],
["Air-Air Short Range", ["300Rnd_25mm_GAU12","8Rnd_Sidewinder_AH64","14Rnd_FFAR"],["GAU12","SidewinderLaucher_AH64","FFARLauncher_14"]]];

if (count (configFile>>"cfgWeapons" >> "GLT_AIM120_Launcher") > 0) then
{
   _mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Air-Air Medium Range", ["300Rnd_25mm_GAU12","GLT_2Rnd_AIM120","4Rnd_Sidewinder_AV8B", "14Rnd_FFAR"],   ["GAU12","GLT_AIM120_Launcher","SidewinderLaucher","FFARLauncher_14"]]];
};
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [
["LGB", ["300Rnd_25mm_GAU12","6Rnd_GBU12_AV8B","14Rnd_FFAR"],["GAU12","BombLauncher","FFARLauncher_14"]],
["SEAD", ["300Rnd_25mm_GAU12","2Rnd_R73","2Rnd_Sidewinder_AH1Z","14Rnd_FFAR"],["GAU12","R73Launcher_2","SidewinderLaucher_AH1Z","FFARLauncher_14"]],
["Maverick", ["300Rnd_25mm_GAU12","2Rnd_Maverick_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","14Rnd_FFAR"],["GAU12","MaverickLauncher","SidewinderLaucher_AH1Z","FFARLauncher_14"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};
         };

         case "AH1Z":
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "HellfireLauncher";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
            _display displayCtrl 1 lbAdd "TOWLauncher";

_mando_weapon_confs_temp = [
["Normal", ["750Rnd_M197_AH1","8Rnd_Hellfire","38Rnd_FFAR", "2Rnd_Sidewinder_AH1Z"],["M197","HellfireLauncher","FFARLauncher", "SidewinderLaucher_AH1Z"]],
["TOW", ["750Rnd_M197_AH1","2Rnd_TOW","38Rnd_FFAR", "2Rnd_Sidewinder_AH1Z"],["M197","TOWLauncher","FFARLauncher", "SidewinderLaucher_AH1Z"]],
["A-A", ["750Rnd_M197_AH1","4Rnd_Sidewinder_AV8B","38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]]];
         };

	 case "ACE_AH1Z_AGM_D":
	 {
        _display displayCtrl 1 lbAdd "SidewinderLaucher";
        _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
    	_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
		_display displayCtrl 1 lbAdd "TOWLauncher";
	    _display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z","ACE_HellfireLauncher","FFARLauncher"]],
["TOW", ["ACE_1Rnd_TOW2","ACE_1Rnd_TOW2","ACE_1Rnd_LAU68","ACE_1Rnd_LAU68","750Rnd_M197_AH1","ACE_TOW4","ACE_8Rnd_Empty_Dummy","ACE_SACLOS_Guidance"], ["M197","TOWLauncher","ACE_SACLOS_Guidance"]]
];

	 };		 

	 case "ACE_AH1Z_AGM_W":
	 {
        _display displayCtrl 1 lbAdd "SidewinderLaucher";
        _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
  	    _display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
		_display displayCtrl 1 lbAdd "TOWLauncher";
	    _display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z","ACE_HellfireLauncher","FFARLauncher"]],
["TOW", ["ACE_1Rnd_TOW2","ACE_1Rnd_TOW2","ACE_1Rnd_LAU68","ACE_1Rnd_LAU68","750Rnd_M197_AH1","ACE_TOW4","ACE_8Rnd_Empty_Dummy","ACE_SACLOS_Guidance"], ["M197","TOWLauncher","ACE_SACLOS_Guidance"]]
];

	 };		

	 case "ACE_AH1Z_AGM_AGM_W":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z"]],
["Air-Ground", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod",  "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z","ACE_HellfireLauncher"]],
["Multirole", ["2Rnd_Sidewinder_AH1Z", "750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_TOW4", "ACE_1Rnd_TOW4", "ACE_8Rnd_Hellfire", "ACE_TOW8"], ["M197", "SidewinderLaucher_AH1Z", "TOWLauncher", "ACE_HellfireLauncher"]]
];

	 };	
		 
	 case "ACE_AH1Z_AGM_AGM_D":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z"]],
["Air-Ground", ["750Rnd_M197_AH1", "2Rnd_Sidewinder_AH1Z", "ACE_1Rnd_Hellfirepod",  "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire"],["M197","SidewinderLaucher","SidewinderLaucher_AH1Z","ACE_HellfireLauncher"]],
["Multirole", ["2Rnd_Sidewinder_AH1Z", "750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_TOW4", "ACE_1Rnd_TOW4", "ACE_8Rnd_Hellfire", "ACE_TOW8"], ["M197", "SidewinderLaucher_AH1Z", "TOWLauncher", "ACE_HellfireLauncher"]]
];

	 };	

	 case "ACE_AH1W_AGM_W":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","ACE_HellfireLauncher","FFARLauncher"]],
["TOW", ["ACE_1Rnd_TOW2","ACE_1Rnd_TOW2","ACE_1Rnd_LAU68","ACE_1Rnd_LAU68","750Rnd_M197_AH1","ACE_TOW4","ACE_8Rnd_Empty_Dummy","ACE_SACLOS_Guidance"], ["M197","TOWLauncher","ACE_SACLOS_Guidance"]]
];

	 };
		 
	 case "ACE_AH1W_AGM_D":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","ACE_HellfireLauncher","FFARLauncher"]],
["TOW", ["ACE_1Rnd_TOW2","ACE_1Rnd_TOW2","ACE_1Rnd_LAU68","ACE_1Rnd_LAU68","750Rnd_M197_AH1","ACE_TOW4","ACE_8Rnd_Empty_Dummy","ACE_SACLOS_Guidance"], ["M197","TOWLauncher","ACE_SACLOS_Guidance"]]
];

	 };


	 case "ACE_AH1W_TOW_W":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","ACE_HellfireLauncher","FFARLauncher"]]
];

	 };
	 
	 
	 case "ACE_AH1W_TOW_TOW_W":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","ACE_HellfireLauncher","FFARLauncher"]]
];

	 };
	 
	 case "ACE_AH1W_TOW_D":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","ACE_HellfireLauncher","FFARLauncher"]]
];

	 };
	 
	 case "ACE_AH1W_TOW_TOW_D":
	 {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher";
			_display displayCtrl 1 lbAdd "TOWLauncher";
			_display displayCtrl 1 lbAdd "ACE_SACLOS_Guidance";
			
_mando_weapon_confs_temp = [
["Anti-Air", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "4Rnd_Sidewinder_AV8B", "38Rnd_FFAR"],["M197","SidewinderLaucher","FFARLauncher"]],
["Air-Ground", ["750Rnd_M197_AH1", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_Hellfirepod", "ACE_1Rnd_LAU61", "ACE_1Rnd_LAU61", "4Rnd_Sidewinder_AV8B", "ACE_4Rnd_Hellfire", "38Rnd_FFAR"],["M197","SidewinderLaucher","ACE_HellfireLauncher","FFARLauncher"]]
];


	 };
		 
         case "AH64D":
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH64";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_F35";
            _display displayCtrl 1 lbAdd "GLT_SidewinderXLauncher";
            _display displayCtrl 1 lbAdd "GLT_SidewinderLauncher";
            _display displayCtrl 1 lbAdd "HellfireLauncher";
			_display displayCtrl 1 lbAdd "ACE_HellfireLauncher_Apache";
            _display displayCtrl 1 lbAdd "FFARLauncher";

_mando_weapon_confs_temp = [
["Sidewinder", ["1200Rnd_30x113mm_M789_HEDP","38Rnd_FFAR","8Rnd_Sidewinder_AH64"],["M230","FFARLauncher","SidewinderLaucher_AH64"]]
];
         };

         case "F35B":
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH64";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_F35";
            _display displayCtrl 1 lbAdd "GLT_SidewinderXLauncher";
            _display displayCtrl 1 lbAdd "GLT_SidewinderLauncher";
            _display displayCtrl 1 lbAdd "GLT_AIM120Launcher";
            _display displayCtrl 1 lbAdd "MaverickLauncher";
            _display displayCtrl 1 lbAdd "GLT_MaverickLauncher";
            _display displayCtrl 1 lbAdd "BombLauncherF35";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

_mando_weapon_confs_temp = [
["Strike", ["300Rnd_25mm_GAU12","2Rnd_GBU12","2Rnd_Sidewinder_F35"],["GAU12","BombLauncherF35","SidewinderLaucher_F35"]],
["Air-Air Short Range", ["300Rnd_25mm_GAU12","4Rnd_Sidewinder_AV8B"],["GAU12","SidewinderLaucher"]]];

if (count (configFile>>"cfgWeapons" >> "GLT_AIM120_Launcher") > 0) then
{
   _mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Air-Air Medium Range", ["300Rnd_25mm_GAU12","2Rnd_Sidewinder_F35","GLT_2Rnd_AIM120"],["GAU12","SidewinderLaucher_F35","GLT_AIM120_Launcher"]]];
};

_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["LGB", ["300Rnd_25mm_GAU12","2Rnd_GBU12","2Rnd_GBU12"],["GAU12","BombLauncherF35"]],
["Maverick", ["300Rnd_25mm_GAU12","2Rnd_Maverick_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_F35"],["GAU12","MaverickLauncher","SidewinderLaucher_F35"]]];

            if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
            {
               _mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
            };


            if (count (configFile>>"cfgWeapons" >> "CBU87_4Pod") > 0) then
            {
               _mando_weapon_confs_temp = _mando_weapon_confs_temp + 
               [
                  ["CBU87", ["300Rnd_25mm_GAU12","CBU87_F35","2Rnd_Sidewinder_F35"],["GAU12","CBU87_F35Pod","SidewinderLaucher_F35"]],
                  ["Mk20", ["300Rnd_25mm_GAU12","MK20_F35","2Rnd_Sidewinder_F35"],["GAU12","MK20_F35Pod","SidewinderLaucher_F35"]]
               ];
            };
         };


	 case "ACE_Su27_CASP":
	 {
  	    _display displayCtrl 1 lbAdd "R73Launcher"; 
            _display displayCtrl 1 lbAdd "R73Launcher_2"; 
            _display displayCtrl 1 lbAdd "ACE_R73Launcher"; 
            _display displayCtrl 1 lbAdd "ACE_R27Launcher"; 
            _display displayCtrl 1 lbAdd "Ch29Launcher"; 
            _display displayCtrl 1 lbAdd "Ch29Launcher_Su34";  
	    _display displayCtrl 1 lbAdd "AirBombLauncher"; 
            _display displayCtrl 1 lbAdd "MaverickLauncher";
	    _display displayCtrl 1 lbAdd "ACE_S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

_mando_weapon_confs_temp = [
["A-A Short Range", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R73", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_4Rnd_R73", "ACE_40Rnd_S8T"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_S8Launcher"]],
["A-A Medium Range", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R27", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_R27", "ACE_2Rnd_R73", "ACE_40Rnd_S8T"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_R27Launcher", "ACE_S8Launcher"]],
["Air-Ground", ["ACE_150Rnd_30mm_GSh301", "4Rnd_Ch29", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_R73", "ACE_2Rnd_R27", "ACE_40Rnd_S8T"], ["ACE_GSh301", "Ch29Launcher", "ACE_R73Launcher", "ACE_R27Launcher", "ACE_S8Launcher"]],
["Air-Bombs", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R73", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_R27", "2Rnd_FAB_250", "ACE_40Rnd_S8T"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_R27Launcher", "AirBombLauncher", "ACE_S8Launcher"]],
["Strike", ["ACE_150Rnd_30mm_GSh301", "4Rnd_FAB_250", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "2Rnd_FAB_250", "ACE_120Rnd_S8T", "ACE_120Rnd_S8T"], ["ACE_GSh301", "AirBombLauncher", "ACE_S8Launcher"]],
["SEAD", ["ACE_150Rnd_30mm_GSh301","4Rnd_Ch29", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "2Rnd_Maverick_A10","ACE_2Rnd_R73","ACE_80Rnd_S8T"],["ACE_GSh301","Ch29Launcher", "MaverickLauncher","ACE_R73Launcher","ACE_S8Launcher"]]
];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};
		
	 };
		 
	 case "ACE_Su27_CAP":
	 {
	    _display displayCtrl 1 lbAdd "R73Launcher"; 
            _display displayCtrl 1 lbAdd "R73Launcher_2"; 
            _display displayCtrl 1 lbAdd "ACE_R73Launcher"; 
            _display displayCtrl 1 lbAdd "ACE_R27Launcher"; 
            _display displayCtrl 1 lbAdd "Ch29Launcher"; 
            _display displayCtrl 1 lbAdd "Ch29Launcher_Su34";  
 	    _display displayCtrl 1 lbAdd "AirBombLauncher"; 
            _display displayCtrl 1 lbAdd "MaverickLauncher";
	    _display displayCtrl 1 lbAdd "ACE_S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

_mando_weapon_confs_temp = [
["A-A Short Range", ["ACE_150Rnd_30mm_GSh301", "ACE_6Rnd_R73", "ACE_4Rnd_R73"], ["ACE_GSh301", "ACE_R73Launcher"]],
["A-A Medium Range", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R73", "ACE_6Rnd_R27"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_R27Launcher"]],
["Air-Ground", ["ACE_150Rnd_30mm_GSh301", "4Rnd_Ch29", "ACE_2Rnd_R73", "ACE_2Rnd_R27", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T"], ["ACE_GSh301", "Ch29Launcher", "ACE_R73Launcher", "ACE_R27Launcher"]],
["Air-Bombs", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R73", "ACE_2Rnd_R27", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "2Rnd_FAB_250"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_R27Launcher", "AirBombLauncher"]],
["Strike", ["ACE_150Rnd_30mm_GSh301", "4Rnd_FAB_250", "ACE_1Rnd_S8T", "ACE_1Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "2Rnd_FAB_250", "ACE_120Rnd_S8T", "ACE_120Rnd_S8T"], ["ACE_GSh301", "ACE_S8Launcher", "AirBombLauncher"]],
["SEAD", ["ACE_150Rnd_30mm_GSh301", "4Rnd_Ch29", "ACE_1Rnd_S8T", "ACE_1Rnd_S8T", "2Rnd_Maverick_A10", "ACE_2Rnd_R73", "ACE_80Rnd_S8T"],["ACE_GSh301","Ch29Launcher", "MaverickLauncher","ACE_R73Launcher","ACE_S8Launcher"]]
];		
if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};
	 };
		 
	 case "ACE_Su27_CAS":
	 {
 	    _display displayCtrl 1 lbAdd "R73Launcher"; 
            _display displayCtrl 1 lbAdd "R73Launcher_2"; 
            _display displayCtrl 1 lbAdd "ACE_R73Launcher"; 
            _display displayCtrl 1 lbAdd "ACE_R27Launcher"; 
            _display displayCtrl 1 lbAdd "Ch29Launcher"; 
            _display displayCtrl 1 lbAdd "Ch29Launcher_Su34";  
	    _display displayCtrl 1 lbAdd "AirBombLauncher"; 
            _display displayCtrl 1 lbAdd "MaverickLauncher";
	    _display displayCtrl 1 lbAdd "ACE_S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
		 
_mando_weapon_confs_temp = [
["A-A Short Range", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R73", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_4Rnd_R73", "ACE_40Rnd_S8T"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_S8Launcher"]],
["A-A Medium Range", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R27", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_R27", "ACE_2Rnd_R73", "ACE_40Rnd_S8T"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_R27Launcher", "ACE_S8Launcher"]],
["Air-Ground", ["ACE_150Rnd_30mm_GSh301", "4Rnd_Ch29", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_R73", "ACE_2Rnd_R27", "ACE_40Rnd_S8T"], ["ACE_GSh301", "Ch29Launcher", "ACE_R73Launcher", "ACE_R27Launcher", "ACE_S8Launcher"]],
["Air-Bombs", ["ACE_150Rnd_30mm_GSh301", "ACE_4Rnd_R73", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_R27", "2Rnd_FAB_250", "ACE_40Rnd_S8T"], ["ACE_GSh301", "ACE_R73Launcher", "ACE_R27Launcher", "AirBombLauncher", "ACE_S8Launcher"]],
["Strike", ["ACE_150Rnd_30mm_GSh301", "4Rnd_FAB_250", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "2Rnd_FAB_250", "ACE_120Rnd_S8T", "ACE_120Rnd_S8T"], ["ACE_GSh301", "AirBombLauncher", "ACE_S8Launcher"]],
["SEAD", ["ACE_150Rnd_30mm_GSh301","4Rnd_Ch29", "ACE_2Rnd_S8T", "ACE_2Rnd_S8T", "2Rnd_Maverick_A10","ACE_2Rnd_R73","ACE_80Rnd_S8T"],["ACE_GSh301","Ch29Launcher", "MaverickLauncher","ACE_R73Launcher","ACE_S8Launcher"]]
];
if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

	 };

         case "Su34":
         {
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "R73Launcher";
            _display displayCtrl 1 lbAdd "Ch29Launcher_Su34";
            _display displayCtrl 1 lbAdd "Ch29Launcher";
            _display displayCtrl 1 lbAdd "AirBombLauncher";
            _display displayCtrl 1 lbAdd "S8Launcher";
            _display displayCtrl 1 lbAdd "MaverickLauncher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

_mando_weapon_confs_temp = [
["Normal", ["180Rnd_30mm_GSh301","6Rnd_Ch29","4Rnd_R73","40Rnd_S8T"],["GSh301","Ch29Launcher_Su34","R73Launcher", "80mmLauncher"]],
["A-A Short R.", ["180Rnd_30mm_GSh301","4Rnd_R73","4Rnd_R73","2Rnd_R73","40Rnd_S8T"],["GSh301","R73Launcher", "R73Launcher_2","80mmLauncher"]],
["Strike", ["180Rnd_30mm_GSh301","4Rnd_Ch29","4Rnd_FAB_250","2Rnd_R73","40Rnd_S8T"],["GSh301","Ch29Launcher_Su34","AirBombLauncher","R73Launcher_2", "80mmLauncher"]],
["Interdiction", ["180Rnd_30mm_GSh301","6Rnd_Ch29","4Rnd_Ch29","40Rnd_S8T"],["GSh301","Ch29Launcher_Su34", "80mmLauncher"]],
["Bombs", ["180Rnd_30mm_GSh301","4Rnd_FAB_250","4Rnd_FAB_250","2Rnd_R73","40Rnd_S8T"],["GSh301","AirBombLauncher","R73Launcher_2", "80mmLauncher"]],
["SEAD", ["180Rnd_30mm_GSh301","4Rnd_Ch29","2Rnd_Maverick_A10","2Rnd_R73","40Rnd_S8T"],["GSh301","Ch29Launcher_Su34", "MaverickLauncher","R73Launcher_2","80mmLauncher"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

if (count (configFile>>"cfgWeapons" >> "GLT_R73_Launcher") > 0) then
{
   _mando_weapon_confs_temp = _mando_weapon_confs_temp + [
      ["AA Medium R.", ["180Rnd_30mm_GSh301","GLT_4Rnd_R73","GLT_4Rnd_R77"], ["GSh301","GLT_R73_Launcher","GLT_R77_Launcher"]],
      ["AA SARH", ["180Rnd_30mm_GSh301","GLT_4Rnd_R73","GLT_4Rnd_R27"], ["GSh301","GLT_R73_Launcher","GLT_R27_Launcher"]],
      ["AGM", ["180Rnd_30mm_GSh301","GLT_2Rnd_R73","GLT_2Rnd_CH29L","GLT_4Rnd_CH29T","GLT_2Rnd_CH31","GLT_1Rnd_CH59"],    ["GSh301","GLT_R73_Launcher","GLT_Ch29L_Launcher","GLT_Ch29T_Launcher","GLT_Ch31_Launcher","GLT_Ch59_Launcher"]],
      ["LGB", ["180Rnd_30mm_GSh301","GLT_2Rnd_R73","GLT_6Rnd_KAB250","GLT_2Rnd_KAB500","GLT_1Rnd_KAB1500"],    ["GSh301","GLT_R73_Launcher","GLT_KAB250_Launcher","GLT_KAB500_Launcher","GLT_KAB1500_Launcher"]],
      ["Bombs + R27", ["180Rnd_30mm_GSh301","GLT_4Rnd_R27","GLT_4Rnd_FAB500","GLT_3Rnd_B8M1_Pod","GLT_60Rnd_80mm"],    ["GSh301","GLT_R27_Launcher","GLT_FAB500_Launcher","GLT_B8M1_Launcher"]],
      ["CAS", ["180Rnd_30mm_GSh301","GLT_2Rnd_R73","GLT_4Rnd_FAB500","GLT_5Rnd_B8M1_Pod","GLT_100Rnd_80mm"],    ["GSh301","GLT_R73_Launcher","GLT_FAB500_Launcher","GLT_B8M1_Launcher"]],
	  ["KAB500SE",["180Rnd_30mm_GSh301","GLT_4Rnd_KAB500_JDAMBIS","GLT_2Rnd_Ch29T","4Rnd_R73","40Rnd_S8T"],["GSh301","GLT_KAB500SE_Launcher","GLT_Ch29T_Launcher","R73Launcher","80mmLauncher"]]

   ];
};

         };


         case "Su39":
         {
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "R73Launcher";
            _display displayCtrl 1 lbAdd "Ch29Launcher";
            _display displayCtrl 1 lbAdd "AirBombLauncher";
            _display displayCtrl 1 lbAdd "S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

_mando_weapon_confs_temp = [
["Ks29", ["180Rnd_30mm_GSh301","4Rnd_Ch29","2Rnd_R73","80Rnd_S8T"],["GSh301","Ch29Launcher","R73Launcher_2", "S8Launcher"]],
["FAB", ["180Rnd_30mm_GSh301","4Rnd_FAB_250","2Rnd_R73","80Rnd_S8T"],["GSh301","AirBombLauncher","R73Launcher_2", "S8Launcher"]],
["A-A", ["180Rnd_30mm_GSh301","4Rnd_R73","2Rnd_R73","80Rnd_S8T"],["GSh301","R73Launcher","R73Launcher_2", "S8Launcher"]],
["Strike", ["180Rnd_30mm_GSh301","4Rnd_Ch29","2Rnd_FAB_250","80Rnd_S8T"],["GSh301","Ch29Launcher","AirBombLauncher", "S8Launcher"]],
["Iron Bombs", ["180Rnd_30mm_GSh301","4Rnd_FAB_250","2Rnd_FAB_250","80Rnd_S8T"],["GSh301","AirBombLauncher", "S8Launcher"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

if (count (configFile>>"cfgWeapons" >> "GLT_R73_Launcher") > 0) then
{
   _mando_weapon_confs_temp = _mando_weapon_confs_temp + [
	["KAB500SE",["180Rnd_30mm_GSh301","GLT_4Rnd_KAB500_JDAMBIS","2Rnd_R73","80Rnd_S8T","120Rnd_CMFlare_Chaff_Magazine"],["GSh301","GLT_KAB500SE_Launcher","R73Launcher_2","S8Launcher","CMFlareLauncher"]]
	];
};

         };

         case "Su25":
         {
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "R73Launcher";
            _display displayCtrl 1 lbAdd "Ch29Launcher";
            _display displayCtrl 1 lbAdd "AirBombLauncher";
            _display displayCtrl 1 lbAdd "S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";

_mando_weapon_confs_temp = [
["FAB", ["180Rnd_30mm_GSh301","4Rnd_FAB_250","2Rnd_R73","80Rnd_S8T"],["GSh301","AirBombLauncher","R73Launcher_2", "S8Launcher"]],
["A-A", ["180Rnd_30mm_GSh301","4Rnd_R73","2Rnd_R73","80Rnd_S8T"],["GSh301","R73Launcher","R73Launcher_2", "S8Launcher"]],
["Bombs", ["180Rnd_30mm_GSh301","4Rnd_FAB_250","2Rnd_FAB_250","80Rnd_S8T"],["GSh301","AirBombLauncher", "S8Launcher"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

         };

         case "GNTB52":
         {
            _display displayCtrl 1 lbAdd "GNTMK82BombRail";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear AGM86", ["84Rnd_GNTMK82","6Rnd_AGM86"],["GNTMK82Launcher","AGM86Launcher"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

if (count (configFile>>"cfgWeapons" >> "GLT_AGM84_Launcher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Harpoon",
["84Rnd_GNTMK82","GLT_6Rnd_AGM84"],["GNTMK82Launcher","GLT_AGM84_Launcher"]]];
};
         };

         case "ffaa_famet_tigre":
         {
            _display displayCtrl 1 lbAdd "ffaa_GIAT30_tig";
            _display displayCtrl 1 lbAdd "FFARLauncher";
            _display displayCtrl 1 lbAdd "ffaa_Trigat_tig";
            _display displayCtrl 1 lbAdd "ffaa_Mistral_tig";

_mando_weapon_confs_temp = [
["FAMET",["ffaa_250Rnd_30mmHE_GIAT30","ffaa_250Rnd_30mmHE_GIAT30","38Rnd_FFAR", "ffaa_Trigat_8nag","ffaa_Mistral_4mag"],["ffaa_GIAT30_tig","FFARLauncher","ffaa_Trigat_tig", "ffaa_Mistral_tig"]]];

         };

         case "F22":
         {
_mando_weapon_confs_temp = [
["A-A",["3lb_20mm_M61A2","GLT_2Rnd_AIM9M","GLT_6Rnd_AIM120","120Rnd_CMFlare_Chaff_Magazine"],["3lb_M61A2","GLT_AIM9M_Launcher","GLT_AIM120_Launcher","CMFlareLauncher"]],
["JDAM",["3lb_20mm_M61A2","GLT_2Rnd_AIM9M","GLT_2Rnd_AIM120","GLT_empty_4","GLT_2Rnd_GBU53","120Rnd_CMFlare_Chaff_Magazine"],["3lb_M61A2","GLT_AIM9M_Launcher","GLT_AIM120_Launcher","GLT_GBU53_Launcher","CMFlareLauncher"]],
["GBU39",["3lb_20mm_M61A2","GLT_2Rnd_AIM9M","GLT_2Rnd_AIM120","GLT_empty_4","GLT_8Rnd_GBU39","120Rnd_CMFlare_Chaff_Magazine"],["3lb_M61A2","GLT_AIM9M_Launcher","GLT_AIM120_Launcher","GLT_GBU39_Launcher","CMFlareLauncher"]]
];
         };
		 
		 
         case "ffaa_ef2000":
         {
            _display displayCtrl 1 lbAdd "GLT_SidewinderXLauncher";
            _display displayCtrl 1 lbAdd "GLT_SidewinderLauncher";
            _display displayCtrl 1 lbAdd "GLT_AIM120Launcher";
            _display displayCtrl 1 lbAdd "GLT_AIM7Launcher";
            _display displayCtrl 1 lbAdd "GLT_MaverickLauncher";
            _display displayCtrl 1 lbAdd "GLT_AGM84Launcher";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_Mk82";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_Mk84";
            _display displayCtrl 1 lbAdd "GLT_AGM88Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_LGB";
	    _display displayCtrl 1 lbAdd "ffaa_MaverickLauncher_ef";
            _display displayCtrl 1 lbAdd "ffaa_BombLauncher_ef";	
	    _display displayCtrl 1 lbAdd "ffaa_SidewinderLaucher_ef";

            _mando_weapon_confs_temp = [
               ["Multirole",["300Rnd_25mm_GAU12","ffaa_4Rnd_Maverick_ef", "ffaa_4Rnd_GBU12_ef", "ffaa_2Rnd_Sidewinder_ef"],["GAU12","ffaa_MaverickLauncher_ef","ffaa_BombLauncher_ef", "ffaa_SidewinderLaucher_ef"]],
               ["Maverick",["300Rnd_25mm_GAU12","ffaa_6Rnd_Maverick_ef", "ffaa_2Rnd_Sidewinder_ef"],["GAU12","ffaa_MaverickLauncher_ef", "ffaa_SidewinderLaucher_ef"]],
               ["LGB",["300Rnd_25mm_GAU12","ffaa_6Rnd_GBU12_ef", "ffaa_2Rnd_Sidewinder_ef"],["GAU12","ffaa_BombLauncher_ef", "ffaa_SidewinderLaucher_ef"]],
               ["Mk82",["300Rnd_25mm_GAU12","6Rnd_Mk82", "ffaa_2Rnd_Sidewinder_ef"],["GAU12","Mk82BombLauncher_6", "ffaa_SidewinderLaucher_ef"]],
	       ["SEAD", ["300Rnd_25mm_GAU12","ffaa_8Rnd_Sidewinder_ef", "2Rnd_R73"],["GAU12","ffaa_SidewinderLaucher_ef","R73Launcher_2"]],

               ["A-A Short Range",["300Rnd_25mm_GAU12", "ffaa_8Rnd_Sidewinder_ef"], ["GAU12", "ffaa_SidewinderLaucher_ef"]]
            ];

if (count (configFile>>"cfgWeapons" >> "GLT_AIM120_Launcher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["A-A Medium Range",["300Rnd_25mm_GAU12", "GLT_4Rnd_AIM120", "ffaa_2Rnd_Sidewinder_ef"], ["GAU12", "GLT_AIM120_Launcher", "ffaa_SidewinderLaucher_ef"]]];
};

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};

         };

         case "RKSL_EF2000":
         {

            _mando_weapon_confs_temp = [
["(AGAA1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_2Rnd_AIM132","RKSL_6Rnd_brimstone_rack_mag","RKSL_litening_Pod_mag","RKSL_1rnd_efa_cft","RKSL_18Rnd_Brimstone_DM"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM132Launcher","RKSL_BrimstoneLauncher"]],
["(AGAA2)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_2Rnd_AIM132","RKSL_6Rnd_brimstone_rack_mag","RKSL_litening_Pod_mag","RKSL_1rnd_efa_cft","RKSL_18Rnd_Brimstone"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM132Launcher","RKSL_BrimstoneLauncher"]],
["(AGAA3)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_2Rnd_AIM132","RKSL_2Rnd_brimstone_rack_mag","RKSL_4Rnd_PAVE4_500","RKSL_1rnd_efa_fueltank","RKSL_1Rnd_pylonblank","RKSL_6Rnd_Brimstone_DM"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM132Launcher","RKSL_BrimstoneLauncher","RKSL_Paveway4500Launcher"]],
["(AGAA4)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_2Rnd_AIM132","RKSL_4Rnd_Maverick","RKSL_2Rnd_PAVE4_500","RKSL_litening_Pod_mag","RKSL_1rnd_efa_cft"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM132Launcher","RKSL_MaverickLauncher","RKSL_Paveway4500Launcher"]],
["(AS1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_4Rnd_AIM132","RKSL_2rnd_efa_fueltank","RKSL_2Rnd_pylonblank","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher"]],
["(AS2)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_4Rnd_AIM132","RKSL_2rnd_efa_fueltank","RKSL_2Rnd_AIM120","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM120Launcher","RKSL_AIM132Launcher"]],
["(CAS-H)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_4Rnd_GP_1000","RKSL_2Rnd_PAVE2_1000","RKSL_litening_Pod_mag"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_1000GPLauncher","RKSL_Paveway1000Launcher"]],
["(CAS-L)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_19Rnd_CRV7_FAT","RKSL_19Rnd_CRV7_HEPD","RKSL_CRV_lau5003FPodx2","RKSL_4Rnd_PAVE4_500","RKSL_litening_Pod_mag"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_CRV7_hepd_Launcher","RKSL_CRV7_FAT_Launcher","RKSL_Paveway4500Launcher"]],
["(CAS-L2)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_19Rnd_CRV7_FAT","RKSL_19Rnd_CRV7_HEPD","RKSL_CRV_lau5003FPodx2","RKSL_2Rnd_brimstone_rack_mag","RKSL_2Rnd_PAVE4_500","RKSL_litening_Pod_mag","RKSL_7Rnd_pylonblank","RKSL_6Rnd_Brimstone_DM"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_CRV7_hepd_Launcher","RKSL_CRV7_FAT_Launcher","RKSL_BrimstoneLauncher","RKSL_Paveway4500Launcher"]],
["(EUMS1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_irist","RKSL_2rnd_agm119mk3","RKSL_2rnd_efa_fueltank","RKSL_3Rnd_pylonblank","RKSL_1rnd_efa_cft"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_iristLauncher","RKSL_agm119mk3_Launcher"]],
["(IDS1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_2Rnd_PAVE2_1000","RKSL_2rnd_efa_fueltank","RKSL_2Rnd_PAVE2_500","RKSL_litening_Pod_mag"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_Paveway1000Launcher","RKSL_Paveway500Launcher"]],
["(LGB-H)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_6Rnd_PAVE2_1000","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_Paveway1000Launcher"]],
["(LGB-L)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_6Rnd_PAVE4_500","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_Paveway4500Launcher"]],
["(LGB-M)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_6Rnd_PAVE2_500","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_Paveway500Launcher"]],
["(MS1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_4Rnd_AIM132","RKSL_2rnd_harpoon","RKSL_2Rnd_PAVE2_1000","RKSL_1rnd_efa_fueltank","RKSL_1rnd_efa_cft"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_harpoon_Launcher","RKSL_Paveway1000Launcher"]],
["(MS2)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_4rnd_harpoon","RKSL_2Rnd_PAVE2_1000","RKSL_1rnd_efa_fueltank","RKSL_1rnd_efa_cft"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_harpoon_Launcher","RKSL_Paveway1000Launcher"]],
["(SEAD1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_2rnd_ALARM","RKSL_2rnd_efa_fueltank","RKSL_2Rnd_PAVE2_500","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_ALARM_Launcher","RKSL_Paveway500Launcher"]],
["(SEAD2)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_AIM120","RKSL_2Rnd_AIM132","RKSL_6rnd_ALARM","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_AIM120Launcher","RKSL_AIM132Launcher","RKSL_ALARM_Launcher"]],
["(SR1)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_4Rnd_AIM132","RKSL_2rnd_stormshadow","RKSL_2Rnd_PAVE2_1000","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM132Launcher","RKSL_stormshadow_Launcher","RKSL_Paveway1000Launcher"]],
["(SR2)",["RKSL_150Rnd_27mmAP_Mauser","RKSL_4Rnd_Meteor","RKSL_2Rnd_AIM132","RKSL_4Rnd_Maverick","RKSL_2Rnd_PAVE4_500","RKSL_1rnd_efa_fueltank"],["RKSL_27mmmauser","RKSL_MeteorLauncher","RKSL_AIM132Launcher","RKSL_MaverickLauncher","RKSL_Paveway4500Launcher"]]
            ];
         };


         case "GNTSU33":
         {
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "R73Launcher";
            _display displayCtrl 1 lbAdd "Ch29Launcher";
            _display displayCtrl 1 lbAdd "AirBombLauncher";
            _display displayCtrl 1 lbAdd "S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
            _display displayCtrl 1 lbAdd "RKT_Kitchen_Rail";
            _display displayCtrl 1 lbAdd "RKTCh29Launcher";
            _display displayCtrl 1 lbAdd "RKTR27Launcher";
            _display displayCtrl 1 lbAdd "RKTR73Launcher";
            _display displayCtrl 1 lbAdd "RKT_kb500Launcher";
            _display displayCtrl 1 lbAdd "RKT_fb250Launcher";

_mando_weapon_confs_temp = [
["A-A", ["180Rnd_30mm_GSh301","6Rnd_RKTR73", "4Rnd_RKTR27"],["GSh301","RKTR73Launcher","RKTR27Launcher", "RKTS8Launcher"]],
["AS-4", ["180Rnd_30mm_GSh301","6Rnd_RKTR73", "2Rnd_RKTR27","3Rnd_RKT_Kitchen_mis"],["GSh301","RKTR73Launcher","RKTR27Launcher", "RKT_Kitchen_Rail", "RKTS8Launcher"]],
["Ground Attack", ["180Rnd_30mm_GSh301","2Rnd_RKTR73", "4Rnd_FB250","6Rnd_RKTCh29","40Rnd_RKTS8T"],["GSh301","RKTR73Launcher","RKT_fb250Launcher","RKTCh29Launcher","RKTS8Launcher"]],
["Bomber", ["180Rnd_30mm_GSh301","2Rnd_RKTR73", "2Rnd_FB250","8Rnd_KB500"],["GSh301","RKTR73Launcher", "RKT_kb500Launcher","RKT_fb250Launcher", "RKTS8Launcher"]]];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};
         };

         case "GNT_TU22":
         {
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "R73Launcher";
            _display displayCtrl 1 lbAdd "Ch29Launcher";
            _display displayCtrl 1 lbAdd "AirBombLauncher";
            _display displayCtrl 1 lbAdd "S8Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
            _display displayCtrl 1 lbAdd "RKT_Kitchen_Rail";
            _display displayCtrl 1 lbAdd "RKTCh29Launcher";
            _display displayCtrl 1 lbAdd "RKTR27Launcher";
            _display displayCtrl 1 lbAdd "RKTR73Launcher";
            _display displayCtrl 1 lbAdd "RKT_kb500Launcher";
            _display displayCtrl 1 lbAdd "RKT_fb250Launcher";
            _display displayCtrl 1 lbAdd "GLT_Ch31_Launcher";

_mando_weapon_confs_temp = [
["Kh-22N", ["GLT_3Rnd_AS4"],["GLT_AS4_Launcher"]],
["Free Fall",["GLT_24Rnd_FAB500","GLT_36Rnd_FAB250"],["GLT_FAB500_Launcher","GLT_FAB250_Launcher"]],
["Laser Guided",["GLT_5Rnd_KAB1500","GLT_8Rnd_KAB250","GLT_8Rnd_KAB500"],["GLT_KAB1500_Launcher","GLT_KAB500_Launcher","GLT_KAB250_Launcher"]],
["Anti-Radar N",["GLT_6Rnd_CH15","GLT_2Rnd_CH31"],["GLT_CH15_Launcher","GLT_CH31_Launcher"]]
];
         };


         case "GLT_Falcon":
         {
            _display displayCtrl 1 lbAdd "GLT_AIM9X_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AIM9M_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AIM120_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AIM54_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AIM7_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AGM65_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AGM84_Launcher";
            _display displayCtrl 1 lbAdd "GLT_MK81_Launcher";
            _display displayCtrl 1 lbAdd "GLT_MK82_Launcher";
            _display displayCtrl 1 lbAdd "GLT_MK84_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AGM88_Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
            _display displayCtrl 1 lbAdd "GLT_GBU12_Launcher";
            _display displayCtrl 1 lbAdd "GLT_GBU53_Launcher";
            _display displayCtrl 1 lbAdd "GLT_AGM154_Launcher";




_mando_weapon_confs_temp = [
["CAP Medium Range", 
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AIM7","GLT_4Rnd_AIM120"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AIM7_Launcher", "GLT_AIM120_Launcher"]],

["CAP Short Range", 
["500Rnd_20mm_M61A1_GLT","GLT_8Rnd_AIM9M"],["GLT_M61A1","GLT_AIM9M_Launcher"]],

["Antitank", 
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AIM120","GLT_6Rnd_AGM65"],["GLT_M61A1","GLT_AIM9M_Launcher", "GLT_AIM120_Launcher","GLT_AGM65_Launcher"]],

["Free Fall Bombs", 
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_MK84","GLT_6Rnd_MK82"],["GLT_M61A1","GLT_AIM9M_Launcher", "GLT_MK84_Launcher","GLT_MK82_Launcher"]],

["Multirole",["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AGM65","GLT_4Rnd_AIM120","GLT_2Rnd_MK82"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AGM65_Launcher","GLT_AIM120_Launcher","GLT_MK82_Launcher"]],

["LGB",
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AIM120","GLT_6Rnd_GBU12"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AIM120_Launcher","GLT_GBU12_Launcher"]],


["Harpoon",
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AGM84"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AGM84_Launcher"]],

["SEAD",
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AGM88","GLT_6Rnd_GBU12"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AGM88_Launcher","GLT_GBU12_Launcher"]],

["JDAM", 
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AIM120","GLT_6Rnd_GBU53"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AIM120_Launcher","GLT_GBU53_Launcher"]],

["JSOW", 
["500Rnd_20mm_M61A1_GLT","GLT_2Rnd_AIM9M","GLT_2Rnd_AGM154","GLT_2Rnd_AIM120"],["GLT_M61A1","GLT_AIM9M_Launcher","GLT_AGM154_Launcher","GLT_AIM120_Launcher"]]

];

if (count (configFile>>"cfgWeapons" >> "ACE_B61BombLauncher") > 0) then
{
_mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Nuclear", ["ACE_1Rnd_B61_50"],["ACE_B61BombLauncher"]]];
};
         };

         default
         {
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH1Z";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_AH64";
            _display displayCtrl 1 lbAdd "SidewinderLaucher_F35";
            _display displayCtrl 1 lbAdd "GLT_SidewinderXLauncher";
            _display displayCtrl 1 lbAdd "GLT_SidewinderLauncher";
            _display displayCtrl 1 lbAdd "GLT_AIM120Launcher";
            _display displayCtrl 1 lbAdd "GLT_AIM7Launcher";
            _display displayCtrl 1 lbAdd "MaverickLauncher";
            _display displayCtrl 1 lbAdd "GLT_MaverickLauncher";
            _display displayCtrl 1 lbAdd "GLT_AGM84Launcher";
            _display displayCtrl 1 lbAdd "BombLauncher";
            _display displayCtrl 1 lbAdd "BombLauncherF35";
            _display displayCtrl 1 lbAdd "Mk82BombLauncher_6";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_Mk82";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_Mk84";
            _display displayCtrl 1 lbAdd "GLT_BombLauncher_LGB";
            _display displayCtrl 1 lbAdd "HellfireLauncher";
            _display displayCtrl 1 lbAdd "R73Launcher_2";
            _display displayCtrl 1 lbAdd "GLT_AGM88Launcher";
            _display displayCtrl 1 lbAdd "ACE_B61BombLauncher";
         };
      };


      _weapons = getArray (configFile>>"cfgVehicles" >> (typeOf mando_rearm_target) >> "weapons");
      _magazines = getArray (configFile>>"cfgVehicles" >> (typeOf mando_rearm_target) >> "magazines");
      for [{_i = 0},{_i < count (configFile>>"cfgVehicles" >> (typeOf mando_rearm_target) >> "Turrets")},{_i=_i+1}] do
      {
         _cfg = (configFile>>"cfgVehicles" >> (typeOf mando_rearm_target) >> "Turrets") select _i;
         _weapons = _weapons + getArray (_cfg >> "weapons");
         _magazines = _magazines + getArray (_cfg >> "magazines");
      };


      _mando_weapon_confs_temp = _mando_weapon_confs_temp + [["Default",_magazines, _weapons]];

      {
         _allowed = true;

         {
            if (_x in mando_weapons_forbidden) then
            {
               _allowed = false;
            };
         } forEach (_x select 1);

         {
            if (_x in mando_weapons_forbidden) then
            {
               _allowed = false;
            };
         } forEach (_x select 2);

         if (_allowed) then
         {
            mando_weapon_confs = mando_weapon_confs + [_x];
         };

      } forEach _mando_weapon_confs_temp;


      {
         _display displayCtrl 5 lbAdd (_x select 0);
      } forEach mando_weapon_confs;


      {
         (_display displayCtrl 3) lbAdd _x;
      } forEach weapons mando_rearm_target;

      {
         (_display displayCtrl 4) lbAdd _x;
      } forEach magazines mando_rearm_target;


      []spawn
      {
         Sleep 0.25;
         ((findDisplay 1) displayCtrl 1) lbSetCurSel 0;
      };


      _msg = "Flares: ";
      _var = mando_rearm_target getVariable "mando_maxflares";
      if (!isNil "_var") then
      {
//         mando_rearm_target setVariable ["mando_flaresleft", _var, true];
         _msg = _msg + format["%1/%2", mando_rearm_target getVariable "mando_flaresleft",_var];
      } 
      else
      {
         _msg = _msg + "0/0";
      };
      (_display displayCtrl 6) lbAdd _msg;

      for [{_i = 0},{_i < 8},{_i = _i + 1}] do
      {
         _msg = format["Virtual weapon %1: ", _i];
         _var = mando_rearm_target getVariable format["mando_maxmissiles%1", _i];
         if (!isNil "_var") then
         {
//            mando_rearm_target setVariable [format["mando_missilesleft%1", _i], _var, true];
            _msg = _msg + format["%1/%2", mando_rearm_target getVariable format["mando_missilesleft%1", _i], _var];
         } 
         else
         {
            _msg = _msg + "0/0";
         };
         (_display displayCtrl 6) lbAdd _msg;
      };

      showCinemaBorder false;
      mando_weapon_confs_cam_angh = 0;
      mando_weapon_confs_cam_dist = 20;
      mando_weapon_confs_cam = "camera" camcreate [0,0,0];
      mando_weapon_confs_cam cameraeffect ["internal", "back"];
      mando_weapon_confs_cam camSetTarget mando_rearm_target;
      mando_weapon_confs_cam camSetRelPos [0,mando_weapon_confs_cam_dist,0.5];
      mando_weapon_confs_cam camSetFov 1.0;
      mando_weapon_confs_cam camCommit 0;


      []spawn mando_update_source_level;

      (_display displayCtrl 11) ctrlSetText (mando_missile_path+"mandotarget_aimcircle.paa");
      (_display displayCtrl 11) ctrlSetTextColor [1,1,1,0.5]; 
   };


   case "onUnLoad":
   {
      mando_weapon_confs_cam cameraeffect ["terminate", "back"];
      camDestroy mando_weapon_confs_cam;
      mandotarget_disp_on = mandotarget_disp_on_old;
      mando_rearm_source = objNull;
   };


   case "CALL_CFG_CHANGE":
   {
      lbClear ((findDisplay 1) displayCtrl 2);
      _weapon = ((findDisplay 1) displayCtrl 1) lbText (lbCursel ((findDisplay 1) displayCtrl 1));
      _magazines = getArray (configFile>>"cfgWeapons" >> _weapon >> "magazines");
      {
         (findDisplay 1) displayCtrl 2 lbAdd _x;
      } forEach _magazines;

      []spawn
      {
         Sleep 0.25;
         ((findDisplay 1) displayCtrl 2) lbSetCurSel 0;
      };
   };


   case "CALL_CFG_ADD":
   {   
      _weapon = ((findDisplay 1) displayCtrl 1) lbText (lbCursel ((findDisplay 1) displayCtrl 1));
      _magazine = ((findDisplay 1) displayCtrl 2) lbText (lbCursel ((findDisplay 1) displayCtrl 2));

      if ((_weapon != "") && (_magazine != "")) then
      {
         if (!(_weapon in (weapons mando_rearm_target))) then
         {
            mando_rearm_target addMagazine _magazine;
            mando_rearm_target addWeapon _weapon;

            ((findDisplay 1) displayCtrl 3) lbAdd _weapon;
         }
         else
         {
            mando_rearm_target addMagazine _magazine;
         };
         ((findDisplay 1) displayCtrl 4) lbAdd _magazine;
      };
   };

   case "CALL_CFG_CLEAR":
   {   
      _weapon = ((findDisplay 1) displayCtrl 3) lbText (lbCursel ((findDisplay 1) displayCtrl 3));
      if (_weapon != "") then
      {
         _magazines = getArray (configFile>>"cfgWeapons" >> _weapon >> "magazines");

         {
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;
            mando_rearm_target removeMagazine _x;

            _continue = true;
            while {_continue} do
            {
               _found = false;
               for [{_i=0},{ (_i < lbSize ((findDisplay 1) displayCtrl 4)) && !_found},{_i=_i+1}] do
               {
                  if ((((findDisplay 1) displayCtrl 4) lbText _i) == _x)  then
                  {
                     _found = true;
                     ((findDisplay 1) displayCtrl 4) lbDelete _i;
                  };
               };
  
               if (!_found) then
               {
                  _continue = false;
               };
            };
 
         } forEach _magazines;


_is_gun = [_weapon] call mando_is_gun;
_is_rocket = [_weapon] call mando_is_rocket;



         if (!_is_gun && !_is_rocket) then
         {
            mando_rearm_target removeWeapon _weapon;
            ((findDisplay 1) displayCtrl 3) lbDelete (lbCursel ((findDisplay 1) displayCtrl 3));
         };

         _found = false;
         for [{_i=0},{ (_i < lbSize ((findDisplay 1) displayCtrl 1)) && !_found},{_i=_i+1}] do
         {  
            if ((((findDisplay 1) displayCtrl 1) lbText _i) == _weapon)  then
            {
               _found = true;
            };
         };
   
         if (!_found) then 
         {
            ((findDisplay 1) displayCtrl 1) lbAdd _weapon;
         };
      };
   };

   case "CALL_CFG_CLEARM":
   {   
      _magazine = ((findDisplay 1) displayCtrl 4) lbText (lbCursel ((findDisplay 1) displayCtrl 4));
      if (_magazine != "") then
      {
         ((findDisplay 1) displayCtrl 4) lbDelete (lbCursel ((findDisplay 1) displayCtrl 4));
         mando_rearm_target removeMagazine _magazine;
      };
   };

   case "CALL_PRECFG_CHANGE":
   {
      _conf = lbCursel ((findDisplay 1) displayCtrl 5);
      lbClear ((findDisplay 1) displayCtrl 7);

      ((findDisplay 1) displayCtrl 7) lbAdd "Weapons ------->";

      {
         ((findDisplay 1) displayCtrl 7) lbAdd _x;
      } forEach ((mando_weapon_confs select _conf) select 2);
      ((findDisplay 1) displayCtrl 7) lbAdd "  ";

      ((findDisplay 1) displayCtrl 7) lbAdd "Magazines ------->";
      {
         ((findDisplay 1) displayCtrl 7) lbAdd _x;
      } forEach ((mando_weapon_confs select _conf) select 1);
   };

   case "CALL_REARM":
   {
      if ((!isNull mando_rearm_source) && (alive mando_rearm_source)) then
      {
         _lvl = mando_rearm_source getVariable "mando_source_level";
      }
      else
      {
         _lvl = 0;
      };

      if ((_lvl > 0) && (alive mando_rearm_source)) then
      {
         mando_rearm_source say3D "mando_rearm";
         _conf = lbCursel ((findDisplay 1) displayCtrl 5);
         if (_conf >= 0) then
         {
            _weapons = weapons mando_rearm_target;
            _magazines = magazines mando_rearm_target;

            {
               if (
                 (!([_x] call mando_is_gun) && !([_x] call mando_is_rocket)) || 
                 ((count (configFile>>"cfgVehicles" >> (typeOf mando_rearm_target) >> "Turrets") == 0) && !([_x] call mando_is_gun))) then
               {
                  mando_rearm_target removeWeapon _x;
               };
            } forEach _weapons;

            {
               if (!([_x] call mando_is_gun_rocket_ammo)) then
               {
                  mando_rearm_target removeMagazine _x;
               };
            } forEach _magazines;

            lbClear ((findDisplay 1) displayCtrl 3);
            lbClear ((findDisplay 1) displayCtrl 4);

            {

               if (!([_x] call mando_is_gun_rocket_ammo)) then
               {               

                  mando_rearm_target addMagazine _x;
               };

               ((findDisplay 1) displayCtrl 4) lbAdd _x;
            } forEach ((mando_weapon_confs select _conf) select 1);


            {
               if ((!([_x] call mando_is_gun) && !([_x] call mando_is_rocket)) || ((count (configFile>>"cfgVehicles" >> (typeOf mando_rearm_target) >> "Turrets") == 0) && !([_x] call mando_is_gun))) then
               {
                  mando_rearm_target addWeapon _x; 
               };
               ((findDisplay 1) displayCtrl 3) lbAdd _x;
            } forEach ((mando_weapon_confs select _conf) select 2);
         };

         lbClear ((findDisplay 1) displayCtrl 6);
         _msg = "Flares: ";
         _var = mando_rearm_target getVariable "mando_maxflares";
         if (!isNil "_var") then
         {
            mando_rearm_target setVariable ["mando_flaresleft", _var, true];
            _msg = _msg + format["%1/%2", mando_rearm_target getVariable "mando_flaresleft",_var];
         } 
         else
         {
            _msg = _msg + "0/0";
         };
         ((findDisplay 1) displayCtrl 6) lbAdd _msg;

         for [{_i = 0},{_i < 8},{_i = _i + 1}] do
         {
            _msg = format["Virtual weapon %1: ", _i];
            _var = mando_rearm_target getVariable format["mando_maxmissiles%1", _i];
            if (!isNil "_var") then
            {
               mando_rearm_target setVariable [format["mando_missilesleft%1", _i], _var, true];
               _msg = _msg + format["%1/%2", mando_rearm_target getVariable format["mando_missilesleft%1", _i], _var];
            } 
            else
            {
               _msg = _msg + "0/0";
            };
            ((findDisplay 1) displayCtrl 6) lbAdd _msg;
         };

         mando_rearm_source setVariable ["mando_source_level", _lvl - 5, true];
      }
      else
      {
         playSound "mando_denied";
      };
   };

   case "onMouseClick":
   {


      _pos = [_params select 2, _params select 3];
      _found = false;
      {
         _poss = worldToScreen (_x modelToWorld [0,0,0]);
         if ((count _poss == 2) && (speed _x < 1) && (alive _x)) then
         {
            _dist = sqrt(((_poss select 0)-(_pos select 0))^2 + ((_poss select 1)-(_pos select 1))^2);
            if (_dist < 0.09) then
            {
               _found = true;
               mando_rearm_source = _x;
            };
         };
      } forEach mando_rearm_sources;

      if (_found) then
      {
         playSound "mando_target1";
      };
   };

   case "onMouseZChanged":
   {
      if ((_params select 1) > 0.1) then
      {
         if (mando_weapon_confs_cam_dist > 10) then
         {
            mando_weapon_confs_cam_dist = mando_weapon_confs_cam_dist - 5;
         };
      }
      else
      {
         if ((_params select 1) < -0.1) then
         {
            if (mando_weapon_confs_cam_dist < 50) then
            {
               mando_weapon_confs_cam_dist = mando_weapon_confs_cam_dist + 5;
            };
         };
      };
      mando_weapon_confs_cam camSetRelPos [sin(mando_weapon_confs_cam_angh)*mando_weapon_confs_cam_dist,cos(mando_weapon_confs_cam_angh)*mando_weapon_confs_cam_dist,0.5];
      mando_weapon_confs_cam camCommit 0;
   };

   case "CALL_PAN_LEFT":
   {
      mando_weapon_confs_cam_angh = mando_weapon_confs_cam_angh + 1;
      if (mando_weapon_confs_cam_angh > 360) then
      {
         mando_weapon_confs_cam_angh = mando_weapon_confs_cam_angh - 360;
      };

      mando_weapon_confs_cam camSetRelPos [sin(mando_weapon_confs_cam_angh)*mando_weapon_confs_cam_dist,cos(mando_weapon_confs_cam_angh)*mando_weapon_confs_cam_dist,0.5];
      mando_weapon_confs_cam camCommit 0;
   };

   case "CALL_PAN_RIGHT":
   {
      mando_weapon_confs_cam_angh = mando_weapon_confs_cam_angh - 1;
      if (mando_weapon_confs_cam_angh < 0) then
      {
         mando_weapon_confs_cam_angh = 359 + mando_weapon_confs_cam_angh;
      };

      mando_weapon_confs_cam camSetRelPos [sin(mando_weapon_confs_cam_angh)*mando_weapon_confs_cam_dist,cos(mando_weapon_confs_cam_angh)*mando_weapon_confs_cam_dist,0.5];
      mando_weapon_confs_cam camCommit 0;
   };

};

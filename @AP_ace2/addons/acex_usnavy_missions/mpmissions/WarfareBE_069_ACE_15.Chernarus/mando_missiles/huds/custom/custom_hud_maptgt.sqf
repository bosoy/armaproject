/* MMA HUD customization - Ground Mode MAP TGT Mandoble - July 2010 */

DisableSerialization;

mando_getmaptgt_setup = 
{
   private["_event", "_params", "_display", "_unit", "_ttypes", "_target","_marker_name"];
   _event = _this select 0;
   _params = _this select 1;

   if (_event == "onLoad") then
   {
      onMapSingleClick "true";
      _display = _params select 0;
      (_display displayCtrl 100) ctrlSetText (mando_missile_path+"mfds\raptor6_mfd1.paa");

      _unit = vehicle player;
      _var = _unit getVariable "mando_scud_type";
      if (isNil "_var") then
      {
         (_display displayCtrl 102) ctrlSetText "";
         (_display displayCtrl 103) ctrlSetText "";
         (_display displayCtrl 102) ctrlEnable false;
         (_display displayCtrl 103) ctrlEnable false;
      }
      else
      {
         if (_var < 2) then
         {
            (_display displayCtrl 102) ctrlSetText "";
            (_display displayCtrl 103) ctrlSetText "";
            (_display displayCtrl 102) ctrlEnable false;
            (_display displayCtrl 103) ctrlEnable false;

         }
         else
         {
            if ((_var == 2) || (_var == 4)) then
            {
               (_display displayCtrl 99) ctrlSetText "Select or change target" + " (Ground burst)";
            }
            else
            {
               (_display displayCtrl 99) ctrlSetText "Select or change target" + " (Air burst)";
            };
         };
      };

      _ttypes = _unit getVariable "mando_target_types";
      _target = objNull;
      if ((_ttypes select 0) == "GROUND") then
      {   
         _target = _unit GetVariable "mando_current_target";
         if (!isNull _target) then
         {
            _marker_name = "mk_mando_maptgt";
            if (getMarkerColor _marker_name == "") then
            {
               createMarkerLocal ["mk_mando_maptgt", getPos _target];
               _marker_name setMarkerTypeLocal "Attack";
               _marker_name setMarkerColorLocal "ColorWhite";
               _marker_name setMarkerSizeLocal [0.55, 0.55];
               _marker_name setMarkerTextLocal "Target";
            }
            else 
            {
               _marker_name setMarkerPosLocal getPos _target;
            };
         };


         []spawn 
         {
            private["_unit", "_ttypes", "_target"];
            _unit = vehicle player;
            createMarkerLocal ["mk_mando_maptgt_lnk", [0,0]];
            "mk_mando_maptgt_lnk" setMarkerShapeLocal "RECTANGLE";
            "mk_mando_maptgt_lnk" setMarkerColorLocal "ColorWhite";
            "mk_mando_maptgt_lnk" setMarkerSizeLocal [0, 0];
         
            createMarkerLocal ["mk_mando_maptgt_dir", getPos _unit];
            "mk_mando_maptgt_dir" setMarkerTypeLocal "Move";
            "mk_mando_maptgt_dir" setMarkerColorLocal "ColorWhite";
            "mk_mando_maptgt_dir" setMarkerSizeLocal [0.55, 0.55];
            "mk_mando_maptgt_dir" setMarkerDirLocal (getDir _unit)-90;

            Sleep 0.5;
            
            while {!isNull (findDisplay 24000)} do
            {
               _ttypes = _unit getVariable "mando_target_types";
               if ((_ttypes select 0) == "GROUND") then
               {   
                  _target = _unit GetVariable "mando_current_target";

                  if (!isNull _target) then
                  {
                     _ang = ((getPos _target select 0)-(getPos _unit select 0)) atan2 ((getPos _target select 1)-(getPos _unit select 1));
                     _dist = sqrt (((getPos _target select 0)-(getPos _unit select 0))^2 + ((getPos _target select 1)-(getPos _unit select 1))^2);
                     "mk_mando_maptgt_lnk" setMarkerPosLocal [(getPos _unit select 0)+sin(_ang)*_dist/2, (getPos _unit select 1)+cos(_ang)*_dist/2];
                     "mk_mando_maptgt_lnk" setMarkerDirLocal _ang;
                     "mk_mando_maptgt_lnk" setMarkerSizeLocal [2, _dist/2];
                  }
                  else
                  {
                     "mk_mando_maptgt_lnk" setMarkerSizeLocal [0, 0];
                  };
               }
               else
               {
                  "mk_mando_maptgt_lnk" setMarkerSizeLocal [0, 0];
               };

               "mk_mando_maptgt_dir" setMarkerDirLocal (getDir _unit)-90;
               "mk_mando_maptgt_dir" setMarkerPosLocal (getPos _unit);
               Sleep 0.1;
            };            
         };
      };
   }
   else
   {
      if (_event == "onUnload") then
      {
         deleteMarker "mk_mando_maptgt";
         deleteMarker "mk_mando_maptgt_lnk";
         deleteMarker "mk_mando_maptgt_dir";
         if (!isNil "mando_last_onmapsclick") then
         {
            onMapSingleClick mando_last_onmapsclick;
         }
         else
         {
            onMapSingleClick "";
         };
      }
      else
      {
         _display = findDisplay 24000;
         if (_event == "on_btn1") then
         {
            _var = (vehicle player) getVariable "mando_scud_type";
	    if (_var == 3) then
	    {
               vehicle player setVariable ["mando_scud_type", 2];
               (_display displayCtrl 99) ctrlSetText "Select or change target" + " (Ground burst)";
            }
	    else
	    {
	       if (_var == 5) then
	       {
                  vehicle player setVariable ["mando_scud_type", 4];
                  (_display displayCtrl 99) ctrlSetText "Select or change target" + " (Ground burst)";
               };
	    };
         }
         else
         {
            _var = (vehicle player) getVariable "mando_scud_type";
	    if (_var == 2) then
	    {
               vehicle player setVariable ["mando_scud_type", 3];
               (_display displayCtrl 99) ctrlSetText "Select or change target" + " (Air burst)";
            }
	    else
	    {
	       if (_var == 4) then
	       {
                  vehicle player setVariable ["mando_scud_type", 5];
                  (_display displayCtrl 99) ctrlSetText "Select or change target" + " (Air burst)";
               };
	    };
         };
      };
   };
};


mando_getmaptgt = 
{
   private ["_unit", "_ttypes", "_target", "_marker_name"];
   _unit = vehicle player;
   _ttypes = _unit getVariable "mando_target_types";
   _target = objNull;
   if ((_ttypes select 0) == "GROUND") then
   {   
      if (((_this select 1) select 1) == 0) then
      {
         if (!((_this select 1) select 4)) then
         {
            _marker_name = "mk_mando_maptgt";
            if (getMarkerColor _marker_name == "") then
            {
               createMarkerLocal [_marker_name, (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3])];
               _marker_name setMarkerTypeLocal "Attack";
               _marker_name setMarkerColorLocal "ColorWhite";
               _marker_name setMarkerSizeLocal [0.55, 0.55];
               _marker_name setMarkerTextLocal "Target";
            }
            else 
            {
               _marker_name setMarkerPosLocal (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]);
            };

            mando_ground_hud_target setPos (((_this select 1) select 0) ctrlMapScreenToWorld [(_this select 1) select 2, (_this select 1) select 3]);
            _unit setVariable ["mando_current_target", mando_ground_hud_target];
            playSound "mando_target1";
         };
      };
   };
};

private["_type", "_veh"];
_type = _this select 0;
_veh = vehicle player;

switch (_type) do
{
   case "F16":
   {
      [] spawn  
      {
         Sleep 4; 
         while {!mando_exit_hud} do
         {
            if (!isNull (UINameSpace GetVariable "mandotarget_disp") && (mando_hud_missile > -1)) then
            {
               _weapon = (mando_missileidxbase select mando_hud_missile) select 1;
               _ttypes = vehicle player getVariable "mando_target_types";
               if (((_ttypes select 0) == "GROUND") && (_weapon in ["GLT_KAB500SE_Launcher","GLT_GBU39_Launcher","GLT_GBU53_Launcher","GLT_AGM154_Launcher","sfp_rbs15_launcher","GLT_MOAB_Launcher","HEXA_AASMLauncher"])) then
               {
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetTextColor [1.0, 1.0, 1.0, 0.9];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetStructuredText ParseText Format ["<t size='1.2'>GPS Targeting: %1</t>", mando_keyspecialname];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.1875, 0.2250, 0.2000];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlCommit 0;
               }
               else
               {
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetTextColor [1.0, 1.0, 1.0, 0];
               };
            };
            Sleep 1; 
         };
      };
   };

   case "EF2000":
   {
      [] spawn  
      {
         Sleep 4; 
         while {!mando_exit_hud} do
         {
            if (!isNull (UINameSpace GetVariable "mandotarget_disp") && (mando_hud_missile > -1)) then
            {
               _weapon = (mando_missileidxbase select mando_hud_missile) select 1;
               _ttypes = vehicle player getVariable "mando_target_types";
               if (((_ttypes select 0) == "GROUND") && (_weapon =="RKSL_stormshadow_Launcher")) then
               {
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetStructuredText ParseText Format ["<t size='1.2'>GPS Targeting: %1</t>", mando_keyspecialname];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.1875, 0.2250, 0.2000];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlCommit 0;
               }
               else
               {
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetTextColor [1.0, 1.0, 1.0, 0];
               };
            };
            Sleep 1; 
         };
      };
   };

   case "MLRS":
   {
      [] spawn  
      {
         Sleep 4; 
         while {!mando_exit_hud} do
         {
            if (!isNull (UINameSpace GetVariable "mandotarget_disp") && (mando_hud_missile > -1)) then
            {
               _ttypes = vehicle player getVariable "mando_target_types";
               if ((_ttypes select 0) == "GROUND") then
               {
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetStructuredText ParseText Format ["<t size='1.2'>GPS Targeting: %1</t>", mando_keyspecialname];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.1875, 0.2250, 0.2000];
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlCommit 0;
               }
               else
               {
                  ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 79) CtrlSetTextColor [1.0, 1.0, 1.0, 0];
               };
            };
            Sleep 1; 
         };
      };
   };

};

while {!mando_exit_hud} do
{
   if (mando_key_pressed == mando_keyspecial) then
   {	
      _continue = false;
      if ((_type == "F16") || (_type == "EF2000")) then
      {
         if (!isNull (UINameSpace GetVariable "mandotarget_disp") && (mando_hud_missile > -1)) then
         {
            _weapon = (mando_missileidxbase select mando_hud_missile) select 1;
            _ttypes = vehicle player getVariable "mando_target_types";
            if (((_ttypes select 0) == "GROUND") && (_weapon in ["GLT_KAB500SE_Launcher","GLT_GBU39_Launcher","GLT_GBU53_Launcher","GLT_AGM154_Launcher","sfp_rbs15_launcher","GLT_MOAB_Launcher","HEXA_AASMLauncher"])) then
            {
               _continue = true;
            };
         };
      }
      else
      {
         _continue = true;
      };

      if (_continue) then
      {
		 mando_key_pressed = -1;	  
         if (isNull(findDisplay 24000)) then
         {
            _ttypes = _veh getVariable "mando_target_types";
            _target = objNull;
            if ((_ttypes select 0) == "GROUND") then
            {   
               _ok = createDialog "Mando_getmaptgt";
            };
         }
         else
         {
            closeDialog 24000;
         };
      };
   };

   Sleep 0.5;
};
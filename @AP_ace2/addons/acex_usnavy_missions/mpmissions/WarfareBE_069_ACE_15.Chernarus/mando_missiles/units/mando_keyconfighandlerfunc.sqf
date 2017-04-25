MISST_DLGMISSILEKEYS    = 22900;
MISKEY_OK               = 22901;
MISKEY_CANCEL           = 22902;
MISKEY_ECM              = 22903;
MISKEY_ECMKEY           = 22904;
MISKEY_FIRE             = 22905;
MISKEY_FIREKEY          = 22906;
MISKEY_FLARES           = 22907;
MISKEY_FLARESKEY        = 22908;
MISKEY_ACTION           = 22909;
MISKEY_MODE             = 22911;
MISKEY_MODKEY           = 22912;


private["_event", "_params", "_keycode"];
_event = _this select 0;
_params = _this select 1;

switch (_event) do
{
   case "onKeyDown":
   {
      _keycode = _params select 1;
      if (mando_keysconf_state == 0) then
      {
         mando_keymode_temp = _keycode;
         mando_keymodename_temp = keyname _keycode;

         ctrlSetText [MISKEY_MODEKEY, format["%1", mando_keymodename_temp]];
         ctrlSetText [MISKEY_ACTION, "Press key to Fire Missile"];

         mando_keysconf_state = 1;
      }
      else
      {
         if (mando_keysconf_state == 1) then  
         {
            mando_keyfire_temp = _keycode;
            mando_keyfirename_temp = keyname _keycode;

            ctrlSetText [MISKEY_FIREKEY, format["%1", mando_keyfirename_temp]];
            ctrlSetText [MISKEY_ACTION, "Press key for Flares/Chaff"];

            mando_keysconf_state = 2;
         }
         else
         {
            if (mando_keysconf_state == 2) then  
            {
               mando_keyflare_temp = _keycode;
               mando_keyflarename_temp = keyname _keycode;

               ctrlSetText [MISKEY_FLARESKEY, format["%1", mando_keyflarename_temp]];
               ctrlSetText [MISKEY_ACTION, "Press key for ECM"];

               mando_keysconf_state = 3;
            }
            else
            {
               if (mando_keysconf_state == 3) then  
               {
                  mando_keyecm_temp = _keycode;
                  mando_keyecmname_temp = keyname _keycode;
   
                  ctrlSetText [MISKEY_ECMKEY, format["%1", mando_keyecmname_temp]];
                  ctrlSetText [MISKEY_ACTION, "Configuration finished"];
  
                  mando_keysconf_state = 4;
               };
            };
         };
      };
   };

   case "onAccept":
   {
      closeDialog MISST_DLGMISSILEKEYS;

      mando_keymode     = mando_keymode_temp;
      mando_keymodename = mando_keymodename_temp;

      mando_keyfire      = mando_keyfire_temp;
      mando_keyfirename  = mando_keyfirename_temp;

      mando_keyflare     = mando_keyflare_temp;
      mando_keyflarename = mando_keyflarename_temp;

      mando_keyecm      = mando_keyecm_temp;
      mando_keyecmname  = mando_keyecmname_temp;

   };

   case "onRepeat":
   {
      mando_keysconf_state = 0;
      ctrlSetText [MISKEY_ACTION, "Press key to switch HUD mode"];
   };

   case "onCancel":
   {
      closeDialog MISST_DLGMISSILEKEYS;
   };
};
true
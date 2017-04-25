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
MISKEY_MODEKEY          = 22912;


private["_ok"];
Sleep 0.2;
_ok = createDialog "DlgMissileKeys";
if (_ok) then
{
   mando_keyecm_temp = mando_keyecm;
   mando_keyecmname_temp = mando_keyecmname;

   mando_keyfire_temp = mando_keyfire;
   mando_keyfirename_temp = mando_keyfirename;

   mando_keyflare_temp = mando_keyflare;
   mando_keyflarename_temp = mando_keyflarename_temp;

   mando_keymode_temp = mando_keymode;
   mando_keymodename_temp = mando_keymodename;


   mando_keysconf_state = 0;
   ctrlSetText [MISKEY_MODEKEY, format["%1", mando_keymodename]];
   ctrlSetText [MISKEY_ECMKEY, format["%1", mando_keyecmname]];
   ctrlSetText [MISKEY_FIREKEY, format["%1", mando_keyfirename]];
   ctrlSetText [MISKEY_FLARESKEY, format["%1", mando_keyflarename]];

   ctrlSetText [MISKEY_ACTION, "Press key to switch HUD mode"];
};

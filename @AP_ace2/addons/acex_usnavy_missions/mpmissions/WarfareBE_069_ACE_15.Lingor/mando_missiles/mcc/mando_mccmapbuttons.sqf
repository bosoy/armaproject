/*mando MCC map buttons text and color control
 mando_mccmapbuttons.sqf v1.0
 July 2007 Mandoble
 
 
 
 Parameters:
    button pressed
*/
disableSerialization;

MCC_DLGMISSILECENTER    = 21900;
MCC_NOMAP		= 21906;
MCC_MAPCONTACT		= 21907;
MCC_MAPTARGET		= 21908;
MCC_MAPMCC              = 21941;
MCC_NAVMARK             = 21942;

private["_button", "_mccdisplay", "_black", "_green"];

_button = _this select 0;
_mccdisplay = findDisplay MCC_DLGMISSILECENTER;
_black = [0,0,0,1];
_green = [0,1,0,1];

switch (_button) do
{
   case MCC_NOMAP:
   {
      (_mccdisplay displayCtrl MCC_NOMAP) ctrlSetTextColor _green;
      (_mccdisplay displayCtrl MCC_MAPCONTACT) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPTARGET) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPMCC) ctrlSetTextColor _black;
      mando_map=0;
   };

   case MCC_MAPCONTACT:
   {
      (_mccdisplay displayCtrl MCC_NOMAP) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPCONTACT) ctrlSetTextColor _green;
      (_mccdisplay displayCtrl MCC_MAPTARGET) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPMCC) ctrlSetTextColor _black;
      mando_map=1;
   };

   case MCC_MAPTARGET:
   {
      (_mccdisplay displayCtrl MCC_NOMAP) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPCONTACT) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPTARGET) ctrlSetTextColor _green;
      (_mccdisplay displayCtrl MCC_MAPMCC) ctrlSetTextColor _black;
      mando_map=2;
   };

   case MCC_MAPMCC:
   {
      (_mccdisplay displayCtrl MCC_NOMAP) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPCONTACT) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPTARGET) ctrlSetTextColor _black;
      (_mccdisplay displayCtrl MCC_MAPMCC) ctrlSetTextColor _green;
      mando_map=3;
   };

   case MCC_NAVMARK:
   {
      if (mando_navmark==0) then
      {
         mando_navmark=1;
         (_mccdisplay displayCtrl MCC_NAVMARK) ctrlSetText "MARK";
      }
      else
      { 
         mando_navmark=0;
         (_mccdisplay displayCtrl MCC_NAVMARK) ctrlSetText "NAV";
      };
   };
};
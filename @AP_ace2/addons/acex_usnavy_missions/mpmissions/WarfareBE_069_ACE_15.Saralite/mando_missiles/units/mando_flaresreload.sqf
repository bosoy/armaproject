// This script is executed automatically by action menu activated by players

private["_ammov", "_sam", "_damage", "_ammoleft", "_samsleft", "_maxsams", "_samsneeded", "_samstoload"];
_ammov = ((_this select 3) select 0);
_sam   = vehicle player;
_damage  = damage _ammov;
if (_damage > 0.1) then
{
   _ammoleft = 0;
}
else
{
   _ammoleft = floor (100 - 100*_damage/0.1);
};

_samsleft = _sam getVariable "mando_flaresleft";
_maxsams  = _sam getVariable "mando_maxflares";

hint format["Launcher:%1, Flares/Chaff left:%2, Max Flares/Chaff:%3", _sam, _samsleft, _maxsams];

if (_maxsams == _samsleft) then
{
   titleText["\n\nYou already have maximum number of flares/chaff", "PLAIN DOWN"];
}
else
{
   if (_ammoleft == 0) then
   {
      titleText["\n\nNo flares/chaff available to load", "PLAIN DOWN"];
   }
   else
   {
      titleText["\n\nLoading fares/chaff ...", "PLAIN DOWN"];

      _samsneeded = _maxsams - _samsleft;
      _samstoload = _samsneeded min _ammoleft;
      _ammov setDamage (_damage + _samstoload*0.1/100);

      Sleep 10;
      _sam setVariable ["mando_flaresleft", _samsleft + _samstoload, true];

      if (_samstoload == 1) then
      {
         titleText[format["\n\n%1 flare/chaff pack loaded", _samstoload], "PLAIN DOWN"];
      };

      if (_samstoload > 1) then
      {
         titleText[format["\n\n%1 flares/chaff packs loaded", _samstoload], "PLAIN DOWN"];
      };
      Sleep 2;

      if (!isNull mandotarget_disp) then
      {
         (mandotarget_disp displayCtrl 111) ctrlSetText format["[%1/%2]",(vehicle player getVariable "mando_flaresleft"), (vehicle player getVariable "mando_maxflares")];
      };
   };
};
// This script is executed automatically by action menu activated by players
private["_ammov", "_sam", "_damage", "_ammoleft", "_samsleft", "_samslefttotal", "_samsneeded", "_samstoload", "_maxsams", "_maxsamstotal", "_i", "_msg", "_var"];

_ammov = ((_this select 3) select 0);
_sam   = vehicle player;
_damage  = damage _ammov;

_ammoleft = 0;

_samsleft = [0,0,0,0,0,0,0,0];
_samslefttotal = 0;
_samsneeded    = 0;
_samstoload    = 0;


_maxsams       = [0,0,0,0,0,0,0,0];
_maxsamstotal  = 0;

_i             = 0;

_msg           = format["Launcher:%1\n", _sam];


if (_damage > 0.1) then
{
   _ammoleft = 0;
}
else
{
   _ammoleft = floor (100 - 100*_damage/0.1);
};

for [{_i = 0},{_i < 8},{_i = _i+1}] do
{
   _var = _sam getVariable format["mando_missilesleft%1", _i];
   if (!isNil "_var") then
   {
      _samsleft set [_i,(_sam getVariable format["mando_missilesleft%1", _i])];
      _samslefttotal = _samslefttotal + (_samsleft select _i);
      _maxsams set [_i, (_sam getVariable format["mando_maxmissiles%1", _i])];
      _maxsamstotal = _maxsamstotal + (_maxsams select _i);
      _msg = _msg + format["Missiles type%1 left: %2, Max missiles type%3: %4\n", _i, _samsleft select _i, _i, _maxsams select _i];
   };
};

hint _msg;

_msg = "\n\n";
if (_maxsamstotal > _samslefttotal) then
{
   if (_ammoleft > 0) then
   {
      titleText["\n\nLoading missiles ...", "PLAIN DOWN"];
      Sleep 5;  
      
      for [{_i = 0},{_i < 8},{_i = _i+1}] do
      {
         if (_ammoleft > 0) then
         { 
            _samsneeded = (_maxsams select _i) - (_samsleft select _i);

            if (_samsneeded > 0) then
            {
               _samstoload = _samsneeded min _ammoleft;

               _ammov setDamage (_damage + _samstoload*0.1/100); // <- CAMBIAR POR GLOBAL DE VEHICULO

               _ammoleft = _ammoleft - _samstoload;
               _sam setVariable [format["mando_missilesleft%1", _i], (_samsleft select _i) + _samstoload, true];
            
               _msg = _msg + format["%1 missile type%2 loaded\n", _samstoload, _i];

               Sleep 2; 
            };
         };
      };

      // Actualizar contadores en el HUD
      if (!isNull mandotarget_disp) then
      {
         if ((vehicle player getVariable format["mando_maxmissiles%1", (mando_missileidxbase select 0) select 0]) > 0) then
         {
            (mandotarget_disp displayCtrl 109) ctrlSetText format["[%1/%2]",(vehicle player getVariable format["mando_missilesleft%1", (mando_missileidxbase select 0) select 0]),(vehicle player getVariable format["mando_maxmissiles%1", (mando_missileidxbase select 0) select 0])];
         };

         if ((vehicle player getVariable format["mando_maxmissiles%1", (mando_missileidxbase select 1) select 0]) > 0) then
         {
            (mandotarget_disp displayCtrl 110) ctrlSetText format["[%1/%2]",(vehicle player getVariable format["mando_missilesleft%1", (mando_missileidxbase select 1) select 0]),(vehicle player getVariable format["mando_maxmissiles%1", (mando_missileidxbase select 1) select 0])];
         };
      };

      titleText [_msg, "PLAIN DOWN"];
   }
   else
   {
      titleText["\n\nNo missiles available to load", "PLAIN DOWN"];
   };
}
else
{
   titleText["\n\nYou already have maximum number of missiles", "PLAIN DOWN"];
};
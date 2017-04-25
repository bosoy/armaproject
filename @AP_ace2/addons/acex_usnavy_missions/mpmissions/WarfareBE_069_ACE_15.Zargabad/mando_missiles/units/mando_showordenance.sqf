/* ShowOrdenance.sqf
By Mandoble June 2007


*/
_unit = vehicle player;
_var = 0;

_msg = "";
for[{_i = 0},{_i < 8},{_i = _i + 1}] do
{
   _var = _unit getVariable format["mando_maxmissiles%1", _i];

   if (!(isNil "_var")) then
   {
      _msg = _msg + format["%1 Missiles type%2 left (%3 max)\n", _unit getVariable format["mando_missilesleft%1",_i], _i, _unit getVariable format["mando_maxmissiles%1", _i]];
   };
};

if (_unit getVariable "mando_maxflares" > 0) then
{
   _msg = _msg + format["%1 Chaff/Flares left left (%2 max)\n", _unit getVariable "mando_flaresleft", _unit getVariable "mando_maxflares"];
};
titleText[_msg, "PLAIN DOWN"];

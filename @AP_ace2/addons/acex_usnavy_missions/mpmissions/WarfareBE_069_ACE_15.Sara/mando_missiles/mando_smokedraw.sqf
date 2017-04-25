/*mando smokedraw
mando_smokedraw.sqf v1.2
April 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private["_mis", "_script", "_res"];
while {true} do
{
   waitUntil {mando_missilesmoke};
   _mis = mando_missilesmoke_mis;
   if (!local _mis) then
   {
      _script = mando_missilesmoke_script;
      _res = [_mis]execVM _script;
   };
   mando_missilesmoke = false;
};
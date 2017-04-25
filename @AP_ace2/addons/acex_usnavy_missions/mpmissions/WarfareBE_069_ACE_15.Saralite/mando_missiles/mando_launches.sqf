/*mando launches
mando_launches.sqf v1.0
April 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private["_mis", "_script", "_res"];
while {true} do
{
   waitUntil {mando_launch_req};
   _mis = mando_launch_mis;
   if (!local _mis) then
   {
      _script = mando_launch_script;
      _res = [_mis]execVM _script;
   };
   mando_launch_req = false;
};
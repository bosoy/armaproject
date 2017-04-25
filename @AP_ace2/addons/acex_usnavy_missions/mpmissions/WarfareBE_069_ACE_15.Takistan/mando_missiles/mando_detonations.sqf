/*mando detonations
mando_detonations.sqf v1.0
April 2007 Mandoble

DO NOT EXECUTE THIS SCRIPT MANUALLY
*/

private["_pos", "_target", "_side", "_launcher", "_script", "_res"];
_pos = [0,0,0];
while {true} do
{
   waitUntil {mando_deton_req};
   _pos = [mando_deton_x, mando_deton_y, mando_deton_z];
   _script = mando_deton_script;
   _launcher = mando_deton_launcher;
   _target = mando_deton_target;
   _side = mando_deton_side;
//   hint format["T:%1, S:%2, L:%3",_target, _side, _launcher];
   _res = [_pos, _target, _side, _launcher]execVM _script;
   mando_deton_req = false;
};
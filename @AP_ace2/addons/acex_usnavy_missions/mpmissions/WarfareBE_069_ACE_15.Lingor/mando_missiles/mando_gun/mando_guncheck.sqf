/* 
 mando_guncheck.sqf v1.2
 August 2007 Mandoble 

 Run at least on every machine with a player in the init.sqs or init.sqf
*/

mando_gun = objNull;
mando_gun_sound = "";
while {true} do
{
   waitUntil {!isNull mando_gun};

   mando_gun say3D mando_gun_sound;
   mando_gun = objNull;
};
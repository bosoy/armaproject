/* 
 mando_guncheck_lite.sqf v1.0
 October 2008 Mandoble 

 Run at least on every machine with a player in the init.sqs or init.sqf
*/

mando_gun_lite = objNull;
mando_gun_lite_sound = "";
while {true} do
{
   waitUntil {!isNull mando_gun_lite};

   mando_gun_lite say mando_gun_lite_sound;
   mando_gun_lite = objNull;
};
/* 
 mando_guneffects.sqf v1.2
 August 2007 Mandoble 

 Run at least on every machine with a player in the init.sqs or init.sqf
*/

mando_gun_x = 0;
mando_gun_y = 0;
mando_gun_z = 0;
mando_gun_vx = 0;
mando_gun_vy = 0;
mando_gun_vz = 0;
mando_gun_shell = objNull;
_shell = objNull;
while {true} do
{
   waitUntil {!isNull mando_gun_shell};


   _vel = [mando_gun_vx, mando_gun_vy, mando_gun_vz];
   _vel1 = [-(_vel select 0)/100,-(_vel select 1)/100,-(_vel select 2)/100];
   _vel2 = [(_vel select 0)/2,(_vel select 1)/2,(_vel select 2)/2];
   _vel3 = [(_vel select 0)/40,(_vel select 1)/40,(_vel select 2)/40];
   drop["\Ca\Data\missileSmoke","","Billboard",100,5,[mando_gun_x,mando_gun_y,mando_gun_z],_vel1,1,1.24,1,0.15,[0.5,2,6],[[1,1,1,0.3]],[1,0],1,0.1,"","",""];

   drop["\ca\data\koulesvetlo","","Billboard",100,1,[mando_gun_x,mando_gun_y,mando_gun_z],_vel2,1,1.245,1,0,[0.3,0.05],[[1,0.5,0,1]],[1,0],0,0,"","",""];

   drop["\Ca\Data\missileSmoke","","Billboard",0.1,0.5,[mando_gun_x,mando_gun_y,mando_gun_z],_vel3,1,1.24,1,0.005,[0.3,0.05],[[1,1,1,0.2]],[1,0],0,0,"mando_missiles\mando_gun\tracer_smoke.sqs","",""];

   mando_gun_shell = objNull;
};
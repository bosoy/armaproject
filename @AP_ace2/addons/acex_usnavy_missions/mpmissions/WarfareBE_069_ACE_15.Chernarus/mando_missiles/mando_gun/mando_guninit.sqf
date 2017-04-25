if (isNil "mando_gun_init") then
{
   []execVM"mando_missiles\mando_gun\mando_guncheck.sqf";
   []execVM"mando_missiles\mando_gun\mando_guneffects.sqf";
   mando_gun_init = true;
};
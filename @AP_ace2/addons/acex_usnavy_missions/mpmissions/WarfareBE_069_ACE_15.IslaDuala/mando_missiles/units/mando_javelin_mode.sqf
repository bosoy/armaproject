/* mando_javelin_mode.sqf
By Mandoble July 2008
*/
(_this select 0) removeAction (_this select 2);
if ((_this select 3) == 0) then
{
   (_this select 0) setVariable ["mando_javelin_mode", 0];
   mando_javelin_ac = (_this select 0) addAction ["Javelin: Hi->Direct", mando_missile_path+"units\mando_javelin_mode.sqf", 1];
}
else
{
   (_this select 0) setVariable ["mando_javelin_mode", 1];
   mando_javelin_ac = (_this select 0) addAction ["Javelin: Direct->Hi", mando_missile_path+"units\mando_javelin_mode.sqf", 0];
};


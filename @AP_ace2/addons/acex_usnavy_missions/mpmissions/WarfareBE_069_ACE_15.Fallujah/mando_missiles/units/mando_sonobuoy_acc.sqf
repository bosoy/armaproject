/* mando_sonobuoy_acc.sqf
By Mandoble Feb 2008

Drops a sonobuoy which will provide remote surface and underwater targets 
Use it as action menu script
*/

private["_veh", "_buoy", "_trigger", "_side"];
_veh = _this select 0;
_side = side (_this select 1);
(_this select 0) removeAction (_this select 2);

[_veh, [0,0,-2]] execVM mando_missile_path+"units\mando_sonobuoy.sqf";

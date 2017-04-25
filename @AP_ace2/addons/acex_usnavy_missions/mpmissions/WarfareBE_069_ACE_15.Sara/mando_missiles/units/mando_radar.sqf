/* mando_radar.sqf
By Mandoble September 2008

Creates a radar to be used by mando_missileattacker.sqf
If you provide the created radar name to mando_missileattacker.sqf, its unit will use this radar instead of its own one.

Parameters:
   vehicle or object acting as radar
   radar name (it might be used as parameter for mando_missileattacker.sqf)
   radar range

   Example:
   [radar_tower1, "my_radar1", 6000]execVM"mando_missiles\units\mando_radar.sqf";
*/

private ["_veh", "_radar", "_range", "_trigger"];
_veh = _this select 0;
_radar = _this select 1;
_range = _this select 2;

if (!alive _veh) exitWith {};
if (isNil format["%1", (call compile _radar)]) then
{
   call compile format["%1 = createTrigger [""EmptyDetector"", getPos %2]", _radar, _veh];
};


_trigger = call compile _radar;

_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerArea [_range, _range, 0, false];
_trigger setTriggerType "NONE";
_trigger setTriggerStatements ["this", "", ""];
_trigger setTriggerTimeout [0, 0, 0, false ];

mando_radar_on = _veh;
publicVariable "mando_radar_on";


while {alive _veh} do
{
   _trigger setPos getPos _veh;
   Sleep 2;
};

_trigger setTriggerArea [1, 1, 0, false];
mando_radar_off = _veh;
publicVariable "mando_radar_off";

/* mando_onlymandoones.sqf
By Mandoble Oct 2008

Replaces ArmA stock missiles fired to this unit by mando missiles
This script must be executed in every machine, to ensure that execute it in the init field of the unit or, if the unit is being spawned by script, use SetVehicleInit and ProcessInitCommands to ensure it is executed everywhere, even in the case of JIP.

For example:
_spawnedplane SetVehicleInit "res = [This] execVM mando_missile_path+""units\mando_onlymandoones.sqf""";
 processInitCommands;
*/

_unit = _this select 0;
_eh = _unit addEventHandler ["IncomingMissile",{ _this spawn mando_missile_replaced }];

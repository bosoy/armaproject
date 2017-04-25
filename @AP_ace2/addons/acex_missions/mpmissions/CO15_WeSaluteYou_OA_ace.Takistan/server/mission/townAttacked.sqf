_grp = _this select 0;

_townDefense1 = creategroup EAST;
{[_x] joinSilent _townDefense1} foreach (units _grp);
_townDefense1 addWaypoint [getMarkerPos "town", 0];
[_townDefense1, 0] setWaypointType "GUARD";
[_townDefense1, 0] setWaypointCombatMode "NO CHANGE";
[_townDefense1, 0] setWaypointFormation "LINE";
[_townDefense1, 0] setWaypointSpeed "FULL";
[_townDefense1, 0] setWaypointBehaviour "COMBAT";
 
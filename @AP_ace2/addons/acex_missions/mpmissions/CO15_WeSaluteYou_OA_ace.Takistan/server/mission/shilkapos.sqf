_grp = _this select 0;

_townDefense2 = creategroup EAST;
{[_x] joinSilent _townDefense2} foreach (units _grp);
_townDefense2 addWaypoint [getMarkerPos "shilkapos_1", 0];
[_townDefense2, 0] setWaypointType "MOVE";
[_townDefense2, 0] setWaypointCombatMode "NO CHANGE";
[_townDefense2, 0] setWaypointFormation "LINE";
[_townDefense2, 0] setWaypointSpeed "FULL";
[_townDefense2, 0] setWaypointBehaviour "NO CHANGE";

 _townDefense2 addWaypoint [getMarkerPos "shilkapos_2", 1];
[_townDefense2, 1] setWaypointType "GUARD";
[_townDefense2, 1] setWaypointCombatMode "NO CHANGE";
[_townDefense2, 1] setWaypointFormation "LINE";
[_townDefense2, 1] setWaypointSpeed "FULL";
[_townDefense2, 1] setWaypointBehaviour "COMBAT";
_grp = _this select 0;

_siteDefense2 = creategroup EAST;
{[_x] joinSilent _siteDefense2} foreach (units _grp);
 _siteDefense2 addWaypoint [getMarkerPos "site", 0];
 [_siteDefense2, 0] setWaypointType "GUARD";
 [_siteDefense2, 0] setWaypointCombatMode "NO CHANGE";
 [_siteDefense2, 0] setWaypointFormation "LINE";
 [_siteDefense2, 0] setWaypointSpeed "FULL";
 [_siteDefense2, 0] setWaypointBehaviour "AWARE";
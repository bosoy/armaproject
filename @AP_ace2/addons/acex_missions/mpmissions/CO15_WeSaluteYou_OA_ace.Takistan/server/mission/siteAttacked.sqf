_grp = _this select 0;

_siteDefense1 = creategroup EAST;
{[_x] joinSilent _siteDefense1} foreach (units _grp);
 _siteDefense1 addWaypoint [getMarkerPos "site", 0];
 [_siteDefense1, 0] setWaypointType "GUARD";
 [_siteDefense1, 0] setWaypointCombatMode "NO CHANGE";
 [_siteDefense1, 0] setWaypointFormation "LINE";
 [_siteDefense1, 0] setWaypointSpeed "FULL";
 [_siteDefense1, 0] setWaypointBehaviour "COMBAT";
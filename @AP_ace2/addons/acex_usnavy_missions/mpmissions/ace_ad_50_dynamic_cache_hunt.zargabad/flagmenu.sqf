_obj = _this select 0;

for [{_d=500}, {_d<=4000}, {_d=_d+250}] do
{
	call compile format ["_obj addAction ['%1 view distance' ,'setviewdistance.sqf', [%1] ,1,false,true,'','true']", str _d];
};

waitUntil {!isNil "roundInProgress"};
_obj addAction ["Resume spectating", "spectate.sqf", [], 2, false, true, "", "roundInProgress"];
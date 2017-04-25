private ["_protectionTime"];

_protectionTime = _this select 1;

_varName = _this select 0;
waitUntil {!isNil _varName};

while {true} do {
	waitUntil {alive (missionNameSpace getVariable _varName)};
    
	(missionNameSpace getVariable _varName) allowDamage false;
	sleep _protectionTime;
	(missionNameSpace getVariable _varName) allowDamage true;

	waitUntil {!alive (missionNameSpace getVariable _varName)};
};
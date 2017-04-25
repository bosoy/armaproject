#include "script_component.hpp"

#define __latest_ace_keys 8
#define __latest_ace_clientside_config 14
#define __latest_ACE_serverconfig 2
#define __latest_ACE_Tracking 1.0

if (local player && {isNil "ACE_latestUCFG"}) then {
	sleep 20;
	waitUntil {alive player};
	sleep 3;
	_outdated = [];

	//ace_clientside_config
	_version = getNumber(configFile >> "CfgSettings" >> "ACE" >> "ACE_CLIENTSIDE_CONFIG_VER");
	_latest = __latest_ace_clientside_config;
	if (_latest > _version) then {PUSH(_outdated,"ace_clientside_config.hpp")};
	//ACE_serverconfig
	_version = getNumber(configFile >> "CfgSettings" >> "ACE" >> "ACE_SERVERCONFIG_VER");
	_latest = __latest_ACE_serverconfig;
	if (_latest > _version) then {PUSH(_outdated,"ACE_serverconfig.hpp")};
	//ACE_Tracking
	//_version = getNumber(configFile >> "CfgSettings" >> "ACE" >> "ACE_TRACKING_VER");
	//_latest = __latest_ACE_Tracking;
	//if (_latest > _version) then {PUSH(_outdated,"ACE_Tracking.hpp")};

	_count = count _outdated;
	if (_count > 0) then {
		_message = (localize "STR_UCFG_OUTDATED") + ": userconfig\ace\" + (_outdated select 0);
		for "_x" from 1 to _count - 1 do {
			_message = _message + ", " + (_outdated select _x);
		};
		_message = _message + localize "STR_UCFG_CLIPPI";
		ERROR(_message);
		player commandChat _message;
		ACE_latestUCFG = false;
	} else {
		ACE_latestUCFG = true;
	};
};

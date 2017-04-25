//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(unitinit);

if (isNil QGVAR(limitZoom)) then { GVAR(limitZoom) = false };
if (isNil QGVAR(auto_limit)) then { GVAR(auto_limit) = false };

// TODO: Perhaps change to return values instead of setting GVAR's directly
FUNC(determineZoom) = {
	private ["_grids", "_fourSize", "_sixSize", "_continue", "_size"];
	_grids = configFile >> "CfgWorlds" >> worldName >> "Grid";
	_fourSize = -1;
	_sixSize = -1;
	for "_i" from 1 to 10 do {
		_continue = false;
		if (isClass(_grids >> format["Zoom%1", _i])) then {
			_continue = true;
			_size = getText(_grids >> format["Zoom%1", _i] >> "formatX");
			if ((count toArray(_size)) == 2) then {
				_fourSize = getNumber(_grids >> format["Zoom%1", _i] >> "zoomMax");
			};
			if ((count toArray(_size)) == 3) then {
				_sixSize = getNumber(_grids >> format["Zoom%1", _i] >> "zoomMax");
			};
			if (_fourSize != -1 && {_sixSize != -1}) then {
				_continue = false;
			};
		};
		if (!_continue) exitWith {};
	};

	if(_fourSize != -1 && {_sixSize != -1}) then {
		if (isNil QGVAR(minMapSize) && {GVAR(limitZoom)}) then { GVAR(minMapSize) = _sixSize+0.01 } else { GVAR(minMapSize) = -1; };
	};
};
/*
FUNC(determineMapLight) = {
	//TODO: Fix NVG color
	private ["_darkMap","_lightColor","_lightFill","_createLight","_gunlight"];
	_gunlight = isArray(configFile>> "CfgWeapons" >> currentWeapon player >>"ace_gunlight_classes") || {"ACE_MugLite" in weapons player};
	// Default Values
	_alphaBase = if (round overcast > 0.5) then { 0.975 } else { 0.93 };
	_alpha = _alphaBase min abs(sunOrMoon - 1);
	_lightColor = [0,0,0,((_alpha*1.1) min 1)];
	_lightFill = format["#(rgb,1,1,1)color(0,0,0,%1)",_alpha];		
	_darkMap = true;
	_createLight = false;
	// Check if player is not in a vehicle
	if (vehicle player == player) then { // player is not in a vehicle
		TRACE_1("NOT in vehicle","");
		_lightColor = [0,0,0,(_alpha*1.1)];
		_lightFill = format["#(rgb,1,1,1)color(0,0,0,%1)",_alpha];
		// check if player has NVG enabled
		if (currentVisionMode player == 1) then {
			// stick to nvg color
			_alpha = 0.8;
			_lightColor = [0,0.96,0,_alpha];
			_lightFill = "#(rgb,1,1,1)color(0,0.96,0,0.8)";
			TRACE_1("nvg on - green tint","");
		} else {
			// darken map, unless following cases are fulfilled
			// Priorities: Weapons flashlight, lamppost, fire, chemlight, flares
			// Check if player is near a campfire - 4m
			if (count (getpos player nearObjects ["Land_Fire",4]) > 0) then {
				_fire = (getpos player nearObjects ["Land_Fire",4]) select 0;
				if (inflamed _fire) then {
					_alpha = (((player distance _fire) min 4)/4) min _alphaBase;
					_lightColor = [0,0,0,_alpha];
					_lightFill = format["#(rgb,1,1,1)color(0,0,0,%1)",_alpha];
					TRACE_1("player near campfire","");
				};
			};
			// Check if player is near a lamppost that is on - 15m
			if (count (getpos player nearObjects ["StreetLamp",15]) > 0) then {
				_lamp = (getpos player nearObjects ["StreetLamp",15]) select 0;
				if (lightIsOn _lamp in ["ON","AUTO"]) then {
					_alpha = (((player distance _lamp) min 15)/15) min _alphaBase;
					_lightColor = [0,0,0,_alpha];
					_lightFill = format["#(rgb,1,1,1)color(0,0,0,%1)",_alpha];					
					TRACE_1("player near lamppost","");
				};
			};
			// BIS: In front of a vehicle with headlights on? - OFC not possible in Arma...
			// TODO: Illumination flares (timed)
			// Using chemlights
			if (count (getpos player nearObjects ["ACE_Knicklicht_Object_Base",2]) > 0) then {
				_chem = (getpos player nearObjects ["ACE_Knicklicht_Object_Base",2]) select 0;
				if (alive _chem) then {
					_alpha = (((player distance _chem) min 2)/2) min 0.5;
					_lightColor = getArray(configFile >> "CfgVehicles" >> typeOf _chem >> "MarkerLights" >> "RedBlinking" >> "color");
					_lightColor set [3,_alpha];
					_lightFill = format["#(rgb,1,1,1)color(%1,%2,%3,%4)",(_lightColor select 0),(_lightColor select 1),(_lightColor select 2),(_lightColor select 3)];					
					TRACE_1("player near chemlight","");
				};
			};
			
			// Gun with light
			if (_gunlight) then {
				_darkMap = false;
				_createLight = true;
				TRACE_1("using gun light","");
			};
		};
	} else { // player is in a vehicle
		if (((vehicle player) getVariable ["ace_sys_tracking_device_active",false]) && {if ((vehicle player) isKindOf "Tank") then { player == (commander vehicle player) } else { player in [(commander vehicle player)] || {player in (assignedCargo vehicle player)} }}) then {
			_darkMap = false;
			_createLight = false;		
		} else {
			// check if vehicle is not of following type: parachute (TODO: Disable maplooking when parachuting or haloing)
			TRACE_1("in vehicle","");
			// check if player has NVG enabled
			if (currentVisionMode player == 1) then {
				// stick to nvg color
				_alpha = 0.8;
				_lightColor = [0,0.96,0,_alpha];
				_lightFill = "#(rgb,1,1,1)color(0,0.96,0,0.8)";
				TRACE_1("nvg on - green tint","");
			} else {
				// darken map if vehicle is kind of bicycle or motorbike or ATV or parachute or PBX boat
				if (vehicle player isKindOf "Bicycle" || {vehicle player isKindOf "Motorcycle"}) then {
					if (_gunlight) then {
						_darkMap = false;
						_createLight = true;
						TRACE_1("bright map - gun lights","");					
					} else {
						_lightColor = [0,0,0,(_alpha*1.1)];
						_lightFill = format["#(rgb,1,1,1)color(0,0,0,%1)",_alpha];				
						TRACE_1("darken map - no lights","");
					};
				} else {
					// do not darken map, but create a lightpoint at players eye pos to simulate dash light / flashlight usage to view map
					// do nothing if in a tank or apc
					_darkMap = false;
					_createLight = true;
					TRACE_1("using vehicle light","");
				};
			};	
		};
	};
	TRACE_4("",_darkMap,_lightColor,_lightFill,_createLight);
	[_darkMap,_lightColor,_lightFill,_createLight]
};
*/
ADDON = true;

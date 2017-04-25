#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

call FUNC(determineZoom);

0 spawn COMPILE_FILE(mapview);

/*
0 spawn {
	sleep 5;
	((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ["Draw", "
		if (player hasWeapon 'ACE_Map' || {player hasWeapon 'ItemMap'}) then {
			_data = call ace_sys_map_fnc_determineMapLight;
			_darkMap = _data select 0;
			_color = _data select 1;
			_fill = _data select 2;
			_externalLight = _data select 3;
			if (_darkMap) then {
				((findDisplay 12) displayCtrl 51) drawRectangle [(getArray(configFile >> 'CfgWorlds' >> worldName >> 'centerPosition')),80000,80000,0,_color,_fill]; 
			} else {
				if (_externalLight) then {
					[] spawn {
						_light = player getVariable ['ace_map_light',objNull];
						if (isNull _light) then {
							_type = if (player == vehicle player) then { 'ACE_Flashlight' } else { 'ACE_Dashlight' };
							_light = _type createVehicle (getPos player);
							_light attachTo [(vehicle player), if (_type == 'ACE_Flashlight') then { [0,0.4,1] } else { [0,0,-1]}];
							player setVariable ['ace_map_light',_light];
							waitUntil {sleep 0.1; !visibleMap; };
							deleteVehicle _light;
							player setVariable ['ace_map_light',objNull];
						};
					};
				};
			};
		} else {
			((findDisplay 12) displayCtrl 51) drawRectangle [(getArray(configFile >> 'CfgWorlds' >> worldName >> 'centerPosition')),80000,80000,0,[0,0,0,1],'#(rgb,1,1,1)color(0,0,0,1)'];
		};
	"];
};
*/

0 spawn {
	sleep 6;
	((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ["Draw", "
		_speed = if (vehicle player == player) then { (velocity player) distance [0,0,0] } else { 0 };
		_ctrl = ((findDisplay 12) displayCtrl 51);
		_scale = ctrlMapScale _ctrl;
		if (_speed > 0.1) then {
			_time = 0.5/_speed;
			_shakePos = if (random 100 > 50) then {
				[0.5 - ((random 0.1)*_time), 0.5 + (random 0.5)];
			} else {
				[0.5 + ((random 0.1)*_time), 0.5 - (random 0.5)];
			};
			_ctrl ctrlMapAnimAdd [_time, _scale, (_ctrl ctrlMapScreenToWorld _shakePos)];
			ctrlMapAnimCommit _ctrl;
			if (ctrlMapAnimDone _ctrl) then { ctrlMapAnimClear _ctrl; };
		} else {
			ctrlMapAnimClear _ctrl;
			if (!isNil 'ace_sys_map_limitZoom' && {ace_sys_map_limitZoom}) then {
				if (ace_sys_map_minMapSize > _scale) then {
					_ctrl ctrlMapAnimAdd [0, ace_sys_map_minMapSize+0.001, (_ctrl ctrlMapScreenToWorld [0.5, 0.5])];
					ctrlMapAnimCommit _ctrl;
				};
				if (ace_sys_map_minMapSize == _scale) then {
					_ctrl ctrlMapAnimAdd [0, ace_sys_map_minMapSize+0.001, (_ctrl ctrlMapScreenToWorld [0.5, 0.5])];
					ctrlMapAnimCommit _ctrl;
				};
			};
		};
	"];
};

["CAManBase", [ace_sys_interaction_key], -2, [QPATHTO_F(fnc_menuDef), "main"]] call CBA_ui_fnc_add;

ADDON = true;

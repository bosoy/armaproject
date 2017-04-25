// by Xeno
#define THIS_FILE "x_vec_hud.sqf"
#include "x_setup.sqf"
private ["_speed_str", "_fuel_str", "_dam_str", "_dir_str", "_gendirlist", "_welcome_message", "_vec", "_welcome_str", "_vec_msg1", "_struct_text", "_endtime", "_type_name", "_vec_string", "_vdir", "_gendir", "_dstr", "_count", "_control", "_type_weap", "_dirtmp"];
_speed_str = (localize "STR_DOM_MISSIONSTRING_611");
_fuel_str =  (localize "STR_DOM_MISSIONSTRING_612");
_dam_str =   (localize "STR_DOM_MISSIONSTRING_613");
_dir_str =   (localize "STR_DOM_MISSIONSTRING_614");
_gendirlist = ["N",(localize "STR_DOM_MISSIONSTRING_615"),(localize "STR_DOM_MISSIONSTRING_616"),(localize "STR_DOM_MISSIONSTRING_617"),"E",(localize "STR_DOM_MISSIONSTRING_618"),(localize "STR_DOM_MISSIONSTRING_619"),(localize "STR_DOM_MISSIONSTRING_620"),"S",(localize "STR_DOM_MISSIONSTRING_621"),(localize "STR_DOM_MISSIONSTRING_622"),(localize "STR_DOM_MISSIONSTRING_623"),"W",(localize "STR_DOM_MISSIONSTRING_624"),(localize "STR_DOM_MISSIONSTRING_625"),(localize "STR_DOM_MISSIONSTRING_626"),"N"];

disableSerialization;

#define __CTRL(A) (_disp displayCtrl A)

_welcome_message = {
	private ["_vec","_vtype"];
	PARAMS_2(_vec,_vtype);
	_welcome_str = format [(localize "STR_DOM_MISSIONSTRING_627"), GVAR(name_pl)];
	_vec_msg1 = switch (true) do {
		case (_vtype == "MHQ"): {
			(localize "STR_DOM_MISSIONSTRING_628")
		};
		case (_vtype == "Engineer"): {
			(localize "STR_DOM_MISSIONSTRING_629")
		};
		default {""};
	};
	_struct_text = composeText[parseText("<t color='#f0a7ff31' size='1'>" + _welcome_str + "</t>"), lineBreak,lineBreak,_vec_msg1];
	_endtime = time + 8;
	hintSilent _struct_text;
	while {vehicle player != player && alive player && time < _endtime} do {
		sleep 1;
		hintSilent _struct_text;
	};
	hintSilent "";
};

while {true} do {
	waitUntil {sleep (0.2 + random 0.2);vehicle player != player};
	_vec = vehicle player;
	if (_vec isKindOf "LandVehicle" && !(_vec isKindOf "StaticWeapon")) then {
		if (GVAR(show_vehicle_welcome) == 0) then {
			_vtype = GV(_vec,GVAR(vec_type));
			if (!isNil "_vtype") then {
				if (_vtype == "MHQ" || _vtype == "Engineer") then {
					[_vec, _vtype] spawn _welcome_message;
				};
			};
		};
		while {vehicle player != player} do {
			if (player == driver _vec || player == gunner _vec || player == commander _vec) then {
				_type_name = [typeOf _vec,0] call FUNC(GetDisplayName);
				_vec_string = format [(localize "STR_DOM_MISSIONSTRING_630"), _type_name];
				67327 cutRsc ["xvehicle_hud", "PLAIN"];
				_disp = __uiGetVar(DVEC_HUD);
				_ison = true;
				while {vehicle player != player && alive player && player == driver _vec} do {
					_crewctrl = __uiGetVar(GVAR(rscCrewText)) displayCtrl 9999;
					_cctrlshown = if (isNil "_crewctrl") then {false} else {ctrlShown _crewctrl};
					if (!visibleMap && !_cctrlshown) then {
						if (!_ison) then {
							67327 cutRsc ["xvehicle_hud", "PLAIN"];
							_disp = __uiGetVar(DVEC_HUD);
							_ison = true;
						};
						__CTRL(64432) ctrlSetText _vec_string;
						__CTRL(64433) ctrlSetText format [_speed_str, round (speed _vec)];
						__CTRL(64434) ctrlSetText format [_fuel_str, round (fuel _vec * 100)];
						__CTRL(64435) ctrlSetText format [_dam_str, round (damage _vec * 100)];
						_vdir = round (direction _vec);
						_gendir = _gendirlist select (round (_vdir/22.5));
						__CTRL(64436) ctrlSetText format [_dir_str, _vdir, _gendir];
					} else {
						if (_ison) then {
							67327 cutRsc ["DEFAULT", "PLAIN"];
							_ison = false;
						};
					};
					sleep 0.331;
				};
				67327 cutRsc["DEFAULT", "PLAIN",1];
			};
			sleep 0.532;
		};
	} else {
		if (_vec isKindOf "StaticWeapon" && !(_vec isKindOf "ACE_SpottingScope") && !(_vec isKindOf "StaticATWeapon")) then {
			while {vehicle player != player} do {
				if (player == gunner _vec) then {
					_type_name = [typeOf _vec,0] call FUNC(GetDisplayName);
					_vec_string = (localize "STR_DOM_MISSIONSTRING_631") + _type_name;
					_type_weap = (getArray(configFile >> "CfgVehicles" >> (typeOf _vec) >> "Turrets" >> "MainTurret" >> "weapons")) select 0;
					67327 cutRsc ["xvehicle_hud", "PLAIN"];
					_disp = __uiGetVar(DVEC_HUD);
					_ison = true;
					while {vehicle player != player && alive player && player == gunner _vec} do {
						_crewctrl = __uiGetVar(GVAR(rscCrewText)) displayCtrl 9999;
						_cctrlshown = if (isNil "_crewctrl") then {false} else {ctrlShown _crewctrl};
						if (!visibleMap && !_cctrlshown) then {
							if (!_ison) then {
								67327 cutRsc ["xvehicle_hud", "PLAIN"];
								_disp = __uiGetVar(DVEC_HUD);
								_ison = true;
							};
							__CTRL(64432) ctrlSetText _vec_string;
							__CTRL(64433) ctrlSetText format [_dam_str, round (damage _vec * 100)];
							_vecwdir = _vec weaponDirection _type_weap;
							_dirtmp = round((_vecwdir select 0) atan2 (_vecwdir select 1));
							if (_dirtmp < 0) then {_dirtmp = _dirtmp + 360};
							_gendir = _gendirlist select (round (_dirtmp/22.5));
							__CTRL(64434) ctrlSetText format [_dir_str, _dirtmp, _gendir];
							__CTRL(64435) ctrlSetText "";
							__CTRL(64436) ctrlSetText "";
						} else {
							if (_ison) then {
								67327 cutRsc ["DEFAULT", "PLAIN"];
								_ison = false;
							};
						};
						sleep 0.331;
					};
					67327 cutRsc["DEFAULT", "PLAIN",1];
				};
				sleep 0.532;
			};
		};
	};
	waitUntil {sleep (0.2 + random 0.2);vehicle player == player};	
};

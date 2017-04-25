/* Customized MMA HUD Radar */

private ["_veh", "_list", "_max_w", "_max_h", "_max_y", "_orgx_s", "_orgy_s", "_hud_on", "_i", "_list", "_pos", "_poss", "_dist", "_angh", "_log", "_scale", "_old_scale", "_contact", "_time_to_deact", "_dir", "_target", "_soffset_x", "_soffset_y", "_fixed"];

DisableSerialization;

_veh = Vehicle player;
_max_w = ((_this select 2) * 3 / 4) / 2;
_orgx_s = (_this select 0) + _max_w;
_max_h = (_this select 2);
_orgy_s = (_this select 1) + _max_h;
_log = "logic" CreateVehicleLocal [0, 0, 0];
_fixed = _this select 3;
_full_x = _orgx_s - (_max_w * 1.4545);
_full_y = _orgy_s - (_max_h * 1.2273);
_full_w = _max_w * 2.9091;
_full_h = _max_h * 1.4545;
_hud_on = false;
_old_scale = 1;
_time_to_deact = 0;
_soffset_x = 0;
_soffset_y = 0;

while {!mando_exit_hud} do {
	if (IsNull (UINameSpace GetVariable "mandotarget_disp")) then {
		_hud_on = false;
	} else {
		if (_hud_on) then {
			if (!_fixed) then {
				if (Abs(mando_hud_sccenter select 0) > 0.015) then {
					_soffset_x = mando_hud_sccenter select 0;
				} else {
					_soffset_x = 0;
				};
				if (Abs(mando_hud_sccenter select 1) > 0.015) then {
					_soffset_y = mando_hud_sccenter select 1;
				} else {
					_soffset_y = 0;
				};
			} else {
				_soffset_x = 0;
				_soffset_y = 0;
			};
			_list = +mando_hud_targets;
			if ((count _list > 1) && ("A" in _list) && (Abs _soffset_x < 0.15) && (Abs _soffset_y < 0.15)) then {
				_time_to_deact = (DayTime * 3600) + 3;
				_max_y = 0;
				{
					if (TypeName _x == "Object") then {
						_dist = _veh Distance _x;
						if (_dist > _max_y) then {
							_max_y = _dist;
						};
					};
				} foreach _list;
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetPosition [_full_x + _soffset_x, _full_y + _soffset_y];
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlCommit 0;
				_max_y = Floor((_max_y + 3000) / 3000);
				_scale = (_max_y Min 4);
				if (_scale != _old_scale) then {
					// Change Background paa (_scale goes from 1 to 4, being 1 3Km and 4 12Km)
					switch (_scale) do {
					case 1: { 
						((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText "mando_missiles\huds\custom\images\radar\radar3km.paa";
					};
					case 2: { 
						((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText "mando_missiles\huds\custom\images\radar\radar6km.paa";
					};
					case 3: { 
						((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText "mando_missiles\huds\custom\images\radar\radar9km.paa";
					};
					case 4: { 
						((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText "mando_missiles\huds\custom\images\radar\radar12km.paa";
					};};
					_old_scale = _scale;
				};
				_max_y = _max_y * 3000;
				_posu = GetPos _veh;
				_log SetPos _posu;
				switch (_veh GetVariable "mando_weapon_name") do {
				case "": {                 
					_log SetDir GetDir _veh;
				};
				case "sight": {
					_pos = PositionCameraToWorld [0,0,100];
					_dir = ((_pos select 0) - (_posu select 0)) atan2 ((_pos select 1) - (_posu select 1));
					_log SetDir _dir;
				};
				default {
					_dir = ((_unit WeaponDirection (_veh GetVariable "mando_weapon_name")) select 0) atan2 ((_unit weaponDirection (_veh getVariable "mando_weapon_name")) select 1);
					_log SetDir GetDir _veh;
				};};
				_target = (_veh GetVariable "mando_current_target");
				if (IsNull _target) then {
					((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 75) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
				};
				for [{_i = 0}, {_i < 6}, {_i = _i + 1}] do { 
					if (_i < ((count _list) - 1)) then {
						_contact = (_list select _i);
						if (!IsNull _contact) then {
							if (TypeName _contact != "LOCATION") then {
								_pos = _log WorldToModel GetPos _contact;
								_dist = (_veh Distance _contact) * _max_h / _max_y;
							} else {
								_pos = _log WorldToModel LocationPosition _contact;
								_dist = (_veh Distance (LocationPosition _contact)) * _max_h / _max_y;
							};
							_dist = _dist Min _max_h;
							_angh = (_pos select 0) atan2 (_pos select 1);
							if (Abs _angh < 60) then {
								_poss = [_soffset_x + _orgx_s + sin(_angh) * _dist * 3 / 4, _soffset_y + _orgy_s - cos(_angh) * _dist];
								((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlSetTextColor [0.0, 0.625, 0.0, 1.0];
								((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlSetPosition _poss;
								((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlCommit 0;
								if (!IsNull _target) then {
									if (TypeName _contact != "LOCATION") then {
										if (_target == _contact) then {
											_dir = (GetDir _contact) - (GetDir _veh);
											((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 75) CtrlSetPosition [(_poss select 0) + 0.005 * 3 / 4, (_poss select 1) + 0.005, sin(_dir) * 0.02 * 3 / 4, -cos(_dir) * 0.02];
											((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 75) CtrlCommit 0;
											((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 75) CtrlSetTextColor [0.2, 0.8, 0.2, 1.0];
											((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlSetTextColor [0.2, 0.8, 0.2, 1.0];
										};
									};
								};
							} else {
								((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
							};
						} else {
							((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
						};
					} else {
						((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _i)) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
					};
				};
			} else {
				{
					((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _x)) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
				} foreach [0, 1, 2, 3, 4, 5, 6];
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 75) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
				if ((count _list > 1) && ("A" in _list)) then {
					_time_to_deact = (DayTime * 3600) + 4;
				};
				if ((Abs _soffset_x < 0.15) && (Abs _soffset_y < 0.15) && ((DayTime * 3600) < _time_to_deact)) then {
					((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetPosition [_full_x + _soffset_x, _full_y + _soffset_y];
					((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlCommit 0;
				} else {
					((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetPosition [-2, -2];
					((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlCommit 0;
				};
			};
		} else {
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetText "mando_missiles\huds\custom\images\radar\radar3km.paa";
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetPosition [-2, -2, _full_w, _full_h];
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlCommit 0;
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 59) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
			{
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _x)) CtrlSetText "mando_missiles\huds\custom\images\radar\track.paa";
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _x)) CtrlSetPosition [-2, -2, 0.01 * 3 / 4, 0.01];
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _x)) CtrlCommit 0; 
				((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl (60 + _x)) CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
			} foreach [0, 1, 2, 3, 4, 5, 6];
			_hud_on = true;
		};
	};
	Sleep 0.01;
};

DeleteVehicle _log;

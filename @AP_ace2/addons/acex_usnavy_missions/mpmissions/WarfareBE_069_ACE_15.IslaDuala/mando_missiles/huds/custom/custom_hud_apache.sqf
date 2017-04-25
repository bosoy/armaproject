/* MMA HUD customisation for Apache AH-64 IHADSS by deFUNKt & Mandoble - January 2010 */

private ["_hidden", "_optics", "_vehicle", "_display", "_rotate", "_help", "_imgpath", "_coords", "_hud_show", "_hud_hide", "_hud_mono"];

DisableSerialization;

_hidden = false;
_optics = false;
_vehicle = Vehicle player;
_display = (UINameSpace GetVariable "mandotarget_disp");
_rotate = 0;
_help = "";

if (GetNumber (ConfigFile >> "CfgPatches" >> "mando_apache" >> "RequiredVersion") > 0) then {
	_imgpath = "\mando\apache\";
} else {
	_imgpath = "mando_missiles\huds\custom\images\helmet\";
};

_coords = [] + mando_hud_coords;
_coords set [1, [-2.0, -2.0]]; // IDC 103 Target
_coords set [2, [0.20, 0.28-0.05]]; // IDC 108 Weapon
_coords set [3, [-2.0, -2.0]]; // IDC 109 Ammo
_coords set [4, [-2.0, -2.0]]; // IDC 111 Flares
_coords set [5, [0.20, 0.64 + 0.03]]; // IDC 113 Range

mando_hud_max_alpha = 0.00;
mando_hud_coords = [[-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2]];
mando_show_hint = false;

_hud_show = {
	mando_hud_max_alpha = 0.57; 
	mando_hud_coords = [] + _coords;
	(_display DisplayCtrl 50) CtrlSetPosition [0.50 - (SafeZoneH * 0.5625), 0.50 - (SafeZoneH * 0.6250), SafeZoneH * 1.1250, SafeZoneH * 1.1250];
	(_display DisplayCtrl 50) CtrlCommit 0.00;
	(_display DisplayCtrl 50) CtrlSetText _imgpath + "monocle_ghost.paa";
	(_display DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
	(_display DisplayCtrl 51) CtrlSetText "mando_missiles\huds\custom\images\helmet\track.paa";
	(_display DisplayCtrl 51) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
	(_display DisplayCtrl 51) CtrlSetPosition [0.500 - 0.175, 0.770 - 0.028, 0.350, 0.056];
	(_display DisplayCtrl 51) CtrlCommit 0;
	if (_this) then {
		(_display DisplayCtrl 67) CtrlSetPosition [0.85 - (SafeZoneH / 2), 0.60 - (SafeZoneH / 2), SafeZoneH * 0.75, SafeZoneH * 1.1250];
		(_display DisplayCtrl 67) CtrlCommit 0.00;
	};
	(_display DisplayCtrl 52) CtrlSetText "mando_missiles\huds\custom\images\helmet\ball.paa";
	(_display DisplayCtrl 52) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
	(_display DisplayCtrl 67) CtrlSetText _imgpath + "monocle_solid.paa";
	(_display DisplayCtrl 67) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
	(_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format [""];
	(_display DisplayCtrl 76) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha * 0.8];
	(_display DisplayCtrl 77) CtrlSetStructuredText ParseText Format [""];
	(_display DisplayCtrl 77) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
	(_display DisplayCtrl 76) CtrlSetPosition [0.00, 0.38, 0.20, 0.40];
	(_display DisplayCtrl 77) CtrlSetPosition [0.80, 0.38, 0.20, 0.40];
	(_display DisplayCtrl 76) CtrlCommit 0.00;
	(_display DisplayCtrl 77) CtrlCommit 0.00;
	(_display DisplayCtrl 107) CtrlSetText "mando_missiles\huds\custom\images\helmet\center.paa";
	(_display DisplayCtrl 107) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
	(_display DisplayCtrl 108) CtrlSetFontHeight 0.04;
	(_display DisplayCtrl 108) CtrlSetPosition [0.20, 0.16, 0.60, 0.10];
	(_display DisplayCtrl 108) CtrlCommit 0.00;
	(_display DisplayCtrl 113) CtrlSetFontHeight 0.03;
	(_display DisplayCtrl 113) CtrlSetPosition [0.20, 0.22, 0.60, 0.10];
	(_display DisplayCtrl 113) CtrlCommit 0.00;
};

_hud_hide = {

	mando_hud_max_alpha = 0.3;
	(_display DisplayCtrl 50)  CtrlSetTextColor [0.2, 1.0, 0.2, 0.0];
//	(_display DisplayCtrl 51)  CtrlSetTextColor [0.2, 1.0, 0.2, 0.0];
	(_display DisplayCtrl 67)  CtrlSetTextColor [0.2, 1.0, 0.2, 0.0];
//	(_display DisplayCtrl 76)  CtrlSetTextColor [0.2, 1.0, 0.2, 0.0];
//	(_display DisplayCtrl 77)  CtrlSetTextColor [0.2, 1.0, 0.2, 0.0];
//	(_display DisplayCtrl 107) CtrlSetTextColor [0.2, 1.0, 0.2, 0.0];
};

_hud_mono = {
	for [{_i = 0}, {_i < count mando_hud_colors}, {_i = _i + 1}] do {
		mando_hud_colors set [_i, [0.2, 1.0, 0.2]];
	};
};

Call _hud_mono;

if (mando_ihavemissiles) then {
	_help = _help + Format ["Lock Target: %1<br />Fire Missile: %2<br />Cycle Modes: %3", mando_keylockname, mando_keyfirename, mando_keymodename];
};
if (mando_ihaveflares) then {
	_help = _help + Format ["<br />Dispense Flares: %1", mando_keyflarename];
};
if ((_unit GetVariable "mando_ecm_time") > 0) then {
	_help = _help + Format ["<br />ECM On: %1", mando_keyecmname];
};
_help = _help + Format ["<br />Xmit Target to Crew: %1", mando_keyspecialname];

(_display DisplayCtrl 107) CtrlSetText "mando_missiles\huds\custom\images\helmet\empty.paa";

PlaySound "mando_visor";

(_display DisplayCtrl 50) CtrlSetText _imgpath + "monocle_ghost.paa";
(_display DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
(_display DisplayCtrl 50) CtrlSetPosition [1.50, 3.00, SafeZoneH * 1.1250, SafeZoneH * 1.1250];
(_display DisplayCtrl 50) CtrlCommit 0.00;
(_display DisplayCtrl 50) CtrlSetPosition [0.50 - (SafeZoneH * 0.5625), 0.50 - (SafeZoneH * 0.6250)];
(_display DisplayCtrl 50) CtrlCommit 0.65;
(_display DisplayCtrl 67) CtrlSetText _imgpath + "monocle_solid.paa";
(_display DisplayCtrl 67) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
(_display DisplayCtrl 67) CtrlSetPosition [1.00, 2.00, SafeZoneH * 0.75, SafeZoneH * 1.1250];
(_display DisplayCtrl 67) CtrlCommit 0.00;
(_display DisplayCtrl 67) CtrlSetPosition [0.85 - (SafeZoneH / 2), 0.60 - (SafeZoneH / 2)];
(_display DisplayCtrl 67) CtrlCommit 0.65;

Sleep 1.0;

[_vehicle] Spawn {
	private["_vehicle", "_to_sleep", "_d_x", "_d_y", "_was", "_dif", "_display", "_had_null_display", "_angroll", "_angpitch", "_vspeed", "_poss", "_posc", "_possa", "_anga","_is_apache", "_i"];
	DisableSerialization;
	_vehicle = _this select 0;
	_d_x = 0.0;
	_d_y = 0.0;
	_was = PositionCameraToWorld [0, 0, 100];
	_is_apache = false;
    if (TypeOf _vehicle in mando_ah64s) then {
		_is_apache = true;
	};
	while {!mando_exit_hud} do {
		_display = (UINameSpace GetVariable "mandotarget_disp");
		if (IsNull _display) then {
			_had_null_display = true;
			Sleep 0.225;
		} else {
			if (_had_null_display) then {
				_had_null_display = false;
				(_display DisplayCtrl 67) CtrlSetPosition [0.85 - (SafeZoneH / 2), 0.6 - (SafeZoneH / 2), SafeZoneH * 0.75, SafeZoneH * 1.125];
				(_display DisplayCtrl 67) CtrlCommit 0.0;
				Sleep 0.225;
			};
			if (CameraView == "GUNNER") then {
				Sleep 0.225;
			} else {
				if (count _was > 0) then {
					_dif = WorldToScreen _was;
					if (count _dif > 0) then {
						_d_x = (_d_x + (0.5 - (_dif select 0))) / 1.5;
						_d_y = (_d_y + (0.5 - (_dif select 1))) / 1.5;
					};
				};
				(_display DisplayCtrl 67) CtrlSetPosition [0.85 - (SafeZoneH / 2) - _d_x, 0.6 - (SafeZoneH / 2) - _d_y];
				(_display DisplayCtrl 67) CtrlCommit 0.0;
			};
			if (_is_apache) then {
				_angroll = Deg(_vehicle AnimationPhase "dg_bank");
				_angpitch = Deg(_vehicle AnimationPhase "dg_pitch");
			} else {
				_angroll = Deg(_vehicle AnimationPhase "horizonBank");
				_angpitch = Deg(_vehicle AnimationPhase "horizonDive");
			};
			_vspeed = Velocity _vehicle select 2;
			_poss = [0.5 + Cos(_angroll) * 0.18 * 3 / 4, (0.5 + Sin(_angroll) * 0.18), 0.5 + Cos(_angroll + 180) * 0.18 * 3 / 4, 0.5 + Sin(_angroll + 180) * 0.18];
			_poss set [1, (_poss select 1) + (_angpitch / 90) * 0.15];
			_poss set [3, (_poss select 3) + (_angpitch / 90) * 0.15];
			(_display DisplayCtrl 68) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
			(_display DisplayCtrl 68) CtrlSetPosition [_poss select 0, _poss select 1, (_poss select 2) - (_poss select 0), (_poss select 3) - (_poss select 1)];
			(_display DisplayCtrl 68) CtrlCommit 0;
			_posc = [0.5 + Cos(_angroll + 90) * 0.05 * 3 / 4, 0.5 + Sin(_angroll + 90) * 0.05];
			_poss = [(_posc select 0) + Cos(_angroll) * 0.14 * 3 / 4, ((_posc select 1) + Sin(_angroll) * 0.14), (_posc select 0) + Cos(_angroll + 180) * 0.14 * 3 / 4, (_posc select 1) + Sin(_angroll + 180) * 0.14];
			_poss set [1,(_poss select 1) + (_angpitch / 90) * 0.15];
			_poss set [3,(_poss select 3) + (_angpitch / 90) * 0.15];
			(_display DisplayCtrl 69) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha / 2];
			(_display DisplayCtrl 69) CtrlSetPosition [_poss select 0, _poss select 1, (_poss select 2) - (_poss select 0), (_poss select 3) - (_poss select 1)];
			(_display DisplayCtrl 69) CtrlCommit 0;
			_posc = [0.5 + Cos(_angroll - 90) * 0.05 * 3 / 4, 0.5+ Sin(_angroll - 90) * 0.05];
			_poss = [(_posc select 0) + Cos(_angroll) * 0.14 * 3 / 4, ((_posc select 1) + Sin(_angroll) * 0.14), (_posc select 0) + Cos(_angroll + 180) * 0.14 * 3 / 4, (_posc select 1) + Sin(_angroll + 180) * 0.14];
			_poss set [1, (_poss select 1) + (_angpitch / 90) * 0.15];
			_poss set [3, (_poss select 3) + (_angpitch / 90) * 0.15];
			(_display DisplayCtrl 70) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha / 2];
			(_display DisplayCtrl 70) CtrlSetPosition [_poss select 0, _poss select 1, (_poss select 2) - (_poss select 0), (_poss select 3) - (_poss select 1)];
			(_display DisplayCtrl 70) CtrlCommit 0;
			// 20 m/s -> 0.3 screen length...
			if (_vspeed >= 0) then {
				_poss = [0.72, 0.5, 0.72, 0.5 - ((_vspeed * 0.3 / 20) Min 0.21)];
				_anga = 25;
			} else {
				_poss = [0.72, 0.5, 0.72, 0.5 - ((_vspeed * 0.3 / 20) Max -0.21)];
				_anga = 155;
			};
			if ((Round _vspeed) == 0) then {
				(_display DisplayCtrl 71) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
				(_display DisplayCtrl 72) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
				(_display DisplayCtrl 73) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
			} else {
				(_display DisplayCtrl 71) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
				(_display DisplayCtrl 71) CtrlSetPosition [_poss select 0, _poss select 1, (_poss select 2) - (_poss select 0), (_poss select 3) - (_poss select 1)];
				(_display DisplayCtrl 71) CtrlCommit 0;
				_posa = [_poss select 2, _poss select 3, (_poss select 2) + Sin(_anga) * 0.01, (_poss select 3) + Cos(_anga) * 0.01];
				(_display DisplayCtrl 72) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
				(_display DisplayCtrl 72) CtrlSetPosition [_posa select 0, _posa select 1, (_posa select 2) - (_posa select 0), (_posa select 3) - (_posa select 1)];
				(_display DisplayCtrl 72) CtrlCommit 0;
				_posa = [_poss select 2, _poss select 3, (_poss select 2) + Sin(-_anga) * 0.01, (_poss select 3) + Cos(-_anga) * 0.01];
				(_display DisplayCtrl 73) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
				(_display DisplayCtrl 73) CtrlSetPosition [_posa select 0, _posa select 1, (_posa select 2) - (_posa select 0), (_posa select 3) - (_posa select 1)];
				(_display DisplayCtrl 73) CtrlCommit 0;
			};
			_poss = [0.72 - 0.01, 0.5, 0.72 + 0.01, 0.5];
			(_display DisplayCtrl 74) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
			(_display DisplayCtrl 74) CtrlSetPosition [_poss select 0, _poss select 1, (_poss select 2) - (_poss select 0), (_poss select 3) - (_poss select 1)];
			(_display DisplayCtrl 74) CtrlCommit 0;

			_center = screenToWorld [0.5,0.5];
			_pos = getPos _vehicle;
			_ang = ((_center select 0)-(_pos select 0)) atan2 ((_center select 1)-(_pos select 1));
			_ang = _ang - 25;
			_posh = [];

			for [{_i=0},{_i<6},{_i=_i+1}] do
			{
				_posh = _posh + [worldToScreen [(_pos select 0)+sin(_ang)*500,(_pos select 1)+cos(_ang)*500, 0]];
				_ang = _ang + 50/5;
			};

			_colors = [0, 1, 0];

			for [{_i=0},{_i<5},{_i=_i+1}] do
			{
				(_display DisplayCtrl (30+_i)) CtrlSetPosition [(_posh select _i) select 0,(_posh select _i) select 1,((_posh select _i+1) select 0)-((_posh select _i) select 0),((_posh select _i+1) select 1)-((_posh select _i) select 1)];
				(_display DisplayCtrl (30+_i)) CtrlCommit 0;
				(_display DisplayCtrl (30+_i)) CtrlSetTextColor _colors + [mando_hud_max_alpha];
			};

			_posh = [];
			_ang = ((_center select 0)-(_pos select 0)) atan2 ((_center select 1)-(_pos select 1));
			_ang = _ang - 25;

			for [{_i=0},{_i<6},{_i=_i+1}] do
			{
				_posh = _posh + [worldToScreen [(_pos select 0)+sin(_ang)*1000,(_pos select 1)+cos(_ang)*1000, 0]];
				_ang = _ang + 50/5;
			};

			_colors = [0, 0.75, 0];

			for [{_i=0},{_i<5},{_i=_i+1}] do
			{
				(_display DisplayCtrl (35+_i)) CtrlSetPosition [(_posh select _i) select 0,(_posh select _i) select 1,((_posh select _i+1) select 0)-((_posh select _i) select 0),((_posh select _i+1) select 1)-((_posh select _i) select 1)];
				(_display DisplayCtrl (35+_i)) CtrlCommit 0;
				(_display DisplayCtrl (35+_i)) CtrlSetTextColor _colors + [mando_hud_max_alpha];
			};

			_posh = [];
			_ang = ((_center select 0)-(_pos select 0)) atan2 ((_center select 1)-(_pos select 1));
			_ang = _ang - 25;

			for [{_i=0},{_i<6},{_i=_i+1}] do
			{
				_posh = _posh + [worldToScreen [(_pos select 0)+sin(_ang)*1500,(_pos select 1)+cos(_ang)*1500, 0]];
				_ang = _ang + 50/5;
			};

			_colors = [0, 0.5, 0];

			for [{_i=0},{_i<5},{_i=_i+1}] do
			{
				(_display DisplayCtrl (40+_i)) CtrlSetPosition [(_posh select _i) select 0,(_posh select _i) select 1,((_posh select _i+1) select 0)-((_posh select _i) select 0),((_posh select _i+1) select 1)-((_posh select _i) select 1)];
				(_display DisplayCtrl (40+_i)) CtrlCommit 0;
				(_display DisplayCtrl (40+_i)) CtrlSetTextColor _colors + [mando_hud_max_alpha];
			};


		};
		_was = PositionCameraToWorld [0, 0, 100];
		Sleep 0.025;
	};
};

(_display DisplayCtrl 76) CtrlSetTextColor (mando_hud_colors select 0) + [0.57 * 0.8];
(_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>Please wait...</t>"];
(_display DisplayCtrl 76) CtrlSetPosition [0.10, 0.38, 0.35, 0.40];
(_display DisplayCtrl 76) CtrlCommit 0.00;
(_display DisplayCtrl 77) CtrlSetTextColor (mando_hud_colors select 0) + [0.57];
(_display DisplayCtrl 77) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75' align='right'>" + _help + "</t><br /><br /><t font='Bitstream' size='1.50' align='right'>Use the action menu to map keys or toggle the HUD.</t>"];
(_display DisplayCtrl 77) CtrlSetPosition [0.55, 0.38, 0.35, 0.40];
(_display DisplayCtrl 77) CtrlCommit 0.00;

Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...</t>", mando_missile_version];
Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...</t>", mando_missile_version];
Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...</t>", mando_missile_version];
Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Stores...</t>", mando_missile_version];
Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Stores...OK<br />Loading.</t>", mando_missile_version];
Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Stores...OK<br />Loading..</t>", mando_missile_version];
Sleep 0.5; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Stores...OK<br />Loading...</t>", mando_missile_version];

Sleep 1.0;

false Call _hud_show;

[_vehicle] Spawn {
	private["_vehicle", "_log_eye", "_log_loc", "_pos_eye1", "_pos_eye2", "_var", "_dir_loc", "_dir_rem", "_had_null_display", "_display"];
	DisableSerialization;
	_vehicle = _this select 0;
	_log_eye = "logic" CreateVehicleLocal [0, 0, 0];
	_log_loc = "logic" CreateVehicleLocal [0, 0, 0];
	if (player == gunner _vehicle) then {
		_vehicle SetVariable ["mando_ah64_gunner_eye", 45 + GetDir _vehicle, true];
		_vehicle SetVariable ["mando_ah64_pilot_eye",  45 + GetDir _vehicle, true];
	} else {
		_vehicle SetVariable ["mando_ah64_pilot_eye", -90 + GetDir _vehicle, true];
		_vehicle SetVariable ["mando_ah64_gunner_eye", -90 + GetDir _vehicle, true];
	};
	_had_null_display = true;
	while {!mando_exit_hud} do {
		_pos_eye1 = PositionCameraToWorld [0, 0, 0];
		_pos_eye2 = PositionCameraToWorld [0, 0, 100];
		if ((count _pos_eye1 == 3) && (count _pos_eye2 == 3)) then {
			_dir_loc = (((_pos_eye2 select 0) - (_pos_eye1 select 0)) Atan2 ((_pos_eye2 select 1) - (_pos_eye1 select 1)));
			_log_eye SetDir _dir_loc;
			if (player == Gunner _vehicle) then {
				if (IsPlayer (driver _vehicle)) then { 
					_vehicle SetVariable ["mando_ah64_gunner_eye", GetDir _log_eye, true];
					_dir_rem = _vehicle GetVariable "mando_ah64_pilot_eye"; 
				} else {
					_dir_rem = GetDir _vehicle;
				};
			} else {
				if (IsPlayer (Gunner _vehicle)) then { 
					_vehicle SetVariable ["mando_ah64_pilot_eye", GetDir _log_eye, true];
					_dir_rem = _vehicle GetVariable "mando_ah64_gunner_eye";
				} else {
					_dir_rem = GetDir _vehicle;
				};
			};
			_display = UINameSpace GetVariable "mandotarget_disp";
			if (!IsNull _display) then {
				_log_loc SetDir (_dir_rem - _dir_loc);
				_dir_loc = GetDir _log_loc;
				_delta = Sin (_dir_loc) Atan2 Cos (_dir_loc);
				if (_had_null_display) then {
					_had_null_display = false;
					(_display DisplayCtrl 52) CtrlSetPosition [0.500 - (0.025 * 3 / 4) + _delta * 0.150 / 180, 0.770 - 0.025, 0.050 * 3 / 4, 0.050];
					(_display DisplayCtrl 52) CtrlCommit 0;
				};
				(_display DisplayCtrl 52) CtrlSetPosition [0.500 - (0.025 * 3 / 4) + _delta * 0.150 / 180, 0.770 - 0.025, 0.050 * 3 / 4, 0.050];
				(_display DisplayCtrl 52) CtrlCommit 0.5;
			} else {
				_had_null_display = true;
			};
		};		Sleep 0.50;	};
	DeleteVehicle _log_eye;
	DeleteVehicle _log_loc;
};

while {!mando_exit_hud} do {
	if (IsNull _display) then {
		if (!_hidden) then {
			_hidden = true;
		};
		_display = (UINameSpace GetVariable "mandotarget_disp");
	} else {
		if (_hidden) then {
			_hidden = false;
			if (!_optics) then {true Call _hud_show;};
		};   
	};
	if (CameraView == "GUNNER") then {
		if (!_optics) then {
			_optics = true;
			Call _hud_hide;
		};
	} else {
		if (_optics) then {
			_optics = false;
			if (!_hidden) then {false Call _hud_show;};
		};
	};
	if (!_optics and !_hidden) then {
		if (_rotate > 2) then {_rotate = 1;} else {_rotate = _rotate + 1;};
		(_display DisplayCtrl 101) CtrlSetText Format ["mando_missiles\huds\custom\images\helmet\rotate%1.paa", _rotate];
		(_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.8' align='right'>%1 KTAS</t><br /><t font='Bitstream' size='1.5' align='right'>%2 KPH</t><br /><br /><t font='Bitstream' size='1.8' align='right'>%3 MSL</t><br /><t font='Bitstream' size='1.8' align='right'>%4 AGL</t><br /><t font='Bitstream' size='1.5' align='right'>%5 M</t><br /><br /><t font='Bitstream' size='1.5' align='right'>%6</t>", Round (Speed _vehicle / 1.852), Round (Speed _vehicle), Round (((GetPosASL _vehicle) select 2) / 0.30480), Round (((GetPos _vehicle) select 2) / 0.30480), Round ((GetPos _vehicle) select 2), mando_hud_target_text];
		(_display DisplayCtrl 77) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.5' align='left'>Payload</t><br /><t font='Bitstream' size='2.0' align='left'>%1</t><br /><br /><t font='Bitstream' size='1.5' align='left'>Decoys</t><br /><t font='Bitstream' size='2.0' align='left'>%2</t><br /><br /><t font='Bitstream' size='1.5' align='left'>%3</t><br /><t font='Bitstream' size='2.0' align='left'>[%4]</t>", mando_hud_ammo_text, mando_hud_flares_text, CurrentWeapon _vehicle, _vehicle Ammo (CurrentWeapon _vehicle)];
		if (mando_hud_colors_toggled) then {
			mando_hud_colors_toggled = false;
			Call _hud_mono;
		};
	};
	if (mando_key_pressed == mando_keyspecial) then {
		mando_key_pressed = -1;
		_target = _vehicle GetVariable "mando_current_target";
		if (!IsNull _target) then {
			_vehicle SetVariable ["mando_current_target", _target, true];
			PlaySound "mando_target1";
		};
	};
	Sleep 0.25;
};

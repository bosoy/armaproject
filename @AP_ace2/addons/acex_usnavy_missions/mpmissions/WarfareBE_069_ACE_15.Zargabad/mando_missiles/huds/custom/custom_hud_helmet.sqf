/* Generic MMA HUD customisation for HMD's by deFUNKt & Mandoble - January 2010 */

private ["_alpha", "_rwr_east", "_rwr_west", "_rwr_full", "_rwr_pos", "_side", "_layout", "_hidden", "_optics", "_vehicle", "_display", "_rwr", "_rotate", "_help", "_coords", "_hud_show", "_hud_hide", "_rwr_show", "_visor_y", "_visor_x", "_opacity", "_txt1", "_txt2", "_div1", "_div2", "_units"];

DisableSerialization;

mando_show_hint = false;

// Parameters: [side, layout, visor_x, visor_y, [red, green, blue]]
// side (east or west): Selects RWR image & metres/feet as primary altitude unit.
// layout (0 - 3): Reverses left/right alignment, left/right sides.
// visor_x (1.0 +/-): Scales the visor image horizontally, optional.
// visor_y (1.0 +/-): Scales the visor image vertically, optional.
// [red, green, blue]: Starting HUD colour, optional.

_alpha = mando_hud_max_alpha;
_rwr_east = mando_rwrimg_east;
_rwr_west = mando_rwrimg_west;
_rwr_full = mando_rwrpos_full;
_rwr_pos = mando_rwrpos;
_side = _this select 0;
_layout = _this select 1;
_hidden = false;
_optics = false;
_vehicle = Vehicle player;
_display = (UINameSpace GetVariable "mandotarget_disp");
_rwr = _display DisplayCtrl 112;
_rotate = 0;
_help = "";

_coords = [] + mando_hud_coords;
_coords set [1, [-2.0, -2.0]]; // IDC 103 Target
_coords set [2, [0.20, 0.16]]; // IDC 108 Weapon
_coords set [3, [-2.0, -2.0]]; // IDC 109 Ammo
_coords set [4, [-2.0, -2.0]]; // IDC 111 Flares
_coords set [5, [0.20, 0.22]]; // IDC 113 Range

mando_hud_max_alpha = 0.00;
mando_hud_coords = [[-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2]];
mando_rwrimg_east = "mando_missiles\huds\custom\images\helmet\rwr_east.paa";
mando_rwrimg_west = "mando_missiles\huds\custom\images\helmet\rwr_west.paa";

_hud_show = {
	mando_hud_max_alpha = 0.75; 
	mando_hud_coords = [] + _coords;
	(_display DisplayCtrl 50) CtrlSetText ("mando_missiles\huds\custom\images\helmet\visor.paa");
	(_display DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, _opacity];
	(_display DisplayCtrl 50) CtrlSetPosition [SafeZoneX - (SafeZoneW * ((_visor_x - 1.00) / 2)), SafeZoneY, SafeZoneW * _visor_x, SafeZoneH * _visor_y];
	(_display DisplayCtrl 50) CtrlCommit 0.00;
	(_display DisplayCtrl 51) CtrlSetText ("mando_missiles\huds\custom\images\helmet\glow.paa");
	(_display DisplayCtrl 51) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha / 3.0];
	(_display DisplayCtrl 51) CtrlSetPosition [-0.05, 0.10, 1.10, 0.60];
	(_display DisplayCtrl 51) CtrlCommit 0.00;
	(_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format [""];
	(_display DisplayCtrl 76) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
	(_display DisplayCtrl 77) CtrlSetStructuredText ParseText Format [""];
	(_display DisplayCtrl 77) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
	if ((_layout % 3) > 0) then {
		(_display DisplayCtrl 76) CtrlSetPosition [0.10, 0.26, 0.20, 0.40];
		(_display DisplayCtrl 77) CtrlSetPosition [0.70, 0.26, 0.20, 0.40];
	} else {
		(_display DisplayCtrl 76) CtrlSetPosition [0.00, 0.26, 0.20, 0.40];
		(_display DisplayCtrl 77) CtrlSetPosition [0.80, 0.26, 0.20, 0.40];
	};
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
	Call _rwr_show;
};

_hud_hide = {
//	mando_hud_max_alpha = 0.0;
	(_display DisplayCtrl 50)  CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 51)  CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 76)  CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 77)  CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 107) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
};

_rwr_show = {
	if (_side == east) then {
		(_display DisplayCtrl 112) CtrlSetText mando_rwrimg_east;
	} else {
		(_display DisplayCtrl 112) CtrlSetText mando_rwrimg_west;
	};
	if (_layout > 1) then {
		(_display DisplayCtrl 112) CtrlSetPosition [0.034, 0.156, 0.366, 0.366*4/3];
		mando_rwrpos = [0.034+0.03, 0.156+0.03*4/3, 0.366-0.06, (0.366-0.06)*4/3];
	} else {
		(_display DisplayCtrl 112) CtrlSetPosition [0.600, 0.156, 0.366, 0.366*4/3];
		mando_rwrpos = [0.6+0.03, 0.156+0.03*4/3, 0.366-0.06, (0.366-0.06)*4/3];
	};
	(_display DisplayCtrl 112) CtrlCommit 0.00;
	(_display DisplayCtrl 112) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
    

};

if (count _this > 4) then {
	for [{_i = 0}, {_i < count mando_hud_colors}, {_i = _i + 1}] do {
		mando_hud_colors set [_i, _this select 4];
	};
};
mando_hud_rwr_line_color = [(mando_hud_colors select 0) select 0, (mando_hud_colors select 0) select 1, (mando_hud_colors select 0) select 2, 1.0];

_visor_y = 1.00;
if (count _this > 3) then {_visor_y = _this select 3;};

_visor_x = 1.00;
if (count _this > 2) then {_visor_x = _this select 2;};

_opacity = 0.20;
switch (Round DayTime) do {
case 5: {_opacity = 0.40;};
case 6: {_opacity = 0.60;};
case 7: {_opacity = 0.80;};
case 8: {_opacity = 1.00;};
case 9: {_opacity = 1.00;};
case 10: {_opacity = 1.00;};
case 11: {_opacity = 1.00;};
case 12: {_opacity = 1.00;};
case 13: {_opacity = 1.00;};
case 14: {_opacity = 1.00;};
case 15: {_opacity = 1.00;};
case 16: {_opacity = 1.00;};
case 17: {_opacity = 0.80;};
case 18: {_opacity = 0.60;};
case 19: {_opacity = 0.40;};};

if (mando_ihavemissiles) then {
	_help = _help + Format ["Lock Target: %1<br />Fire Missile: %2<br />Cycle Modes: %3", mando_keylockname, mando_keyfirename, mando_keymodename];
};
if (mando_ihaveflares) then {
	_help = _help + Format ["<br />Dispense Flares: %1", mando_keyflarename];
};
if ((_unit GetVariable "mando_ecm_time") > 0) then {
	_help = _help + Format ["<br />ECM On: %1", mando_keyecmname];
};

Call _rwr_show;

PlaySound "mando_visor";

(_display DisplayCtrl 50) CtrlSetText ("mando_missiles\huds\custom\images\helmet\visor.paa");
(_display DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, _opacity];
(_display DisplayCtrl 50) CtrlSetPosition [SafeZoneX + (SafeZoneW * 0.10), SafeZoneY, SafeZoneW * 0.80, 0.00];
(_display DisplayCtrl 50) CtrlCommit 0.00;
(_display DisplayCtrl 50) CtrlSetPosition [SafeZoneX - (SafeZoneW * ((_visor_x - 1.00) / 2)), SafeZoneY, SafeZoneW * _visor_x, SafeZoneH * _visor_y];
(_display DisplayCtrl 50) CtrlCommit 0.65;

Sleep 1.0;

(_display DisplayCtrl 51) CtrlSetText ("mando_missiles\huds\custom\images\helmet\glow.paa");
(_display DisplayCtrl 51) CtrlSetTextColor (mando_hud_colors select 0) + [0.75 / 4.5];
(_display DisplayCtrl 51) CtrlSetPosition [-0.05, 0.10, 1.10, 0.60];
(_display DisplayCtrl 51) CtrlCommit 0.00;

(_display DisplayCtrl 76) CtrlSetTextColor (mando_hud_colors select 0) + [0.75];
(_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>Please wait...</t>"];
(_display DisplayCtrl 76) CtrlSetPosition [0.10, 0.26, 0.35, 0.40];
(_display DisplayCtrl 76) CtrlCommit 0.00;
(_display DisplayCtrl 77) CtrlSetTextColor (mando_hud_colors select 0) + [0.75];
(_display DisplayCtrl 77) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75' align='right'>" + _help + "</t><br /><br /><t font='Bitstream' size='1.50' align='right'>Use the action menu to map keys or toggle the HUD.</t>"];
(_display DisplayCtrl 77) CtrlSetPosition [0.55, 0.26, 0.35, 0.40];
(_display DisplayCtrl 77) CtrlCommit 0.00;

Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...</t>", mando_missile_version];
Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...</t>", mando_missile_version];
Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...</t>", mando_missile_version];
Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Reading stores...</t>", mando_missile_version];
Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Reading stores...OK<br />Loading.</t>", mando_missile_version];
Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Reading stores...OK<br />Loading..</t>", mando_missile_version];
Sleep 1.0; (_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.75'>MMA v%1<br />Initialising...OK<br />Port...OK<br />Starboard...OK<br />Reading stores...OK<br />Loading...</t>", mando_missile_version];

Sleep 1.0;

if (_layout > 1) then {
	_txt1 = _display DisplayCtrl 77;
	_txt2 = _display DisplayCtrl 76;
} else {
	_txt1 = _display DisplayCtrl 76;
	_txt2 = _display DisplayCtrl 77;
};

if (_side == east) then {
	_div1 = 1.0; _div2 = 0.30480; _units = "FT";
} else {
	_div1 = 0.30480; _div2 = 1.0; _units = "M";
};

[_vehicle, _layout] Spawn {
	private["_tosleep", "_vehicle", "_had_null_display", "_xpos", "_display", "_angroll", "_angpitch", "_vspeed", "_poss", "_posc", "_possa", "_anga"];
	DisableSerialization;
	_vehicle = _this select 0;
	_had_null_display = false;
	if ((_this select 1) > 1) then {_xpos = 0.72;} else {_xpos = 0.28;};
	while {!mando_exit_hud} do {
		_display = (UINameSpace GetVariable "mandotarget_disp");
		_tosleep = 0.250;
		if (IsNull _display) then {
			_had_null_display = true;
		} else {
			if (_had_null_display) then {
				_had_null_display = false;
                Sleep 0.250;
			};
			if (CameraView != "GUNNER") then {
				_tosleep = 0.025;
			};
			if (TypeOf Vehicle player == "AH64D") then {
				_angroll = Deg(Vehicle player AnimationPhase "dg_bank");
				_angpitch = Deg(Vehicle player AnimationPhase "dg_pitch");
			} else {
				_angroll = Deg(Vehicle player AnimationPhase "horizonBank");
				_angpitch = Deg(Vehicle player AnimationPhase "horizonDive");
			};
			_vspeed = Velocity Vehicle player select 2;
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
				_poss = [_xpos, 0.5, _xpos, 0.5 - ((_vspeed * 0.3 / 20) Min 0.21)];
				_anga = 25;
			} else {
				_poss = [_xpos, 0.5, _xpos, 0.5 - ((_vspeed * 0.3 / 20) Max -0.21)];
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
			_poss = [_xpos - 0.01, 0.5, _xpos + 0.01, 0.5];
			(_display DisplayCtrl 74) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
			(_display DisplayCtrl 74) CtrlSetPosition [_poss select 0, _poss select 1, (_poss select 2) - (_poss select 0), (_poss select 3) - (_poss select 1)];
			(_display DisplayCtrl 74) CtrlCommit 0;
		};
		Sleep _tosleep;
	};
};

Call _hud_show;

while {!mando_exit_hud} do {
	if (CameraView == "GUNNER") then {
		if (!_optics) then {
			_optics = true;
			Call _hud_hide;
		};
	} else {
		if (_optics) then {
			_optics = false;
			if (!_hidden) then {Call _hud_show;};
		};
	};
	if (IsNull _display) then {
		if (!_hidden) then {
			_hidden = true;
		};
		_display = (UINameSpace GetVariable "mandotarget_disp");
	} else {
		if (_hidden) then {
			_hidden = false;
			if (_layout > 1) then {
				_txt1 = _display DisplayCtrl 77;
				_txt2 = _display DisplayCtrl 76;
			} else {
				_txt1 = _display DisplayCtrl 76;
				_txt2 = _display DisplayCtrl 77;
			};
			_rwr = _display DisplayCtrl 112;
			if (!_optics) then {Call _hud_show;};
		};   
	};
	if (!_optics and !_hidden) then {
		if (_rotate > 2) then {_rotate = 1;} else {_rotate = _rotate + 1;};
		(_display DisplayCtrl 101) CtrlSetText Format ["mando_missiles\huds\custom\images\helmet\rotate%1.paa", _rotate];
		if ((_layout % 2) > 0) then {
			_txt1 CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.5' align='left'>Payload</t><br /><t font='Bitstream' size='2.0' align='left'>%1</t><br /><br /><t font='Bitstream' size='1.5' align='left'>Decoys</t><br /><t font='Bitstream' size='2.0' align='left'>%2</t><br /><br /><t font='Bitstream' size='1.5' align='left'>%3</t><br /><t font='Bitstream' size='2.0' align='left'>[%4]</t>", mando_hud_ammo_text, mando_hud_flares_text, CurrentWeapon _vehicle, _vehicle Ammo (CurrentWeapon _vehicle)];
			_txt2 CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.8' align='right'>%1 KTAS</t><br /><t font='Bitstream' size='1.5' align='right'>%2 KPH</t><br /><br /><t font='Bitstream' size='1.8' align='right'>%3 MSL</t><br /><t font='Bitstream' size='1.8' align='right'>%4 AGL</t><br /><t font='Bitstream' size='1.5' align='right'>%5 %6</t><br /><br /><t font='Bitstream' size='1.5' align='right'>%7</t>", Round (Speed _vehicle / 1.852), Round (Speed _vehicle), Round (((GetPosASL _vehicle) select 2) / _div1), Round (((GetPos _vehicle) select 2) / _div1), Round (((GetPos _vehicle) select 2) / _div2), _units, mando_hud_target_text];
		} else {
			_txt1 CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.5' align='right'>Payload</t><br /><t font='Bitstream' size='2.0' align='right'>%1</t><br /><br /><t font='Bitstream' size='1.5' align='right'>Decoys</t><br /><t font='Bitstream' size='2.0' align='right'>%2</t><br /><br /><t font='Bitstream' size='1.5' align='right'>%3</t><br /><t font='Bitstream' size='2.0' align='right'>[%4]</t>", mando_hud_ammo_text, mando_hud_flares_text, CurrentWeapon _vehicle, _vehicle Ammo (CurrentWeapon _vehicle)];
			_txt2 CtrlSetStructuredText ParseText Format ["<t font='Bitstream' size='1.8' align='left'>%1 KTAS</t><br /><t font='Bitstream' size='1.5' align='left'>%2 KPH</t><br /><br /><t font='Bitstream' size='1.8' align='left'>%3 MSL</t><br /><t font='Bitstream' size='1.8' align='left'>%4 AGL</t><br /><t font='Bitstream' size='1.5' align='left'>%5 %6</t><br /><br /><t font='Bitstream' size='1.5' align='left'>%7</t>", Round (Speed _vehicle / 1.852), Round (Speed _vehicle), Round (((GetPosASL _vehicle) select 2) / _div1), Round (((GetPos _vehicle) select 2) / _div1), Round (((GetPos _vehicle) select 2) / _div2), _units, mando_hud_target_text];
		};
		if (mando_hud_colors_toggled) then {
			mando_hud_colors_toggled = false;
			mando_hud_rwr_line_color = [(mando_hud_colors select 0) select 0, (mando_hud_colors select 0) select 1, (mando_hud_colors select 0) select 2, 1.0];
			(_display DisplayCtrl 107) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
			(_display DisplayCtrl 51) CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha / 3.0];
			_rwr CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
			_txt1 CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
		};
		if (CtrlShown _rwr) then {
			_txt2 CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
		} else {
			_txt2 CtrlSetTextColor (mando_hud_colors select 0) + [mando_hud_max_alpha];
		};
	};
	Sleep 0.25;
};

mando_hud_max_alpha = _alpha;
mando_rwrimg_east = _rwr_east;
mando_rwrimg_west = _rwr_west;
mando_rwrpos_full = _rwr_full;
mando_rwrpos = _rwr_pos;
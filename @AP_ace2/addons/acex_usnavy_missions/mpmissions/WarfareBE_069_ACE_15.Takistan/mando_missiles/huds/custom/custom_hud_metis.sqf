/* Customised MMA HUD for the Metis AT-13, by deFUNKt - December 2009 */

private ["_optics", "_missile", "_launched", "_testflag", "_fovstate", "_power_up", "_aperture", "_weapon", "_control_show", "_pp_effects"];

DisableSerialization;

mando_hud_coords = [[-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2]];
mando_hud_colors = [[0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5]];

_optics = false;
_missile = objnull;
_launched = 0;
_testflag = 0;
_fovstate = 0;
_power_up = 40;
_aperture = 0.08;
_weapon = CurrentWeapon Vehicle player;

switch (Round DayTime) do {
case 5: {_aperture = 00.40;};
case 6: {_aperture = 02.00;};
case 7: {_aperture = 10.00;};
case 8: {_aperture = 50.00;};
case 9: {_aperture = 50.00;};
case 10: {_aperture = 50.00;};
case 11: {_aperture = 50.00;};
case 12: {_aperture = 50.00;};
case 13: {_aperture = 50.00;};
case 14: {_aperture = 50.00;};
case 15: {_aperture = 50.00;};
case 16: {_aperture = 50.00;};
case 17: {_aperture = 10.00;};
case 18: {_aperture = 02.00;};
case 19: {_aperture = 00.40;};};

_control_show = {

	private ["_idno", "_show", "_ctrl", "_xpos", "_xdim", "_ypos", "_ydim"];

	_idno = _this select 0;
	_show = _this select 1;
	_ctrl = (UINameSpace GetVariable "mandotarget_disp") DisplayCtrl _idno;

	if (_show == 0) exitwith {_ctrl CtrlSetText "";};
	if (_show >= 1) exitwith {_ctrl CtrlSetText Format ["mando_missiles\huds\custom\images\metis\lamp%1%2.paa", _idno - 51, _show - 1];};

	_xpos = SafeZoneX; _xdim = 0.23426061 * SafeZoneW;
	_ypos = SafeZoneY; _ydim = 0.31250000 * SafeZoneH;
	
	switch (_idno) do {
	case 51: /* TOP-LEFT */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.12445095);
		_ypos = SafeZoneY;
	};
	case 52: /* TOP-RIGHT */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.64128843);
		_ypos = SafeZoneY;
	};
	case 53: /* BOTTOM-RIGHT */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.64128843);
		_ypos = SafeZoneY + (SafeZoneH * 0.68750000);
	};
	case 54: /* BOTTOM-LEFT */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.12445095);
		_ypos = SafeZoneY + (SafeZoneH * 0.68750000);
	};};

	_ctrl CtrlSetPosition [_xpos, _ypos, _xdim, _ydim];
	_ctrl CtrlCommit 0;
	_ctrl CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
	_ctrl CtrlSetText Format ["mando_missiles\huds\custom\images\metis\lamp%1%2.paa", _idno - 51, (Abs _show) - 1];

};

_pp_effects = {

	private ["_init"];
	
	_init = _this select 1;
	
	switch (_this select 0) do {
	case 0: {
		[51, 0] Call _control_show;
		SetAperture -1;
		PPEffectDestroy mando_ppccor;
		PPEffectDestroy mando_ppcinv;
		PPEffectDestroy mando_ppdyblur;
		PPEffectDestroy mando_ppfgrain;
	};
	case 1: {
		if (_init > -1) then {
			[51, 2] Call _control_show;
			Sleep 0.25;
		};
		SetAperture -1;
		PPEffectDestroy mando_ppccor;
		mando_ppccor = PPEffectCreate ["ColorCorrections", 1];
		mando_ppccor PPEffectEnable true;
		mando_ppccor PPEffectAdjust [1.10, 1.00, 0.00, [0.80, 0.90, 1.00, -0.10], [1.00, 1.00, 1.00, 0.75], [1.00, 1.00, 1.00, 0.75]];
		mando_ppccor PPEffectCommit 0;
		PPEffectDestroy mando_ppcinv;
		PPEffectDestroy mando_ppdyblur;
		PPEffectDestroy mando_ppfgrain;
		Sleep 0.25;
		[51, 1 * _init] Call _control_show;
	};
	case 2: {
		[51, 2 * _init] Call _control_show;
		if (_init > -1) then {Sleep 0.25;};
		SetAperture _aperture; // NB: In scope when Call'ed.
		PPEffectDestroy mando_ppccor;
		mando_ppccor = PPEffectCreate ["ColorCorrections", 1];
		mando_ppccor PPEffectEnable true;
		mando_ppccor PPEffectAdjust [1, 1, -0.002, [1, 1, 1, 0.1], [1, 1, 1, 0], [1, 1, 1, 0]];
		mando_ppccor PPEffectCommit 0;
		PPEffectDestroy mando_ppcinv;
		mando_ppcinv = PPEffectCreate ["ColorInversion", 2];
		mando_ppcinv PPEffectEnable true;
		mando_ppcinv PPEffectAdjust [0.2, 0.2, 0.2];
		mando_ppcinv PPEffectCommit 0;
		PPEffectDestroy mando_ppdyblur;
		mando_ppdyblur = PPEffectCreate ["DynamicBlur", 0];
		mando_ppdyblur PPEffectEnable true;  
		mando_ppdyblur PPEffectAdjust [0.4];
		mando_ppdyblur PPEffectCommit 0;
		PPEffectDestroy mando_ppfgrain;
		mando_ppfgrain = PPEffectCreate ["FilmGrain", 2005];
		mando_ppfgrain PPEffectEnable true;
		mando_ppfgrain PPEffectAdjust [0.02, 1.0, 1.0, 0.0, 1.0];
		mando_ppfgrain PPEffectCommit 0;
		Sleep 0.25;
		[51, 4] Call _control_show;
	};
	case 3: {
		[51, 2 * _init] Call _control_show;
		if (_init > -1) then {Sleep 0.25;};
		SetAperture _aperture; // NB: In scope when Call'ed.
		PPEffectDestroy mando_ppccor;
		mando_ppccor = PPEffectCreate ["ColorCorrections", 1999];
		mando_ppccor PPEffectEnable true;
		mando_ppccor PPEffectAdjust [1.0, 1.0, 0.0, [1.0, 1.0, 1.0, 0.0], [1.0, 1.0, 1.0, 0.0], [1.0, 1.0, 1.0, 1.0]];
		mando_ppccor PPEffectCommit 0;
		PPEffectDestroy mando_ppcinv;
		mando_ppcinv = PPEffectCreate ["ColorInversion", 2555];
		mando_ppcinv PPEffectEnable true;
		mando_ppcinv PPEffectAdjust [1.0, 1.0, 1.0];
		mando_ppcinv PPEffectCommit 0;
		PPEffectDestroy mando_ppdyblur;
		mando_ppdyblur = PPEffectCreate ["DynamicBlur", 505];
		mando_ppdyblur PPEffectEnable true;  
		mando_ppdyblur PPEffectAdjust [0.5];
		mando_ppdyblur PPEffectCommit 0;
		PPEffectDestroy mando_ppfgrain;
		mando_ppfgrain = PPEffectCreate ["FilmGrain", 2005];
		mando_ppfgrain PPEffectEnable true;
		mando_ppfgrain PPEffectAdjust [0.02, 1.0, 1.0, 0.0, 1.0];
		mando_ppfgrain PPEffectCommit 0;
		Sleep 0.25;
		[51, 4] Call _control_show;
	};};

};

((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 107) CtrlSetText "mando_missiles\huds\custom\images\metis\empty.paa";
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetText ("mando_missiles\huds\custom\images\metis\reticle.paa");
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];

[51, 4] Call _control_show;
[51, 3] Call _control_show;
[51, 2] Call _control_show;
[53, 4] Call _control_show;
[53, 3] Call _control_show;
[53, 2] Call _control_show;

for [{_i = 51}, {_i < 55}, {_i = _i + 1}] do {
	[_i, 1] Call _control_show;
};

((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 55) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 55) CtrlSetText "mando_missiles\huds\custom\images\metis\tracker.paa";
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 55) CtrlSetPosition [-2, -2, SafeZoneW * 0.024 * 2, SafeZoneH * 0.032 * 2];
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 55) CtrlCommit 0;

((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["Infra-Red Modes<br />= %1<br />On firing guide the missile to the target manually.", mando_keyflarename];
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.0875, 0.4750, 0.1000];
((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlCommit 0;

[_weapon] Spawn {
	private ["_weapon", "_missile", "_control", "_follow_old"];
	DisableSerialization;
	_weapon = _this select 0;
	while {!mando_exit_hud} do {
		if (mando_hud_fired) then {
			Sleep 0.050;
			_missile = ((Position vehicle player) NearestObject "MissileBase");
			_control = (UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 55;
			_follow_old = true;
			mando_missile_follow = true;
			while {(Alive _missile) && !mando_exit_hud} do {
				if (CameraView == "GUNNER") then {
					_tracker = WorldToScreen GetPos _missile;
					_control CtrlSetPosition [(_tracker select 0) - SafeZoneW * 0.024, (_tracker select 1) - SafeZoneH * 0.032];
					_control CtrlCommit 0;
					_control CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
					if ((_follow_old || mando_missile_follow) && !(_follow_old && mando_missile_follow)) then {
						_follow_old = mando_missile_follow;
						if (mando_missile_follow) then {
							((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 53) CtrlSetText "mando_missiles\huds\custom\images\metis\lamp22.paa";
						} else {
							((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 53) CtrlSetText "mando_missiles\huds\custom\images\metis\lamp23.paa";
						};
					};
					Sleep 0.025;
				} else {
					_control CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
					Sleep 0.500;
				};
			};
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 53) CtrlSetText "mando_missiles\huds\custom\images\metis\lamp23.paa";
			_control CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
			mando_hud_fired = false;
		};
		Sleep 0.05;
	};
};



while {!mando_exit_hud} do {
	if (CameraView == "GUNNER") then {
		if (!_optics) then {
			_launched = 0;
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetPosition [SafeZoneX, SafeZoneY, SafeZoneW, SafeZoneH];
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlCommit 0;
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetText ("mando_missiles\huds\custom\images\metis\reticle.paa");
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
			[_fovstate + 1, -1] Call _pp_effects;
			[52, -1] Call _control_show;
			[53, -1] Call _control_show;
			[54, -1] Call _control_show;
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
			_optics = true;
		};
	} else {
		if (_optics) then {
			_optics = false;
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 76) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
			[54, 0] Call _control_show;
			[53, 0] Call _control_show;
			[52, 0] Call _control_show;
			[0, 1] Call _pp_effects;
			((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 50) CtrlSetText "";
			_launched = 0;
		};
	};
	if (_optics) then {
		if (mando_key_pressed != 0) then {
			switch (mando_key_pressed) do {
			case mando_keyfire: {
				// NB: Has issues (must wait between presses).
			};
			case mando_keyecm: {
				// NB: Has issues (denied sound).
			};
			case mando_keyflare: {
				if (_power_up > 0) then {
					PlaySound "mando_denied";
				} else {
					_fovstate = (_fovstate + 1) % 3;
					[_fovstate + 1, 1] Call _pp_effects;
				};
			};};
			mando_key_pressed = 0;
		};
		if ((vehicle player Ammo _weapon) == 0) then {
			_testflag = 1; Sleep 0.05; // NB: Allow mando_hud_fired to be set.
		} else {
			_testflag = 0;
		};
		if (_launched != _testflag) then {
			if (_testflag == 1) then { // Missile fired.
				if (mando_hud_fired) then {
					[53, 2] Call _control_show;
					Sleep 0.25;
					[53, 3] Call _control_show;
				} else {
					[53, 4] Call _control_show;
				};
			};
			_launched = _testflag;
		};
		if (_power_up > 0) then {
			_power_up = _power_up - 1;
			if (_power_up > 0) then {
				if ((_power_up % 2) == 0) then {
					[51, ((_power_up % 4) / 2) + 2] Call _control_show;
				};
			} else {
				[51, 0] Call _control_show;
			};
		};
	};
	Sleep 0.25;
};

[0, 1] Call _pp_effects;

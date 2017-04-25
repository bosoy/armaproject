/* Customised MMA HUD for the FGM-148 Javelin, by deFUNKt - December 2009 */

private ["_has_addon", "_display", "_hidden", "_optics", "_target", "_lockflag", "_testflag", "_old_mode", "_nvgmode", "_blinking", "_power_up", "_sleep", "_aperture", "_addon_ver", "_hud_lamp", "_hud_ppfx", "_hud_init", "_hud_show", "_hud_hide", "_world_pos", "_screen_xy"];

DisableSerialization;

_display = displaynull;
_hidden = false;
_optics = false;
_target = objnull;
_widefov = true;
_lockflag = 0;
_testflag = 0;
_old_mode = 0;
_nvgmode = 0;
_blinking = 0;
_addon_ver = GetNumber (ConfigFile >> "CfgPatches" >> "mando_portables" >> "Version");
_has_oa = IsClass (ConfigFile >> "CfgVehicles" >> "A10_US_EP1");
_power_up = if (_has_oa) then {0;} else {30;};
_sleep = 0.25;
_aperture = 0.08;
_has_addon = false;
if (GetNumber (ConfigFile >> "CfgPatches" >> "mando_portables" >> "RequiredVersion") > 0) then
{
   _has_addon = true;
};

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

_hud_lamp = {

	private ["_idno", "_show", "_ctrl", "_xpos", "_xdim", "_ypos", "_ydim"]; // NOT: _display

	_idno = _this select 0;
	_show = _this select 1;
	_ctrl = _display DisplayCtrl _idno;
	
	if (_show == 0) exitwith {_ctrl CtrlSetText "";};
	if (_show >= 1) exitwith {_ctrl CtrlSetText Format ["mando_missiles\huds\custom\images\javelin\lamp%1%2.paa", _idno, _show];};
	
	// TODO: _xpos = SafeZoneX; _xdim = 0.13671875 * (((SafeZoneW * 3) / 4) / SafeZoneW) / (1 / SafeZoneH);
	
	_xpos = SafeZoneX; _xdim = 0.10248902 * SafeZoneW;
	_ypos = SafeZoneY; _ydim = 0.13671875 * SafeZoneH;
	
	switch (_idno) do {
	case 53: /* DAY */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.18521230);
		_ypos = SafeZoneY + (SafeZoneH * 0.01171875);
	};
	case 54: /* WFOV */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.36090776);
		_ypos = SafeZoneY + (SafeZoneH * 0.01171875);
	};
	case 55: /* NFOV */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.53660322);
		_ypos = SafeZoneY + (SafeZoneH * 0.01171875);
	};
	case 56: /* SEEK */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.71229868);
		_ypos = SafeZoneY + (SafeZoneH * 0.01171875);
	};
	case 57: /* TOP */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.88799414);
		_ypos = SafeZoneY + (SafeZoneH * 0.22167969);
	};
	case 58: /* DIR */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.88799414);
		_ypos = SafeZoneY + (SafeZoneH * 0.43164063);
	};
	case 59: /* FLTR or GRND */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.88799414);
		_ypos = SafeZoneY + (SafeZoneH * 0.64160156);
	};
	case 60: /* WAIT */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.71229868);
		_ypos = SafeZoneY + (SafeZoneH * 0.85156250);
	};
	case 61: /* MSL */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.53660322);
		_ypos = SafeZoneY + (SafeZoneH * 0.85156250);
	};
	case 62: /* HANG */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.36090776);
		_ypos = SafeZoneY + (SafeZoneH * 0.85156250);
	};
	case 63: /* BCU */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.18521230);
		_ypos = SafeZoneY + (SafeZoneH * 0.85156250);
	};
	case 64: /* CLU+ */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.00951684);
		_ypos = SafeZoneY + (SafeZoneH * 0.64160156);
	};
	case 65: /* CLU */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.00951684);
		_ypos = SafeZoneY + (SafeZoneH * 0.43164063);
	};
	case 66: /* NIGHT */ {
		_xpos = SafeZoneX + (SafeZoneW * 0.00951684);
		_ypos = SafeZoneY + (SafeZoneH * 0.22167969);
	};};

	_ctrl CtrlSetPosition [_xpos, _ypos, _xdim, _ydim];
	_ctrl CtrlCommit 0;
	_ctrl CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
	_ctrl CtrlSetText Format ["mando_missiles\huds\custom\images\javelin\lamp%1%2.paa", _idno, Abs _show];
	
};

_hud_ppfx = {

	private ["_init"]; // NOT: _aperture
	
	_init = _this select 1;
	
	switch (_this select 0) do {
	case 0: {
		SetAperture -1;
		PPEffectDestroy mando_ppccor;
		PPEffectDestroy mando_ppcinv;
		PPEffectDestroy mando_ppdyblur;
		PPEffectDestroy mando_ppfgrain;
		[53, 0] Call _hud_lamp;
	};
	case 1: {
		SetAperture -1;
		PPEffectDestroy mando_ppccor;
		mando_ppccor = PPEffectCreate ["ColorCorrections", 1];
		mando_ppccor PPEffectEnable true;
		mando_ppccor PPEffectAdjust [1.05, 0.95, 0.00, [0.80, 0.90, 1.00, -0.10], [0.75, 1.50, 0.75, 0.75], [0.75, 1.50, 0.75, 1.00]];
		mando_ppccor PPEffectCommit 0;
		PPEffectDestroy mando_ppcinv;
		PPEffectDestroy mando_ppdyblur;
		PPEffectDestroy mando_ppfgrain;
		[53, 2 * _init] Call _hud_lamp;
	};
	case 2: {
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
		[53, 1 * _init] Call _hud_lamp;
	};
	case 3: {
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
		[53, 1 * _init] Call _hud_lamp;
	};};

};

_hud_init = {

	private []; // NOT: _display, _hud_lamp
	
	(_display DisplayCtrl 101)   CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 107)   CtrlSetTextColor [0.0, 0.0, 0.0, 0.0];
	(_display DisplayCtrl 23929) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 23930) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 23931) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 23932) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 23933) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 23934) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 23935) CtrlSetText "mando_missiles\huds\custom\images\javelin\empty.paa";
	(_display DisplayCtrl 50)    CtrlSetText Format ["mando_missiles\huds\custom\images\javelin\reticle_%1.paa", (if (_has_oa) then {"oa";} else {"a2";})];
	(_display DisplayCtrl 50)    CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
	for [{_i = 53}, {_i < 62}, {_i = _i + 1}] do {
		[_i, 2] Call _hud_lamp;	Sleep 0.001;
		[_i, 1] Call _hud_lamp;
	};
	[62, 1] Call _hud_lamp;
	[63, 1] Call _hud_lamp;
	[64, 1] Call _hud_lamp;
	[65, 1] Call _hud_lamp;
	[66, 2] Call _hud_lamp;	Sleep 0.001;
	[66, 1] Call _hud_lamp;
	(_display DisplayCtrl 76) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 76) CtrlSetStructuredText ParseText Format ["<br /><br />Infra-Red Mode: %1<br />Targeting Mode: %2<br />Lock Target: %3<br /><br />Fire normally when locked.", (if (_has_oa) then {ActionKeysNames "NightVision";} else {mando_keyflarename;}), mando_keymodename, mando_keylockname];
	(_display DisplayCtrl 76) CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.1875, 0.4750, 0.2000];
	(_display DisplayCtrl 76) CtrlCommit 0.0;
	
	WaitUntil {count mando_hud_coords > 5};
	
	mando_hud_coords = [[-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2]];
	mando_hud_colors = [[0.8, 0.4, 0.4], [1.0, 1.0, 1.0], [1.0, 1.0, 1.0], [1.0, 1.0, 1.0], [1.0, 1.0, 1.0], [1.0, 1.0, 1.0]];
	mando_hud_max_alpha = 1.00;
	
	if (_this) then {Call _hud_show;};
	
};

_hud_show = {

	private []; // NOT: _display, _nvgmode, _hud_ppfx, _hud_lamp, _widefov, _old_mode
	
	(_display DisplayCtrl 50) CtrlSetPosition [SafeZoneX, SafeZoneY, SafeZoneW, SafeZoneH];
	(_display DisplayCtrl 50) CtrlCommit 0;
	(_display DisplayCtrl 50) CtrlSetText Format ["mando_missiles\huds\custom\images\javelin\reticle_%1.paa", (if (_has_oa) then {"oa";} else {"a2";})];
	(_display DisplayCtrl 50) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
	(_display DisplayCtrl 51) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 51) CtrlSetBackgroundColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 51) CtrlSetText "mando_missiles\huds\custom\images\javelin\line_x.paa";
	(_display DisplayCtrl 52) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 52) CtrlSetBackgroundColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 52) CtrlSetText "mando_missiles\huds\custom\images\javelin\line_y.paa";
	
	(_display DisplayCtrl 67) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 67) CtrlSetBackgroundColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 67) CtrlSetText "mando_missiles\4corners.paa";
	
	
	[_nvgmode + 1, -1] Call _hud_ppfx;
	[54, (if (_widefov) then {-2} else {-1})] Call _hud_lamp;
	[55, (if (_widefov) then {-1} else {-2})] Call _hud_lamp;
	[56, -1] Call _hud_lamp;
	[57, -1] Call _hud_lamp; _old_mode = -1; // Force mode test.
	[58, -1] Call _hud_lamp;
	[59, -1] Call _hud_lamp;
	[60, -2] Call _hud_lamp;
	[61, -1] Call _hud_lamp;
	[62, -1] Call _hud_lamp;
	[63, -1] Call _hud_lamp;
	[64, -1] Call _hud_lamp;
	[65, -1] Call _hud_lamp;
	[66, -1] Call _hud_lamp;
	(_display DisplayCtrl 76)  CtrlSetTextColor (if (mando_show_hint_global) then {[1.0, 1.0, 1.0, 0.375];} else {[1.0, 1.0, 1.0, 0.00];});
	(_display DisplayCtrl 107) CtrlSetTextColor (if (_addon_ver < 1.00) then {[0.0, 1.0, 0.0, 0.5];} else {[1.0, 1.0, 1.0, 0.5];});
	
};

_hud_hide = {

	private []; // NOT: _display, _hud_lamp, _hud_ppfx
	
	(_display DisplayCtrl 107) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	(_display DisplayCtrl 76)  CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
	[66, 0] Call _hud_lamp;
	[65, 0] Call _hud_lamp;
	[64, 0] Call _hud_lamp;
	[63, 0] Call _hud_lamp;
	[62, 0] Call _hud_lamp;
	[61, 0] Call _hud_lamp;
	[60, 0] Call _hud_lamp;
	[59, 0] Call _hud_lamp;
	[58, 0] Call _hud_lamp;
	[57, 0] Call _hud_lamp;
	[56, 0] Call _hud_lamp;
	[55, 0] Call _hud_lamp;
	[54, 0] Call _hud_lamp;
	[0, 1] Call _hud_ppfx;
	(_display DisplayCtrl 52) CtrlSetText "";
	(_display DisplayCtrl 51) CtrlSetText "";
	(_display DisplayCtrl 50) CtrlSetText "";
	
	(_display DisplayCtrl 67)  CtrlSetText "";
	
};

_hud_wfov = {

	private ["_dir", "_pos"];
	_pos = WorldToScreen positionCameraToWorld [0,1,1];	
	if (count _pos == 2) exitwith {(_pos select 1) > -18;};	
	false;

};

while {!mando_exit_hud} do {
	if (IsNull _display) then {
		if (!_hidden) then {
			mando_hud_max_alpha = 0.00;
			_hidden = true;
		};
		_display = (UINameSpace GetVariable "mandotarget_disp");
	} else {
		if (_hidden) then {
			_optics Call _hud_init;
			_hidden = false;
		};
	};
	if (CameraView == "GUNNER") then {
		if (!_optics) then {
			_optics = true;
			_lockflag = 0;
			if (!_hidden) then {Call _hud_show;};
		};
	} else {
		if (_optics) then {
			_optics = false;
			_lockflag = 0;
			Call _hud_hide;
		};
	};
	_sleep = 0.25;
	if (_optics and !_hidden) then {
		if (mando_key_pressed != 0) then {
			if (!_has_oa) then {
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
						_nvgmode = (_nvgmode + 1) % 3;
						[_nvgmode + 1, 1] Call _hud_ppfx;
					};
				};};
			};
			mando_key_pressed = 0;
		};
		if (mando_hud_mode != _old_mode) then {
			if (_old_mode == 0) then {[57, 1] Call _hud_lamp;};
			if (_old_mode == 1) then {[58, 1] Call _hud_lamp;};
			if (_old_mode == 2) then {[58, 1] Call _hud_lamp; [59, 1] Call _hud_lamp;};
			if (mando_hud_mode == 0) then {[57, 2] Call _hud_lamp;};
			if (mando_hud_mode == 1) then {[58, 2] Call _hud_lamp;};
			if (mando_hud_mode == 2) then {[58, 2] Call _hud_lamp; [59, 2] Call _hud_lamp;};
			_old_mode = mando_hud_mode;
		};
		if (_lockflag < 3) then { // Not already fired.
			if (!IsNull mando_lockingon) then {_testflag = 1;} else {_testflag = 0;};
			if (!IsNull (player GetVariable "mando_current_target")) then {_testflag = 2;};
			if ((player Ammo (currentWeapon vehicle player)) == 0) then {_testflag = 3;};
		} else { // Check for reload.
			if ((player Ammo (currentWeapon vehicle player)) != 0) then {_testflag = 0;};
		};
		if (_lockflag != _testflag) then {
			if (_lockflag == 2) then { // Lock has been lost.
				(_display DisplayCtrl 51) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
				(_display DisplayCtrl 52) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
				(_display DisplayCtrl 67) CtrlSetTextColor [1.0, 1.0, 1.0, 0.0];
				[56, 1] Call _hud_lamp; // SEEK Off
				[60, 2] Call _hud_lamp; // WAIT On
			};
			if (_testflag == 2) then { // Lock has been achieved.
				_target = player GetVariable "mando_current_target";
				[56, 2] Call _hud_lamp; // SEEK On
				[60, 1] Call _hud_lamp; // WAIT Off
			};
			if (_testflag == 3) then { // Missile fired.
				mando_hud_fired = false; // NB: Not used.
				[61, 2] Call _hud_lamp; // MSL On
			};
			_lockflag = _testflag;
		};
		if (_lockflag == 1) then {
			_blinking = (_blinking + 1) % 2;
			[56, _blinking + 1] Call _hud_lamp;
		};
		if (_lockflag == 2) then {
			_world_pos = GetPos _target;
			_world_pos set [2, (_world_pos select 2) + (((_target ModelToWorld [0, 0, 0]) select 2) - (_world_pos select 2)) / 2];
			_screen_xy = WorldToScreen _world_pos; 
			(_display DisplayCtrl 51) CtrlSetPosition (if (_has_addon) then {[0.100, _screen_xy select 1, 0.800, 0.002]} else {[0.200, _screen_xy select 1, 0.600, 0.002]}); ;
			(_display DisplayCtrl 51) CtrlCommit 0;
			(_display DisplayCtrl 52) CtrlSetPosition [_screen_xy select 0, 0.1500, 0.0020, 0.7000];
			(_display DisplayCtrl 52) CtrlCommit 0;
			(_display DisplayCtrl 51) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
			(_display DisplayCtrl 52) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];

            if ((count crew _target) > 0) then
			{
			   _bound = boundingBox _target;
//               _bound = [[-2,-4,-2],[2,4,2]];
               _bound = _bound + [[(_bound select 0) select 0,(_bound select 1) select 1,(_bound select 0) select 2]];
			   _bound = _bound + [[(_bound select 1) select 0,(_bound select 0) select 1,(_bound select 0) select 2]];
			   _minsx = 1000;
			   _minsy = 1000;
			   _maxsx = -1000;
			   _maxsy = -1000;
			   {
			      _ps = worldToScreen (_target modelToWorld _x);
				  if ((_ps select 0) > _maxsx) then
				  {
				     _maxsx = _ps select 0;
				  };
				  if ((_ps select 0) < _minsx) then
				  {
				     _minsx = _ps select 0;
				  };		  

				  if ((_ps select 1) > _maxsy) then
				  {
				     _maxsy = _ps select 1;
				  };
				  if ((_ps select 1) < _minsy) then
				  {
				     _minsy = _ps select 1;
				  };		  
			   } forEach _bound;
			   
			   (_display DisplayCtrl 67) CtrlSetPosition [_minsx, 
														  _minsy,
														  _maxsx - _minsx, 
														  _maxsy - _minsy];
			   (_display DisplayCtrl 67) CtrlCommit 0;					   
			}
			else
			{
			   (_display DisplayCtrl 67) CtrlSetPosition [(_screen_xy select 0)-0.05, (_screen_xy select 1)-0.05, 0.1, 0.1];
			   (_display DisplayCtrl 67) CtrlCommit 0;		
			};
			(_display DisplayCtrl 67) CtrlSetTextColor [1.0, 1.0, 1.0, 1.0];
			_sleep = 0.05;
		} else {
			if  (_power_up > 0) then {
				_power_up = (_power_up - 1);
				[66, (_power_up % 2) + 1] Call _hud_lamp;
			};
		};
		if (_widefov) then {
			_widefov = Call _hud_wfov;
			if (!_widefov) then {
				[54, 1] Call _hud_lamp;
				[55, 2] Call _hud_lamp;
			};
		} else {
			_widefov = Call _hud_wfov;
			if (_widefov) then {
				[54, 2] Call _hud_lamp;
				[55, 1] Call _hud_lamp;
			};
		};
		if (_has_oa) then {
			if (_nvgmode == 0) then {
				Call Compile "_nvgmode = if ((CurrentVisionMode player) == 0) then {0;} else {1;};";
				if (_nvgmode != 0) then {[53, 1] Call _hud_lamp;};
			} else {
				Call Compile "_nvgmode = if ((CurrentVisionMode player) == 0) then {0;} else {1;};";
				if (_nvgmode == 0) then {[53, 2] Call _hud_lamp;};
			};
		};
	};
	Sleep _sleep;
};

[0, 1] Call _hud_ppfx;

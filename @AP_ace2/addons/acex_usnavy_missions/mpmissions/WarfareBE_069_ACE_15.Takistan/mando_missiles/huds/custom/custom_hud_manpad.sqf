/* Customised MMA HUD for Stinger/Igla/Strela, by deFUNKt - December 2009 */

private ["_target", "_weapon", "_lockflag", "_testflag", "_sleep", "_topleft", "_bottomright"];

DisableSerialization;

mando_hud_coords = [[-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2]];
mando_hud_colors = [[0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5]];
mando_hud_aperture = 0.03;
mando_hud_max_alpha = 0.0;

_display = displaynull;
_hidden = false;
_target = objnull;
_weapon = _this select 0;
_lockflag = 0;
_testflag = 0;
_sleep = 0.25;

_hud_init = {

	(_display DisplayCtrl 76)  CtrlSetTextColor [1.0, 1.0, 1.0, 0.5];
	(_display DisplayCtrl 76)  CtrlSetStructuredText ParseText Format ["<br /><br /><br /><br />Lock Target: %1<br /><br />Fire normally when you have a continuous lock tone/growl.", mando_keylockname];
	(_display DisplayCtrl 76)  CtrlSetPosition [SafeZoneX + 0.0125, SafeZoneY + SafeZoneH - 0.1875, 0.4750, 0.2000];
	(_display DisplayCtrl 76)  CtrlCommit 0;
	(_display DisplayCtrl 107) CtrlSetText "mando_missiles\huds\custom\images\manpad\empty.paa";

};
	
while {!mando_exit_hud} do {
	if (IsNull _display) then {
		if (!_hidden) then {
			_hidden = true;
		};
		_display = (UINameSpace GetVariable "mandotarget_disp");
	} else {
		if (_hidden) then {
			Call _hud_init;
			_hidden = false;
		};
	};
	_sleep = 0.25;
	if (_lockflag < 3) then { // Not already fired.
		if (!IsNull mando_lockingon) then {_testflag = 1;} else {_testflag = 0;};
		if (!IsNull (vehicle player GetVariable "mando_current_target")) then {_testflag = 2;};
		if ((vehicle player Ammo _weapon) == 0) then {_testflag = 3;};
	} else { // Check for reload.
		if ((vehicle player Ammo _weapon) != 0) then {_testflag = 0;};
	};
	if (_lockflag != _testflag) then {
		if (_testflag == 3) then { // Missile fired.
			mando_hud_fired = false; // NB: Not used.
		};
		_lockflag = _testflag;
	};
	if (_lockflag == 1) then {
		PlaySound "mando_LockBeep";
		_topleft = CtrlPosition ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 86);
		_bottomright = CtrlPosition ((UINameSpace GetVariable "mandotarget_disp") DisplayCtrl 89);
		_sleep = 0.1 Max SqRt ((((_bottomright select 0) - (_topleft select 0)) ^ 2) + (((_bottomright select 1) - (_topleft select 1)) ^ 2));
	};
	if (_lockflag == 2) then {
		PlaySound "mando_LockTone";
	};
	Sleep _sleep;
};

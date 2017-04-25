#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);
//PREP(keypressed);
PREP(keypressed_cook);
PREP(applyPosVel);
PREP(applyPosVelPFH);
PREP(applyPosVel_veh);
PREP(cursor);
PREP(throwselected);
PREP(indicator);
PREP(mkey);
	
GVAR(presstime) = 0;
GVAR(reset) = 0;
GVAR(speed) = 1;	//multiplier of init speed set in mag config
GVAR(mode) = 0;
GVAR(grenadecursor) = false;
GVAR(holding)=false;
GVAR(initholdtime)=0;
GVAR(holding)=false;
GVAR(holdtime) = 0;
GVAR(campos) = [0,0,0];
GVAR(throwdir) = [0,0,0];
GVAR(cookie) = objNull;
GVAR(cookclicktime) = 0;
GVAR(cancelthrow) = false; //for canceling throw during animation


//user settings
GVAR(opt_enabled) = if (getNumber(configFile>>"cfgMagazines">>"HandGrenade">>"maxThrowHoldTime") == 100) then {1} else {0}; //enable grenade throw system
GVAR(opt_invmb) = 0; //inverse left/right mouse buttons
GVAR(opt_velrate) = 0.6;//0.27; //rate of throw speed gain per second when holding LMB (1 means it'll take 1 sec holding to achieve max speed, 0.5 means 2 seconds etc)
GVAR(opt_1clickampl) = 1; //float [0..1], amplitude of 'insta-throw' (1 click, no holding) 
GVAR(opt_startvel) = 0; //[0..1] start throw speed when holding (corresp. to 0 on indicator)
GVAR(opt_cursortype) = 2; //0 - no cursor 1 - standard cursor 2 - grenade icon as a cursor
GVAR(opt_resetmode) = 0; //reset to 'arc throw' after each throw
GVAR(opt_slctprimwpn) = 0; //select main weapon immediately after throwing


FUNC(readsettings) = 
{
	GVAR(opt_velrate) = ["ACE", "sys_grenadethrow", "holding_ampl_gain"] call ace_settings_fnc_getNumber;
	GVAR(opt_1clickampl) = ["ACE", "sys_grenadethrow", "fast_throw_ampl"] call ace_settings_fnc_getNumber;
	GVAR(opt_cursortype) = ["ACE", "sys_grenadethrow", "cursor_type"] call ace_settings_fnc_getNumber;
	GVAR(opt_resetmode) = ["ACE", "sys_grenadethrow", "reset_mode"] call ace_settings_fnc_getNumber;
	GVAR(opt_slctprimwpn) = ["ACE", "sys_grenadethrow", "switch_to_weapon"] call ace_settings_fnc_getNumber;
	GVAR(opt_invmb) = ["ACE", "sys_grenadethrow", "swap_mouse_buttons"] call ace_settings_fnc_getNumber;
};


//[QUOTE(ADDON), "Change_mode", { _this call FUNC(keyPressed)}] call CBA_fnc_addKeyHandlerFromConfig;
//[QUOTE(ADDON), "Throw_speed_down", { [_this, -1] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
//[QUOTE(ADDON), "Throw_speed_up", { [_this, 1] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
//[QUOTE(ADDON), "Throw", { [_this, 0] call FUNC(keypressed) }] call CBA_fnc_addKeyHandlerFromConfig;
//[QUOTE(ADDON), "Throw", {GVAR(holding)=false;if (GVAR(holdtime)<0.3) then {GVAR(speed)=1;GVAR(speed) call FUNC(indicator)}; true },"keyup"] call CBA_fnc_addKeyHandlerFromConfig;
//[QUOTE(ADDON), "release_lever", { _this call FUNC(keypressed_cook) }] call CBA_fnc_addKeyHandlerFromConfig;

GVAR(mkey_add) = 
{
	GVAR(handlerid_mousedown) = (findDisplay 46) displayAddEventHandler ["MouseButtonDown", "0=[_this,0] call ace_sys_grenadethrow_fnc_mkey"];
	GVAR(handlerid_mouseup) = (findDisplay 46) displayAddEventHandler ["MouseButtonUp", "0=[_this,1] call ace_sys_grenadethrow_fnc_mkey"];
};

GVAR(mkey_remove) = 
{
	if (typename GVAR(handlerid_mousedown) == "SCALAR") then
	{
		(findDisplay 46) displayRemoveEventHandler ["MouseButtonDown", GVAR(handlerid_mousedown)];
		(findDisplay 46) displayRemoveEventHandler ["MouseButtonUp", GVAR(handlerid_mouseup)];
	};
};
0 = call GVAR(mkey_remove);
[QGVAR(setposvelremote), 
{
	_this spawn FUNC(applyPosVel);
}] call CBA_fnc_addEventHandler;

/*
[QGVAR(firedremote), 
{
		PARAMS_3(_unit,_ammo,_orig);
		private ["_nade"];
		//if (local _unit) exitwith {};
		_nade = nearestobject [_unit,_ammo];
		//diag_log format ["%1 unit %2 ammo %3 obj %4 orig %5 vel %6 pos %7 dist %8",time,_unit,_ammo,_nade,_orig,velocity _nade,getposASL _nade,_unit distance _nade];
		if (local _unit) exitwith {};
		_orig spawn
		{
			while {alive _this} do
			{
				[QGVAR(trackremote), [(getposASL _this),_this,(getpos _this)]] call CBA_fnc_globalEvent;
				//if (((velocity _this) call ACE_fnc_magnitude) < 0.05) exitwith {};
				sleep 0.1;
			};
		};

}] call CBA_fnc_addEventHandler;

[QGVAR(trackremote), 
{
	if (isServer) exitwith {};
	private ["_b","_pos","_orig","_pos1"];
	_pos = _this select 0;
	_orig = _this select 1;
	_pos1 = _this select 2;
	diag_log format ["%1 pos %2 origpos %4 dist %3 distnades %5",time,_pos,(getposASL player) distance _pos,getposASL _orig,(getposASL _orig) distance _pos];
	//_b = "baseball" createvehicle [0,0,1000];
	//_b setposASL _pos;
	drop ["\ca\data\koulesvetlo","","Billboard",100,120,_pos1,[0,0,0],0,1.275,1,0,[1],[[1,0.1,0.1,0.9]],[0],0,0,"","",""];

}] call CBA_fnc_addEventHandler;

[QGVAR(syncposremote), 
{
	
	(_this select 0) setvelocity [0,0,0];
	(_this select 0) setposASL (_this select 1);
	(_this select 0) setvelocity [0,0,0];
	//diag_log format ["%1 syncing smoke this %2",time,_this];

}] call CBA_fnc_addEventHandler;
*/				

ADDON = true;
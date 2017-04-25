private ["_display", "_playerlist", "_groupcolor", "_othercolor", "_units", "_stru", "_index", "_control", "_targetPos", "_position", "_col"];

if (!local player) exitwith {};

#define IDCPLAYER 5200

if (isNil "BIS_fnc_arrayInsert") then {
	BIS_fnc_arrayInsert = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arrayinsert.sqf";
	BIS_fnc_subSelect = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_subselect.sqf";
	BIS_fnc_arrayPushStack = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arraypushstack.sqf";
	BIS_fnc_arrayPush = compile preprocessFileLineNumbers "\ca\modules\Functions\arrays\fn_arraypush.sqf";
};

disableSerialization;

x_pm_received_ar = [];
x_pm_send_ar = [];
x_pm_add_ar = [];
x_player_name = name player;

if (isNil "x_show_settings") then {x_show_settings = true};

// setup global chat logic
x_global_chat_logic = "Logic" createVehicleLocal [0,0,0];

// display a text message over a global logic chat
// parameters: text (without brackets)
// example: "Hello World!" call XfGlobalChat;
XfGlobalChat = {
	x_global_chat_logic globalChat _this;
};

XSendMsgSysMsg = {
	private ["_xctrl"];
	disableSerialization;
	_xx_display = findDisplay 11001;
	_xctrl = _xx_display displayCtrl 1010;
	if (ctrlText (_xx_display displayCtrl 1201) != "") then {
		if (x_player_name != ctrlText _xctrl) then {
			x_msg_net = [ctrlText _xctrl,x_player_name,ctrlText (_xx_display displayCtrl 1201)];
			publicVariable "x_msg_net";
			("Message sent to: " + ctrlText _xctrl) call XfGlobalChat;
		} else {
			"Message stored" call XfGlobalChat;
		};
		_one_ele = [ctrlText _xctrl, ctrlText (_xx_display displayCtrl 1201), date];
		x_pm_send_ar = [x_pm_send_ar, [_one_ele], 0] call BIS_fnc_arrayInsert;
	} else {
		"NO TEXT TO SEND OR STORE" call XfGlobalChat
	};
};

"x_msg_net" addpublicvariableeventhandler {
	if (x_player_name == (_this select 1) select 0) then {
		x_pm_add_ar set [count x_pm_add_ar, [(_this select 1) select 1, (_this select 1) select 2]];
		playSound "IncomingChallenge";
		(format ["You have received a message from %1.", (_this select 1) select 1]) call XfGlobalChat;
	};
};


d_graslayer_index = 1;
d_viewdistance = viewdistance;

if (x_show_settings) then {
	x_settings_action = player addAction ["Settings", "x_scripts\x_showsettings.sqf",[],-1,false];
	_trigger = createTrigger["EmptyDetector" ,position player];
	_trigger setTriggerArea [0, 0, 0, false];
	_trigger setTriggerActivation ["NONE", "PRESENT", true];
	_trigger setTriggerStatements["vehicle player != player", "x_set_vehicle = vehicle player;x_set_vec_id = x_set_vehicle addAction [""Settings"", ""x_scripts\x_showsettings.sqf"",[],-1,false];", "x_set_vehicle removeAction x_set_vec_id;x_set_vec_id = -1"];
};

5 cutrsc["PlayerNameHud","PLAIN"];

_display = uiNamespace getVariable "X_PHUD";

_playerlist = ["p1","p2","p3","p4","p5","p6","p7","p8","p9","p10","p11","p12","p13","p14","p15","p16","p17","p18","p19","p20",
	"p21","p22","p23","p24","p25","p26","p27","p28","p29","p30","p31","p32","p33","p34","p35","p36","p37","p38","p39","p40",
	"p41","p42","p43","p44","p45","p46","p47","p48","p49","p50"];

_groupcolor = [0.7,0.7,0,1];
_othercolor = [0.2,0.2,1,1];
_heinercolor = [1,0.2,0.6]; // todo: add Heiners uid
_isHeiner = if (getPlayerUID player == "3870210") then {true} else {false};

X_KeyboardHandlerKeyDown = {
	private ["_dikCode", "_handled"];
	_dikCode = _this select 1;
	handled = false;
	if (_dikCode == 57) then {_handled = true}; // space
	_handled
};

// if (isNil "x_show_pname_hud") then {
	// x_show_pname_hud = if (cadetmode) then {false} else {true};
// };
x_show_pname_hud = false;
if (x_show_pname_hud) then {
	d_show_player_namesx = 1;
} else {
	d_show_player_namesx = 0;
};

if (isNil "x_blockspacebar") then {x_blockspacebar = true};
if (x_blockspacebar) then {
	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call X_KeyboardHandlerKeyDown"];
};

while {true} do {
	_units = if (!ismultiplayer) then {switchableunits} else {playableunits};

	if (x_show_pname_hud) then {
		{
			if (_x != player) then {
				if (alive player && alive _x && player distance _x <= 50) then {
					_stru = str(_x);
					_index = _playerlist find _stru;
					if (_index != -1) then {
						_control = _display displayCtrl (IDCPLAYER + _index);
						if (!surfaceiswater (position _x)) then {
							_targetPos = getPosATL _x;
							_targetPos set [ 2 , (_targetPos select 2) + 1.9 ];	// make marker float 1.8m above
						} else {
							_targetPos = getPosASL _x;
							_targetPos set [ 2 , (_targetPos select 2) + 1.2 ];	// make marker float 1.8m above
						};

						_position = worldToScreen _targetPos;

						if( (count _position) != 0 ) then { // this checks player is not out of view
							_control ctrlShow true;
							_control ctrlSetPosition _position;
							private ["_tex"];
							_tex = name _x;
							if (isNil "_tex") then {_tex = "Error"};
							_control ctrlSetText _tex;
							_col = if (_isHeiner) then {_heinercolor} else {if (group _x == group player) then {_groupcolor} else {_othercolor}};
							_control ctrlSetTextColor _col ;
						} else {
							_control ctrlShow false;
						};
						_control ctrlCommit 0;
						waituntil {ctrlCommitted _control};
					};
				} else {
					_stru = str(_x);
					_index = _playerlist find _stru;
					if (_index != -1) then {
						_control = _display displayCtrl (IDCPLAYER + _index);
						_control ctrlShow false;
						_control ctrlCommit 0;
						waituntil {ctrlCommitted _control};
					};
				};
				sleep 0.001;
			};
		} foreach _units;
	};
	sleep 0.001;

	if (!x_show_pname_hud) then {
		_units = if (!ismultiplayer) then {switchableunits} else {playableunits};
		{
			if (_x != player) then {
				_stru = str(_x);
				_index = _playerlist find _stru;
				if (_index != -1) then {
					_control = _display displayCtrl (IDCPLAYER + _index);
					_control ctrlShow false;
					_control ctrlCommit 0;
					waituntil {ctrlCommitted _control};
				};
			};
			sleep 0.01;
		} foreach _units;
		waituntil {x_show_pname_hud};
	};
};

if (true) exitwith {};
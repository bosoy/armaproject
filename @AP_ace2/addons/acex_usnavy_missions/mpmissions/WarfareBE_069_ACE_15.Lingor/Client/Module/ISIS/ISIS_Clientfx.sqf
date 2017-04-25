Private ["_camera","_nu","_ran","_stunned","_unit"];

_unit = _this select 0;

titleCut["","BLACK FADED",0];
titleCut["","BLACK IN",2];

"dynamicBlur" ppEffectEnable true;
"dynamicBlur" ppEffectAdjust [1];
"dynamicBlur" ppEffectCommit 0.1;  

"colorCorrections" ppEffectCommit 0.1;
"colorCorrections" ppEffectEnable true;
"colorCorrections" ppEffectAdjust [1, 1, 0, [0.1, 0.0, 0.0, 0.5], [0, 0.5, 0.5, 0.5], [0.199, 0.187, 0.114, 0.0]];
"colorCorrections" ppEffectCommit 0.3;

_camera = "camera" camCreate (getPos player);

showCinemaBorder true;

_camera camSetDir 0;
_camera camSetFov 0.200;
_camera cameraEffect["Internal","back"];
_camera camSetTarget player;
_camera camSetRelPos [2,2,3];
_camera camCommit 0;

_nu = [_camera] Spawn {
	private ["_camera","_rx","_ry","_rz","_shout","_shoutTrsl","_ran"];
	_camera = _this select 0;
	_shout = ["ImHitE","ImBleedingE","SomebodyHelpMeE","GetMeACorpsmanNowE","CorpsmanE","TheyGotMeE","NeedHelpE","WoundedE"];
	_shoutTrsl = ["I'm hit!","I'm bleeding!","Somebody help me!","Get me a corpsman now!","Corpsman!","They got me!","Need help!","Wounded!"];
	while {true} do {
		_rx = 1 + random 7;
		_ry = 1 + random 7;
		_rz = 1 + random 7;
		
		_camera camSetRelPos [_rx,_ry,_rz];
		_camera camCommit 10;
		waitUntil{camCommitted _camera};
		if (random 100 < 20) then {
			_ran = round(random((count _shout)-1));
			player kbTell [sideHQ, WFBE_V_HQTopicSide, "simple",["1","",(_shoutTrsl select _ran),[(_shout select _ran)]],true];
		};
	};
};

while {true} do {
	sleep 1;
	_stunned = _unit getVariable "stunned";
	if (isNil '_stunned') exitWith {};
	if (!alive _unit || !(_unit getVariable "stunned")) exitWith {};
};

terminate _nu;
showCinemaBorder false;

if (!playerDead) then {
	"dynamicBlur" ppEffectEnable false;
	"colorCorrections" ppEffectEnable false;
	_camera cameraEffect["TERMINATE","BACK"];
	camDestroy _camera;
};
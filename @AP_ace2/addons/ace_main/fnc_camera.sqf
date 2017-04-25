// code provided by Dslyecxi

_v = _this select 0;
if (_v isKindOf "StaticWeapon") exitWith {}; // Not for StaticWeapons

if !(cameraView in ["INTERNAL","GUNNER"]) exitwith {}; // Not when in 3rd person

_u = _this select 2;
if !(alive _u) exitWith {}; // Not when dead
if !(local _u) exitWith {}; // Not when not local

_u spawn {
	if (!isNil{ACE_EjectingBool} && {ACE_EjectingBool}) exitWith {}; // Not when using ejection seat
	_u = _this;
	_bla = _u getVariable ["ace_w_uncon", false];
	if (_bla) exitWith {}; // Not when unconscious

	_sitPos = positionCameraToWorld [0,0,0];
	_lookingAt = positionCameraToWorld [0,0,1];

	_locCam = "CAMERA" camCreate [0,0,0];
	_locCam cameraEffect ["Internal","Back"];
	_locCam camSetTarget _lookingAt;
	_locCam camSetPos _sitPos;
	showCinemaBorder false;
	camUseNVG ace_sys_nvg_on;
	_locCam camSetFOV .7;
	_locCam camCommit 0;

	waitUntil {camCommitted _locCam};

	_newLook = _u modelToWorld [0,5,1];
	_newPos = _u modelToWorld [0,3,1.5]; //_u modelToWorld [0,.2,1.5];

	_locCam camSetTarget _newLook;
	_locCam camSetPos _newPos;
	_locCam camCommit .9;

	waitUntil {camCommitted _locCam};
	_locCam cameraEffect ["TERMINATE","BACK"];
	camDestroy _locCam;
};

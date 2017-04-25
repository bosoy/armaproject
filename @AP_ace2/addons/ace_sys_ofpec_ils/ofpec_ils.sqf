//#define DEBUG_MODE_FULL
#include "script_component.hpp"
/* OFPEC ILS (.pbo) | (c) 2007 by Mandoble */

PARAMS_4(_vehicle,_ilsName,_ilsPosition,_ilsDirection);

private ["_target", "_pos", "_posu", "_disth", "_distv", "_hscreen", "_vscreen", "_sinvscreen", "_angh", "_angv", "_vdir", "_mark", "_dist", "_screen", "_continue", "_alt", "_logic", "_glide", "_i", "_messages", "_logic2", "_logic3", "_ilspos", "_ischopper", "_ils", "_ilsoffact", "_runwayalt", "_landspeed", "_maxspeed", "_speeds", "_blink", "_blinkdir", "_cname", "_lastsoundtime", "_sounds", "_ilsPosition", "_logicMarker", "_pshd", "_lastsoundtimeM", "_alt2", "_distMarker", "_angle"];

if (isNil "OFPEC_MandoWorldToScreen") then {
   OFPEC_MandoWorldToScreen = {
		private["_target", "_vehicle", "_pos", "_posu", "_disth", "_distv", "_hscreen", "_vscreen", "_sinvscreen", "_angh", "_angv", "_vdir"];
		_target = _this select 0;
		_vehicle = _this select 1;
		_pos = _vehicle worldToModel (getPos _target);
		_disth = sqrt((_pos select 0)^2+(_pos select 1)^2);
		_distv = sqrt(((getPosASL _target select 2) - (getPosASL _vehicle select 2))^2+_disth^2);
		if (_disth < 0.1) then { _disth = 0.1; };
		if (_distv < 0.1) then { _distv = 0.1; };
		_sinvscreen = (_pos select 2)/_distv;
		_angh = (_pos select 0) atan2 (_pos select 1);
		_angv = asin(_sinvscreen);
		_hscreen = 0.5 + _angh*0.5/42;
		_vscreen = 0.5 - _angv*0.5/35;
		[_hscreen, _vscreen, _angh, _angv]
	};
};
//#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")
private["_mark", "_dist", "_continue", "_alt", "_logic", "_glide", "_i", "_messages", "_ilsDirection", "_logic", "_logic2", "_logic3", "_ilspos", "__map", "_ischopper", "_ils", "_ilsoffact", "_runwayalt", "_landspeed", "_maxspeed","_speeds", "__speedw", "__altw", "_blink", "_blinkdir", "_cname", "_lastsoundtime", "_sounds"];

//ILSOFFACT = _vehicle addAction [ACE_TEXT_SILVER("I L S OFF"), QPATHTO_F(ofpec_ils_off),[],-999,false,true,""];

_ischopper = false;
_cname = typeOf _vehicle;
while { _cname != "All" } do {
	_cname = configName (inheritsFrom (configFile>> "CfgVehicles" >>_cname));
	if (_cname == "Helicopter") then { _ischopper = true; };
};

if (!_ischopper) then {
	_landspeed = getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "landingSpeed");
	_maxspeed = getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "maxSpeed");
};
GVAR(ils) = true;

cutRsc["ofpec_ils","PLAIN"];
waitUntil { !isNull (uiNameSpace getVariable "ofpec_ils_disp") };

#define __disp (uiNameSpace getVariable "ofpec_ils_disp")
#define __horb (__disp displayCtrl 102)
#define __verb (__disp displayCtrl 103)
#define __aim (__disp displayCtrl 104)
#define __aim2 (__disp displayCtrl 105)
#define __type (__disp displayCtrl 106)
__type ctrlSetBackgroundColor [0,0,0,0];
__type ctrlCommit 0;
#define __range (__disp displayCtrl 107)
__range ctrlSetBackgroundColor [0,0,0,0];
__range ctrlCommit 0;
#define __altc (__disp displayCtrl 108)
__altc ctrlSetBackgroundColor [0,0,0,0];
__altc ctrlCommit 0;
#define __map (__disp displayCtrl 109)
#define __speedw (__disp displayCtrl 111)
#define __altw (__disp displayCtrl 112)

_glide = _ilsDirection select 1;
_ilsPosition = [(_ilsPosition select 0)-(_ilsDirection select 0)*50,(_ilsPosition select 1)-(_ilsDirection select 2)*50, 0];
_logic = "ACE_LogicDummy" createVehicleLocal [_ilsPosition select 0,_ilsPosition select 1, 0];
_logic2 = "ACE_LogicDummy" createVehicleLocal [_ilsPosition select 0,_ilsPosition select 1, 0];
_logic3 = "ACE_LogicDummy" createVehicleLocal [_ilsPosition select 0,_ilsPosition select 1, 0];
_runwayalt = getPosASL _logic select 2;

private["_logicMarker"];
_logicMarker = "ACE_LogicDummy" createVehicleLocal [_ilsPosition select 0,_ilsPosition select 1, 0];
_messages = ["First WP","Second WP","Landing WP"];
_sounds = ["","ofpec_firstwp","ofpec_final_aproach"];
_speeds = [_maxspeed*2/3,_maxspeed/2,_landspeed+_landspeed*1/4];

/*
createMarkerLocal ["ofpec_ils",[0,0]];
"ofpec_ils" setMarkerShapeLocal "RECTANGLE";
"ofpec_ils" setMarkerColorLocal "ColorWhite";
"ofpec_ils" setMarkerSizeLocal [4,100];

createMarkerLocal ["ils_plane",[0,0]];
"ils_plane" setMarkerColorLocal "ColorGreen";
"ils_plane" setMarkerSizeLocal [1,1];
"ils_plane" setMarkerTypeLocal "Arrow";
"ils_plane" setMarkerSizeLocal [0.5,0.5];

createMarkerLocal ["ils_plane2",[0,0]];
"ils_plane2" setMarkerColorLocal "ColorGreen";
"ils_plane2" setMarkerSizeLocal [1,1];
"ils_plane2" setMarkerTypeLocal "Select";
"ils_plane2" setMarkerSizeLocal [0.6,0.6];

createMarkerLocal ["ils_wp",[0,0]];
"ils_wp" setMarkerColorLocal "ColorGreen";
"ils_wp" setMarkerSizeLocal [1,1];
"ils_wp" setMarkerTypeLocal "Arrow";
"ils_wp" setMarkerSizeLocal [0.5,0.5];
*/

_ilspos = [];
_pshd = [(_ilsPosition select 0)+(_ilsDirection select 0)*6000,(_ilsPosition select 1)+(_ilsDirection select 2)*6000, _runwayalt+_glide*6000];
PUSH(_ilspos,_pshd);
_pshd = [(_ilsPosition select 0)+(_ilsDirection select 0)*3000,(_ilsPosition select 1)+(_ilsDirection select 2)*3000, _runwayalt+_glide*3000];
PUSH(_ilspos,_pshd);
_pshd = getPosASL _logic;
PUSH(_ilspos,_pshd);
_pshd = [(_ilsPosition select 0)+(_ilsDirection select 0)*-200,(_ilsPosition select 1)+(_ilsDirection select 2)*-200, _runwayalt];
PUSH(_ilspos,_pshd);

if (!_ischopper) then {
	_ils = 0;
} else {
	_ils = 2;
	__aim ctrlSetTextColor [0, 0.5, 0, 0];
	__aim2 ctrlSetTextColor [0, 0.5, 0, 0];
};

_logic setPosASL (_ilspos select _ils);
_logic2 setPosASL [((_ilspos select _ils) select 0)-(_ilsDirection select 0)*1000,((_ilspos select _ils) select 1)-(_ilsDirection select 2)*1000, ((_ilspos select _ils) select 2)-_glide*1000];

_logic3 setPosASL [((_ilspos select _ils) select 0)+(_ilsDirection select 0)*1000,((_ilspos select _ils) select 1)+(_ilsDirection select 2)*1000, ((_ilspos select _ils) select 2)+_glide*1000];

playSound "ofpec_enabled";
_lastsoundtime = dayTime * 3600;
private["_lastsoundtimeM"];
_lastsoundtimeM = dayTime * 3600;

__type ctrlSetText format["%1: %2", _ilsName, (_messages select _ils)];

_continue = true;
_blink = 0;
_blinkdir = 1;
while { _continue && {(vehicle player == _vehicle)} && {GVAR(ils)} && {((getPos _vehicle select 2)>1)} && {(player == driver _vehicle)} } do {
	__map ctrlMapAnimAdd [0.01, 1, getPos _vehicle];
	ctrlMapAnimCommit __map;

	_alt = getPos _logic select 2;
	_alt = _alt-_alt%1;

	_alt2 = (getPosASL _vehicle select 2) - (getPosASL _logic select 2);
	_alt2 = _alt2-_alt2%1;

	_dist = sqrt(((getPos _logic select 0)-(getPos _vehicle select 0))^2+((getPos _logic select 1)-(getPos _vehicle select 1))^2);
	_dist = _dist-_dist%1;

	private["_distMarker"];
	_distMarker = sqrt(((getPos _logicMarker select 0) - (getPos _vehicle select 0))^2+((getPos _logicMarker select 1) - (getPos _vehicle select 1))^2);
	_distMarker = _distMarker - _distMarker % 1;

	// OUTER MARKER
	if ((dayTime * 3600 - _lastsoundtimeM) > 3.95 && {_distMarker > 2700} && {(_distMarker < 6500)}) then {
		playSound "ofpec_outermarker";
		_lastsoundtimeM = dayTime * 3600;
	};
	// MIDDLE MARKER
	if ((dayTime * 3600 - _lastsoundtimeM) > 2.3 && {_distMarker < 2700} && {(_distMarker > 950)}) then {
		playSound "ofpec_middlemarker";
		_lastsoundtimeM = dayTime * 3600;
	};
	// INNER MARKER
	if ((dayTime * 3600 - _lastsoundtimeM) > 4.3 && {(_distMarker < 950)}) then {
		playSound "ofpec_innermarker";
		_lastsoundtimeM = dayTime * 3600;
	};

	__altc ctrlSetText format["Altitudes: %1 m /%2 m", _alt, _alt2];
	__range ctrlSetText format["Range: %1 m", _dist];

	_angle = ((getPos _logic select 0) - (getPos _vehicle select 0)) atan2 ((getPos _logic select 1) - (getPos vehicle player select 1));

	_screen = [_logic, _vehicle] call OFPEC_MandoWorldToScreen;
	_hscreen = (_screen select 0) - 0.04/2;
	_vscreen = (_screen select 1) - 0.05/2;
	_hscreen = _hscreen min (0.6-0.04);
	_hscreen = _hscreen max (0.4);
	_vscreen = _vscreen min (0.6-0.05);
	_vscreen = _vscreen max (0.4);
	_angh = _screen select 2;
	_angv = _screen select 3;

	__verb ctrlSetTextColor (if (abs(_angh)<10) then {[0, 1, 0, 1]} else {[0, 0.5, 0, 0.5]});
	__horb ctrlSetTextColor (if (abs(_angv) < 10) then {[0, 1, 0, 1]} else {[0, 0.5, 0, 0.5]});

	__horb ctrlSetPosition [0.4, _vscreen];
	__horb ctrlCommit 0;
	__verb ctrlSetPosition [_hscreen, 0.4];
	__verb ctrlCommit 0;

	if (!_ischopper) then {
		if (speed _vehicle > (_speeds select _ils)) then {
			if ((dayTime * 3600 - _lastsoundtime) > 4) then {
				playSound "ofpec_toofast";
				_lastsoundtime = dayTime * 3600;
			};
			__speedw ctrlSetText "Too fast";
		} else {
			if (speed _vehicle < _landspeed) then {
				if ((dayTime * 3600 - _lastsoundtime) > 4) then {
					playSound "ofpec_tooslow";
					_lastsoundtime = dayTime * 3600;
				};

				__speedw ctrlSetText "Too slow";
			} else {
				__speedw ctrlSetText "";
			};
		};

		if ((getPosASL _vehicle select 2) > ((getPosASL _logic3 select 2)+50)) then {
			if ((dayTime * 3600 - _lastsoundtime) > 4) then {
				playSound "ofpec_toohigh";
				_lastsoundtime = dayTime * 3600;
			};

			__altw ctrlSetText "Too high";
		} else {
			if ((getPosASL _vehicle select 2) < (getPosASL _logic select 2)) then {
				if ((dayTime * 3600 - _lastsoundtime) > 4) then {
					playSound "ofpec_toolow";
					_lastsoundtime = dayTime * 3600;
				};

				__altw ctrlSetText "Too low";
			} else {
				__altw ctrlSetText "";
			};
		};

		_screen = [_logic2, _vehicle] call OFPEC_MandoWorldToScreen;
		if (abs (_screen select 2) < 45) then {
			_hscreen = (_screen select 0) - 0.04/2;
			_vscreen = (_screen select 1) - 0.05/2;
			_hscreen = _hscreen min (0.6-0.04);
			_hscreen = _hscreen max (0.4);
			_vscreen = _vscreen min (0.6-0.05);
			_vscreen = _vscreen max (0.4);
			__aim ctrlSetPosition [_hscreen, _vscreen];
			__aim ctrlCommit 0;
			__aim ctrlSetTextColor [0, 0.5, 0, 0.5];
		} else {
			__aim ctrlSetTextColor [0, 0.5, 0, 0];
		};

		_screen = [_logic3, _vehicle] call OFPEC_MandoWorldToScreen;
		if (abs (_screen select 2) < 45) then {
			_hscreen = (_screen select 0) - 0.04/2;
			_vscreen = (_screen select 1) - 0.05/2;
			_hscreen = _hscreen min (0.6-0.04);
			_hscreen = _hscreen max (0.4);
			_vscreen = _vscreen min (0.6-0.05);
			_vscreen = _vscreen max (0.4);
			__aim2 ctrlSetPosition [_hscreen, _vscreen];
			__aim2 ctrlCommit 0;
			__aim2 ctrlSetTextColor [0, 0.5, 0, 0.5];
		} else {
			__aim2 ctrlSetTextColor [0, 0.5, 0, 0];
		};
	};

	if (_dist < 200) then {
		if (_ils < ((count _ilspos)-2)) then {
			_ils = _ils + 1;
			_logic setPosASL (_ilspos select _ils);
			_logic2 setPosASL [((_ilspos select _ils) select 0)-(_ilsDirection select 0)*1000,((_ilspos select _ils) select 1)-(_ilsDirection select 2)*1000, ((_ilspos select _ils) select 2)-_glide*1000];
			_logic3 setPosASL [((_ilspos select _ils) select 0)+(_ilsDirection select 0)*1000,((_ilspos select _ils) select 1)+(_ilsDirection select 2)*1000, ((_ilspos select _ils) select 2)+_glide*1000];


			__type ctrlSetText format["%1: %2", _ilsName, _messages select _ils];
			playSound (_sounds select _ils);
			_lastsoundtime = dayTime * 3600;

			"ils_wp" setMarkerPosLocal getPos _logic;
			"ils_wp" setMarkerDirLocal ((getPos _logic2 select 0) - (getPos _logic select 0)) atan2 ((getPos _logic2 select 1) - (getPos _logic select 1));
		} else {
			_continue = false;
		};
	};

	if (_blink % 20 == 0) then {
		if (_blinkdir == 1) then {
			__speedw ctrlSetTextColor [0, 1, 0, 1];
			__altw ctrlSetTextColor [0, 1, 0, 1];
		} else {
			__speedw ctrlSetTextColor [0, 1, 0, 0];
			__altw ctrlSetTextColor [0, 1, 0, 0];
		};
		_blinkdir = -_blinkdir;
	};

	_blink = _blink+1;
	if (_blink == 2000) then { _blink = 0; };
	Sleep .01;

	if ( _continue && {isNull (uiNameSpace getVariable "ofpec_ils_disp")}) then {
		cutRsc["ofpec_ils", "PLAIN"];
		waitUntil { !isNull (uiNameSpace getVariable "ofpec_ils_disp") };
	};
};

deleteVehicle _logic;
deleteVehicle _logic2;
deleteVehicle _logic3;
deleteVehicle _logicMarker;

//deleteMarkerLocal "ils_plane";
//deleteMarkerLocal "ils_plane2";
//deleteMarkerLocal "ils_wp";
//deleteMarkerLocal "ofpec_ils";

cutText["", "PLAIN"];
GVAR(ils) = false;
playSound "ofpec_clear";
//_vehicle removeAction ILSOFFACT;
//ILSONACT = _vehicle addAction [ACE_TEXT_SILVER("I L S"), QPATHTO_F(ofpec_open_airfieldselector),[],-999,false,true,""];

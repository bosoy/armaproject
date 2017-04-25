// Guidance limits enforcer by zGuba (c) 2009
// Input: [vehicle, type of vehicle, weapon direction]
// Output: [guidance vector [n,n,n], limits exceeded (t/f), weapon direction (string), guidance direction (string)]
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __array getArray(configFile>>"cfgVehicles">>_vType>>QGVAR(limits))
//[-30,5,-15,15]

#define __dsp (uiNamespace getVariable "ACE_Kh29Cursor")
#define __ctrl (__dsp displayCtrl 1)
#define __ctrl2 (__dsp displayCtrl 2)
#define __ctrl3 (__dsp displayCtrl 3)

private 
[
	"_vectorDir","_vectorUp",
	"_vectorM","_worldDirM","_worldUpM",
	"_outputMH","_outputMV","_outputM","_output",
	"_limitArray","_limitS","_limitN","_limitW","_limitE",
	"_limitsHR","_limitsVR",
	"_exceeded","_vectorText","_outputText","_tgt","_pos","_vector",
	"_cursorpos","_xoff","_yoff","_w","_h","_p","_k","_dist","_typeoftgt",
	"_tof","_d","_tof1",
	"_prevtime","_prevshaketime","_scale","_txt","_tti","_mis","_tofarray","_dz"
];

PARAMS_2(_vehicle,_vType);


_limitArray = __array;
_limitS = _limitArray select 0;
_limitN = _limitArray select 1;
_limitW = _limitArray select 2;
_limitE = _limitArray select 3;

[QUOTE(ADDON), "Lase_Kh29_Up", { [(vehicle player),0,0.1] call FUNC(Kh29_keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Lase_Kh29_Down", { [(vehicle player),0,-0.1] call FUNC(Kh29_keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Lase_Kh29_Left", { [(vehicle player),-0.1,0] call FUNC(Kh29_keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Lase_Kh29_Right", { [(vehicle player),0.1,0] call FUNC(Kh29_keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;

13538 cutRsc ["ACE_Kh29Cursor", "PLAIN",0];

_w = 0.08*safezoneH*0.749351;
_h = 0.08*safezoneH;
_xoff = _w/2;
_yoff = _h/2;
__ctrl ctrlsetposition [-10,-10,_w,_h];
__ctrl ctrlsettextcolor [1,1,0,1];
__ctrl ctrlcommit 0;

_p = ctrlposition __ctrl;
_k = 1.5*0.55/(getresolution select 5);
__ctrl2 ctrlsetposition [(_p select 0),(_p select 1)-0.04*SafezoneH,(_p select 2)/_k,0.03*SafezoneH/_k];
__ctrl2 ctrlsetscale _k;
__ctrl2 ctrlsettextcolor [1,1,0,1];
__ctrl2 ctrlcommit 0;

__ctrl3 ctrlsetposition [(_p select 0),(_p select 1)-0.04*SafezoneH,(_p select 2)/_k,0.03*SafezoneH/_k];
__ctrl3 ctrlsetscale _k;
__ctrl3 ctrlsettextcolor [1,1,0,1];
__ctrl3 ctrlcommit 0;

_tgt = _vehicle getVariable QGVAR(laserObject);
_t = getposASL _tgt;
_typeoftgt = typeOf _tgt;
_prevtime = time - 1;
_prevshaketime = time;
_dz = 0.01;
_tof1 = -300;
//_tofarray = [[4,0],[260,1.3],[514,1.9],[767,2.3],[1028,2.7],[1286,3.1],[1539,3.5],[1800,3.9],[2061,4.4],[2315,4.8],[2567,5.3],[2818,5.8],[3074,6.4],[3332,6.9],[3582,7.5],[3835,8.1],[4089,8.7],[4345,9.4],[4599,10.1],[4855,10.8],[5109,11.6],[5362,12.4],[5613,13.2],[5868,14.1],[6120,14.9],[6373,15.9],[6624,16.8],[6877,17.9],[7131,18.9],[7381,20]];
while {!isNil {_vehicle getVariable QGVAR(tracking)} && {alive _tgt} && {alive _vehicle}} do {

	_tgt = _vehicle getVariable QGVAR(laserObject);

	if (time - _prevshaketime > 5) then //need to move target at least once every 10 sec or it is deleted by the engine
	{
		_prevshaketime = time;
		_t = getposASL _tgt;
		_tgt setposASL [_t select 0,_t select 1,(_t select 2)+_dz];
		_dz = -_dz;
	};
	if (time - _prevtime > 0.5) then //limits calculation
	{
		_t = getposASL _tgt;
		_prevtime = time;

		_vectorDir = vectorDir _vehicle;
		_vectorUp = vectorUp _vehicle;
		_pos = getposASL _vehicle;

		//vec from aircraft nose to target, magnitude 1
		_vector = [-(_pos select 0)-4*(_vectordir select 0)+(_t select 0),-(_pos select 1)-4*(_vectordir select 1)+(_t select 1),-(_pos select 2)-4*(_vectordir select 2)+(_t select 2)] call ACE_fnc_unitVector;
		_vectorM = [_vector, _vectorDir, _vectorUp] call FUNC(mat_turnvecdirup);

		_output = _vector;

		_vectorMH = (_vectorM select 0) atan2 (_vectorM select 1);
		_vectorMV = (_vectorM select 2) atan2 1;

		_outputMH = (_vectorMH max _limitW) min _limitE;
		_outputMV = (_vectorMV max _limitS) min _limitN;

		if (_outputMH != _vectorMH || {_outputMV != _vectorMV}) then
		{	// Limitation box is always vertical ATM.  I guess that elipse would be correct but even more restrictive.
			_R = [0,_outputMV,_outputMH] call FUNC(mat_buildRotationMatrix);
			_output = [_vectorDir, _R] call FUNC(mat_applyRotation);
			_vehicle setVariable [QGVAR(tracking),nil];
		};

		_vectorText = format ["%1°H %2°V",round (_vectorMH), round (_vectorMV)];
		_outputText = format ["%1°H %2°V",round (_outputMH), round (_outputMV)];

		//[_output,_exceeded,_outputText,_vectorText]
		hintSilent format [localize "STR_ACE_UA_LASEING_DATA",_outputText];
	};
	_p = getposATL _tgt;
	if (surfaceisWater [_p select 0,_p select 1]) then {_p = getposASL _tgt};
	_p = worldtoscreen _p;
	if (count _p == 2 && {player in _vehicle}) then //maintaining cursor on target
	{
		_scale = 0.1*round(1.8/((call cba_fnc_getfov) select 0));
		
		__ctrl ctrlsetposition [(_p select 0)-_xoff*_scale,(_p select 1)-_yoff*_scale];
		__ctrl ctrlsetscale _scale;
		__ctrl ctrlcommit 0;

		__ctrl2 ctrlsetposition [(_p select 0)-_xoff*_scale,(_p select 1)-_yoff*_scale-0.02*SafezoneH*_scale];
		_txt = (0.1*round((_tgt distance _vehicle)/100));
		_txt = if (_txt mod 1 == 0) then {(str _txt) + ".0"} else {str _txt};
		__ctrl2 ctrlsettext _txt;
		__ctrl2 ctrlsetscale _scale*_k;
		__ctrl2 ctrlcommit 0;

		_mis = _vehicle getVariable QGVAR(curmis);
		if !(isNil "_mis") then  // time till impact
		{
			if !(isNull _mis) then
			{
				_dist = _tgt distance _mis;
				//_spd = ((velocity _mis) call ACE_fnc_magnitude) max 450;
				_d = round ((_vehicle getVariable QGVAR(launchpos)) distance (getpos _mis));
				_tof = 0.1 max (0.1*round (10*(time-(_vehicle getVariable QGVAR(launchtime)))));
				_spd = (_d/_tof) max 420;
				_tti = 0.1*round(10*_dist/_spd);
				_txt = if (_tti mod 1 == 0) then {str _tti + ".0s"} else {str _tti + "s"};
				__ctrl3 ctrlsetposition [(_p select 0)-_xoff*_scale,(_p select 1)+ _yoff*_scale -0.01*SafezoneH*_scale ];
				__ctrl3 ctrlsettext _txt;
				__ctrl3 ctrlsetscale _scale*_k;
				__ctrl3 ctrlcommit 0;
			} else
			{
				_vehicle setVariable [QGVAR(curmis),nil];
				_vehicle setVariable [QGVAR(launchtime),nil];
				__ctrl3 ctrlsettext "";
				__ctrl3 ctrlcommit 0;
			};
		};
	} else
	{
		__ctrl ctrlsetposition [-10,-10];
		__ctrl ctrlcommit 0;
		__ctrl2 ctrlsetposition [-10,-10];
		__ctrl2 ctrlcommit 0;
		__ctrl3 ctrlsetposition [-10,-10];
		__ctrl3 ctrlcommit 0;
	};
	sleep 0.01;
};
hintSilent (localize "STR_ACE_UA_LASEING_OFF");
["ace_sys_missileguidance_lase_kh29_up"] call CBA_fnc_removeKeyHandler;
["ace_sys_missileguidance_lase_kh29_down"] call CBA_fnc_removeKeyHandler;
["ace_sys_missileguidance_lase_kh29_left"] call CBA_fnc_removeKeyHandler;
["ace_sys_missileguidance_lase_kh29_right"] call CBA_fnc_removeKeyHandler;

deletevehicle _tgt;
_vehicle setVariable [QGVAR(laserObject),nil];
_vehicle setVariable [QGVAR(tracking),nil];
if !(isNil {(_vehicle getVariable QGVAR(Kh29_feh))}) then {
	_vehicle removeEventhandler ["fired",_vehicle getVariable QGVAR(Kh29_feh)];
	_vehicle setVariable [QGVAR(Kh29_feh),nil];
};
13538 cutRsc ["Default", "PLAIN",0];
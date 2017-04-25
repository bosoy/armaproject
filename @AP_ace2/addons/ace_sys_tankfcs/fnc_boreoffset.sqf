#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh


private ["_diffV","_signH","_veh","_opt1","_opt","_bore1","_dir","_dirto","_path","_turret","_bore","_dirH","_vec","_cos","_h","_diffH"];
_veh = _this;

if (isNumber(__vehcfg>>"ace_tankfcs_opticsoffsetH")) exitwith {
	_veh setvariable ["ace_tankfcs_boreoffseth",getNumber(__vehcfg>>"ace_tankfcs_opticsoffsetH")];
	//_veh setvariable ["ace_tankfcs_boreoffsetv",getNumber(__vehcfg>>"ace_tankfcs_opticsoffsetV")];
};

//crosshair pos in veh coords
//_opt = _veh worldtomodel (positioncameratoworld [0,0,0]);
//_opt1 = _veh worldtomodel (positioncameratoworld [0,0,0.1]);
//_dir = [_opt,_opt1] call BIS_fnc_vectorDiff;

_path = __vehcfg;
_turret = (player call ace_fnc_unitvehpos) select 1;
{
	_path = _path >> "Turrets";
	_path = _path select _x;

} foreach _turret;

//a point on bore line
_bore = _veh selectionposition (getText(_path >> "gunBeg"));
_bore1 = _veh selectionposition (getText(_path >> "gunEnd"));
_opt = _veh selectionposition (getText(_path >> "memoryPointGunnerOptics"));

_dir = [_bore1,_bore] call BIS_fnc_vectorDiff;

//horiz difference
_dirH = _dir call cba_fnc_vectDir;
_dirto = [_opt,_bore] call BIS_fnc_dirTo;
_dirto = (_dirto - _dirH) call cba_fnc_simplifyAngle;

//turn left or right, dep. on optics pos relative to bore
_signH = if (_dirTo < 180) then {-1} else {1};

_vec = [_opt,_bore] call BIS_fnc_vectorDiff;
_cos = [_dir,_vec] call ace_sys_missileguidance_fnc_mat_cos2DVec;
_H = sqrt((_vec select 0)^2 + (_vec select 1)^2);

_diffH = _signH*_H*sqrt(1-_cos^2);
_diffV = (_opt select 2)-(_bore1 select 2);

_veh setvariable ["ace_tankfcs_boreoffseth",_diffH];
//_veh setvariable ["ace_tankfcs_boreoffsetv",_diffV];

TRACE_4("",_path,(getText(_path >> "memoryPointGunnerOptics")),(getText(_path >> "gunBeg")),(getText(_path >> "gunEnd")));
TRACE_1("",([_opt,_bore,_bore1,_dir,_dirH,_dirto,_vec,_cos,_diffH,_diffV]));

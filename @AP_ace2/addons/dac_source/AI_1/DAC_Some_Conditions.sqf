//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Some_Conditions   //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private ["_run","_marker","_leader","_group","_target","_timestep","_array","_go","_temp","_knowsabout"];

_run = 1;_group = _this select 0;_leader = _this select 1;_go = 0;
_marker = _this select 2;_timestep = _this select 3;_array = [];_temp = DAC_StartDummy;_target = objNull;
_knowsabout = ((DAC_KnowsAbout + 2) - ((skill _leader * 2) + 0.01));

if(format["%1",side _leader] != "CIV") then
{
	if(((getMarkerSize (_marker select 0)) select 0) <= 4) then {_go = 1;_run = 0};
	if(format["%1",_group getVariable "getout_dac"] != "<NULL>") then {if((_group getVariable "getout_dac") == 1) then {_go = 1;_run = 0}};
	if((not alive _leader) && (_go == 0)) then {_go = 1;_run = 20};
	if((_group in DAC_Hit_Groups) && (_go == 0)) then {_go = 1;_run = 17};

	if((!(isNull(_leader findNearestEnemy (position _leader)))) && (_go == 0) && (time > _timestep)) then
	{
		_temp = (_leader findNearestEnemy (position _leader));
		if((alive _temp) && (!(format["%1",behaviour _temp] == "ERROR")) && (format["%1",typeof _temp] != "")) then
		{
			if(({(((_x knowsabout _temp) > _knowsabout) && ((_x distance _temp) < (call compile DAC_Alert_Dist))) && (alive _x)} count units _group) > 0) then
			{
				if(((position (vehicle _temp)) select 2) < 5) then
				{
					_run = 13;_target = _temp;(units _group) commandTarget _target;
				};
			};
		};
	};
};

if(_run != 1) then {_array = [_run,_target]};
_array;
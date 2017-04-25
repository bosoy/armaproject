//////////////////////////////
//    Dynamic-AI-Creator    //
//    Version 3.0 - 2010    //
//--------------------------//
//    DAC_Server_Check      //
//--------------------------//
//    Script by Silola      //
//    silola@freenet.de     //
//////////////////////////////

private ["_val0","_val1","_val2","_val3","_val4","_val5","_sc"];

_val0 = [];_val1 = objNull;_val2 = [];_val3 = 0;_val4 = 0;_val5 = objNull;_sc = [];

waituntil {(DAC_Basic_Value == 1)};
sleep 3;

DAC_Zone_Values = 0;
publicvariable "DAC_Zone_Values";
sleep 1;

while{time > 0} do
{
	{
		if((!(format["%1",call compile _x] == scalar)) && (!(format["%1",call compile _x] == "<NULL-object>")) && (!(format["%1",call compile _x] == "scalar"))) then
		{
			if(!((call compile _x) in DAC_Players)) then
			{
				DAC_Players set [count DAC_Players,call compile _x];
			};
			switch (side (call compile _x)) do
			{
				case "WEST":{if(!((call compile _x) in DAC_West_Units)) then {DAC_West_Units set [count DAC_West_Units,(call compile _x)]}};
				case "EAST":{if(!((call compile _x) in DAC_East_Units)) then {DAC_East_Units set [count DAC_East_Units,(call compile _x)]}};
				case "GUER":{
								if(DAC_Res_Side == 0) then
								{
									if(!((call compile _x) in DAC_West_Units)) then {DAC_West_Units set [count DAC_West_Units,(call compile _x)]}
								}
								else
								{
									if(!((call compile _x) in DAC_East_Units)) then {DAC_East_Units set [count DAC_East_Units,(call compile _x)]}
								};
							};
				Default {};
			};
		};
	}	foreach DAC_STRPlayers;
	sleep 1;
	if(format["%1",DAC_Player_Arti] != "") then
	{
		_val0 = call compile format["%1",DAC_Player_Arti];
		_val1 = _val0 select 0;_val2 = _val0 select 1;_val3 = _val0 select 2;_val4 = _val0 select 3;_val5 = _val0 select 4;
		[_val1,_val2,_val3,_val4] spawn DAC_fCallArti;
		if(!(local player)) then {[7,_val5] spawn DAC_fAIRadio};
		DAC_Player_Arti = "";
	};
	if(format["%1",DAC_Player_SupGroup] != "") then
	{
		_val0 = call compile DAC_Player_SupGroup;
		_val1 = _val0 select 0;_val2 = (group _val1);_val3 = _val0 select 1;
		DAC_Hit_Groups set [count DAC_Hit_Groups,_val2];
		_val2 setVariable ["support_pos", _val3, true];
		[_val1,_val2,_val3] spawn DAC_fCallHelp;
		DAC_Player_SupGroup = "";
	};
};
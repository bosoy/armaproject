/*
  CONFIG.CPP 

  
Taken and adapted from ArmA Group Link II Plus! script by SNKMAN.

********************************************************************************************************************************
Start config.cpp
*/

class CfgSounds
{
	sounds[] = 
	{
		Brian_Im_hit, Brian_Im_bleeding,Brian_Medic,Brian_Bastards,Brian_Shit_Man_down,Brian_Oh_no,
		Brian_Fuck,Brian_Fuck_it,Brian_Shit,Brian_Need_help,Brian_A_little_help_here
	};

	class Brian_Im_hit
	{
		name="Brian_Im_hit";
		sound[]={"revive_sqf\sound\UNIV_v05.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Im_bleeding
	{
		name="Brian_Im_bleeding";
		sound[]={"revive_sqf\sound\UNIV_v06.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Medic
	{
		name="Brian_Medic";
		sound[]={"revive_sqf\sound\UNIV_v07.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Bastards
	{
		name="Brian_Bastards";
	        sound[]={"revive_sqf\sound\UNIV_v10.ogg",0.05,1.0};
	        titles[]={};
	};
	class Brian_Shit_Man_down
	{
		name="Brian_Shit_Man_down";
	        sound[]={"revive_sqf\sound\UNIV_v11.ogg",0.05,1.0};
	        titles[]={};
	};
	class Brian_Oh_no
	{
		name="Brian_Oh_no";
		sound[]={"revive_sqf\sound\UNIV_v18.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Fuck
	{
		name="Brian_Fuck";
		sound[]={"revive_sqf\sound\UNIV_v24.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Fuck_it
	{
		name="Brian_Fuck_it";
		sound[]={"revive_sqf\sound\UNIV_v25.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Shit
	{
		name="Brian_Shit";
		sound[]={"revive_sqf\sound\UNIV_v31.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_Need_help
	{
		name="Brian_Need_help";
		sound[]={"revive_sqf\sound\UNIV_v50.ogg",0.05,1.0};
		titles[]={};
	};
	class Brian_A_little_help_here
	{
		name="Brian_A_little_help_here";
		sound[]={"revive_sqf\sound\UNIV_v51.ogg",0.05,1.0};
		titles[]={};
	};
	class LDL_gun01
{
	name = "LDL_gun01";
	sound[] = {\LDL_ac130\Sounds\gun01.ogg, db+3, 1.0};
	titles[]= {}; 
};
		
class LDL_gun02
{
	name = "LDL_gun02";
	sound[] = {\LDL_ac130\Sounds\gun02.ogg, db+3, 1.0};
	titles[]= {}; 
};
		
class LDL_gun03
{
	name = "LDL_gun03";
	sound[] = {\LDL_ac130\Sounds\gun03.ogg, db+5, 1.0};
	titles[]= {}; 
};
			
class LDL_reload
{
	name = "LDL_reload";
	sound[] = {\LDL_ac130\Sounds\reload.ogg, db+5, 1.0};
	titles[]= {}; 
};
	
class LDL_Amb01
{
	name = "LDL_Amb01";
	sound[] = {\LDL_ac130\Sounds\Amb01.ogg, db+2, 1.0};
	titles[]= {}; 
};
	
class LDL_Amb02
{
	name = "LDL_Amb02";
	sound[] = {\LDL_ac130\Sounds\Amb02.ogg, db+2, 1.0};
	titles[]= {}; 
};
	
class LDL_Amb03
{
	name = "LDL_Amb03";
	sound[] = {\LDL_ac130\Sounds\Amb03.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb04
{
	name = "LDL_Amb04";
	sound[] = {\LDL_ac130\Sounds\Amb04.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb05
{
	name = "LDL_Amb05";
	sound[] = {\LDL_ac130\Sounds\Amb05.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb06
{
	name = "LDL_Amb06";
	sound[] = {\LDL_ac130\Sounds\Amb06.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb07
{
	name = "LDL_Amb07";
	sound[] = {\LDL_ac130\Sounds\Amb07.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb08
{
	name = "LDL_Amb08";
	sound[] = {\LDL_ac130\Sounds\Amb08.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb09
{
	name = "LDL_Amb09";
	sound[] = {\LDL_ac130\Sounds\Amb09.ogg, db+2, 1.0};
	titles[]= {}; 
};
		
class LDL_Amb10
{
	name = "LDL_Amb10";
	sound[] = {\LDL_ac130\Sounds\Amb10.ogg, db+2, 1.0};
	titles[]= {}; 
};

class LDL_beep_short
{
	name = "LDL_beep_short";
	sound[] = {\LDL_ac130\Sounds\beep_short.ogg, db+0, 1.0};
	titles[]= {}; 
};

class LDL_beep_long
{
	name = "LDL_beep_long";
	sound[] = {\LDL_ac130\Sounds\beep_long.ogg, db+0, 1.0};
	titles[]= {}; 
};
};
/*	LDL_init.sqf for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

LDL_initDone = false;

//ARMA2
/*
if (!(isClass (configfile >> "cfgpatches" >> "Chernarus"))) exitWith 
{
	hintc "You need ARMA2 to run AC130 Script!";
	LDL_initDone = true;
};
*/

//Operation Arrowhead
if (isClass (configfile >> "cfgpatches" >> "ca_E")) then 
{
	//Use OA FLIR	
	LDL_OAH_setCamUseTi = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_setCamUseTi.sqf";
};

//Addon
if (!(isClass(configFile>>"CfgPatches">>"LDL_ac130"))) then 
{
	//ARMA2 Weapons
	LDL_ammo = ["G_30mm_HE","Sh_120_SABOT","Sh_120_HE"];	
}
else
{
	//LDL Weapons
	LDL_ammo = ["LDL_25mm","LDL_40mm","LDL_105mm"];		
};

//Create some necessary objects
LDL_gunPosition = (createGroup (createCenter sideLogic)) createUnit ["LOGIC",[0,0,0],[],0,""];
LDL_cam_rotating_center = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0,0,0], [], 0, ""];
LDL_destination = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0, 0, 0], [], 0, ""];
LDL_ac130_cam_target = (createGroup (createCenter sideLogic)) createUnit ["LOGIC", [0, 0, 0], [], 0, ""];

//Misc
LDL_ac130_client = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_client.sqf";
LDL_ac130_functions = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_functions.sqf";
LDL_mando_angles = compile preprocessFileLineNumbers "LDL_ac130\Misc\mando_angles.sqf";
LDL_setPitchBank = compile preprocessFileLineNumbers "LDL_ac130\Misc\setPitchBank.sqf";
LDL_float = compile preprocessFileLineNumbers "LDL_ac130\Misc\float.sqf";
LDL_ac130_createDialog = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_createDialog.sqf";
LDL_ac130_createMap = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_createMap.sqf";
LDL_calculateBullet = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_calculateBullet.sqf";
LDL_ac130_correctAxis = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_correctAxis.sqf";
LDL_ac130_warning = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_warning.sqf";
LDL_ac130_delay = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_delay.sqf";
LDL_ac130_createPlane = compile preprocessFileLineNumbers "LDL_ac130\Misc\ac130_createPlane.sqf";

//AC130 Core
LDL_ac130_rot_camera = compile preprocessFileLineNumbers "LDL_ac130\ac130_rot_camera.sqf";
LDL_ac130_rot_camera_opt = compile preprocessFileLineNumbers "LDL_ac130\ac130_rot_camera_opt.sqf";
LDL_ac130_rot_main = compile preprocessFileLineNumbers "LDL_ac130\ac130_rot_main.sqf";
LDL_ac130_att_camera = compile preprocessFileLineNumbers "LDL_ac130\ac130_att_camera.sqf";
LDL_ac130_att_main = compile preprocessFileLineNumbers "LDL_ac130\ac130_att_main.sqf";
LDL_ac130_AI_main = compile preprocessFileLineNumbers "LDL_ac130\ac130_AI_main.sqf";
LDL_uav_rot_main = compile preprocessFileLineNumbers "LDL_ac130\uav_rot_main.sqf";

//AC130
LDL_ac130_rot_waypoints = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_rot_waypoints.sqf";
LDL_ac130_rot_float = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_rot_float.sqf";
LDL_ac130_HUD = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_HUD.sqf";
LDL_ac130_AI_shooting = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_AI_shooting.sqf";
LDL_ac130_guns = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_guns.sqf";
LDL_ac130_blink = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_blink.sqf";
LDL_ac130_troops = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_troops.sqf";
LDL_ac130_sound = compile preprocessFileLineNumbers "LDL_ac130\AC130\ac130_sound.sqf";

//UAV
LDL_uav_createDialog = compile preprocessFileLineNumbers "LDL_ac130\UAV\uav_createDialog.sqf";
LDL_uav_guns = compile preprocessFileLineNumbers "LDL_ac130\UAV\uav_guns.sqf";
LDL_uav_HUD = compile preprocessFileLineNumbers "LDL_ac130\UAV\uav_HUD.sqf";

//Setups
LDL_ac130_rot_setup = compile preprocessFileLineNumbers "LDL_ac130\Setups\ac130_rot_setup.sqf";
LDL_ac130_att_setup = compile preprocessFileLineNumbers "LDL_ac130\Setups\ac130_att_setup.sqf";
LDL_ac130_AI_setup = compile preprocessFileLineNumbers "LDL_ac130\Setups\ac130_AI_setup.sqf";
LDL_uav_rot_setup = compile preprocessFileLineNumbers "LDL_ac130\Setups\uav_rot_setup.sqf";

//Camera
LDL_camera_approach = compile preprocessFileLineNumbers "LDL_ac130\Camera\camera_approach.sqf";
LDL_camera = compile preprocessFileLineNumbers "LDL_ac130\Camera\camera.sqf";

//Spawn Client script and call functions
[]spawn LDL_ac130_client;
[]call LDL_ac130_functions;

LDL_showParticles = true; //Every client will see the particles
LDL_ac130_active = false; //Necessary
player setVariable ["LDL_Mapclicks", 0, true]; //Necessary
LDL_AI_targets = []; //Necessary

//Options for the AC130. Don't change them here. Overwrite them in another script.
LDL_options =
[
	1000,  //0:  Default radius for the rotating AC130. Default: 1000
	1000,  //1:  Default height for the rotating AC130. Default: 1000
	1000,  //2:  Munition for the 25mm. Default: 1000
	50,    //3:  Munition for the 40mm. Default: 50
	20,    //4:  Munition for the 105mm. Default: 20
	true,  //5:  Show Infantry Strobes at startup. Default: true
	false, //6:  Show Vehicle Detection at startup. Default: false
	false, //7:  Activate 360° view. Default: false
	false, //8:  Show waypoints for rotating AC130. Default: false
	true,  //9:  Show particles (smoke, tracer etc.); Default: true
	9.5,   //10: Maximum zoom level for the 25mm. Default: 9.5 (only numbers between 1 and 10)
	9,     //11: Maximum zoom level for the 40mm. Default: 9 (only numbers between 1 and 10)
	8,     //12: Maximum zoom level for the 105mm. Default: 8 (only numbers between 1 and 10)
	-1,    //13: Time in seconds when AC130 script stops. Default: -1 (infinite)
	180,   //14: Time in seconds the AI controlled AC130 stays in the air. Default: 180
	true,  //15: Disable Vehicle Detection (Enemy and friendly units). Default: true
	false, //16: Disable Infantry Strobes. Default: false
	false, //17: Disable Monitor. Default: false
	false, //18: Disable third-person view. Default: false
	1,     //19: Camera effect at startup: 1 (Nothing), 2 (FLIR white), 3 (FLIR black), 4 (NVG). Default: 1
	120,   //20: Delay for mapclick AC130 to arrive. Default: 120
	true,  //21: Sequence at startup. Default: true
	3,	 //22: Available AC130 mapclicks per player. Default: 3
	false, //23: Disable Sounds. Default: false
	false  //24: Enable Optical Zoom. Default: false !BETA only available for rotating AC130 BETA!
];

//Initialisation of PVEH
"LDL_PublicLDLCannon25Sound" addPublicVariableEventHandler
{
	_soundSource = _this select 1;
	_soundSource say format ["LDL_gun01"];
};
"LDL_PublicLDLCannon40Sound" addPublicVariableEventHandler
{
	_soundSource = _this select 1;
	_soundSource say format ["LDL_gun02"];
};
"LDL_PublicLDLCannon105Sound" addPublicVariableEventHandler
{
	_soundSource = _this select 1;
	_soundSource say format ["LDL_gun03"];
};

"LDL_PublicLDLCannon25FX" addPublicVariableEventHandler
{
	_shell = (_this select 1) select 0;
	_vel = (_this select 1) select 1;
	_weapon = (_this select 1) select 2;
	_position = (_this select 1) select 3;
	
};
"LDL_PublicLDLCannon40FX" addPublicVariableEventHandler
{
	_shell = (_this select 1) select 0;
	_vel = (_this select 1) select 1;
	_weapon = (_this select 1) select 2;
	_position = (_this select 1) select 3;
	
};
"LDL_PublicLDLCannon105FX" addPublicVariableEventHandler
{
	_shell = (_this select 1) select 0;
	_vel = (_this select 1) select 1;
	_weapon = (_this select 1) select 2;
	_position = (_this select 1) select 3;
	
};

//Init done
LDL_initDone = true;
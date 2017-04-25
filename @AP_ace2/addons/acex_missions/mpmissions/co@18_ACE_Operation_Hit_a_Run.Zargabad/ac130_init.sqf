//*****************************************//
/*	init.sqf by LurchiDerLurch for AC130-Script
*	@author: LurchiDerLurch
*	@param: nothing
*	@return: nothing
*	@description: 
*/

//Check for Addon
if (!(isClass(configFile>>"CfgPatches">>"LDL_ac130"))) then 
{
	//No Addon detected
	//Spawn LDL_init
	LDL_init = compile preprocessFileLineNumbers "LDL_ac130\LDL_init.sqf";
	[]spawn LDL_init;
}
else
{
	//Addon detected.
	//LDL_init = compile preprocessFileLineNumbers "LDL_ac130\LDL_init.sqf";
	//[]spawn LDL_init;
};

//Wait for the init
waitUntil {!isNil "LDL_initDone"};
waitUntil {LDL_initDone};

//*****************************************//

//Options for the AC-130 (optional)
LDL_options =
[
	1000,  //0:  Default radius for the rotating AC130. Default: 1000
	500,  //1:  Default height for the rotating AC130. Default: 700
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
	90,   //14: Time in seconds the AI controlled AC130 stays in the air. Default: 180
	true,  //15: Disable Vehicle Detection (Enemy and friendly units). Default: true
	false, //16: Disable Infantry Strobes. Default: false
	false, //17: Disable Monitor. Default: false
	false, //18: Disable third-person view. Default: false
	1,     //19: Camera effect at startup: 1 (Nothing), 2 (FLIR white), 3 (FLIR black), 4 (NVG). Default: 1
	0,     //20: Delay for mapclick AC130 to arrive. Default: 120
	true,  //21: Sequence at startup. Default: true
	3,	 //22: Available AC130 mapclicks per player. Default: 3
	false, //23: Disable Sounds. Default: false
	false	 //24: Enable Optical Zoom. Default: false !BETA only available for rotating AC130 BETA!
];

/*
2.2 Necessary work in the editor

2.2.1 To convert a C-130J to an AC-130 put the following line into the init-line of the plane 

	this setVariable ["LDL_planeInUse", false, true];

2.2.2 To give certain object actions put the following codes into the init-line of the object

	Type 1: Ability to call rotating AC130 via mapclick

	this addAction ["Call AC130", "LDL_ac130\Actions\ac130_action_map.sqf"];
	
	Type 2: Ability to call AI controlled rotating AC130 via mapclick

	this addAction ["Call AC130 (AI)", "LDL_ac130\Actions\ac130_action_map_AI.sqf"];
	
	Type 3: Ability to call rotating UAV via mapclick

	this addAction ["Call UAV", "LDL_ac130\Actions\uav_action_map.sqf"];

2.3 Run and control the AC130 Script via scripting

Note: You must execute the codes via script. Either directly in the init.sqf or in an extern *.sqf file. 
	
2.3.1 Call AC130

	Type 1: Create rotating AC130 / Let existing AC130 rotate

	//[POSITION/OBJECT, RADIUS, HEIGHT, SEQUENCE, DELAY]call LDL_ac130_rot_setup;
	f.e: 
	[getPos player,LDL_options select 0,LDL_options select 1,LDL_options select 21, LDL_options select 20]call LDL_ac130_rot_setup;
	
	Type 2: Attach camera to an existing AC130

	//[OBJECT, RADIUS]call LDL_ac130_att_setup;
	f.e:
	[PLANE,LDL_options select 0]call LDL_ac130_att_setup;
	
	Type 3: Create AI controlled rotating AC130 / Let existing AC130 rotate AI controlled

	//[POSITION/OBJECT, RADIUS, HEIGHT, TIME, DELAY]call LDL_ac130_AI_setup;
	f.e:
	[getPos player,LDL_options select 0,LDL_options select 1,LDL_options select 14, LDL_options select 20]call LDL_ac130_AI_setup;
	
	Type 4: Create rotating UAV / Let existing UAV rotate

	//[POSITION/OBJECT, RADIUS, HEIGHT, SEQUENCE, DELAY]call LDL_uav_rot_setup;
	f.e:
	[getPos player,LDL_options select 0,LDL_options select 1,LDL_options select 21, LDL_options select 20]call LDL_uav_rot_setup;

Note: POSITION: Array ([0,0,0]); OBJECT: object; RADIUS: Number; HEIGHT: Number; SEQUENCE: boolean (true or false); DELAY: Number

2.3.2 Let AI controlled AC130 attack specific targets

	LDL_AI_ceaseFire = true; //AC-130 stops aiming targets automatically
	LDL_AI_targets = [target1, target2, target3]; //Every target must be an object
	
2.4.3 Abort AC130 Script

	LDL_ac130_abort = true;
	waitUntil{(!LDL_ac130_active)};
	
2.4.4 Check if client uses the LDL_AC130 AddOn

	if (!(isClass(configFile>>"CfgPatches">>"LDL_ac130"))) then 
	{
		//No Addon detected
	}
	else
	{
		//Addon detected
	};
	
2.4.5 LDL_options

Note: Ensure that the lines are executet after the LDL_init. Otherwise the script will use the default values.

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
		true,  //9: Show particles (smoke, tracer etc.); Default: true
		9.5,   //10: Maximum zoom level for the 25mm. Default: 9.5 (only numbers between 1 and 10)
		9,     //11: Maximum zoom level for the 40mm. Default: 9 (only numbers between 1 and 10)
		8,     //12: Maximum zoom level for the 105mm. Default: 8 (only numbers between 1 and 10)
		-1,    //13: Time in seconds when AC130 script stops. Default: -1 (infinite)
		180,    //14: Time in seconds the AI controlled AC130 stays in the air. Default: 180
		true,  //15: Disable Vehicle Detection (Enemy and friendly units). Default: true
		false, //16: Disable Infantry Strobes. Default: false
		false, //17: Disable Monitor. Default: false
		false, //18: Disable third-person view. Default: false
		4,     //19: Camera effect at startup: 1 (Nothing), 2 (FLIR white), 3 (FLIR black), 4 (NVG). Default: 1
		0,     //20: Delay for mapclick AC130 to arrive. Default: 180
		true,  //21: Sequence at startup. Default: true
		3,	 //22: Available AC130 mapclicks per player. Default: 3
		false, //23: Disable Sounds. Default: false
		false	 //24: Enable Optical Zoom. Default: false !BETA only available for rotating AC130 BETA!
	];			
*/
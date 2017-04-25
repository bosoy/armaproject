////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu May 09 00:18:21 2013 : Created on Thu May 09 00:18:21 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_common : config.bin{
class CfgPatches
{
	class cba_common
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_XEH"};
		version = "1.0.0.190";
		author[] = {"Spooner","Sickboy","Rocko"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_common
	{
		init = "call ('\x\cba\addons\common\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\cba\addons\common\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class cba_common
	{
		init = "call ('\x\cba\addons\common\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Misc
		{
			class actionArgument
			{
				description = "Used to call the code parsed in the addaction argument.";
				file = "\x\cba\addons\common\fnc_actionArgument.sqf";
			};
			class addMagazine
			{
				description = "Add magazine to a vehicle/unit.";
				file = "\x\cba\addons\common\fnc_addMagazine.sqf";
			};
			class addMagazineCargo
			{
				description = "Add magazine(s) to a vehicle's cargo.";
				file = "\x\cba\addons\common\fnc_addMagazineCargo.sqf";
			};
			class addMagazineCargoGlobal
			{
				description = "Add magazine(s) to a vehicle's cargo. MP synchronized.";
				file = "\x\cba\addons\common\fnc_addMagazineCargoGlobal.sqf";
			};
			class addMagazineVerified
			{
				description = "Add magazines to the unit, but verify that it was successful and doesn't over-burden the recipient.";
				file = "\x\cba\addons\common\fnc_addMagazineVerified.sqf";
			};
			class addPerFrameHandler
			{
				description = "Add a handler that will execute every frame, or every x number of seconds";
				file = "\x\cba\addons\common\fnc_addPerFrameHandler.sqf";
			};
			class addPlayerAction
			{
				description = "Adds persistent action to player (which will also be available in vehicles and after respawn or teamswitch).";
				file = "\x\cba\addons\common\fnc_addPlayerAction.sqf";
			};
			class addWeapon
			{
				description = "Add a weapon to a unit.";
				file = "\x\cba\addons\common\fnc_addWeapon.sqf";
			};
			class addWeaponCargo
			{
				description = "Add weapon(s) to vehicle cargo.";
				file = "\x\cba\addons\common\fnc_addWeaponCargo.sqf";
			};
			class addWeaponCargoGlobal
			{
				description = "Add weapon(s) to vehicle cargo. MP synchronized.";
				file = "\x\cba\addons\common\fnc_addWeaponCargoGlobal.sqf";
			};
			class createCenter
			{
				description = "Selects center if it already exists, creates it if it doesn't yet.";
				file = "\x\cba\addons\common\fnc_createCenter.sqf";
			};
			class createMarker
			{
				description = "Creates a marker all at once.";
				file = "\x\cba\addons\common\fnc_createMarker.sqf";
			};
			class createTrigger
			{
				description = "Create a trigger all at once.";
				file = "\x\cba\addons\common\fnc_createTrigger.sqf";
			};
			class defaultParam
			{
				description = "Gets a value from parameters list (usually _this) with a default.";
				file = "\x\cba\addons\common\fnc_defaultParam.sqf";
			};
			class deleteEntity
			{
				description = "A function used to delete entities";
				file = "\x\cba\addons\common\fnc_deleteEntity.sqf";
			};
			class determineMuzzles
			{
				description = "Gets the list of possible muzzles for a weapon.";
				file = "\x\cba\addons\common\fnc_determineMuzzles.sqf";
			};
			class dropMagazine
			{
				description = "Drop a magazine.";
				file = "\x\cba\addons\common\fnc_dropMagazine.sqf";
			};
			class dropWeapon
			{
				description = "Drops a weapon.";
				file = "\x\cba\addons\common\fnc_dropWeapon.sqf";
			};
			class findEntity
			{
				description = "A function used to find out the first entity of parsed type in a nearEntitys call";
				file = "\x\cba\addons\common\fnc_findEntity.sqf";
			};
			class getAlive
			{
				description = "A function used to find out who is alive in an array or a group.";
				file = "\x\cba\addons\common\fnc_getAlive.sqf";
			};
			class getAnimType
			{
				description = "Used to determine which weapon unit is currently holding and return proper animation type.";
				file = "\x\cba\addons\common\fnc_getAnimType.sqf";
			};
			class getArg
			{
				description = "Get default named argument from list.";
				file = "\x\cba\addons\common\fnc_getArg.sqf";
			};
			class getAspectRatio
			{
				description = "Used to determine the Aspect ratio of the screen.";
				file = "\x\cba\addons\common\fnc_getAspectRatio.sqf";
			};
			class getConfigEntry
			{
				description = "Gets a configuration entry.";
				file = "\x\cba\addons\common\fnc_getConfigEntry.sqf";
			};
			class getDistance
			{
				description = "A function used to find out the distance between two positions.";
				file = "\x\cba\addons\common\fnc_getDistance.sqf";
			};
			class getFirer
			{
				description = "A function used to find out which unit exactly fired (Replacement for gunner, on multi-turret vehicles).";
				file = "\x\cba\addons\common\fnc_getFirer.sqf";
			};
			class getFov
			{
				description = "Get current camera's field of view in radians and zoom.";
				file = "\x\cba\addons\common\fnc_getFov.sqf";
			};
			class getGroup
			{
				description = "A function used to find out the group of an object.";
				file = "\x\cba\addons\common\fnc_getGroup.sqf";
			};
			class getGroupIndex
			{
				description = "Finds out the actual ID number of a person within his group as assigned by the game and used in the squad leader's command menu.";
				file = "\x\cba\addons\common\fnc_getGroupIndex.sqf";
			};
			class getNearest
			{
				description = "A function used to find out the nearest entity parsed in an array to a position. Compares the distance between entity's in the parsed array.";
				file = "\x\cba\addons\common\fnc_getNearest.sqf";
			};
			class getNearestBuilding
			{
				description = "A function used to find out the nearest building and appropriate building positions available.";
				file = "\x\cba\addons\common\fnc_getNearestBuilding.sqf";
			};
			class getPistol
			{
				description = "Returns name of pistol in unit's inventory, if any.";
				file = "\x\cba\addons\common\fnc_getPistol.sqf";
			};
			class getPos
			{
				description = "A function used to get the position of an entity.";
				file = "\x\cba\addons\common\fnc_getPos.sqf";
			};
			class getSharedGroup
			{
				description = "Returns existing group on side, or newly created group when not existent.";
				file = "\x\cba\addons\common\fnc_getSharedGroup.sqf";
			};
			class getTerrainProfile
			{
				description = "A function used to find the terrain profile between two positions";
				file = "\x\cba\addons\common\fnc_getTerrainProfile.sqf";
			};
			class getTurret
			{
				description = "A function used to find out which config turret is turretpath.";
				file = "\x\cba\addons\common\fnc_getTurret.sqf";
			};
			class getUISize
			{
				description = "Used to determine the UI size of the screen.";
				file = "\x\cba\addons\common\fnc_getUISize.sqf";
			};
			class getUnitAnim
			{
				description = "Get information about a unit's stance and speed.";
				file = "\x\cba\addons\common\fnc_getUnitAnim.sqf";
			};
			class getUnitDeathAnim
			{
				description = "Get death animation for a unit.";
				file = "\x\cba\addons\common\fnc_getUnitDeathAnim.sqf";
			};
			class getVolume
			{
				description = "Return the volume of an object based on the object's model's bounding box.";
				file = "\x\cba\addons\common\fnc_getVolume.sqf";
			};
			class headDir
			{
				description = "Get the direction of a unit's head.";
				file = "\x\cba\addons\common\fnc_headDir.sqf";
			};
			class inArea
			{
				description = "A function used to determine if a position is within a zone.";
				file = "\x\cba\addons\common\fnc_inArea.sqf";
			};
			class inheritsFrom
			{
				description = "Checks whether a config entry inherits, directly or indirectly, from another one.";
				file = "\x\cba\addons\common\fnc_inheritsFrom.sqf";
			};
			class intToString
			{
				description = "Faster int to string, uses an integer lookup table if possible";
				file = "\x\cba\addons\common\fnc_intToString.sqf";
			};
			class isAlive
			{
				description = "A function used to find out if the group or object is alive.";
				file = "\x\cba\addons\common\fnc_isAlive.sqf";
			};
			class isTurnedOut
			{
				description = "Checks whether a unit is turned out in a vehicle or not.";
				file = "\x\cba\addons\common\fnc_isTurnedOut.sqf";
			};
			class isUnitGetOutAnim
			{
				description = "Checks whether a unit is turned out in a vehicle or not.";
				file = "\x\cba\addons\common\fnc_isUnitGetOutAnim.sqf";
			};
			class locked
			{
				description = "A2/OA/TOH compatible locked function.";
				file = "\x\cba\addons\common\fnc_locked.sqf";
			};
			class mapDirTo
			{
				description = "Gets the direction between two map grid references.";
				file = "\x\cba\addons\common\fnc_mapDirTo.sqf";
			};
			class mapGridToPos
			{
				description = "Converts a 2, 4, 6, 8, or 10 digit grid reference into a Position.";
				file = "\x\cba\addons\common\fnc_mapGridToPos.sqf";
			};
			class mapRelPos
			{
				description = "Find a position relative to a known position on the map. Passing strings in for the Northing and Easting is the preferred way.";
				file = "\x\cba\addons\common\fnc_mapRelPos.sqf";
			};
			class modelHeadDir
			{
				description = "Get the direction of any unit's head.";
				file = "\x\cba\addons\common\fnc_modelHeadDir.sqf";
			};
			class nearPlayer
			{
				description = "Check whether these are any players within a certain distance of a unit.";
				file = "\x\cba\addons\common\fnc_nearPlayer.sqf";
			};
			class northingReversed
			{
				description = "Checks if the maps northing is reversed (like Chernarus & Utes, or any map pre-OA)";
				file = "\x\cba\addons\common\fnc_northingReversed.sqf";
			};
			class objectRandom
			{
				description = "Creates a ""random"" number 0-9 based on an object's velocity";
				file = "\x\cba\addons\common\fnc_objectRandom.sqf";
			};
			class parseYAML
			{
				description = "Parses a YAML file into a nested array/Hash structure.";
				file = "\x\cba\addons\common\fnc_parseYAML.sqf";
			};
			class players
			{
				description = "Get a list of current player objects.";
				file = "\x\cba\addons\common\fnc_players.sqf";
			};
			class randPos
			{
				description = "A function used to randomize a position around a given center";
				file = "\x\cba\addons\common\fnc_randPos.sqf";
			};
			class realHeight
			{
				description = "Real z coordinate of an object, for placing stuff on roofs, etc.";
				file = "\x\cba\addons\common\fnc_realHeight.sqf";
			};
			class removeMagazine
			{
				description = "Remove a magazine.";
				file = "\x\cba\addons\common\fnc_removeMagazine.sqf";
			};
			class removeMagazineCargo
			{
				description = "Function to remove specific items from local cargo space.";
				file = "\x\cba\addons\common\fnc_removeMagazineCargo.sqf";
			};
			class removeMagazineCargoGlobal
			{
				description = "Function to remove specific items from global cargo space. MP synchronized.";
				file = "\x\cba\addons\common\fnc_removeMagazineCargoGlobal.sqf";
			};
			class removePerFrameHandler
			{
				description = "Remove a handler that you have added using CBA_fnc_addPerFrameHandler";
				file = "\x\cba\addons\common\fnc_removePerFrameHandler.sqf";
			};
			class removePlayerAction
			{
				description = "Removes player action previously added with <CBA_fnc_addPlayerAction>.";
				file = "\x\cba\addons\common\fnc_removePlayerAction.sqf";
			};
			class removeWeapon
			{
				description = "Remove a weapon.";
				file = "\x\cba\addons\common\fnc_removeWeapon.sqf";
			};
			class removeWeaponCargo
			{
				description = "Function to remove specific items from local cargo space.";
				file = "\x\cba\addons\common\fnc_removeWeaponCargo.sqf";
			};
			class removeWeaponCargoGlobal
			{
				description = "Function to remove specific items from global cargo space. MP synchronized.";
				file = "\x\cba\addons\common\fnc_removeWeaponCargoGlobal.sqf";
			};
			class selectWeapon
			{
				description = "Selects weapon, if the player has the weapon, including correctly selecting a muzzle, if any.";
				file = "\x\cba\addons\common\fnc_selectWeapon.sqf";
			};
			class setHeight
			{
				description = "A function used to set the height of an object";
				file = "\x\cba\addons\common\fnc_setHeight.sqf";
			};
			class setPos
			{
				description = "A function used to set the position of an entity.";
				file = "\x\cba\addons\common\fnc_setPos.sqf";
			};
			class switchPlayer
			{
				description = "Switch player to another unit.";
				file = "\x\cba\addons\common\fnc_switchPlayer.sqf";
			};
			class systemChat
			{
				description = "Display a message in the global chat channel.";
				file = "\x\cba\addons\common\fnc_systemChat.sqf";
			};
		};
	};
	class BIS
	{
		class variables
		{
			class undefCheck
			{
				file = "\x\cba\addons\common\dummy.sqf";
			};
		};
	};
	class BIS_PMC
	{
		class PMC_Campaign
		{
			class initIdentity
			{
				file = "\x\cba\addons\common\dummy.sqf";
			};
		};
	};
};
class RscMapControl
{
	class Task;
	class CustomMark;
	class Legend;
	class Bunker;
	class Bush;
	class Busstop;
	class Command;
	class Cross;
	class Fortress;
	class Fuelstation;
	class Fountain;
	class Hospital;
	class Chapel;
	class Church;
	class Lighthouse;
	class Quay;
	class Rock;
	class Ruin;
	class SmallTree;
	class Stack;
	class Tree;
	class Tourism;
	class Transmitter;
	class ViewTower;
	class WaterTower;
	class Waypoint;
	class WaypointCompleted;
	class ActiveMarker;
};
class CBA_Dummy_Map: RscMapControl
{
	idc = -1;
	type = 100;
	style = 48;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	colorBackground[] = {1.0,1.0,1.0,0};
	colorText[] = {0.0,0.0,0.0,0};
	colorSea[] = {0.56,0.8,0.98,0};
	colorForest[] = {0.6,0.8,0.2,0};
	colorRocks[] = {0.5,0.5,0.5,0};
	colorCountlines[] = {0.65,0.45,0.27,0};
	colorMainCountlines[] = {0.65,0.45,0.27,0};
	colorCountlinesWater[] = {0.0,0.53,1.0,0};
	colorMainCountlinesWater[] = {0.0,0.53,1.0,0};
	colorForestBorder[] = {0.4,0.8,0.0,0};
	colorRocksBorder[] = {0.5,0.5,0.5,0};
	colorPowerLines[] = {0.0,0.0,0.0,0};
	colorNames[] = {0.0,0.0,0.0,0};
	colorInactive[] = {1.0,1.0,1.0,0};
	colorLevels[] = {0.0,0.0,0.0,0};
	colorRailWay[] = {0.0,0.0,0.0,0};
	colorOutside[] = {0.56,0.8,0.98,0};
	font = "TahomaB";
	sizeEx = 0.0;
	stickX[] = {0.0,{"Gamma",1.0,1.5}};
	stickY[] = {0.0,{"Gamma",1.0,1.5}};
	ptsPerSquareSea = 0;
	ptsPerSquareTxt = 0;
	ptsPerSquareCLn = 0;
	ptsPerSquareExp = 0;
	ptsPerSquareCost = 0;
	ptsPerSquareFor = "0f";
	ptsPerSquareForEdge = "0f";
	ptsPerSquareRoad = 0;
	ptsPerSquareObj = 0;
	fontLabel = "Zeppelin32";
	sizeExLabel = 0.0;
	fontGrid = "Zeppelin32";
	sizeExGrid = 0.0;
	fontUnits = "Zeppelin32";
	sizeExUnits = 0.0;
	fontNames = "Zeppelin32";
	sizeExNames = 0.0;
	fontInfo = "Zeppelin32";
	sizeExInfo = 0.0;
	fontLevel = "Zeppelin32";
	sizeExLevel = 0.0;
	scaleMax = 1;
	scaleMin = 0.125;
	text = "";
	maxSatelliteAlpha = 0;
	alphaFadeStartScale = 1.0;
	alphaFadeEndScale = 1.1;
	showCountourInterval = 1;
	scaleDefault = 2;
	class Task: Task
	{
		color[] = {1,0.537,0,0};
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		iconCreated = "";
		iconCanceled = "";
		iconDone = "";
		iconFailed = "";
		colorCreated[] = {1,1,1,0};
		colorCanceled[] = {1,1,1,0};
		colorDone[] = {1,1,1,0};
		colorFailed[] = {1,1,1,0};
	};
	class CustomMark: CustomMark
	{
		color[] = {0.6471,0.6706,0.6235,0};
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Legend: Legend
	{
		x = "SafeZoneX";
		y = "SafeZoneY";
		w = 0.34;
		h = 0.152;
		font = "Zeppelin32";
		sizeEx = 0.03921;
		colorBackground[] = {0.906,0.901,0.88,0};
		color[] = {0,0,0,0};
	};
	class Bunker: Bunker
	{
		color[] = {0.55,0.64,0.43,0};
		size = 14;
		importance = "1.5 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bush: Bush
	{
		color[] = {0.45,0.64,0.33,0.0};
		size = 14;
		importance = "0.2 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class BusStop: BusStop
	{
		color[] = {0.15,0.26,0.87,0};
		size = 12;
		importance = "1 * 10 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Command: Command
	{
		color[] = {0,0.9,0,0};
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Cross: Cross
	{
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "0.7 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress: Fortress
	{
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fuelstation: Fuelstation
	{
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.75;
		coefMax = 4;
	};
	class Fountain: Fountain
	{
		color[] = {0.2,0.45,0.7,0};
		size = 11;
		importance = "1 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Hospital: Hospital
	{
		color[] = {0.78,0,0.05,0};
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Chapel: Chapel
	{
		color[] = {0.55,0.64,0.43,0};
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Church: Church
	{
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Lighthouse: Lighthouse
	{
		size = 14;
		color[] = {0,0.9,0,0};
		importance = "3 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Quay: Quay
	{
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Rock: Rock
	{
		color[] = {0.1,0.1,0.1,0.0};
		size = 12;
		importance = "0.5 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Ruin: Ruin
	{
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "1.2 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
	class SmallTree: SmallTree
	{
		color[] = {0.45,0.64,0.33,0.0};
		size = 12;
		importance = "0.6 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Stack: Stack
	{
		size = 20;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Tree: Tree
	{
		color[] = {0.45,0.64,0.33,0.0};
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Tourism: Tourism
	{
		color[] = {0.78,0,0.05,0};
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Transmitter: Transmitter
	{
		color[] = {0,0.9,0,0};
		size = 20;
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class ViewTower: ViewTower
	{
		color[] = {0,0.9,0,0};
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Watertower: Watertower
	{
		color[] = {0.2,0.45,0.7,0};
		size = 20;
		importance = "1.2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint: Waypoint
	{
		color[] = {0,0.35,0.7,0};
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class WaypointCompleted: WaypointCompleted
	{
		color[] = {0,0.35,0.7,0};
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class ActiveMarker: ActiveMarker
	{
		color[] = {0.3,0.1,0.9,0};
		size = 50;
	};
};
class RscPicture;
class RscTitles
{
	class CBA_FrameHandlerTitle
	{
		idd = 40121;
		movingEnable = 1;
		enableSimulation = 1;
		enableDisplay = 1;
		onLoad = "_this call CBA_common_fnc_perFrameEngine";
		duration = 2147483647;
		fadein = 0;
		fadeout = 0;
		name = "CBA_FrameHandlerTitle";
		class controlsBackground
		{
			class dummy_map: RscMapControl
			{
				idc = 40122;
				x = 0;
				y = 0;
				w = 0;
				h = 0;
			};
		};
		class objects{};
		class controls{};
	};
};
//};

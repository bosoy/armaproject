////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:31:15 2012 : Created on Fri Nov 09 22:31:15 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_ui : config.bin{
class CfgPatches
{
	class ace_c_ui
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAUI","Warfare2","CAFonts","ace_m_compass","Takistan","Desert_E","zargabad","Shapur_BAF","ProvingGrounds_PMC"};
	};
};
class CfgInGameUI
{
	class Cursor
	{
		iconComplex = "ca\ui\data\clear_empty.paa";
	};
	class DefaultAction
	{
		size = 0;
	};
};
class RscIGUIText;
class RscEdit;
class RscInGameUI
{
	class RscWeaponZeroing
	{
		class CA_ZeroingText: RscIGUIText
		{
			text = "$STR_DISP_ACE_ZEROING";
		};
	};
	class RscWeaponRangeZeroing
	{
		class CA_ZeroingText: RscIGUIText
		{
			text = "$STR_DISP_ACE_ZEROING";
		};
	};
	class RscUnitInfo_AH64D_gunner
	{
		class CA_WeaponZeroingText: RscIGUIText
		{
			text = "$STR_DISP_ACE_ZEROING";
		};
	};
};
class cfgActions
{
	class None;
	class GetInCommander: None
	{
		textDefault = "";
	};
	class GetInDriver: None
	{
		textDefault = "";
	};
	class GetInPilot: None
	{
		textDefault = "";
	};
	class GetInGunner: None
	{
		textDefault = "";
	};
	class GetInCargo: None
	{
		textDefault = "";
	};
	class GetInTurret: None
	{
		textDefault = "";
	};
	class Heal: None
	{
		textDefault = "";
	};
	class HealSoldier: None
	{
		textDefault = "";
	};
	class FirstAid: None
	{
		textDefault = "";
	};
	class Repair: None
	{
		textDefault = "";
	};
	class Refuel: None
	{
		textDefault = "";
	};
	class Rearm: None
	{
		textDefault = "";
	};
	class GetOut: None
	{
		textDefault = "";
	};
	class LightOn: None
	{
		textDefault = "";
	};
	class LightOff: None
	{
		textDefault = "";
	};
	class EngineOn: None
	{
		textDefault = "";
	};
	class EngineOff: None
	{
		textDefault = "";
	};
	class SwitchWeapon: None
	{
		textDefault = "";
	};
	class SwitchMagazine: SwitchWeapon{};
	class HideWeapon: SwitchWeapon
	{
		textDefault = "";
	};
	class UseWeapon: None
	{
		textDefault = "";
	};
	class LoadMagazine: None
	{
		textDefault = "";
	};
	class LoadOtherMagazine: LoadMagazine{};
	class LoadEmptyMagazine: LoadMagazine{};
	class TakeWeapon: None
	{
		textDefault = "";
	};
	class TakeDropWeapon: TakeWeapon
	{
		textDefault = "";
	};
	class TakeMagazine: None
	{
		textDefault = "";
	};
	class TakeDropMagazine: TakeMagazine
	{
		textDefault = "";
	};
	class TakeFlag: None
	{
		textDefault = "";
	};
	class ReturnFlag: None
	{
		textDefault = "";
	};
	class TurnIn: None
	{
		textDefault = "";
	};
	class TurnOut: None
	{
		textDefault = "";
	};
	class WeaponInHand: None
	{
		textDefault = "";
	};
	class WeaponOnBack: None
	{
		textDefault = "";
	};
	class SitDown: None
	{
		textDefault = "";
	};
	class Land: None
	{
		textDefault = "";
	};
	class cancelLand: None
	{
		textDefault = "";
	};
	class Eject: None
	{
		textDefault = "";
	};
	class MoveToDriver: None
	{
		textDefault = "";
	};
	class MoveToPilot: MoveToDriver
	{
		textDefault = "";
	};
	class MoveToGunner: None
	{
		textDefault = "";
	};
	class MoveToCommander: None
	{
		textDefault = "";
	};
	class MoveToCargo: None
	{
		textDefault = "";
	};
	class MoveToTurret: None
	{
		textDefault = "";
	};
	class HideBody: None
	{
		textDefault = "";
	};
	class TouchOff: None
	{
		textDefault = "";
	};
	class SetTimer: None
	{
		textDefault = "";
	};
	class StartTimer: SetTimer
	{
		textDefault = "";
	};
	class Deactivate: None
	{
		textDefault = "";
	};
	class NVGoggles: None
	{
		textDefault = "";
	};
	class NVGogglesOff: NVGoggles
	{
		textDefault = "";
	};
	class ManualFire: None
	{
		textDefault = "";
	};
	class ManualFireCancel: ManualFire
	{
		textDefault = "";
	};
	class AutoHover: None
	{
		textDefault = "";
	};
	class AutoHoverCancel: AutoHover
	{
		textDefault = "";
	};
	class StrokeFist: None
	{
		textDefault = "";
	};
	class StrokeGun: None
	{
		textDefault = "";
	};
	class LadderUp: None
	{
		textDefault = "";
	};
	class LadderDown: None
	{
		textDefault = "";
	};
	class LadderOnDown: None
	{
		textDefault = "";
	};
	class LadderOnUp: None
	{
		textDefault = "";
	};
	class LadderOff: None
	{
		textDefault = "";
	};
	class FireInflame: None
	{
		textDefault = "";
	};
	class FirePutDown: None
	{
		textDefault = "";
	};
	class LandGear: None
	{
		textDefault = "";
	};
	class LandGearUp: LandGear
	{
		textDefault = "";
	};
	class FlapsDown: None
	{
		textDefault = "";
	};
	class FlapsUp: None
	{
		textDefault = "";
	};
	class Salute: None
	{
		textDefault = "";
	};
	class ScudLaunch: None
	{
		textDefault = "";
	};
	class ScudStart: None
	{
		textDefault = "";
	};
	class ScudCancel: None
	{
		textDefault = "";
	};
	class User: None
	{
		textDefault = "";
	};
	class DropWeapon: None
	{
		textDefault = "";
	};
	class PutWeapon: DropWeapon
	{
		textDefault = "";
	};
	class DropMagazine: None
	{
		textDefault = "";
	};
	class PutMagazine: DropMagazine
	{
		textDefault = "";
	};
	class UserType: None
	{
		textDefault = "";
	};
	class HandGunOn: None
	{
		textDefault = "";
	};
	class HandGunOnStand: HandGunOn
	{
		textDefault = "";
	};
	class HandGunOff: None
	{
		textDefault = "";
	};
	class HandGunOffStand: HandGunOff
	{
		textDefault = "";
	};
	class TakeMine: None
	{
		textDefault = "";
	};
	class DeactivateMine: None
	{
		textDefault = "";
	};
	class UseMagazine: None
	{
		textDefault = "";
	};
	class IngameMenu: None
	{
		textDefault = "";
	};
	class cancelTakeFlag: None
	{
		textDefault = "";
	};
	class cancelAction: None
	{
		textDefault = "";
	};
	class MarkEntity: None
	{
		textDefault = "";
	};
	class MarkWeapon: MarkEntity
	{
		textDefault = "";
	};
	class TeamSwitch: None
	{
		textDefault = "";
	};
	class Gear: None
	{
		textDefault = "";
	};
	class Talk: None
	{
		textDefault = "";
	};
	class Tell: None
	{
		textDefault = "";
	};
	class Surrender: None
	{
		textDefault = "";
	};
	class GetOver: None
	{
		textDefault = "";
	};
};
class RscObject;
class RscWatch: RscObject
{
	scale = 1.5;
};
class RscMapControl;
class RscDisplayMainMap
{
	class controlsBackground
	{
		class CA_Map: RscMapControl
		{
			maxSatelliteAlpha = 0;
			colorBackground[] = {0.929412,0.929412,0.929412,1.0};
			colorCountlines[] = {0.647059,0.533333,0.286275,1};
			colorMainCountlines[] = {0.858824,0,0};
			colorForest[] = {0.6,0.8,0.2,0.25};
			colorLevels[] = {0.0,0.0,0.0,1.0};
			colorRocks[] = {0.5,0.5,0.5,0.5};
			sizeExLevel = 0.03;
			showCountourInterval = 1;
			class Bush
			{
				icon = "";
				color[] = {0.45,0.64,0.33,0.0};
				size = 14;
				importance = "0.2 * 14 * 0.05";
				coefMin = 0.25;
				coefMax = 4;
			};
			class SmallTree
			{
				icon = "";
				color[] = {0.45,0.64,0.33,0.0};
				size = 12;
				importance = "0.6 * 12 * 0.05";
				coefMin = 0.25;
				coefMax = 4;
			};
			class Tree
			{
				icon = "";
				color[] = {0.45,0.64,0.33,0.0};
				size = 12;
				importance = "0.9 * 16 * 0.05";
				coefMin = 0.25;
				coefMax = 4;
			};
			class Legend
			{
				x = "SafeZoneX+SafeZoneW-.340";
				y = "SafeZoneY+SafeZoneH-.152";
				w = 0.34;
				h = 0.152;
				font = "Zeppelin32";
				sizeEx = 0.03921;
				colorBackground[] = {0.906,0.901,0.88,0.5};
				color[] = {0,0,0,0.75};
			};
		};
	};
	class objects
	{
		class Compass: RscObject
		{
			scale = "(0.35 * 2.85)";
			model = "\x\ace\addons\m_compass\Compass.p3d";
		};
	};
};
class RscDisplayChat
{
	class controls
	{
		class CA_Line: RscEdit
		{
			colorBackground[] = {0,0,0,0.4};
		};
	};
};
class CfgWorlds
{
	class DefaultWorld;
	class CAWorld: DefaultWorld
	{
		class Grid{};
	};
	class Chernarus: CAWorld
	{
		class Grid: Grid
		{
			offsetY = 15360;
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.075;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class utes: CAWorld
	{
		class Grid: Grid
		{
			offsetY = 5120;
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.3;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class Desert_E: CAWorld
	{
		class Grid: Grid
		{
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.3;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class Takistan: CAWorld
	{
		class Grid: Grid
		{
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.1;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class Zargabad: CAWorld
	{
		class Grid: Grid
		{
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.18;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class Shapur_BAF: CAWorld
	{
		class Grid: Grid
		{
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.3;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class ProvingGrounds_PMC: CAWorld
	{
		class Grid: Grid
		{
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.3;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
};
class RscPicture;
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscDisplayLoading
{
	class Variants
	{
		class LoadingOne
		{
			class controls
			{
				class LoadingPic: RscPictureKeepAspect
				{
					text = "\x\ace\addons\c_ui\data\ls.paa";
				};
			};
		};
	};
};
class RscDisplayLoadMission: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPictureKeepAspect
		{
			text = "\x\ace\addons\c_ui\data\ls.paa";
		};
	};
};
class RscDisplayStart: RscStandardDisplay
{
	class controls
	{
		class LoadingPic: RscPictureKeepAspect
		{
			text = "\x\ace\addons\c_ui\data\ls.paa";
		};
	};
};
class CfgWrapperUI
{
	class Background
	{
		texture = "\x\ace\addons\c_ui\data\ls.paa";
	};
};
class RscDisplayClient: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPic: RscPicture
		{
			text = "\x\ace\addons\c_ui\data\ls.paa";
		};
	};
};
class RscButton
{
	soundEnter[] = {"",0.09,1};
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEscape[] = {"",0.09,1};
};
class RscShortcutButton
{
	soundEnter[] = {"",0.09,1};
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEscape[] = {"",0.09,1};
};
class RscXListBox
{
	soundSelect[] = {"",0.09,1};
};
class RscShortcutButtonMainMenu: RscShortcutButton
{
	soundEnter[] = {"",0.09,1};
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEscape[] = {"",0.09,1};
};
class RscShortcutButtonMain: RscShortcutButton
{
	soundEnter[] = {"",0.09,1};
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEscape[] = {"",0.09,1};
};
class RscShortcutButtonDiary: RscShortcutButton
{
	soundEnter[] = {"",0.09,1};
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEscape[] = {"",0.09,1};
};
class RscShortcutButtonDiaryMap: RscShortcutButton
{
	soundEnter[] = {"",0.09,1};
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEscape[] = {"",0.09,1};
};
class WFGUIButton
{
	soundPush[] = {"",0.09,1};
	soundClick[] = {"\ca\ui\data\sound\new1",0.07,1};
	soundEnter[] = {"",0.1,1};
	soundEscape[] = {"",0.2,1};
};
class WFGUIImage
{
	soundClick[] = {"\ca\ui\data\sound\new1",0.2,1};
	soundEnter[] = {"",0.2,1};
	soundEscape[] = {"",0.2,1};
	soundPush[] = {"",0.2,1};
};
//};

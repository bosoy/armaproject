////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:08 2013 : Created on Sat Jun 08 13:05:08 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_anims : movement\config.bin{
class CfgPatches
{
	class ace_anims_movement
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.01;
		requiredAddons[] = {"CA_Anims","CA_Anims_E","CA_Anims_Sdr","CA_Anims_E_Sdr","CA_Animals2_Anim_Config"};
		version = 0;
	};
};
class CfgMovesBasic
{
	class Default;
	class DefaultDie;
	class Actions
	{
		class NoActions;
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions
		{
			weaponOn = "ACE_LauncherProne";
			weaponOff = "AmovPpneMstpSnonWnonDnon";
		};
		class LauncherKneelActions: NoActions
		{
			down = "ACE_LauncherProne";
			up = "AmovPercMstpSrasWlnrDnon";
			PlayerProne = "ACE_LauncherProne";
			PlayerStand = "AmovPercMstpSrasWlnrDnon";
			CivilLying = "ACE_LauncherProne";
			Lying = "ACE_LauncherProne";
			EvasiveBack = "";
			Stand = "AmovPercMstpSrasWlnrDnon";
			Crouch = "AmovPknlMstpSrasWlnrDnon";
		};
		class ACE_LauncherProneActions: LauncherKneelActions
		{
			stop = "ACE_LauncherProne";
			default = "ACE_LauncherProne";
			weaponOn = "ACE_LauncherProne";
			weaponOff = "AmovPpneMstpSrasWrflDnon";
			binocOn = "awopppnemstpsoptwbindnon_non";
			binocOff = "ACE_LauncherProne";
			handGunOn = "AmovPpneMstpSrasWpstDnon";
			reloadAT[] = {"",""};
			reloadMagazine[] = {"",""};
			down = "AmovPercMstpSrasWlnrDnon";
			up = "AmovPknlMstpSrasWlnrDnon";
			PlayerStand = "AmovPercMstpSrasWlnrDnon";
			PlayerCrouch = "AmovPknlMstpSrasWlnrDnon";
			PlayerProne = "ACE_LauncherProne";
			Combat = "ACE_LauncherProne";
			Lying = "ACE_LauncherProne";
			Stand = "AmovPercMstpSrasWlnrDnon";
			Crouch = "AmovPknlMstpSrasWlnrDnon";
			die = "AdthPpneMstpSrasWrflDnon_1";
			Civil = "AmovPpneMstpSnonWnonDnon";
			CivilLying = "AmovPpneMstpSnonWnonDnon";
			walkF = "ACE_LauncherProneCrawlF";
			walkLF = "ACE_LauncherProneCrawlfl";
			walkRF = "ACE_LauncherProneCrawlfr";
			walkL = "ACE_LauncherProneCrawll";
			walkR = "ACE_LauncherProneCrawlr";
			walkLB = "ACE_LauncherProneCrawlbl";
			walkRB = "ACE_LauncherProneCrawlbr";
			walkB = "ACE_LauncherProneCrawlb";
			slowF = "ACE_LauncherProneCrawlf";
			slowLF = "ACE_LauncherProneCrawlfl";
			slowRF = "ACE_LauncherProneCrawlfr";
			slowL = "ACE_LauncherProneCrawll";
			slowR = "ACE_LauncherProneCrawlr";
			slowLB = "ACE_LauncherProneCrawlbl";
			slowRB = "ACE_LauncherProneCrawlbr";
			slowB = "ACE_LauncherProneCrawlb";
			fastF = "ACE_LauncherProneCrawlf";
			fastLF = "ACE_LauncherProneCrawlfl";
			fastRF = "ACE_LauncherProneCrawlfr";
			fastL = "ACE_LauncherProneCrawll";
			fastR = "ACE_LauncherProneCrawlr";
			fastLB = "ACE_LauncherProneCrawlbl";
			fastRB = "ACE_LauncherProneCrawlbr";
			fastB = "ACE_LauncherProneCrawlb";
			EvasiveForward = "AmovPknlMstpSrasWlnrDnon";
			EvasiveLeft = "AmovPpneMstpSnonWnonDnon_AmovPpneMevaSnonWnonDl";
			EvasiveRight = "AmovPpneMstpSnonWnonDnon_AmovPpneMevaSnonWnonDr";
			EvasiveBack = "";
			turnL = "";
			turnR = "";
			turnLRelaxed = "";
			turnRRelaxed = "";
			getInCar = "AmovPknlMstpSrasWrflDnon";
			getOutCar = "AmovPknlMstpSrasWrflDnon";
			getInTank = "AmovPknlMstpSrasWrflDnon";
			getOutTank = "AmovPknlMstpSrasWrflDnon";
			upDegree = "ManPosWeapon";
			leanRRot = 0;
			leanRShift = 0;
			leanLRot = 0;
			leanLShift = 0;
			turnSpeed = 2;
		};
		class CivilStandActions;
		class CivilProneActions: CivilStandActions
		{
			weaponOn = "ACE_LauncherProne";
		};
		class ACE_Keycuffed_LoopActions: CivilStandActions
		{
			stop = "ACE_Keycuffed_Loop";
			stopRelaxed = "ACE_Keycuffed_Loop";
			default = "ACE_Keycuffed_Loop";
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AmovPercMstpSrasWrflDnon;
		class AswmPercMstpSnonWnonDnon: AmovPercMstpSrasWrflDnon
		{
			duty = 0.06;
		};
		class TransAnimBase;
		class AmovPknlMstpSrasWrflDnon_AmovPpneMstpSrasWrflDnon: TransAnimBase
		{
			disableWeapons = 1;
		};
		class AmovPpneMstpSrasWrflDnon_AmovPknlMstpSrasWrflDnon: TransAnimBase
		{
			disableWeapons = 1;
		};
		class AmovPercMstpSrasWrflDnon_AmovPpneMstpSrasWrflDnon: TransAnimBase
		{
			disableWeapons = 1;
		};
		class AmovPpneMstpSrasWrflDnon_AmovPercMstpSrasWrflDnon: TransAnimBase
		{
			disableWeapons = 1;
		};
		class ACE_LauncherProne: Default
		{
			actions = "ACE_LauncherProneActions";
			duty = "-0.7";
			file = "\x\ace\addons\anims\movement\ACE_Launcher_Lying.rtm";
			collisionShape = "ca\Anims\Characters\data\Geom\Sdr\Ppne.p3d";
			showWeaponAim = 0;
			disableWeapons = 0;
			disableWeaponsLong = 0;
			enableMissile = 1;
			canPullTrigger = 1;
			aimPrecision = 0.3;
			speed = 1e+010;
			relSpeedMin = 0.7;
			relSpeedMax = 1.1;
			aiming = "aimingLauncher";
			looped = 1;
			soundEnabled = 0;
			connectTo[] = {};
			connectFrom[] = {};
			interpolateFrom[] = {"ACE_LauncherProne",0.04};
			interpolateTo[] = {"ACE_LauncherProne",0.04};
			enableBinocular = 1;
			preload = 0;
			headBobStrength = 0.20398;
			headBobMode = 2;
			leftHandIKBeg = 1;
			leftHandIKCurve[] = {1};
			leftHandIKEnd = 1;
			rightHandIKBeg = 1;
			rightHandIKCurve[] = {1};
			rightHandIKEnd = 1;
			weaponIK = 4;
			legs = "legsLyingAimingPistol";
			visibleSize = 0.15;
			onLandBeg = 1;
			onLandEnd = 1;
			leaningFactorBeg = 0;
			leaningFactorEnd = 0;
			enableOptics = 4;
		};
		class ACE_LauncherKneel_LauncherProne: TransAnimBase
		{
			actions = "ACE_LauncherProneActions";
			file = "\ca\Anims\Characters\data\Anim\Sdr\mov\knl\stp\ras\lnr\AmovPknlMstpSrasWlnrDnon_AmovPpneMstpSnonWnonDnon";
			speed = 0.33;
			weaponIK = 4;
			aiming = "aimingCivil";
			aimingBody = "aimingUpCivil";
			onLandBeg = 0;
			onLandEnd = 1;
			interpolationSpeed = 1;
			soundOverride = "laydown";
			soundEnabled = 1;
			enableMissile = 1;
			interpolateFrom[] = {"AmovPknlMstpSrasWlnrDnon",0.01};
			interpolateTo[] = {"ACE_LauncherProne",0.01};
		};
		class ACE_LauncherProne_LauncherKneel: TransAnimBase
		{
			actions = "LauncherKneelActions";
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\stp\non\non\AmovPpneMstpSnonWnonDnon_AmovPknlMstpSrasWlnrDnon";
			speed = 0.31;
			aiming = "aimingCivil";
			aimingBody = "aimingUpCivil";
			onLandBeg = 1;
			onLandEnd = 0;
			enableMissile = 1;
			interpolationSpeed = 1;
			soundOverride = "standup";
			soundEnabled = 1;
			leaningFactorBeg = 0.5;
			leaningFactorEnd = 0.5;
			weaponIK = 4;
			interpolateFrom[] = {"ACE_LauncherProne",0.01};
			interpolateTo[] = {"AmovPknlMstpSrasWlnrDnon",0.01};
		};
		class ACE_RifleProne_LauncherProne: TransAnimBase
		{
			actions = "ACE_LauncherProneActions";
			file = "\ca\Anims\Characters\data\Anim\Sdr\mov\pne\stp\ras\rfl\AmovPpneMstpSrasWrflDnon_AwopPpneMstpSoptWbinDnon";
			speed = 0.66;
			disableWeapons = 1;
			aiming = "aimingCivil";
			aimingBody = "aimingUpCivil";
			interpolationSpeed = 1;
			leftHandIKBeg = 0.0;
			leftHandIKCurve[] = {};
			leftHandIKEnd = 0.0;
			rightHandIKBeg = 0.0;
			rightHandIKCurve[] = {};
			rightHandIKEnd = 0.0;
			soundEnabled = 0;
			leaningFactorBeg = 1.0;
			leaningFactorEnd = 0.5;
			interpolateFrom[] = {"AmovPpneMstpSrasWrflDnon",0.01};
			interpolateTo[] = {"ACE_LauncherProne",0.01};
			weaponIK = 4;
			onLandBeg = 1;
			onLandEnd = 1;
		};
		class ACE_LauncherProne_RifleProne: TransAnimBase
		{
			actions = "RifleProneActions";
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\stp\ras\pst\AmovPpneMstpSrasWpstDnon_AmovPpneMstpSrasWrflDnon_end";
			speed = 0.16;
			disableWeapons = 1;
			aiming = "aimingCivil";
			aimingBody = "aimingUpCivil";
			interpolationSpeed = 1;
			leftHandIKBeg = 0.0;
			leftHandIKCurve[] = {0};
			leftHandIKEnd = 0;
			rightHandIKBeg = 0.0;
			rightHandIKCurve[] = {0};
			rightHandIKEnd = 0;
			soundEnabled = 0;
			leaningFactorBeg = 0;
			leaningFactorEnd = 0;
			interpolateFrom[] = {"ACE_LauncherProne",0.01};
			interpolateTo[] = {"AmovPpneMstpSrasWrflDnon",0.01};
			weaponIK = 4;
			onLandBeg = 1;
			onLandEnd = 1;
		};
		class ACE_LauncherProneCrawlf: ACE_LauncherProne
		{
			actions = "ACE_LauncherProneActions";
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDf";
			speed = 0.9;
			collisionShape = "ca\Anims\Characters\data\Geom\Sdr\Ppne.p3d";
			duty = "-0.3";
			leaningFactorBeg = 0;
			leaningFactorEnd = 0;
			disableWeapons = 1;
			disableWeaponsLong = 1;
			soundEnabled = 1;
			connectTo[] = {"ACE_LauncherProneCrawlf",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlf",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlfl",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlfl",0.025};
			weaponIK = 0;
		};
		class ACE_LauncherProneCrawlfl: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDfl";
			speed = 0.9;
			connectTo[] = {"ACE_LauncherProneCrawlfl",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlfl",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawll",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawll",0.025};
		};
		class ACE_LauncherProneCrawll: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDl";
			speed = 1.2;
			connectTo[] = {"ACE_LauncherProneCrawll",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawll",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlbl",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlbl",0.025};
		};
		class ACE_LauncherProneCrawlbl: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDbl";
			speed = 0.9;
			connectTo[] = {"ACE_LauncherProneCrawlbl",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlbl",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlb",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlb",0.025};
		};
		class ACE_LauncherProneCrawlb: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDb";
			speed = 0.9;
			connectTo[] = {"ACE_LauncherProneCrawlb",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlb",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlbr",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlbr",0.025};
		};
		class ACE_LauncherProneCrawlbr: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDbr";
			speed = 0.8;
			connectTo[] = {"ACE_LauncherProneCrawlbr",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlbr",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlr",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlr",0.025};
		};
		class ACE_LauncherProneCrawlr: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDr";
			speed = 1.2;
			connectTo[] = {"ACE_LauncherProneCrawlr",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlr",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlfr",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlfr",0.025};
		};
		class ACE_LauncherProneCrawlfr: ACE_LauncherProneCrawlf
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\Mov\pne\run\non\non\AmovPpneMrunSnonWnonDfr";
			speed = 0.75;
			connectTo[] = {"ACE_LauncherProneCrawlfr",0.02};
			connectFrom[] = {"ACE_LauncherProneCrawlfr",0.02};
			interpolateFrom[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlf",0.025};
			interpolateTo[] = {"ACE_LauncherProne",0.02,"ACE_LauncherProneCrawlf",0.025};
		};
		class AmovPercMstpSnonWnonDnon;
		class ACE_Keycuffed_Loop: AmovPercMstpSnonWnonDnon
		{
			actions = "ACE_Keycuffed_LoopActions";
			file = "\x\ace\addons\anims\movement\ACE_Keycuffed_Loop.rtm";
			speed = 0.075;
			looped = 1;
			ConnectTo[] = {"DeadState",1};
			connectFrom[] = {"AmovPercMstpSlowWrflDnon",2};
			interpolateFrom[] = {};
			interpolateTo[] = {};
			disableWeapons = 1;
		};
	};
	class Interpolations
	{
		ACE_LauncherProneMove[] = {2,"ACE_LauncherProne","ACE_LauncherProneCrawlF","ACE_LauncherProneCrawlfl","ACE_LauncherProneCrawlfr","ACE_LauncherProneCrawll","ACE_LauncherProneCrawlr","ACE_LauncherProneCrawlbl","ACE_LauncherProneCrawlbr","ACE_LauncherProneCrawlb"};
	};
};
class CfgMovesAnimalsBase
{
	class StandBase;
	class DefaultDie;
};
class CfgMovesHen: CfgMovesAnimalsBase
{
	class States
	{
		class Hen_Die: DefaultDie
		{
			soundEnabled = 1;
			soundOverride = "laydown";
			soundEdge[] = {0,0.2};
		};
	};
};
class CfgMovesCow: CfgMovesAnimalsBase
{
	class States
	{
		class Cow_Die: DefaultDie
		{
			soundEnabled = 1;
			soundOverride = "laydown";
			soundEdge[] = {0,0.5};
		};
	};
};
class CfgMovesGoat: CfgMovesAnimalsBase
{
	class States
	{
		class Goat_Die: DefaultDie
		{
			soundEnabled = 1;
			soundOverride = "laydown";
			soundEdge[] = {0,0.5};
		};
	};
};
class CfgMovesSheep: CfgMovesAnimalsBase
{
	class States
	{
		class Sheep_Die: DefaultDie
		{
			soundEnabled = 1;
			soundOverride = "laydown";
			soundEdge[] = {0,0.5};
		};
	};
};
class CfgMovesDog: CfgMovesAnimalsBase
{
	class States
	{
		class Dog_Die: DefaultDie
		{
			soundEnabled = 1;
			soundOverride = "laydown";
			soundEdge[] = {0,0.5};
		};
	};
};
//};

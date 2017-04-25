////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:08 2013 : Created on Sat Jun 08 13:05:08 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_anims : reload\config.bin{
class CfgPatches
{
	class ace_anims_reload
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.01;
		requiredAddons[] = {"CA_Anims","CA_Anims_E","CA_Anims_Sdr","CA_Anims_E_Sdr","CAWeapons","CAWeapons2","CAWeapons_E","CAWeapons_BAF"};
		version = 0;
	};
};
class CfgMovesBasic
{
	class Default;
	class ManActions
	{
		ReloadM136 = "";
	};
	class Actions
	{
		class NoActions;
		class RifleBaseLowStandActions: NoActions
		{
			reloadMGun = "MGunMagazineReloadStand";
		};
		class RifleBaseStandActions: RifleBaseLowStandActions
		{
			reloadMGun = "MGunMagazineReloadStand";
		};
		class RifleStandActions: RifleBaseStandActions
		{
			reloadMGun = "MGunMagazineReloadStand";
		};
		class RifleStandActionsRunF: RifleStandActions
		{
			reloadMGun = "MGunMagazineReloadStand";
		};
		class RifleKneelActions: RifleBaseStandActions
		{
			reloadMGun = "MGunMagazineReloadKneel";
		};
		class RifleProneActions: RifleBaseStandActions
		{
			reloadMGun = "MGunMagazineReloadProne";
		};
		class PistolStandActions: NoActions
		{
			reloadMGun = "MGunMagazineReloadStand";
		};
		class PistolKneelActions: PistolStandActions
		{
			reloadMGun = "MGunMagazineReloadKneel";
		};
		class PistolProneActions: PistolStandActions
		{
			reloadMGun = "MGunMagazineReloadProne";
		};
		class CivilStandActions: NoActions
		{
			reloadMGun = "MGunMagazineReloadStand";
		};
		class CivilKneelActions: CivilStandActions
		{
			reloadMGun = "MGunMagazineReloadKneel";
			ReloadM136 = "ACE_LauncherMagazineReloadKneel_M136";
		};
		class CivilProneActions: CivilStandActions
		{
			reloadMGun = "MGunMagazineReloadProne";
		};
		class LauncherKneelActions: NoActions
		{
			ReloadM136[] = {"ACE_LauncherMagazineReloadKneel_M136","Gesture"};
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class WeaponMagazineReloadStand;
		class WeaponMagazineReloadKneel;
		class WeaponMagazineReloadProne;
		class MGunMagazineReloadStand: WeaponMagazineReloadStand
		{
			connectFrom[] = {"AmovPercMstpSrasWrflDnon",0.1};
			connectTo[] = {"AmovPercMstpSrasWrflDnon",0.1};
			speed = 0.25;
			interpolateFrom[] = {"AmovPercMstpSrasWrflDnon",1};
			interpolateTo[] = {"AdthPercMstpSrasWrflDnon_1",0.1};
		};
		class MGunMagazineReloadKneel: WeaponMagazineReloadKneel
		{
			connectFrom[] = {"AmovPknlMstpSrasWrflDnon",0.1};
			connectTo[] = {"AmovPknlMstpSrasWrflDnon",0.1};
			speed = 0.25;
			interpolateFrom[] = {"AmovPknlMstpSrasWrflDnon",1};
			interpolateTo[] = {"AdthPknlMstpSrasWrflDnon_1",0.1};
		};
		class MGunMagazineReloadProne: WeaponMagazineReloadProne
		{
			connectFrom[] = {"AmovPpneMstpSrasWrflDnon",0.1};
			connectTo[] = {"AmovPpneMstpSrasWrflDnon",0.1};
			speed = 0.25;
			interpolateFrom[] = {"AmovPpneMstpSrasWrflDnon",1};
			interpolateTo[] = {"AdthPpneMstpSrasWrflDnon_1",0.1};
		};
	};
};
class CfgGesturesMale
{
	class Default;
	class States
	{
		class MGunMagazineReloadStand: Default
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\wop\erc\stp\rld\rfl\AwopPercMstpSrldWrflDnon.rtm";
			looped = 0;
			speed = 0.3;
			mask = "handsWeapon";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
			leftHandIKCurve[] = {0,1,0.05,0,0.95,0,1,1};
		};
		class MGunMagazineReloadKneel: Default
		{
			file = "\ca\Anims\Characters\data\Anim\Sdr\wop\knl\stp\rld\rfl\AwopPknlMstpSrldWrflDnon.rtm";
			looped = 0;
			speed = 0.3;
			mask = "handsWeapon";
			headBobStrength = 0.2;
			headBobMode = 2;
			rightHandIKBeg = 1;
			rightHandIKEnd = 1;
			leftHandIKCurve[] = {0,1,0.05,0,0.95,0,1,1};
		};
		class LauncherMagazineReloadStand;
		class LauncherMagazineReloadKneel;
		class ACE_LauncherMagazineReloadKneel_M136: LauncherMagazineReloadKneel
		{
			speed = 1.2;
		};
		class ACE_LauncherMagazineReloadKneel_SMAW: LauncherMagazineReloadKneel
		{
			speed = 0.3;
		};
		class ACE_LauncherMagazineReloadKneel_Javelin: LauncherMagazineReloadKneel
		{
			speed = 0.1;
		};
		class ACE_LauncherMagazineReloadKneel_MAAWS: LauncherMagazineReloadKneel
		{
			speed = 0.3;
		};
	};
};
class CfgWeapons
{
	class Rifle;
	class Launcher;
	class M249: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class PK: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class M240: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class M60A4_EP1: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class BAF_L110A1_Aim: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class m107: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class ksvk: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class BAF_AS50_scoped: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class UK59_ACR: Rifle
	{
		reloadAction = "ManActReloadMGun";
	};
	class M136: Launcher
	{
		reloadAction = "ManActReloadM136";
	};
	class RPG18: Launcher
	{
		reloadAction = "ManActReloadM136";
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class CA_LauncherMagazine;
	class 200Rnd_556x45_M249: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class 100Rnd_762x51_M240: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class 100Rnd_762x54_PK: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class 10Rnd_127x99_m107: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class 5Rnd_127x108_KSVK: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class 5Rnd_86x70_L115A1: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class 5Rnd_127x99_as50: CA_Magazine
	{
		reloadAction = "ManActReloadMGun";
	};
	class M136: CA_LauncherMagazine
	{
		reloadAction = "ManActReloadM136";
	};
	class RPG18: CA_LauncherMagazine
	{
		reloadAction = "ManActReloadM136";
	};
};
//};

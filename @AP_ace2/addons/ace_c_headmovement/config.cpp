////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:23:15 2011 : Created on Fri Oct 21 13:23:15 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_headmovement : config.bin{
class CfgPatches
{
	class ace_c_headmovement
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.59;
		requiredAddons[] = {"ace_main","CA_Anims","CA_Anims","CA_Anims_Sdr","CA_Anims_Wmn","CA_Anims_Char","CACharacters","CACharacters2"};
	};
};
class CfgVehicles
{
	class Land;
	class Man: Land
	{
		class ViewPilot;
	};
	class CAManBase: Man
	{
		minGunElev = -89;
		maxGunElev = 89;
		class ViewPilot: ViewPilot
		{
			maxAngleX = 89;
			initAngleY = 0;
			minAngleY = -155;
			maxAngleY = 155;
		};
		class HeadLimits;
	};
	class SoldierWB: CAManBase
	{
		class HeadLimits: HeadLimits
		{
			minAngleX = -45;
			maxAngleX = 60;
			minAngleY = -90;
			maxAngleY = 90;
		};
	};
	class SoldierEB: CAManBase
	{
		class HeadLimits: HeadLimits
		{
			minAngleX = -45;
			maxAngleX = 60;
			minAngleY = -90;
			maxAngleY = 90;
		};
	};
	class SoldierGB: CAManBase
	{
		class HeadLimits: HeadLimits
		{
			minAngleX = -45;
			maxAngleX = 60;
			minAngleY = -90;
			maxAngleY = 90;
		};
	};
	class Civilian: CAManBase
	{
		class HeadLimits: HeadLimits
		{
			minAngleX = -45;
			maxAngleX = 60;
			minAngleY = -90;
			maxAngleY = 90;
		};
	};
};
class CfgMovesBasic
{
	class BlendAnims;
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class BlendAnims: BlendAnims
	{
		access = 1;
		empty[] = {};
		aimingDefault[] = {"head",0.9,"neck1",0.8,"neck",0.7,"weapon",1,"launcher",1,"LeftShoulder",0.7,"LeftArm",0.9,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",0.7,"RightArm",0.9,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",0.1,"Spine1",0.2,"Spine2",0.4,"Spine3",0.6};
		aimingLying[] = {"head",0.9,"neck1",0.7,"neck",0.8,"weapon",1,"launcher",1,"LeftShoulder",0.7,"LeftArm",0.8,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",0.7,"RightArm",0.8,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",0.3,"Spine1",0.3,"Spine2",0.4,"Spine3",0.6};
		aimingPistol[] = {"head",0.9,"neck1",0.8,"neck",0.7,"weapon",1,"launcher",1,"LeftShoulder",0.7,"LeftArm",0.8,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",0.7,"RightArm",0.8,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",0.3,"Spine1",0.3,"Spine2",0.4,"Spine3",0.6};
		aimingLyingPistol[] = {"head",0.9,"neck1",0.7,"neck",0.8,"weapon",1,"launcher",1,"LeftShoulder",0.7,"LeftArm",0.8,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",0.7,"RightArm",0.8,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",0.3,"Spine1",0.3,"Spine2",0.4,"Spine3",0.6};
		aimingLauncher[] = {"head",0.9,"neck1",0.7,"neck",0.8,"launcher",1,"LeftShoulder",0.7,"LeftArm",0.8,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",0.7,"RightArm",0.8,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",0.3,"Spine1",0.3,"Spine2",0.4,"Spine3",0.6};
		aimingCivil[] = {};
		headDefault[] = {"head",1,"neck1",0.5,"neck",0.25};
	};
};
//};

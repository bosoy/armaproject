////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:49 2012 : Created on Fri Nov 09 22:39:49 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_ka50 : config.bin{
class CfgPatches
{
	class acex_ru_veh_ka50
	{
		units[] = {"ACE_Ka50","ACE_Ka50N"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAAir","CAAir_E"};
		version = "1.14.0.76";
	};
};
class AirplaneHUD
{
	class Pos10Vector;
	class Bones
	{
		class AGLMove1;
		class AGLMove2;
		class ASLMove1;
		class ASLMove2;
		class VertSpeed;
		class ILS;
		class SpdMove2;
		class TargetDistanceMissile;
		class TargetDistanceMGun;
		class Level0;
		class PlaneW;
	};
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class HitPoints;
	};
	class Kamov_Base: Helicopter{};
	class Ka52: Kamov_Base
	{
		class HitPoints: HitPoints
		{
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitHRotor;
		};
		class ViewPilot;
	};
	class ACE_Ka50_base: Ka52
	{
		scope = 1;
		destrType = "DestructEngine";
		side = 0;
		faction = "RU";
		crew = "RU_Soldier_Pilot";
		crewVulnerable = 0;
		memoryPointGun = "machinegun";
		displayName = "$STR_ACE_VDN_KA50";
		nameSound = "kamov";
		damageResistance = 0.00635;
		model = "\x\acex_ru\addons\m_veh_ka50\KA50";
		weapons[] = {"ACE_2A42","80mmLauncher","VikhrLauncher","CMFlareLauncher"};
		magazines[] = {"230Rnd_30mmHE_2A42","230Rnd_30mmAP_2A42","40Rnd_80mm","12Rnd_Vikhr_KA50","120Rnd_CMFlareMagazine"};
		transportSoldier = 0;
		typicalCargo[] = {"RU_Soldier_Pilot"};
		transportAmmo = 0;
		class Turrets{};
		driverAction = "KA52_Pilot";
		driverInAction = "KA52_Pilot";
		hasGunner = 0;
		driverOpticsModel = "\ca\air\optika_Ka50_gun";
		driverOpticsColor[] = {0,0,0,1};
		gearRetracting = 1;
		mainRotorSpeed = 1.0;
		backRotorSpeed = 1.0;
		selectionHRotorStill = "velka vrtule staticka";
		selectionHRotorMove = "velka vrtule blur";
		selectionVRotorStill = "mala vrtule staticka";
		selectionVRotorMove = "mala vrtule blur";
		castDriverShadow = 1;
		viewCargoShadow = 1;
		gunnerUsesPilotView = 1;
		memoryPointLMissile = "Missile_1";
		memoryPointRMissile = "Missile_2";
		memoryPointLRocket = "Rocket_1";
		memoryPointRRocket = "Rocket_2";
		maxMainRotorDive = 4;
		minMainRotorDive = -4;
		neutralMainRotorDive = 0;
		gunnerOpticsModel = "\ca\air\optika_Ka50_gun";
		gunnerOpticsEffect[] = {"TankCommanderOptics1","BWTV"};
		gunnerForceOptics = 0;
		gunBeg = "muzzle";
		gunEnd = "chamber";
		memoryPointGunnerOptics = "gunnerview";
		selectionFireAnim = "zasleh";
		hiddenSelections[] = {};
		class HitPoints: HitPoints
		{
			class HitHRotor: HitHRotor
			{
				armor = 0.3;
			};
			class HitGlass1: HitGlass1
			{
				armor = 8;
			};
			class HitGlass2: HitGlass2
			{
				armor = 8;
			};
			class HitGlass3: HitGlass3
			{
				armor = 5;
			};
			class HitGlass4: HitGlass4
			{
				armor = 5;
			};
		};
		class ViewPilot
		{
			initFov = 1;
			minFov = 0.5;
			maxFov = 1.2;
			initAngleX = 10;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -125;
			maxAngleY = 125;
		};
		class Viewoptics
		{
			initAngleX = 0;
			minAngleX = 0;
			maxAngleX = 0;
			initAngleY = 0;
			minAngleY = 0;
			maxAngleY = 0;
			initFov = 0.1;
			minFov = 0.1;
			maxFov = 1.2;
		};
		class OpticsIn
		{
			class Wide
			{
				opticsDisplayName = "E";
				initAngleX = 0;
				minAngleX = -30;
				maxAngleX = 30;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				maxFov = "0.3333/1";
				minFov = "0.3333/1";
				initFov = "0.3333/1";
				visionMode[] = {"Normal","NVG","Ti"};
				thermalMode[] = {0,1};
				gunnerOpticsModel = "\ca\air\optika_Ka50_gun";
				gunnerOpticsEffect[] = {"TVOptics","OpticsBlur2","OpticsCHAbera2"};
			};
			class Medium: Wide
			{
				opticsDisplayName = "W";
				minFov = "0.3333/6";
				maxFov = "0.3333/6";
				initFov = "0.3333/6";
				gunnerOpticsModel = "\ca\air\optika_Ka50_gun";
			};
			class Narrow: Wide
			{
				opticsDisplayName = "M";
				minFov = "0.3333/18";
				maxFov = "0.3333/18";
				initFov = "0.3333/18";
				gunnerOpticsModel = "\ca\air\optika_Ka50_rocket";
			};
			class Narrowest: Wide
			{
				opticsDisplayName = "N";
				minFov = "0.3333/32";
				maxFov = "0.3333/32";
				initFov = "0.3333/32";
				gunnerOpticsModel = "\ca\air\optika_Ka50_rocket";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[] = {0.8,0.8,1.0,1.0};
				ambient[] = {0.07,0.07,0.07,1.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 1.0;
			};
			class Right
			{
				color[] = {0.8,0.8,1.0,1.0};
				ambient[] = {0.07,0.07,0.07,1.0};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 1;
				brightness = 1.0;
			};
		};
		dammageHalf[] = {"\ca\air2\ka52\Data\ka52_cauges_CO.paa","\ca\air2\ka52\Data\ka52_caugesmf_CO.paa"};
		dammageFull[] = {"\ca\air2\ka52\Data\ka52_cauges_CO.paa","\ca\air2\ka52\Data\ka52_caugesmf_CO.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_ka50\ka50_01.rvmat","x\acex_ru\addons\c_veh_ka50\ka50_01_damage.rvmat","x\acex_ru\addons\c_veh_ka50\ka50_01_destruct.rvmat","x\acex_ru\addons\c_veh_ka50\ka50_02.rvmat","x\acex_ru\addons\c_veh_ka50\ka50_02_damage.rvmat","x\acex_ru\addons\c_veh_ka50\ka50_02_destruct.rvmat"};
		};
		class Library
		{
			libTextDesc = "";
		};
		class MFD
		{
			class AirplaneHUD
			{
				enableParallax = 1;
				class Pos10Vector
				{
					type = "vector";
					pos0[] = {0.502,0.49};
					pos10[] = {1.112,1.03};
				};
				topLeft = "HUD LH";
				topRight = "HUD PH";
				bottomLeft = "HUD LD";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0,1,0,0.1};
				class Bones
				{
					class PlaneW
					{
						type = "fixed";
						pos[] = {0.502,0.49};
					};
					class WeaponAim: Pos10Vector
					{
						source = "weapon";
					};
					class Target: Pos10Vector
					{
						source = "target";
					};
					class Velocity: Pos10Vector
					{
						type = "vector";
						source = "velocity";
						pos0[] = {0.502,0.49};
						pos10[] = {0.563,0.544};
					};
					class SpdMove2
					{
						source = "speed";
						min = 0;
						max = 138.889;
						type = "linear";
						minPos[] = {0.0,"0.15*0.65"};
						maxPos[] = {0.0,"0.65*0.65"};
					};
					class AGLMove
					{
						type = "linear";
						source = "altitudeAGL";
						min = 0;
						max = 50;
						minPos[] = {0.0,"0.15*0.65"};
						maxPos[] = {0.0,"0.65*0.65"};
					};
					class Heading
					{
						type = "linear";
						source = "Heading";
						min = -36;
						max = 36;
						minPos[] = {0.0,0.0};
						maxPos[] = {1.0,0.0};
					};
					class TargetDistanceMissile
					{
						type = "rotational";
						source = "targetDist";
						center[] = {0,0};
						min = 100;
						max = 3000;
						minAngle = -120;
						maxAngle = 120;
					};
					class vspeed
					{
						source = "vspeed";
						type = "linear";
						min = -30;
						max = 30;
						minPos[] = {0.0,"0.15*0.4"};
						maxPos[] = {0.0,"0.75*0.4"};
					};
					class HorizonBankMGun
					{
						type = "rotational";
						source = "HorizonBank";
						center[] = {0,0};
						min = -6.28319;
						max = 6.28319;
						minAngle = -360;
						maxAngle = 360;
						aspectRatio = 0.885246;
					};
					class HorizonDive
					{
						source = "horizonDive";
						type = "linear";
						min = -1;
						max = 1;
						minPos[] = {0.502,2.49};
						maxPos[] = {0.502,-1.51};
					};
				};
				class Draw
				{
					alpha = 0.4;
					color[] = {0.0,0.3,0.05};
					condition = "on";
					clipTL[] = {0.0,0.0};
					clipBR[] = {1.0,1.0};
					class PlaneW
					{
						type = "line";
						points[] = {{"PlaneW",1,"HorizonBankMGun",{-0.08,0},1},{"PlaneW",1,"HorizonBankMGun",{-0.04,0},1},{"PlaneW",1,"HorizonBankMGun",{-0.0348,-0.0177049},1},{"PlaneW",1,"HorizonBankMGun",{-0.02,-0.0308066},1},{"PlaneW",1,"HorizonBankMGun",{0,-0.0354098},1},{"PlaneW",1,"HorizonBankMGun",{0.02,-0.0308066},1},{"PlaneW",1,"HorizonBankMGun",{0.0348,-0.0177049},1},{"PlaneW",1,"HorizonBankMGun",{0.04,0},1},{"PlaneW",1,"HorizonBankMGun",{0.08,0},1}};
					};
					class PlaneHeading
					{
						clipTL[] = {0.3,0.3};
						clipBR[] = {0.7,0.7};
						class Vector
						{
							type = "line";
							points[] = {{"Velocity",0.001,"PlaneW",{0,0},1},{"Velocity",{0,0},1}};
						};
					};
					class Static
					{
						clipTL[] = {0.0,0.1};
						clipBR[] = {1.0,0.0};
						type = "line";
						points[] = {{"SpdMove2",{0.27,"0.1+0.01"},1},{"SpdMove2",{0.255,"0.1+0.0"},1},{"SpdMove2",{0.27,"0.1-0.01"},1},{"SpdMove2",{0.27,"0.1+0.01"},1},{},{{0.25,"0.1+0.15*0.65"},1},{{0.25,"0.1+0.65*0.65"},1},{},{{0.25,"0.1+0.15*0.65"},1},{{0.23,"0.1+0.15*0.65"},1},{},{{0.245,"0.1+0.65*0.65"},1},{{0.23,"0.1+0.65*0.65"},1},{},{{0.245,"0.1+0.25*0.65"},1},{{0.23,"0.1+0.25*0.65"},1},{},{{0.245,"0.1+0.35*0.65"},1},{{0.23,"0.1+0.35*0.65"},1},{},{{0.245,"0.1+0.45*0.65"},1},{{0.23,"0.1+0.45*0.65"},1},{},{{0.2455,"0.1+0.55*0.65"},1},{{0.23,"0.1+0.55*0.65"},1},{},{"AGLMove",{"1-0.27","0.1+0.01"},1},{"AGLMove",{"1-0.255","0.1+0.0"},1},{"AGLMove",{"1-0.27","0.1-0.01"},1},{"AGLMove",{"1-0.27","0.1+0.01"},1},{},{{"1-0.25","0.1+0.15*0.65"},1},{{"1-0.25","0.1+0.65*0.65"},1},{},{{"1-0.25","0.1+0.15*0.65"},1},{{"1-0.23","0.1+0.15*0.65"},1},{},{{"1-0.245-0.03","0.1+0.65*0.65"},1},{{"1-0.23+0.005","0.1+0.65*0.65"},1},{},{{"1-0.245","0.1+0.25*0.65"},1},{{"1-0.23","0.1+0.25*0.65"},1},{},{{"1-0.245","0.1+0.35*0.65"},1},{{"1-0.23","0.1+0.35*0.65"},1},{},{{"1-0.245","0.1+0.45*0.65"},1},{{"1-0.23","0.1+0.45*0.65"},1},{},{{"1-0.245","0.1+0.55*0.65"},1},{{"1-0.23","0.1+0.55*0.65"},1},{},{"vspeed",{"0.27-0.05","0.55+0.01"},1},{"vspeed",{"0.255-0.05","0.55+0.0"},1},{"vspeed",{"0.27-0.05","0.55-0.01"},1},{"vspeed",{"0.27-0.05","0.55+0.01"},1},{},{{"0.25-0.05","0.55+0.12*0.40"},1},{{"0.25-0.05","0.55+0.58*0.40"},1},{},{{"0.25-0.05","0.55+0.15*0.40"},1},{{"0.23-0.05","0.55+0.15*0.40"},1},{},{{"0.245-0.05","0.55+0.55*0.40"},1},{{"0.23-0.05","0.55+0.55*0.40"},1},{},{{"0.245-0.05","0.55+0.25*0.40"},1},{{"0.23-0.05","0.55+0.25*0.40"},1},{},{{"0.245-0.05","0.55+0.35*0.40"},1},{{"0.23-0.05","0.55+0.35*0.40"},1},{},{{"0.245-0.05","0.55+0.45*0.40"},1},{{"0.23-0.05","0.55+0.45*0.40"},1},{},{"vspeed",{"1-0.27+0.05","0.55+0.01"},1},{"vspeed",{"1-0.255+0.05","0.55+0.0"},1},{"vspeed",{"1-0.27+0.05","0.55-0.01"},1},{"vspeed",{"1-0.27+0.05","0.55+0.01"},1},{},{{"1-0.25+0.05","0.55+0.12*0.40"},1},{{"1-0.25+0.05","0.55+0.78*0.40"},1},{},{{"1-0.25+0.05","0.55+0.15*0.40"},1},{{"1-0.22+0.05","0.55+0.15*0.40"},1},{},{{"1-0.245+0.05","0.55+0.75*0.40"},1},{{"1-0.22+0.05","0.55+0.75*0.40"},1},{},{{"1-0.245+0.05","0.55+0.25*0.40"},1},{{"1-0.23+0.05","0.55+0.25*0.40"},1},{},{{"1-0.245+0.05","0.55+0.35*0.40"},1},{{"1-0.23+0.05","0.55+0.35*0.40"},1},{},{{"1-0.245+0.05","0.55+0.45*0.40"},1},{{"1-0.22+0.05","0.55+0.45*0.40"},1},{},{{"1-0.245+0.05","0.55+0.55*0.40"},1},{{"1-0.23+0.05","0.55+0.55*0.40"},1},{},{{"1-0.245+0.05","0.55+0.65*0.40"},1},{{"1-0.23+0.05","0.55+0.65*0.40"},1},{},{{0.52,"0.08+0.01+0.05"},1},{{0.5,"0.06+0.01+0.05"},1},{{0.48,"0.08+0.01+0.05"},1},{},{{0.3,"0.055+0.01+0.05"},1},{{0.7,"0.055+0.01+0.05"},1},{}};
					};
					class Horizont
					{
						clipTL[] = {0.25,0.25};
						clipBR[] = {0.75,0.75};
						class Dimmed
						{
							class Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,0},1},{"HorizonDive",{-0.15,0},1},{},{"HorizonDive",{-0.01,0},1},{"HorizonDive",{0.01,0},1},{},{"HorizonDive",{0.15,0},1},{"HorizonDive",{0.2,0},1}};
							};
							class Level2M5: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*5*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*5*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*5*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*5*2/3"},1}};
							};
							class VALM2_1_5
							{
								type = "text";
								source = "static";
								text = 5;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*5*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*5*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*5*2/3"},1};
							};
							class Level2P5: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*5*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*5*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*5*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*5*2/3"},1}};
							};
							class VALP2_1_5
							{
								type = "text";
								source = "static";
								text = -5;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*5*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*5*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*5*2/3"},1};
							};
							class Level2M10: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*10*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*10*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*10*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*10*2/3"},1}};
							};
							class VALM2_1_10
							{
								type = "text";
								source = "static";
								text = 10;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*10*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*10*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*10*2/3"},1};
							};
							class Level2P10: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*10*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*10*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*10*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*10*2/3"},1}};
							};
							class VALP2_1_10
							{
								type = "text";
								source = "static";
								text = -10;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*10*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*10*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*10*2/3"},1};
							};
							class Level2M15: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*15*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*15*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*15*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*15*2/3"},1}};
							};
							class VALM2_1_15
							{
								type = "text";
								source = "static";
								text = 15;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*15*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*15*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*15*2/3"},1};
							};
							class Level2P15: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*15*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*15*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*15*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*15*2/3"},1}};
							};
							class VALP2_1_15
							{
								type = "text";
								source = "static";
								text = -15;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*15*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*15*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*15*2/3"},1};
							};
							class Level2M20: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*20*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*20*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*20*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*20*2/3"},1}};
							};
							class VALM2_1_20
							{
								type = "text";
								source = "static";
								text = 20;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*20*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*20*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*20*2/3"},1};
							};
							class Level2P20: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*20*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*20*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*20*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*20*2/3"},1}};
							};
							class VALP2_1_20
							{
								type = "text";
								source = "static";
								text = -20;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*20*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*20*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*20*2/3"},1};
							};
							class Level2M25: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*25*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*25*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*25*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*25*2/3"},1}};
							};
							class VALM2_1_25
							{
								type = "text";
								source = "static";
								text = 25;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*25*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*25*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*25*2/3"},1};
							};
							class Level2P25: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*25*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*25*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*25*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*25*2/3"},1}};
							};
							class VALP2_1_25
							{
								type = "text";
								source = "static";
								text = -25;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*25*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*25*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*25*2/3"},1};
							};
							class Level2M30: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*30*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*30*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*30*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*30*2/3"},1}};
							};
							class VALM2_1_30
							{
								type = "text";
								source = "static";
								text = 30;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*30*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*30*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*30*2/3"},1};
							};
							class Level2P30: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*30*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*30*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*30*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*30*2/3"},1}};
							};
							class VALP2_1_30
							{
								type = "text";
								source = "static";
								text = -30;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*30*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*30*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*30*2/3"},1};
							};
							class Level2M35: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*35*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*35*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*35*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*35*2/3"},1}};
							};
							class VALM2_1_35
							{
								type = "text";
								source = "static";
								text = 35;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*35*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*35*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*35*2/3"},1};
							};
							class Level2P35: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*35*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*35*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*35*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*35*2/3"},1}};
							};
							class VALP2_1_35
							{
								type = "text";
								source = "static";
								text = -35;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*35*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*35*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*35*2/3"},1};
							};
							class Level2M40: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*40*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*40*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*40*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*40*2/3"},1}};
							};
							class VALM2_1_40
							{
								type = "text";
								source = "static";
								text = 40;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*40*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*40*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*40*2/3"},1};
							};
							class Level2P40: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*40*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*40*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*40*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*40*2/3"},1}};
							};
							class VALP2_1_40
							{
								type = "text";
								source = "static";
								text = -40;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*40*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*40*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*40*2/3"},1};
							};
							class Level2M45: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*45*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*45*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*45*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*45*2/3"},1}};
							};
							class VALM2_1_45
							{
								type = "text";
								source = "static";
								text = 45;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*45*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*45*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*45*2/3"},1};
							};
							class Level2P45: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*45*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*45*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*45*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*45*2/3"},1}};
							};
							class VALP2_1_45
							{
								type = "text";
								source = "static";
								text = -45;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*45*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*45*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*45*2/3"},1};
							};
							class Level2M50: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"-0.54/10*50*2/3"},1},{"HorizonDive",{-0.1,"-0.54/10*50*2/3"},1},{},{"HorizonDive",{0.1,"-0.54/10*50*2/3"},1},{"HorizonDive",{0.2,"-0.54/10*50*2/3"},1}};
							};
							class VALM2_1_50
							{
								type = "text";
								source = "static";
								text = 50;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3*+0.03","-0.025*2/3-0.54/10*50*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3-0.54/10*50*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3-0.54/10*50*2/3"},1};
							};
							class Level2P50: Level00
							{
								type = "line";
								points[] = {{"HorizonDive",{-0.2,"+0.54/10*50*2/3"},1},{"HorizonDive",{-0.1,"+0.54/10*50*2/3"},1},{},{"HorizonDive",{0.1,"+0.54/10*50*2/3"},1},{"HorizonDive",{0.2,"+0.54/10*50*2/3"},1}};
							};
							class VALP2_1_50
							{
								type = "text";
								source = "static";
								text = -50;
								align = "center";
								scale = 1;
								sourceScale = 1;
								pos[] = {"HorizonDive",{"-0.04*2/3+0.03","-0.025*2/3+0.54/10*50*2/3"},1};
								right[] = {"HorizonDive",{"0.04*2/3+0.03","-0.025*2/3+0.54/10*50*2/3"},1};
								down[] = {"HorizonDive",{"-0.04*2/3+0.03","0.025*2/3+0.54/10*50*2/3"},1};
							};
						};
					};
					class Target
					{
						type = "line";
						points[] = {{"Target",{0,0.057541},1},{"Target",{0.0325,0.0500607},1},{"Target",{0.05655,"+0.50*0.065/(0.61/0.54)"},1},{"Target",{0.065,0},1},{"Target",{0.05655,-0.0287705},1},{"Target",{0.0325,"-0.87*0.065/(0.61/0.54)"},1},{"Target",{0,-0.057541},1},{"Target",{-0.0325,-0.0500607},1},{"Target",{-0.05655,"-0.50*0.065/(0.61/0.54)"},1},{"Target",{-0.065,0},1},{"Target",{-0.05655,0.0287705},1},{"Target",{-0.0325,"+0.87*0.065/(0.61/0.54)"},1},{"Target",{0,0.057541},1}};
					};
					class SpeedNumber
					{
						type = "text";
						align = "right";
						scale = 1;
						source = "speed";
						sourceScale = 3.6;
						pos[] = {{"0.06+0.1",0.07},1};
						right[] = {{"0.14+0.1",0.07},1};
						down[] = {{"0.06+0.1",0.12},1};
						format = "+%3.0fp";
					};
					class AltNumber: SpeedNumber
					{
						source = "altitudeAGL";
						sourceScale = 1;
						pos[] = {{"0.86-0.1",0.07},1};
						right[] = {{"0.94-0.1",0.07},1};
						down[] = {{"0.86-0.1",0.12},1};
						format = "%3.0f";
					};
					class VspeedNumber: SpeedNumber
					{
						source = "vspeed";
						sourceScale = 1;
						align = "left";
						pos[] = {{"0.86-0.05","0.52+0.03"},1};
						right[] = {{"0.94-0.05","0.52+0.03"},1};
						down[] = {{"0.86-0.05","0.57+0.03"},1};
					};
					class VspeedNumberStaticP30
					{
						type = "text";
						source = "static";
						text = "+30";
						scale = 1;
						sourceScale = 1;
						align = "right";
						pos[] = {{"0.9-0.05","0.54+0.15*0.4"},1};
						right[] = {{"0.95-0.05","0.54+0.15*0.4"},1};
						down[] = {{"0.9-0.05","0.54+0.15*0.4+0.05*5/8"},1};
					};
					class VspeedNumberStaticM30: VspeedNumberStaticP30
					{
						text = -30;
						pos[] = {{"0.9-0.05","0.54+0.75*0.4"},1};
						right[] = {{"0.95-0.05","0.54+0.75*0.4"},1};
						down[] = {{"0.9-0.05","0.54+0.75*0.4+0.05*5/8"},1};
					};
					class VspeedNumberStaticZERO: VspeedNumberStaticP30
					{
						text = " 0";
						pos[] = {{"0.9-0.05","0.54+0.45*0.4"},1};
						right[] = {{"0.95-0.05","0.54+0.45*0.4"},1};
						down[] = {{"0.9-0.05","0.54+0.45*0.4+0.05*5/8"},1};
					};
					class AltStatic50: VspeedNumberStaticP30
					{
						text = "50";
						pos[] = {{"0.9-0.11","0.08+0.15*0.65"},1};
						right[] = {{"0.95-0.11","0.08+0.15*0.65"},1};
						down[] = {{"0.9-0.11","0.08+0.15*0.65+0.05*5/8"},1};
					};
					class SpeedStatic500: VspeedNumberStaticP30
					{
						text = 500;
						align = "left";
						pos[] = {{"0.1+0.1","0.08+0.15*0.65"},1};
						right[] = {{"0.15+0.1","0.08+0.15*0.65"},1};
						down[] = {{"0.1+0.1","0.08+0.15*0.65+0.05*5/8"},1};
					};
					class SpeedStaticZERO: SpeedStatic500
					{
						text = "0";
						pos[] = {{"0.1+0.1","0.08+0.65*0.65"},1};
						right[] = {{"0.15+0.1","0.08+0.65*0.65"},1};
						down[] = {{"0.1+0.1","0.08+0.65*0.65+0.05*5/8"},1};
					};
					class NevimStaticZERO: SpeedStatic500
					{
						text = "0";
						pos[] = {{"0.1+0.07","0.54+0.45*0.4"},1};
						right[] = {{"0.15+0.07","0.54+0.45*0.4"},1};
						down[] = {{"0.1+0.07","0.54+0.45*0.4+0.05*5/8"},1};
					};
					class NevimStatic1: NevimStaticZERO
					{
						text = "1";
						pos[] = {{"0.1+0.07","0.58+0.45*0.4"},1};
						right[] = {{"0.15+0.07","0.58+0.45*0.4"},1};
						down[] = {{"0.1+0.07","0.58+0.45*0.4+0.05*5/8"},1};
					};
					class NevimStatic3: NevimStaticZERO
					{
						text = "3";
						pos[] = {{"0.1+0.07","0.42+0.45*0.4"},1};
						right[] = {{"0.15+0.07","0.42+0.45*0.4"},1};
						down[] = {{"0.1+0.07","0.42+0.45*0.4+0.05*5/8"},1};
					};
					class HeadingScale
					{
						type = "scale";
						scale = 1;
						source = "Heading";
						sourceScale = 1;
						align = "center";
						pos[] = {"0.32-0.01","0.0+0.05"};
						right[] = {"0.38-0.01","0.0+0.05"};
						down[] = {"0.32-0.01","0.04+0.05"};
						lineXleft = "0.06+0.05";
						lineYright = "0.05+0.05";
						lineXleftMajor = "0.06+0.05";
						lineYrightMajor = "0.04+0.05";
						bottom = 0.7;
						center = 0.5;
						top = 0.3;
						step = "18/9";
						StepSize = "(0.70- 0.3)/15";
						horizontal = 1;
						min = "none";
						max = "none";
						numberEach = 5;
						majorLineEach = 5;
					};
				};
			};
		};
	};
	class ACE_Ka50: ACE_Ka50_base
	{
		scope = 2;
	};
	class ACE_Ka50N: ACE_Ka50
	{
		scope = 1;
	};
};
//};

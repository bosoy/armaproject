#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#define VSoft		0
#define VArmor		1
#define VAir		2

#define LockNo		0
#define LockCadet		1
#define LockYes		2

#define LockNo		0
#define LockCadet		1
#define LockYes		2

class CfgPatches {
	class ace_c_weapon {
		units[] = {"ACE_USBasicAmmunitionBox", "ACE_USLaunchersBox", "ACE_USOrdnanceBox", "ACE_USBasicWeaponsBox", "ACE_USSpecialWeaponsBox", "ACE_USVehicleBox", "ACE_RUBasicAmmunitionBox", "ACE_RULaunchersBox", "ACE_RUOrdnanceBox", "ACE_RUBasicWeaponsBox", "ACE_RUSpecialWeaponsBox", "ACE_RUVehicleBox", "ACE_LocalBasicAmmunitionBox", "ACE_LocalBasicWeaponsBox", "ACE_GuerillaCacheBox", "ACE_SpecialWeaponsBox"};
		weapons[] = {"ACE_M203_Launcher", "ACE_KeyCuffs"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons", "CAWeapons2", "CAWeapons_E", "CAWeapons_BAF", "CAWeapons_M252_81mm_Mortar", "CAWeapons_2b14_82mm_Mortar", "CAweapons_m107", "ace_main", "ace_m_wep_rpg7", "ace_m_wep_dragon"};
		version = 1.14.0.597;
	};
	
	class ace_c_wep_magazines {
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		version = 1.14.0.597;
		ace_bwc = 1;
	};
};

class CfgAddons {
	class PreloadAddons {
		class ace_c_weapon {
			list[] = {"ace_c_weapon"};
		};
	};
};

class ACE_FAE_Explosion {
	class Light {
		intensity = 0.001;
		interval = 1;
		lifetime = 0.2;
		position[] = {0, 0, 0};
		simulation = "light";
		type = "ExploLight";
	};
	
	class Aerosol {
		intensity = 8;
		interval = 0.32;
		lifetime = 0.32;
		position[] = {0, 0, 0};
		simulation = "particles";
		type = "ACE_FAE_Aerosol";
	};
	
	class Explosion {
		intensity = 12;
		interval = 0.32;
		lifetime = 0.32;
		position[] = {0, 0, 0};
		simulation = "particles";
		type = "ACE_FAE_Explosion";
	};
	
	class Explosion2 : Explosion {};
	
	class Smoke {
		intensity = 14;
		interval = 0.96;
		lifetime = 0.96;
		position[] = {0, 0, 0};
		simulation = "particles";
		type = "ACE_FAE_Smoke";
	};
};

class ACE_FAE_Crater {
	class DustCircle {
		intensity = 1;
		interval = 1;
		lifetime = 0.3;
		position[] = {0, 0, 0};
		simulation = "particles";
		type = "CircleDustMed";
	};
	
	class DustCircle2 : DustCircle {};
};

class CfgCloudlets {
	class ExploAmmoFlash;	// External class reference
	
	class ACE_FAE_Explosion : ExploAmmoFlash {
		animationspeed[] = {0, 0, 2, 1, 2};
		color[] = {{1, 1, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, -2}, {1, 1, 1, -2}, {1, 1, 1, 0}};
		interval = 0.32;
		lifetime = 0.32;
		lifetimevar = 0.04;
		positionvar[] = {0, 0.1, 0};
		rotationvelocity = 0;
		rotationvelocityvar = 1;
		rubbing = 0.1;
		size[] = {0, 0, 10, 11, 12};
		volume = 10;
		weight = 10;
	};
	
	class ACE_FAE_Aerosol : ACE_FAE_Explosion {
		animationspeed[] = {1};
		color[] = {{1, 1, 1, 1}, {1, 1, 1, 0.9}, {1, 1, 1, 0.8}, {1, 1, 1, 0.4}, {1, 1, 1, 0}};
		particlefsframecount = 8;
		particlefsindex = 12;
		size[] = {4, 6, 8, 4, 0};
		volume = 8;
		weight = 8;
	};
	
	class ACE_FAE_Smoke : ACE_FAE_Aerosol {
		animationspeed[] = {0, 2.8, 1.9, 1.2, 1.05, 0.7, 0.35, 0.175};
		color[] = {{1, 1, 1, 0}, {1, 1, 1, 0.4}, {0.95, 0.95, 0.95, 0.8}, {0.9, 0.9, 0.9, 0.6}, {0.85, 0.85, 0.85, 0.3}, {0.8, 0.8, 0.8, 0.15}, {0.7, 0.7, 0.7, 0.075}, {0.6, 0.6, 0.6, 0}};
		interval = 0.96;
		lifetime = 0.96;
		lifetimevar = 0.02;
		particlefsframecount = 48;
		particlefsindex = 7;
		particlefsloop = 1;
		particlefsntieth = 16;
		size[] = {0, 0, 9, 10, 11, 12, 13, 14};
		volume = 14;
	};
	class RocketSmokeTrails;	// External class reference
	
	class ACE_FAE_SmokeTrails : RocketSmokeTrails {
		animationspeed[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.5, 1.5, 0.9, 0.75, 0.75};
		interval = 0.24;
		lifetime = 0.24;
		lifetimevar = 0.02;
		ontimerscript = "";
	};
};

class CfgVehicleClasses {
	class ACE_Ammunition {
		displayName = $STR_VC_ACE_AMMO;
	};
	
	class ACE_AmmunitionTransportUS {
		displayName = $STR_VC_ACE_AMMO_TRANSPORT_US;
	};
	
	class ACE_AmmunitionTransportRU {
		displayName = $STR_VC_ACE_AMMO_TRANSPORT_RU;
	};
};

class CfgRecoils {
	ACE_762x25_PistolRecoil[] = {0, 0.007, 0.05, 0.005, 0.007, 0.05, 0.09, 0, -0.008, 0.1, 0, 0};
	ACE_9x18_PistolRecoil[] = {0, 0.007, 0.05, 0.005, 0.007, 0.05, 0.09, 0, -0.008, 0.1, 0, 0};
	ACE_9x19_PistolRecoil[] = {0, 0.007, 0.05, 0.005, 0.007, 0.05, 0.09, 0, -0.008, 0.1, 0, 0};
	ACE_45ACP_PistolRecoil[] = {0, 0.007, 0.06, 0.005, 0.007, 0.06, 0.09, 0, -0.009, 0.1, 0, 0};
	ACE_Glock_Auto_Recoil[] = {0, 0.007, 0.03, 0.005, 0.007, 0.03, 0.09, 0, -0.0024, 0.1, 0, 0};
	ACE_Glock_Recoil[] = {0, 0.007, 0.05, 0.005, 0.007, 0.05, 0.09, 0, -0.008, 0.1, 0, 0};
	ACE_vz61Recoil[] = {0, 0.006, 0.02, 0.005, 0.006, 0.02, 0.09, 0, -0.001, 0.1, 0, 0};
	ACE_9x18_SUP_PistolRecoil[] = {0, 0.007, 0.04, 0.005, 0.007, 0.04, 0.09, 0, -0.01, 0.11, 0, 0};
	ACE_9x19_SUP_PistolRecoil[] = {0, 0.007, 0.04, 0.005, 0.007, 0.04, 0.09, 0, -0.01, 0.11, 0, 0};
	ACE_45ACP_SUP_PistolRecoil[] = {0, 0.007, 0.05, 0.005, 0.007, 0.05, 0.09, 0, -0.011, 0.11, 0, 0};
	ACE_9x19_SMG_Recoil[] = {0, 0.004, -0.001, 0.01, 0.004, 0.006, 0.02, 0.002, 0.006, 0.1, 0, 0};
	ACE_45ACP_SMG_Recoil[] = {0, 0.005, -0.002, 0.01, 0.005, 0.007, 0.03, 0.003, 0.007, 0.1, 0, 0};
	ACE_545x39_Rifle_Recoil[] = {0, 0.006, 0, 0.01, 0.006, 0, 0.02, 0.004, 0.01, 0.08, 0, 0};
	ACE_545x39_Rifle_Recoil_B[] = {0, 0.005, 0.008, 0.01, 0.005, 0.008, 0.02, 0.002, 0.008, 0.08, 0, 0};
	ACE_545x39_Rifle_Recoil_Low[] = {0, 0.0045, 0, 0.01, 0.0045, 0, 0.02, 0.003, 0.007, 0.08, 0, 0};
	ACE_545x39_Rifle_Recoil_GL[] = {0, 0.005, 0, 0.01, 0.005, 0, 0.02, 0.003, 0.006, 0.12, 0, 0};
	ACE_545x39_Rifle_Recoil_AKSU[] = {0, 0.007, 0.003, 0.01, 0.007, 0.003, 0.02, 0.006, 0.012, 0.08, 0, 0};
	ACE_545x39_Rifle_RecoilProne[] = {0, 0.004, 0.006, 0.01, 0.004, 0.006, 0.02, 0.002, 0.001, 0.05, 0, 0};
	ACE_545x39_MG_Recoil[] = {0, 0.006, 0.005, 0.01, 0.006, 0.005, 0.03, 0.004, 0.009, 0.12, 0, 0};
	ACE_545x39_MG_RecoilProne[] = {0, 0.006, 0.003, 0.01, 0.006, 0.003, 0.05, 0.004, -0.002, 0.12, 0, 0};
	ACE_762x39_Rifle_Recoil[] = {0, 0.012, 0.001, 0.02, 0.01, 0.015, 0.03, 0.008, 0.015, 0.1, 0, 0};
	ACE_762x39_PBS_Recoil[] = {0, 0.007, 0.007, 0.01, 0.007, 0.007, 0.02, 0.003, 0.01, 0.08, 0, 0};
	ACE_762x39_Rifle_Recoil_GL[] = {0, 0.01, 0.001, 0.02, 0.01, 0.012, 0.03, 0.006, 0.012, 0.14, 0, 0};
	ACE_762x39_Rifle_RecoilProne[] = {0, 0.007, 0.008, 0.01, 0.007, 0.008, 0.03, 0.004, 0.001, 0.1, 0, 0};
	ACE_762x39_MG_Recoil[] = {0, 0.01, 0.013, 0.01, 0.01, 0.013, 0.04, 0.005, 0.005, 0.12, 0, 0};
	ACE_762x39_MG_RecoilProne[] = {0, 0.007, 0.0045, 0.01, 0.007, 0.0045, 0.05, 0.0035, -0.0025, 0.13, 0, 0};
	ACE_762x54R_Rifle_Recoil[] = {0, 0.013, 0.015, 0.02, 0.013, 0.015, 0.1, 0.009, 0.015, 0.17, 0, 0};
	ACE_762x54R_Rifle_RecoilProne[] = {0, 0.007, 0.01, 0.013, 0.007, 0.01, 0.03, 0.003, 0, 0.07, 0, 0};
	ACE_762x54R_MG_Recoil[] = {0, 0.008, 0.014, 0.14, 0.006, 0, 0.2, 0, 0};
	ACE_762x54R_MG_RecoilProne[] = {0, 0.01, 0.0012, 0.1, 0.0095, -0.001, 0.15, 0, 0};
	ACE_127x108_Rifle_Recoil[] = {0, 0.015, 0.02, 0.025, 0.014, 0.02, 0.6, 0, 0};
	ACE_127x108_Rifle_RecoilProne[] = {0, 0.015, 0.001, 0.03, 0.015, -0.002, 0.04, 0.01, 0.005, 0.06, 0, 0};
	ACE_556x45_Rifle_Recoil[] = {0, 0.006, 0, 0.01, 0.006, 0, 0.02, 0.004, 0.01, 0.08, 0, 0};
	ACE_556x45_Rifle_Recoil_B[] = {0, 0.005, -0.002, 0.01, 0.005, 0.008, 0.02, 0.004, 0.008, 0.08, 0, 0};
	ACE_556x45_Rifle_Recoil_GL[] = {0, 0.005, 0, 0.01, 0.005, 0, 0.02, 0.003, 0.006, 0.12, 0, 0};
	ACE_556x45_Rifle_RecoilProne[] = {0, 0.004, 0.006, 0.01, 0.004, 0.006, 0.02, 0.002, 0.001, 0.05, 0, 0};
	ACE_556x45_MG_Recoil[] = {0, 0.006, 0.005, 0.01, 0.006, 0.005, 0.03, 0.004, 0.009, 0.12, 0, 0};
	ACE_556x45_MG_RecoilProne[] = {0, 0.006, 0.003, 0.01, 0.006, 0.003, 0.02, 0.004, -0.001, 0.14, 0, 0};
	ACE_M249_Recoil[] = {0, 0.006, -0.003, 0.05, 0.006, 0.006, 0.03, 0.006, 0.006, 0.17, 0, 0};
	ACE_M249_PIP_Recoil[] = {0, 0.005, -0.0025, 0.045, 0.0055, 0.005, 0.025, 0.005, 0.0051, 0.156, 0, 0};
	ACE_M249_RecoilProne[] = {0, 0.005, 0.002, 0.07, 0.005, -0.0015, 0.12, 0, 0};
	ACE_M240_Recoil[] = {0, 0.01, 0.014, 0.14, 0.006, 0, 0.2, 0, 0};
	ACE_M240_RecoilProne[] = {0, 0.01, 0.0012, 0.09, 0.009, -0.001, 0.15, 0, 0};
	ACE_Mk48_Recoil[] = {0, 0.01, 0.002, 0.05, 0.01, 0.003, 0.04, 0.006, 0.02, 0.17, 0, 0};
	ACE_Mk48_RecoilProne[] = {0, 0.01, 0.0012, 0.09, 0.009, -0.001, 0.15, 0, 0};
	ACE_762x51_Rifle_Recoil[] = {0, 0.013, 0.015, 0.02, 0.013, 0.015, 0.1, 0.009, 0.015, 0.12, 0, 0};
	ACE_762x51_Rifle_RecoilProne[] = {0, 0.007, 0.01, 0.013, 0.007, 0.01, 0.03, 0.003, 0, 0.12, 0, 0};
	ACE_338_Rifle_Recoil[] = {0, 0.015, 0.017, 0.02, 0.015, 0.017, 0.1, 0.009, 0.017, 0.16, 0, 0};
	ACE_338_Rifle_RecoilProne[] = {0, 0.012, 0.001, 0.03, 0.012, -0.002, 0.05, 0.008, 0.005, 0.06, 0, 0};
	ACE_762x51_SCAR_Recoil[] = {0, 0.012, 0.015, 0.02, 0.012, 0.015, 0.03, 0.009, 0.018, 0.08, 0, 0};
	ACE_762x51_SCAR_RecoilProne[] = {0, 0.007, 0.01, 0.013, 0.007, 0.01, 0.03, 0.004, -0.001, 0.13, 0, 0};
	ACE_762x51_SCAR_Recoil_GL[] = {0, 0.01, 0.015, 0.02, 0.012, 0.012, 0.03, 0.007, 0.015, 0.12, 0, 0};
	ACE_762x51_M14_RecoilW[] = {0, 0.012, 0.015, 0.02, 0.012, 0.015, 0.03, 0.008, 0.02, 0.16, 0, 0};
	ACE_762x51_M14_Recoil[] = {0, 0.012, 0.017, 0.02, 0.012, 0.017, 0.1, 0.009, 0.023, 0.17, 0, 0};
	ACE_762x51_FAL_Recoil[] = {0, 0.009, 0.017, 0.02, 0.009, 0.017, 0.03, 0.007, 0.023, 0.16, 0, 0};
	ACE_762x51_G3_Grip_Recoil[] = {0, 0.011, 0.0145, 0.015, 0.011, 0.012, 0.03, 0.008, 0.018, 0.13, 0, 0};
	ACE_127x99_Rifle_Recoil[] = {0, 0.015, 0.02, 0.025, 0.014, 0.02, 0.6, 0, 0};
	ACE_127x99_Rifle_RecoilProne[] = {0, 0.015, 0.001, 0.03, 0.015, -0.002, 0.05, 0.01, 0.005, 0.06, 0, 0};
	ACE_Shotgun_Recoil[] = {0, 0.018, 0.02, 0.04, 0.018, 0.027, 0.03, 0.012, 0.027, 0.17, 0, 0};
	ACE_Shotgun_RecoilProne[] = {0, 0.01, 0.02, 0.013, 0.01, 0.02, 0.09, 0.008, 0.001, 0.14, 0, 0};
	ACE_AT_Recoil[] = {0.1, 0, 0.01, 0.15, 0, 0};
	ACE_GL_Recoil[] = {0, 0.02, 0, 0.05, 0.02, 0.02, 0.03, 0.02, 0.02, 0.2, 0, 0};
	ACE_M32_Recoil[] = {0, 0.02, 0, 0.05, 0.02, 0.02, 0.03, 0.02, 0.02, 0.2, 0, 0};
	ACE_MGun[] = {0, 0.01, 0.025, 0.2, 0.006, 0, 0.4, 0, 0};
	ACE_EmptyRecoil[] = {0, 0, 0};
};

class CfgAmmo {
	class Default;	// External class reference
	
	class ACE_DummyAmmo : Default {
		scope = protected;
		hit = 0.001;
		indirectHit = 0.001;
		indirectHitRange = 0.01;
	};
	class MissileCore;	// External class reference
	class BombCore;	// External class reference
	class LaserBombCore;	// External class reference
	class RocketCore;	// External class reference
	class BulletCore;	// External class reference
	class ShellCore;	// External class reference
	class GrenadeCore;	// External class reference
	class TimeBombCore;	// External class reference
	class PipeBombCore;	// External class reference
	class MineCore;	// External class reference
	class SmokeShellCore;	// External class reference
	class BulletBase;	// External class reference
	class GrenadeBase;	// External class reference
	class ShellBase;	// External class reference
	class RocketBase;	// External class reference
	class MissileBase;	// External class reference
	
	class B_9x18_Ball : BulletBase {
		hit = 6.6;
		ace_hit = 6.6;
		airFriction = -0.001525;
	};
	
	class ACE_B_9x18_S : B_9x18_Ball {
		hit = 6;
		ace_hit = 6;
		visibleFire = 0.2;	// how much is visible when this weapon is fired
		audibleFire = 3;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_9x18_SD : B_9x18_Ball {
		hit = 6;
		ace_hit = 6;
		airFriction = -0.001525;
	};
	
	class B_9x19_Ball : B_9x18_Ball {
		hit = 6.9;
		airFriction = -0.0017;
	};
	
	class ACE_B_9x19_S : B_9x19_Ball {
		hit = 6.5;
		ace_hit = 6;
		visibleFire = 0.05;	// how much is visible when this weapon is fired
		audibleFire = 0.05;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_9x19_SD : B_9x19_Ball {
		hit = 6.5;
		ace_hit = 6.5;
		airFriction = -0.000955;
	};
	
	class B_45ACP_Ball : BulletBase {
		hit = 9;
		ace_hit = 9;
		airFriction = -0.002225;
	};
	
	class ACE_B_1143x23_S : B_45ACP_Ball {
		visibleFire = 0.05;	// how much is visible when this weapon is fired
		audibleFire = 0.05;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_46x30_B : B_9x19_Ball {
		ace_hit = 7;
		hit = 5;
		typicalspeed = 675;
		airfriction = -0.005225;
	};
	
	class ACE_B_46x30_S : ACE_B_46x30_B {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_46x30_SD : ACE_B_46x30_B {
		visibleFire = 0.035;	// how much is visible when this weapon is fired
		audibleFire = 0.035;
		visibleFireTime = 1;	// how long is it visible
		typicalspeed = 320;
	};
	
	class ACE_B_57x28_B : B_9x19_Ball {
		ace_hit = 6;
		hit = 6;
		typicalspeed = 716;
		airfriction = -0.003255;
	};
	
	class ACE_B_57x28_S : ACE_B_57x28_B {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_765x17_Ball : BulletBase {
		hit = 6.3;
		airFriction = -0.0017;
	};
	
	class ACE_Bullet_762x25_B : B_9x19_Ball {
		hit = 7;
		airFriction = -0.004;
		typicalSpeed = 420;
	};
	
	class B_12Gauge_74Slug : BulletBase {
		ace_hit = 15;
		hit = 15;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_slug";
		cost = 5;
		typicalSpeed = 400;
		visibleFire = 18;	// how much is visible when this weapon is fired
		audibleFire = 18;
		airFriction = -0.005;
		caliber = 0.5;
	};
	
	class B_12Gauge_Pellets : BulletBase {
		simulation = "shotSpread";
		ace_hit = 7;
		hit = 7;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "FxCartridge_slug";
		cost = 2;
		typicalSpeed = 400;
		visibleFire = 18;	// how much is visible when this weapon is fired
		audibleFire = 18;
		airFriction = -0.005;
		caliber = 0.5;
	};
	
	class B_545x39_Ball : BulletBase {
		ace_hit = 7;
		deflecting = 20;
		tracerStartTime = 0.06;
	};
	
	class ACE_B_545x39_S : B_545x39_Ball {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_545x39_T : B_545x39_Ball {
		caliber = 0.4;
		tracerScale = 1;
		tracerStartTime = 0.06;
		tracerEndTime = 1.4;
		nvgOnly = 0;
	};
	
	class ACE_B_545x39_EP : B_545x39_Ball {
		hit = 8.3;
		airFriction = -0.00134;
		caliber = 0.75;
	};
	
	class ACE_B_545x39_EP_S : ACE_B_545x39_EP {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_545x39_AP : B_545x39_Ball {
		hit = 8.8;
		airFriction = -0.001314;
		caliber = 1.17;
	};
	
	class ACE_B_545x39_AP_S : ACE_B_545x39_AP {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_556x45_Ball : BulletBase {
		ace_hit = 7.5;
		deflecting = 20;
		tracerStartTime = 0.06;
	};
	
	class ACE_B_556x45_S : B_556x45_Ball {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_556x45_EP : B_556x45_Ball {
		hit = 8.3;
		caliber = 0.75;
	};
	
	class ACE_B_556x45_EP_S : ACE_B_556x45_EP {};
	
	class ACE_B_556x45_T : B_556x45_Ball {
		caliber = 0.4;
		tracerScale = 1;
		tracerStartTime = 0.06;
		tracerEndTime = 1.4;
		nvgOnly = 0;
	};
	
	class ACE_B_556x45_AP : B_556x45_Ball {
		hit = 8.4;
		caliber = 0.9;
	};
	
	class ACE_B_556x45_AP_S : ACE_B_556x45_AP {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_556x45_SB : B_556x45_Ball {
		ace_hit = 7.5;
		hit = 8.5;
		typicalSpeed = 850;
		airFriction = -0.001125;
		visibleFire = 14;	// how much is visible when this weapon is fired
		tracerColor[] = {0, 0, 0, 0};
		tracerColorR[] = {0, 0, 0, 0};
		tracerStartTime = -1;
		caliber = 0.4;
	};
	
	class ACE_B_556x45_SB_S : ACE_B_556x45_SB {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_556x45_DM11 : B_556x45_Ball {};
	
	class ACE_B_556x45_DM11_S : ACE_B_556x45_DM11 {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 6;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_556x45_DM21 : ACE_B_556x45_T {
		tracerEndTime = 1.47;
	};
	
	class ACE_B_556x45_DM31 : ACE_B_556x45_AP {};
	
	class ACE_B_556x45_DM31_S : ACE_B_556x45_AP_S {};
	
	class ACE_B_6x35_B : B_556x45_Ball {
		airfriction = -0.0015;
		typicalspeed = 739;
	};
	
	class ACE_B_65x38_B : B_556x45_Ball {
		ace_hit = 8;
		hit = 9;
		typicalspeed = 800;
		airfriction = -0.00081088;
	};
	
	class ACE_B_68x43_B : B_556x45_Ball {
		ace_hit = 8;
		hit = 9;
		typicalspeed = 800;
		airfriction = -0.0013139;
	};
	
	class B_9x39_SP5 : BulletBase {
		ace_hit = 8;
		hit = 10;
		typicalSpeed = 300;
		airFriction = -0.000305;
		timetolive = 8;
		caliber = 0.7;
		cartridge = "FxCartridge_556";
	};
	
	class ACE_B_9x39_SP5_U : B_9x39_SP5 {
		visibleFire = 10;	// how much is visible when this weapon is fired
		audibleFire = 10;
	};
	
	class ACE_B_9x39_SP6 : B_9x39_SP5 {
		hit = 11;
		airFriction = -0.000325;
		caliber = 0.84;
	};
	
	class ACE_B_9x39_SP6_U : ACE_B_9x39_SP6 {
		visibleFire = 10;	// how much is visible when this weapon is fired
		audibleFire = 10;
	};
	
	class B_762x39_Ball : BulletBase {
		ace_hit = 9;
		airFriction = -0.00144;
	};
	
	class ACE_B_762x39_S : B_762x39_Ball {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 7;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_762x39_T : B_762x39_Ball {
		model = "\ca\Weapons\Data\bullettracer\tracer_green";
		tracerScale = 1.2;
		tracerStartTime = 0.06;
		tracerEndTime = 1.4;
		nvgOnly = 0;
		tracerColorR[] = {0.2, 0.8, 0.1, 0.04};
	};
	
	class ACE_B_762x39_SD : B_762x39_Ball {
		ace_hit = 7;
		hit = 7;
		typicalSpeed = 290;
		airFriction = -0.00055;
		deflecting = 10;
		visibleFire = 0.06;	// how much is visible when this weapon is fired
		audibleFire = 0.06;
		visibleFireTime = 0.5;	// how long is it visible
		tracerColor[] = {0, 0, 0, 0};
		tracerColorR[] = {0, 0, 0, 0};
		tracerStartTime = -1;
	};
	
	class ACE_B_762x39_AP : B_762x39_Ball {
		hit = 10.5;
		typicalSpeed = 730;
		caliber = 1.58;
	};
	
	class ACE_B_762x39_AP_S : ACE_B_762x39_AP {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 7;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_762x51_Ball : BulletBase {
		ace_hit = 12;
		hit = 12;
		typicalSpeed = 750;
		tracerStartTime = 0.06;
		tracerEndTime = 1.8;
		deflecting = 20;
		timetolive = 8;
	};
	
	class ACE_B_762x51_S : B_762x51_Ball {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 8;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_762x51_T : B_762x51_Ball {
		tracerScale = 1.2;
		tracerStartTime = 0.06;
		tracerEndTime = 1.8;
		nvgOnly = 0;
	};
	
	class B_762x51_noTracer : B_762x51_Ball {
		airFriction = -0.0008;
	};
	
	class ACE_B_762x51_SB_S : B_762x51_noTracer {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 8;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_762x51_3RndBurst : B_762x51_Ball {
		cost = 0.4;
		craterEffects = "ImpactEffectsBig";
		explosionEffects = "NoExplosion";
		explosive = 0.1;
		hit = 12;
		tracerStartTime = 0;
	};
	
	class B_86x70_Ball_noTracer : BulletBase {
		ace_hit = 12;
		ace_hit_distance = 100;
		hit = 17;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "";
		airfriction = -0.0005875;
	};
	
	class ACE_B_86x70_T : B_86x70_Ball_noTracer {
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		tracerstarttime = 0.075;
		tracerendtime = 2.0;
		tracerscale = 1.3;
		tracercolor[] = {0.7, 0.7, 0.5, 0.04};
		tracercolorr[] = {0.7, 0.7, 0.5, 0.04};
		nvgOnly = 0;
	};
	
	class ACE_B_86x70_SB : B_762x51_noTracer {
		ace_hit = 12;
		ace_hit_distance = 100;
		hit = 17;
		typicalspeed = 750;
		airfriction = -0.0005875;
	};
	
	class ACE_B_104x77_SB : B_762x51_noTracer {
		ace_hit = 18;
		ace_hit_distance = 100;
		hit = 22;
		typicalspeed = 750;
		airfriction = -0.0003973;
	};
	
	class ACE_B_106x83_SB : B_762x51_noTracer {
		ace_hit = 15;
		ace_hit_distance = 100;
		hit = 22;
		typicalspeed = 750;
		airfriction = -0.0004155;
	};
	
	class B_762x54_Ball : BulletBase {
		ace_hit = 12.5;
		hit = 12.5;
		typicalSpeed = 750;
		airFriction = -0.00125;
		tracerStartTime = 0.06;
		tracerEndTime = 1.7;
		timetolive = 10;
		deflecting = 20;
	};
	
	class ACE_B_762x54_S : B_762x54_Ball {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 8;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class ACE_B_762x54_T : B_762x54_Ball {
		tracerScale = 1.2;
		tracerStartTime = 0.06;
		tracerEndTime = 1.7;
		nvgOnly = 0;
	};
	
	class B_762x54_noTracer : B_762x54_Ball {
		airFriction = -0.00099;
	};
	
	class ACE_B_762x54_SB_S : B_762x54_noTracer {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 8;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_303_Ball : BulletBase {
		hit = 13.5;
		ace_hit = 13.5;
		airFriction = -0.00085;
		cartridge = "";
		airLock = false;
	};
	
	class ACE_B_77x56_T : B_303_Ball {
		model = "\ca\Weapons\Data\bullettracer\tracer_yellow";
		tracerScale = 1.2;
		tracerStartTime = 0.06;
		tracerEndTime = 1.7;
		nvgOnly = 0;
		airFriction = -0.00125;
	};
	
	class B_127x99_Ball : BulletBase {
		ace_hit = 17;
		ace_hit_distance = 100;
		hit = 22;
		indirectHit = 1.3;
		indirectHitRange = 0.01;
		ace_incendiary = 0;
		airFriction = -0.00056;
		timetolive = 8;
		tracerStartTime = 0.06;
		tracerEndTime = 6;
		deflecting = 20;
		caliber = 3;
		airLock = true;
		cost = 12;
	};
	
	class ACE_B_127x99_Raufoss : B_127x99_Ball {
		ace_hit = 21;
		ace_incendiary = 1;
		hit = 28;
		deflecting = 5;
		caliber = 3.5;
	};
	
	class ACE_B_127x99_T : B_127x99_Ball {
		hit = 19;
		tracerScale = 1.9;
		tracerStartTime = 0.06;
		tracerEndTime = 6;
		nvgOnly = 0;
	};
	
	class B_127x99_Ball_noTracer : B_127x99_Ball {
		hit = 19;
		airFriction = -0.00056;
	};
	
	class ACE_B_127x99_SB_S : B_127x99_Ball_noTracer {
		visibleFire = 0.5;	// how much is visible when this weapon is fired
		audibleFire = 12;
		visibleFireTime = 1;	// how long is it visible
	};
	
	class B_127x99_Ball_noTracer_BAF : B_127x99_Ball_noTracer {
		hit = 19;
	};
	class B_127x107_Ball;	// External class reference
	
	class ACE_B_127x108_T : B_127x107_Ball {
		ace_hit = 18;
		ace_hit_distance = 100;
		ace_mass = 4.4;
		hit = 24;
		muzzleEffect = "BIS_Effects_HeavySniper";
	};
	
	class B_127x108_Ball : BulletBase {
		ace_hit = 20;
		ace_hit_distance = 100;
		ace_mass = 4.82;
		hit = 26;
		ace_incendiary = 1;
		airFriction = -0.0006;
		tracerColor[] = {0, 0, 0, 0};
		tracerColorR[] = {0, 0, 0, 0};
		tracerStartTime = -1;
		timetolive = 8;
		deflecting = 20;
		caliber = 3;
	};
	
	class ACE_Bullet_25x59_HEDP : B_127x99_Ball_noTracer {
		model = "\x\ace\addons\m_wep_magazines\ace_m433_armed.p3d";
		ace_windcoef = 0.15;
		ace_hit = 25;
		ace_heat = 1;
		ace_incendiary = 1;
		hit = 65;
		indirectHit = 12;
		indirectHitRange = 2;
		explosive = true;
		airFriction = -0.00084;
		typicalSpeed = 792;
		deflecting = 1;
		timeToLive = 15;
		soundHitAll[] = {"Ca\sounds\Weapons\explosions\AZP85_explosion1", 3.16228, 1, 500};
		hitGroundSoft[] = {"soundHitAll", 1};
		hitGroundHard[] = {"soundHitAll", 1};
		hitMan[] = {"soundHitAll", 1};
		hitArmor[] = {"soundHitAll", 1};
		hitIron[] = {"soundHitAll", 1};
		hitBuilding[] = {"soundHitAll", 1};
		hitFoliage[] = {"soundHitAll", 1};
		hitWood[] = {"soundHitAll", 1};
		hitGlass[] = {"soundHitAll", 1};
		hitGlassArmored[] = {"soundHitAll", 1};
		hitConcrete[] = {"soundHitAll", 1};
		hitRubber[] = {"soundHitAll", 1};
		hitPlastic[] = {"soundHitAll", 1};
		hitDefault[] = {"soundHitAll", 1};
		hitMetal[] = {"soundHitAll", 1};
		hitMetalplate[] = {"soundHitAll", 1};
		craterEffects = "ExploAmmoCrater";
		explosionEffects = "ExploAmmoExplosion";
		cost = 4;
		tracerScale = 0.7;
		tracerStartTime = 0;
		tracerEndTime = 18;
	};
	
	class Grenade : Default {
		hit = 20;
		indirectHit = 12;
		indirectHitRange = 4;
	};
	
	class GrenadeHand : Grenade {
		fuseDistance = 0;
		caliber = 2;
		model = "\x\ace\addons\m_wep_magazines\ace_rgo_armed.p3d";
		hiddenSelections[] = {"PinPulled"};
		indirectHit = 10;
		indirectHitRange = 6;
		deflectionSlowDown = 0.3;
		deflecting = 15;
	};
	
	class GrenadeHandTimedWest : GrenadeHand {
		model = "\x\ace\addons\m_wep_magazines\ace_m67_armed.p3d";
		indirectHit = 12;
		indirectHitRange = 3.5;
	};
	
	class GrenadeHandTimedEast : GrenadeHandTimedWest {
		model = "\x\ace\addons\m_wep_magazines\ace_rgd5_armed.p3d";
		indirectHit = 11;
		indirectHitRange = 3.5;
	};
	
	class GrenadeHand_stone : GrenadeHand {
		caliber = 1;
		explosive = true;
		deflecting = 90;
		explosionTime = 100;
	};
	
	class ACE_DM51 : GrenadeHandTimedWest {
		model = "\x\ace\addons\m_wep_magazines\ace_dm51_armed.p3d";
		indirectHit = 6;
		indirectHitRange = 3.5;
	};
	
	class ACE_DM51A1 : GrenadeHandTimedWest {
		model = "\x\ace\addons\m_wep_magazines\ace_dm51a1_armed.p3d";
		indirectHit = 14;
		indirectHitRange = 7;
	};
	
	class SmokeShell : GrenadeHand {
		model = "\x\ace\addons\m_wep_magazines\ANM8_white_armed.p3d";
		soundFly[] = {"\x\ace\addons\c_weapon\data\sound\shhhhhhh.wss", db-80, 1, 20};
	};
	
	class SmokeShellRed : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\M18_red_armed.p3d";
	};
	
	class SmokeShellGreen : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\M18_green_armed.p3d";
	};
	
	class SmokeShellYellow : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\M18_yellow_armed.p3d";
	};
	
	class SmokeShellPurple : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\M18_violet_armed.p3d";
	};
	
	class SmokeShellBlue : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\M18_blue_armed.p3d";
	};
	
	class SmokeShellOrange : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\M18_orange_armed.p3d";
	};
	
	class ACE_RDG2 : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\ace_rdg2_armed.p3d";
	};
	
	class ACE_RDGM : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\ace_rdgm_armed.p3d";
	};
	
	class ACE_DM25 : SmokeShell {
		timeToLive = 80;
		explosionTime = 1.5;
		model = "\x\ace\addons\m_wep_magazines\ace_dm25_armed.p3d";
	};
	
	class ACE_DM31 : SmokeShellGreen {
		timeToLive = 60;
		explosionTime = 2;
		model = "\x\ace\addons\m_wep_magazines\ace_dm3x_armed.p3d";
	};
	
	class ACE_DM32 : SmokeShellOrange {
		timeToLive = 60;
		explosionTime = 2;
		model = "\x\ace\addons\m_wep_magazines\ace_dm3x_armed.p3d";
	};
	
	class ACE_DM33 : SmokeShellRed {
		timeToLive = 60;
		explosionTime = 2;
		model = "\x\ace\addons\m_wep_magazines\ace_dm3x_armed.p3d";
	};
	
	class ACE_DM34 : SmokeShellPurple {
		timeToLive = 60;
		explosionTime = 2;
		model = "\x\ace\addons\m_wep_magazines\ace_dm3x_armed.p3d";
	};
	
	class ACE_DM36 : SmokeShellYellow {
		timeToLive = 60;
		explosionTime = 2;
		model = "\x\ace\addons\m_wep_magazines\ace_dm3x_armed.p3d";
	};
	
	class G_40mm_HE : GrenadeBase {
		airFriction = -0.0005;
		model = "\x\ace\addons\m_wep_magazines\ace_m433_armed.p3d";
		explosionEffects = "ACE_GrenadeExplosion_M433HEDP";
		visibleFire = 8;	// how much is visible when this weapon is fired
		audibleFire = 4;
		visibleFireTime = 3;	// how long is it visible
		indirectHitRange = 4;
	};
	
	class G_30mm_HE : GrenadeBase {
		model = "\x\ace\addons\m_wep_magazines\ace_vog25_armed.p3d";
		visibleFire = 8;	// how much is visible when this weapon is fired
		audibleFire = 4;
		visibleFireTime = 3;	// how long is it visible
	};
	
	class ACE_G40mm_HE_VOG25P : G_40mm_HE {
		model = "\x\ace\addons\m_wep_magazines\ace_vog25p_armed.p3d";
		explosionEffects = "ACE_VOG25P_Explosion";
		indirectHitRange = 7;
	};
	
	class ACE_G_40mm_HEDP : G_40mm_HE {
		model = "\x\ace\addons\m_wep_magazines\ace_m433_armed.p3d";
		explosionEffects = "ACE_GrenadeExplosion_M433HEDP";
		hit = 35;
		ace_hit = 50;
		ace_heat = 1;
		indirectHitRange = 3;
	};
	
	class ACE_G_40mm_HE : ACE_G_40mm_HEDP {
		hit = 35;
		ace_hit = 10;
		ace_heat = 0;
		indirectHitRange = 4;
	};
	
	class ACE_G_40mm_Practice : ACE_G_40mm_HE {
		hit = 1;
		indirectHit = 0;
		ace_hit = 0;
		CraterEffects = "NoCrater";
		explosionEffects = "ACE_GrenadeExplosion_Practice";
		soundHit[] = {"", 1.16228, 1, 500};
	};
	
	class ACE_G_40mm_HEDP_DM111 : ACE_G_40mm_HEDP {
		model = "\x\ace\addons\m_wep_magazines\ace_m433_armed.p3d";
		explosionEffects = "ACE_GrenadeExplosion_M433HEDP";
		hit = 35;
		ace_hit = 10;
		ace_heat = 0;
		tracerScale = 0.7;
		tracerStartTime = 0.06;
		tracerEndTime = 6.06;
		tracersEvery = 1;
		lastRoundsTracer = 1;
		simulation = "shotBullet";
		ACE_FRAG_MULTIPLIER = 1.6;
		indirectHitRange = 5;
	};
	
	class ACE_G_40mm_HEDP_DM42 : ACE_G_40mm_HEDP_DM111 {
		hit = 35;
		ace_hit = 80;
		ace_heat = 1;
		ACE_FRAG_MULTIPLIER = 1.2;
	};
	
	class ACE_G_40mm_HEDP_DM111DM42 : ACE_G_40mm_HEDP_DM111 {
		hit = 35;
		ace_hit = 30;
		ace_heat = 1;
	};
	
	class G_40mm_Smoke : SmokeShell {
		model = "\x\ace\addons\m_wep_magazines\ace_groundmarker_armed.p3d";
		deflecting = 5;
		visibleFire = 8;	// how much is visible when this weapon is fired
		audibleFire = 4;
		visibleFireTime = 3;	// how long is it visible
	};
	
	class ACE_G_40mmSmokePurple : G_40mm_Smoke {
		smokeColor[] = {0.6641, 0.2188, 0.7344, 1};
	};
	
	class ACE_VG40_Smoke : G_40mm_Smoke {
		model = "\x\ace\addons\m_wep_magazines\ace_vg40md_armed.p3d";
	};
	
	class ACE_VG40_SmokeRed : ACE_VG40_Smoke {
		smokeColor[] = {0.8438, 0.2383, 0.1953, 1};
	};
	
	class ACE_VG40_SmokeGreen : ACE_VG40_Smoke {
		smokeColor[] = {0.3125, 0.6758, 0.2891, 1};
	};
	
	class ACE_VG40_SmokeYellow : ACE_VG40_Smoke {
		smokeColor[] = {0.9883, 0.9606, 0.1719, 1};
	};
	
	class FlareCore : GrenadeCore {
		timeToLive = 45;
		hit = 10;
		indirectHit = 0;
		indirectHitRange = 0;
		visibleFire = 8;	// how much is visible when this weapon is fired
		audibleFire = 4;
		visibleFireTime = 3;	// how long is it visible
	};
	
	class FlareBase : FlareCore {
		timeToLive = 45;
		hit = 10;
		indirectHit = 0;
		indirectHitRange = 0;
	};
	class F_40mm_White;	// External class reference
	
	class ACE_F_40mm_IR : F_40mm_White {
		lightColor[] = {0.05, 0.05, 0.05, 0};
	};
	
	class ACE_StarShell_Base : FlareBase {
		model = "\x\ace\addons\m_wep_magazines\ace_starcluster_armed.p3d";
		timeToLive = 10;
		brightness = 1.8;
		size = 0.35;
		deflecting = 30;
	};
	
	class ACE_SS_White : ACE_StarShell_Base {
		lightColor[] = {0.5, 0.5, 0.5, 0};
	};
	
	class ACE_SS_Green : ACE_SS_White {
		lightColor[] = {0.25, 0.5, 0.25, 0};
	};
	
	class ACE_SS_Red : ACE_SS_White {
		lightColor[] = {0.5, 0.25, 0.25, 0};
	};
	
	class ACE_SS_Yellow : ACE_SS_White {
		lightColor[] = {0.5, 0.5, 0.25, 0};
	};
	
	class Mine : MineCore {
		indirectHit = 700;
		indirectHitRange = 7;
	};
	
	class R_M136_AT : RocketBase {
		ace_hit = 420;
		hit = 420;
		indirectHit = 25;
		indirectHitRange = 3;
		timeToLive = 10;
		maxSpeed = 170;	// max speed on level road, km/h
		sideAirFriction = 0.3;
		initTime = 0;
		thrustTime = 0.01;
		thrust = 1;
		fusedistance = 10;
		irlock = true;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	
	class ACE_R_M136_CSRS : R_M136_AT {
		fuseDistance = 15;
	};
	
	class ACE_R_M136_CSHP : ACE_R_M136_CSRS {
		fuseDistance = 5;
		ace_hit = 500;
		hit = 500;
		indirectHit = 20;
	};
	
	class R_SMAW_HEDP : RocketBase {
		ace_hit = 60;
		hit = 300;
		indirectHit = 30;
		indirectHitRange = 5;
		inittime = 0;
		thrustTime = 0.01;
		thrust = 1;
		maxSpeed = 220;	// max speed on level road, km/h
		sideAirFriction = 0.3;
		fusedistance = 10;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	
	class R_SMAW_HEAA : R_SMAW_HEDP {
		ace_hit = 530;
		hit = 560;
		indirectHit = 25;
		indirectHitRange = 3;
		irlock = true;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	
	class ACE_R_SMAW_NE : R_SMAW_HEDP {
		ace_hit = 30;
		hit = 75;
		indirectHit = 70;
		indirectHitRange = 5;
		ace_thermobaric = 1;
		ace_heat = 0;
		craterEffects = "ACE_FAE_Crater";
		explosionEffects = "ACE_FAE_Explosion";
		soundDefault1[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit1.wss", 44.6684, 1, 4000};
		soundDefault2[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit2.wss", 44.6684, 1, 4000};
		soundDefault3[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit3.wss", 44.6684, 1, 4000};
		soundMetal1[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit1.wss", 44.6684, 1, 4000};
		soundMetal2[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit2.wss", 44.6684, 1, 4000};
		soundMetal3[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit3.wss", 44.6684, 1, 4000};
		hitGroundSoft[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitGroundHard[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitMan[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitArmor[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		hitIron[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		hitBuilding[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitFoliage[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitWood[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitGlass[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitGlassArmored[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitConcrete[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitRubber[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitPlastic[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitDefault[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitMetal[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		hitMetalplate[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		ACE_FRAG_SKIP = 1;
	};
	
	class R_PG7V_AT : RocketBase {
		ace_hit = 260;
		hit = 260;
		indirecthit = 25;
		indirectHitRange = 3;
		timetolive = 5;
		maxspeed = 290;	// max speed on level road, km/h
		sideAirFriction = 0.7;
		initTime = 0.1;
		thrustTime = 0.5;
		thrust = 510;
		fusedistance = 10;
		airLock = true;
		irLock = false;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	
	class ACE_R_PG7VM_AT : R_PG7V_AT {
		ace_hit = 330;
		hit = 330;
		model = "\x\ace\addons\m_wep_rpg7\ACE_PG7VM.p3d";
		ACE_FRAG_FORCE = 1;
	};
	
	class R_PG7VL_AT : R_PG7V_AT {
		ace_hit = 500;
		hit = 500;
		indirectHitRange = 3.5;
		maxspeed = 195;	// max speed on level road, km/h
		thrust = 285;
		sideAirFriction = 0.6;
		airLock = true;
		irLock = true;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
		ACE_FRAG_FORCE = 1;
	};
	
	class R_PG7VR_AT : R_PG7V_AT {
		ace_hit = 650;
		hit = 780;
		indirecthit = 25;
		indirectHitRange = 4;
		maxSpeed = 110;	// max speed on level road, km/h
		initTime = 0.15;
		thrust = 70;
		sideAirFriction = 0.5;
		airLock = false;
		irLock = true;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	
	class ACE_R_TBG7V_AT : R_PG7VR_AT {
		ace_hit = 40;
		ace_tandemheat = 0;
		ace_thermobaric = 1;
		hit = 95;
		indirecthit = 90;
		indirectHitRange = 5;
		model = "\x\ace\addons\m_wep_rpg7\ACE_TBG7V.p3d";
		irlock = false;
		craterEffects = "ACE_FAE_Crater";
		explosionEffects = "ACE_FAE_Explosion";
		soundDefault1[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit1.wss", 44.6684, 1, 4000};
		soundDefault2[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit2.wss", 44.6684, 1, 4000};
		soundDefault3[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit3.wss", 44.6684, 1, 4000};
		soundMetal1[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit1.wss", 44.6684, 1, 4000};
		soundMetal2[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit2.wss", 44.6684, 1, 4000};
		soundMetal3[] = {"\x\ace\addons\c_weapon\data\sound\fae_hit3.wss", 44.6684, 1, 4000};
		hitGroundSoft[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitGroundHard[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitMan[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitArmor[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		hitIron[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		hitBuilding[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitFoliage[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitWood[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitGlass[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitGlassArmored[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitConcrete[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitRubber[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitPlastic[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitDefault[] = {"soundDefault1", 0.33, "soundDefault2", 0.33, "soundDefault3", 0.33};
		hitMetal[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		hitMetalplate[] = {"soundMetal1", 0.33, "soundMetal2", 0.33, "soundMetal3", 0.33};
		ACE_FRAG_SKIP = 1;
	};
	
	class R_OG7_AT : R_PG7V_AT {
		ace_hit = 10;
		hit = 20;
		indirecthit = 20;
		indirectHitRange = 6;
		timetolive = 5;
		sideAirFriction = 0.05;
		initTime = 0;
		thrustTime = 0.01;
		thrust = 1;
		maxspeed = 76;	// max speed on level road, km/h
		airLock = false;
		irLock = false;
		ACE_FRAG_FORCE = 1;
	};
	
	class R_RPG18_AT : RocketBase {
		ace_hit = 375;
		hit = 375;
		indirecthit = 20;
		indirectHitRange = 2.7;
		timetolive = 5;
		sideAirFriction = 0.05;
		initTime = 0;
		thrustTime = 0.01;
		thrust = 1;
		maxspeed = 84;	// max speed on level road, km/h
		fusedistance = 10;
		irlock = true;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	
	class M_Javelin_AT : MissileBase {
		ace_hit = 800;
		hit = 960;
		indirectHit = 25;
		indirectHitRange = 3.2;
		maneuvrability = 12;
		maxSpeed = 217;	// max speed on level road, km/h
		initTime = 0.35;
		thrustTime = 3.5;
		thrust = 66.95;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	
	class ACE_M_Javelin_AT_Direct : M_Javelin_AT {};
	
	class M_NLAW_AT : MissileBase {
		effectsmissile = "missile4";
		ace_hit = 150;
		hit = 100;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	
	class R_MEEWS_HEDP : R_SMAW_HEDP {
		ace_hit = 150;
		initTime = 0.05;
		audibleFire = 65;
		hit = 150;
		indirectHit = 30;
		indirectHitRange = 4;
		thrustTime = 0;
		thrust = 0;
		sideAirFriction = 0.1;
		maxSpeed = 130;	// max speed on level road, km/h
		explosionEffects = "GrenadeExplosion";
	};
	
	class ACE_R_MEEWS_HE : R_MEEWS_HEDP {
		ace_hit = 20;
		hit = 105;
		indirectHit = 72;
		indirectHitRange = 8;
		thrustTime = 0;
		thrust = 0.01;
		cost = 100;
		sideAirFriction = 0.1;
		maxSpeed = 130;	// max speed on level road, km/h
		ace_heat = 0;
		explosioneffects = "ATRocketExplosion";
		CraterEffects = "ATMissileCrater";
	};
	
	class R_MEEWS_HEAT : R_SMAW_HEAA {
		ace_hit = 550;
		hit = 660;
		indirectHit = 34;
		indirectHitRange = 2,1;
		initTime = 0.05;
		thrustTime = 0.5;
		thrust = 295;
		audibleFire = 65;
		maxSpeed = 330;	// max speed on level road, km/h
		ace_tandemheat = 1;
	};
	class M_TOW_AT;	// External class reference
	
	class M_47_AT_EP1 : M_TOW_AT {
		airLock = false;
		irLock = true;
		laserLock = false;
		ace_hit = 450;
		hit = 450;
		indirectHit = 22;
		indirectHitRange = 3.5;
		typicalSpeed = 100;
		fuseDistance = 65;
		model = "\x\ace\addons\m_wep_dragon\dragon.p3d";
		maneuvrability = 1;
		sideAirFriction = 0.1;
		thrust = 62.75;
		thrustTime = 1.5;
		maxSpeed = 100;	// max speed on level road, km/h
		six_tracerenable = 0;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
};

class CfgMagazines {
	class Default;	// External class reference
	class CA_Magazine;	// External class reference
	
	class CA_LauncherMagazine : CA_Magazine {
		type = 512;
	};
	
	class 8Rnd_9x18_Makarov : CA_Magazine {
		model = "\x\ace\addons\m_wep_magazines\8Rnd_9x18_Makarov.p3d";
	};
	
	class 15Rnd_9x19_M9 : CA_Magazine {
		initSpeed = 365;
		model = "\x\ace\addons\m_wep_magazines\15Rnd_9x19_M9.p3d";
	};
	
	class ACE_15Rnd_9x19_S_M9 : 15Rnd_9x19_M9 {
		ammo = "ACE_B_9x19_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 15Rnd_9x19_M9SD : 15Rnd_9x19_M9 {
		initSpeed = 278;
		displayNameShort = "SD";
	};
	
	class 10Rnd_9x19_Compact : 15Rnd_9x19_M9 {
		displayName = $STR_ACE_MDN_14RND_CZ75;
		descriptionShort = $STR_ACE_DSS_14RND_9X19_CZ75;
		initSpeed = 340;
		count = 14;
	};
	
	class 18Rnd_9x19_Phantom : 15Rnd_9x19_M9 {
		displayName = $STR_ACE_MDN_18RND_CZ75;
		initSpeed = 365;
	};
	
	class ACE_18Rnd_9x19_S_Phantom : 18Rnd_9x19_Phantom {
		ammo = "ACE_B_9x19_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_16Rnd_9x19_CZ75 : 18Rnd_9x19_Phantom {
		displayName = $STR_ACE_MDN_16RND_CZ75;
		descriptionShort = $STR_ACE_DSS_16RND_9X19_CZ75;
		count = 16;
	};
	
	class ACE_16Rnd_9x19_S_CZ75 : ACE_16Rnd_9x19_CZ75 {
		ammo = "ACE_B_9x19_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 18Rnd_9x19_PhantomSD : 15Rnd_9x19_M9SD {
		displayName = $STR_ACE_MDN_18RND_CZ75SD;
	};
	
	class ACE_13Rnd_9x19_L9A1 : 15Rnd_9x19_M9 {
		count = 13;
		displayName = $STR_ACE_MDN_13RND_9X19_L9A1;
		descriptionShort = $STR_ACE_DSS_13RND_9X19_L9A1;
	};
	
	class 30Rnd_9x19_UZI_SD : CA_Magazine {
		count = 32;
		displayName = $STR_ACE_MDN_32RND_9X19_UZI_SD;
		displayNameShort = "SD";
		descriptionShort = $STR_ACE_DSS_32RND_9X19_UZI_SD;
	};
	
	class 30Rnd_9x19_UZI : CA_Magazine {
		count = 32;
		displayName = $STR_ACE_MDN_32RND_9X19_UZI;
		descriptionShort = $STR_ACE_DSS_32RND_9X19_UZI;
		initSpeed = 350;
	};
	
	class ACE_30Rnd_9x19_S_UZI : 30Rnd_9x19_UZI {
		ammo = "ACE_B_9x19_S";
		
		class Armory {
			disabled = 1;
		};
	};
	class 17Rnd_9x19_glock17;	// External class reference
	
	class ACE_33Rnd_9x19_G18 : 17Rnd_9x19_glock17 {
		displayName = "$STR_ACE_MDN_33Rnd_9x19_G18";
		count = 33;
		initSpeed = 365;
		descriptionShort = $STR_ACE_DSS_33RND_9X19_G18;
	};
	
	class 7Rnd_45ACP_1911 : CA_Magazine {
		model = "\x\ace\addons\m_wep_magazines\7Rnd_45ACP_1911.p3d";
		initspeed = 259;
	};
	
	class 30Rnd_9x19_MP5 : CA_Magazine {
		displayName = $STR_ACE_MDN_30RND_9X19_MP5;
		model = "\x\ace\addons\m_wep_magazines\30Rnd_9x19_MP5";
	};
	
	class ACE_30Rnd_9x19_S_MP5 : 30Rnd_9x19_MP5 {
		ammo = "ACE_B_9x19_S";
		initSpeed = 320;
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_9x19_MP5SD : CA_Magazine {
		displayName = $STR_ACE_MDN_30RND_9X19_MP5;
		initSpeed = 302;
		displayNameShort = "SD";
	};
	
	class 20Rnd_9x19_EVO : 30Rnd_9x19_MP5 {
		displayName = $STR_ACE_MDN_30RND_9X19_EVO;
		descriptionShort = $STR_ACE_DSS_30RND_9X19_EVO;
		initspeed = 370;
		count = 30;
	};
	
	class ACE_30Rnd_9x19_S_EVO : 20Rnd_9x19_EVO {
		ammo = "ACE_B_9x19_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 20Rnd_9x19_EVOSD : 30Rnd_9x19_MP5SD {
		displayName = $STR_ACE_MDN_30RND_9X19_EVOSD;
		descriptionShort = $STR_ACE_DSS_30RND_9X19_EVO;
		count = 30;
	};
	class 64Rnd_9x19_Bizon;	// External class reference
	
	class ACE_64Rnd_9x19_S_Bizon : 64Rnd_9x19_Bizon {
		ammo = "ACE_B_9x18_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_25Rnd_1143x23_B_UMP45 : 30Rnd_9x19_MP5 {
		displayName = "$STR_ACE_MDN_25Rnd_1143x23_B_UMP45";
		ammo = "B_45ACP_Ball";
		initSpeed = 260;
		count = 25;
		descriptionShort = $STR_ACE_DSS_25RND_1143X23_B_UMP45;
	};
	
	class ACE_25Rnd_1143x23_S_UMP45 : ACE_25Rnd_1143x23_B_UMP45 {
		ammo = "ACE_B_1143x23_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_30Rnd_1143x23_B_M3 : ACE_25Rnd_1143x23_B_UMP45 {
		count = 30;
		displayName = "$STR_ACE_MDN_30Rnd_1143x23_B_M3";
		descriptionShort = $STR_ACE_DSS_30RND_1143X23_B_M3;
		picture = "\Ca\weapons_e\Data\Icons\m_uzi_CA.paa";
	};
	
	class ACE_40Rnd_B_46x30_MP7 : 30Rnd_9x19_MP5 {
		displayName = $STR_ACE_MDN_40RND_B_46X30_MP7;
		count = 40;
		ammo = "ACE_B_46x30_B";
		descriptionShort = $STR_ACE_DSS_40RND_B_46X30_MP7;
		initspeed = 690;
	};
	
	class ACE_40Rnd_S_46x30_MP7 : ACE_40Rnd_B_46x30_MP7 {
		ammo = "ACE_B_46x30_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_545x39_AK : CA_Magazine {
		displayName = $STR_ACE_MDN_30RND_545X39_AK;
		model = "\x\ace\addons\m_wep_magazines\30Rnd_545x39_AK.p3d";
	};
	
	class ACE_30Rnd_545x39_S_AK : 30Rnd_545x39_AK {
		ammo = "ACE_B_545x39_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_545x39_AKSD : 30Rnd_545x39_AK {
		displayName = $STR_ACE_MDN_30RND_545X39_AKSD;
		displayNameShort = "SD";
	};
	
	class ACE_30Rnd_545x39_T_AK : 30Rnd_545x39_AK {
		displayName = $STR_ACE_MDN_30RND_545X39_T_AK;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_545x39_T";
		tracersEvery = 1;
	};
	
	class ACE_30Rnd_545x39_EP_AK : 30Rnd_545x39_AK {
		displayName = $STR_ACE_MDN_30RND_545X39_EP_AK;
		displayNameShort = 7N10;
		descriptionShort = $STR_ACE_DSS_30RND_545X39_EP_AK;
		ammo = "ACE_B_545x39_EP";
	};
	
	class ACE_30Rnd_545x39_EP_S_AK : ACE_30Rnd_545x39_EP_AK {
		ammo = "ACE_B_545x39_EP_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_30Rnd_545x39_AP_AK : 30Rnd_545x39_AK {
		displayName = $STR_ACE_MDN_30RND_545X39_AP_AK;
		displayNameShort = 7N22;
		descriptionShort = $STR_ACE_DSS_30RND_545X39_AP_AK;
		ammo = "ACE_B_545x39_AP";
	};
	
	class ACE_30Rnd_545x39_AP_S_AK : ACE_30Rnd_545x39_AP_AK {
		ammo = "ACE_B_545x39_AP_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_45Rnd_545x39_B_AK : 30Rnd_545x39_AK {
		displayName = $STR_ACE_MDN_45RND_545X39_B_AK;
		descriptionShort = $STR_ACE_DSS_45RND_545X39_B_AK;
		picture = "\x\ace\addons\c_weapon\data\equip\m_rpk74_ca.paa";
		ammo = "ACE_B_545x39_T";
		tracersEvery = 5;
		count = 45;
	};
	
	class ACE_45Rnd_545x39_S_AK : ACE_45Rnd_545x39_B_AK {
		ammo = "ACE_B_545x39_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_45Rnd_545x39_EP_AK : ACE_45Rnd_545x39_B_AK {
		displayName = $STR_ACE_MDN_45RND_545X39_EP_AK;
		displayNameShort = 7N10;
		descriptionShort = $STR_ACE_DSS_45RND_545X39_EP_AK;
		ammo = "ACE_B_545x39_EP";
		tracersEvery = 0;
	};
	
	class ACE_45Rnd_545x39_EP_S_AK : ACE_45Rnd_545x39_EP_AK {
		ammo = "ACE_B_545x39_EP_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_45Rnd_545x39_AP_AK : ACE_45Rnd_545x39_B_AK {
		displayName = $STR_ACE_MDN_45RND_545X39_AP_AK;
		displayNameShort = 7N22;
		descriptionShort = $STR_ACE_DSS_45RND_545X39_AP_AK;
		ammo = "ACE_B_545x39_AP";
		tracersEvery = 0;
	};
	
	class ACE_45Rnd_545x39_AP_S_AK : ACE_45Rnd_545x39_AP_AK {
		ammo = "ACE_B_545x39_AP_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_762x39_AK47 : CA_Magazine {
		displayName = $STR_ACE_MDN_30RND_762X39_AK47;
		model = "\x\ace\addons\m_wep_magazines\30Rnd_762x39_AK47.p3d";
	};
	
	class ACE_30Rnd_762x39_S_AK47 : 30Rnd_762x39_AK47 {
		ammo = "ACE_B_762x39_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_30Rnd_762x39_T_AK47 : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_30RND_762X39_T_AK47;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x39_T";
		tracersEvery = 1;
	};
	
	class ACE_40Rnd_762x39_B_AK47 : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_40RND_762X39_B_AK47;
		count = 40;
	};
	
	class ACE_40Rnd_762x39_S_AK47 : ACE_40Rnd_762x39_B_AK47 {
		ammo = "ACE_B_762x39_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_40Rnd_762x39_T_AK47 : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_40RND_762X39_T_AK47;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x39_T";
		tracersEvery = 1;
		count = 40;
	};
	
	class ACE_75Rnd_762x39_B_AK47 : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_75RND_762X39_B_AK47;
		picture = "\x\ace\addons\c_weapon\data\equip\m_rpk_ca.paa";
		ammo = "ACE_B_762x39_T";
		tracersEvery = 3;
		count = 75;
	};
	
	class ACE_75Rnd_762x39_S_AK47 : ACE_75Rnd_762x39_B_AK47 {
		ammo = "ACE_B_762x39_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_75Rnd_762x39_SD_AK47 : ACE_75Rnd_762x39_B_AK47 {
		displayName = $STR_ACE_MDN_75RND_762X39_SD_AK47;
		ammo = "ACE_B_762x39_SD";
		tracersEvery = 0;
		initspeed = 290;
		displayNameShort = "SD";
	};
	
	class ACE_30Rnd_762x39_SD_AK47 : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_30RND_762X39_SD_AK47;
		ammo = "ACE_B_762x39_SD";
		initspeed = 290;
		tracersEvery = 0;
		displayNameShort = "SD";
	};
	
	class ACE_30Rnd_762x39_AP_AK47 : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_30RND_762X39_AP_AK47;
		displayNameShort = 7N23;
		descriptionShort = "$STR_ACE_DSS_30Rnd_762x39_AP_AK47";
		ammo = "ACE_B_762x39_AP";
		initspeed = 730;
	};
	
	class ACE_30Rnd_762x39_AP_S_AK47 : ACE_30Rnd_762x39_AP_AK47 {
		ammo = "ACE_B_762x39_AP_S";
	};
	
	class ACE_40Rnd_762x39_AP_AK47 : ACE_40Rnd_762x39_B_AK47 {
		displayName = $STR_ACE_MDN_40RND_762X39_AP_AK47;
		displayNameShort = 7N23;
		descriptionShort = "$STR_ACE_DSS_40Rnd_762x39_AP_AK47";
		ammo = "ACE_B_762x39_AP";
		initspeed = 730;
	};
	
	class ACE_40Rnd_762x39_AP_S_AK47 : ACE_40Rnd_762x39_AP_AK47 {
		ammo = "ACE_B_762x39_AP_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_762x39_SA58 : CA_Magazine {
		displayName = $STR_ACE_MDN_30RND_762X39_SA58;
	};
	
	class ACE_30Rnd_762x39_T_SA58 : 30Rnd_762x39_SA58 {
		displayName = $STR_ACE_MDN_30RND_762X39_T_SA58;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x39_T";
		tracersEvery = 1;
	};
	
	class 20Rnd_556x45_Stanag : CA_Magazine {
		displayName = $STR_ACE_MDN_20RND_556X45_STANAG;
		displayNameShort = "Mk262";
		model = "\x\ace\addons\m_wep_magazines\20Rnd_556x45_Stanag.p3d";
		ammo = "ACE_B_556x45_SB";
		initSpeed = 850;
		tracersEvery = 0;
	};
	
	class ACE_20Rnd_556x45_S_Stanag : 20Rnd_556x45_Stanag {
		ammo = "ACE_B_556x45_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_556x45_Stanag : 20Rnd_556x45_Stanag {
		ammo = "B_556x45_Ball";
		displayName = $STR_ACE_MDN_30RND_556X45_STANAG;
		displayNameShort = "";
		model = "\x\ace\addons\m_wep_magazines\30Rnd_556x45_Stanag.p3d";
		initspeed = 930;
	};
	
	class ACE_30Rnd_556x45_S_Stanag : 30Rnd_556x45_Stanag {
		ammo = "ACE_B_556x45_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_30Rnd_556x45_T_Stanag : 30Rnd_556x45_Stanag {
		displayName = $STR_ACE_MDN_30RND_556X45_T_STANAG;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_556x45_T";
		tracersEvery = 1;
	};
	
	class ACE_30Rnd_556x45_SB_Stanag : 30Rnd_556x45_Stanag {
		displayName = $STR_ACE_MDN_30RND_556X45_SB_STANAG;
		displayNameShort = "Mk262";
		ammo = "ACE_B_556x45_SB";
		initSpeed = 850;
	};
	
	class ACE_30Rnd_556x45_SB_S_Stanag : ACE_30Rnd_556x45_SB_Stanag {
		ammo = "ACE_B_556x45_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_30Rnd_6x35_B_PDW : 30Rnd_556x45_Stanag {
		displayName = "$STR_ACE_MDN_30Rnd_6x35_B_PDW";
		descriptionShort = "$STR_ACE_DSS_30Rnd_6x35_B_PDW";
		picture = "\x\ace\addons\c_weapon\data\equip\m_30pdw_ca.paa";
		ammo = "ACE_B_6x35_B";
		initspeed = 739;
		lastroundstracer = 0;
	};
	
	class 30Rnd_556x45_G36 : 30Rnd_556x45_Stanag {
		displayName = $STR_ACE_MDN_30RND_556X45_G36;
		ammo = "ACE_B_556x45_DM11";
	};
	
	class ACE_30Rnd_556x45_S_G36 : 30Rnd_556x45_G36 {
		ammo = "ACE_B_556x45_DM11_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 30Rnd_556x45_G36SD : 30Rnd_556x45_G36 {
		displayName = "$STR_ACE_MDN_30RND_556x45_SD_G36";
	};
	
	class ACE_30Rnd_556x45_T_G36 : 30Rnd_556x45_G36 {
		displayName = $STR_ACE_MDN_30RND_556X45_T_G36;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_556x45_DM21";
		tracersEvery = 1;
	};
	
	class ACE_30Rnd_556x45_AP_G36 : 30Rnd_556x45_G36 {
		displayName = "$STR_ACE_MDN_30Rnd_556x45_AP_G36";
		displayNameShort = $STR_ACE_MDNS_AP;
		ammo = "ACE_B_556x45_DM31";
	};
	
	class ACE_30Rnd_556x45_AP_S_G36 : ACE_30Rnd_556x45_AP_G36 {
		ammo = "ACE_B_556x45_DM31_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 100Rnd_556x45_BetaCMag : CA_Magazine {
		displayName = $STR_ACE_MDN_100RND_556X45_BETACMAG;
		model = "\x\ace\addons\m_wep_magazines\100Rnd_556x45_BetaCMag.p3d";
		type = 256;
	};
	
	class ACE_100Rnd_556x45_S_BetaCMag : 100Rnd_556x45_BetaCMag {
		ammo = "ACE_B_556x45_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 5Rnd_762x51_M24 : CA_Magazine {
		displayName = $STR_ACE_MDN_5RND_762X51_M24;
		model = "\x\ace\addons\m_wep_magazines\5Rnd_762x51_M24.p3d";
		initSpeed = 786;
	};
	
	class ACE_5Rnd_762x51_T_M24 : 5Rnd_762x51_M24 {
		displayName = $STR_ACE_MDN_5RND_762X51_T_M24;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		initspeed = 850;
		tracersEvery = 1;
	};
	
	class 10Rnd_762x51_CZ750 : 5Rnd_762x51_M24 {
		displayName = $STR_ACE_MDN_10RND_762X51_CZ750;
	};
	
	class 20Rnd_762x51_DMR : CA_Magazine {
		displayName = $STR_ACE_MDN_20RND_762X51_DMR;
		initSpeed = 786;
	};
	
	class ACE_20Rnd_762x51_S_DMR : 20Rnd_762x51_DMR {
		ammo = "ACE_B_762x51_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_762x51_B_M14 : 20Rnd_762x51_DMR {
		displayName = $STR_ACE_MDN_20RND_762X51_M14;
		ammo = "B_762x51_Ball";
		initspeed = 850;
	};
	
	class ACE_20Rnd_762x51_S_M14 : ACE_20Rnd_762x51_B_M14 {
		ammo = "ACE_B_762x51_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_762x51_T_DMR : ACE_20Rnd_762x51_B_M14 {
		displayName = $STR_ACE_MDN_20RND_762X51_T_DMR;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		tracersEvery = 1;
	};
	
	class 5x_22_LR_17_HMR : CA_Magazine {
		initSpeed = 786;
	};
	
	class 10Rnd_762x54_SVD : CA_Magazine {
		displayName = $STR_ACE_MDN_10RND_762X54_SVD;
		model = "\x\ace\addons\m_wep_magazines\10Rnd_762x54_SVD.p3d";
		initSpeed = 830;
	};
	
	class ACE_10Rnd_762x54_T_SVD : 10Rnd_762x54_SVD {
		displayName = $STR_ACE_MDN_10RND_762X54_T_SVD;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x54_T";
		tracersEvery = 1;
	};
	
	class 10Rnd_9x39_SP5_VSS : CA_Magazine {
		displayName = "$STR_ACE_DN_10Rnd_9x39_SP5_VSS";
		initSpeed = 295;
		descriptionShort = $STR_ACE_DSS_10RND_VSS_SP5;
	};
	
	class 20Rnd_9x39_SP5_VSS : CA_Magazine {
		displayName = "$STR_ACE_DN_20Rnd_9x39_SP5_VSS";
		initSpeed = 295;
		descriptionShort = $STR_ACE_DSS_20RND_VSS_SP5;
	};
	
	class ACE_10Rnd_9x39_SP6_VSS : 10Rnd_9x39_SP5_VSS {
		displayName = "$STR_ACE_DN_10Rnd_9x39_SP6_VSS";
		ammo = "ACE_B_9x39_SP6";
		descriptionShort = $STR_ACE_DSS_10RND_VSS_SP6;
	};
	
	class ACE_20Rnd_9x39_SP6_VSS : 20Rnd_9x39_SP5_VSS {
		displayName = "$STR_ACE_DN_20Rnd_9x39_SP6_VSS";
		ammo = "ACE_B_9x39_SP6";
		descriptionShort = $STR_ACE_DSS_20RND_VSS_SP6;
	};
	
	class ACE_20Rnd_9x39_B_OC14 : 20Rnd_9x39_SP5_VSS {
		displayName = $STR_ACE_MDN_20RND_9X39_B_SP5_OC14;
		ammo = "ACE_B_9x39_SP5_U";
		descriptionShort = $STR_ACE_DSS_20RND_9X39_B_SP5_OC14;
	};
	
	class ACE_20Rnd_9x39_S_OC14 : ACE_20Rnd_9x39_B_OC14 {
		ammo = "B_9x39_SP5";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_9x39_B_SP6_OC14 : ACE_20Rnd_9x39_B_OC14 {
		displayName = $STR_ACE_MDN_20RND_9X39_B_SP6_OC14;
		ammo = "ACE_B_9x39_SP6_U";
		descriptionShort = $STR_ACE_DSS_20RND_9X39_B_SP6_OC14;
	};
	
	class ACE_20Rnd_9x39_S_SP6_OC14 : ACE_20Rnd_9x39_B_SP6_OC14 {
		ammo = "ACE_B_9x39_SP6";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 5Rnd_127x108_KSVK : CA_Magazine {
		displayName = $STR_ACE_MDN_5RND_127X108_KSVK;
		model = "\x\ace\addons\m_wep_magazines\5Rnd_127x108_KSVK.p3d";
		initSpeed = 845;
	};
	
	class ACE_5Rnd_127x108_T_KSVK : 5Rnd_127x108_KSVK {
		displayName = $STR_ACE_MDN_5RND_127X108_T_KSVK;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_127x108_T";
		tracersEvery = 1;
	};
	
	class 10Rnd_127x99_m107 : CA_Magazine {
		model = "\x\ace\addons\m_wep_magazines\10Rnd_127x99_m107.p3d";
		initSpeed = 887;
	};
	
	class ACE_10Rnd_127x99_T_m107 : 10Rnd_127x99_m107 {
		displayName = $STR_ACE_MDN_10RND_127X99_T_M107;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_127x99_T";
		tracersEvery = 1;
	};
	
	class ACE_10Rnd_127x99_Raufoss_m107 : 10Rnd_127x99_m107 {
		displayName = "$STR_ACE_MDN_10RND_127X99_Raufoss_M107";
		displayNameShort = RAUFOSS;
		ammo = "ACE_B_127x99_Raufoss";
		tracersEvery = 0;
	};
	
	class 20Rnd_762x51_B_SCAR : CA_Magazine {
		displayName = $STR_ACE_MDN_20RND_762X51_B_SCAR;
		displayNameShort = "";
		model = "\x\ace\addons\m_wep_magazines\20rnd_762x51_B_SCAR.p3d";
		ammo = "B_762x51_Ball";
		initSpeed = 844;
	};
	
	class ACE_20Rnd_762x51_S_SCAR : 20Rnd_762x51_B_SCAR {
		ammo = "ACE_B_762x51_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_762x51_SB_SCAR : 20Rnd_762x51_B_SCAR {
		displayName = $STR_ACE_MDN_20RND_762X51_SB_SCAR;
		ammo = "B_762x51_noTracer";
		initSpeed = 759;
	};
	
	class ACE_20Rnd_762x51_SB_S_SCAR : ACE_20Rnd_762x51_SB_SCAR {
		ammo = "ACE_B_762x51_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class 20Rnd_762x51_SB_SCAR : CA_Magazine {
		displayName = $STR_ACE_MDN_20RND_762X51_SD_SCAR;
		initSpeed = 340;
	};
	
	class ACE_20Rnd_762x51_T_SCAR : 20Rnd_762x51_B_SCAR {
		displayName = $STR_ACE_MDN_20RND_762X51_T_SCAR;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		tracersevery = 1;
	};
	
	class ACE_20Rnd_762x51_B_HK417 : 20Rnd_762x51_B_SCAR {
		displayName = "$STR_ACE_MDN_ACE_20Rnd_762x51_B_HK417";
		ammo = "B_762x51_Ball";
		descriptionShort = "$STR_ACE_DSS_20Rnd_762x51_B_HK417";
	};
	
	class ACE_20Rnd_762x51_S_HK417 : ACE_20Rnd_762x51_B_HK417 {
		ammo = "ACE_B_762x51_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_762x51_SB_HK417 : ACE_20Rnd_762x51_B_HK417 {
		displayName = "$STR_ACE_MDN_ACE_20Rnd_762x51_SB_HK417";
		ammo = "B_762x51_noTracer";
		initSpeed = 750;
	};
	
	class ACE_20Rnd_762x51_SB_S_HK417 : ACE_20Rnd_762x51_SB_HK417 {
		ammo = "ACE_B_762x51_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_762x51_T_HK417 : ACE_20Rnd_762x51_B_HK417 {
		displayName = "$STR_ACE_MDN_ACE_20Rnd_762x51_T_HK417";
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		tracersevery = 1;
	};
	
	class 20Rnd_762x51_FNFAL : CA_Magazine {
		initSpeed = 760;
		displayName = $STR_ACE_MDN_20RND_762X51_B_FAL;
		model = "\x\ace\addons\m_wep_magazines\20Rnd_762x51_FNFAL.p3d";
	};
	
	class ACE_20Rnd_762x51_B_FAL : 20Rnd_556x45_Stanag {
		scope = public;
		displayName = $STR_ACE_MDN_20RND_762X51_B_FAL;
		displayNameShort = "";
		descriptionShort = $STR_ACE_DSS_20RND_762X51_B_FAL;
		ammo = "B_762x51_Ball";
		initSpeed = 760;
		tracersevery = 0;
		count = 20;
	};
	
	class ACE_30Rnd_762x51_B_FAL : ACE_20Rnd_762x51_B_FAL {
		displayName = $STR_ACE_MDN_30RND_762X51_B_FAL;
		picture = "\ca\weapons\data\equip\m_30stanag_CA.paa";
		count = 30;
		initSpeed = 700;
		descriptionShort = $STR_ACE_DSS_30RND_762X51_B_FAL;
	};
	
	class ACE_20Rnd_762x51_T_FAL : 20Rnd_762x51_FNFAL {
		displayName = $STR_ACE_MDN_20RND_762X51_T_FAL;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		tracersevery = 1;
	};
	
	class ACE_10Rnd_762x39_B_SKS : 30Rnd_762x39_AK47 {
		displayName = $STR_ACE_MDN_10RND_762X39_B_SKS;
		descriptionShort = $STR_ACE_DSS_10RND_762X39_B_SKS;
		scope = public;
		initSpeed = 735;
		count = 10;
		tracersevery = 0;
	};
	
	class ACE_10Rnd_762x39_T_SKS : ACE_10Rnd_762x39_B_SKS {
		displayName = $STR_ACE_MDN_10RND_762X39_T_SKS;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x39_T";
		tracersevery = 1;
	};
	
	class ACE_20Rnd_762x51_B_G3 : 20Rnd_556x45_Stanag {
		scope = public;
		displayName = $STR_ACE_MDN_20RND_762X51_B_G3;
		displaynameshort = "";
		descriptionShort = $STR_ACE_DSS_20RND_762X51_B_G3;
		ammo = "B_762x51_Ball";
		initSpeed = 800;
		tracersevery = 0;
		count = 20;
	};
	
	class ACE_20Rnd_762x51_T_G3 : ACE_20Rnd_762x51_B_G3 {
		displayName = $STR_ACE_MDN_20RND_762X51_T_G3;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		tracersevery = 1;
	};
	
	class 5Rnd_86x70_L115A1 : CA_Magazine {
		initSpeed = 936;
	};
	
	class ACE_5Rnd_86x70_T_L115A1 : 5Rnd_86x70_L115A1 {
		ammo = "ACE_B_86x70_T";
		displayName = "$STR_ACE_MDN_5RND_86x70_L115";
		displayNameShort = $STR_ACE_MDNS_TRACER;
		tracersevery = 1;
	};
	
	class 5Rnd_127x99_as50 : CA_Magazine {
		initSpeed = 887;
	};
	
	class ACE_5Rnd_25x59_HEDP_Barrett : 10Rnd_127x99_m107 {
		displayName = $STR_ACE_MDN_5RND_25X59_HEDP_BARRETT;
		count = 5;
		initSpeed = 792;
		ammo = "ACE_Bullet_25x59_HEDP";
		tracersevery = 1;
		descriptionShort = $STR_ACE_DSS_5RND_25X59_HEDP_BARRETT;
	};
	
	class ACE_20Rnd_762x51_SB_M110 : 20Rnd_556x45_Stanag {
		displayName = $STR_ACE_MDN_20RND_762X51_SB_M110;
		displaynameshort = "";
		picture = "\ca\weapons_e\data\icons\m_mk17_CA.paa";
		ammo = "B_762x51_noTracer";
		scope = public;
		count = 20;
		initSpeed = 786;
		descriptionShort = $STR_ACE_DSS_20RND_762X51_SB_M110;
	};
	
	class ACE_20Rnd_762x51_S_M110 : ACE_20Rnd_762x51_SB_M110 {
		ammo = "ACE_B_762x51_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_20Rnd_762x51_T_M110 : ACE_20Rnd_762x51_SB_M110 {
		displayName = "$STR_ACE_MDN_20Rnd_762x51_T_M110";
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_762x51_T";
		initspeed = 850;
		tracersEvery = 1;
	};
	
	class ACE_5Rnd_127x99_B_TAC50 : 10Rnd_127x99_m107 {
		displayName = "$STR_ACE_MDN_5Rnd_127x99_B_TAC50";
		count = 5;
		scope = public;
	};
	
	class ACE_5Rnd_127x99_S_TAC50 : ACE_5Rnd_127x99_B_TAC50 {
		displayName = "$STR_ACE_MDN_5Rnd_127x99_S_TAC50";
		ammo = "ACE_B_127x99_SB_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_5Rnd_127x99_T_TAC50 : ACE_5Rnd_127x99_B_TAC50 {
		displayName = "$STR_ACE_MDN_5Rnd_127x99_T_TAC50";
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_127x99_T";
		tracersEvery = 1;
	};
	
	class 10x_303 : CA_Magazine {
		displayName = $STR_ACE_MDN_10RND_303_B_SMLE;
	};
	
	class ACE_10Rnd_77x56_T_SMLE : 10x_303 {
		displayName = $STR_ACE_MDN_10RND_303_T_SMLE;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_77x56_T";
		initspeed = 820;
		tracersEvery = 1;
	};
	
	class 8Rnd_B_Beneli_74Slug : CA_Magazine {
		displayName = $STR_MDN_ACE_8RND_12GA_SLUG;
	};
	
	class 8Rnd_B_Saiga12_74Slug : CA_Magazine {
		displayName = $STR_MDN_ACE_8RND_12GA_SLUG;
	};
	
	class 20Rnd_B_AA12_Pellets : CA_Magazine {
		displayname = $STR_ACE_MDN_20RND_AA12_BUCK00;
		displayNameShort = $STR_DNS_ACE_PELLETS;
	};
	
	class 100Rnd_762x51_M240 : CA_Magazine {
		type = 256;
		displayName = $STR_ACE_MDN_100RND_762X51_M240;
		model = "\x\ace\addons\m_wep_magazines\100Rnd_762x51_M240.p3d";
		initSpeed = 838;
		tracersevery = 5;
	};
	
	class 200Rnd_556x45_M249 : CA_Magazine {
		displayName = $STR_ACE_MDN_200RND_556X45_M249;
		model = "\x\ace\addons\m_wep_magazines\200Rnd_556x45_M249.p3d";
		tracersevery = 5;
	};
	
	class ACE_200Rnd_556x45_T_M249 : 200Rnd_556x45_M249 {
		displayName = $STR_ACE_MDN_200RND_556X45_T_M249;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_556x45_T";
		tracersEvery = 5;
	};
	
	class 100Rnd_556x45_M249 : 200Rnd_556x45_M249 {
		displayName = $STR_ACE_MDN_100RND_556X45_M249;
		displayNameShort = "";
		model = "\x\ace\addons\m_wep_magazines\100Rnd_556x45_M249.p3d";
		type = 256;
	};
	
	class ACE_100Rnd_556x45_T_M249 : 100Rnd_556x45_M249 {
		displayName = $STR_ACE_MDN_100RND_556X45_T_M249;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_556x45_T";
	};
	
	class 75Rnd_545x39_RPK : CA_Magazine {
		displayName = $STR_ACE_MDN_75RND_545X39_RPK;
		model = "\x\ace\addons\m_wep_magazines\30Rnd_545x39_AK.p3d";
		descriptionShort = $STR_ACE_DSS_45RND_545X39_B_AK;
		picture = "\x\ace\addons\c_weapon\data\equip\m_rpk74_ca.paa";
		type = 256;
		initspeed = 900;
		ammo = "ACE_B_545x39_T";
		tracersEvery = 5;
		count = 45;
		ACE_Size = 750;
	};
	
	class ACE_75Rnd_545x39_S_RPK : 75Rnd_545x39_RPK {
		ammo = "ACE_B_545x39_S";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_75Rnd_545x39_T_RPK : 75Rnd_545x39_RPK {
		displayName = $STR_ACE_MDN_75RND_545X39_T_RPK;
		displayNameShort = $STR_ACE_MDNS_TRACER;
		ammo = "ACE_B_545x39_T";
		tracersEvery = 5;
	};
	
	class 100Rnd_762x54_PK : CA_Magazine {
		displayName = $STR_ACE_MDN_100RND_762X54_PK;
		model = "\x\ace\addons\m_wep_magazines\100Rnd_762x54_PK.p3d";
		type = 256;
		initSpeed = 825;
		tracersevery = 5;
	};
	
	class 1Rnd_HE_M203 : CA_Magazine {
		displayName = $STR_ACE_MDN_1RND_433HEDP_M203;
		displayNameShort = HEDP;
		model = "\x\ace\addons\m_wep_magazines\ace_m433.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_m433_ca.paa";
		ammo = "ACE_G_40mm_HEDP";
		initSpeed = 76;
	};
	
	class ACE_1Rnd_HE_M203 : 1Rnd_HE_M203 {
		displayName = $STR_ACE_MDN_1RND_HE_M203;
		displayNameShort = "HE";
		model = "\x\ace\addons\m_wep_magazines\ace_m406.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_m406_ca.paa";
		ammo = "ACE_G_40mm_HE";
	};
	
	class ACE_1Rnd_PR_M203 : 1Rnd_HE_M203 {
		displayName = $STR_ACE_MDN_1RND_PR_M203;
		displayNameShort = $STR_ACE_MDNS_PRACTICE;
		model = "\x\ace\addons\m_wep_magazines\ace_m918.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_m918_pract_ca.paa";
		ammo = "ACE_G_40mm_Practice";
	};
	
	class 6Rnd_HE_M203 : 1Rnd_HE_M203 {
		displayName = $STR_ACE_MDN_6RND_433HEDP_M32;
	};
	
	class 1Rnd_HE_GP25 : CA_Magazine {
		displayName = $STR_ACE_MDN_1RND_HE_GP25;
		initSpeed = 76;
		model = "\x\ace\addons\m_wep_magazines\ace_vog25.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_vog25_ca.paa";
	};
	
	class ACE_1Rnd_HE_GP25P : 1Rnd_HE_GP25 {
		displayName = "$STR_ACE_MDN_1Rnd_HE_GP25P";
		ammo = "ACE_G40mm_HE_VOG25P";
		model = "\x\ace\addons\m_wep_magazines\ace_vog25p.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_vog25p_ca.paa";
	};
	
	class FlareWhite_M203 : CA_Magazine {
		displayName = $STR_ACE_MDN_FLAREWHITE_M203;
		displayNameShort = $STR_ACE_MDNS_WHITE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareW_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m583.p3d";
	};
	
	class FlareGreen_M203 : FlareWhite_M203 {
		displayName = $STR_ACE_MDN_FLAREGREEN_M203;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareG_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m661.p3d";
	};
	
	class FlareRed_M203 : FlareWhite_M203 {
		displayName = $STR_ACE_MDN_FLARERED_M203;
		displayNameShort = $STR_ACE_MDNS_RED;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareR_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m662.p3d";
	};
	
	class FlareYellow_M203 : FlareWhite_M203 {
		displayName = $STR_ACE_MDN_FLAREYELLOW_M203;
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareY_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m665.p3d";
	};
	
	class ACE_FlareIR_M203 : FlareWhite_M203 {
		displayName = $STR_ACE_MDN_FLAREIR_M203;
		displayNameShort = $STR_ACE_MDNS_IR;
		ammo = "ACE_F_40mm_IR";
	};
	
	class 6Rnd_FlareWhite_M203 : FlareWhite_M203 {
		displayName = $STR_ACE_MDN_6RND_FLAREWHITE_M32;
	};
	
	class 6Rnd_FlareGreen_M203 : FlareGreen_M203 {
		displayName = $STR_ACE_MDN_6RND_FLAREGREEN_M32;
	};
	
	class 6Rnd_FlareRed_M203 : FlareRed_M203 {
		displayName = $STR_ACE_MDN_6RND_FLARERED_M32;
	};
	
	class 6Rnd_FlareYellow_M203 : FlareYellow_M203 {
		displayName = $STR_ACE_MDN_6RND_FLAREYELLOW_M32;
	};
	
	class 1Rnd_Smoke_M203 : 1Rnd_HE_M203 {
		displayName = $STR_ACE_MDN_1RND_SMOKEPURPLE_M203;
		displayNameShort = $STR_ACE_MDNS_PURPLE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_smokeV_ca.paa";
		ammo = "ACE_G_40mmSmokePurple";
		model = "\x\ace\addons\m_wep_magazines\ace_m701.p3d";
	};
	
	class 1Rnd_SmokeRed_M203 : 1Rnd_Smoke_M203 {
		displayName = $STR_ACE_MDN_1RND_SMOKERED_M203;
		displayNameShort = $STR_ACE_MDNS_RED;
		picture = "\x\ace\addons\c_weapon\data\equip\m_smokeR_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m713.p3d";
	};
	
	class 1Rnd_SmokeGreen_M203 : 1Rnd_Smoke_M203 {
		displayName = $STR_ACE_MDN_1RND_SMOKEGREEN_M203;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		picture = "\x\ace\addons\c_weapon\data\equip\m_smokeG_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m715.p3d";
	};
	
	class 1Rnd_SmokeYellow_M203 : 1Rnd_Smoke_M203 {
		displayName = $STR_ACE_MDN_1RND_SMOKEYELLOW_M203;
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		picture = "\x\ace\addons\c_weapon\data\equip\m_smokeY_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m716.p3d";
	};
	
	class 6Rnd_Smoke_M203 : 1Rnd_Smoke_M203 {
		displayName = $STR_ACE_MDN_6RND_SMOKEPURPLE_M32;
	};
	
	class 6Rnd_SmokeRed_M203 : 1Rnd_SmokeRed_M203 {
		displayName = $STR_ACE_MDN_6RND_SMOKERED_M32;
	};
	
	class 6Rnd_SmokeGreen_M203 : 1Rnd_SmokeGreen_M203 {
		displayName = $STR_ACE_MDN_6RND_SMOKEGREEN_M32;
	};
	
	class 6Rnd_SmokeYellow_M203 : 1Rnd_SmokeYellow_M203 {
		displayName = $STR_ACE_MDN_6RND_SMOKEYELLOW_M32;
	};
	
	class FlareWhite_GP25 : CA_Magazine {
		displayName = $STR_ACE_MDN_1RND_FLARE_GP25;
		displayNameShort = $STR_ACE_MDNS_WHITE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40op_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_vg40op.p3d";
	};
	
	class FlareGreen_GP25 : FlareWhite_GP25 {
		displayName = $STR_ACE_MDN_1RND_FLAREGREEN_GP25;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40op_ca.paa";
	};
	
	class FlareRed_GP25 : FlareWhite_GP25 {
		displayName = $STR_ACE_MDN_1RND_FLARERED_GP25;
		displayNameShort = $STR_ACE_MDNS_RED;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40op_ca.paa";
	};
	
	class FlareYellow_GP25 : FlareWhite_GP25 {
		displayName = $STR_ACE_MDN_1RND_FLAREYELLOW_GP25;
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40op_ca.paa";
	};
	
	class 1Rnd_SMOKE_GP25 : 1Rnd_HE_GP25 {
		displayName = $STR_ACE_MDN_1RND_SMOKE_GP25;
		displayNameShort = $STR_ACE_MDNS_WHITE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40md_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_vg40md.p3d";
	};
	
	class 1Rnd_SmokeRed_GP25 : 1Rnd_SMOKE_GP25 {
		displayName = $STR_ACE_MDN_1RND_SMOKERED_GP25;
		displayNameShort = $STR_ACE_MDNS_RED;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40md_ca.paa";
	};
	
	class 1Rnd_SmokeGreen_GP25 : 1Rnd_SMOKE_GP25 {
		displayName = $STR_ACE_MDN_1RND_SMOKEGREEN_GP25;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40md_ca.paa";
	};
	
	class 1Rnd_SmokeYellow_GP25 : 1Rnd_SMOKE_GP25 {
		displayName = $STR_ACE_MDN_1RND_SMOKEYELLOW_GP25;
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		picture = "\x\ace\addons\c_weapon\data\equip\m_vg40md_ca.paa";
	};
	
	class ACE_SSWhite_M203 : CA_Magazine {
		scope = public;
		type = 16;
		displayName = $STR_ACE_MDN_SS_WHITE_M203;
		displayNameShort = $STR_ACE_MDNS_WHITE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareW_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m585.p3d";
		ammo = "ACE_SS_White";
		initSpeed = 80;
		count = 1;
		nameSound = "grenadelauncher";
		descriptionShort = $STR_DSS_1RND_FLAREYELLOW_M203;
	};
	
	class ACE_SSGreen_M203 : ACE_SSWhite_M203 {
		displayName = $STR_ACE_MDN_SS_GREEN_M203;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareG_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m663.p3d";
		ammo = "ACE_SS_Green";
	};
	
	class ACE_SSRed_M203 : ACE_SSWhite_M203 {
		displayName = $STR_ACE_MDN_SS_RED_M203;
		displayNameShort = $STR_ACE_MDNS_RED;
		picture = "\x\ace\addons\c_weapon\data\equip\m_flareR_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_m664.p3d";
		ammo = "ACE_SS_Red";
	};
	
	class ACE_SSYellow_M203 : ACE_SSWhite_M203 {};
	
	class ACE_SSWhite_GP25 : CA_Magazine {
		scope = public;
		type = 16;
		displayName = $STR_ACE_MDN_SS_WHITE_GP25;
		displayNameShort = $STR_ACE_MDNS_WHITE;
		picture = "\Ca\weapons\Data\Equip\m_FlareWhite_CA.paa";
		ammo = "ACE_SS_White";
		initSpeed = 80;
		count = 1;
		nameSound = "grenadelauncher";
		descriptionShort = $STR_DSS_1RND_FLAREYELLOW_GP25;
	};
	
	class ACE_SSGreen_GP25 : ACE_SSWhite_GP25 {
		displayName = $STR_ACE_MDN_SS_GREEN_GP25;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		ammo = "ACE_SS_Green";
		picture = "\Ca\weapons\Data\Equip\m_FlareGreen_CA.paa";
	};
	
	class ACE_SSRed_GP25 : ACE_SSWhite_GP25 {
		displayName = $STR_ACE_MDN_SS_RED_GP25;
		displayNameShort = $STR_ACE_MDNS_RED;
		ammo = "ACE_SS_Red";
		picture = "\Ca\weapons\Data\Equip\m_FlareRed_CA.paa";
	};
	
	class ACE_SSYellow_GP25 : ACE_SSWhite_GP25 {
		displayName = $STR_ACE_MDN_SS_YELLOW_GP25;
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		ammo = "ACE_SS_Yellow";
		picture = "\Ca\weapons\Data\Equip\m_FlareYelow_CA.paa";
	};
	
	class ACE_SSWhite_FG : ACE_SSWhite_M203 {
		displayName = $STR_ACE_MDN_SS_WHITE_FG;
		displayNameShort = $STR_ACE_MDNS_WHITE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_ss_fg_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_ss_fg.p3d";
		ammo = "ACE_SS_White_FG";
		descriptionShort = $STR_ACE_DSS_1RND_SS_FG;
	};
	
	class ACE_SSGreen_FG : ACE_SSWhite_FG {
		displayName = $STR_ACE_MDN_SS_GREEN_FG;
		displayNameShort = $STR_ACE_MDNS_GREEN;
		ammo = "ACE_SS_Green_FG";
	};
	
	class ACE_SSRed_FG : ACE_SSWhite_FG {
		displayName = $STR_ACE_MDN_SS_RED_FG;
		displayNameShort = $STR_ACE_MDNS_RED;
		ammo = "ACE_SS_Red_FG";
	};
	
	class ACE_SSYellow_FG : ACE_SSWhite_FG {
		displayName = $STR_ACE_MDN_SS_YELLOW_FG;
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		ammo = "ACE_SS_Yellow_FG";
	};
	
	class HandGrenade : CA_Magazine {
		model = "\x\ace\addons\m_wep_magazines\ace_rgo.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_rgo_ca.paa";
		displayName = $STR_ACE_MDN_RG0;
		displayNameShort = $STR_ACE_MDNS_RG0;
	};
	
	class HandGrenade_Stone : HandGrenade {
		picture = "\x\ace\addons\c_weapon\data\equip\m_stone_ca.paa";
		displayNameShort = $STR_MN_STONE;
	};
	
	class HandGrenade_West : HandGrenade {
		model = "\ca\Weapons\M67";
		displayNameShort = M67;
	};
	
	class BAF_L109A1_HE : HandGrenade_West {
		displayNameShort = L109A2;
	};
	
	class HandGrenade_East : HandGrenade_West {
		model = "\ca\Weapons\frag_rgd5";
		displayName = $STR_ACE_MDN_RGD5;
		displayNameShort = $STR_ACE_MDNS_RGD5;
	};
	
	class ACE_DM51 : HandGrenade_West {
		displayName = DM51;
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm51_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ACE_DM51.p3d";
		displayNameShort = DM51;
		ammo = ACE_DM51;
	};
	
	class ACE_DM51A1 : ACE_DM51 {
		displayName = DM51A1;
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm51a1_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ACE_DM51A1.p3d";
		displayNameShort = DM51A1;
		ammo = ACE_DM51A1;
	};
	
	class SmokeShell : HandGrenade {
		displayNameShort = $STR_ACE_MDNS_WHITE;
		model = "\x\ace\addons\m_wep_magazines\ANM8_white.p3d";
	};
	
	class SmokeShellGreen : SmokeShell {
		displayNameShort = $STR_ACE_MDNS_GREEN;
		model = "\x\ace\addons\m_wep_magazines\M18_green.p3d";
	};
	
	class SmokeShellRed : SmokeShell {
		displayNameShort = $STR_ACE_MDNS_RED;
		picture = "\CA\weapons\data\equip\m_m18red_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\M18_red.p3d";
	};
	
	class SmokeShellYellow : SmokeShell {
		displayNameShort = $STR_ACE_MDNS_YELLOW;
		picture = "\CA\weapons\data\equip\m_m18yellow_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\M18_yellow.p3d";
	};
	
	class SmokeShellPurple : SmokeShell {
		displayNameShort = $STR_ACE_MDNS_PURPLE;
		picture = "\CA\weapons\data\equip\m_m18violet_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\M18_violet.p3d";
	};
	
	class SmokeShellBlue : SmokeShell {
		displayNameShort = $STR_ACE_MDNS_BLUE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_m18blue_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\M18_blue.p3d";
	};
	
	class SmokeShellOrange : SmokeShell {
		displayName = $STR_ACE_MDN_SMOKE_ORANGE;
		displayNameShort = $STR_ACE_MDNS_ORANGE;
		picture = "\x\ace\addons\c_weapon\data\equip\m_m18orange_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\M18_orange.p3d";
	};
	
	class ACE_RDG2 : SmokeShell {
		displayName = $STR_ACE_MDN_RDG2;
		displayNameShort = $STR_ACE_MDNS_RDG2;
		model = "\x\ace\addons\m_wep_magazines\ace_rdg2.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_rdg2_ca.paa";
		ammo = ACE_RDG2;
	};
	
	class ACE_RDGM : SmokeShell {
		displayName = $STR_ACE_MDN_RDGM;
		displayNameShort = $STR_ACE_MDNS_RDGM;
		model = "\x\ace\addons\m_wep_magazines\ace_rdgm.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_rdgm_ca.paa";
		ammo = ACE_RDGM;
	};
	
	class ACE_DM25 : SmokeShell {
		displayName = DM25;
		model = "\x\ace\addons\m_wep_magazines\ace_dm25.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm25_ca.paa";
		ammo = ACE_DM25;
	};
	
	class ACE_DM31 : SmokeShellGreen {
		displayName = DM31;
		model = "\x\ace\addons\m_wep_magazines\ace_dm31.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm32_ca.paa";
		ammo = ACE_DM31;
	};
	
	class ACE_DM32 : SmokeShellOrange {
		displayName = DM32;
		model = "\x\ace\addons\m_wep_magazines\ace_dm32.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm32_ca.paa";
		ammo = ACE_DM32;
	};
	
	class ACE_DM33 : SmokeShellRed {
		displayName = DM33;
		model = "\x\ace\addons\m_wep_magazines\ace_dm33.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm32_ca.paa";
		ammo = ACE_DM33;
	};
	
	class ACE_DM34 : SmokeShellPurple {
		displayName = DM34;
		model = "\x\ace\addons\m_wep_magazines\ace_dm34.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm32_ca.paa";
		ammo = ACE_DM34;
	};
	
	class ACE_DM36 : SmokeShellYellow {
		displayName = DM36;
		model = "\x\ace\addons\m_wep_magazines\ace_dm36.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\m_dm32_ca.paa";
		ammo = ACE_DM36;
	};
	
	class TimeBomb : CA_Magazine {
		model = "\x\ace\addons\m_wep_magazines\Pipebomb.p3d";
	};
	
	class Mine : TimeBomb {
		model = "\x\ace\addons\m_wep_magazines\Mine.p3d";
	};
	
	class MineE : TimeBomb {
		model = "\x\ace\addons\m_wep_magazines\MineE.p3d";
	};
	
	class Laserbatteries : CA_Magazine {
		model = "\x\ace\addons\m_wep_magazines\BA5590.p3d";
	};
	
	class RPG18 : CA_LauncherMagazine {
		initSpeed = 133;
		type = 256;
	};
	
	class PG7V : CA_LauncherMagazine {
		initSpeed = 120;
		type = 512;
		displayName = $STR_ACE_MDN_PG7V;
		displayNameShort = $STR_ACE_MDNS_PG7V;
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pg7v";
	};
	
	class ACE_PG7V_PGO7 : PG7V {
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pgo7_pg7v";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_PG7VM : PG7V {
		ammo = ACE_R_PG7VM_AT;
		initSpeed = 120;
		displayName = $STR_ACE_MDN_PG7VM;
		displayNameShort = $STR_ACE_MDNS_PG7VM;
		model = "\x\ace\addons\m_wep_rpg7\ace_pg7vm_magazine";
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pg7vm";
	};
	
	class ACE_PG7VM_PGO7 : ACE_PG7VM {
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pgo7_pg7vm";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class PG7VL : PG7V {
		initspeed = 112;
		type = 512;
		displayName = $STR_ACE_MDN_PG7VL;
		displayNameShort = $STR_ACE_MDNS_PG7VL;
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pg7vl";
	};
	
	class ACE_PG7VL_PGO7 : PG7VL {
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pgo7_pg7vl";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class PG7VR : PG7V {
		initspeed = 84.5;
		type = 512;
		displayName = $STR_ACE_MDN_PG7VR;
		displayNameShort = $STR_ACE_MDNS_PG7VR;
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pg7vr";
	};
	
	class ACE_PG7VR_PGO7 : PG7VR {
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pgo7_pg7vr";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_TBG7V : PG7VR {
		ammo = ACE_R_TBG7V_AT;
		displayName = $STR_ACE_MDN_TBG7V;
		displayNameShort = $STR_ACE_MDNS_TBG7V;
		model = "\x\ace\addons\m_wep_rpg7\ace_tbg7v_magazine";
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_tbg7v";
	};
	
	class ACE_TBG7V_PGO7 : ACE_TBG7V {
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pgo7_tbg7v";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class OG7 : CA_LauncherMagazine {
		initspeed = 140;
		type = 512;
		displayName = $STR_ACE_MDN_OG7V;
		displayNameShort = $STR_ACE_MDNS_OG7V;
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_og7v";
	};
	
	class ACE_OG7_PGO7 : OG7 {
		modelSpecial = "\x\ace\addons\m_wep_rpg7\slx_rpg7_pgo7_og7v";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class SMAW_HEDP : CA_LauncherMagazine {
		initspeed = 325;
		type = 512;
		displayName = $STR_ACE_MDN_SMAW_HEDP;
		displayNameShort = HEDP;
	};
	
	class SMAW_HEAA : SMAW_HEDP {
		displayName = $STR_ACE_MDN_SMAW_HEAA;
		displayNameShort = HEAA;
	};
	
	class ACE_SMAW_NE : SMAW_HEDP {
		displayName = $STR_ACE_MDN_SMAW_NE;
		ammo = ACE_R_SMAW_NE;
		displayNameShort = "NE";
	};
	
	class Javelin : CA_LauncherMagazine {
		initSpeed = 15;
		descriptionShort = $STR_ACE_DSS_JAVELIN_FIXED;
		displayName = $STR_ACE_MDN_JAVELIN;
		model = "\x\ace\addons\m_wep_magazines\ace_javelin_tube";
	};
	
	class ACE_Javelin_Direct : Javelin {
		ammo = "ACE_M_Javelin_AT_Direct";
	};
	
	class AT13 : CA_LauncherMagazine {
		displayName = $STR_ACE_MDN_AT13;
		ammo = M_AT13_AT;
		initSpeed = 80;
		displaynameShort = $STR_ACE_MDNS_AT13;
		type = 4 * 256;
	};
	
	class ACE_AT13TB : AT13 {
		ammo = ACE_M_AT13_TB;
		descriptionshort = $STR_ACE_DSS_ACE_AT13TB;
		displayname = $STR_ACE_MDN_AT13TB;
		displaynameShort = $STR_ACE_MDNS_AT13TB;
	};
	
	class Stinger : CA_LauncherMagazine {
		displayName = $STR_ACE_MDN_STINGER;
	};
	
	class Strela : CA_LauncherMagazine {
		displayName = $STR_ACE_MDN_STRELA;
		displayNameShort = $STR_ACE_MDNS_STRELA;
	};
	
	class Igla : Strela {
		displayName = $STR_ACE_MDN_IGLA;
		displayNameShort = $STR_ACE_MDNS_IGLA;
	};
	
	class MAAWS_HEDP : CA_LauncherMagazine {
		displayName = $STR_ACE_MDN_MAAWS_HEDP;
		displayNameShort = HEDP;
		ammo = R_MEEWS_HEDP;
		initSpeed = 230;
	};
	
	class ACE_MAAWS_HE : MAAWS_HEDP {
		displayName = $STR_ACE_MDN_MAAWS_HE;
		displayNameShort = "HE";
		ammo = ACE_R_MEEWS_HE;
		initSpeed = 240;
	};
	
	class MAAWS_HEAT : MAAWS_HEDP {
		displayName = $STR_ACE_MDN_MAAWS_HEAT;
		displayNameShort = HEAT;
		ammo = R_MEEWS_HEAT;
		initSpeed = 255;
	};
};

class Mode_SemiAuto {
	displayName = $STR_ACE_DN_MODE_SEMI;
};

class Mode_Burst : Mode_SemiAuto {
	displayName = $STR_ACE_DN_MODE_BURST;
};

class Mode_FullAuto : Mode_SemiAuto {
	displayName = $STR_ACE_DN_MODE_AUTO;
};

class CfgWeapons {
	class Default;	// External class reference
	
	class Binocular : Default {
		forceOptics = false;
		opticsZoomMin = 0.056889;
		opticsZoomMax = 0.056889;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_M22_5x";
		visionMode[] = {"Normal"};
		minRange = 500;
		minRangeProbab = 0.001;
		midRange = 1000;
		midRangeProbab = 0.01;
		maxRange = 5000;
		maxRangeProbab = 0.01;
	};
	
	class LaserDesignator : Binocular {
		forceOptics = false;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_GTLD_5x";
		opticsZoomMin = 0.056889;
		opticsZoomMax = 0.056889;
		minrangeprobab = 0.4;
		midrangeprobab = 0.5;
		dexterity = 0.2;
	};
	
	class NVGoggles : Binocular {
		ACE_DamagedItem = "ACE_BrokenNVGoggles";
	};
	
	class ACE_BrokenNVGoggles : NVGoggles {
		simulation = "";
		
		class Armory {
			disabled = 1;
		};
	};
	class PistolCore;	// External class reference
	class RifleCore;	// External class reference
	class MGunCore;	// External class reference
	class LauncherCore;	// External class reference
	class GrenadeCore;	// External class reference
	class Launcher;	// External class reference
	class CannonCore;	// External class reference
	class RocketPods;	// External class reference
	
	class GrenadeLauncher : Default {
		dispersion = 0.01;
	};
	class Pistol;	// External class reference
	
	class M9 : Pistol {
		magazines[] = {"15Rnd_9x19_M9", "15Rnd_9x19_M9SD", "ACE_15Rnd_9x19_S_M9"};
		dispersion = 0.004;
		recoil = "ACE_9x19_PistolRecoil";
	};
	
	class M9SD : M9 {
		magazines[] = {"15Rnd_9x19_M9SD", "ACE_15Rnd_9x19_S_M9", "15Rnd_9x19_M9"};
		recoil = "ACE_9x19_SUP_PistolRecoil";
	};
	
	class Makarov : Pistol {
		dispersion = 0.004;
		recoil = "ACE_9x18_PistolRecoil";
	};
	
	class MakarovSD : Makarov {
		magazines[] = {"8Rnd_9x18_MakarovSD", "8Rnd_9x18_Makarov"};
		recoil = "ACE_9x18_SUP_PistolRecoil";
	};
	
	class Colt1911 : M9 {
		recoil = "ACE_45ACP_PistolRecoil";
	};
	
	class glock17_EP1 : Pistol {
		displayName = "Glock 17";
		dispersion = 0.004;
		
		class FlashLight {
			color[] = {0.9, 0.9, 0.7, 0.9};
			ambient[] = {0.1, 0.1, 0.1, 1.0};
			position = "flash dir";
			direction = "flash";
			angle = 20;
			scale[] = {0.9, 0.9, 0.4};
			brightness = 0.09;
		};
		magazines[] = {"17Rnd_9x19_glock17", "ACE_33Rnd_9x19_G18"};
		recoil = "ACE_9x19_PistolRecoil";
	};
	
	class UZI_EP1 : Pistol {
		displayName = $STR_ACE_WDN_MICROUZI;
		magazines[] = {"30Rnd_9x19_UZI", "30Rnd_9x19_UZI_SD", "ACE_30Rnd_9x19_S_UZI"};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.035;
			dispersion = 0.0036;
			recoil = "ACE_9x19_PistolRecoil";
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.035;
			dispersion = 0.0036;
			recoil = "ACE_Glock_Auto_Recoil";
		};
	};
	
	class UZI_SD_EP1 : UZI_EP1 {
		displayName = $STR_ACE_WDN_MICROUZISD;
		magazines[] = {"30Rnd_9x19_UZI_SD", "ACE_30Rnd_9x19_S_UZI", "30Rnd_9x19_UZI"};
		
		class Single : Single {
			recoil = "ACE_9x19_SUP_PistolRecoil";
		};
	};
	
	class Sa61_EP1 : Pistol {
		class Single : Mode_SemiAuto {
			dispersion = 0.0038;
			recoil = "ACE_vz61Recoil";
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.0038;
			recoil = "ACE_vz61Recoil";
		};
	};
	
	class revolver_EP1 : Pistol {
		dispersion = 0.004;
		recoil = "ACE_45ACP_PistolRecoil";
	};
	
	class CZ_75_P_07_DUTY : M9 {
		displayName = "CZ 75 Duty";
		magazines[] = {"ACE_16Rnd_9x19_CZ75", "18Rnd_9x19_Phantom", "18Rnd_9x19_PhantomSD", "ACE_16Rnd_9x19_S_CZ75", "ACE_18Rnd_9x19_S_Phantom"};
		
		class FlashLight {
			color[] = {0.9, 0.9, 0.7, 0.9};
			ambient[] = {0.1, 0.1, 0.1, 1.0};
			position = "flash dir";
			direction = "flash";
			angle = 20;
			scale[] = {0.9, 0.9, 0.4};
			brightness = 0.09;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	
	class CZ_75_D_COMPACT : M9 {
		displayName = "CZ 75 Compact";
	};
	
	class CZ_75_SP_01_PHANTOM : M9 {
		displayName = "CZ 75 Phantom";
		magazines[] = {"18Rnd_9x19_Phantom", "ACE_16Rnd_9x19_CZ75", "18Rnd_9x19_PhantomSD", "ACE_18Rnd_9x19_S_Phantom", "ACE_16Rnd_9x19_S_CZ75"};
		
		class FlashLight {
			color[] = {0.9, 0.9, 0.7, 0.9};
			ambient[] = {0.1, 0.1, 0.1, 1.0};
			position = "flash dir";
			direction = "flash";
			angle = 20;
			scale[] = {0.9, 0.9, 0.4};
			brightness = 0.09;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	
	class CZ_75_SP_01_PHANTOM_SD : M9SD {
		displayName = "CZ 75 Phantom SD";
		magazines[] = {"18Rnd_9x19_PhantomSD", "ACE_18Rnd_9x19_S_Phantom", "ACE_16Rnd_9x19_S_CZ75", "18Rnd_9x19_Phantom", "ACE_16Rnd_9x19_CZ75"};
		
		class FlashLight {
			color[] = {0.9, 0.9, 0.7, 0.9};
			ambient[] = {0.1, 0.1, 0.1, 1.0};
			position = "flash dir";
			direction = "flash";
			angle = 20;
			scale[] = {0.9, 0.9, 0.4};
			brightness = 0.09;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	
	class ACE_M203_Launcher : GrenadeLauncher {
		scope = protected;
		displayName = $STR_ACE_WDN_ACE_M203_LAUNCHER;
		magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
		recoil = "M240Recoil";
		ACE_GRENADE_TYPE = M203;
		magazineReloadTime = 0;
		reloadTime = 0.1;
		optics = true;
		modelOptics = "-";
		cameraDir = "GL look";
		memoryPointCamera = "GL eye";
		opticsZoomMin = 0.3;
		opticsZoomMax = 0.5;
		opticsZoomInit = 0.5;
		opticsPPEffects[] = {};
		weaponInfoType = "RscWeaponEmpty";
		
		class Library {
			libTextDesc = "$STR_ACE_LIB_ACE_M203_Launcher";
		};
	};
	
	class Rifle : RifleCore {
		class M203Muzzle : GrenadeLauncher {
			magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
			recoil = "M240Recoil";
			ACE_GRENADE_TYPE = M203;
			magazineReloadTime = 0;
			reloadTime = 0.1;
			optics = true;
			modelOptics = "-";
			cameraDir = "GL look";
			memoryPointCamera = "GL eye";
			opticsZoomMin = 0.3;
			opticsZoomMax = 0.5;
			opticsZoomInit = 0.5;
			opticsPPEffects[] = {};
			weaponInfoType = "RscWeaponEmpty";
		};
		
		class ACE_M203Muzzle_AI : M203Muzzle {
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = false;
		};
	};
	
	class M16_base : Rifle {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD"};
		
		class M203Muzzle : M203Muzzle {
			magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
			recoil = "M240Recoil";
			ACE_GRENADE_TYPE = M203;
			magazineReloadTime = 0;
			reloadTime = 0.1;
			optics = true;
			modelOptics = "-";
			cameraDir = "GL look";
			memoryPointCamera = "GL eye";
			opticsZoomMin = 0.3;
			opticsZoomMax = 0.5;
			opticsZoomInit = 0.5;
			opticsPPEffects[] = {};
			weaponInfoType = "RscWeaponEmpty";
		};
		
		class ACE_M203Muzzle_AI : M203Muzzle {
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = false;
		};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.071;
			dispersion = 0.00175;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.071;
			dispersion = 0.00175;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.071;
			dispersion = 0.00175;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
	};
	
	class M16A2 : M16_base {
		class Single;	// External class reference
		class Burst;	// External class reference
	};
	
	class M16A2GL : M16A2 {
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class Burst : Burst {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class m16a4 : M16A2 {
		class Armory {
			disabled = 1;
		};
	};
	
	class M4A1 : M16_base {
		class Single : Single {
			reloadTime = 0.071;
			dispersion = 0.00225;
		};
		
		class FullAuto : FullAuto {
			reloadTime = 0.071;
			dispersion = 0.00225;
		};
	};
	
	class M4SPR : M4A1 {
		class Armory {
			disabled = 1;
		};
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_10x_round_mildot";
		
		class OpticsModes {
			class StepScope {
				opticsID = 1;
				distanceZoomMin = 325;
				distanceZoomMax = 325;
				opticsZoomMin = 0.029624;
				opticsZoomMax = 0.085714;
				opticsZoomInit = 0.085714;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "eye";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		magazines[] = {"ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "ACE_30Rnd_556x45_T_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD"};
		
		class Single : Single {
			dispersion = 0.0003;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
	};
	
	class M4A1_RCO_GL : M4A1 {
		class M4_ACOG_Muzzle : M4A1 {
			modelOptics = "\x\ace\addons\m_wep_optics\NWD_acog_ta01nsn";
			
			class OpticsModes {
				class ACOG4X {
					opticsID = 1;
					distanceZoomMin = 189;
					distanceZoomMax = 189;
					opticsZoomMin = 0.071945;
					opticsZoomMax = 0.071945;
					opticsZoomInit = 0.071945;
					opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				
				class CQB : ACOG4X {
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
			magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD"};
			
			class Single : Single {
				recoil = "ACE_556x45_Rifle_Recoil_GL";
			};
			
			class FullAuto : FullAuto {
				recoil = "ACE_556x45_Rifle_Recoil_GL";
			};
		};
		
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class M4A1_Aim : M4A1 {
		class Armory {
			disabled = 1;
		};
	};
	
	class M4A1_AIM_SD_camo : M4A1_Aim {
		magazines[] = {"ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_T_Stanag", "ACE_20Rnd_556x45_S_Stanag", "20Rnd_556x45_Stanag", "30Rnd_556x45_StanagSD", "ACE_100Rnd_556x45_S_BetaCMag", "100Rnd_556x45_BetaCMag"};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.00225;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00225;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
	};
	
	class M4A1_HWS_GL_SD_Camo : M4A1_AIM_SD_camo {
		displayName = "M4A1 M203 Holo SD";
		
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class M4A1_HWS_GL : M4A1_RCO_GL {
		displayName = "M4A1 M203 Holo";
	};
	
	class M4A1_HWS_GL_camo : M4A1_HWS_GL {
		displayName = "M4A1 M203 Holo";
	};
	
	class M4A3_CCO_EP1 : M16_base {
		class Single : Single {
			reloadTime = 0.071;
			dispersion = 0.00225;
		};
		
		class FullAuto : FullAuto {
			reloadTime = 0.071;
			dispersion = 0.00225;
		};
	};
	
	class M4A3_RCO_GL_EP1 : M4A3_CCO_EP1 {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_acog_ta01nsn";
		
		class OpticsModes {
			class ACOG {
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Kolimator : ACOG {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class G36C : Rifle {
		magazines[] = {"30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_G36", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.08;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.08;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.08;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
		};
	};
	
	class G36_C_SD_eotech : G36C {
		magazines[] = {"30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_G36", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
	};
	
	class G36a : Rifle {
		class MuzzleFar : G36C {
			modelOptics = "\x\ace\addons\m_wep_optics\NWD_G36_optics_wide";
			
			class OpticsModes {
				class Scope {
					opticsID = 1;
					distanceZoomMin = 236;
					distanceZoomMax = 236;
					opticsZoomMin = 0.095903;
					opticsZoomMax = 0.095903;
					opticsZoomInit = 0.095903;
					opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				
				class Kolimator : Scope {
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
			magazines[] = {"30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_G36", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
			
			class Single : Mode_SemiAuto {
				reloadTime = 0.08;
				recoil = "ACE_556x45_Rifle_Recoil";
				recoilProne = "ACE_556x45_Rifle_RecoilProne";
				dispersion = 0.0016;
			};
			
			class Burst : Mode_Burst {
				reloadTime = 0.08;
				recoil = "ACE_556x45_Rifle_Recoil_B";
				recoilProne = "ACE_556x45_Rifle_RecoilProne";
				dispersion = 0.0016;
			};
			
			class FullAuto : Mode_FullAuto {
				reloadTime = 0.08;
				recoil = "ACE_556x45_Rifle_Recoil_B";
				recoilProne = "ACE_556x45_Rifle_RecoilProne";
				dispersion = 0.0016;
			};
		};
	};
	
	class G36A_camo : G36a {
		class MuzzleFar : MuzzleFar {
			class OpticsModes {
				class Scope {
					opticsID = 1;
					distanceZoomMin = 236;
					distanceZoomMax = 236;
					opticsZoomMin = 0.095903;
					opticsZoomMax = 0.095903;
					opticsZoomInit = 0.095903;
					opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				
				class Kolimator : Scope {
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
		};
	};
	
	class G36K : G36A {
		class MuzzleFar : Muzzlefar {
			class OpticsModes {
				class Scope {
					opticsID = 1;
					distanceZoomMin = 236;
					distanceZoomMax = 236;
					opticsZoomMin = 0.095903;
					opticsZoomMax = 0.095903;
					opticsZoomInit = 0.095903;
					opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				
				class Kolimator : Scope {
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
			
			class Single : Single {
				dispersion = 0.002;
			};
			
			class Burst : Burst {
				dispersion = 0.002;
			};
			
			class FullAuto : FullAuto {
				dispersion = 0.002;
			};
		};
	};
	
	class G36K_camo : G36K {
		class MuzzleFar : MuzzleFar {
			class OpticsModes {
				class Scope {
					opticsID = 1;
					distanceZoomMin = 236;
					distanceZoomMax = 236;
					opticsZoomMin = 0.095903;
					opticsZoomMax = 0.095903;
					opticsZoomInit = 0.095903;
					opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = true;
					opticsDisablePeripherialVision = true;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				
				class Kolimator : Scope {
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = false;
					opticsDisablePeripherialVision = false;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
		};
	};
	
	class m8_base : Rifle {
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_T_G36", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		
		class XM320Muzzle : M203Muzzle {
			displayName = XM320;
		};
		
		class ACE_XM320Muzzle_AI : XM320Muzzle {
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = false;
		};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.072;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.002;
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.072;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.002;
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.072;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.002;
		};
	};
	
	class m8_carbine : m8_base {
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		irDistance = 300;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	
	class m8_compact : m8_base {
		displayname = "M8 Compact CQC";
		
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
		};
		
		class Burst : Burst {
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
		};
		irDistance = 300;
	};
	
	class m8_sharpshooter : m8_base {
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		
		class Single : Single {
			recoil = "ACE_556x45_MG_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
			dispersion = 0.0016;
		};
		
		class Burst : Burst {
			recoil = "ACE_556x45_MG_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
			dispersion = 0.0016;
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_MG_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
			dispersion = 0.0016;
		};
		irDistance = 300;
	};
	
	class m8_carbineGL : m8_base {
		displayName = "M8 M320 CQC";
		
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class Burst : Burst {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		irDistance = 300;
	};
	
	class m8_compact_pmc : m8_compact {
		displayname = "M8 Compact Holo";
	};
	
	class m8_carbine_pmc : m8_base {
		irDistance = 300;
	};
	
	class m8_holo_sd : m8_base {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_T_G36", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
	};
	
	class m8_tws : m8_base {
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		
		class OpticsModes {
			class LTWS {
				cameradir = "";
				distancezoommax = 300;
				distancezoommin = 300;
				memorypointcamera = "eye";
				opticsdisableperipherialvision = true;
				opticsflare = true;
				opticsid = 1;
				opticsPPEffects[] = {};
				opticszoominit = 0.1606;
				opticszoommax = 0.1606;
				opticszoommin = 0.1606;
				thermalmode[] = {0, 1};
				usemodeloptics = 1;
				visionmode[] = {"Ti"};
			};
		};
		irDistance = 300;
	};
	
	class m8_tws_sd : m8_base {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_T_G36", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		
		class OpticsModes {
			class LTWS {
				cameradir = "";
				distancezoommax = 300;
				distancezoommin = 300;
				memorypointcamera = "eye";
				opticsdisableperipherialvision = true;
				opticsflare = true;
				opticsid = 1;
				opticsPPEffects[] = {};
				opticszoominit = 0.1606;
				opticszoommax = 0.1606;
				opticszoommin = 0.1606;
				thermalmode[] = {0, 1};
				usemodeloptics = 1;
				visionmode[] = {"Ti"};
			};
		};
	};
	
	class SCAR_Base : M16_base {
		class SCAR_L_Single : Single {
			reloadtime = 0.096;
			dispersion = 0.00225;
		};
		
		class SCAR_L_FullAuto : FullAuto {
			reloadtime = 0.096;
			dispersion = 0.00225;
		};
		
		class EGLMMuzzle : M203Muzzle {};
		
		class ACE_EGLMMuzzle_AI : EGLMMuzzle {
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = false;
		};
	};
	
	class SCAR_L_Base : SCAR_Base {
		class SCAR_L_Single;	// External class reference
		class SCAR_L_FullAuto;	// External class reference
	};
	
	class SCAR_L_STD_HOLO : SCAR_L_Base {
		irDistance = 300;
	};
	
	class SCAR_L_CQC : SCAR_L_Base {
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100, 200, 300, 400, 500, 600};
		discreteDistanceInitIndex = 2;
		
		class SCAR_L_Single : SCAR_L_Single {
			dispersion = 0.0025;
		};
		
		class SCAR_L_FullAuto : SCAR_L_FullAuto {
			dispersion = 0.0025;
		};
	};
	
	class SCAR_L_CQC_EGLM_Holo : SCAR_L_CQC {
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		
		class SCAR_L_Single : SCAR_L_Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class SCAR_L_FullAuto : SCAR_L_FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		irDistance = 300;
	};
	
	class SCAR_L_CQC_CCO_SD : SCAR_L_CQC {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD"};
		distanceZoomMin = 200;
		distanceZoomMax = 200;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		
		class SCAR_L_SD_Single : Mode_SemiAuto {
			reloadtime = 0.096;
			dispersion = 0.0025;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class SCAR_L_SD_FullAuto : Mode_FullAuto {
			reloadtime = 0.096;
			dispersion = 0.0025;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
	};
	
	class SCAR_L_STD_Mk4CQT : SCAR_L_Base {
		class SCAR_L_Single;	// External class reference
		class SCAR_L_FullAuto;	// External class reference
		irDistance = 300;
	};
	
	class SCAR_L_STD_EGLM_RCO : SCAR_L_STD_Mk4CQT {
		class SCAR_L_Single : SCAR_L_Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class SCAR_L_FullAuto : SCAR_L_FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		
		class OpticsModes {
			class ACOG {
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Kolimator : ACOG {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
	};
	
	class SCAR_H_Base : SCAR_Base {
		magazines[] = {"20Rnd_762x51_B_SCAR", "ACE_20Rnd_762x51_S_SCAR", "ACE_20Rnd_762x51_T_SCAR", "ACE_20Rnd_762x51_SB_SCAR", "ACE_20Rnd_762x51_SB_S_SCAR", "20Rnd_762x51_SB_SCAR"};
		
		class SCAR_H_Single : Mode_SemiAuto {
			reloadtime = 0.096;
			dispersion = 0.00225;
			recoil = "ACE_762x51_SCAR_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
		};
		
		class SCAR_H_FullAuto : Mode_FullAuto {
			reloadtime = 0.096;
			dispersion = 0.00225;
			recoil = "ACE_762x51_SCAR_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
		};
	};
	
	class SCAR_H_CQC_CCO : SCAR_H_Base {
		class SCAR_H_Single : SCAR_H_Single {
			dispersion = 0.00225;
		};
	};
	
	class SCAR_H_CQC_CCO_SD : SCAR_H_CQC_CCO {
		magazines[] = {"20Rnd_762x51_B_SCAR", "ACE_20Rnd_762x51_S_SCAR", "ACE_20Rnd_762x51_T_SCAR", "ACE_20Rnd_762x51_SB_SCAR", "ACE_20Rnd_762x51_SB_S_SCAR", "20Rnd_762x51_SB_SCAR"};
		irDistance = 300;
	};
	
	class SCAR_H_STD_EGLM_Spect : SCAR_H_CQC_CCO {
		irDistance = 300;
		
		class SCAR_H_Single : SCAR_H_Single {
			dispersion = 0.00175;
			recoil = "ACE_762x51_SCAR_Recoil_GL";
		};
		
		class SCAR_H_FullAuto : SCAR_H_FullAuto {
			dispersion = 0.00175;
			recoil = "ACE_762x51_SCAR_Recoil_GL";
		};
	};
	
	class SCAR_H_LNG_Sniper_SD : SCAR_H_Base {
		magazines[] = {"20Rnd_762x51_B_SCAR", "ACE_20Rnd_762x51_S_SCAR", "ACE_20Rnd_762x51_T_SCAR", "ACE_20Rnd_762x51_SB_SCAR", "ACE_20Rnd_762x51_SB_S_SCAR", "20Rnd_762x51_SB_SCAR"};
		modelOptics = "\x\ace\addons\m_wep_optics\SB_CQB_optic_4x";
		weaponInfoType = "RscWeaponEmpty";
		
		class OpticsModes {
			class StepScope {
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.22;
				opticsZoomInit = 0.22;
				opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		
		class SCAR_H_SD_Single : Mode_SemiAuto {
			reloadTime = 0.096;
			dispersion = 0.0006;
			recoil = "ACE_762x51_G3_Grip_Recoil";
		};
		
		class SCAR_H_SD_FullAuto : Mode_FullAuto {
			reloadTime = 0.096;
			dispersion = 0.0006;
			recoil = "ACE_762x51_G3_Grip_Recoil";
		};
	};
	
	class SCAR_H_STD_TWS_SD : SCAR_H_LNG_Sniper_SD {
		irDistance = 300;
		
		class SCAR_H_SD_Single : SCAR_H_SD_Single {
			dispersion = 0.00175;
		};
		
		class SCAR_H_SD_FullAuto : SCAR_H_SD_FullAuto {
			dispersion = 0.00175;
		};
	};
	
	class SCAR_H_LNG_Sniper : SCAR_H_Base {
		weaponInfoType = "RscWeaponEmpty";
		
		class OpticsModes {
			class StepScope {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.033574;
				opticsZoomMax = 0.087666;
				opticsZoomInit = 0.087666;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "eye";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		
		class SCAR_H_Single : SCAR_H_Single {
			dispersion = 0.0006;
		};
		
		class SCAR_H_FullAuto : SCAR_H_FullAuto {
			dispersion = 0.0006;
		};
	};
	
	class M24 : Rifle {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_10x_round_mildot";
		weaponInfoType = "RscWeaponEmpty";
		
		class OpticsModes {
			class StepScope {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.029624;
				opticsZoomMax = 0.029624;
				opticsZoomInit = 0.029624;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "usti hlavne";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		magazines[] = {"5Rnd_762x51_M24", "ACE_5Rnd_762x51_T_M24"};
		recoil = "ACE_762x51_Rifle_Recoil";
		recoilProne = "ACE_762x51_Rifle_RecoilProne";
		dispersion = 0.0002;
	};
	
	class DMR : Rifle {
		displayname = "M14 DMR";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_10x_round_mildot";
		
		class OpticsModes {
			class StepScope {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.029624;
				opticsZoomMax = 0.029624;
				opticsZoomInit = 0.029624;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "usti hlavne";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		magazines[] = {"20Rnd_762x51_DMR", "ACE_20Rnd_762x51_B_M14", "ACE_20Rnd_762x51_T_DMR", "ACE_20Rnd_762x51_S_DMR", "ACE_20Rnd_762x51_S_M14"};
		
		class Single : Mode_SemiAuto {
			recoil = "ACE_762x51_Rifle_Recoil";
			recoilProne = "ACE_762x51_Rifle_RecoilProne";
			dispersion = 0.00045;
			displayName = $STR_ACE_DN_MODE_SEMI;
		};
		handAnim[] = {};
	};
	
	class M110_TWS_EP1 : Rifle {
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		reloadTime = 0.1;
		magazines[] = {"ACE_20Rnd_762x51_SB_M110", "ACE_20Rnd_762x51_S_M110", "ACE_20Rnd_762x51_T_M110", "ACE_20Rnd_762x51_SB_SCAR", "ACE_20Rnd_762x51_SB_S_SCAR", "ACE_20Rnd_762x51_T_SCAR", "20Rnd_762x51_B_SCAR", "ACE_20Rnd_762x51_S_SCAR", "20Rnd_762x51_SB_SCAR"};
		weaponInfoType = "RscWeaponEmpty";
		
		class OpticsModes {
			class HTWS {
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.0249;
				distanceZoomMin = 300;
				opticsZoomMax = 0.0755;
				distanceZoomMax = 300;
				opticsZoomInit = 0.0755;
				memoryPointCamera = "eye";
				opticsFlare = "true";
				opticsDisablePeripherialVision = "true";
				cameraDir = "";
				opticsPPEffects[] = {};
				visionMode[] = {"Ti"};
				thermalMode[] = {0, 1};
				discretefov[] = {0.0755, 0.0249};
				discreteInitIndex = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
			};
		};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.0003;
			recoil = "ACE_762x51_Rifle_Recoil";
			recoilProne = "ACE_762x51_Rifle_RecoilProne";
			displayName = $STR_ACE_DN_MODE_SEMI;
		};
	};
	
	class M110_NVG_EP1 : M110_TWS_EP1 {
		modelOptics = "\x\ace\Addons\m_wep_optics\NWD_875x_illum_round_mildot";
		opticsZoomMin = 0.033574;
		opticsZoomMax = 0.033574;
		opticsZoomInit = 0.033574;
		
		class OpticsModes : OpticsModes {
			class StepScope : HTWS {
				opticsZoomMin = 0.033574;
				opticsZoomMax = 0.033574;
				opticsZoomInit = 0.033574;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				visionMode[] = {"Normal", NVG};
				thermalMode[] = {};
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				discretefov[] = {};
			};
		};
	};
	
	class m107 : Rifle {
		ace_heavy = 1;
		type = VArmor;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_14x_oval_mildot";
		opticsZoomMin = 0.020984;
		opticsZoomMax = 0.05246;
		distanceZoomMin = 500;
		distanceZoomMax = 500;
		magazines[] = {"10Rnd_127x99_m107", "ACE_10Rnd_127x99_T_m107", "ACE_10Rnd_127x99_Raufoss_m107"};
		recoil = "ACE_127x99_Rifle_Recoil";
		recoilProne = "ACE_127x99_Rifle_RecoilProne";
		reloadTime = 0.25;
		dispersion = 0.0006;
		weaponInfoType = "RscWeaponEmpty";
		visionMode[] = {"Normal"};
		
		class OpticsModes {
			class StepScope {
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				opticsZoomInit = 0.05246;
				opticsZoomMin = 0.020984;
				opticsZoomMax = 0.05246;
				distanceZoomMax = 500;
				distanceZoomMin = 500;
				memoryPointCamera = "konec hlavne";
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				visionMode[] = {"Normal"};
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
			};
		};
	};
	
	class m107_TWS_EP1 : m107 {
		distanceZoomMin = 519;
		distanceZoomMax = 519;
		
		class OpticsModes : OpticsModes {
			class HWTS : StepScope {
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomInit = 0.0553;
				opticsZoomMin = 0.0178;
				opticsZoomMax = 0.0553;
				distanceZoomMin = 500;
				distanceZoomMax = 500;
				memoryPointCamera = "konec hlavne";
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				opticsPPEffects[] = {};
				visionMode[] = {"Ti"};
				thermalMode[] = {0, 1};
				discretefov[] = {0.0755, 0.0249};
				discreteInitIndex = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
			};
		};
	};
	
	class huntingrifle : M24 {
		displayName = "CZ 550";
		distanceZoomMin = 329;
		distanceZoomMax = 329;
		dispersion = 0.0008;
		
		class OpticsModes : OpticsModes {
			class StepScope : StepScope {
				opticsZoomMin = 0.025;
				opticsZoomMax = 0.1;
				opticsZoomInit = 0.1;
			};
		};
	};
	
	class M1014 : Rifle {
		class Single : Mode_SemiAuto {
			reloadtime = 0.1;
			dispersion = 0.005;
			recoil = "ACE_Shotgun_Recoil";
			recoilProne = "ACE_Shotgun_RecoilProne";
		};
	};
	
	class FN_FAL : M16A2 {
		displayName = "FN FAL Para";
		magazines[] = {"20Rnd_762x51_FNFAL", "ACE_20Rnd_762x51_B_FAL", "ACE_20Rnd_762x51_T_FAL"};
		
		class Single : Single {
			reloadTime = 0.085;
			dispersion = 0.00175;
			recoil = "ACE_762x51_FAL_Recoil";
			recoilProne = "ACE_762x51_Rifle_RecoilProne";
		};
		
		class Burst : Burst {
			reloadTime = 0.085;
			dispersion = 0.00175;
			recoil = "ACE_762x51_FAL_Recoil";
			recoilProne = "ACE_762x51_Rifle_RecoilProne";
			showToPlayer = false;
		};
		
		class Armory {
			disabled = 0;
		};
	};
	
	class LeeEnfield : Rifle {
		magazines[] = {"10x_303", "ACE_10Rnd_77x56_T_SMLE"};
		autofire = false;
		recoil = "ACE_762x54R_Rifle_Recoil";
		recoilProne = "ACE_762x54R_Rifle_RecoilProne";
		dispersion = 0.0005;
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
		discreteDistanceInitIndex = 2;
		weaponInfoType = "RscWeaponZeroing";
	};
	
	class M14_EP1 : Rifle {
		displayName = $STR_ACE_WDN_M14_AIMPOINT;
		magazines[] = {"20Rnd_762x51_DMR", "ACE_20Rnd_762x51_B_M14", "ACE_20Rnd_762x51_T_DMR", "ACE_20Rnd_762x51_S_DMR", "ACE_20Rnd_762x51_S_M14"};
		
		class Single : Mode_SemiAuto {
			recoil = "ACE_762x51_SCAR_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
			dispersion = 0.0007;
			reloadTime = 0.08;
			displayName = $STR_ACE_DN_MODE_SEMI;
		};
	};
	
	class GrenadeLauncher_EP1 : Rifle {};
	
	class M32_EP1 : GrenadeLauncher_EP1 {
		magazines[] = {"6Rnd_HE_M203", "6Rnd_FlareWhite_M203", "6Rnd_FlareGreen_M203", "6Rnd_FlareRed_M203", "6Rnd_FlareYellow_M203", "6Rnd_Smoke_M203", "6Rnd_SmokeRed_M203", "6Rnd_SmokeGreen_M203", "6Rnd_SmokeYellow_M203", "ACE_6Rnd_CS_M32", "1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
		muzzles[] = {this, "ACE_M32Muzzle_AI"};
		
		class ACE_M32Muzzle_AI : ACE_M203Muzzle_AI {
			magazines[] = {"6Rnd_HE_M203", "6Rnd_FlareWhite_M203", "6Rnd_FlareGreen_M203", "6Rnd_FlareRed_M203", "6Rnd_FlareYellow_M203", "6Rnd_Smoke_M203", "6Rnd_SmokeRed_M203", "6Rnd_SmokeGreen_M203", "6Rnd_SmokeYellow_M203", "ACE_6Rnd_CS_M32", "1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
			airateoffire = 0.5;	// delay between shots at given distance
			reloadtime = 0.5;
		};
	};
	
	class M79_EP1 : GrenadeLauncher_EP1 {
		magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_40mm_Buck_M79", ACE_M576, "ACE_FlareIR_M203"};
		muzzles[] = {this, "ACE_M203Muzzle_AI"};
	};
	
	class Mk13_EP1 : GrenadeLauncher_EP1 {
		magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
		muzzles[] = {this, "ACE_M203Muzzle_AI"};
	};
	
	class AK_BASE : Rifle {
		magazines[] = {"30Rnd_545x39_AK", "ACE_30Rnd_545x39_S_AK", "ACE_30Rnd_545x39_T_AK", "ACE_45Rnd_545x39_B_AK", "ACE_45Rnd_545x39_S_AK", "75Rnd_545x39_RPK", "ACE_75Rnd_545x39_S_RPK", "ACE_75Rnd_545x39_T_RPK", "ACE_30Rnd_545x39_EP_AK", "ACE_30Rnd_545x39_EP_S_AK", "ACE_30Rnd_545x39_AP_AK", "ACE_30Rnd_545x39_AP_S_AK", "ACE_45Rnd_545x39_EP_AK", "ACE_45Rnd_545x39_EP_S_AK", "ACE_45Rnd_545x39_AP_AK", "ACE_45Rnd_545x39_AP_S_AK", "30Rnd_545x39_AKSD"};
		
		class GP25Muzzle : GrenadeLauncher {
			magazines[] = {"1Rnd_HE_GP25", "ACE_1Rnd_HE_GP25P", "FlareWhite_GP25", "FlareGreen_GP25", "FlareRed_GP25", "FlareYellow_GP25", "1Rnd_SMOKE_GP25", "1Rnd_SMOKERED_GP25", "1Rnd_SMOKEGREEN_GP25", "1Rnd_SMOKEYELLOW_GP25", "ACE_1Rnd_CS_GP25", "ACE_SSWhite_GP25", "ACE_SSGreen_GP25", "ACE_SSRed_GP25", "ACE_SSYellow_GP25", ACE_VG40SZ};
			magazineReloadTime = 0;
			reloadTime = 0.1;
			recoil = "ACE_GL_Recoil";
			optics = true;
			modelOptics = "-";
			cameraDir = "GL look";
			memoryPointCamera = "GL eye";
			opticsZoomMin = 0.3;
			opticsZoomMax = 0.5;
			opticsZoomInit = 0.5;
			ACE_GRENADE_TYPE = GP25;
			opticsPPEffects[] = {};
			weaponInfoType = "RscWeaponEmpty";
		};
		
		class ACE_GP25Muzzle_AI : GP25Muzzle {
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = false;
		};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.00225;
			recoil = "ACE_545x39_Rifle_Recoil";
			recoilProne = "ACE_545x39_Rifle_RecoilProne";
		};
		
		class Burst : Mode_Burst {
			dispersion = 0.00225;
			recoil = "ACE_545x39_Rifle_Recoil_B";
			recoilProne = "ACE_545x39_Rifle_RecoilProne";
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00225;
			recoil = "ACE_545x39_Rifle_Recoil_B";
			recoilProne = "ACE_545x39_Rifle_RecoilProne";
		};
	};
	
	class AKS_BASE : AK_BASE {
		class Single : Single {
			dispersion = 0.00225;
		};
		
		class Burst : Burst {
			dispersion = 0.00225;
		};
		
		class FullAuto : FullAuto {
			dispersion = 0.00225;
		};
	};
	
	class AK_107_BASE : AK_BASE {
		class Single : Single {
			dispersion = 0.0021;
			recoil = "ACE_545x39_Rifle_Recoil_Low";
			reloadtime = 0.07;
		};
		
		class Burst : Burst {
			dispersion = 0.0021;
			recoil = "ACE_545x39_Rifle_Recoil_Low";
			reloadtime = 0.07;
		};
		
		class FullAuto : FullAuto {
			dispersion = 0.0021;
			recoil = "ACE_545x39_Rifle_Recoil_Low";
			reloadtime = 0.07;
		};
	};
	
	class AK_47_M : AK_BASE {
		magazines[] = {"30Rnd_762x39_AK47", "ACE_30Rnd_762x39_S_AK47", "ACE_30Rnd_762x39_T_AK47", "ACE_40Rnd_762x39_B_AK47", "ACE_40Rnd_762x39_S_AK47", "ACE_40Rnd_762x39_T_AK47", "ACE_75Rnd_762x39_B_AK47", "ACE_75Rnd_762x39_S_AK47", "ACE_30Rnd_762x39_AP_AK47", "ACE_30Rnd_762x39_AP_S_AK47", "ACE_40Rnd_762x39_AP_AK47", "ACE_40Rnd_762x39_AP_S_AK47", "ACE_30Rnd_762x39_SD_AK47", "ACE_75Rnd_762x39_SD_AK47"};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.00225;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
		};
		
		class Burst : Mode_Burst {
			dispersion = 0.00225;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00225;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
		};
	};
	
	class AK_74 : AK_BASE {
		displayName = $STR_ACE_WDN_AK_74;
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800};
		discreteDistanceInitIndex = 2;
		weaponInfoType = "RscWeaponZeroing";
		distanceZoomMin = 300;
		distanceZoomMax = 300;
	};
	
	class AK_74_GL : AK_BASE {
		displayName = $STR_ACE_WDN_AK_74_GL;
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800};
		discreteDistanceInitIndex = 2;
		weaponInfoType = "RscWeaponZeroing";
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		
		class Single : Single {
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
		
		class Burst : Burst {
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
	};
	
	class AK_74_GL_kobra : AK_74_GL {
		weaponInfoType = "RscWeaponEmpty";
	};
	
	class AK_107_GL_kobra : AK_107_BASE {
		displayName = $STR_ACE_WDN_AK_107_GL;
	};
	
	class AK_107_GL_pso : AK_107_GL_kobra {
		displayName = $STR_ACE_WDN_AK_107_GL_PSO;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		weaponInfoType = "RscWeaponZeroing";
		
		class OpticsModes {
			class Scope {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
				discreteDistanceInitIndex = 2;
			};
		};
	};
	
	class AK_107_pso : AK_107_BASE {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		weaponInfoType = "RscWeaponZeroing";
		
		class OpticsModes {
			class Scope {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
				discreteDistanceInitIndex = 2;
			};
		};
		
		class Single : Single {
			dispersion = 0.002;
		};
	};
	
	class AKS_74_pso : AKS_BASE {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		weaponInfoType = "RscWeaponZeroing";
		
		class OpticsModes {
			class Scope {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
				discreteDistanceInitIndex = 2;
			};
		};
		
		class Single : Single {
			dispersion = 0.002;
		};
	};
	
	class AKS_74_NSPU : AKS_BASE {
		weaponInfoType = "RscWeaponZeroing";
		
		class OpticsModes {
			class NSPU {
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				opticsPPEffects[] = {};
				opticsDisablePeripherialVision = true;
				memoryPointCamera = "opticView";
				visionMode[] = {NVG};
				opticsFlare = true;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				cameraDir = "";
				discreteDistance[] = {400, 500, 600, 700, 800, 900, 1000};
				discreteDistanceInitIndex = 0;
			};
			
			class Ironsights : NSPU {
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
	};
	
	class AKS_74_GOSHAWK : AKS_BASE {
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800};
		discreteDistanceInitIndex = 2;
	};
	
	class AKS_74 : AKS_BASE {
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800};
		discreteDistanceInitIndex = 2;
	};
	
	class AKS_74_U : AKS_BASE {
		class Single : Single {
			dispersion = 0.00275;
			reloadTime = 0.092;
			recoil = "ACE_545x39_Rifle_Recoil_AKSU";
		};
		
		class Burst : Burst {
			dispersion = 0.00275;
			reloadTime = 0.092;
			recoil = "ACE_545x39_Rifle_Recoil_AKSU";
		};
		
		class FullAuto : FullAuto {
			dispersion = 0.00275;
			reloadTime = 0.092;
			recoil = "ACE_545x39_Rifle_Recoil_AKSU";
		};
		discreteDistance[] = {200, 400};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponZeroing";
		distanceZoomMin = 200;
		distanceZoomMax = 200;
	};
	
	class AKS_74_UN_kobra : AKS_BASE {
		fireLightIntensity = 0;
		fireLightDuration = 0;
		magazines[] = {"30Rnd_545x39_AK", "ACE_30Rnd_545x39_S_AK", "ACE_30Rnd_545x39_T_AK", "ACE_45Rnd_545x39_B_AK", "ACE_45Rnd_545x39_S_AK", "75Rnd_545x39_RPK", "ACE_75Rnd_545x39_S_RPK", "ACE_75Rnd_545x39_T_RPK", "ACE_30Rnd_545x39_EP_AK", "ACE_30Rnd_545x39_EP_S_AK", "ACE_30Rnd_545x39_AP_AK", "ACE_30Rnd_545x39_AP_S_AK", "ACE_45Rnd_545x39_EP_AK", "ACE_45Rnd_545x39_EP_S_AK", "ACE_45Rnd_545x39_AP_AK", "ACE_45Rnd_545x39_AP_S_AK", "30Rnd_545x39_AKSD"};
		
		class Single : Single {
			dispersion = 0.00275;
			reloadTime = 0.092;
			recoil = "ACE_545x39_Rifle_Recoil_AKSU";
		};
		
		class Burst : Burst {
			dispersion = 0.00275;
			reloadTime = 0.092;
			recoil = "ACE_545x39_Rifle_Recoil_AKSU";
		};
		
		class FullAuto : FullAuto {
			dispersion = 0.00275;
			reloadTime = 0.092;
			recoil = "ACE_545x39_Rifle_Recoil_AKSU";
		};
	};
	
	class SVD : Rifle {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1";
		distanceZoomMin = 330;
		distanceZoomMax = 330;
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		magazines[] = {"10Rnd_762x54_SVD", "ACE_10Rnd_762x54_T_SVD"};
		recoil = "ACE_762x54R_Rifle_Recoil";
		recoilProne = "ACE_762x54R_Rifle_RecoilProne";
		dispersion = 0.0006;
	};
	
	class SVD_NSPU_EP1 : SVD {
		distanceZoomMin = 330;
		distanceZoomMax = 330;
		
		class OpticsModes {
			class NSPU {
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				opticsPPEffects[] = {};
				opticsDisablePeripherialVision = true;
				memoryPointCamera = "opticView";
				visionMode[] = {NVG};
				opticsFlare = true;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				cameraDir = "";
			};
			
			class Ironsights : NSPU {
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
	};
	
	class VSS_vintorez : Rifle {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1";
		distanceZoomMin = 120;
		distanceZoomMax = 120;
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		visionMode[] = {"Normal"};
		magazines[] = {"20Rnd_9x39_SP5_VSS", "10Rnd_9x39_SP5_VSS", "ACE_20Rnd_9x39_SP6_VSS", "ACE_10Rnd_9x39_SP6_VSS"};
		
		class Single : Mode_SemiAuto {
			recoil = "ACE_545x39_Rifle_Recoil";
			recoilProne = "ACE_545x39_Rifle_RecoilProne";
		};
		
		class Full : Mode_FullAuto {
			recoil = "ACE_545x39_Rifle_Recoil";
			recoilProne = "ACE_545x39_Rifle_RecoilProne";
		};
	};
	
	class ksvk : Rifle {
		ace_heavy = 1;
		type = VArmor;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_3_1";
		distanceZoomMin = 517;
		distanceZoomMax = 517;
		opticsZoomMin = 0.035972;
		opticsZoomMax = 0.035972;
		magazines[] = {"5Rnd_127x108_KSVK", "ACE_5Rnd_127x108_T_KSVK"};
		recoil = "ACE_127x108_Rifle_Recoil";
		recoilProne = "ACE_127x108_Rifle_RecoilProne";
		dispersion = 0.0005;
	};
	
	class Saiga12K : Rifle {
		class Single : Mode_SemiAuto {
			reloadtime = 0.1;
			dispersion = 0.005;
			recoil = "ACE_Shotgun_Recoil";
			recoilProne = "ACE_Shotgun_RecoilProne";
		};
	};
	
	class Sa58P_EP1 : Rifle {
		magazines[] = {"30Rnd_762x39_SA58", "ACE_30Rnd_762x39_T_SA58"};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.0022;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			reloadTime = 0.075;
		};
		
		class Burst : Mode_Burst {
			dispersion = 0.0022;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			reloadTime = 0.075;
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.0022;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			reloadTime = 0.075;
		};
	};
	class Sa58V_EP1;	// External class reference
	
	class Sa58V_RCO_EP1 : Sa58V_EP1 {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_acog_ta01nsnAK";
		
		class OpticsModes {
			class ACOG {
				opticsID = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 100;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Ironsigts : ACOG {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		irDistance = 300;
		
		class Burst : Mode_Burst {
			dispersion = 0.0022;
			recoil = "ACE_762x39_Rifle_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			reloadTime = 0.075;
		};
	};
	
	class Sa58V_CCO_EP1 : Sa58V_EP1 {
		irDistance = 300;
	};
	
	class BAF_L17_40mm : GrenadeLauncher {
		magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
	};
	
	class L85A2_base_BAF : Rifle {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD"};
		
		class BAF_L17_40mm : BAF_L17_40mm {
			magazines[] = {"1Rnd_HE_M203", "ACE_1Rnd_HE_M203", "ACE_1Rnd_PR_M203", "FlareWhite_M203", "FlareGreen_M203", "FlareRed_M203", "FlareYellow_M203", "1Rnd_Smoke_M203", "1Rnd_SmokeRed_M203", "1Rnd_SmokeGreen_M203", "1Rnd_SmokeYellow_M203", "ace_1rnd_cs_m203", "ACE_HuntIR_M203", "ACE_SSWhite_M203", "ACE_SSGreen_M203", "ACE_SSRed_M203", "ACE_SSYellow_M203", "ACE_FlareIR_M203", "ACE_40mm_Buck_M79", ACE_M576};
			magazineReloadTime = 0;
			reloadTime = 0.1;
			optics = true;
			modelOptics = "-";
			cameraDir = "UGL look";
			memoryPointCamera = "UGL eye";
			opticsZoomMin = 0.3;
			opticsZoomMax = 0.5;
			opticsZoomInit = 0.5;
			ACE_GRENADE_TYPE = M203;
			recoil = "ACE_GL_Recoil";
			opticsPPEffects[] = {};
		};
		
		class ACE_L17_AI : BAF_L17_40mm {
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = false;
		};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.00175;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00175;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
		};
		irDistance = 300;
	};
	
	class BAF_L85A2_RIS_ACOG : L85A2_base_BAF {
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31doc";
		
		class OpticsModes {
			class ACOG {
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Kolimator : ACOG {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
	};
	
	class BAF_L85A2_UGL_ACOG : BAF_L85A2_RIS_ACOG {
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class BAF_L85A2_RIS_Holo : L85A2_base_BAF {};
	
	class BAF_L85A2_UGL_Holo : BAF_L85A2_RIS_Holo {
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class BAF_L85A2_RIS_SUSAT : L85A2_base_BAF {
		modelOptics = "\x\ace\addons\m_wep_optics\ukf_susat3";
		
		class OpticsModes {
			class SUSAT {
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {300, 400, 500, 600, 700, 800};
				discreteDistanceInitIndex = 0;
			};
			
			class ironsights : SUSAT {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
	};
	
	class BAF_L85A2_UGL_SUSAT : BAF_L85A2_RIS_SUSAT {
		class Single : Single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class FullAuto : FullAuto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class BAF_L86A2_ACOG : Rifle {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD"};
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31doc";
		
		class OpticsModes {
			class ACOG {
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Kolimator : ACOG {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		
		class Single : Mode_SemiAuto {
			dispersion = 0.00175;
			recoil = "ACE_556x45_MG_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
		};
		
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00175;
			recoil = "ACE_556x45_MG_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
		};
	};
	
	class BAF_L85A2_RIS_CWS : L85A2_base_BAF {
		visionMode[] = {"Normal", NVG};
	};
	
	class BAF_AS50_scoped : Rifle {
		ace_heavy = 1;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_12x_gen2_mildot";
		
		class Single : Mode_SemiAuto {
			recoil = "ACE_127x99_Rifle_Recoil";
			recoilProne = "ACE_127x99_Rifle_RecoilProne";
			dispersion = 0.00045;
		};
		magazines[] = {"5Rnd_127x99_as50", "ACE_5Rnd_127x99_B_TAC50", "ACE_5Rnd_127x99_S_TAC50", "ACE_5Rnd_127x99_T_TAC50"};
		weaponInfoType = "RscWeaponEmpty";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		distanceZoomMin = 500;
		distanceZoomMax = 500;
		opticsZoomMin = 0.0256;
		opticsZoomMax = 0.082;
		opticsZoomInit = 0.082;
		discretefov[] = {};
		discreteInitIndex = 0;
	};
	
	class PMC_AS50_scoped : BAF_AS50_scoped {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_12x_gen2_mildot";
	};
	
	class BAF_LRR_scoped : Rifle {
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_12x_gen2_mildot";
		
		class Single : Mode_SemiAuto {
			dispersion = 0.00018;
			recoil = "ACE_338_Rifle_Recoil";
			recoilProne = "ACE_338_Rifle_RecoilProne";
		};
		magazines[] = {"5Rnd_86x70_L115A1", "ACE_5Rnd_86x70_T_L115A1"};
		weaponInfoType = "RscWeaponEmpty";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		handAnim[] = {};
		opticsZoomMin = 0.0256;
		opticsZoomMax = 0.082;
		opticsZoomInit = 0.082;
		discretefov[] = {};
		discreteInitIndex = 0;
	};
	
	class ACE_M4A1_C : M4A1 {
		model = "\ca\weapons_E\m4a3\m4a1";
		picture = "\ca\Weapons\Data\equip\w_m4_ca";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_M4_C : ACE_M4A1_C {
		displayname = "M4";
		modes[] = {"Single", "ACE_Burst"};
	};
	
	class M40A3 : M24 {
		displayName = M40A3;
	};
	
	class CZ_750_S1_ACR : M40A3 {
		displayName = "CZ 750";
		dispersion = 0.0002;
	};
	
	class CZ805_A1_ACR : Rifle {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_T_G36", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		
		class OpticsModes {
			class Mk4 {
				opticsID = 1;
				useModelOptics = 0;
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				cameraDir = "";
			};
			
			class Kolimator : Mk4 {
				opticsID = 1;
				useModelOptics = 0;
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				cameraDir = "";
			};
		};
		modes[] = {"single", "burst", "fullauto"};
		
		class single : Mode_SemiAuto {
			dispersion = 0.00225;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class burst : Mode_Burst {
			dispersion = 0.00225;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class fullauto : Mode_FullAuto {
			dispersion = 0.00225;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		class M203Muzzle;	// External class reference
	};
	
	class CZ805_A1_GL_ACR : CZ805_A1_ACR {
		class M203Muzzle : M203Muzzle {
			opticsZoomMin = 0.25;
			opticsZoomMax = 1.1;
			opticsZoomInit = 0.5;
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		
		class single : single {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class burst : burst {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		
		class fullauto : fullauto {
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
	};
	
	class CZ805_A2_ACR : CZ805_A1_ACR {
		class single : Mode_SemiAuto {
			dispersion = 0.0025;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class burst : Mode_Burst {
			dispersion = 0.0025;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class fullauto : Mode_FullAuto {
			dispersion = 0.0025;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
	};
	
	class CZ805_A2_SD_ACR : CZ805_A2_ACR {
		magazines[] = {"30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_T_G36", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_StanagSD", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		fireLightIntensity = 0;
		fireLightDuration = 0;
		
		class single : Mode_SemiAuto {
			dispersion = 0.0025;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class burst : Mode_Burst {
			dispersion = 0.0025;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
		
		class fullauto : Mode_FullAuto {
			dispersion = 0.0025;
			reloadtime = 0.079;
			recoil = "ACE_556x45_Rifle_Recoil_B";
			recoilprone = "ACE_556x45_Rifle_RecoilProne";
		};
	};
	
	class CZ805_B_GL_ACR : CZ805_A1_ACR {
		magazines[] = {"20Rnd_762x51_B_SCAR", "ACE_20Rnd_762x51_S_SCAR", "ACE_20Rnd_762x51_T_SCAR", "ACE_20Rnd_762x51_SB_SCAR", "ACE_20Rnd_762x51_SB_S_SCAR", "20Rnd_762x51_SB_SCAR"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		
		class OpticsModes {
			class ACOG {
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Kolimator : ACOG {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		
		class M203Muzzle : M203Muzzle {
			opticsZoomMin = 0.25;
			opticsZoomMax = 1.1;
			opticsZoomInit = 0.5;
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		
		class single : Mode_SemiAuto {
			dispersion = 0.00175;
			reloadtime = 0.079;
			recoil = "ACE_762x51_SCAR_Recoil_GL";
			recoilprone = "ACE_762x51_SCAR_RecoilProne";
		};
		
		class burst : Mode_Burst {
			dispersion = 0.00175;
			reloadtime = 0.079;
			recoil = "ACE_762x51_SCAR_Recoil_GL";
			recoilprone = "ACE_762x51_SCAR_RecoilProne";
		};
		
		class fullauto : Mode_FullAuto {
			dispersion = 0.00175;
			reloadtime = 0.079;
			recoil = "ACE_762x51_SCAR_Recoil_GL";
			recoilprone = "ACE_762x51_SCAR_RecoilProne";
		};
	};
	
	class MachineGun {
		scope = private;
		
		class Armory {
			disabled = 1;
		};
	};
	
	class M240 : Rifle {
		displayName = M240G;
		type = VArmor;
		distanceZoomMin = 420;
		distanceZoomMax = 420;
		
		class manual : Mode_FullAuto {
			dispersion = 0.003;
			recoil = "ACE_M240_Recoil";
			recoilProne = "ACE_M240_RecoilProne";
			displayName = $STR_ACE_DN_MODE_AUTO;
		};
		class close;	// External class reference
		class short;	// External class reference
		class medium;	// External class reference
		class far;	// External class reference
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
		discreteDistanceInitIndex = 3;
	};
	
	class m240_scoped_EP1 : M240 {
		displayName = "M240G M145";
		weaponInfoType = "RscWeaponEmpty";
		modelOptics = "\x\ace\addons\m_wep_optics\ace_optics_m145";
		
		class OpticsModes {
			class M145 {
				opticsID = 1;
				distanceZoomMin = 308;
				distanceZoomMax = 308;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class Ironsights : M145 {
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
	};
	
	class ACE_BAF_L7A2_GPMG : m240_scoped_EP1 {
		displayName = "L7A2 GPMG M145";
	};
	
	class Mk_48 : M240 {
		weaponInfoType = "RscWeaponEmpty";
		displayName = "Mk48 Mod 0";
		type = VArmor;
		
		class manual : manual {
			dispersion = 0.003;
			recoil = "ACE_Mk48_Recoil";
			recoilProne = "ACE_Mk48_RecoilProne";
			reloadTime = 0.082;
		};
		
		class close : close {
			dispersion = 0.003;
			recoil = "ACE_Mk48_Recoil";
			recoilProne = "ACE_Mk48_RecoilProne";
			reloadTime = 0.082;
		};
		
		class short : short {
			dispersion = 0.003;
			recoil = "ACE_Mk48_Recoil";
			recoilProne = "ACE_Mk48_RecoilProne";
			reloadTime = 0.082;
		};
		
		class medium : medium {
			dispersion = 0.003;
			recoil = "ACE_Mk48_Recoil";
			recoilProne = "ACE_Mk48_RecoilProne";
			reloadTime = 0.082;
		};
		
		class far : far {
			dispersion = 0.003;
			recoil = "ACE_Mk48_Recoil";
			recoilProne = "ACE_Mk48_RecoilProne";
			reloadTime = 0.082;
		};
	};
	
	class Mk_48_DES_EP1 : Mk_48 {
		displayName = "Mk48 Mod 0";
		irDistance = 300;
	};
	
	class M60A4_EP1 : Rifle {
		type = VArmor;
		discreteDistance[] = {300, 400, 500, 600, 700, 800, 900, 1000, 1100};
		discreteDistanceInitIndex = 2;
		
		class manual : Mode_FullAuto {
			dispersion = 0.0035;
			reloadtime = 0.11;
			recoil = "ACE_M240_Recoil";
			recoilProne = "ACE_M240_RecoilProne";
			displayName = $STR_ACE_DN_MODE_AUTO;
		};
	};
	
	class M249 : Rifle {
		type = VArmor;
		magazines[] = {"200Rnd_556x45_M249", "200Rnd_556x45_L110A1", "ACE_200Rnd_556x45_T_M249", "100Rnd_556x45_M249", "ACE_100Rnd_556x45_T_M249", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_T_Stanag", "20Rnd_556x45_Stanag", "100Rnd_556x45_BetaCMag", "30Rnd_556x45_StanagSD", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag"};
		
		class manual : Mode_FullAuto {
			dispersion = 0.0035;
			recoil = "ACE_M249_Recoil";
			recoilProne = "ACE_M249_RecoilProne";
			displayName = $STR_ACE_DN_MODE_AUTO;
		};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
		discreteDistanceInitIndex = 3;
	};
	
	class M249_EP1 : M249 {
		magazines[] = {"200Rnd_556x45_M249", "200Rnd_556x45_L110A1", "ACE_200Rnd_556x45_T_M249", "100Rnd_556x45_M249", "ACE_100Rnd_556x45_T_M249", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_T_Stanag", "20Rnd_556x45_Stanag", "100Rnd_556x45_BetaCMag", "30Rnd_556x45_StanagSD", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag"};
		irDistance = 300;
	};
	
	class M249_TWS_EP1 : M249 {
		magazines[] = {"200Rnd_556x45_M249", "200Rnd_556x45_L110A1", "ACE_200Rnd_556x45_T_M249", "100Rnd_556x45_M249", "ACE_100Rnd_556x45_T_M249", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_T_Stanag", "20Rnd_556x45_Stanag", "100Rnd_556x45_BetaCMag", "30Rnd_556x45_StanagSD", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag"};
		weaponInfoType = "RscWeaponEmpty";
		irDistance = 300;
	};
	
	class M249_m145_EP1 : M249 {
		displayName = "M249 M145";
		magazines[] = {"200Rnd_556x45_M249", "200Rnd_556x45_L110A1", "ACE_200Rnd_556x45_T_M249", "100Rnd_556x45_M249", "ACE_100Rnd_556x45_T_M249", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_T_Stanag", "20Rnd_556x45_Stanag", "100Rnd_556x45_BetaCMag", "30Rnd_556x45_StanagSD", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag"};
		weaponInfoType = "RscWeaponEmpty";
		modelOptics = "\x\ace\addons\m_wep_optics\ace_optics_m145";
		
		class OpticsModes {
			class M145 {
				opticsID = 1;
				distanceZoomMin = 308;
				distanceZoomMax = 308;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			
			class CQB : M145 {
				opticsID = 2;
				distanceZoomMin = 50;
				distanceZoomMax = 50;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		irDistance = 300;
	};
	
	class MG36 : G36C {
		type = VArmor;
		magazines[] = {"100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_G36", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.08;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
			dispersion = 0.0018;
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.08;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
			dispersion = 0.0018;
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.08;
			recoil = "ACE_556x45_Rifle_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
			dispersion = 0.0018;
		};
	};
	
	class m8_SAW : m8_sharpshooter {
		type = VArmor;
		magazines[] = {"100Rnd_556x45_BetaCMag", "ACE_100Rnd_556x45_S_BetaCMag", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_S_Stanag", "30Rnd_556x45_G36", "ACE_30Rnd_556x45_S_G36", "ACE_30Rnd_556x45_T_Stanag", "ACE_30Rnd_556x45_T_G36", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag", "20Rnd_556x45_Stanag", "ACE_20Rnd_556x45_S_Stanag", "30Rnd_556x45_StanagSD", "30Rnd_556x45_G36SD", "ACE_30Rnd_556x45_AP_G36"};
		
		class manual : Mode_FullAuto {
			dispersion = 0.002;
			reloadTime = 0.072;
			recoil = "ACE_556x45_MG_Recoil";
			recoilProne = "ACE_556x45_MG_RecoilProne";
		};
	};
	
	class PK : Rifle {
		type = VArmor;
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		
		class manual : Mode_FullAuto {
			dispersion = 0.004;
			recoil = "ACE_762x54R_MG_Recoil";
			recoilProne = "ACE_762x54R_MG_RecoilProne";
			displayName = $STR_ACE_DN_MODE_AUTO;
		};
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
		discreteDistanceInitIndex = 3;
	};
	
	class Pecheneg : PK {
		displayName = $STR_ACE_WDN_PECHENEG;
		type = VArmor;
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		
		class manual : manual {
			dispersion = 0.003;
		};
		
		class OpticsModes {
			class 1P29 {
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1"};
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				cameraDir = "";
				discreteDistance[] = {400, 500, 600, 700, 800, 900, 1000, 1100, 1200};
				discreteDistanceInitIndex = 0;
			};
		};
	};
	
	class RPK_74 : AK_74 {
		displayName = "RPK-74";
		type = VArmor;
		magazines[] = {"ACE_45Rnd_545x39_B_AK", "ACE_45Rnd_545x39_S_AK", "75Rnd_545x39_RPK", "ACE_75Rnd_545x39_S_RPK", "ACE_75Rnd_545x39_T_RPK", "ACE_45Rnd_545x39_EP_AK", "ACE_45Rnd_545x39_EP_S_AK", "ACE_45Rnd_545x39_AP_AK", "ACE_45Rnd_545x39_AP_S_AK", "30Rnd_545x39_AK", "ACE_30Rnd_545x39_S_AK", "ACE_30Rnd_545x39_T_AK", "ACE_30Rnd_545x39_EP_AK", "ACE_30Rnd_545x39_EP_S_AK", "ACE_30Rnd_545x39_AP_AK", "ACE_30Rnd_545x39_AP_S_AK", "30Rnd_545x39_AKSD"};
		
		class manual : Mode_FullAuto {
			recoil = "ACE_545x39_MG_Recoil";
			recoilProne = "ACE_545x39_MG_RecoilProne";
			dispersion = 0.00225;
			displayName = $STR_ACE_DN_MODE_AUTO;
		};
		
		class Single : Mode_SemiAuto {
			recoil = "ACE_545x39_MG_Recoil";
			recoilProne = "ACE_545x39_MG_RecoilProne";
			dispersion = 0.00225;
		};
	};
	
	class BAF_L110A1_Aim : Rifle {
		type = VArmor;
		magazines[] = {"200Rnd_556x45_M249", "200Rnd_556x45_L110A1", "ACE_200Rnd_556x45_T_M249", "100Rnd_556x45_M249", "ACE_100Rnd_556x45_T_M249", "30Rnd_556x45_Stanag", "ACE_30Rnd_556x45_T_Stanag", "20Rnd_556x45_Stanag", "100Rnd_556x45_BetaCMag", "30Rnd_556x45_StanagSD", "ACE_30Rnd_556x45_SB_Stanag", "ACE_30Rnd_556x45_SB_S_Stanag"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		
		class manual : Mode_FullAuto {
			dispersion = 0.0035;
			recoil = "ACE_M249_Recoil";
			recoilProne = "ACE_M249_RecoilProne";
			displayName = $STR_ACE_DN_MODE_AUTO;
		};
	};
	
	class UK59_ACR : Rifle {
		type = VArmor;
		discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};
		discreteDistanceInitIndex = 3;
		magazinereloadtime = 0;
		
		class manual : Mode_FullAuto {
			dispersion = 0.004;
			reloadTime = 0.08;
			recoil = "ACE_762x54R_MG_Recoil";
			recoilprone = "ACE_762x54R_MG_RecoilProne";
		};
	};
	
	class MP5SD : Rifle {
		modes[] = {"Single", "Burst", "FullAuto"};
		magazines[] = {"30Rnd_9x19_MP5SD", "ACE_30Rnd_9x19_S_MP5", "30Rnd_9x19_MP5"};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.07;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.07;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.07;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
	};
	
	class MP5A5 : MP5SD {
		magazines[] = {"30Rnd_9x19_MP5", "30Rnd_9x19_MP5SD", "ACE_30Rnd_9x19_S_MP5"};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.07;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.07;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.07;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
	};
	
	class bizon : rifle {
		fireLightDuration = 0.05;
		fireLightIntensity = 0.012;
		modes[] = {"Single", "Burst", "FullAuto"};
		magazines[] = {"64Rnd_9x19_Bizon", "ACE_64Rnd_9x19_S_Bizon", "64Rnd_9x19_SD_Bizon"};
		
		class Single : Mode_SemiAuto {
			reloadTime = 0.088;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		
		class Burst : Mode_Burst {
			reloadTime = 0.088;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		
		class FullAuto : Mode_FullAuto {
			reloadTime = 0.088;
			recoil = "ACE_9x19_SMG_Recoil";
			recoilProne = "ACE_9x19_SMG_Recoil";
		};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {50, 100, 150};
		discreteDistanceInitIndex = 1;
	};
	
	class bizon_silenced : bizon {
		fireLightDuration = 0;
		fireLightIntensity = 0;
		magazines[] = {"64Rnd_9x19_SD_Bizon", "ACE_64Rnd_9x19_S_Bizon", "64Rnd_9x19_Bizon"};
	};
	
	class Evo_ACR : MP5A5 {
		displayName = $STR_ACE_WDN_EVO3;
		magazines[] = {"20Rnd_9x19_EVO", "ACE_30Rnd_9x19_S_EVO", "20Rnd_9x19_EVOSD"};
		distancezoommax = 100;
		distancezoommin = 100;
		
		class Single : Single {
			reloadTime = 0.06;
		};
		
		class Burst : Burst {
			reloadTime = 0.06;
		};
		
		class FullAuto : FullAuto {
			reloadTime = 0.06;
		};
	};
	
	class Evo_mrad_ACR : Evo_ACR {
		displayName = $STR_ACE_WDN_EVO3CCO;
		irDistance = 100;
	};
	
	class evo_sd_ACR : MP5SD {
		displayName = $STR_ACE_WDN_EVO3SDCCO;
		magazines[] = {"20Rnd_9x19_EVOSD", "ACE_30Rnd_9x19_S_EVO", "20Rnd_9x19_EVO"};
		distancezoommax = 100;
		distancezoommin = 100;
		
		class FlashLight {
			color[] = {0.9, 0.9, 0.7, 0.9};
			ambient[] = {0.1, 0.1, 0.1, 1.0};
			position = "flash dir";
			direction = "flash";
			angle = 20;
			scale[] = {0.9, 0.9, 0.4};
			brightness = 0.09;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		
		class Single : Single {
			reloadTime = 0.06;
		};
		
		class Burst : Burst {
			reloadTime = 0.06;
		};
		
		class FullAuto : FullAuto {
			reloadTime = 0.06;
		};
		
		class Library {
			libTextDesc = "";
		};
	};
	
	class Javelin : Launcher {
		displayName = "FGM-148 Javelin";
		opticsDisablePeripherialVision = true;
		opticsFlare = false;
		optics = true;
		forceOptics = false;
		useAsBinocular = 0;
		opticsZoomMin = 0.0725;
		opticsZoomMax = 0.0725;
		opticsZoomInit = 0.0725;
		
		class OpticsModes {
			class StepScope {
				visionMode[] = {"Normal", "Ti"};
			};
		};
	};
	
	class ACE_Javelin_Direct : Javelin {};
	
	class M136 : Launcher {
		displayName = "M136 AT4";
	};
	
	class SMAW : Launcher {
		displayName = "Mk153 Mod 0 SMAW";
		magazines[] = {SMAW_HEAA, SMAW_HEDP, ACE_SMAW_NE};
	};
	
	class MetisLauncher : Launcher {
		displayName = $STR_ACE_WDN_METISLAUNCHER;
		maxRange = 1500;
		canlock = LockNo;
		magazines[] = {AT13, ACE_AT13TB};
		visionmode[] = {"Normal", "Ti"};
	};
	
	class M47Launcher_EP1 : Launcher {
		displayName = "M47 Dragon";
		canlock = LockNo;
	};
	
	class MAAWS : Launcher {
		displayName = "M3 MAAWS";
		magazines[] = {MAAWS_HEAT, MAAWS_HEDP, ACE_MAAWS_HE};
		opticsZoomMin = 0.14389;
		opticsZoomMax = 0.14389;
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		weaponInfoType = "RscWeaponEmpty";
		modelOptics = "x\ace\Addons\m_wep_optics\ACE_optics_m3";
	};
	
	class Strela : Launcher {
		displayName = $STR_ACE_WDN_STRELA;
	};
	
	class Igla : Strela {
		displayName = $STR_ACE_WDN_IGLA;
	};
	
	class RPG7V : Launcher {
		displayName = $STR_ACE_WDN_RPG7V;
		model = "\x\ace\addons\m_wep_rpg7\SLX_RPG7";
		magazines[] = {PG7VL, ACE_PG7VL_PGO7, PG7VR, ACE_PG7VR_PGO7, ACE_PG7VM, ACE_PG7VM_PGO7, PG7V, ACE_PG7V_PGO7, ACE_TBG7V, ACE_TBG7V_PGO7, OG7, ACE_OG7_PGO7};
	};
	
	class ACE_RPG7V_PGO7 : RPG7V {
		displayName = $STR_ACE_WDN_RPG7V_PGO7;
		magazines[] = {ACE_PG7VL_PGO7, PG7VL, ACE_PG7VR_PGO7, PG7VR, ACE_PG7VM_PGO7, ACE_PG7VM, ACE_PG7V_PGO7, PG7V, ACE_TBG7V_PGO7, ACE_TBG7V, ACE_OG7_PGO7, OG7};
		model = "\x\ace\addons\m_wep_rpg7\SLX_RPG7_PGO7";
		modelOptics = "x\ace\Addons\m_wep_optics\ACE_optics_PGO7V3";
		optics = true;
		opticsFlare = true;
		opticsZoomMin = 0.128;
		opticsZoomMax = 0.128;
		opticsZoomInit = 0.128;
		ace_sa_enabled = 0;
		ace_at_zero = 50.6;
		ace_at_zero_fov = 0.128;
		
		class OpticsModes {
			class Optics {
				opticsID = 1;
				useModelOptics = 1;
				opticsFlare = true;
				opticsDisablePeripherialVision = true;
				opticsPPEffects[] = {"OpticsCHAbera3", "OpticsBlur3"};
				distanceZoomMax = 100;
				distanceZoomMin = 100;
				opticsZoomMin = 0.128;
				opticsZoomInit = 0.128;
				opticsZoomMax = 0.128;
				memoryPointCamera = "optics";
				visionMode[] = {"Normal"};
				cameraDir = "";
			};
			
			class Ironsights : Optics {
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = false;
				opticsDisablePeripherialVision = false;
				opticsPPEffects[] = {};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
	};
	
	class Put : Default {
		muzzles[] = {"TimeBombMuzzle", "PipeBombMuzzle", "MineMuzzle", "MineEMuzzle", "ace_sys_wounds", "ace_sys_explosives", "ace_sys_sandbag", "ace_sys_crewserved", "ace_sys_dogtag", "ace_sys_fastroping", "ace_sys_groundmarker", "ace_sys_ravlifter", "BAF_ied_v1_muzzle", "BAF_ied_v2_muzzle", "BAF_ied_v3_muzzle", "BAF_ied_v4_muzzle", "PMC_ied_v1_muzzle", "PMC_ied_v2_muzzle", "PMC_ied_v3_muzzle", "PMC_ied_v4_muzzle"};
		
		class ACE_Dummy_Utility : Default {
			displayName = "";
			picture = "";
			simulation = "ProxyWeapon";
			autoReload = true;
			backgroundReload = false;
			magazineReloadTime = 0;
			reloadSound[] = {"", 1, 1};
			reloadMagazineSound[] = {"", 1, 1};
			reloadTime = 0.01;
			canLock = LockNo;
			enableAttack = false;
			value = 0;
			optics = false;
			uiPicture = "";
			primary = true;
			canDrop = false;
			showEmpty = 0;
			showToPlayer = false;
			dispersion = 0.0009;
			minRange = 0.1;
			minRangeProbab = 0.0001;
			midRange = 1;
			midRangeProbab = 0.0001;
			maxRange = 2;
			maxRangeProbab = 0.0001;
			magazines[] = {};
		};
		
		class ace_sys_wounds : ACE_Dummy_Utility {};
		
		class ace_sys_explosives : ACE_Dummy_Utility {};
		
		class ace_sys_sandbag : ACE_Dummy_Utility {};
		
		class ace_sys_crewserved : ACE_Dummy_Utility {};
		
		class ace_sys_dogtag : ACE_Dummy_Utility {};
		
		class ace_sys_fastroping : ACE_Dummy_Utility {};
		
		class ace_sys_groundmarker : ACE_Dummy_Utility {};
		
		class ace_sys_ravlifter : ACE_Dummy_Utility {};
	};
	
	class ACE_Safe : Put {
		muzzles[] = {this};
		displayName = SAFE;
		magazines[] = {"fakemagazine"};
		cursor = "\ca\Weapons\Data\clear_empty";
		cursorAim = "";
		showempty = 1;
		showtoplayer = true;
		enableAttack = false;
		optics = false;
		canLock = LockNo;
	};
	class ItemCore;	// External class reference
	
	class ItemWatch : ItemCore {
		model = "\x\ace\addons\m_wep_magazines\Watch.p3d";
		ACE_DamagedItem = "ACE_BrokenWatch";
	};
	
	class ItemCompass : ItemCore {
		model = "\x\ace\addons\m_wep_magazines\Compass.p3d";
	};
	
	class ItemGPS : ItemCore {
		model = "\x\ace\addons\m_wep_magazines\GPS.p3d";
		ACE_GPS = 1;
		ACE_DamagedItem = "ACE_BrokenGPS";
	};
	
	class ItemRadio : ItemCore {
		model = "\x\ace\addons\m_wep_magazines\Radio.p3d";
		ACE_DamagedItem = "ACE_BrokenRadio";
	};
	
	class ACE_BrokenWatch : ItemWatch {
		simulation = "";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_Broken_GPS : ItemGPS {
		simulation = "";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_BrokenRadio : ItemRadio {
		simulation = "";
		
		class Armory {
			disabled = 1;
		};
	};
	
	class ACE_Item : ItemCore {
		class Armory {
			disabled = 0;
		};
	};
	
	class ACE_KeyCuffs : ACE_Item {
		scope = public;
		displayName = $STR_MDN_ACE_KEYCUFF;
		model = "\x\ace\addons\m_wep_magazines\ace_keycuff.p3d";
		picture = "\x\ace\addons\c_weapon\data\equip\w_keycuff_ca.paa";
	};
	
	class Throw : GrenadeLauncher {
		class ThrowMuzzle;	// External class reference
		class HandGrenadeMuzzle;	// External class reference
		
		class ACE_SmokeShellMuzzle_RU : ThrowMuzzle {
			displayName = $STR_MN_SMOKE;
			magazines[] = {ACE_RDG2, ACE_RDGM};
		};
		
		class ACE_SmokeShellMuzzle_GER : ACE_SmokeShellMuzzle_RU {
			magazines[] = {ACE_DM25, ACE_DM31, ACE_DM32, ACE_DM33, ACE_DM34, ACE_DM36};
		};
		
		class ACE_HandGrenadeMuzzle_GER : HandGrenadeMuzzle {
			magazines[] = {ACE_DM51, ACE_DM51A1};
		};
		muzzles[] = {"HandGrenade_Stone", "HandGrenadeMuzzle", "SmokeShellMuzzle", "IRStrobe", "ACE_SmokeShellMuzzle_RU", "ACE_SmokeShellMuzzle_GER", "ACE_HandGrenadeMuzzle_GER", "ACE_M86PDMMuzzle", "ACE_FlashbangMuzzle", "ACE_TeargasMuzzle", "ACE_WPMuzzle", "ACE_IncendiaryMuzzle", "ACE_KnicklichtMuzzle", "ACE_Knicklicht_UsedMuzzle"};
	};
};

class CfgVehicles {
	class Strategic;	// External class reference
	
	class ReammoBox : Strategic {
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
	};
	
	class Library_WeaponHolder : Strategic {
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	
	class WeaponHolder : ReammoBox {
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		accuracy = 0.001;	// accuracy needed to recognize type of this target
		
		class Eventhandlers {
			init = " { if (isPlayer _x) then { _x reveal (_this select 0)} } foreach ((position (_this select 0)) nearEntities [['CaManBase'],20])";
		};
	};
	class NonStrategic;	// External class reference
	
	class Gunrack1 : NonStrategic {
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class USBasicAmmunitionBox_EP1;	// External class reference
	
	class ACE_USBasicAmmunitionBox : USBasicAmmunitionBox_EP1 {
		vehicleClass = "ACE_Ammunition";
		scope = protected;
		
		class TransportWeapons {
			class _xx_M4A1 {
				weapon = M4A1;
				count = 4;
			};
			
			class _xx_M9 {
				weapon = "M9";
				count = 4;
			};
		};
		
		class TransportMagazines {
			class _xx_30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 400;
			};
			
			class _xx_ACE_30Rnd_556x45_T_Stanag {
				magazine = "ACE_30Rnd_556x45_T_Stanag";
				count = 200;
			};
			
			class _xx_20Rnd_556x45_Stanag {
				magazine = "20Rnd_556x45_Stanag";
				count = 20;
			};
			
			class _xx_ACE_30Rnd_556x45_SB_Stanag {
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 20;
			};
			
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 50;
			};
			
			class _xx_200Rnd_556x45_M249 {
				magazine = "200Rnd_556x45_M249";
				count = 50;
			};
			
			class _xx_ACE_200Rnd_556x45_T_M249 {
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 50;
			};
			
			class _xx_30Rnd_9x19_MP5 {
				magazine = "30Rnd_9x19_MP5";
				count = 90;
			};
			
			class _xx_1Rnd_HE_M203 {
				magazine = "1Rnd_HE_M203";
				count = 80;
			};
			
			class _xx_FlareWhite_M203 {
				magazine = "FlareWhite_M203";
				count = 80;
			};
			
			class _xx_FlareGreen_M203 {
				magazine = "FlareGreen_M203";
				count = 80;
			};
			
			class _xx_FlareRed_M203 {
				magazine = "FlareRed_M203";
				count = 80;
			};
			
			class _xx_FlareYellow_M203 {
				magazine = "FlareYellow_M203";
				count = 80;
			};
			
			class _xx_ACE_SSWhite_M203 {
				magazine = "ACE_SSWhite_M203";
				count = 80;
			};
			
			class _xx_ACE_SSGreen_M203 {
				magazine = "ACE_SSGreen_M203";
				count = 80;
			};
			
			class _xx_ACE_SSRed_M203 {
				magazine = "ACE_SSRed_M203";
				count = 80;
			};
			
			class _xx_5Rnd_762x51_M24 {
				magazine = "5Rnd_762x51_M24";
				count = 30;
			};
			
			class _xx_ACE_5Rnd_762x51_T_M24 {
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 30;
			};
			
			class _xx_20Rnd_762x51_DMR {
				magazine = "20Rnd_762x51_DMR";
				count = 30;
			};
			
			class _xx_ACE_20Rnd_762x51_T_DMR {
				magazine = "ACE_20Rnd_762x51_T_DMR";
				count = 30;
			};
			
			class _xx_8Rnd_B_Beneli_74Slug {
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 50;
			};
			
			class _xx_10Rnd_127x99_m107 {
				magazine = "10Rnd_127x99_m107";
				count = 30;
			};
			
			class _xx_ACE_10Rnd_127x99_T_m107 {
				magazine = "ACE_10Rnd_127x99_T_m107";
				count = 30;
			};
			
			class _xx_15Rnd_9x19_M9 {
				magazine = "15Rnd_9x19_M9";
				count = 30;
			};
			
			class _xx_7Rnd_45ACP_1911 {
				magazine = "7Rnd_45ACP_1911";
				count = 30;
			};
			
			class _xx_HandGrenade_West {
				magazine = "HandGrenade_West";
				count = 50;
			};
			
			class _xx_SmokeShellRed {
				magazine = "SmokeShellRed";
				count = 20;
			};
			
			class _xx_SmokeShellGreen {
				magazine = "SmokeShellGreen";
				count = 20;
			};
			
			class _xx_SmokeShellYellow {
				magazine = "SmokeShellYellow";
				count = 20;
			};
			
			class _xx_SmokeShellBlue {
				magazine = "SmokeShellBlue";
				count = 20;
			};
			
			class _xx_SmokeShellPurple {
				magazine = "SmokeShellPurple";
				count = 20;
			};
			
			class _xx_SmokeShellOrange {
				magazine = "SmokeShellOrange";
				count = 20;
			};
			
			class _xx_SmokeShell {
				magazine = "SmokeShell";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeRed_M203 {
				magazine = "1Rnd_SmokeRed_M203";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeGreen_M203 {
				magazine = "1Rnd_SmokeGreen_M203";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeYellow_M203 {
				magazine = "1Rnd_SmokeYellow_M203";
				count = 20;
			};
			
			class _xx_1Rnd_Smoke_M203 {
				magazine = "1Rnd_Smoke_M203";
				count = 20;
			};
		};
	};
	
	class ACE_EmptyBox : USBasicAmmunitionBox_EP1 {
		scope = protected;
		displayName = "Empty Box";
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	
	class ACE_AmmoPallet : ACE_EmptyBox {
		scope = protected;
		model = "\x\ace\addons\m_veh_crates\ace_allinone.p3d";
	};
	
	class ACE_Tbox_US : ACE_EmptyBox {
		scope = public;
		vehicleClass = "ACE_AmmunitionTransportUS";
	};
	
	class ACE_Tbox_RU : ACE_Tbox_US {
		vehicleClass = "ACE_AmmunitionTransportRU";
	};
	
	class ACE_Tbox_GP_W : ACE_Tbox_US {
		displayName = "General Purpose Box";
		model = "x\ace\addons\m_veh_crates\ace_generalpurpose_us.p3d";
		transportMaxMagazines = 50;
		transportMaxWeapons = 4;
	};
	
	class ACE_Tbox_GP_R : ACE_Tbox_RU {
		displayName = "General Purpose Box";
		model = "x\ace\addons\m_veh_crates\ace_generalpurpose_ru.p3d";
		transportMaxMagazines = 50;
		transportMaxWeapons = 4;
	};
	
	class ACE_Bag : ACE_EmptyBox {
		scope = protected;
		displayName = "Bag";
		model = "x\ace\addons\m_veh_crates\ace_bag.p3d";
		transportMaxMagazines = 100;
		transportMaxWeapons = 5;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	
	class ACE_Tbox_M136 : ACE_Tbox_GP_W {
		displayName = "M136 AT4 Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_AT4_us.p3d";
		transportMaxMagazines = 0;
		transportMaxWeapons = 4;
		
		class TransportWeapons {
			class _xx_M136 {
				weapon = M136;
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_Javelin : ACE_Tbox_GP_W {
		displayName = "FGM-148 Javelin Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_STINGER_us.p3d";
		
		class TransportWeapons {
			class _xx_Javelin {
				weapon = "Javelin";
				count = 1;
			};
			
			class _xx_ACE_Javelin_CLU {
				weapon = "ACE_Javelin_CLU";
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_Stinger : ACE_Tbox_GP_W {
		displayName = "FIM-92F Stinger Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_STINGER_us.p3d";
		transportMaxMagazines = 1;
		transportMaxWeapons = 1;
		
		class TransportWeapons {
			class _xx_Stinger {
				weapon = "Stinger";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_Stinger {
				magazine = "Stinger";
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_RPG7V : ACE_Tbox_GP_R {
		displayName = "OG-7V Transport Box";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_ACE_OG7_PGO7 {
				magazine = ACE_OG7_PGO7;
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_Strela : ACE_Tbox_GP_R {
		displayName = "9K32 Strela-2 Transport Box";
		
		class TransportWeapons {
			class _xx_Strela {
				weapon = "Strela";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_Strela {
				magazine = "Strela";
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_Igla : ACE_Tbox_GP_R {
		displayName = "9K38 Igla Transport Box";
		
		class TransportWeapons {
			class _xx_Igla {
				weapon = "Igla";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_Igla {
				magazine = "Igla";
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_MetisLauncher : ACE_Tbox_GP_R {
		displayName = "9P151M Metis-M1 Transport Box";
		
		class TransportWeapons {
			class _xx_MetisLauncher {
				weapon = "MetisLauncher";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_AT13 {
				magazine = AT13;
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_RPG18 : ACE_Tbox_GP_R {
		displayName = "RPG-18 Transport Box";
		
		class TransportWeapons {
			class _xx_RPG18 {
				weapon = RPG18;
				count = 3;
			};
		};
	};
	
	class ACE_Tbox_SMAW : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "Mk.153 Mod 0 SMAW Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_STINGER_us.p3d";
		
		class TransportWeapons {
			class _xx_SMAW {
				weapon = SMAW;
				count = 1;
			};
		};
		
		class TransportMagazines {};
	};
	
	class ACE_Tbox_BAF_NLAW_Launcher : ACE_Tbox_GP_W {
		displayName = "NLAW Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_STINGER_us.p3d";
		
		class TransportWeapons {
			class _xx_BAF_NLAW_Launcher {
				weapon = "BAF_NLAW_Launcher";
				count = 2;
			};
		};
	};
	
	class ACE_Tbox_M47Launcher_EP1 : ACE_Tbox_GP_R {
		displayName = "M47 Dragon Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_STINGER_us.p3d";
		
		class TransportWeapons {
			class _xx_M47Launcher_EP1 {
				weapon = "M47Launcher_EP1";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_Dragon_EP1 {
				magazine = "Dragon_EP1";
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_MAAWS : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M3 MAAWS Transport Box";
		
		class TransportWeapons {
			class _xx_MAAWS {
				weapon = MAAWS;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_MAAWS_HE {
				magazine = ACE_MAAWS_HE;
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_ACE_RPG7V_PGO7 : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "RPG-7V PGO-7 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_RPG7V_PGO7 {
				weapon = ACE_RPG7V_PGO7;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_OG7_PGO7 {
				magazine = ACE_OG7_PGO7;
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_ACE_M136_CSRS : ACE_Tbox_GP_W {
		displayName = "M136 AT4 CS/RS Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_AT4_us.p3d";
		transportMaxMagazines = 0;
		transportMaxWeapons = 4;
		
		class TransportWeapons {
			class _xx_ACE_M136_CSRS {
				weapon = ACE_M136_CSRS;
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_ACE_M72A2 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M72A2 Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_AT4_us.p3d";
		
		class TransportWeapons {
			class _xx_ACE_M72A2 {
				weapon = ACE_M72A2;
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_ACE_RPG29 : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "RPG-29 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_RPG29 {
				weapon = ACE_RPG29;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_RPG29_PG29 {
				magazine = ACE_RPG29_PG29;
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_ACE_RPG22 : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "RPG-22 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_RPG22 {
				weapon = ACE_RPG22;
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_ACE_RPG27 : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "RPG-27 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_RPG27 {
				weapon = ACE_RPG27;
				count = 1;
			};
		};
	};
	
	class ACE_Tbox_556x45STANAG : ACE_Tbox_GP_W {
		displayName = "5.56x45 (Magazine) Box";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 20;
			};
		};
	};
	
	class ACE_Tbox_556x45Belt : ACE_Tbox_GP_W {
		displayName = "5.56x45 (Belt) Box ";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_200Rnd_556x45_M249 {
				magazine = "200Rnd_556x45_M249";
				count = 4;
			};
			
			class _xx_100Rnd_556x45_M249 {
				magazine = "100Rnd_556x45_M249";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_762x51Belt : ACE_Tbox_GP_W {
		displayName = "7.62x51 (Belt) Box";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_1Rnd_HE_M203 : ACE_Tbox_GP_W {
		displayName = "Grenades (M433)";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_1Rnd_HE_M203 {
				magazine = "1Rnd_HE_M203";
				count = 50;
			};
		};
	};
	
	class ACE_Tbox_HandGrenade_West : ACE_Tbox_GP_W {
		displayName = "Handgrenades (M67)";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_HandGrenade_West {
				magazine = "HandGrenade_West";
				count = 50;
			};
		};
	};
	
	class ACE_Tbox_SmokeGrenade_West : ACE_Tbox_GP_W {
		displayName = "Smoke Grenades";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_SmokeShell {
				magazine = "SmokeShell";
				count = 30;
			};
			
			class _xx_SmokeShellRed {
				magazine = "SmokeShellRed";
				count = 10;
			};
			
			class _xx_SmokeShellGreen {
				magazine = "SmokeShellGreen";
				count = 10;
			};
		};
	};
	
	class ACE_Tbox_DM51 : ACE_Tbox_HandGrenade_West {
		displayName = "Handgranatenkoffer, DM51";
		model = "x\ace\addons\m_veh_crates\ace_koffer_dm51.p3d";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_ACE_DM51A1 {
				magazine = ACE_DM51A1;
				count = 10;
			};
		};
	};
	
	class ACE_Tbox_545x39Magazine : ACE_Tbox_GP_R {
		displayName = "5.45x39 (Magazine) Box";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_30Rnd_545x39_AK {
				magazine = "30Rnd_545x39_AK";
				count = 30;
			};
		};
	};
	
	class ACE_Tbox_762x54Belt : ACE_Tbox_GP_R {
		displayName = "7.62x54 (Belt) Box";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_100Rnd_762x54_PK {
				magazine = "100Rnd_762x54_PK";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_1Rnd_HE_GP25 : ACE_Tbox_GP_R {
		displayName = "Grenades (VOG-25)";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_1Rnd_HE_GP25 {
				magazine = "1Rnd_HE_GP25";
				count = 50;
			};
		};
	};
	
	class ACE_Tbox_ACE_1Rnd_HE_GP25P : ACE_Tbox_GP_R {
		displayName = "Grenades (VOG-25P)";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_ACE_1Rnd_HE_GP25P {
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 50;
			};
		};
	};
	
	class ACE_Tbox_HandGrenade : ACE_Tbox_GP_R {
		displayName = "Handgrenades (RGO)";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_HandGrenade {
				magazine = "HandGrenade";
				count = 50;
			};
		};
	};
	
	class ACE_Tbox_HandGrenade_East : ACE_Tbox_GP_R {
		displayName = "Handgrenades (RGD5)";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_HandGrenade_East {
				magazine = "HandGrenade_East";
				count = 50;
			};
		};
	};
	
	class ACE_Tbox_SmokeGrenade_East : ACE_Tbox_GP_R {
		displayName = "Smoke Grenades";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_ACE_RDGM {
				magazine = ACE_RDGM;
				count = 30;
			};
			
			class _xx_SmokeShellOrange {
				magazine = "SmokeShellOrange";
				count = 10;
			};
			
			class _xx_SmokeShellBlue {
				magazine = "SmokeShellBlue";
				count = 10;
			};
		};
	};
	
	class ACE_Tbox_M24 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M24 Transport Box";
		
		class TransportWeapons {
			class _xx_M24 {
				weapon = M24;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_762x51_M24 {
				magazine = "5Rnd_762x51_M24";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_M40A3 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M40A3 Transport Box";
		
		class TransportWeapons {
			class _xx_M40A3 {
				weapon = M40A3;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_762x51_M24 {
				magazine = "5Rnd_762x51_M24";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_SVD : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "SVD Transport Box";
		
		class TransportWeapons {
			class _xx_SVD {
				weapon = SVD;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_762x54_SVD {
				magazine = "10Rnd_762x54_SVD";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_SVD_CAMO : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "SVD Camo Transport Box";
		
		class TransportWeapons {
			class _xx_SVD_CAMO {
				weapon = SVD_CAMO;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_762x54_SVD {
				magazine = "10Rnd_762x54_SVD";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_DMR : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "DMR Transport Box";
		
		class TransportWeapons {
			class _xx_DMR {
				weapon = DMR;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_20Rnd_762x51_DMR {
				magazine = "20Rnd_762x51_DMR";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ksvk : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "KSVK Transport Box";
		
		class TransportWeapons {
			class _xx_ksvk {
				weapon = "ksvk";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_127x108_KSVK {
				magazine = "5Rnd_127x108_KSVK";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_m107 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M107 Transport Box";
		
		class TransportWeapons {
			class _xx_m107 {
				weapon = "m107";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_127x99_m107 {
				magazine = "10Rnd_127x99_m107";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_VSS_vintorez : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "VSS Vintorez Transport Box";
		
		class TransportWeapons {
			class _xx_VSS_vintorez {
				weapon = "VSS_vintorez";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_9x39_SP5_VSS {
				magazine = "10Rnd_9x39_SP5_VSS";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_huntingrifle : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "CZ 550 Transport Box";
		
		class TransportWeapons {
			class _xx_huntingrifle {
				weapon = "huntingrifle";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5x_22_LR_17_HMR {
				magazine = "5x_22_LR_17_HMR";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_BAF_AS50_scoped : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "AS50 Transport Box";
		
		class TransportWeapons {
			class _xx_BAF_AS50_scoped {
				weapon = "BAF_AS50_scoped";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_127x99_as50 {
				magazine = "5Rnd_127x99_as50";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_BAF_AS50_TWS : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "AS50 TWS Transport Box";
		
		class TransportWeapons {
			class _xx_BAF_AS50_TWS {
				weapon = BAF_AS50_TWS;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_127x99_as50 {
				magazine = "5Rnd_127x99_as50";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_BAF_LRR_scoped : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "L115A3 LRR Transport Box";
		
		class TransportWeapons {
			class _xx_BAF_LRR_scoped {
				weapon = "BAF_LRR_scoped";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_86x70_L115A1 {
				magazine = "5Rnd_86x70_L115A1";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_BAF_LRR_scoped_W : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "L115A2 LRR Transport Box";
		
		class TransportWeapons {
			class _xx_BAF_LRR_scoped_W {
				weapon = "BAF_LRR_scoped_W";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_86x70_L115A1 {
				magazine = "5Rnd_86x70_L115A1";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_M24_des_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M24 desert Transport Box";
		
		class TransportWeapons {
			class _xx_M24_des_EP1 {
				weapon = "M24_des_EP1";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_5Rnd_762x51_M24 {
				magazine = "5Rnd_762x51_M24";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_SVD_des_EP1 : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "SVD (camo) Transport Box";
		
		class TransportWeapons {
			class _xx_SVD_des_EP1 {
				weapon = "SVD_des_EP1";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_762x54_SVD {
				magazine = "10Rnd_762x54_SVD";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_SVD_NSPU_EP1 : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "SVD NSPU Transport Box";
		
		class TransportWeapons {
			class _xx_SVD_NSPU_EP1 {
				weapon = SVD_NSPU_EP1;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_762x54_SVD {
				magazine = "10Rnd_762x54_SVD";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_m107_TWS_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M107 TWS Transport Box";
		
		class TransportWeapons {
			class _xx_m107_TWS_EP1 {
				weapon = "m107_TWS_EP1";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_127x99_m107 {
				magazine = "10Rnd_127x99_m107";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_M110_TWS_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M110 TWS Transport Box";
		
		class TransportWeapons {
			class _xx_M110_TWS_EP1 {
				weapon = M110_TWS_EP1;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_20Rnd_762x51_B_SCAR {
				magazine = "20Rnd_762x51_B_SCAR";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_M110_NVG_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M110 NV Scope Transport Box";
		
		class TransportWeapons {
			class _xx_M110_NVG_EP1 {
				weapon = M110_NVG_EP1;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_20Rnd_762x51_B_SCAR {
				magazine = "20Rnd_762x51_B_SCAR";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_Val_PSO : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "AS Val PSO Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_Val_PSO {
				weapon = "ACE_Val_PSO";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_10Rnd_9x39_SP5_VSS {
				magazine = "10Rnd_9x39_SP5_VSS";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_M110 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M110 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_M110 {
				weapon = ACE_M110;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_20Rnd_762x51_B_SCAR {
				magazine = "20Rnd_762x51_B_SCAR";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_M110_SD : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M110 SD Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_M110_SD {
				weapon = ACE_M110_SD;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_20Rnd_762x51_B_SCAR {
				magazine = "20Rnd_762x51_B_SCAR";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_M109 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M109 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_M109 {
				weapon = ACE_M109;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_5Rnd_25x59_HEDP_Barrett {
				magazine = "ACE_5Rnd_25x59_HEDP_Barrett";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_TAC50 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "TAC-50 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_TAC50 {
				weapon = ACE_TAC50;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_5Rnd_127x99_B_TAC50 {
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_TAC50_SD : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "TAC-50 SD Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_TAC50_SD {
				weapon = ACE_TAC50_SD;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_5Rnd_127x99_B_TAC50 {
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_ACE_AS50 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "AS50 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_AS50 {
				weapon = ACE_AS50;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_5Rnd_127x99_B_TAC50 {
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 8;
			};
		};
	};
	
	class ACE_Tbox_M240 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M240G Transport Box";
		
		class TransportWeapons {
			class _xx_M240 {
				weapon = M240;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_Mk_48 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "Mk 48 Mod 0 Transport Box";
		
		class TransportWeapons {
			class _xx_Mk_48 {
				weapon = "Mk_48";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_PK : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "PKM Transport Box";
		
		class TransportWeapons {
			class _xx_PK {
				weapon = "PK";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x54_PK {
				magazine = "100Rnd_762x54_PK";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_Pecheneg : ACE_Tbox_GP_R {
		scope = protected;
		displayName = "PKP Transport Box";
		
		class TransportWeapons {
			class _xx_Pecheneg {
				weapon = "Pecheneg";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x54_PK {
				magazine = "100Rnd_762x54_PK";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_BAF_L7A2_GPMG : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "L7A2 GPMG Transport Box";
		
		class TransportWeapons {
			class _xx_BAF_L7A2_GPMG {
				weapon = BAF_L7A2_GPMG;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_M60A4_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M60E4 Transport Box";
		
		class TransportWeapons {
			class _xx_M60A4_EP1 {
				weapon = M60A4_EP1;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_Mk_48_DES_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "Mk48 Mod 0 (camo) Transport Box";
		
		class TransportWeapons {
			class _xx_Mk_48_DES_EP1 {
				weapon = "Mk_48_DES_EP1";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_m240_scoped_EP1 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M240G M145 Transport Box";
		
		class TransportWeapons {
			class _xx_m240_scoped_EP1 {
				weapon = "m240_scoped_EP1";
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	
	class ACE_Tbox_ACE_M60 : ACE_Tbox_GP_W {
		scope = protected;
		displayName = "M60 Transport Box";
		
		class TransportWeapons {
			class _xx_ACE_M60 {
				weapon = ACE_M60;
				count = 1;
			};
		};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 4;
			};
		};
	};
	class USLaunchers_EP1;	// External class reference
	
	class ACE_USLaunchersBox : USLaunchers_EP1 {
		vehicleClass = "ACE_Ammunition";
		scope = protected;
		
		class TransportWeapons {
			class _xx_M136 {
				weapon = M136;
				count = 15;
			};
			
			class _xx_Stinger {
				weapon = "Stinger";
				count = 4;
			};
			
			class _xx_Javelin {
				weapon = "Javelin";
				count = 4;
			};
			
			class _xx_ACE_Javelin_CLU {
				weapon = "ACE_Javelin_CLU";
				count = 1;
			};
			
			class _xx_ACE_M136_CSRS {
				weapon = ACE_M136_CSRS;
				count = 10;
			};
		};
		
		class TransportMagazines {
			class _xx_Stinger {
				magazine = "Stinger";
				count = 4;
			};
		};
	};
	class USOrdnanceBox_EP1;	// External class reference
	
	class ACE_USOrdnanceBox : USOrdnanceBox_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_Mine {
				magazine = "Mine";
				count = 10;
			};
			
			class _xx_PipeBomb {
				magazine = "PipeBomb";
				count = 20;
			};
			
			class _xx_HandGrenade_West {
				magazine = "HandGrenade_West";
				count = 50;
			};
			
			class _xx_ACE_Claymore_M {
				magazine = "ACE_Claymore_M";
				count = 10;
			};
			
			class _xx_ACE_BBetty_M {
				magazine = "ACE_BBetty_M";
				count = 10;
			};
			
			class _xx_ACE_TripFlare_M {
				magazine = "ACE_TripFlare_M";
				count = 10;
			};
			
			class _xx_ACE_C4_M {
				magazine = ACE_C4_M;
				count = 5;
			};
		};
	};
	class USBasicWeapons_EP1;	// External class reference
	
	class ACE_USBasicWeaponsBox : USBasicWeapons_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {
			class _xx_M4A3_CCO_EP1 {
				weapon = M4A3_CCO_EP1;
				count = 4;
			};
			
			class _xx_M4A1 {
				weapon = M4A1;
				count = 10;
			};
			
			class _xx_M4A3_RCO_GL_EP1 {
				weapon = M4A3_RCO_GL_EP1;
				count = 2;
			};
			
			class _xx_M16A2 {
				weapon = M16A2;
				count = 4;
			};
			
			class _xx_M16A2GL {
				weapon = M16A2GL;
				count = 2;
			};
			
			class _xx_Colt1911 {
				weapon = "Colt1911";
				count = 4;
			};
			
			class _xx_M9 {
				weapon = "M9";
				count = 4;
			};
		};
		
		class TransportMagazines {
			class _xx_30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 400;
			};
			
			class _xx_ACE_30Rnd_556x45_T_Stanag {
				magazine = "ACE_30Rnd_556x45_T_Stanag";
				count = 200;
			};
			
			class _xx_30Rnd_9x19_MP5 {
				magazine = "30Rnd_9x19_MP5";
				count = 90;
			};
			
			class _xx_1Rnd_HE_M203 {
				magazine = "1Rnd_HE_M203";
				count = 80;
			};
			
			class _xx_FlareWhite_M203 {
				magazine = "FlareWhite_M203";
				count = 80;
			};
			
			class _xx_FlareGreen_M203 {
				magazine = "FlareGreen_M203";
				count = 80;
			};
			
			class _xx_FlareRed_M203 {
				magazine = "FlareRed_M203";
				count = 80;
			};
			
			class _xx_FlareYellow_M203 {
				magazine = "FlareYellow_M203";
				count = 80;
			};
			
			class _xx_ACE_SSWhite_M203 {
				magazine = "ACE_SSWhite_M203";
				count = 80;
			};
			
			class _xx_ACE_SSGreen_M203 {
				magazine = "ACE_SSGreen_M203";
				count = 80;
			};
			
			class _xx_ACE_SSRed_M203 {
				magazine = "ACE_SSRed_M203";
				count = 80;
			};
			
			class _xx_15Rnd_9x19_M9 {
				magazine = "15Rnd_9x19_M9";
				count = 30;
			};
			
			class _xx_7Rnd_45ACP_1911 {
				magazine = "7Rnd_45ACP_1911";
				count = 30;
			};
			
			class _xx_1Rnd_SmokeRed_M203 {
				magazine = "1Rnd_SmokeRed_M203";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeGreen_M203 {
				magazine = "1Rnd_SmokeGreen_M203";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeYellow_M203 {
				magazine = "1Rnd_SmokeYellow_M203";
				count = 20;
			};
			
			class _xx_1Rnd_Smoke_M203 {
				magazine = "1Rnd_Smoke_M203";
				count = 20;
			};
		};
	};
	class USSpecialWeapons_EP1;	// External class reference
	
	class ACE_USSpecialWeaponsBox : USSpecialWeapons_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {
			class _xx_ACE_Earplugs {
				weapon = "ACE_Earplugs";
				count = 5;
			};
			
			class _xx_Binocular {
				weapon = "Binocular";
				count = 5;
			};
			
			class _xx_NVGoggles {
				weapon = "NVGoggles";
				count = 10;
			};
			
			class _xx_Laserdesignator {
				weapon = "Laserdesignator";
				count = 2;
			};
			
			class _xx_ACE_Rangefinder_OD {
				weapon = "ACE_Rangefinder_OD";
				count = 1;
			};
			
			class _xx_M24_des_EP1 {
				weapon = "M24_des_EP1";
				count = 2;
			};
			
			class _xx_M4SPR {
				weapon = M4SPR;
				count = 5;
			};
			
			class _xx_M249_EP1 {
				weapon = M249_EP1;
				count = 4;
			};
			
			class _xx_m107 {
				weapon = "m107";
				count = 2;
			};
			
			class _xx_ACE_GlassesTactical {
				weapon = "ACE_GlassesTactical";
				count = 20;
			};
			
			class _xx_ACE_GlassesLHD_glasses {
				weapon = "ACE_GlassesLHD_glasses";
				count = 20;
			};
			
			class _xx_ACE_GlassesGasMask_US {
				weapon = "ACE_GlassesGasMask_US";
				count = 10;
			};
			
			class _xx_ACE_GlassesBalaklava {
				weapon = "ACE_GlassesBalaklava";
				count = 10;
			};
			
			class _xx_ACE_KeyCuffs {
				weapon = "ACE_KeyCuffs";
				count = 30;
			};
		};
		
		class TransportMagazines {
			class _xx_Laserbatteries {
				magazine = "Laserbatteries";
				count = 10;
			};
			
			class _xx_ACE_Battery_Rangefinder {
				magazine = "ACE_Battery_Rangefinder";
				count = 10;
			};
			
			class _xx_30Rnd_556x45_Stanag {
				magazine = "30Rnd_556x45_Stanag";
				count = 100;
			};
			
			class _xx_ACE_30Rnd_556x45_T_Stanag {
				magazine = "ACE_30Rnd_556x45_T_Stanag";
				count = 100;
			};
			
			class _xx_20Rnd_556x45_Stanag {
				magazine = "20Rnd_556x45_Stanag";
				count = 50;
			};
			
			class _xx_ACE_30Rnd_556x45_SB_Stanag {
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 50;
			};
			
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 40;
			};
			
			class _xx_200Rnd_556x45_M249 {
				magazine = "200Rnd_556x45_M249";
				count = 40;
			};
			
			class _xx_ACE_200Rnd_556x45_T_M249 {
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 40;
			};
			
			class _xx_1Rnd_HE_M203 {
				magazine = "1Rnd_HE_M203";
				count = 80;
			};
			
			class _xx_ACE_1Rnd_HE_M203 {
				magazine = "ACE_1Rnd_HE_M203";
				count = 80;
			};
			
			class _xx_ACE_1Rnd_PR_M203 {
				magazine = "ACE_1Rnd_PR_M203";
				count = 80;
			};
			
			class _xx_FlareWhite_M203 {
				magazine = "FlareWhite_M203";
				count = 80;
			};
			
			class _xx_FlareGreen_M203 {
				magazine = "FlareGreen_M203";
				count = 80;
			};
			
			class _xx_FlareRed_M203 {
				magazine = "FlareRed_M203";
				count = 80;
			};
			
			class _xx_FlareYellow_M203 {
				magazine = "FlareYellow_M203";
				count = 80;
			};
			
			class _xx_ACE_SSWhite_M203 {
				magazine = "ACE_SSWhite_M203";
				count = 80;
			};
			
			class _xx_ACE_SSGreen_M203 {
				magazine = "ACE_SSGreen_M203";
				count = 80;
			};
			
			class _xx_ACE_SSRed_M203 {
				magazine = "ACE_SSRed_M203";
				count = 80;
			};
			
			class _xx_ACE_SSWhite_FG {
				magazine = "ACE_SSWhite_FG";
				count = 20;
			};
			
			class _xx_ACE_SSGreen_FG {
				magazine = "ACE_SSGreen_FG";
				count = 20;
			};
			
			class _xx_ACE_SSRed_FG {
				magazine = "ACE_SSRed_FG";
				count = 20;
			};
			
			class _xx_ACE_SSYellow_FG {
				magazine = "ACE_SSYellow_FG";
				count = 20;
			};
			
			class _xx_5Rnd_762x51_M24 {
				magazine = "5Rnd_762x51_M24";
				count = 30;
			};
			
			class _xx_ACE_5Rnd_762x51_T_M24 {
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 30;
			};
			
			class _xx_20Rnd_762x51_DMR {
				magazine = "20Rnd_762x51_DMR";
				count = 30;
			};
			
			class _xx_ACE_20Rnd_762x51_T_DMR {
				magazine = "ACE_20Rnd_762x51_T_DMR";
				count = 30;
			};
			
			class _xx_8Rnd_B_Beneli_74Slug {
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 50;
			};
			
			class _xx_10Rnd_127x99_m107 {
				magazine = "10Rnd_127x99_m107";
				count = 30;
			};
			
			class _xx_ACE_10Rnd_127x99_T_m107 {
				magazine = "ACE_10Rnd_127x99_T_m107";
				count = 30;
			};
			
			class _xx_ACE_10Rnd_127x99_Raufoss_m107 {
				magazine = "ACE_10Rnd_127x99_Raufoss_m107";
				count = 10;
			};
			
			class _xx_15Rnd_9x19_M9 {
				magazine = "15Rnd_9x19_M9";
				count = 30;
			};
			
			class _xx_15Rnd_9x19_M9SD {
				magazine = "15Rnd_9x19_M9SD";
				count = 30;
			};
			
			class _xx_7Rnd_45ACP_1911 {
				magazine = "7Rnd_45ACP_1911";
				count = 30;
			};
			
			class _xx_1Rnd_SmokeRed_M203 {
				magazine = "1Rnd_SmokeRed_M203";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeGreen_M203 {
				magazine = "1Rnd_SmokeGreen_M203";
				count = 20;
			};
			
			class _xx_1Rnd_SmokeYellow_M203 {
				magazine = "1Rnd_SmokeYellow_M203";
				count = 20;
			};
			
			class _xx_1Rnd_Smoke_M203 {
				magazine = "1Rnd_Smoke_M203";
				count = 20;
			};
			
			class _xx_SmokeShellRed {
				magazine = "SmokeShellRed";
				count = 20;
			};
			
			class _xx_SmokeShellGreen {
				magazine = "SmokeShellGreen";
				count = 20;
			};
			
			class _xx_SmokeShellYellow {
				magazine = "SmokeShellYellow";
				count = 20;
			};
			
			class _xx_SmokeShellBlue {
				magazine = "SmokeShellBlue";
				count = 20;
			};
			
			class _xx_SmokeShellPurple {
				magazine = "SmokeShellPurple";
				count = 20;
			};
			
			class _xx_SmokeShellOrange {
				magazine = "SmokeShellOrange";
				count = 20;
			};
			
			class _xx_SmokeShell {
				magazine = "SmokeShell";
				count = 20;
			};
			
			class _xx_ace_flashbang {
				magazine = "ace_flashbang";
				count = 10;
			};
			
			class _xx_ace_m84 {
				magazine = "ace_m84";
				count = 10;
			};
			
			class _xx_ace_m7a3 {
				magazine = "ace_m7a3";
				count = 10;
			};
			
			class _xx_ACE_1Rnd_CS_M203 {
				magazine = "ACE_1Rnd_CS_M203";
				count = 10;
			};
			
			class _xx_ACE_6Rnd_CS_M32 {
				magazine = "ACE_6Rnd_CS_M32";
				count = 10;
			};
			
			class _xx_ace_m34 {
				magazine = "ace_m34";
				count = 10;
			};
			
			class _xx_ACE_IRStrobe {
				magazine = "ACE_IRStrobe";
				count = 10;
			};
			
			class _xx_ACE_M86PDM {
				magazine = ACE_M86PDM;
				count = 10;
			};
			
			class _xx_ACE_M2SLAM_M {
				magazine = ACE_M2SLAM_M;
				count = 10;
			};
			
			class _xx_ACE_M4SLAM_M {
				magazine = ACE_M4SLAM_M;
				count = 10;
			};
		};
	};
	class USVehicleBox_EP1;	// External class reference
	
	class ACE_USVehicleBox_EP1 : USVehicleBox_EP1 {
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_100Rnd_762x51_M240 {
				magazine = "100Rnd_762x51_M240";
				count = 50;
			};
			
			class _xx_200Rnd_556x45_M249 {
				magazine = "200Rnd_556x45_M249";
				count = 50;
			};
			
			class _xx_ACE_200Rnd_556x45_T_M249 {
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 50;
			};
		};
	};
	class TKBasicAmmunitionBox_EP1;	// External class reference
	
	class ACE_RUBasicAmmunitionBox : TKBasicAmmunitionBox_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_ACE_RDG2 {
				magazine = ACE_RDG2;
				count = 100;
			};
		};
	};
	class TKLaunchers_EP1;	// External class reference
	
	class ACE_RULaunchers : TKLaunchers_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	class TKOrdnanceBox_EP1;	// External class reference
	
	class ACE_RUOrdnanceBox : TKOrdnanceBox_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {
			class _xx_ACE_Pomz_M {
				magazine = "ACE_Pomz_M";
				count = 20;
			};
		};
	};
	class TKBasicWeapons_EP1;	// External class reference
	
	class ACE_RUBasicWeaponsBox : TKBasicWeapons_EP1 {
		vehicleClass = "ACE_Ammunition";
		scope = protected;
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	class TKSpecialWeapons_EP1;	// External class reference
	
	class ACE_RUSpecialWeaponsBox : TKSpecialWeapons_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {
			class _xx_ACE_Earplugs {
				weapon = "ACE_Earplugs";
				count = 5;
			};
			
			class _xx_Binocular {
				weapon = "Binocular";
				count = 5;
			};
			
			class _xx_NVGoggles {
				weapon = "NVGoggles";
				count = 10;
			};
			
			class _xx_Laserdesignator {
				weapon = "Laserdesignator";
				count = 2;
			};
			
			class _xx_ACE_GlassesGasMask_RU {
				weapon = "ACE_GlassesGasMask_RU";
				count = 10;
			};
			
			class _xx_ACE_GlassesBalaklava {
				weapon = "ACE_GlassesBalaklava";
				count = 10;
			};
			
			class _xx_ACE_KeyCuffs {
				weapon = "ACE_KeyCuffs";
				count = 30;
			};
		};
		
		class TransportMagazines {
			class _xx_ACE_1Rnd_CS_GP25 {
				magazine = "ACE_1Rnd_CS_GP25";
				count = 20;
			};
			
			class _xx_ACE_RDG2 {
				magazine = ACE_RDG2;
				count = 100;
			};
			
			class _xx_ACE_RDGM {
				magazine = ACE_RDGM;
				count = 20;
			};
			
			class _xx_ACE_RG60A {
				magazine = ACE_RG60A;
				count = 10;
			};
			
			class _xx_ACE_TORCH_C {
				magazine = ACE_TORCH_C;
				count = 10;
			};
			
			class _xx_ACE_1Rnd_HE_GP25P {
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 50;
			};
		};
	};
	class TKVehicleBox_EP1;	// External class reference
	
	class ACE_RUVehicleBox : TKVehicleBox_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	class UNBasicAmmunitionBox_EP1;	// External class reference
	
	class ACE_LocalBasicAmmunitionBox : UNBasicAmmunitionBox_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	class UNBasicWeapons_EP1;	// External class reference
	
	class ACE_LocalBasicWeaponsBox : UNBasicWeapons_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	class GuerillaCacheBox_EP1;	// External class reference
	
	class ACE_GuerillaCacheBox : GuerillaCacheBox_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	
	class ACE_SpecialWeaponsBox : USSpecialWeapons_EP1 {
		scope = protected;
		vehicleClass = "ACE_Ammunition";
		
		class TransportWeapons {};
		
		class TransportMagazines {};
	};
	
	class ACE_ItemsBox : UNBasicAmmunitionBox_EP1 {
		scope = public;
		vehicleClass = "ACE_Ammunition";
		displayName = "Items Crate";
		
		class TransportWeapons {
			class _xx_ItemWatch {
				weapon = "ItemWatch";
				count = 4;
			};
			
			class _xx_ItemCompass {
				weapon = "ItemCompass";
				count = 4;
			};
			
			class _xx_ItemRadio {
				weapon = "ItemRadio";
				count = 4;
			};
			
			class _xx_ItemGPS {
				weapon = "ItemGPS";
				count = 4;
			};
			
			class _xx_ACE_Map_Tools {
				weapon = "ACE_Map_Tools";
				count = 4;
			};
			
			class _xx_ACE_DAGR {
				weapon = ACE_DAGR;
				count = 4;
			};
			
			class _xx_ACE_Kestrel4500 {
				weapon = "ACE_Kestrel4500";
				count = 4;
			};
		};
		
		class TransportMagazines {};
	};
};

class CfgCoreData {
	rayModel = "x\ace\addons\c_weapon\data\laserBeam.p3d";
};

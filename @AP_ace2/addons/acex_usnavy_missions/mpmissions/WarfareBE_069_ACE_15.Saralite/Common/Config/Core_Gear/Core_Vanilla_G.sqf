private ["_config","_element","_get","_i","_info","_prefix","_proceed","_u"];

_u = [];
_i = [];

/* _i = _i + [[label, picture, config, belong to type, cost, upgrade level, allowed in camps, belong to the handgun pool, magazines, magazine space, allow two weapons]]*/

/* Magazines - West */
_u = _u + ['5Rnd_762x51_M24'];
_i = _i + [['','','CfgMagazines','primary',7,0,true,false,0,0,true]];

_u = _u + ['8Rnd_B_Beneli_74Slug'];
_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];

_u = _u + ['10Rnd_127x99_m107'];
_i = _i + [['','','CfgMagazines','primary',18,0,true,false,0,0,true]];

_u = _u + ['20Rnd_762x51_DMR'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['20Rnd_556x45_Stanag'];
_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];

_u = _u + ['30Rnd_9x19_MP5'];
_i = _i + [['','','CfgMagazines','primary',3,0,true,false,0,0,true]];

_u = _u + ['30Rnd_9x19_MP5SD'];
_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];

_u = _u + ['30Rnd_556x45_G36'];
_i = _i + [['','','CfgMagazines','primary',7,0,true,false,0,0,true]];

_u = _u + ['30Rnd_556x45_G36SD'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['30Rnd_556x45_Stanag'];
_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];

_u = _u + ['30Rnd_556x45_StanagSD'];
_i = _i + [['','','CfgMagazines','primary',7,0,true,false,0,0,true]];

_u = _u + ['100Rnd_556x45_BetaCMag'];
_i = _i + [['','','CfgMagazines','primary',16,0,true,false,0,0,true]];

_u = _u + ['100Rnd_762x51_M240'];
_i = _i + [['','','CfgMagazines','primary',14,0,true,false,0,0,true]];

_u = _u + ['200Rnd_556x45_M249'];
_i = _i + [['','','CfgMagazines','primary',24,0,true,false,0,0,true]];

_u = _u + ['Laserbatteries'];
_i = _i + [['','','CfgMagazines','secondary',20,3,true,false,0,0,true]];

_u = _u + ['Javelin'];
_i = _i + [['','','CfgMagazines','secondary',290,3,false,false,0,0,true]];

_u = _u + ['M136'];
_i = _i + [['','','CfgMagazines','secondary',50,0,true,false,0,0,true]];

_u = _u + ['SMAW_HEAA'];
_i = _i + [['','','CfgMagazines','secondary',225,2,false,false,0,0,true]];

_u = _u + ['SMAW_HEDP'];
_i = _i + [['','','CfgMagazines','secondary',250,3,false,false,0,0,true]];

_u = _u + ['Stinger'];
_i = _i + [['','','CfgMagazines','secondary',100,2,false,false,0,0,true]];

_u = _u + ['7Rnd_45ACP_1911'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['15Rnd_9x19_M9'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['15Rnd_9x19_M9SD'];
_i = _i + [['','','CfgMagazines','sidearm',3,0,true,true,0,0,true]];

if (WF_ACE) then
{
	_u = _u + ['ACE_SMAW_Spotting'];
	_i = _i + [['','','CfgMagazines','CfgMagazines',5,2,true,true,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_556x45_T_G36'];
	_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_556x45_S_G36'];
	_i = _i + [['','','CfgMagazines','primary',8,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_20Rnd_762x51_T_HK417'];
	_i = _i + [['','','CfgMagazines','primary',10,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_20Rnd_762x51_S_HK417'];
	_i = _i + [['','','CfgMagazines','primary',9,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_5Rnd_762x51_T_M24'];
	_i = _i + [['','','CfgMagazines','primary',8,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_20Rnd_762x51_B_HK417'];
	_i = _i + [['','','CfgMagazines','primary',9,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_556x45_T_Stanag'];
	_i = _i + [['','','CfgMagazines','primary',7,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_556x45_S_Stanag'];
	_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_20Rnd_762x51_T_M110'];
	_i = _i + [['','','CfgMagazines','primary',10,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_100Rnd_556x45_T_M249'];
	_i = _i + [['','','CfgMagazines','primary',17,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_200Rnd_556x45_T_M249'];
	_i = _i + [['','','CfgMagazines','primary',25,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_10Rnd_127x99_T_m107'];
	_i = _i + [['','','CfgMagazines','primary',19,3,true,false,0,0,true]];
	
	_u = _u + ['ACE_10Rnd_127x99_Raufoss_m107'];
	_i = _i + [['','','CfgMagazines','primary',25,3,true,false,0,0,true]];
	
	_u = _u + ['ACE_5Rnd_25x59_HEDP_Barrett'];
	_i = _i + [['','','CfgMagazines','primary',35,3,true,false,0,0,true]];
	
	_u = _u + ['ACE_M252HE_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',40,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_M252WP_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',15,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_M2_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',20,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_TOW_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',100,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_20Rnd_762x51_SB_SCAR'];
	_i = _i + [['','','CfgMagazines','secondary',15,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_20Rnd_762x51_SB_S_SCAR'];
	_i = _i + [['','','CfgMagazines','secondary',15,2,true,false,0,0,true]];
};

/* Magazines - East */
_u = _u + ['5x_22_LR_17_HMR'];
_i = _i + [['','','CfgMagazines','primary',3,0,true,false,0,0,true]];

_u = _u + ['5Rnd_127x108_KSVK'];
_i = _i + [['','','CfgMagazines','primary',11,0,true,false,0,0,true]];

_u = _u + ['8Rnd_B_Saiga12_74Slug'];
_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];

_u = _u + ['10Rnd_9x39_SP5_VSS'];
_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];

_u = _u + ['10Rnd_762x54_SVD'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['20Rnd_9x39_SP5_VSS'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['30Rnd_545x39_AK'];
_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];

_u = _u + ['30Rnd_545x39_AKSD'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['30Rnd_762x39_AK47'];
_i = _i + [['','','CfgMagazines','primary',3,0,true,false,0,0,true]];

_u = _u + ['64Rnd_9x19_Bizon'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['64Rnd_9x19_SD_Bizon'];
_i = _i + [['','','CfgMagazines','primary',8,0,true,false,0,0,true]];

_u = _u + ['75Rnd_545x39_RPK'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['100Rnd_762x54_PK'];
_i = _i + [['','','CfgMagazines','primary',12,0,true,false,0,0,true]];

_u = _u + ['AT13'];
_i = _i + [['','','CfgMagazines','secondary',280,3,false,false,0,0,true]];

_u = _u + ['Igla'];
_i = _i + [['','','CfgMagazines','secondary',110,2,false,false,0,0,true]];

_u = _u + ['OG7'];
_i = _i + [['','','CfgMagazines','secondary',95,2,false,false,0,0,true]];

_u = _u + ['PG7V'];
_i = _i + [['','','CfgMagazines','secondary',50,0,true,false,0,0,true]];

_u = _u + ['PG7VR'];
_i = _i + [['','','CfgMagazines','secondary',100,2,false,false,0,0,true]];

_u = _u + ['PG7VL'];
_i = _i + [['','','CfgMagazines','secondary',70,1,true,false,0,0,true]];

_u = _u + ['RPG18'];
_i = _i + [['','','CfgMagazines','secondary',40,0,true,false,0,0,true]];

_u = _u + ['Strela'];
_i = _i + [['','','CfgMagazines','secondary',100,0,false,false,0,0,true]];

_u = _u + ['8Rnd_9x18_Makarov'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['8Rnd_9x18_MakarovSD'];
_i = _i + [['','','CfgMagazines','sidearm',3,0,true,true,0,0,true]];

if (WF_ACE) then
{
	_u = _u + ['ACE_75Rnd_762x39_B_AK47'];
	_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_40Rnd_762x39_B_AK47'];
	_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_75Rnd_762x39_T_AK47'];
	_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_40Rnd_762x39_T_AK47'];
	_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_762x39_T_AK47'];
	_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_762x39_SD_AK47'];
	_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_75Rnd_545x39_T_RPK'];
	_i = _i + [['','','CfgMagazines','primary',10,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_545x39_T_AK'];
	_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_10Rnd_762x54_T_SVD'];
	_i = _i + [['','','CfgMagazines','primary',5,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_5Rnd_127x108_T_KSVK'];
	_i = _i + [['','','CfgMagazines','primary',12,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_TBG7V'];
	_i = _i + [['','','CfgMagazines','secondary',120,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_OG7_PGO7'];
	_i = _i + [['','','CfgMagazines','secondary',95,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_PG7V_PGO7'];
	_i = _i + [['','','CfgMagazines','secondary',50,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_PG7VL_PGO7'];
	_i = _i + [['','','CfgMagazines','secondary',70,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_PG7VR_PGO7'];
	_i = _i + [['','','CfgMagazines','secondary',100,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_TBG7V_PGO7'];
	_i = _i + [['','','CfgMagazines','secondary',120,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_RPG29_PG29'];
	_i = _i + [['','','CfgMagazines','secondary',85,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_RPG29_TBG29'];
	_i = _i + [['','','CfgMagazines','secondary',110,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_2B14HE_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',40,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_2B14WP_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',15,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_KORD_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',20,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_Konkurs_CSWDM'];
	_i = _i + [['','','CfgMagazines','secondary',100,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_30Rnd_762x39_T_SA58'];
	_i = _i + [['','','CfgMagazines','secondary',5,1,true,false,0,0,true]];
};

/* Primary weapons - West */
_u = _u + ['DMR'];
_i = _i + [['','','CfgWeapons','',270,2,false,false,0,0,true]];

_u = _u + ['G36a'];
_i = _i + [['','','CfgWeapons','',225,1,false,false,0,0,true]];

_u = _u + ['G36C'];
_i = _i + [['','','CfgWeapons','',195,0,true,false,0,0,true]];

_u = _u + ['G36_C_SD_eotech'];
_i = _i + [['','','CfgWeapons','',210,2,false,false,0,0,true]];

_u = _u + ['G36K'];
_i = _i + [['','','CfgWeapons','',205,1,false,false,0,0,true]];

_u = _u + ['M16A2'];
_i = _i + [['','','CfgWeapons','',60,0,true,false,0,0,true]];

_u = _u + ['M16A2GL'];
_i = _i + [['','','CfgWeapons','',70,0,true,false,0,0,true]];

_u = _u + ['m16a4'];
_i = _i + [['','','CfgWeapons','',75,0,true,false,0,0,true]];

_u = _u + ['m16a4_acg'];
_i = _i + [['','','CfgWeapons','',85,1,true,false,0,0,true]];

_u = _u + ['M16A4_ACG_GL'];
_i = _i + [['','','CfgWeapons','',95,1,true,false,0,0,true]];

_u = _u + ['M16A4_GL'];
_i = _i + [['','','CfgWeapons','',90,0,true,false,0,0,true]];

_u = _u + ['M24'];
_i = _i + [['','','CfgWeapons','',140,0,true,false,0,0,true]];

_u = _u + ['M40A3'];
_i = _i + [['','','CfgWeapons','',155,2,false,false,0,0,true]];

_u = _u + ['M240'];
_i = _i + [['','','CfgWeapons','',150,0,true,false,0,0,false]];

_u = _u + ['M249'];
_i = _i + [['','','CfgWeapons','',185,2,true,false,0,0,false]];

_u = _u + ['M4A1'];
_i = _i + [['','','CfgWeapons','',95,0,true,false,0,0,true]];

_u = _u + ['M4A1_Aim'];
_i = _i + [['','','CfgWeapons','',105,0,true,false,0,0,true]];

_u = _u + ['M4A1_Aim_camo'];
_i = _i + [['','','CfgWeapons','',150,1,true,false,0,0,true]];

_u = _u + ['M4SPR'];
_i = _i + [['','','CfgWeapons','',160,1,true,false,0,0,true]];

_u = _u + ['M4A1_RCO_GL'];
_i = _i + [['','','CfgWeapons','',115,2,true,false,0,0,true]];

_u = _u + ['M4A1_AIM_SD_camo'];
_i = _i + [['','','CfgWeapons','',165,3,false,false,0,0,true]];

_u = _u + ['M4A1_HWS_GL_SD_Camo'];
_i = _i + [['','','CfgWeapons','',200,3,false,false,0,0,true]];

_u = _u + ['M4A1_HWS_GL'];
_i = _i + [['','','CfgWeapons','',180,3,false,false,0,0,true]];

_u = _u + ['M4A1_HWS_GL_camo'];
_i = _i + [['','','CfgWeapons','',195,3,false,false,0,0,true]];

_u = _u + ['m8_carbine'];
_i = _i + [['','','CfgWeapons','',280,2,true,false,0,0,true]];

_u = _u + ['m8_carbineGL'];
_i = _i + [['','','CfgWeapons','',290,3,true,false,0,0,true]];

_u = _u + ['m8_compact'];
_i = _i + [['','','CfgWeapons','',285,2,false,false,0,0,true]];

_u = _u + ['m8_SAW'];
_i = _i + [['','','CfgWeapons','',310,3,false,false,0,0,false]];

_u = _u + ['m8_sharpshooter'];
_i = _i + [['','','CfgWeapons','',295,3,false,false,0,0,true]];

_u = _u + ['m107'];
_i = _i + [['','','CfgWeapons','',310,3,false,false,0,0,false]];

_u = _u + ['M1014'];
_i = _i + [['','','CfgWeapons','',60,0,true,false,0,0,true]];

_u = _u + ['Mk_48'];
_i = _i + [['','','CfgWeapons','',220,3,false,false,0,0,false]];

_u = _u + ['MP5A5'];
_i = _i + [['','','CfgWeapons','',70,0,true,false,["30Rnd_9x19_MP5","30Rnd_9x19_MP5SD"],0,true]];

_u = _u + ['MP5SD'];
_i = _i + [['','','CfgWeapons','',90,1,true,false,["30Rnd_9x19_MP5SD"],0,true]];

_u = _u + ['MG36'];
_i = _i + [['','','CfgWeapons','',240,2,false,false,0,0,false]];

if (WF_ACE) then
{
	_u = _u + ['ACE_HK416_D10'];
	_i = _i + [['','','CfgWeapons','',100,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D10_Holo'];
	_i = _i + [['','','CfgWeapons','',120,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D10_COMPM3_SD'];
	_i = _i + [['','','CfgWeapons','',140,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D10_M320'];
	_i = _i + [['','','CfgWeapons','',150,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D14'];
	_i = _i + [['','','CfgWeapons','',105,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D14_ACOG_PVS14'];
	_i = _i + [['','','CfgWeapons','',155,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D14_TWS'];
	_i = _i + [['','','CfgWeapons','',220,3,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK416_D14_COMPM3_M320'];
	_i = _i + [['','','CfgWeapons','',165,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK417_Eotech_4x'];
	_i = _i + [['','','CfgWeapons','',125,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK417_micro'];
	_i = _i + [['','','CfgWeapons','',115,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_HK417_leupold'];
	_i = _i + [['','','CfgWeapons','',115,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_M109'];
	_i = _i + [['','','CfgWeapons','',350,3,true,false,0,0,false]];
	
	_u = _u + ['ACE_Javelin_CLU'];
	_i = _i + [['','','CfgWeapons','Special',160,3,true,false,0,0,false]];
};

/* Primary weapons - East */
_u = _u + ['AK_47_M'];
_i = _i + [['','','CfgWeapons','',40,0,true,false,0,0,true]];

_u = _u + ['AK_47_S'];
_i = _i + [['','','CfgWeapons','',50,0,true,false,0,0,true]];

_u = _u + ['AK_74'];
_i = _i + [['','','CfgWeapons','',60,0,true,false,0,0,true]];

_u = _u + ['AK_74_GL'];
_i = _i + [['','','CfgWeapons','',70,0,true,false,0,0,true]];

_u = _u + ['AK_107_kobra'];
_i = _i + [['','','CfgWeapons','',110,0,true,false,0,0,true]];

_u = _u + ['AK_107_GL_kobra'];
_i = _i + [['','','CfgWeapons','',120,0,true,false,0,0,true]];

_u = _u + ['AK_107_pso'];
_i = _i + [['','','CfgWeapons','',125,1,false,false,0,0,true]];

_u = _u + ['AK_107_GL_pso'];
_i = _i + [['','','CfgWeapons','',135,1,false,false,0,0,true]];

_u = _u + ['AKS_74_kobra'];
_i = _i + [['','','CfgWeapons','',90,0,true,false,0,0,true]];

_u = _u + ['AKS_74_pso'];
_i = _i + [['','','CfgWeapons','',105,1,true,false,0,0,true]];

_u = _u + ['AKS_74_U'];
_i = _i + [['','','CfgWeapons','',115,0,true,false,0,0,true]];

_u = _u + ['AKS_74_UN_kobra'];
_i = _i + [['','','CfgWeapons','',155,2,true,false,0,0,true]];

_u = _u + ['AKS_GOLD'];
_i = _i + [['','','CfgWeapons','',350,2,true,false,0,0,true]];

_u = _u + ['bizon'];
_i = _i + [['','','CfgWeapons','',155,1,true,false,0,0,true]];

_u = _u + ['bizon_silenced'];
_i = _i + [['','','CfgWeapons','',175,2,false,false,0,0,true]];

_u = _u + ['PK'];
_i = _i + [['','','CfgWeapons','',190,0,true,false,0,0,false]];

_u = _u + ['Pecheneg'];
_i = _i + [['','','CfgWeapons','',225,2,false,false,0,0,false]];

_u = _u + ['RPK_74'];
_i = _i + [['','','CfgWeapons','',185,1,true,false,0,0,true]];

_u = _u + ['huntingrifle'];
_i = _i + [['','','CfgWeapons','',120,0,true,false,0,0,true]];

_u = _u + ['SVD'];
_i = _i + [['','','CfgWeapons','',160,1,true,false,0,0,true]];

_u = _u + ['SVD_CAMO'];
_i = _i + [['','','CfgWeapons','',180,2,false,false,0,0,true]];

_u = _u + ['Saiga12K'];
_i = _i + [['','','CfgWeapons','',85,0,true,false,0,0,true]];

_u = _u + ['ksvk'];
_i = _i + [['','','CfgWeapons','',255,3,false,false,0,0,false]];

_u = _u + ['VSS_vintorez'];
_i = _i + [['','','CfgWeapons','',220,2,false,false,0,0,true]];

if (WF_ACE) then
{
	_u = _u + ['ACE_SVD_Bipod'];
	_i = _i + [['','','CfgWeapons','',190,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103'];
	_i = _i + [['','','CfgWeapons','',120,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_Kobra'];
	_i = _i + [['','','CfgWeapons','',130,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_PSO'];
	_i = _i + [['','','CfgWeapons','',150,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK104_Kobra'];
	_i = _i + [['','','CfgWeapons','',120,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK104'];
	_i = _i + [['','','CfgWeapons','',105,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK104_PSO'];
	_i = _i + [['','','CfgWeapons','',130,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK104_1P29'];
	_i = _i + [['','','CfgWeapons','',135,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_GL'];
	_i = _i + [['','','CfgWeapons','',160,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_1P29'];
	_i = _i + [['','','CfgWeapons','',140,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_GL_1P29'];
	_i = _i + [['','','CfgWeapons','',175,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_GL_PSO'];
	_i = _i + [['','','CfgWeapons','',175,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK103_GL_Kobra'];
	_i = _i + [['','','CfgWeapons','',155,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK105_1P29'];
	_i = _i + [['','','CfgWeapons','',125,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK105_PSO'];
	_i = _i + [['','','CfgWeapons','',130,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK105_Kobra'];
	_i = _i + [['','','CfgWeapons','',105,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_RPK74M_1P29'];
	_i = _i + [['','','CfgWeapons','',205,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_AKMS_SD'];
	_i = _i + [['','','CfgWeapons','',120,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK74M_GL_1P29'];
	_i = _i + [['','','CfgWeapons','',140,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK74M_GL_PSO'];
	_i = _i + [['','','CfgWeapons','',145,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK74M_GL_Kobra'];
	_i = _i + [['','','CfgWeapons','',120,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK74M_PSO'];
	_i = _i + [['','','CfgWeapons','',105,1,true,false,0,0,true]];
	
	_u = _u + ['ACE_AK74M_1P29'];
	_i = _i + [['','','CfgWeapons','',105,1,true,false,0,0,true]];
};

/* Secondary weapons - West */
_u = _u + ['Javelin'];
_i = _i + [['','','CfgWeapons','',450,3,false,false,0,0,false]];

_u = _u + ['Laserdesignator'];
_i = _i + [['','','CfgWeapons','Special',275,3,true,false,0,0,true]];

_u = _u + ['M136'];
_i = _i + [['','','CfgWeapons','',85,0,true,false,0,0,false]];

_u = _u + ['SMAW'];
_i = _i + [['','','CfgWeapons','',325,2,false,false,0,0,false]];

_u = _u + ['Stinger'];
_i = _i + [['','','CfgWeapons','',250,2,false,false,0,0,false]];

/* Secondary weapons - East */
_u = _u + ['Igla'];
_i = _i + [['','','CfgWeapons','',250,2,false,false,0,0,false]];

_u = _u + ['MetisLauncher'];
_i = _i + [['','','CfgWeapons','',375,3,false,false,0,0,false]];

_u = _u + ['RPG7V'];
_i = _i + [['','','CfgWeapons','',90,1,true,false,0,0,false]];

_u = _u + ['RPG18'];
_i = _i + [['','','CfgWeapons','',50,0,true,false,0,0,false]];

_u = _u + ['Strela'];
_i = _i + [['','','CfgWeapons','',230,2,false,false,0,0,false]];

if (WF_ACE) then
{
	_u = _u + ['ACE_RPG27'];
	_i = _i + [['','','CfgWeapons','',95,1,true,false,0,0,false]];
	
	_u = _u + ['ACE_RPG7V_PGO7'];
	_i = _i + [['','','CfgWeapons','',175,1,true,false,0,0,false]];
	
	_u = _u + ['ACE_RPG29'];
	_i = _i + [['','','CfgWeapons','',165,2,true,false,0,0,false]];
};

/* Pistols - West */
_u = _u + ['Colt1911'];
_i = _i + [['','','CfgWeapons','',15,0,true,false,0,0,true]];

_u = _u + ['M9'];
_i = _i + [['','','CfgWeapons','',20,0,true,false,0,0,true]];

_u = _u + ['M9SD'];
_i = _i + [['','','CfgWeapons','',25,0,true,false,0,0,true]];

/* Pistols - East */
_u = _u + ['Makarov'];
_i = _i + [['','','CfgWeapons','',8,0,true,false,0,0,true]];

_u = _u + ['MakarovSD'];
_i = _i + [['','','CfgWeapons','',15,0,true,false,0,0,true]];

/* Misc - West */
_u = _u + ['HandGrenade_West'];
_i = _i + [['','','CfgMagazines','CfgMagazines',10,0,true,false,0,0,true]];

_u = _u + ['HandGrenade_Stone'];
_i = _i + [['','','CfgMagazines','CfgMagazines',1,0,true,false,0,0,true]];

_u = _u + ['SmokeShell'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['SmokeShellRed'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['SmokeShellGreen'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['SmokeShellBlue'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['SmokeShellYellow'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['SmokeShellOrange'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['SmokeShellPurple'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,false,0,0,true]];

_u = _u + ['FlareWhite_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',9,0,true,true,0,0,true]];

_u = _u + ['FlareYellow_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',9,0,true,true,0,0,true]];

_u = _u + ['FlareGreen_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',9,0,true,true,0,0,true]];

_u = _u + ['FlareRed_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',9,0,true,true,0,0,true]];

_u = _u + ['1Rnd_HE_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',15,0,true,true,0,0,true]];

_u = _u + ['1Rnd_Smoke_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',12,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SmokeRed_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',12,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SmokeGreen_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',12,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SmokeYellow_M203'];
_i = _i + [['','','CfgMagazines','CfgMagazines',12,0,true,true,0,0,true]];

_u = _u + ['Mine'];
_i = _i + [['','','CfgMagazines','CfgMagazines',35,0,true,false,0,0,true]];

_u = _u + ['PipeBomb'];
_i = _i + [['','','CfgMagazines','CfgMagazines',50,0,true,false,0,0,true]];

_u = _u + ['Binocular'];
_i = _i + [['','','CfgWeapons','Special',10,0,true,false,0,0,true]];

_u = _u + ['NVGoggles'];
_i = _i + [['','','CfgWeapons','Special',20,0,true,false,0,0,true]];

_u = _u + ['ItemCompass'];
_i = _i + [['','','CfgWeapons','Item',4,0,true,false,0,0,true]];

_u = _u + ['ItemGPS'];
_i = _i + [['','','CfgWeapons','Item',25,0,true,false,0,0,true]];

_u = _u + ['ItemMap'];
_i = _i + [['','','CfgWeapons','Item',5,0,true,false,0,0,true]];

_u = _u + ['ItemRadio'];
_i = _i + [['','','CfgWeapons','Item',10,0,true,false,0,0,true]];

_u = _u + ['ItemWatch'];
_i = _i + [['','','CfgWeapons','Item',5,0,true,false,0,0,true]];

/* Misc - East */
_u = _u + ['HandGrenade_East'];
_i = _i + [['','','CfgMagazines','CfgMagazines',9,0,true,false,0,0,true]];

_u = _u + ['FlareWhite_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,true,0,0,true]];

_u = _u + ['FlareYellow_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,true,0,0,true]];

_u = _u + ['FlareGreen_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,true,0,0,true]];

_u = _u + ['FlareRed_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',8,0,true,true,0,0,true]];

_u = _u + ['1Rnd_HE_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',13,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SMOKE_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',10,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SMOKERED_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',10,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SMOKEGREEN_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',10,0,true,true,0,0,true]];

_u = _u + ['1Rnd_SMOKEYELLOW_GP25'];
_i = _i + [['','','CfgMagazines','CfgMagazines',10,0,true,true,0,0,true]];

_u = _u + ['MineE'];
_i = _i + [['','','CfgMagazines','CfgMagazines',40,0,true,false,0,0,true]];

for '_z' from 0 to (count _u)-1 do {
	_info = (_i select _z);
	_element = (_u select _z);
	_config = (_info select 2);
	
	if (isClass (configFile >> _config >> _element)) then {
		//--- The loadout has a prefix since we can have two elements with the same name but with different class.
		_get = _element Call GetNamespace;
		_proceed = false;
		_prefix = "";
		
		if (isNil '_get') then {
			_proceed = true;
		} else {
			//--- Two elements can have the same name, like "Javelin(Weapon) >> Javelin (Magazine)", if two elements are found, we compare the class to see if they're already defined or not.
			if ((_get select 2) == _config) then {
				diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_Vanilla_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
			} else {
				//--- Is it a special class?
				_get = (_element+'_W') Call GetNamespace;
				if (isNil '_get') then {
					_prefix = '_w';
					_proceed = true;
				} else {
					diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_Vanilla_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
				};
			};
		};
		
		if (_proceed) then {
			//--- A custom loadout displayName can be set.
			if ((_info select 1) == '') then {_info set [0, [_element,'displayName',_config] Call GetConfigInfo]};
			_info set [1, [_element,'picture',_config] Call GetConfigInfo];
			
			if (_config == 'CfgWeapons') then {
				//--- A custom loadout magazine can be set.
				if (typeName (_info select 8) != 'ARRAY') then {
					_info set [8, getArray (configFile >> _config >> _element >> 'magazines')];
				};
			};
			
			//--- Set the magazine space.
			if (_config == 'CfgMagazines') then {
				if ((_info select 3) in ['CfgMagazines','primary','secondary','sidearm']) then {
					_info set [9, ceil(getNumber(configFile >> _config >> _element >> 'type') / 256)];
				};
			};

			[_element+_prefix,_info] Call SetNamespace;
		};
	} else {
		diag_log Format ["[WFBE (ERROR)][frameno:%3 | ticktime:%4] Core_Vanilla_G: Loadout Element '%1' with class '%2' is not a defined a class!",_element,_config,diag_frameno,diag_tickTime];
	};
};

diag_log Format ["[WFBE (INIT)][frameno:%2 | ticktime:%3] Core_Vanilla_G: Loadout Initialization (%1 Elements) - [Done]",count _u,diag_frameno,diag_tickTime];
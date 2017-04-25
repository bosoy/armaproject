private ["_config","_element","_get","_i","_info","_prefix","_proceed","_u"];

_u = [];
_i = [];

/* _i = _i + [[label, picture, config, belong to type, cost, upgrade level, allowed in camps, belong to the handgun pool, magazines, magazine space, allow two weapons]]*/

/* Magazines - West */
_u = _u + ['5Rnd_762x51_M24'];
_i = _i + [['','','CfgMagazines','primary',7,0,true,false,0,0,true]];

_u = _u + ['6Rnd_HE_M203'];
_i = _i + [['','','CfgMagazines','primary',40,0,true,false,0,0,true]];

_u = _u + ['6Rnd_FlareWhite_M203'];
_i = _i + [['','','CfgMagazines','primary',30,0,true,false,0,0,true]];

_u = _u + ['6Rnd_FlareGreen_M203'];
_i = _i + [['','','CfgMagazines','primary',30,0,true,false,0,0,true]];

_u = _u + ['6Rnd_FlareRed_M203'];
_i = _i + [['','','CfgMagazines','primary',30,0,true,false,0,0,true]];

_u = _u + ['6Rnd_FlareYellow_M203'];
_i = _i + [['','','CfgMagazines','primary',30,0,true,false,0,0,true]];

_u = _u + ['6Rnd_Smoke_M203'];
_i = _i + [['','','CfgMagazines','primary',35,0,true,false,0,0,true]];

_u = _u + ['6Rnd_SmokeRed_M203'];
_i = _i + [['','','CfgMagazines','primary',35,0,true,false,0,0,true]];

_u = _u + ['6Rnd_SmokeGreen_M203'];
_i = _i + [['','','CfgMagazines','primary',35,0,true,false,0,0,true]];

_u = _u + ['6Rnd_SmokeYellow_M203'];
_i = _i + [['','','CfgMagazines','primary',35,0,true,false,0,0,true]];

_u = _u + ['8Rnd_B_Beneli_Pellets'];
_i = _i + [['','','CfgMagazines','primary',3,0,true,false,0,0,true]];

_u = _u + ['10Rnd_127x99_m107'];
_i = _i + [['','','CfgMagazines','primary',18,0,true,false,0,0,true]];

_u = _u + ['20Rnd_762x51_B_SCAR'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['20Rnd_762x51_DMR'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['20Rnd_762x51_SB_SCAR'];
_i = _i + [['','','CfgMagazines','primary',8,0,true,false,0,0,true]];

_u = _u + ['20Rnd_556x45_Stanag'];
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

_u = _u + ['100Rnd_556x45_M249'];
_i = _i + [['','','CfgMagazines','primary',12,0,true,false,0,0,true]];

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

_u = _u + ['MAAWS_HEAT'];
_i = _i + [['','','CfgMagazines','secondary',250,3,false,false,0,0,true]];

_u = _u + ['MAAWS_HEDP'];
_i = _i + [['','','CfgMagazines','secondary',275,2,false,false,0,0,true]];

_u = _u + ['Stinger'];
_i = _i + [['','','CfgMagazines','secondary',125,2,false,false,0,0,true]];

_u = _u + ['7Rnd_45ACP_1911'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['15Rnd_9x19_M9'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['15Rnd_9x19_M9SD'];
_i = _i + [['','','CfgMagazines','sidearm',3,0,true,true,0,0,true]];

_u = _u + ['17Rnd_9x19_glock17'];
_i = _i + [['','','CfgMagazines','sidearm',3,0,true,true,0,0,true]];

if (WF_ACE) then
{
	_u = _u + ['ACE_Battery_Rangefinder'];
	_i = _i + [['','','CfgMagazines','primary',2,0,true,false,0,0,true]];

	_u = _u + ['ACE_HuntIR_M203'];
	_i = _i + [['','','CfgMagazines','CfgMagazines',50,2,true,true,0,0,true]];
};

/* Magazines - East */
_u = _u + ['5Rnd_127x108_KSVK'];
_i = _i + [['','','CfgMagazines','primary',11,0,true,false,0,0,true]];

_u = _u + ['8Rnd_B_Saiga12_Pellets'];
_i = _i + [['','','CfgMagazines','primary',3,0,true,false,0,0,true]];

_u = _u + ['10Rnd_762x54_SVD'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['10x_303'];
_i = _i + [['','','CfgMagazines','primary',2,0,true,false,0,0,true]];

_u = _u + ['20Rnd_762x51_FNFAL'];
_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];

_u = _u + ['20Rnd_9x39_SP5_VSS'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['30Rnd_545x39_AK'];
_i = _i + [['','','CfgMagazines','primary',4,0,true,false,0,0,true]];

_u = _u + ['30Rnd_545x39_AKSD'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['30Rnd_762x39_AK47'];
_i = _i + [['','','CfgMagazines','primary',3,0,true,false,0,0,true]];

_u = _u + ['30Rnd_762x39_SA58'];
_i = _i + [['','','CfgMagazines','primary',6,0,true,false,0,0,true]];

_u = _u + ['75Rnd_545x39_RPK'];
_i = _i + [['','','CfgMagazines','primary',9,0,true,false,0,0,true]];

_u = _u + ['100Rnd_762x54_PK'];
_i = _i + [['','','CfgMagazines','primary',12,0,true,false,0,0,true]];

_u = _u + ['AT13'];
_i = _i + [['','','CfgMagazines','secondary',280,3,false,false,0,0,true]];

_u = _u + ['Dragon_EP1'];
_i = _i + [['','','CfgMagazines','secondary',155,1,false,false,0,0,true]];

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

_u = _u + ['6Rnd_45ACP'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['8Rnd_9x18_Makarov'];
_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];

_u = _u + ['8Rnd_9x18_MakarovSD'];
_i = _i + [['','','CfgMagazines','sidearm',3,0,true,true,0,0,true]];

_u = _u + ['10Rnd_B_765x17_Ball'];
_i = _i + [['','','CfgMagazines','sidearm',3,0,true,true,0,0,true]];

_u = _u + ['20Rnd_B_765x17_Ball'];
_i = _i + [['','','CfgMagazines','sidearm',4,0,true,true,0,0,true]];

_u = _u + ['30Rnd_9x19_UZI'];
_i = _i + [['','','CfgMagazines','sidearm',4,0,true,true,0,0,true]];

_u = _u + ['30Rnd_9x19_UZI_SD'];
_i = _i + [['','','CfgMagazines','sidearm',6,0,true,true,0,0,true]];

if (WF_ACE) then
{
	_u = _u + ['ACE_Battery_Rangefinder'];
	_i = _i + [['','','CfgMagazines','sidearm',2,0,true,true,0,0,true]];
};

/* Primary weapons - West */
_u = _u + ['G36A_camo'];
_i = _i + [['','','CfgWeapons','',225,1,false,false,0,0,true]];

_u = _u + ['G36C_camo'];
_i = _i + [['','','CfgWeapons','',195,0,true,false,0,0,true]];

_u = _u + ['G36_C_SD_camo'];
_i = _i + [['','','CfgWeapons','',210,2,false,false,0,0,true]];

_u = _u + ['G36K_camo'];
_i = _i + [['','','CfgWeapons','',205,1,false,false,0,0,true]];

_u = _u + ['M16A2'];
_i = _i + [['','','CfgWeapons','',60,0,true,false,0,0,true]];

_u = _u + ['M16A2GL'];
_i = _i + [['','','CfgWeapons','',70,0,true,false,0,0,true]];

_u = _u + ['M24_des_EP1'];
_i = _i + [['','','CfgWeapons','',140,0,true,false,0,0,true]];

_u = _u + ['M60A4_EP1'];
_i = _i + [['','','CfgWeapons','',170,0,true,false,0,0,false]];

_u = _u + ['m240_scoped_EP1'];
_i = _i + [['','','CfgWeapons','',165,0,true,false,0,0,false]];

_u = _u + ['M249_EP1'];
_i = _i + [['','','CfgWeapons','',185,2,true,false,0,0,false]];

_u = _u + ['M249_m145_EP1'];
_i = _i + [['','','CfgWeapons','',210,2,true,false,0,0,false]];

_u = _u + ['M249_TWS_EP1'];
_i = _i + [['','','CfgWeapons','',285,3,false,false,0,0,false]];

_u = _u + ['M4A1'];
_i = _i + [['','','CfgWeapons','',95,0,true,false,0,0,true]];

_u = _u + ['M4A3_CCO_EP1'];
_i = _i + [['','','CfgWeapons','',115,0,true,false,0,0,true]];

_u = _u + ['M4A3_RCO_GL_EP1'];
_i = _i + [['','','CfgWeapons','',125,1,true,false,0,0,true]];

_u = _u + ['m107'];
_i = _i + [['','','CfgWeapons','',310,3,false,false,0,0,true]];

_u = _u + ['m107_TWS_EP1'];
_i = _i + [['','','CfgWeapons','',410,3,false,false,0,0,false]];

_u = _u + ['Mk_48_DES_EP1'];
_i = _i + [['','','CfgWeapons','',220,3,false,false,0,0,false]];

_u = _u + ['MG36_camo'];
_i = _i + [['','','CfgWeapons','',240,2,false,false,0,0,false]];

_u = _u + ['M32_EP1'];
_i = _i + [['','','CfgWeapons','',210,2,false,false,["6Rnd_HE_M203","6Rnd_FlareWhite_M203","6Rnd_FlareGreen_M203","6Rnd_FlareRed_M203","6Rnd_FlareYellow_M203","6Rnd_Smoke_M203","6Rnd_SmokeRed_M203","6Rnd_SmokeGreen_M203","6Rnd_SmokeYellow_M203"],0,true]];

_u = _u + ['M79_EP1'];
_i = _i + [['','','CfgWeapons','',80,0,true,false,[],0,true]];

/* Mk13 use handgun pool ammos */
_u = _u + ['Mk13_EP1'];
_i = _i + [['','','CfgWeapons','',110,0,true,false,[],0,true]];

_u = _u + ['M14_EP1'];
_i = _i + [['','','CfgWeapons','',190,0,true,false,0,0,true]];

_u = _u + ['M110_TWS_EP1'];
_i = _i + [['','','CfgWeapons','',350,3,false,false,0,0,true]];

_u = _u + ['M110_NVG_EP1'];
_i = _i + [['','','CfgWeapons','',290,2,false,false,0,0,true]];

_u = _u + ['SCAR_L_CQC'];
_i = _i + [['','','CfgWeapons','',190,0,true,false,0,0,true]];

_u = _u + ['SCAR_L_CQC_Holo'];
_i = _i + [['','','CfgWeapons','',210,1,true,false,0,0,true]];

_u = _u + ['SCAR_L_STD_Mk4CQT'];
_i = _i + [['','','CfgWeapons','',215,2,true,false,0,0,true]];

_u = _u + ['SCAR_L_STD_EGLM_RCO'];
_i = _i + [['','','CfgWeapons','',230,1,true,false,0,0,true]];

_u = _u + ['SCAR_L_CQC_EGLM_Holo'];
_i = _i + [['','','CfgWeapons','',245,1,true,false,0,0,true]];

_u = _u + ['SCAR_L_STD_EGLM_TWS'];
_i = _i + [['','','CfgWeapons','',345,3,true,false,0,0,true]];

_u = _u + ['SCAR_L_STD_HOLO'];
_i = _i + [['','','CfgWeapons','',215,1,true,false,0,0,true]];

_u = _u + ['SCAR_H_CQC_CCO'];
_i = _i + [['','','CfgWeapons','',225,1,true,false,0,0,true]];

_u = _u + ['SCAR_H_CQC_CCO_SD'];
_i = _i + [['','','CfgWeapons','',250,2,true,false,0,0,true]];

_u = _u + ['SCAR_H_STD_EGLM_Spect'];
_i = _i + [['','','CfgWeapons','',280,2,true,false,0,0,true]];

_u = _u + ['SCAR_H_LNG_Sniper'];
_i = _i + [['','','CfgWeapons','',275,2,true,false,0,0,true]];

_u = _u + ['SCAR_H_LNG_Sniper_SD'];
_i = _i + [['','','CfgWeapons','',295,3,true,false,0,0,true]];

_u = _u + ['SCAR_H_STD_TWS_SD'];
_i = _i + [['','','CfgWeapons','',395,3,true,false,0,0,true]];

/* Primary weapons - East */
_u = _u + ['AK_47_M'];
_i = _i + [['','','CfgWeapons','',40,0,true,false,0,0,true]];

_u = _u + ['AK_47_S'];
_i = _i + [['','','CfgWeapons','',50,0,true,false,0,0,true]];

_u = _u + ['AK_74'];
_i = _i + [['','','CfgWeapons','',60,0,true,false,0,0,true]];

_u = _u + ['AK_74_GL'];
_i = _i + [['','','CfgWeapons','',70,0,true,false,0,0,true]];

_u = _u + ['AK_74_GL_kobra'];
_i = _i + [['','','CfgWeapons','',85,0,true,false,0,0,true]];

_u = _u + ['AKS_74'];
_i = _i + [['','','CfgWeapons','',80,0,true,false,0,0,true]];

_u = _u + ['AKS_74_GOSHAWK'];
_i = _i + [['','','CfgWeapons','',180,2,true,false,0,0,true]];

_u = _u + ['AKS_74_kobra'];
_i = _i + [['','','CfgWeapons','',90,0,true,false,0,0,true]];

_u = _u + ['AKS_74_NSPU'];
_i = _i + [['','','CfgWeapons','',145,1,true,false,0,0,true]];

_u = _u + ['AKS_74_pso'];
_i = _i + [['','','CfgWeapons','',105,1,true,false,0,0,true]];

_u = _u + ['AKS_74_U'];
_i = _i + [['','','CfgWeapons','',115,0,true,false,0,0,true]];

_u = _u + ['FN_FAL'];
_i = _i + [['','','CfgWeapons','',110,0,true,false,0,0,true]];

_u = _u + ['FN_FAL_ANPVS4'];
_i = _i + [['','','CfgWeapons','',140,1,true,false,0,0,true]];

_u = _u + ['LeeEnfield'];
_i = _i + [['','','CfgWeapons','',25,0,true,false,0,0,true]];

_u = _u + ['PK'];
_i = _i + [['','','CfgWeapons','',190,0,true,false,0,0,false]];

_u = _u + ['RPK_74'];
_i = _i + [['','','CfgWeapons','',185,1,true,false,0,0,true]];

_u = _u + ['Sa58P_EP1'];
_i = _i + [['','','CfgWeapons','',110,0,true,false,0,0,true]];

_u = _u + ['Sa58V_EP1'];
_i = _i + [['','','CfgWeapons','',120,0,true,false,0,0,true]];

_u = _u + ['Sa58V_RCO_EP1'];
_i = _i + [['','','CfgWeapons','',155,1,true,false,0,0,true]];

_u = _u + ['Sa58V_CCO_EP1'];
_i = _i + [['','','CfgWeapons','',145,1,true,false,0,0,true]];

_u = _u + ['SVD'];
_i = _i + [['','','CfgWeapons','',160,1,true,false,0,0,true]];

_u = _u + ['SVD_des_EP1'];
_i = _i + [['','','CfgWeapons','',180,2,false,false,0,0,true]];

_u = _u + ['SVD_NSPU_EP1'];
_i = _i + [['','','CfgWeapons','',210,2,false,false,0,0,true]];

_u = _u + ['ksvk'];
_i = _i + [['','','CfgWeapons','',255,3,false,false,0,0,false]];

/* Secondary weapons - West */
_u = _u + ['Javelin'];
_i = _i + [['','','CfgWeapons','',290,3,false,false,0,0,false]];

_u = _u + ['Laserdesignator'];
_i = _i + [['','','CfgWeapons','',275,3,true,false,0,0,true]];

_u = _u + ['M136'];
_i = _i + [['','','CfgWeapons','',85,0,true,false,0,0,false]];

_u = _u + ['MAAWS'];
_i = _i + [['','','CfgWeapons','',350,2,false,false,0,0,false]];

_u = _u + ['Stinger'];
_i = _i + [['','','CfgWeapons','',250,2,false,false,0,0,false]];

if(WF_ACE) then
{
	_u = _u + ['ACE_Rucksack_MOLLE_Brown'];
	_i = _i + [['','','CfgWeapons','',80,1,true,false,0,0,false]];

	_u = _u + ['ACE_Coyote_Pack'];
	_i = _i + [['','','CfgWeapons','',70,0,true,false,0,0,false]];

	_u = _u + ['ACE_CharliePack'];
	_i = _i + [['','','CfgWeapons','',90,2,true,false,0,0,false]];
	
	_u = _u + ['ACE_M252Proxy'];
	_i = _i + [['','','CfgWeapons','',600,1,true,false,0,0,false]];
	
	_u = _u + ['ACE_M252TripodProxy'];
	_i = _i + [['','','CfgWeapons','',40,1,true,false,0,0,false]];
	
	_u = _u + ['ACE_M2HBProxy'];
	_i = _i + [['','','CfgWeapons','',140,0,true,false,0,0,false]];
	
	_u = _u + ['ACE_M3TripodProxy'];
	_i = _i + [['','','CfgWeapons','',25,0,true,false,0,0,false]];
	
	_u = _u + ['ACE_M220Proxy'];
	_i = _i + [['','','CfgWeapons','',500,2,true,false,0,0,false]];
	
	_u = _u + ['ACE_M220TripodProxy'];
	_i = _i + [['','','CfgWeapons','',40,2,true,false,0,0,false]];
}
else
{
	_u = _u + ['US_Assault_Pack_EP1'];
	_i = _i + [['','','CfgVehicles','',80,1,true,false,0,0,false]];

	_u = _u + ['US_Patrol_Pack_EP1'];
	_i = _i + [['','','CfgVehicles','',70,0,true,false,0,0,false]];

	_u = _u + ['US_Backpack_EP1'];
	_i = _i + [['','','CfgVehicles','',90,2,true,false,0,0,false]];
	
	_u = _u + ['Tripod_Bag'];
	_i = _i + [['','','CfgVehicles','',25,0,true,false,0,0,false]];

	_u = _u + ['M2HD_mini_TriPod_US_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',155,0,false,false,0,0,false]];

	_u = _u + ['M2StaticMG_US_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',190,0,false,false,0,0,false]];

	_u = _u + ['MK19_TriPod_US_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',450,1,false,false,0,0,false]];

	_u = _u + ['TOW_TriPod_US_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',600,2,false,false,0,0,false]];

	_u = _u + ['M252_US_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',750,1,false,false,0,0,false]];
};

/* Secondary weapons - East */
_u = _u + ['Igla'];
_i = _i + [['','','CfgWeapons','',250,2,false,false,0,0,false]];

_u = _u + ['M47Launcher_EP1'];
_i = _i + [['','','CfgWeapons','',275,2,false,false,0,0,false]];

_u = _u + ['MetisLauncher'];
_i = _i + [['','','CfgWeapons','',350,3,false,false,0,0,false]];

_u = _u + ['RPG7V'];
_i = _i + [['','','CfgWeapons','',90,1,true,false,0,0,false]];

_u = _u + ['RPG18'];
_i = _i + [['','','CfgWeapons','',50,0,true,false,0,0,false]];

_u = _u + ['Strela'];
_i = _i + [['','','CfgWeapons','',230,2,false,false,0,0,false]];

if(WF_ACE) then
{
	_u = _u + ['ACE_Rucksack_RD90'];
	_i = _i + [['','','CfgWeapons','',80,1,true,false,0,0,false]];

	_u = _u + ['ACE_Rucksack_RD54'];
	_i = _i + [['','','CfgWeapons','',70,0,true,false,0,0,false]];

	_u = _u + ['ACE_Rucksack_RD99'];
	_i = _i + [['','','CfgWeapons','',90,2,true,false,0,0,false]];
	
	_u = _u + ['ACE_2b14Proxy'];
	_i = _i + [['','','CfgWeapons','',600,1,true,false,0,0,false]];
	
	_u = _u + ['ACE_2b14TripodProxy'];
	_i = _i + [['','','CfgWeapons','',40,1,true,false,0,0,false]];
	
	_u = _u + ['ACE_KORDProxy'];
	_i = _i + [['','','CfgWeapons','',140,0,true,false,0,0,false]];
	
	_u = _u + ['ACE_6T7TripodProxy'];
	_i = _i + [['','','CfgWeapons','',25,0,true,false,0,0,false]];
	
	_u = _u + ['ACE_KonkursTripodProxy'];
	_i = _i + [['','','CfgWeapons','',500,2,true,false,0,0,false]];
}
else
{
	_u = _u + ['TK_Assault_Pack_EP1'];
	_i = _i + [['','','CfgVehicles','',80,1,true,false,0,0,false]];

	_u = _u + ['TK_RPG_Backpack_EP1'];
	_i = _i + [['','','CfgVehicles','',70,0,true,false,0,0,false]];

	_u = _u + ['TK_ALICE_Pack_EP1'];
	_i = _i + [['','','CfgVehicles','',90,2,true,false,0,0,false]];
	
	_u = _u + ['Tripod_Bag'];
	_i = _i + [['','','CfgVehicles','',40,0,false,false,0,0,false]];

	_u = _u + ['KORD_TK_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',155,0,false,false,0,0,false]];

	_u = _u + ['KORD_high_TK_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',190,0,false,false,0,0,false]];

	_u = _u + ['SPG9_TK_INS_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',410,1,false,false,0,0,false]];

	_u = _u + ['AGS_TK_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',490,1,false,false,0,0,false]];

	_u = _u + ['Metis_TK_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',600,2,false,false,0,0,false]];

	_u = _u + ['2b14_82mm_TK_Bag_EP1'];
	_i = _i + [['','','CfgVehicles','',750,1,false,false,0,0,false]];
};

/* Pistols - West */
_u = _u + ['Colt1911'];
_i = _i + [['','','CfgWeapons','',15,0,true,false,0,0,true]];

_u = _u + ['M9'];
_i = _i + [['','','CfgWeapons','',20,0,true,false,0,0,true]];

_u = _u + ['M9SD'];
_i = _i + [['','','CfgWeapons','',25,0,true,false,0,0,true]];

_u = _u + ['glock17_EP1'];
_i = _i + [['','','CfgWeapons','',35,1,true,false,0,0,true]];

/* Pistols - East */
_u = _u + ['Makarov'];
_i = _i + [['','','CfgWeapons','',8,0,true,false,0,0,true]];

_u = _u + ['MakarovSD'];
_i = _i + [['','','CfgWeapons','',15,0,true,false,0,0,true]];

_u = _u + ['revolver_EP1'];
_i = _i + [['','','CfgWeapons','',10,0,true,false,0,0,true]];

_u = _u + ['revolver_gold_EP1'];
_i = _i + [['','','CfgWeapons','',10,1,true,false,0,0,true]];

_u = _u + ['Sa61_EP1'];
_i = _i + [['','','CfgWeapons','',25,0,true,false,0,0,true]];

_u = _u + ['UZI_EP1'];
_i = _i + [['','','CfgWeapons','',55,1,true,false,["30Rnd_9x19_UZI","30Rnd_9x19_UZI_SD"],0,true]];

_u = _u + ['UZI_SD_EP1'];
_i = _i + [['','','CfgWeapons','',65,2,true,false,["30Rnd_9x19_UZI_SD"],0,true]];

/* Misc - West */
_u = _u + ['HandGrenade_West'];
_i = _i + [['','','CfgMagazines','CfgMagazines',10,0,true,false,0,0,true]];

_u = _u + ['HandGrenade_Stone'];
_i = _i + [['','','CfgMagazines','CfgMagazines',1,0,true,false,0,0,true]];

_u = _u + ['IR_Strobe_Target'];
_i = _i + [['','','CfgMagazines','CfgMagazines',25,0,true,false,0,0,true]];

_u = _u + ['IR_Strobe_Marker'];
_i = _i + [['','','CfgMagazines','CfgMagazines',35,0,true,false,0,0,true]];

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

if(WF_ACE) then
{
	_u = _u + ['ACE_Bandage'];
	_i = _i + [['','','CfgMagazines','CfgMagazines',2,0,true,true,0,0,true]];
	
	_u = _u + ['ACE_Epinephrine'];
	_i = _i + [['','','CfgMagazines','CfgMagazines',20,0,true,true,0,0,true]];
	
	_u = _u + ['ACE_Morphine'];
	_i = _i + [['','','CfgMagazines','CfgMagazines',20,0,true,true,0,0,true]];
	
	_u = _u + ['ACE_Medkit'];
	_i = _i + [['','','CfgMagazines','CfgMagazines',50,0,true,true,0,0,true]];
};

_u = _u + ['Mine'];
_i = _i + [['','','CfgMagazines','CfgMagazines',35,0,true,false,0,0,true]];

_u = _u + ['PipeBomb'];
_i = _i + [['','','CfgMagazines','CfgMagazines',50,0,true,false,0,0,true]];

_u = _u + ['Binocular'];
_i = _i + [['','','CfgWeapons','Special',10,0,true,false,0,0,true]];

_u = _u + ['NVGoggles'];
_i = _i + [['','','CfgWeapons','Special',20,0,true,false,0,0,true]];

_u = _u + ['Binocular_Vector'];
_i = _i + [['','','CfgWeapons','Special',50,1,true,false,0,0,true]];

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

if (WF_ACE) then
{
	_u = _u + ['ACE_HuntIR_monitor'];
	_i = _i + [['','','CfgWeapons','Item',50,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_Earplugs'];
	_i = _i + [['','','CfgWeapons','Item',1,0,true,false,0,0,true]];

	_u = _u + ['ACE_MX2A'];
	_i = _i + [['','','CfgWeapons','Special',50,2,true,false,0,0,true]];
	
	_u = _u + ['ACE_GlassesLHD_glasses'];
	_i = _i + [['','','CfgWeapons','Item',5,0,true,false,0,0,true]];
	
	_u = _u + ['ACE_GlassesTactical'];
	_i = _i + [['','','CfgWeapons','Item',3,0,true,false,0,0,true]];
};

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
				diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_Arrowhead_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
			} else {
				//--- Is it a special class?
				_get = (_element+'_W') Call GetNamespace;
				if (isNil '_get') then {
					_prefix = '_W';
					_proceed = true;
				} else {
					diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Core_Arrowhead_G: Duplicated Loadout Element found '%1' for class '%2'",_element,_config,diag_frameno,diag_tickTime];
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
		diag_log Format ["[WFBE (ERROR)][frameno:%3 | ticktime:%4] Core_Arrowhead_G: Loadout Element '%1' with class '%2' is not a defined a class!",_element,_config,diag_frameno,diag_tickTime];
	};
};

diag_log Format ["[WFBE (INIT)][frameno:%2 | ticktime:%3] Core_Arrowhead_G: Loadout Initialization (%1 Elements) - [Done]",count _u,diag_frameno,diag_tickTime];
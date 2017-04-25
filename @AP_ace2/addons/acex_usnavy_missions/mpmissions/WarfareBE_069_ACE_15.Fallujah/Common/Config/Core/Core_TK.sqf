/* TK Configuration */
private ["_c","_get","_i","_p"];

_c = [];
_i = [];

/* Infantry */
_c = _c + ['TK_Soldier_EP1'];
_i = _i + [['','',150,4,-1,0,0,0.77,'Takistani']];

_c = _c + ['TK_Soldier_B_EP1'];
_i = _i + [['','',125,4,-1,0,0,0.77,'Takistani']];

_c = _c + ['TK_Soldier_TWS_EP1'];
_i = _i + [['','',205,5,-1,0,0,0.82,'Takistani']];

_c = _c + ['TK_Soldier_Engineer_EP1'];
_i = _i + [['','',155,5,-1,0,0,0.78,'Takistani']];

_c = _c + ['TK_Soldier_LAT_EP1'];
_i = _i + [['','',225,5,-1,0,0,0.78,'Takistani']];

_c = _c + ['TK_Soldier_AT_EP1'];
_i = _i + [['','',310,5,-1,1,0,0.8,'Takistani']];

_c = _c + ['TK_Soldier_HAT_EP1'];
_i = _i + [['','',620,7,-1,3,0,0.83,'Takistani']];

_c = _c + ['TK_Soldier_AA_EP1'];
_i = _i + [['','',425,6,-1,1,0,0.82,'Takistani']];

_c = _c + ['TK_Soldier_AR_EP1'];
_i = _i + [['','',210,5,-1,1,0,0.79,'Takistani']];

_c = _c + ['TK_Soldier_MG_EP1'];
_i = _i + [['','',220,5,-1,0,0,0.8,'Takistani']];

_c = _c + ['TK_Soldier_GL_EP1'];
_i = _i + [['','',160,5,-1,0,0,0.78,'Takistani']];

_c = _c + ['TK_Soldier_Sniper_EP1'];
_i = _i + [['','',280,5,-1,1,0,0.88,'Takistani']];

_c = _c + ['TK_Soldier_Spotter_EP1'];
_i = _i + [['','',290,5,-1,1,0,0.82,'Takistani']];

_c = _c + ['TK_Soldier_Medic_EP1'];
_i = _i + [['','',190,4,-1,0,0,0.81,'Takistani']];

_c = _c + ['TK_Soldier_Crew_EP1'];
_i = _i + [['','',120,4,-1,0,0,0.76,'Takistani']];

_c = _c + ['TK_Soldier_Pilot_EP1'];
_i = _i + [['','',120,4,-1,0,0,0.77,'Takistani']];

_c = _c + ['TK_Soldier_Officer_EP1'];
_i = _i + [['','',240,5,-1,1,0,0.85,'Takistani']];

_c = _c + ['TK_Soldier_SL_EP1'];
_i = _i + [['','',220,5,-1,2,0,0.86,'Takistani']];

/* Light Vehicles */
_c = _c + ['TT650_TK_EP1'];
_i = _i + [['','',150,15,1,0,1,0,'Takistani']];

_c = _c + ['UAZ_Unarmed_TK_EP1'];
_i = _i + [['','',260,15,1,0,1,0,'Takistani']];

_c = _c + ['SUV_TK_EP1'];
_i = _i + [['','',290,15,1,0,1,0,'Takistani']];

_c = _c + ['UAZ_MG_TK_EP1'];
_i = _i + [['','',460,15,2,0,1,0,'Takistani']];

_c = _c + ['UAZ_AGS30_TK_EP1'];
_i = _i + [['','',585,15,2,1,1,0,'Takistani']];

_c = _c + ['LandRover_MG_TK_EP1'];
_i = _i + [['','',550,17,2,0,1,0,'Takistani']];

_c = _c + ['LandRover_SPG9_TK_EP1'];
_i = _i + [['','',750,17,2,2,1,0,'Takistani']];

_c = _c + ['V3S_TK_EP1'];
_i = _i + [['','',275,20,1,0,1,0,'Takistani']];

_c = _c + ['V3S_Open_TK_EP1'];
_i = _i + [['','',250,20,1,0,1,0,'Takistani']];

_c = _c + ['UralRepair_TK_EP1'];
_i = _i + [['','',1250,21,1,2,1,0,'Takistani']];

_c = _c + ['UralSalvage_TK_EP1'];
_i = _i + [['','',450,17,1,1,1,0,'Takistani']];

_c = _c + ['UralReammo_TK_EP1'];
_i = _i + [['','',450,18,1,1,1,0,'Takistani']];

_c = _c + ['UralRefuel_TK_EP1'];
_i = _i + [['','',400,19,1,1,1,0,'Takistani']];

_c = _c + ['UralSupply_TK_EP1'];
_i = _i + [['','',450,21,1,0,1,0,'Takistani']];

_c = _c + ['M113Ambul_TK_EP1'];
_i = _i + [['','',750,25,1,1,1,0,'Takistani']];

_c = _c + ['BRDM2_TK_EP1'];
_i = _i + [['','',1100,22,2,1,1,0,'Takistani']];

_c = _c + ['BRDM2_ATGM_TK_EP1'];
_i = _i + [['','',1650,22,2,2,1,0,'Takistani']];

_c = _c + ['BTR60_TK_EP1'];
_i = _i + [['','',1425,25,3,2,1,0,'Takistani']];

_c = _c + ['Ural_ZU23_TK_EP1'];
_i = _i + [['','',1750,25,2,2,1,0,'Takistani']];

_c = _c + ['GRAD_TK_EP1'];
_i = _i + [['','',4200,25,2,3,1,0,'Takistani']];

/* Heavy Vehicles */
_c = _c + ['M113_TK_EP1'];
_i = _i + [['','',1100,22,2,0,2,0,'Takistani']];

_c = _c + ['BMP2_TK_EP1'];
_i = _i + [['','',2600,25,3,if (WF_A2_Arrowhead) then {0} else {1},2,0,'Takistani']];

_c = _c + ['ZSU_TK_EP1'];
_i = _i + [['','',3400,25,3,1,2,0,'Takistani']];

_c = _c + ['T34_TK_EP1'];
_i = _i + [['','',3900,25,3,0,2,0,'Takistani']];

_c = _c + ['T55_TK_EP1'];
_i = _i + [['','',4500,27,3,1,2,0,'Takistani']];

_c = _c + ['T72_TK_EP1'];
_i = _i + [['','',4900,30,3,2,2,0,'Takistani']];

/* Air Vehicles */
_c = _c + ['An2_TK_EP1'];
_i = _i + [['','',6200,35,1,1,3,0,'Takistani']];

_c = _c + ['Mi17_TK_EP1'];
_i = _i + [['','',7000,35,2,0,3,0,'Takistani']];

_c = _c + ['UH1H_TK_EP1'];
_i = _i + [['','',7500,35,2,0,3,0,'Takistani']];

_c = _c + ['Mi24_D_TK_EP1'];
_i = _i + [['','',32800,40,2,1,3,0,'Takistani']];

_c = _c + ['L39_TK_EP1'];
_i = _i + [['','',38700,50,1,2,3,0,'Takistani']];

_c = _c + ['Su25_TK_EP1'];
_i = _i + [['','',46400,55,1,3,3,0,'Takistani']];

/* Static Defenses */
_c = _c + ['WarfareBMGNest_PK_TK_EP1'];
_i = _i + [['','',300,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['KORD_TK_EP1'];
_i = _i + [['KORD Minitripod','',200,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['KORD_high_TK_EP1'];
_i = _i + [['KORD','',225,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['SearchLight_TK_EP1'];
_i = _i + [['','',125,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['AGS_TK_EP1'];
_i = _i + [['','',650,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['SPG9_TK_INS_EP1'];
_i = _i + [['','',475,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['Metis_TK_EP1'];
_i = _i + [['Metis-M 9K115-2','',725,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['Igla_AA_pod_TK_EP1'];
_i = _i + [['Igla AA POD launcher','',815,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['ZU23_TK_EP1'];
_i = _i + [['','',945,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['2b14_82mm_TK_EP1'];
_i = _i + [['Podnos 2B14','',1025,0,1,0,'Defense',0,'Takistani']];

_c = _c + ['D30_TK_EP1'];
_i = _i + [['','',2300,0,1,0,'Defense',0,'Takistani']];

/* Defense Structures */
_c = _c + ['TK_WarfareBBarrier5x_EP1'];
_i = _i + [['','',15,0,0,0,'Fortification',0,'Takistani']];

_c = _c + ['TK_WarfareBBarrier10x_EP1'];
_i = _i + [['','',25,0,0,0,'Fortification',0,'Takistani']];

_c = _c + ['TK_WarfareBBarrier10xTall_EP1'];
_i = _i + [['','',50,0,0,0,'Fortification',0,'Takistani']];

_c = _c + ['Land_CamoNet_EAST_EP1'];
_i = _i + [['','',35,0,0,0,'Strategic',0,'Takistani']];

_c = _c + ['Land_CamoNetVar_EAST_EP1'];
_i = _i + [['','',45,0,0,0,'Strategic',0,'Takistani']];

_c = _c + ['Land_CamoNetB_EAST_EP1'];
_i = _i + [['','',55,0,0,0,'Strategic',0,'Takistani']];

_c = _c + ['TKOrdnanceBox_EP1'];
_i = _i + [['','',850,0,0,0,'Ammo',0,'Takistani']];

_c = _c + ['TKVehicleBox_EP1'];
_i = _i + [['','',1200,0,0,0,'Ammo',0,'Takistani']];

_c = _c + ['TKBasicAmmunitionBox_EP1'];
_i = _i + [['','',1950,0,0,0,'Ammo',0,'Takistani']];

_c = _c + ['TKBasicWeapons_EP1'];
_i = _i + [['','',2975,0,0,0,'Ammo',0,'Takistani']];

_c = _c + ['TKLaunchers_EP1'];
_i = _i + [['','',6250,0,0,0,'Ammo',0,'Takistani']];

_c = _c + ['TKSpecialWeapons_EP1'];
_i = _i + [['','',7200,0,0,0,'Ammo',0,'Takistani']];

for '_z' from 0 to (count _c)-1 do {
	if (isClass (configFile >> 'CfgVehicles' >> (_c select _z))) then {
		_get = (_c select _z) Call GetNamespace;
		if (isNil '_get') then {
			if ((_i select _z) select 0 == '') then {(_i select _z) set [0, [_c select _z,'displayName'] Call GetConfigInfo]};
			if (WF_Debug) then {(_i select _z) set [3,1]};
			_p = if ((_c select _z) isKindOf 'Man') then {'portrait'} else {'picture'};
			(_i select _z) set [1, [_c select _z,_p] Call GetConfigInfo];
			[_c select _z,_i select _z] Call SetNamespace;
		} else {
			diag_log Format ["[WFBE (INIT)][frameno:%2 | ticktime:%3] Core_TK: Duplicated Element found '%1'",(_c select _z),diag_frameno,diag_tickTime];
		};
	} else {
		diag_log Format ["[WFBE (ERROR)][frameno:%2 | ticktime:%3] Core_TK: Element '%1' is not a valid class.",(_c select _z),diag_frameno,diag_tickTime];
	};
};

diag_log Format ["[WFBE (INIT)][frameno:%2 | ticktime:%3] Core_TK: Initialization (%1 Elements) - [Done]",count _c,diag_frameno,diag_tickTime];
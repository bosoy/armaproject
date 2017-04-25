// by Xeno
#define THIS_FILE "x_weaponcargor_oa_ace.sqf"
#include "x_setup.sqf"
private "_vec";
PARAMS_1(_vec);

#define __awc(wtype,wcount) _vec addWeaponCargo [#wtype,wcount];
#define __amc(mtype,mcount) _vec addMagazineCargo [#mtype,mcount];

if (isNil "x_ranked_weapons") then {
		_x_ranked_weapons_w = [
			[
				// private rifles
				[
					["M16A2",5],["FN_FAL",5],["Sa58P_EP1",5],["Sa58V_EP1",5],["LeeEnfield",5],["ACE_MP5A4",5],["ACE_UMP45",5],["ACE_UMP45_SD",5],["ACE_SpottingScope",5],["ACE_WireCutter",5]
				],
				// corporal rifles (gets added to private rifles)
				[
					["M16A2GL",5],["M4A1",5],["G36C_camo",5],["G36A_camo",5],["G36K_camo",5],["M14_EP1",5],["ACE_SOC_M4A1_Aim",5],["ACE_SOC_M4A1",5],["ACE_SOC_M4A1_Eotech",5],
					["ACE_M4A1_Eotech",5],["ACE_HK416_D10",5],["ACE_G3A3",5],["ACE_HK417_micro",5],["ACE_DAGR",5]
				],
				// sergeant rifles (gets added to corporal and private rifles)
				[
					["M4A3_CCO_EP1",5],["G36_C_SD_camo",5],["M79_EP1",5],["Sa58V_RCO_EP1",5],["Sa58V_CCO_EP1",5],["ACE_SOC_M4A1_AIM_SD",5],["ACE_SOC_M4A1_GL",5],["ACE_SOC_M4A1_GL_SD",5],
					["ACE_SOC_M4A1_GL_EOTECH",5],["ACE_SOC_M4A1_SD_9",5],["ACE_SOC_M4A1_GL_AIMPOINT",5],["ACE_M4A1_Aim_SD",5],["ACE_HK416_D10_SD",5],["ACE_HK416_D14",5],["ACE_G3SG1",5],["ACE_HK417_Shortdot",5]
				],
				// lieutenant rifles (gets added to...)
				[
					["FN_FAL_ANPVS4",5],["M4A3_RCO_GL_EP1",5],["SCAR_L_CQC",5],["SCAR_L_CQC_Holo",5],["M32_EP1",5],["ACE_M4A1_GL",5],["ACE_M4A1_GL_SD",5],["ACE_SOC_M4A1_GL_13",5],
					["ACE_SOC_M4A1_SHORTDOT",5],["ACE_SOC_M4A1_SHORTDOT_SD",5],["ACE_SOC_M4A1_RCO_GL",5],["ACE_M4A1_ACOG",5],["ACE_HK416_D10_COMPM3",5],["ACE_HK416_D10_COMPM3_SD",5],
					["ACE_HK416_D14_SD",5],["ACE_HK416_D14_COMPM3",5],["ACE_HK417_leupold",5]
				],
				// captain rifles (gets added...)
				[
					["SCAR_L_STD_Mk4CQT",5],["SCAR_L_STD_EGLM_RCO",5],["SCAR_L_CQC_EGLM_Holo",5],["SCAR_L_STD_HOLO",5],["SCAR_H_CQC_CCO",5],["ACE_M4A1_ACOG_SD",5],
					["ACE_HK416_D14_COMPM3_M320",5],["ACE_HK416_D10_M320",5]
				],
				// major rifles (gets...)
				[
					["SCAR_L_STD_EGLM_TWS",5],["SCAR_L_CQC_CCO_SD",5],["SCAR_H_CQC_CCO_SD",5],["SCAR_H_STD_EGLM_Spect",5],["Mk13_EP1",5]
				],
				// colonel rifles (...)
				[
				]
			],
			[
				// private sniper rifles
				[
				],
				// corporal sniper rifles
				[
				],
				// sergeant sniper rifles
				[
					["M24_des_EP1",5]
				],
				// lieutenant sniper rifles
				[
				],
				// captain sniper rifles
				[
					["ACE_M4SPR_SD",5]
				],
				// major sniper rifles
				[
					["SCAR_H_LNG_Sniper",5],["SCAR_H_LNG_Sniper_SD",5],["M107",5],["M110_NVG_EP1",5],["ACE_M110",5],["ACE_TAC50",5]
				],
				// colonel sniper rifles
				[
					["SCAR_H_STD_TWS_SD",5],["m107_TWS_EP1",5],["M110_TWS_EP1",5],["ACE_M109",5],["ACE_M110_SD",5],["ACE_TAC50_SD",5]
				]
			],
			[
				// private MG
				[
				],
				// corporal MG
				[
					["M60A4_EP1",5]
				],
				// sergeant MG
				[
					["Mk_48_DES_EP1",5]
				],
				// lieutenant MG
				[
					["m240_scoped_EP1",5],["M249_EP1",5]
				],
				// captain MG
				[
					["MG36_camo",5]
				],
				// major MG
				[
					["M249_TWS_EP1",5],["M249_m145_EP1",5]
				],
				// colonel MG
				[
				]
			],
			[
				// private launchers
				[
					["M136",5]
				],
				// corporal launchers
				[
					["STINGER",5]
				],
				// sergeant launchers
				[
					["M47Launcher_EP1",5]
				],
				// lieutenant launchers
				[
					["MAAWS",5]
				],
				// capain launchers
				[
				],
				// major launchers
				[
				],
				// colonel launchers
				[
					["JAVELIN",2],["ACE_Javelin_CLU",2]
				]
			],
			[
				// private pistols
				[
					["M9",5]
				],
				// corporal pistols
				[
					["M9SD",5],["revolver_EP1",5]
				],
				// sergeant pistols
				[
					["Colt1911",5],["revolver_gold_EP1",5],["ACE_Flaregun",5]
				],
				// lieutenant pistols
				[
					["glock17_EP1",5]
				],
				// captain pistols
				[
					["Sa61_EP1",5],["UZI_EP1",5],["UZI_SD_EP1",5]
				],
				// major pistols
				[
					["ACE_Glock18",5],["ACE_P226",5]
				],
				// colonel pistols
				[
				]
			]
		];
	_x_ranked_weapons_e = [
		[
			// private rifles
			[
				["AK_74",5],["AK_47_M",5],["AK_47_S",5],["AKS_74",5],["AKS_74_U",5]
			],
			// corporal rifles (gets added to private rifles)
			[
				["AK_74_GL",5]
			],
			// sergeant rifles (gets added to corporal and private rifles)
			[
				["AK_74_GL_kobra",5],["AKS_74_kobra",5]
			],
			// lieutenant rifles (gets added to...)
			[
				["AKS_74_NSPU",5],["AKS_74_GOSHAWK",5]
			],
			// captain rifles (gets added...)
			[
				["AKS_74_pso",5]
			],
			// major rifles (gets...)
			[
			],
			// colonel rifles (...)
			[
			]
		],
		[
			// private sniper rifles
			[
			],
			// corporal sniper rifles
			[
			],
			// sergeant sniper rifles
			[
			],
			// lieutenant sniper rifles
			[
			],
			// captain sniper rifles
			[
				["SVD",5],["SVD_des_EP1",5]
			],
			// major sniper rifles
			[
				["SVD_NSPU_EP1",5]
			],
			// colonel sniper rifles
			[
				["KSVK",5]
			]
		],
		[
			// private MG
			[
			],
			// corporal MG
			[
				["RPK_74",5]
			],
			// sergeant MG
			[
				["PK",5]
			],
			// lieutenant MG
			[
			],
			// captain MG
			[
			],
			// major MG
			[
			],
			// colonel MG
			[
			]
		],
		[
			// private launchers
			[
				["RPG7V",5]
			],
			// corporal launchers
			[
				["STRELA",5],["RPG18",5]
			],
			// sergeant launchers
			[
				["Igla",5]
			],
			// lieutenant launchers
			[
			],
			// capain launchers
			[
				["MetisLauncher",5]
			],
			// major launchers
			[
			],
			// colonel launchers
			[
				["JAVELIN",2]
			]
		],
		[
			// private pistols
			[
				["Makarov",5]
			],
			// corporal pistols
			[
				["MakarovSD",5]
			],
			// sergeant pistols
			[
			],
			// lieutenant pistols
			[
			],
			// captain pistols
			[
			],
			// major pistols
			[
			],
			// colonel pistols
			[
			]
		]
	];
	
	{GVAR(misc_store) setVariable [_x,[]]} forEach ["PRIVATE","CORPORAL","SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"];
	
	{
		for "_i" from 0 to (count _x) - 1 do {
			_typear = _x select _i;
			if (count _typear > 0) then {
				_rank = switch (_i) do {
					case 0: {
						{
							_ar = GV2(GVAR(misc_store),_x);
							{
								_ar set [count _ar, toUpper(_x select 0)];
							} forEach _typear;
						} forEach ["PRIVATE","CORPORAL","SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"];
					};
					case 1: {
						{
							_ar = GV2(GVAR(misc_store),_x);
							{_ar set [count _ar, toUpper(_x select 0)]} forEach _typear;
						} forEach ["CORPORAL","SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"];
					};
					case 2: {
						{
							_ar = GV2(GVAR(misc_store),_x);
							{_ar set [count _ar, toUpper(_x select 0)]} forEach _typear;
						} forEach ["SERGEANT","LIEUTENANT","CAPTAIN","MAJOR","COLONEL"];
					};
					case 3: {
						{
							_ar = GV2(GVAR(misc_store),_x);
							{_ar set [count _ar, toUpper(_x select 0)]} forEach _typear;
						} forEach ["LIEUTENANT","CAPTAIN","MAJOR","COLONEL"];
					};
					case 4: {
						{
							_ar = GV2(GVAR(misc_store),_x);
							{_ar set [count _ar, toUpper(_x select 0)]} forEach _typear;
						} forEach ["CAPTAIN","MAJOR","COLONEL"];
					};
					case 5: {
						{
							_ar = GV2(GVAR(misc_store),_x);
							{_ar set [count _ar, toUpper(_x select 0)]} forEach _typear;
						} forEach ["MAJOR","COLONEL"];
					};
					case 6: {
						_ar = GV(GVAR(misc_store),COLONEL);
						{_ar set [count _ar, toUpper(_x select 0)]} forEach _typear;
					};
				};
			};
		};
	} forEach (_x_ranked_weapons_w + _x_ranked_weapons_e);
	
	x_ranked_weapons = if (GVAR(player_side) == west) then {_x_ranked_weapons_w} else {_x_ranked_weapons_e};
	_x_ranked_weapons_w = nil;
	_x_ranked_weapons_e = nil;
	
	execFSM "fsms\LimitWeaponsRanked.fsm";
};

[_vec] spawn {
	private ["_vec", "_old_rank", "_index", "_weapons", "_i", "_rk"];
	PARAMS_1(_vec);
	_old_rank = "";
	while {!isNull _vec && alive _vec} do {
		if (_old_rank != rank player) then {
			clearMagazineCargo _vec;
			clearWeaponCargo _vec;
			_old_rank = rank player;
			_index = _old_rank call FUNC(GetRankIndex);
			if (GVAR(player_side) == west) then {
				{
					_weapons = _x;
					for "_i" from 0 to _index do {
						_rk = _weapons select _i;
						{_vec addweaponcargo _x} forEach _rk;
					};
				} forEach x_ranked_weapons;
				
				__awc(ACE_GlassesSunglasses,1)
				__awc(ACE_GlassesLHD_glasses,1)
				__awc(ACE_GlassesTactical,1)
				__awc(ACE_GlassesGasMask_US,1)
				__awc(ACE_GlassesBalaklava,1)
				__awc(ACE_Earplugs,1)
				__awc(ACE_Kestrel4500,1)
				__awc(ACE_Map_Tools,1)
				__awc(ACE_KeyCuffs,1)
				
				__awc(ACE_ParachutePack,50)
				__awc(Laserdesignator,1)
				__awc(Binocular,1)
				__awc(Binocular_Vector,1)
				__awc(ACE_Rangefinder_OD,1)
				if (GVAR(without_nvg) == 1) then {
					__awc(NVGoggles,1)
				};
				
				__amc(ace_flashbang,30)
				__amc(ace_m84,30)
				__amc(ace_m7a3,30)
				__amc(ace_m34,30)
				__amc(ACE_IRStrobe,30)
				__amc(ACE_M86PDM,30)
				__amc(ACE_M2SLAM_M,30)
				__amc(ACE_Battery_Rangefinder,30)
				__amc(HandGrenade_West,30)
				//__amc(HandGrenade_Stone,50)
				__amc(Smokeshell,20)
				__amc(Smokeshellred,20)
				__amc(Smokeshellgreen,20)
				__amc(SmokeShellYellow,20)
				__amc(SmokeShellOrange,20)
				__amc(SmokeShellPurple,50)
				__amc(SmokeShellBlue,50)
				__amc(30Rnd_9x19_MP5,30)
				__amc(30Rnd_9x19_MP5SD,30)
				__amc(ACE_25Rnd_1143x23_B_UMP45,50)
				__amc(7Rnd_45ACP_1911,30)
				__amc(ACE_33Rnd_9x19_G18,30)
				__amc(ACE_15Rnd_9x19_P226,30)
				__amc(6Rnd_45ACP,50)
				__amc(20Rnd_B_765x17_Ball,30)
				__amc(10Rnd_B_765x17_Ball,50)
				__amc(15Rnd_9x19_M9,30)
				__amc(15Rnd_9x19_M9SD,30)
				__amc(17Rnd_9x19_glock17,50)
				__amc(20Rnd_556x45_Stanag,30)
				__amc(30Rnd_556x45_Stanag,30)
				__amc(ACE_30Rnd_556x45_T_Stanag,30)
				__amc(ACE_30Rnd_556x45_SB_Stanag,30)
				__amc(30Rnd_556x45_StanagSD,30)
				__amc(30Rnd_762x39_SA58,50)
				__amc(20Rnd_762x51_FNFAL,30)
				__amc(10x_303,50)
				__amc(30Rnd_556x45_G36,30)
				__amc(30Rnd_556x45_G36SD,30)
				__amc(ACE_20Rnd_762x51_B_G3,30)
				__amc(200Rnd_556x45_M249,30)
				__amc(ACE_200Rnd_556x45_T_M249,30)
				__amc(100Rnd_556x45_M249,30)
				__amc(100Rnd_556x45_BetaCMag,30)
				//__amc(8Rnd_B_Beneli_74Slug,50)
				__amc(5Rnd_762x51_M24,6)
				__amc(ACE_5Rnd_762x51_T_M24,6)
				__amc(20Rnd_762x51_DMR,50)
				__amc(10Rnd_127x99_M107,3)
				__amc(ACE_10Rnd_127x99_Raufoss_m107,3)
				__amc(ACE_5Rnd_25x59_HEDP_Barrett,3)
				__amc(ACE_20Rnd_762x51_SB_M110,10)
				__amc(ACE_20Rnd_762x51_S_M110,10)
				__amc(ACE_20Rnd_762x51_T_M110,10)
				__amc(ACE_5Rnd_127x99_B_TAC50,3)
				__amc(ACE_5Rnd_127x99_S_TAC50,3)
				__amc(ACE_5Rnd_127x99_T_TAC50,3)
				__amc(20Rnd_762x51_B_SCAR,30)
				__amc(20rnd_762x51_SB_SCAR,30)
				__amc(100Rnd_762x51_M240,30)
				__amc(ACE_6Rnd_CS_M32,30)
				__amc(FlareWhite_M203,20)
				__amc(FlareGreen_M203,20)
				__amc(FlareRed_M203,20)
				__amc(FlareYellow_M203,20)
				__amc(1Rnd_HE_M203,30)
				__amc(6Rnd_FlareWhite_M203,20)
				__amc(6Rnd_FlareGreen_M203,20)
				__amc(6Rnd_FlareRed_M203,20)
				__amc(6Rnd_FlareYellow_M203,20)
				__amc(6Rnd_HE_M203,30)
				__amc(6Rnd_Smoke_M203,20)
				__amc(6Rnd_SmokeRed_M203,20)
				__amc(6Rnd_SmokeGreen_M203,20)
				__amc(6Rnd_SmokeYellow_M203,20)
				__amc(1Rnd_Smoke_M203,20)
				__amc(1Rnd_SmokeRed_M203,20)
				__amc(1Rnd_SmokeGreen_M203,20)
				__amc(1Rnd_SmokeYellow_M203,20)
				__amc(ACE_SSWhite_FG,20)
				__amc(ACE_SSRed_FG,20)
				__amc(ACE_SSGreen_FG,20)
				__amc(ACE_SSYellow_FG,20)
				__amc(ACE_SSWhite_M203,20)
				__amc(ACE_SSGreen_M203,20)
				__amc(ACE_SSRed_M203,20)
				__amc(ACE_SSYellow_M203,20)
				__amc(M136,10)
				__amc(Dragon_EP1,10)
				__amc(MAAWS_HEAT,2)
				__amc(MAAWS_HEDP,2)
				__amc(Pipebomb,5)
				__amc(Mine,10)
				__amc(Laserbatteries,20)
				//__amc(JAVELIN,1)
				__amc(STINGER,2)
				//__amc(30Rnd_545x39_AK,50)
				//__amc(PG7V,3)
				//__amc(PG7VR,3)
				//__amc(PG7VL,3)
				//__amc(100Rnd_762x54_PK,50)
				//__amc(60Rnd_762x54_DT,50)
				//__amc(75Rnd_545x39_RPK,50)
				__amc(ACE_Claymore_M,5)
				__amc(ACE_C4_M,5)
				__amc(ACE_BBetty_M,5)
				__amc(ACE_TripFlare_M,5)
				__amc(IR_Strobe_Target,3)
				__amc(IR_Strobe_Marker,3)
				__amc(IRStrobe,3)
				
				__amc(30Rnd_9x19_UZI,30)
				__amc(30Rnd_9x19_UZI_SD,30)
				
				//__amc(30Rnd_762x39_AK47,50)
				//__amc(10Rnd_762x54_SVD,50)
				
				__amc(ACE_Knicklicht_R,50)
				__amc(ACE_Knicklicht_W,50)
				__amc(ACE_Knicklicht_Y,50)
				__amc(ACE_Knicklicht_B,50)
				__amc(ACE_Knicklicht_IR,50)
				__amc(ACE_VS17Panel_M,50)
				__amc(ACE_Rope_M_50,2)
				__amc(ACE_Rope_M_60,2)
				__amc(ACE_Rope_M_90,2)
				__amc(ACE_Rope_M_120,2)
				if (__WoundsVer) then {
					__amc(ACE_Bandage,50)
					__amc(ACE_LargeBandage,50)
					__amc(ACE_Morphine,50)
					__amc(ACE_Epinephrine,50)
					__amc(ACE_Medkit,50)
				};
			} else {
				{
					_weapons = _x;
					for "_i" from 0 to _index do {
						_rk = _weapons select _i;
						{_vec addweaponcargo _x} forEach _rk;
					};
				} forEach x_ranked_weapons;

				__awc(Laserdesignator,1)
				__awc(Binocular,1)
				__awc(Binocular_Vector,1)
				if (GVAR(without_nvg) == 1) then {
					__awc(NVGoggles,1)
				};
				
				__amc(30Rnd_545x39_AK,30)
				__amc(30Rnd_762x39_AK47,30)
				__amc(64Rnd_9x19_Bizon,30)
				__amc(64Rnd_9x19_SD_Bizon,30)
				__amc(8Rnd_B_Saiga12_74Slug,30)
				__amc(10Rnd_9x39_SP5_VSS,30)
				__amc(20Rnd_9x39_SP5_VSS,30)
				__amc(75Rnd_545x39_RPK,30)
				__amc(60Rnd_762x54_DT,50)
				__amc(30Rnd_9x19_UZI,50)
				__amc(30Rnd_9x19_UZI_SD,50)
				__amc(FlareWhite_GP25,20)
				__amc(FlareGreen_GP25,20)
				__amc(FlareRed_GP25,20)
				__amc(FlareYellow_GP25,20)
				__amc(1Rnd_HE_GP25,30)
				__amc(1Rnd_SMOKE_GP25,20)
				__amc(1Rnd_SmokeRed_GP25,20)
				__amc(1Rnd_SmokeGreen_GP25,20)
				__amc(1Rnd_SmokeYellow_GP25,20)
				__amc(30Rnd_545x39_AKSD,30)
				__amc(100Rnd_762x54_PK,30)
				__amc(10Rnd_762x54_SVD,6)
				__amc(8Rnd_9x18_Makarov,30)
				__amc(8Rnd_9x18_MakarovSD,30)
				__amc(PG7V,3)
				__amc(PG7VR,3)
				__amc(PG7VL,3)
				__amc(PG9_AT,3)
				__amc(OG7,3)
				__amc(OG9_HE,3)
				__amc(AT13,3)
				__amc(RPG18,3)
				__amc(Igla,5)
				__amc(SmokeShellRed,20)
				__amc(SmokeShellGreen,20)
				__amc(SmokeShellYellow,20)
				__amc(SmokeShellPurple,50)
				__amc(SmokeShellBlue,50)
				__amc(SmokeShellOrange,20)
				__amc(SmokeShell,20)
				__amc(HandGrenade_East,30)
				__amc(5Rnd_127x108_KSVK,3)
				__amc(Mine,10)
				__amc(Pipebomb,5)
				__amc(Laserbatteries,10)
				__amc(Strela,2)
				__amc(IR_Strobe_Target,3)
				__amc(IR_Strobe_Marker,3)
				__amc(IRStrobe,3)
			};
		};
		sleep 2.32;
	};
};
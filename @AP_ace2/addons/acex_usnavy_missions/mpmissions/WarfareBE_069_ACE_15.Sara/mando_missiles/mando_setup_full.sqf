if (!isNil "mando_missile_setup_full") exitWith {};
mando_missile_setup_full = true;
waitUntil {!isNil "mando_missile_init_done"};
waitUntil {mando_missile_init_done};
Sleep 1;

// F35B added to the array of stealth planes
mando_missile_stealth = ["ADF_F35A","F35B","F35_MK20","F35_CBU87","3lb_f22","3lb_f22_jdam","3lb_f22_sdb"];

[] spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   []execVM mando_missile_path+"setups\mando_GLT_falcon_setup.sqf";
   []execVM mando_missile_path+"setups\mando_Su34_setup.sqf";
   []execVM mando_missile_path+"setups\mando_a10_setup.sqf";
   []execVM mando_missile_path+"setups\mando_f35b_setup.sqf";
   []execVM mando_missile_path+"setups\mando_f22_setup.sqf";   
   []execVM mando_missile_path+"setups\mando_av8b_setup.sqf";
   []execVM mando_missile_path+"setups\mando_c130j_setup.sqf";
   []execVM mando_missile_path+"setups\mando_mi24_p_setup.sqf";
   []execVM mando_missile_path+"setups\mando_mi24_v_setup.sqf";
   []execVM mando_missile_path+"setups\mando_mi24_d_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ka52_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ah1z_setup.sqf";
   []execVM mando_missile_path+"setups\mando_su25_setup.sqf";
   []execVM mando_missile_path+"setups\mando_gntb52_setup.sqf";
   []execVM mando_missile_path+"setups\mando_pmc_ah64_setup.sqf";
   []execVM mando_missile_path+"setups\mando_cma_mi28_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ah64_setup.sqf";
   []execVM mando_missile_path+"setups\mando_eble_f4_setup.sqf";
   []execVM mando_missile_path+"setups\mando_eble_f14_setup.sqf";
   []execVM mando_missile_path+"setups\mando_eble_f15_setup.sqf";
   []execVM mando_missile_path+"setups\mando_GNT_Su33_setup.sqf";
   []execVM mando_missile_path+"setups\mando_hexa_mirage_setup.sqf";
   []execVM mando_missile_path+"setups\mando_hexa_tigre_setup.sqf";
   []execVM mando_missile_path+"setups\mando_iran_ah1j_setup.sqf";
   []execVM mando_missile_path+"setups\mando_kiowa_setup.sqf";
   []execVM mando_missile_path+"setups\mando_sti_uh60_setup.sqf";
   []execVM mando_missile_path+"setups\mando_rah66_setup.sqf";
   []execVM mando_missile_path+"setups\mando_lobo_irak_setup.sqf";
   []execVM mando_missile_path+"setups\mando_anzac_f111_setup.sqf";
   []execVM mando_missile_path+"setups\mando_anzac_tigre_setup.sqf";
   []execVM mando_missile_path+"setups\mando_bas_lynx_setup.sqf";
   []execVM mando_missile_path+"setups\mando_bgs_setup.sqf";
   []execVM mando_missile_path+"setups\mando_mig15_setup.sqf";
   []execVM mando_missile_path+"setups\mando_RKSL_typhoon_setup.sqf";
   []execVM mando_missile_path+"setups\mando_sfp_jas39_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ped_mod_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ibr_setup.sqf";
   []execVM mando_missile_path+"setups\mando_GNT_Tu22_setup.sqf";
   []execVM mando_missile_path+"setups\mando_csla_mig29_setup.sqf";

   // HUDs sfp_hkp15 for pilots and gunners
   [["sfp_hkp15_rbs55","sfp_hkp15"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_stp_hkp15.sqf", 0, 0, [[-1,"sfp_rbs55_veh_launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["sfp_hkp15_rbs55","sfp_hkp15"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_stp_hkp15.sqf", 0, 0, [[-1,"sfp_rbs55_veh_launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


   // HEXA Choppers and transports HUD setup (only flares and ECM)
   [["HEXA_Transall_A", "HEXA_Puma_CE","HEXA_Puma_RESCO","HEXA_Puma_CE_Pirate","BW_Transall_A"], 0, "", [], [], 20, 20, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_hexa_transports.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // GNT Coaler HUD setup and Iran C130 (only flares and ECM)
   [["sfp_tp84","DDL_C27J_AM","ASZ_C130J_AM","Antonov225", "Antonov225_2", "Antonov225_3","il76moe", "il76", "il76loaded","nzdf_c130", "adf_c130_1", "adf_c130","RKTCoalerS","RKTCoalerD","RKTCoalerI","RKTCoalerR","iran_c130","USMC_c130_1","ANG_c130", "USN_c130", "USMC_c130","USCG_c130","usaf_c130","ANG_c130_1"], 0, "", [], [], 20, 20, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_c130j.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["AFMC_AH6","AFMC_MH6","AAW_s70","AAW_s70bh_mg", "sfp_sk60_cas","ASZ_AH6_EI_ffar","ASZ_AH6_EI_reos","OWP_MI26cg", "OWP_MI26ps", "OWP_MI26hk", "OWP_MI26md", "OWP_MI26fl","Ka60_GL_PMC","L39_TK_EP1","CSLA_L39","AH6J_EP1","MH6J_EP1","AH6X_EP1","CYBP_AH6_US","CYBP_AH6_RACS","CYBP_AH6_NAPA",
"CYBP_AH6_CHDKZ","CYBP_MH6_US","CYBP_MH6_RACS","CYBP_MH6_NAPA","CYBP_MH6_CHDKZ","ACE_AH6J_DAGR_FLIR"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_locations.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["sfp_hkp14","sfp_hkp14b","ASZ_AB212_AM","ASZ_AB212_MM","ASZ_AB212_MM_ffar","ASZ_AB412_EI","ASZ_AB412_EI_reos","ASZ_AB412_EI_ffar","ASZ_NH90_EI","ASZ_NH90_EI_reos","ASZ_NH90_MM","ASZ_NH90_EI_support","ASZ_NH90_MM_support","adf_NH90_casevac", "adf_NH90_mg", "adf_NH90", "nzdf_NH90_casevac", "nzdf_nh90_mg", "nzdf_nh90", "MAF_NH90_2", "MAF_NH90", "adf_s70csar", "adf_s70mg", "adf_ch47f", "adf_uh1h_1", "adf_uh1h", "nzdf_uh1h_2", "nzdf_uh1h_1", "nzdf_uh1h", "MV22", "UH1Y","Mi17_rockets_RU", "Mi17_Ins", "Mi17_CDF", "Mi17_Civilian","Mi17_medevac_CDF","modem_NH90","Mi17_Iraq","Mi171_IRAN","Mi17_IRAN","Mi17transp_Iraq","IRAN_AB206","iran_ab212","iran_uh1n","BWMod_UH1D_SAR","BWMod_UH1D","UH60M_EP1","Mi171Sh_CZ_EP1","Mi171Sh_rockets_CZ_EP1","Mi17_TK_EP1","Mi17_UN_CDF_EP1","ad_hh60g","ad_mh60k","ad_mh60k_black","ad_mh60k_erfs","ad_mh60k_erfs_black","Mi8MT_OTA_SAR","Mi8MT_SA_SAR","TPS_PL_Mi8","TPS_PL_Mi8_med_1","TPS_PL_MI8_med","p85_PL_Mi8","p85_PL_Mi2"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lift.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // UH1Y laser TV camera setup
   _background_mfd = [];
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_onlylaser.sqs";
   [["UH1Y"], 0, 0, ["Vehicles", "REMOTE"], "MMA Laser Camera", _mcctypeaascript, [-3,2,-2], [0,0,-1.5,0,181], 0, 0, -6, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // AH6X_EP1 laser TV camera setup
   _background_mfd = [];
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_onlylaser.sqs";
   [["AH6X_EP1"], 0, 0, ["Vehicles", "REMOTE"], "MMA Laser Camera", _mcctypeaascript, [-3,2,-2], [0,2.7,-1.5,0,120], 0, 0, -6, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // Iranian ship units will be simulated SAM launchers for players as gunners (missile idx 0)
   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_hawk.sqs";
   [["IRAN_LST"], 8, 8, ["Air"], "SAM Console", _mcctypeaascript, [0,50,9,2], [0,1,20], 0, -1, 0, [], 3, 75]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // CH53 Choppers HUD setup (only flares)
   [["adf_as350", "AAW_CH47","adf_ch47f", "CH_47F_EP1","RAF_Chin47", "CH_47F_BAF", "BAF_Merlin_HC3_D","ou_ch_53d","ou_ch_46e","BW_ch_53d"], 0, "", [], [], 20, 20, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ch47.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


   // BIS MH60S and Iranian iran_ab212asw torpedo armed chopper
   [["adf_s70b2mg", "MH60S","iran_ab212asw"], 0, "", [3,2], [3,2], 10, 10, 0, [3,3,-2.5], mando_missile_path+"huds\mando_hud_sono.sqf", 0, 0.0, [[0,""],[1,""]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


   // Fouga Magister
   [["FougaMagister3"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_fmagister.sqf", -0.02, 0, [[-9,"NordAS11"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["FougaMagister","FougaMagister2","FougaMagister4"], 0, "", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_fmagister.sqf", -0.02, 0, [[-9,"R73Launcher_2"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


   // Avenger HUD, 8 AA missiles of a maximum of 8 ([8, 0], [8, 0])
   [["HMMWV_Avenger","HMMWV_Avenger_DES_EP1"], 1, "StingerLaucher", [8,0], [8,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_avenger.sqf", 0, 0, [[-1,"StingerLaucher"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // M6_EP1 HUD, 4 AA missiles of a maximum of 4 ([4, 0], [4, 0])
   [["M6_EP1"], 1, "StingerLaucher_4x", [4,0], [4,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_avenger.sqf", 0, 0, [[-1,"StingerLaucher_4x"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // 3LB_SA6 HUD, 2 AA missiles of a maximum of 3 ([3, 0], [3, 0])
   [["3LB_SA6"], 1, "3LB_2K21Launcher", [3,0], [3,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_3LB_SA6.sqf", 0, 0, [[-1,"3LB_2K21Launcher"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // Tunguska HUD, 8 AA missiles of a maximum of 8 ([8, 0], [8, 0])
   [["2S6M_Tunguska"], 1, "9M311Laucher", [8,0], [8,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_tunguska.sqf", 0, 0, [[-6,"9M311Laucher"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


   if (mma_mlrs_mode == 0) then
   {
      // MLRS HUD GROUND
      [["MLRS"], 1, "MLRS", [8,0], [8,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_mlrs.sqf", 0, 0, [[-1,"MLRS"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
   };

   if (mma_mlrs_mode == 1) then
   {
      // MLRS HUD AA
      [["MLRS"], 1, "MLRS", [8,0], [8,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_mlrs_air.sqf", 0, 0, [[-1,"MLRS"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
   };

   // Checks if you have a laser designator to provide corresponding actions
   []execVm"mando_missiles\units\mando_haveialaser.sqf";

   [[""], 0, "Javelin", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_javelin.sqf", 0, 0, [[-1,"Javelin"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";
   [[""], 0, "ACE_Javelin_Direct", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_ACE_javelin.sqf", 0, 0, [[-1,"ACE_Javelin_Direct"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "Stinger", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_stinger.sqf", 0, 0, [[-1,"Stinger"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "StingerLauncher_twice", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_stinger.sqf", 0, 0, [[-1,"StingerLauncher_twice"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";


   [[""], 0, "Igla", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_igla.sqf", 0, 0, [[-1,"Igla"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";
   [[""], 0, "Igla_twice", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_igla.sqf", 0, 0, [[-1,"Igla_twice"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";


   [[""], 0, "Strela", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_strela.sqf", 0, 0, [[-1,"Strela"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "MetisLauncher", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_metis.sqf", 0, 0, [[-1,"MetisLauncher"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "AT13LauncherSingle", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_metis.sqf", 0, 0, [[-1,"AT13LauncherSingle"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";


   [[""], 0, "TOWLauncherSingle", [1], [1], 0, 0, 0, [0,0,2,3], mando_missile_path+"huds\mando_hud_hmmwv_tow.sqf", 0, 0, [[-1,"TOWLauncherSingle"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "TOWLauncher", [1], [1], 0, 0, 0, [0,0,2,3], mando_missile_path+"huds\mando_hud_hmmwv_tow.sqf", 0, 0, [[-1,"TOWLauncher"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "AT5LauncherSingle", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_at5.sqf", 0, 0, [[-1,"AT5LauncherSingle"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   [[""], 0, "AT5Launcher", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_at5.sqf", 0, 0, [[-1,"AT5Launcher"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

[[""], 0, "2A46MRocket", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_refleks.sqf", 0, 0, [[-1,"2A46MRocket"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

[[""], 0, "2A70Rocket", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_arkan.sqf", 0, 0, [[-1,"2A70Rocket"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";


[[""], 0, "M47Launcher_EP1", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_dragon.sqf", 0, 0, [[-1,"M47Launcher_EP1"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

[[""], 0, "BAF_NLAW_Launcher", [1], [1], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_nlaw.sqf", 0, 0, [[-1,"BAF_NLAW_Launcher"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_oa_scud.sqs";
   [["MAZ_543_SCUD_TK_EP1"], 0, 0, [""], "MMA SCUD Console", _mcctypeaascript, [3,2,-3], [0,7.5,-3.8], {(driver _plane == player)}, 0, "", [], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   [30]execVM"mando_missiles\units\mando_rearm_by_type.sqf";


};


if (isServer) then
{
   [] spawn
   {
      // Auto countermeasures for all the planes/choppers, not for manned ones
      [[], 1200, 1, 5, true, 3]execVM"mando_missiles\units\mando_missileecm_by_type.sqf";

      // All arma missiles replaced for all vehicle types
      [[]]execVM "mando_missiles\units\mando_onlymandoones_by_type.sqf";
   };
};

// BI OA Flares out
if (isClass (configFile >> "CfgVehicles" >> "A10_US_EP1")) then
{
   []execVM mando_missile_path+"mando_no_bi_flares.sqf";
};
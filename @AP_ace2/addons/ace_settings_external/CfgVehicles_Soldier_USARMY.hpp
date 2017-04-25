	class US_Soldier_Base_EP1: SoldierWB {};
	class US_Soldier_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_B_EP1: US_Soldier_EP1 {
		// backpack = "";
	};
	class US_Soldier_AMG_EP1: US_Soldier_EP1 {
		// backpack = "";
	};
	class US_Soldier_AAR_EP1: US_Soldier_EP1 {
		// backpack = "";
	};
	class US_Soldier_AHAT_EP1: US_Soldier_EP1 {
		// backpack = "";
	};
	class US_Soldier_AAT_EP1: US_Soldier_EP1 {
		// backpack = "";
	};
	class US_Soldier_Light_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_GL_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_Officer_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_SL_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_TL_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_AT_Base_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_LAT_EP1: US_Soldier_AT_Base_EP1 {};
	class US_Soldier_AT_EP1: US_Soldier_AT_Base_EP1 {};
	class US_Soldier_HAT_EP1: US_Soldier_AT_Base_EP1 {};
	class US_Soldier_AA_EP1: US_Soldier_AT_Base_EP1 {};
	class US_Soldier_Medic_EP1: US_Soldier_Base_EP1 {
		// Model replace due to FIXED rucksack on model
		model = "\ca\characters_E\US\US_at_gunner";
	};
	class US_Soldier_AR_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_MG_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_Spotter_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_Sniper_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_Sniper_NV_EP1: US_Soldier_Sniper_EP1 {};
	class US_Soldier_SniperH_EP1: US_Soldier_Sniper_EP1 {};
	class US_Soldier_Marksman_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_Engineer_EP1: US_Soldier_Base_EP1 {
		// backpack = "";
	};
	class US_Soldier_Pilot_EP1: US_Soldier_Base_EP1 {};
	class US_Soldier_Crew_EP1: US_Soldier_Base_EP1 {};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1 {
		// backpack = "";
	};
	class US_Delta_Force_TL_EP1: US_Soldier_Base_EP1 {
		// backpack = "";
	};
	class US_Delta_Force_Medic_EP1: US_Delta_Force_EP1 {
		// Model replace due to FIXED rucksack on model
		model = "\ca\characters_e\Delta\Delta1.p3d";
	};
	class US_Delta_Force_Assault_EP1: US_Delta_Force_EP1 {
		// backpack = "";
	};
	class US_Delta_Force_SD_EP1: US_Delta_Force_EP1 {};
	class US_Delta_Force_MG_EP1: US_Delta_Force_EP1 {};
	class US_Delta_Force_AR_EP1: US_Delta_Force_EP1 {};
	class US_Delta_Force_Night_EP1: US_Delta_Force_EP1 {
		// backpack = "";
	};
	class US_Delta_Force_Marksman_EP1: US_Delta_Force_EP1 {
		// backpack = "";
	};
	class US_Delta_Force_M14_EP1: US_Delta_Force_EP1 {};
	class US_Delta_Force_Air_Controller_EP1: US_Delta_Force_EP1 {};
	class US_Pilot_Light_EP1: US_Soldier_Base_EP1 {};
	class Drake: US_Soldier_Base_EP1 {};
	class Herrera: US_Soldier_Crew_EP1 {};
	class Pierce: US_Soldier_Pilot_EP1 {};
	class Graves: US_Delta_Force_EP1 {};
	class Drake_Light: Drake {};
	class Herrera_Light: Herrera {};
	class Pierce_Light: Pierce {};
	class Graves_Light: Graves {};

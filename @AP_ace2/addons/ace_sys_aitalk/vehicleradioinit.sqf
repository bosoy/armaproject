#include "script_component.hpp"

GVAR(us_vec_radio) = [
	[
		"ACE_us_mrn_01","ACE_us_mrn_02","ACE_us_mrn_03","ACE_us_mrn_04","ACE_us_mrn_05","ACE_us_mrn_06","ACE_us_mrn_07","ACE_us_mrn_08","ACE_us_mrn_09","ACE_us_mrn_10","ACE_us_mrn_11","ACE_us_mrn_12","ACE_us_mrn_13","ACE_us_mrn_14",
		"ACE_us_air_land_rc_01","ACE_us_air_land_rc_02","ACE_us_air_land_rc_03","ACE_us_air_land_rc_04","ACE_us_air_land_rc_05","ACE_us_air_land_rc_06","ACE_us_air_land_rc_07","ACE_us_air_land_rc_08","ACE_us_air_land_rc_09","ACE_us_air_land_rc_10",
		"ACE_us_air_land_rc_11","ACE_us_air_land_rc_12","ACE_us_air_land_rc_13","ACE_us_air_land_rc_14","ACE_us_air_land_rc_15","ACE_us_air_land_rc_16","ACE_us_air_land_rc_17","ACE_us_air_land_rc_18","ACE_us_air_land_rc_19","ACE_us_air_land_rc_20",
		"ACE_us_air_land_rc_21","ACE_us_air_land_rc_22","ACE_us_air_land_rc_23","ACE_us_air_land_rc_24","ACE_us_air_land_rc_25","ACE_us_air_land_rc_26","ACE_us_air_land_rc_27","ACE_us_air_land_rc_28","ACE_us_air_land_rc_29","ACE_us_air_land_rc_30",
		"ACE_us_air_land_rc_31","ACE_us_air_land_rc_32","ACE_us_air_land_rc_33","ACE_us_air_land_rc_34","ACE_us_air_land_rc_35","ACE_us_air_land_rc_36","ACE_us_air_land_rc_37","ACE_us_air_land_rc_38","ACE_us_air_land_rc_39","ACE_us_air_land_rc_40",
		"ACE_us_air_land_rc_41","ACE_us_air_land_rc_42","ACE_us_air_land_rc_43","ACE_us_air_land_rc_44",
		"ACE_gb_attk_01","ACE_gb_attk_02","ACE_gb_attk_03","ACE_gb_attk_04","ACE_gb_attk_05","ACE_gb_attk_06","ACE_gb_attk_07","ACE_gb_attk_08","ACE_gb_attk_09","ACE_gb_attk_10","ACE_gb_attk_11","ACE_gb_attk_12","ACE_gb_attk_13","ACE_gb_attk_14",
		"ACE_gb_attk_15","ACE_gb_attk_16","ACE_gb_attk_17","ACE_gb_attk_18","ACE_gb_attk_19","ACE_gb_attk_20","ACE_gb_attk_21","ACE_gb_attk_22","ACE_gb_attk_23","ACE_gb_attk_24","ACE_gb_attk_25","ACE_gb_attk_26","ACE_gb_attk_27","ACE_gb_attk_28"
	],
	[
		"ACE_us_air_gen_01","ACE_us_air_gen_02","ACE_us_air_gen_03","ACE_us_air_gen_04","ACE_us_air_gen_05","ACE_us_air_gen_06","ACE_us_air_gen_07","ACE_us_air_gen_08","ACE_us_air_gen_09","ACE_us_air_gen_10",
		"ACE_us_air_gen_11","ACE_us_air_gen_12","ACE_us_air_gen_13","ACE_us_air_gen_14","ACE_us_air_gen_15","ACE_us_air_gen_16","ACE_us_air_gen_17","ACE_us_air_gen_18","ACE_us_air_gen_19","ACE_us_air_gen_20",
		"ACE_us_air_gen_21","ACE_us_air_gen_22","ACE_us_air_gen_23","ACE_us_air_gen_24","ACE_us_air_gen_25","ACE_us_air_gen_26","ACE_us_air_gen_27","ACE_us_air_gen_28","ACE_us_air_gen_29","ACE_us_air_gen_30",
		"ACE_us_air_gen_31","ACE_us_air_gen_32","ACE_us_air_gen_33","ACE_us_air_gen_34","ACE_us_air_gen_35","ACE_us_air_gen_36","ACE_us_air_gen_37","ACE_us_air_gen_38","ACE_us_air_gen_39","ACE_us_air_gen_40",
		"ACE_us_air_gen_41","ACE_us_air_gen_42","ACE_us_air_gen_43","ACE_us_air_gen_44","ACE_us_air_gen_45","ACE_us_air_gen_46","ACE_us_air_gen_47","ACE_us_air_gen_48","ACE_us_air_gen_49","ACE_us_air_gen_50",
		"ACE_us_air_gen_51","ACE_us_air_gen_52","ACE_us_air_gen_53","ACE_us_air_gen_54","ACE_us_air_gen_55",
		"ACE_us_air_land_rc_01","ACE_us_air_land_rc_02","ACE_us_air_land_rc_03","ACE_us_air_land_rc_04","ACE_us_air_land_rc_05","ACE_us_air_land_rc_06","ACE_us_air_land_rc_07","ACE_us_air_land_rc_08","ACE_us_air_land_rc_09","ACE_us_air_land_rc_10",
		"ACE_us_air_land_rc_11","ACE_us_air_land_rc_12","ACE_us_air_land_rc_13","ACE_us_air_land_rc_14","ACE_us_air_land_rc_15","ACE_us_air_land_rc_16","ACE_us_air_land_rc_17","ACE_us_air_land_rc_18","ACE_us_air_land_rc_19","ACE_us_air_land_rc_20",
		"ACE_us_air_land_rc_21","ACE_us_air_land_rc_22","ACE_us_air_land_rc_23","ACE_us_air_land_rc_24","ACE_us_air_land_rc_25","ACE_us_air_land_rc_26","ACE_us_air_land_rc_27","ACE_us_air_land_rc_28","ACE_us_air_land_rc_29","ACE_us_air_land_rc_30",
		"ACE_us_air_land_rc_31","ACE_us_air_land_rc_32","ACE_us_air_land_rc_33","ACE_us_air_land_rc_34","ACE_us_air_land_rc_35","ACE_us_air_land_rc_36","ACE_us_air_land_rc_37","ACE_us_air_land_rc_38","ACE_us_air_land_rc_39","ACE_us_air_land_rc_40",
		"ACE_us_air_land_rc_41","ACE_us_air_land_rc_42","ACE_us_air_land_rc_43","ACE_us_air_land_rc_44"
	]
];

GVAR(rus_vec_radio) = [
	[
		"ACE_rus_land_rc_01","ACE_rus_land_rc_02","ACE_rus_land_rc_03","ACE_rus_land_rc_04","ACE_rus_land_rc_05","ACE_rus_land_rc_06","ACE_rus_land_rc_07","ACE_rus_land_rc_08","ACE_rus_land_rc_09","ACE_rus_land_rc_10","ACE_rus_land_rc_11","ACE_rus_land_rc_12","ACE_rus_land_rc_13",
		"ACE_rus_land_rc_14","ACE_rus_land_rc_15","ACE_rus_land_rc_16","ACE_rus_land_rc_17","ACE_rus_land_rc_18","ACE_rus_land_rc_19","ACE_rus_land_rc_20","ACE_rus_land_rc_21","ACE_rus_land_rc_22","ACE_rus_land_rc_23","ACE_rus_land_rc_24","ACE_rus_land_rc_25","ACE_rus_land_rc_26","ACE_rus_land_rc_27",
		"ACE_rus_land_rc_28","ACE_rus_land_rc_29","ACE_rus_land_rc_30","ACE_rus_land_rc_31","ACE_rus_land_rc_32","ACE_rus_land_rc_33","ACE_rus_land_rc_34","ACE_rus_land_rc_35","ACE_rus_land_rc_36","ACE_rus_land_rc_37","ACE_rus_land_rc_38"
	]
];

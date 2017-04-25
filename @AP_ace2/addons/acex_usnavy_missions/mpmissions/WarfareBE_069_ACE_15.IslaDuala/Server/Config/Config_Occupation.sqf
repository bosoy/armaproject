
private ["_n","_u"];
if (WF_A2_Vanilla) then {
	//--- West.
	_n		= ["SmallTeam1"];
	_u		= ["USMC_Soldier_SL"];
	_u = _u + ["USMC_Soldier_TL"];
	_u = _u + ["USMC_Soldier_AR"];
	_u = _u + ["USMC_Soldier"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam2"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["USMC_Soldier_AR"];
	_u = _u + ["USMC_Soldier_LAT"];
	_u = _u + ["USMC_Soldier_Medic"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam3"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["USMC_Soldier_MG"];
	_u = _u + ["USMC_Soldier_AR"];
	_u = _u + ["USMC_Soldier_LAT"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam1"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["HMMWV_Avenger"];
	_u = _u + ["HMMWV_Armored"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam2"];
	_u		= ["USMC_Soldier_SL"];
	_u = _u + ["HMMWV_TOW"];
	_u = _u + ["LAV25"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam3"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["HMMWV_Avenger"];
	_u = _u + ["HMMWV_MK19"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam1"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["USMC_Soldier_AR"];
	_u = _u + ["USMC_Soldier_Medic"];
	_u = _u + ["USMC_Soldier_AA"];
	_u = _u + ["USMC_Soldier_AA"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam2"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["USMC_Soldier_AA"];
	_u = _u + ["USMC_Soldier_AA"];
	_u = _u + ["USMC_Soldier_LAT"];
	_u = _u + ["USMC_Soldier_AT"];
	_u = _u + ["USMC_Soldier_AR"];
	_u = _u + ["USMC_Soldier_MG"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam3"];
	_u		= ["USMC_SoldierS_Sniper"];
	_u = _u + ["USMC_SoldierS_Spotter"];
	_u = _u + ["USMC_SoldierS_Spotter"];
	_u = _u + ["USMC_SoldierS"];
	_u = _u + ["USMC_SoldierS"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam1"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["HMMWV_Avenger"];
	_u = _u + ["AAV"];
	_u = _u + ["LAV25"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam2"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["M1A1"];
	_u = _u + ["M1A1"];
	_u = _u + ["HMMWV_Ambulance"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam3"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["AAV"];
	_u = _u + ["HMMWV_M2"];
	_u = _u + ["M1A1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam1"];
	_u		= ["USMC_Soldier_HAT"];
	_u = _u + ["USMC_Soldier_AT"];
	_u = _u + ["USMC_Soldier_HAT"];
	_u = _u + ["USMC_Soldier_HAT"];
	_u = _u + ["USMC_Soldier_HAT"];
	_u = _u + ["USMC_Soldier"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam2"];
	_u		= ["FR_TL"];
	_u = _u + ["FR_AR"];
	_u = _u + ["FR_GL"];
	_u = _u + ["FR_Marksman"];
	_u = _u + ["FR_R"];
	_u = _u + ["FR_Corpsman"];
	_u = _u + ["FR_Sapper"];
	_u = _u + ["FR_AC"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam3"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["USMC_Soldier_AA"];
	_u = _u + ["USMC_Soldier_AA"];
	_u = _u + ["USMC_Soldier_Medic"];
	_u = _u + ["USMC_Soldier_GL"];
	_u = _u + ["USMC_SoldierS_Sniper"];
	_u = _u + ["USMC_Soldier_AT"];
	_u = _u + ["USMC_Soldier_MG"];
	_u = _u + ["USMC_Soldier_AR"];
	_u = _u + ["USMC_Soldier_LAT"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam1"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["M1A2_TUSK_MG"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam2"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["MLRS"];
	_u = _u + ["M1A2_TUSK_MG"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam3"];
	_u		= ["USMC_Soldier_TL"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["M1A2_TUSK_MG"];
	_u = _u + ["AAV"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	//--- East.
	_n		= ["SmallTeam1"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_MG"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam2"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_LAT"];
	_u = _u + ["RU_Soldier_Marksman"];
	_u = _u + ["RU_Soldier_AR"];
	_u = _u + ["RU_Soldier_GL"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam3"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["RU_Soldier_MG"];
	_u = _u + ["RU_Soldier_GL"];
	_u = _u + ["RU_Soldier_AT"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam1"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["UAZ_AGS30_RU"];
	_u = _u + ["GAZ_Vodnik"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam2"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["GAZ_Vodnik"];
	_u = _u + ["GAZ_Vodnik_HMG"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam3"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["UAZ_AGS30_RU"];
	_u = _u + ["GAZ_Vodnik_HMG"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam1"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_AA"];
	_u = _u + ["RU_Soldier_LAT"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam2"];
	_u		= ["RUS_Commander"];
	_u = _u + ["RUS_Soldier1"];
	_u = _u + ["RUS_Soldier2"];
	_u = _u + ["RUS_Soldier_GL"];
	_u = _u + ["RUS_Soldier_Marksman"];
	_u = _u + ["RUS_Soldier3"];
	_u = _u + ["RUS_Soldier_TL"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam3"];
	_u		= ["MVD_Soldier_TL"];
	_u = _u + ["MVD_Soldier_MG"];
	_u = _u + ["MVD_Soldier_AT"];
	_u = _u + ["MVD_Soldier_GL"];
	_u = _u + ["MVD_Soldier_Sniper"];
	_u = _u + ["MVD_Soldier_Marksman"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam1"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["GAZ_Vodnik"];
	_u = _u + ["BMP3"];
	_u = _u + ["BTR90"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam2"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["T72_RU"];
	_u = _u + ["T72_RU"];
	_u = _u + ["GAZ_Vodnik_MedEvac"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam3"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["BMP3"];
	_u = _u + ["GAZ_Vodnik_HMG"];
	_u = _u + ["T72_RU"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam1"];
	_u		= ["RU_Soldier_HAT"];
	_u = _u + ["RU_Soldier_HAT"];
	_u = _u + ["RU_Soldier_HAT"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam2"];
	_u		= ["RUS_Commander"];
	_u = _u + ["RUS_Soldier1"];
	_u = _u + ["RUS_Soldier2"];
	_u = _u + ["RUS_Soldier_GL"];
	_u = _u + ["RUS_Soldier_Marksman"];
	_u = _u + ["RUS_Soldier3"];
	_u = _u + ["RUS_Soldier_TL"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam3"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_MG"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier_LAT"];
	_u = _u + ["RU_Soldier_Marksman"];
	_u = _u + ["RU_Soldier_AR"];
	_u = _u + ["RU_Soldier_GL"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam1"];
	_u		= ["RU_Soldier_TL"];
	if (WF_ACE) then
	{
		_u = _u + ["ACE_T90"];

		_u = _u + ["ACE_T90"];

		_u = _u + ["ACE_T90"];
	}
	else
	{
		_u = _u + ["T90"];
		_u = _u + ["T90"];
		_u = _u + ["T90"];
	};
	_u = _u + ["T72_RU"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam2"];
	_u		= ["RU_Soldier_TL"];
	if (WF_ACE) then
	{
		_u = _u + ["ACE_T90"];
	}
	else
	{
		_u = _u + ["T90"];
	};
	_u = _u + ["GRAD_RU"];
	_u = _u + ["T72_RU"];
	_u = _u + ["2S6M_Tunguska"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam3"];
	_u		= ["RU_Soldier_TL"];
	
	if (WF_ACE) then
	{
		_u = _u + ["ACE_T90"];

		_u = _u + ["ACE_T90"];
	}
	else
	{
		_u = _u + ["T90"];

		_u = _u + ["T90"];
	};
	
	_u = _u + ["2S6M_Tunguska"];
	_u = _u + ["T72_RU"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

if (WF_A2_Arrowhead) then {
	//--- West.
	_n		= ["SmallTeam1"];
	_u		= ["US_Soldier_SL_EP1"];
	_u = _u + ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	_u = _u + ["US_Soldier_Medic_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_MG_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["HMMWV_Avenger_DES_EP1"];
	_u = _u + ["HMMWV_M1151_M2_DES_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam2"];
	_u		= ["US_Soldier_SL_EP1"];
	_u = _u + ["HMMWV_TOW_DES_EP1"];
	_u = _u + ["M1126_ICV_mk19_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["HMMWV_Avenger_DES_EP1"];
	_u = _u + ["HMMWV_M998_crows_MK19_DES_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_Medic_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	_u = _u + ["US_Soldier_AT_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_MG_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam3"];
	_u		= ["US_Soldier_Sniper_EP1"];
	_u = _u + ["US_Soldier_Marksman_EP1"];
	_u = _u + ["US_Soldier_Marksman_EP1"];
	_u = _u + ["US_Soldier_SniperH_EP1"];
	_u = _u + ["US_Soldier_SniperH_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["HMMWV_Avenger_DES_EP1"];
	_u = _u + ["M2A3_EP1"];
	_u = _u + ["M1126_ICV_M2_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["M1A1_US_DES_EP1"];
	_u = _u + ["M1A1_US_DES_EP1"];
	_u = _u + ["HMMWV_Ambulance_DES_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["M1126_ICV_M2_EP1"];
	_u = _u + ["HMMWV_M998_crows_M2_DES_EP1"];
	_u = _u + ["M1A1_US_DES_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam1"];
	_u		= ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_AT_EP1"];
	_u = _u + ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam2"];
	_u		= ["US_Delta_Force_EP1"];
	_u = _u + ["US_Delta_Force_AR_EP1"];
	_u = _u + ["US_Delta_Force_SD_EP1"];
	_u = _u + ["US_Delta_Force_Assault_EP1"];
	_u = _u + ["US_Delta_Force_Marksman_EP1"];
	_u = _u + ["US_Delta_Force_M14_EP1"];
	_u = _u + ["US_Delta_Force_MG_EP1"];
	_u = _u + ["US_Delta_Force_Medic_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_Medic_EP1"];
	_u = _u + ["US_Soldier_GL_EP1"];
	_u = _u + ["US_Soldier_Sniper_EP1"];
	_u = _u + ["US_Soldier_AT_EP1"];
	_u = _u + ["US_Soldier_MG_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["MLRS_DES_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M1A2_US_TUSK_MG_EP1"];
	_u = _u + ["M6_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	//--- East.
	_n		= ["SmallTeam1"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["TK_Soldier_MG_EP1"];
	_u = _u + ["TK_Soldier_AT_EP1"];
	_u = _u + ["TK_Soldier_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam2"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["TK_Soldier_LAT_EP1"];
	_u = _u + ["TK_Soldier_Spotter_EP1"];
	_u = _u + ["TK_Soldier_AR_EP1"];
	_u = _u + ["TK_Soldier_GL_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam3"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["TK_Soldier_MG_EP1"];
	_u = _u + ["TK_Soldier_GL_EP1"];
	_u = _u + ["TK_Soldier_AT_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam1"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["LandRover_MG_TK_EP1"];
	_u = _u + ["BTR60_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam2"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["BTR60_TK_EP1"];
	_u = _u + ["BRDM2_TK_EP1"];
	_u = _u + ["BRDM2_ATGM_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam3"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["UAZ_AGS30_TK_EP1"];
	_u = _u + ["BRDM2_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam1"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["TK_Soldier_AA_EP1"];
	_u = _u + ["TK_Soldier_LAT_EP1"];
	_u = _u + ["TK_Soldier_AT_EP1"];
	_u = _u + ["TK_Soldier_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam2"];
	_u		= ["TK_Special_Forces_TL_EP1"];
	_u = _u + ["TK_Soldier_Medic_EP1"];
	_u = _u + ["TK_Soldier_HAT_EP1"];
	_u = _u + ["TK_Soldier_HAT_EP1"];
	_u = _u + ["TK_Special_Forces_EP1"];
	_u = _u + ["TK_Special_Forces_EP1"];
	_u = _u + ["TK_Special_Forces_MG_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam3"];
	_u		= ["TK_Special_Forces_TL_EP1"];
	_u = _u + ["TK_Soldier_Medic_EP1"];
	_u = _u + ["TK_Soldier_SniperH_EP1"];
	_u = _u + ["TK_Soldier_Sniper_Night_EP1"];
	_u = _u + ["TK_Soldier_Night_1_EP1"];
	_u = _u + ["TK_Soldier_Night_2_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam1"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["BMP2_TK_EP1"];
	_u = _u + ["BMP2_TK_EP1"];
	_u = _u + ["BTR60_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam2"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["M113Ambul_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam3"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["BMP2_TK_EP1"];
	_u = _u + ["Ural_ZU23_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam1"];
	_u		= ["TK_Soldier_HAT_EP1"];
	_u = _u + ["TK_Soldier_HAT_EP1"];
	_u = _u + ["TK_Soldier_HAT_EP1"];
	_u = _u + ["TK_Soldier_AT_EP1"];
	_u = _u + ["TK_Soldier_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam2"];
	_u		= ["TK_Special_Forces_TL_EP1"];
	_u = _u + ["TK_Special_Forces_EP1"];
	_u = _u + ["TK_Special_Forces_EP1"];
	_u = _u + ["TK_Special_Forces_EP1"];
	_u = _u + ["TK_Special_Forces_MG_EP1"];
	_u = _u + ["TK_Special_Forces_MG_EP1"];
	_u = _u + ["TK_Special_Forces_MG_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam3"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["TK_Soldier_MG_EP1"];
	_u = _u + ["TK_Soldier_AT_EP1"];
	_u = _u + ["TK_Soldier_LAT_EP1"];
	_u = _u + ["TK_Soldier_Spotter_EP1"];
	_u = _u + ["TK_Soldier_AR_EP1"];
	_u = _u + ["TK_Soldier_GL_EP1"];
	_u = _u + ["TK_Soldier_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam1"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["T55_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam2"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["T55_TK_EP1"];
	_u = _u + ["T55_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["ZSU_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam3"];
	_u		= ["TK_Soldier_SL_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	_u = _u + ["ZSU_TK_EP1"];
	_u = _u + ["T72_TK_EP1"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

if (WF_A2_CombinedOps) then {
	//--- West.
	_n		= ["SmallTeam1"];
	_u		= ["US_Soldier_SL_EP1"];
	_u = _u + ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	_u = _u + ["US_Soldier_Medic_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_MG_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"HMMWV_Avenger"} else {"HMMWV_Avenger_DES_EP1"}];
	_u = _u + [if (WF_Camo) then {"HMMWV_M2"} else {"HMMWV_M1151_M2_DES_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam2"];
	_u		= ["US_Soldier_SL_EP1"];
	_u = _u + [if (WF_Camo) then {"LAV25"} else {"M1126_ICV_mk19_EP1"}];
	_u = _u + [if (WF_Camo) then {"HMMWV_TOW"} else {"HMMWV_TOW_DES_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"HMMWV_Avenger"} else {"HMMWV_Avenger_DES_EP1"}];
	_u = _u + [if (WF_Camo) then {"HMMWV_MK19"} else {"HMMWV_M998_crows_MK19_DES_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_Medic_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	_u = _u + ["US_Soldier_AT_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_MG_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam3"];
	_u		= ["US_Soldier_Sniper_EP1"];
	_u = _u + ["US_Soldier_Marksman_EP1"];
	_u = _u + ["US_Soldier_Marksman_EP1"];
	_u = _u + ["US_Soldier_SniperH_EP1"];
	_u = _u + ["US_Soldier_SniperH_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"HMMWV_Avenger"} else {"HMMWV_Avenger_DES_EP1"}];
	_u = _u + ["M2A3_EP1"];
	_u = _u + [if (WF_Camo) then {"AAV"} else {"M1126_ICV_M2_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"M1A1"} else {"M1A1_US_DES_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A1"} else {"M1A1_US_DES_EP1"}];
	_u = _u + [if (WF_Camo) then {"HMMWV_Ambulance"} else {"HMMWV_Ambulance_DES_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"AAV"} else {"M1126_ICV_M2_EP1"}];
	_u = _u + [if (WF_Camo) then {"HMMWV_Armored"} else {"HMMWV_M998_crows_M2_DES_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A1"} else {"M1A1_US_DES_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam1"];
	_u		= ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_AT_EP1"];
	_u = _u + ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_HAT_EP1"];
	_u = _u + ["US_Soldier_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam2"];
	_u		= ["US_Delta_Force_EP1"];
	_u = _u + ["US_Delta_Force_AR_EP1"];
	_u = _u + ["US_Delta_Force_SD_EP1"];
	_u = _u + ["US_Delta_Force_Assault_EP1"];
	_u = _u + ["US_Delta_Force_Marksman_EP1"];
	_u = _u + ["US_Delta_Force_M14_EP1"];
	_u = _u + ["US_Delta_Force_MG_EP1"];
	_u = _u + ["US_Delta_Force_Medic_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_AA_EP1"];
	_u = _u + ["US_Soldier_Medic_EP1"];
	_u = _u + ["US_Soldier_GL_EP1"];
	_u = _u + ["US_Soldier_Sniper_EP1"];
	_u = _u + ["US_Soldier_AT_EP1"];
	_u = _u + ["US_Soldier_MG_EP1"];
	_u = _u + ["US_Soldier_AR_EP1"];
	_u = _u + ["US_Soldier_LAT_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam1"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam2"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"MLRS"} else {"MLRS_DES_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam3"];
	_u		= ["US_Soldier_TL_EP1"];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + [if (WF_Camo) then {"M1A2_TUSK_MG"} else {"M1A2_US_TUSK_MG_EP1"}];
	_u = _u + ["M6_EP1"];
	[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	//--- East.
	_n		= ["SmallTeam1"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_MG"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam2"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_LAT"];
	_u = _u + ["RU_Soldier_Marksman"];
	_u = _u + ["RU_Soldier_AR"];
	_u = _u + ["RU_Soldier_GL"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallTeam3"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["RU_Soldier_MG"];
	_u = _u + ["RU_Soldier_GL"];
	_u = _u + ["RU_Soldier_AT"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam1"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["UAZ_AGS30_RU"];
	_u = _u + ["GAZ_Vodnik"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam2"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["GAZ_Vodnik"];
	_u = _u + ["GAZ_Vodnik_HMG"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["SmallVehTeam3"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["UAZ_AGS30_RU"];
	_u = _u + ["GAZ_Vodnik_HMG"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam1"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_AA"];
	_u = _u + ["RU_Soldier_LAT"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam2"];
	_u		= ["RUS_Commander"];
	_u = _u + ["RUS_Soldier1"];
	_u = _u + ["RUS_Soldier2"];
	_u = _u + ["RUS_Soldier_GL"];
	_u = _u + ["RUS_Soldier_Marksman"];
	_u = _u + ["RUS_Soldier3"];
	_u = _u + ["RUS_Soldier_TL"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumTeam3"];
	_u		= ["MVD_Soldier_TL"];
	_u = _u + ["MVD_Soldier_MG"];
	_u = _u + ["MVD_Soldier_AT"];
	_u = _u + ["MVD_Soldier_GL"];
	_u = _u + ["MVD_Soldier_Sniper"];
	_u = _u + ["MVD_Soldier_Marksman"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam1"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["GAZ_Vodnik"];
	_u = _u + ["BMP3"];
	_u = _u + ["BTR90"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam2"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["T72_RU"];
	_u = _u + ["T72_RU"];
	_u = _u + ["GAZ_Vodnik_MedEvac"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["MediumVehTeam3"];
	_u		= ["RU_Soldier_TL"];
	_u = _u + ["BMP3"];
	_u = _u + ["GAZ_Vodnik_HMG"];
	_u = _u + ["T72_RU"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam1"];
	_u		= ["RU_Soldier_HAT"];
	_u = _u + ["RU_Soldier_HAT"];
	_u = _u + ["RU_Soldier_HAT"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam2"];
	_u		= ["RUS_Commander"];
	_u = _u + ["RUS_Soldier1"];
	_u = _u + ["RUS_Soldier2"];
	_u = _u + ["RUS_Soldier_GL"];
	_u = _u + ["RUS_Soldier_Marksman"];
	_u = _u + ["RUS_Soldier3"];
	_u = _u + ["RUS_Soldier_TL"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeTeam3"];
	_u		= ["RU_Soldier_SL"];
	_u = _u + ["RU_Soldier_MG"];
	_u = _u + ["RU_Soldier_AT"];
	_u = _u + ["RU_Soldier_LAT"];
	_u = _u + ["RU_Soldier_Marksman"];
	_u = _u + ["RU_Soldier_AR"];
	_u = _u + ["RU_Soldier_GL"];
	_u = _u + ["RU_Soldier"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam1"];
	_u		= ["RU_Soldier_TL"];
	
	if (WF_ACE) then
	{
		_u = _u + ["ACE_T90"];
		_u = _u + ["ACE_T90"];
		_u = _u + ["ACE_T90"];
	}
	else
	{
		_u = _u + ["T90"];
		_u = _u + ["T90"];
		_u = _u + ["T90"];
	};
	
	_u = _u + ["T72_RU"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam2"];
	_u		= ["RU_Soldier_TL"];
	if (WF_ACE) then
	{
		_u = _u + ["ACE_T90"];
	}
	else
	{
		_u = _u + ["T90"];
	};
	_u = _u + ["GRAD_RU"];
	_u = _u + ["T72_RU"];
	_u = _u + ["2S6M_Tunguska"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

	_n = _n + ["LargeVehTeam3"];
	_u		= ["RU_Soldier_TL"];
	if (WF_ACE) then
	{
		_u = _u + ["ACE_T90"];
		_u = _u + ["ACE_T90"];
	}
	else
	{
		_u = _u + ["T90"];
		_u = _u + ["T90"];
	};
	_u = _u + ["2S6M_Tunguska"];
	_u = _u + ["T72_RU"];
	[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;
};

diag_log "[WFBE (INIT)] Config_Occupation: Intialization - [Done]";
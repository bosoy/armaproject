Private ["_n","_u"];

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

//--- AA Units used by towns occupation in case of 'air assault' only.
_n = _n + ["SmallAATeam"];
_u		= ["USMC_Soldier_TL"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["USMC_Soldier_AA"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumAATeam"];
_u		= ["USMC_Soldier_TL"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["HMMWV_Avenger"];
_u = _u + ["HMMWV_Avenger"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeAATeam"];
_u		= ["USMC_Soldier_TL"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["USMC_Soldier_AA"];
_u = _u + ["HMMWV_Avenger"];
_u = _u + ["HMMWV_Avenger"];
_u = _u + ["HMMWV_Avenger"];
_u = _u + ["HMMWV_Armored"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Occupation_USMC: Initialization - [Done]",diag_frameno,diag_tickTime];
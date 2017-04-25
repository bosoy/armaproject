Private ["_n","_u"];

_n		= ["SmallTeam1"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Medic"];
_u = _u + ["CDF_Soldier"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SmallTeam2"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_Medic"];
_u = _u + ["CDF_Soldier"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SmallTeam3"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_MG"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier_Engineer"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SmallVehTeam1"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["BRDM2_ATGM_CDF"];
_u = _u + ["BRDM2_CDF"];
_u = _u + ["UAZ_MG_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SmallVehTeam2"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["BRDM2_ATGM_CDF"];
_u = _u + ["Ural_ZU23_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["SmallVehTeam3"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["UAZ_AGS30_CDF"];
_u = _u + ["UAZ_MG_CDF"];
_u = _u + ["Ural_ZU23_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumTeam1"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier_Medic"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumTeam2"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier_MG"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumTeam3"];
_u		= ["CDF_Soldier_Sniper"];
_u = _u + ["CDF_Soldier_Spotter"];
_u = _u + ["CDF_Soldier_Spotter"];
_u = _u + ["CDF_Soldier_Marksman"];
_u = _u + ["CDF_Soldier_Marksman"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumVehTeam1"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["Ural_ZU23_CDF"];
_u = _u + ["BMP2_CDF"];
_u = _u + ["ZSU_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumVehTeam2"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
_u = _u + ["BMP2_Ambul_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumVehTeam3"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["ZSU_CDF"];
_u = _u + ["BMP2_CDF"];
_u = _u + ["T72_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeTeam1"];
_u		= ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_Medic"];
_u = _u + ["CDF_Soldier"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeTeam2"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Medic"];
_u = _u + ["CDF_Soldier_GL"];
_u = _u + ["CDF_Soldier"];
_u = _u + ["CDF_Soldier"];
_u = _u + ["CDF_Soldier_Sniper"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier_RPG"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeTeam3"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Medic"];
_u = _u + ["CDF_Soldier_GL"];
_u = _u + ["CDF_Soldier_Sniper"];
_u = _u + ["CDF_Soldier_RPG"];
_u = _u + ["CDF_Soldier_MG"];
_u = _u + ["CDF_Soldier_Engineer"];
_u = _u + ["CDF_Soldier_AR"];
_u = _u + ["CDF_Soldier_RPG"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeVehTeam1"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeVehTeam2"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
_u = _u + ["ZSU_CDF"];
_u = _u + ["BMP2_CDF"];
_u = _u + ["T72_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeVehTeam3"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
_u = _u + ["T72_CDF"];
_u = _u + ["ZSU_CDF"];
_u = _u + ["GRAD_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

//--- AA Units used by towns occupation in case of 'air assault' only.
_n = _n + ["SmallAATeam"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumAATeam"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["ZSU_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeAATeam"];
_u		= ["CDF_Soldier_TL"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["CDF_Soldier_Strela"];
_u = _u + ["ZSU_CDF"];
_u = _u + ["ZSU_CDF"];
_u = _u + ["BMP2_CDF"];
[Format["WFBE_WEST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Occupation_CDF: Initialization - [Done]",diag_frameno,diag_tickTime];
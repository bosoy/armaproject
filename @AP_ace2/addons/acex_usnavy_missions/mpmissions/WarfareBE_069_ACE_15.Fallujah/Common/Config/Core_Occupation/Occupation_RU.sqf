Private ["_n","_u"];

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
_u = _u + ["T90"];
_u = _u + ["T90"];
_u = _u + ["T90"];
_u = _u + ["T72_RU"];
[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeVehTeam2"];
_u		= ["RU_Soldier_TL"];
_u = _u + ["T90"];
_u = _u + ["GRAD_RU"];
_u = _u + ["T72_RU"];
_u = _u + ["2S6M_Tunguska"];
[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeVehTeam3"];
_u		= ["RU_Soldier_TL"];
_u = _u + ["T90"];
_u = _u + ["T90"];
_u = _u + ["2S6M_Tunguska"];
_u = _u + ["T72_RU"];
[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

//--- AA Units used by towns occupation in case of 'air assault' only.
_n = _n + ["SmallAATeam"];
_u		= ["RU_Soldier_TL"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["RU_Soldier_AA"];
[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["MediumAATeam"];
_u		= ["RU_Soldier_TL"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["BTR90"];
[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

_n = _n + ["LargeAATeam"];
_u		= ["RU_Soldier_TL"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["RU_Soldier_AA"];
_u = _u + ["BTR90"];
_u = _u + ["2S6M_Tunguska"];
[Format["WFBE_EAST%1UNITS",_n select (count _n - 1)],_u,true] Call SetNamespace;

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Occupation_RU: Initialization - [Done]",diag_frameno,diag_tickTime];
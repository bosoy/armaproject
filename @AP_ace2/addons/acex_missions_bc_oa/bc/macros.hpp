#define QUOTE(str) #str

#ifndef DEFAULT_ADDONS
	#define DEFAULT_ADDONS "cacharacters2", \
		"camisc3", \
		"ace_sys_menu", \
		"ace_sys_bc", \
		"acex_missions_bc_oa", \
		"ace_c_weapon", \
		"ace_c_vehicle", \
		"ace_main", \
		"cba_main", \
		"acex_main"
#endif

/*
		"acex_men_usarmy", \
		"oh2_Characters", \
		"oh2_Weapons", \
		"RW_Characters"
*/

#define SKILL 1.0

#ifndef DEFAULT_STARTPOS
	#define DEFAULT_STARTPOS -9999,0.5,-9999
	// -10006.0,0.5,-10005.5
#endif

#ifndef DEFAULT_STARTPOS_EAST
	#define DEFAULT_STARTPOS_EAST DEFAULT_STARTPOS
#endif

#ifndef DEFAULT_STARTPOS_WEST
	#define DEFAULT_STARTPOS_WEST DEFAULT_STARTPOS
#endif

#ifndef DEFAULT_STARTPOS_GUER
	#define DEFAULT_STARTPOS_GUER DEFAULT_STARTPOS
#endif

#define INTEL class Intel \
	{ \
		briefingName="@str_sixbc_name"; \
		briefingDescription="@str_sixbc_subname"; \
		startWeather=0.3; \
		forecastWeather=0.3; \
		year=2010; \
		month=7; \
		day=1; \
		hour=12; \
		minute=0; \
		resistanceEast=1.0; \
		resistanceWest=0.0; \
	};

#ifndef STARTPOS
	#define STARTPOS DEFAULT_STARTPOS
#endif

#ifndef STARTPOS_EAST
	#define STARTPOS_EAST STARTPOS
#endif

#ifndef STARTPOS_WEST
	#define STARTPOS_WEST STARTPOS
#endif

#ifndef STARTPOS_GUER
	#define STARTPOS_GUER STARTPOS
#endif

#ifndef RANDOMSEED
	#define RANDOMSEED 14991706
#endif

#define QUOTE(y) #y

/*
	// WARNING, DO NOT USE COMMA (,) INSIDE PARAMETERS!
	Example
	Add above every group:
	#define GROUPID Alpha Lead

	Add to every unit, instead of init and description:
	FNC_UNIT(GROUPID,Squad Leader);

	etc.
*/

#define FNC_UNIT(GROUP,DESC) description=QUOTE(GROUP: DESC); \
					init=QUOTE(if (isNil 'ace_sys_bc_fnc_man_init') then { ace_sys_bc_fnc_man_init = compile preProcessFileLineNumbers '\x\ace\addons\sys_bc\fnc_man_init.sqf' }; ([this]+['GROUP']+['DESC']) call ace_sys_bc_fnc_man_init)


#define SCRIPTPOS_EAST [[STARTPOS_EAST] select 0,[STARTPOS_EAST] select 2,[STARTPOS_EAST] select 1]
#define SCRIPTPOS_WEST [[STARTPOS_WEST] select 0,[STARTPOS_WEST] select 2,[STARTPOS_WEST] select 1]
#define SCRIPTPOS_GUER [[STARTPOS_GUER] select 0,[STARTPOS_GUER] select 2,[STARTPOS_GUER] select 1]

#define DEFAULT_SCRIPTPOS_EAST [[DEFAULT_STARTPOS_EAST] select 0,[DEFAULT_STARTPOS_EAST] select 2,[DEFAULT_STARTPOS_EAST] select 1]
#define DEFAULT_SCRIPTPOS_WEST [[DEFAULT_STARTPOS_WEST] select 0,[DEFAULT_STARTPOS_WEST] select 2,[DEFAULT_STARTPOS_WEST] select 1]
#define DEFAULT_SCRIPTPOS_GUER [[DEFAULT_STARTPOS_GUER] select 0,[DEFAULT_STARTPOS_GUER] select 2,[DEFAULT_STARTPOS_GUER] select 1]


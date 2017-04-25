#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
#include "\ca\editor\Data\Scripts\dikCodes.h"

#define HAS_RETICLES(VEH) (getNumber(configfile>>"cfgvehicles">>(typeof VEH)>>"ace_sys_reticles_gunneroptics")==1)

ADDON = false;

LOG(MSG_INIT);

PREP(playerisgunner);
PREP(getweaponcfg);
PREP(fired);
PREP(setdegrees);
PREP(findunittext);
PREP(equalarrays);
PREP(getturretcfg);
PREP(getvalue);
PREP(nextElev);
PREP(nextRng);
PREP(nextWnd);
PREP(prevElev);
PREP(prevRng);
PREP(prevWnd);
PREP(ApplyRngChanges);
PREP(ApplyElevChanges);

//[QGVAR(setadj), {(_this select 0) setVariable ["ace_sys_sight_adjustment_params",(_this select 1)]}] call CBA_fnc_addEventHandler;

ACE_SYS_SA_WCFG = [];				//current weapon's sight properties/range table
ACE_SYS_SA = ACE_SYS_SA_NEW;			//current unit/vehicle/weapon/elevation/windage
ACE_SYS_SA_VEH_LST = [];			//list of vehicles used by player and sight settings for used turrets: [[veh1,[turret1],elev1,wind1],[veh2,[turret2],elev2,wind2],...,[veh_n,[turretn],elev_n,wind_n]]

0 spawn {
	private ["_veh","_pos","_turret"];
	while { true } do {
		waituntil { sleep 1; vehicle player != player };
		_veh = vehicle player;
		_pos = assignedVehicleRole player;
		if (player == gunner _veh) then
		{
			if (HAS_RETICLES(_veh) && (!ace_sys_reticles_sightup_veh)) then
			{
				player spawn ace_sys_reticles_fnc_veh_reticle;
			};
		};
		if ((_pos select 0 == "Turret") && {!(_veh isKindOf "ParachuteBase")}) then {
			_turret = _pos select 1;
			_turret call FUNC(playerisgunner); //внутри цикл крутится, пока игрок не покинет позицию стрелка
		};
	};
};

ADDON = true;

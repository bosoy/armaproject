//--- Radio Announcer (Vanilla worlds).
if (worldName in ('WFBE_WORLDWHITELISTVA' Call GetNamespace)) then {
	['WFBE_WESTANNOUNCERS',['WFHQ_EN0','WFHQ_EN1','WFHQ_EN2'],true] Call SetNamespace;
} else {
	['WFBE_WESTANNOUNCERS',['WFHQ_EN0_EP1','WFHQ_EN1_EP1','WFHQ_EN2_EP1','WFHQ_EN3_EP1','WFHQ_EN4_EP1','WFHQ_EN5_EP1'],true] Call SetNamespace;
};

//--- Crew model.
['WFBE_WESTCREW',if (WF_Camo) then {'USMC_Soldier_Crew'} else {'US_Soldier_Crew_EP1'},false] Call SetNamespace;

//--- Pilot model.
['WFBE_WESTPILOT',if (WF_Camo) then {'USMC_Soldier_Pilot'} else {'US_Soldier_Pilot_EP1'},false] Call SetNamespace;

//--- Soldier model.
['WFBE_WESTSOLDIER',if (WF_Camo) then {'USMC_Soldier'} else {'US_Soldier_EP1'},false] Call SetNamespace;

//--- Ambulances.
['WFBE_WESTAMBULANCES',['HMMWV_Ambulance','HMMWV_Ambulance_DES_EP1'],true] Call SetNamespace;

//--- Repair Trucks.
['WFBE_WESTREPAIRTRUCKS',['MtvrRepair','MtvrRepair_DES_EP1'],true] Call SetNamespace;

//--- Salvage Trucks.
['WFBE_WESTSALVAGETRUCK',['WarfareSalvageTruck_USMC','MtvrSalvage_DES_EP1'],true] Call SetNamespace;

//--- Supply Trucks.
['WFBE_WESTSUPPLYTRUCKS',['WarfareSupplyTruck_USMC','MtvrSupply_DES_EP1'],true] Call SetNamespace;

//--- UAV.
['WFBE_WESTUAV','MQ9PredatorB_US_EP1',true] Call SetNamespace;

if (isServer) then {
	//--- Base Patrols.
	if (paramBasePatrols) then {
		['WFBE_WESTBASEPATROLS_0',['US_Soldier_SL_EP1','US_Soldier_EP1','US_Soldier_EP1','US_Soldier_AR_EP1','US_Soldier_GL_EP1','US_Soldier_MG_EP1'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_1',['US_Soldier_SL_EP1','US_Soldier_EP1','US_Soldier_EP1','US_Soldier_MG_EP1','US_Soldier_LAT_EP1','US_Soldier_Medic_EP1'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_2',['US_Soldier_SL_EP1','US_Soldier_EP1','US_Soldier_EP1','US_Soldier_AT_EP1','US_Soldier_AA_EP1','US_Soldier_Sniper_EP1'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_3',['US_Soldier_SL_EP1','US_Soldier_EP1','US_Soldier_AR_EP1','US_Soldier_HAT_EP1','US_Soldier_LAT_EP1','US_Soldier_GL_EP1'],true] Call SetNamespace;
	};
	
	//--- Paratroopers.
	['WFBE_WESTPARACHUTELEVEL1',['US_Soldier_SL_EP1','US_Soldier_LAT_EP1','US_Soldier_EP1','US_Soldier_EP1','US_Soldier_AR_EP1','US_Soldier_Medic_EP1'],true] Call SetNamespace;
	['WFBE_WESTPARACHUTELEVEL2',['US_Soldier_SL_EP1','US_Soldier_AT_EP1','US_Soldier_AT_EP1','US_Soldier_AT_EP1','US_Soldier_AA_EP1','US_Soldier_MG_EP1','US_Soldier_Medic_EP1','US_Soldier_Spotter_EP1','US_Soldier_Sniper_EP1'],true] Call SetNamespace;
	['WFBE_WESTPARACHUTELEVEL3',['US_Delta_Force_TL_EP1','US_Soldier_HAT_EP1','US_Soldier_HAT_EP1','US_Soldier_HAT_EP1','US_Soldier_HAT_EP1','US_Soldier_AA_EP1','US_Soldier_AA_EP1','US_Delta_Force_AR_EP1','US_Delta_Force_Assault_EP1','US_Soldier_Medic_EP1','US_Delta_Force_M14_EP1','US_Soldier_AT_EP1','US_Soldier_Marksman_EP1'],true] Call SetNamespace;

	//--- Paratroopers, Vehicle.
	['WFBE_WESTPARACARGO','C130J_US_EP1',true] Call SetNamespace;
		
	//--- Repair Truck model.
	['WFBE_WESTREPAIRTRUCK',if (WF_Camo) then {'MtvrRepair'} else {'MtvrRepair_DES_EP1'},false] Call SetNamespace;
	
	//--- Starting Vehicles.
	['WFBE_WESTSTARTINGVEHICLES',if (WF_Camo) then {['HMMWV_Ambulance','MTVR']} else {['HMMWV_Ambulance_DES_EP1','MTVR_DES_EP1']},true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Ammunition.
	['WFBE_WESTPARAAMMO',['USBasicAmmunitionBox_EP1','USBasicWeapons_EP1','USLaunchers_EP1'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Vehicle.
	['WFBE_WESTPARAVEHICARGO','HMMWV_DES_EP1',true] Call SetNamespace;
	
	//--- Supply Paradropping, Vehicle.
	['WFBE_WESTPARAVEHI','CH_47F_EP1',true] Call SetNamespace;
	
	//--- Supply Paradropping, Parachute Model.
	['WFBE_WESTPARACHUTE','ParachuteMediumWest_EP1',true] Call SetNamespace;
	
	//--- Supply Truck model.
	['WFBE_WESTSUPPLYTRUCK',if (WF_Camo) then {'WarfareSupplyTruck_USMC'} else {'MtvrSupply_DES_EP1'},false] Call SetNamespace;
};

if (local player) then {
	//--- Default Faction (Buy Menu), this is the faction name defined in core_xxx.sqf files.
	['WFBE_WESTDEFAULTFACTION',if (WF_Camo) then {'USMC'} else {'US'},true] Call SetNamespace;
};
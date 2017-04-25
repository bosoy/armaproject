//--- Radio Announcer.
['WFBE_WESTANNOUNCERS',['WFHQ_EN0','WFHQ_EN1','WFHQ_EN2'],true] Call SetNamespace;

//--- Crew model.
['WFBE_WESTCREW','USMC_Soldier_Crew',true] Call SetNamespace;

//--- Pilot model.
['WFBE_WESTPILOT','USMC_Soldier_Pilot',true] Call SetNamespace;

//--- Soldier model.
['WFBE_WESTSOLDIER','USMC_Soldier',true] Call SetNamespace;

//--- Ambulances.
['WFBE_WESTAMBULANCES',['HMMWV_Ambulance'],true] Call SetNamespace;

//--- Repair Trucks.
['WFBE_WESTREPAIRTRUCKS',['MtvrRepair'],true] Call SetNamespace;

//--- Salvage Trucks.
['WFBE_WESTSALVAGETRUCK',['WarfareSalvageTruck_USMC'],true] Call SetNamespace;

//--- Supply Trucks.
['WFBE_WESTSUPPLYTRUCKS',['WarfareSupplyTruck_USMC'],true] Call SetNamespace;

//--- UAV.
['WFBE_WESTUAV','MQ9PredatorB',true] Call SetNamespace;

if (isServer) then {
	//--- Base Patrols.
	if (paramBasePatrols) then {
		['WFBE_WESTBASEPATROLS_0',['USMC_Soldier_SL','USMC_Soldier','USMC_Soldier','USMC_Soldier_AR','USMC_Soldier_GL','USMC_Soldier_MG'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_1',['USMC_Soldier_SL','USMC_Soldier','USMC_Soldier','USMC_Soldier_MG','USMC_Soldier_LAT','USMC_Soldier_Medic'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_2',['USMC_Soldier_SL','USMC_Soldier','USMC_Soldier','USMC_Soldier_AT','USMC_Soldier_AA','USMC_SoldierS_Sniper'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_3',['USMC_Soldier_SL','USMC_Soldier','USMC_Soldier_AR','USMC_Soldier_HAT','USMC_Soldier_LAT','USMC_Soldier_GL'],true] Call SetNamespace;
	};
	
	//--- Paratroopers.
	['WFBE_WESTPARACHUTELEVEL1',['USMC_Soldier_SL','USMC_Soldier_LAT','USMC_Soldier','USMC_Soldier2','USMC_Soldier_AR','USMC_Soldier_Medic'],true] Call SetNamespace;
	['WFBE_WESTPARACHUTELEVEL2',['USMC_Soldier_SL','USMC_Soldier_AT','USMC_Soldier_AT','USMC_Soldier_AT','USMC_Soldier_AA','USMC_Soldier_MG','USMC_Soldier_Medic','USMC_SoldierS_Spotter','USMC_SoldierS_Sniper'],true] Call SetNamespace;
	['WFBE_WESTPARACHUTELEVEL3',['FR_Assault_R','USMC_Soldier_HAT','USMC_Soldier_HAT','USMC_Soldier_HAT','USMC_Soldier_HAT','USMC_Soldier_AA','USMC_Soldier_AA','FR_AR','FR_AC','USMC_Soldier_Medic','FR_Marksman','USMC_Soldier_AT','USMC_SoldierS_Sniper'],true] Call SetNamespace;
	
	//--- Paratroopers, Vehicle.
	['WFBE_WESTPARACARGO','C130J',true] Call SetNamespace;
		
	//--- Repair Truck model.
	['WFBE_WESTREPAIRTRUCK','MtvrRepair',true] Call SetNamespace;
	
	//--- Starting Vehicles.
	['WFBE_WESTSTARTINGVEHICLES',['HMMWV_Ambulance','MTVR'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Ammunition.
	['WFBE_WESTPARAAMMO',['USBasicAmmunitionBox','USBasicWeaponsBox','USLaunchersBox'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Vehicle.
	['WFBE_WESTPARAVEHICARGO','HMMWV',true] Call SetNamespace;
	
	//--- Supply Paradropping, Vehicle.
	['WFBE_WESTPARAVEHI','MH60S',true] Call SetNamespace;
	
	//--- Supply Paradropping, Parachute Model.
	['WFBE_WESTPARACHUTE','ParachuteMediumWest',true] Call SetNamespace;
	
	//--- Supply Truck model.
	['WFBE_WESTSUPPLYTRUCK','WarfareSupplyTruck_USMC',true] Call SetNamespace;
};

if (local player) then {
	//--- Default Faction (Buy Menu), this is the faction name defined in core_xxx.sqf files.
	['WFBE_WESTDEFAULTFACTION','USMC',true] Call SetNamespace;
};
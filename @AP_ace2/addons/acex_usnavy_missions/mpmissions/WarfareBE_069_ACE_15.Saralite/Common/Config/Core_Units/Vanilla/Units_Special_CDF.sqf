//--- Radio Announcer.
['WFBE_WESTANNOUNCERS',['WFHQ_RU0','WFHQ_RU1','WFHQ_RU2'],true] Call SetNamespace;

//--- Crew model.
['WFBE_WESTCREW','CDF_Soldier_Crew',true] Call SetNamespace;

//--- Pilot model.
['WFBE_WESTPILOT','CDF_Soldier_Pilot',true] Call SetNamespace;

//--- Soldier model.
['WFBE_WESTSOLDIER','CDF_Soldier',true] Call SetNamespace;

//--- Ambulances.
['WFBE_WESTAMBULANCES',['BMP2_Ambul_CDF'],true] Call SetNamespace;

//--- Repair Trucks.
['WFBE_WESTREPAIRTRUCKS',['UralRepair_CDF'],true] Call SetNamespace;

//--- Salvage Trucks.
['WFBE_WESTSALVAGETRUCK',['WarfareSalvageTruck_CDF'],true] Call SetNamespace;

//--- Supply Trucks.
['WFBE_WESTSUPPLYTRUCKS',['WarfareSupplyTruck_CDF'],true] Call SetNamespace;

//--- UAV.
['WFBE_WESTUAV','MQ9PredatorB',true] Call SetNamespace;

if (isServer) then {
	//--- Base Patrols.
	if (paramBasePatrols) then {
		['WFBE_WESTBASEPATROLS_0',['CDF_Soldier_TL','CDF_Soldier','CDF_Soldier','CDF_Soldier_AR','CDF_Soldier_GL','CDF_Soldier_MG'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_1',['CDF_Soldier_TL','CDF_Soldier','CDF_Soldier','CDF_Soldier_MG','CDF_Soldier_RPG','CDF_Soldier_Medic'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_2',['CDF_Soldier_TL','CDF_Soldier','CDF_Soldier','CDF_Soldier_Marksman','CDF_Soldier_Strela','CDF_Soldier_Sniper'],true] Call SetNamespace;
		['WFBE_WESTBASEPATROLS_3',['CDF_Soldier_TL','CDF_Soldier','CDF_Soldier_AR','CDF_Soldier_RPG','CDF_Soldier_RPG','CDF_Soldier_GL'],true] Call SetNamespace;
	};
	
	//--- Paratroopers.
	['WFBE_WESTPARACHUTELEVEL1',['CDF_Soldier_TL','CDF_Soldier_RPG','CDF_Soldier','CDF_Soldier','CDF_Soldier_AR','CDF_Soldier_Medic'],true] Call SetNamespace;
	['WFBE_WESTPARACHUTELEVEL2',['CDF_Soldier_TL','CDF_Soldier_RPG','CDF_Soldier_RPG','CDF_Soldier_RPG','CDF_Soldier_Strela','CDF_Soldier_MG','CDF_Soldier_Medic','CDF_Soldier_Spotter','CDF_Soldier_Sniper'],true] Call SetNamespace;
	['WFBE_WESTPARACHUTELEVEL3',['CDF_Soldier_TL','CDF_Soldier_RPG','CDF_Soldier_RPG','CDF_Soldier_RPG','CDF_Soldier_RPG','CDF_Soldier_Strela','CDF_Soldier_Strela','CDF_Soldier','CDF_Soldier_GL','CDF_Soldier_Medic','CDF_Soldier_Sniper','CDF_Soldier','CDF_Soldier_Marksman'],true] Call SetNamespace;
	
	//--- Paratroopers, Vehicle.
	['WFBE_WESTPARACARGO','Mi17_CDF',true] Call SetNamespace;

	//--- Repair Truck model.
	['WFBE_WESTREPAIRTRUCK','UralRepair_CDF',true] Call SetNamespace;
	
	//--- Starting Vehicles.
	['WFBE_WESTSTARTINGVEHICLES',['BMP2_Ambul_CDF','Ural_CDF'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Ammunition.
	['WFBE_WESTPARAAMMO',['RUBasicAmmunitionBox','RUBasicWeaponsBox','RULaunchersBox'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Vehicle.
	['WFBE_WESTPARAVEHICARGO','BRDM2_CDF',true] Call SetNamespace;
	
	//--- Supply Paradropping, Vehicle.
	['WFBE_WESTPARAVEHI','Mi17_CDF',true] Call SetNamespace;
	
	//--- Supply Paradropping, Parachute Model.
	['WFBE_WESTPARACHUTE','ParachuteMediumWest',true] Call SetNamespace;
	
	//--- Supply Truck model.
	['WFBE_WESTSUPPLYTRUCK','WarfareSupplyTruck_CDF',true] Call SetNamespace;
};

if (local player) then {
	//--- Default Faction (Buy Menu), this is the faction name defined in core_xxx.sqf files.
	['WFBE_WESTDEFAULTFACTION','CDF',true] Call SetNamespace;
};
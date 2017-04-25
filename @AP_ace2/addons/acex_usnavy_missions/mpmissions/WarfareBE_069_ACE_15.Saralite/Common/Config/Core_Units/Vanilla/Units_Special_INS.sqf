//--- Radio Announcer.
['WFBE_EASTANNOUNCERS',['WFHQ_CZ0','WFHQ_CZ1','WFHQ_CZ2'],true] Call SetNamespace;

//--- Crew model.
['WFBE_EASTCREW','Ins_Soldier_Crew',true] Call SetNamespace;

//--- Pilot model.
['WFBE_EASTPILOT','Ins_Soldier_Pilot',true] Call SetNamespace;

//--- Soldier model.
['WFBE_EASTSOLDIER','Ins_Soldier_1',true] Call SetNamespace;

//--- Ambulances.
['WFBE_EASTAMBULANCES',['BMP2_Ambul_INS'],true] Call SetNamespace;

//--- Repair Trucks.
['WFBE_EASTREPAIRTRUCKS',['UralRepair_INS'],true] Call SetNamespace;

//--- Salvage Trucks.
['WFBE_EASTSALVAGETRUCK',['WarfareSalvageTruck_INS'],true] Call SetNamespace;

//--- Supply Trucks.
['WFBE_EASTSUPPLYTRUCKS',['WarfareSupplyTruck_INS'],true] Call SetNamespace;

//--- UAV.
['WFBE_EASTUAV','Pchela1T',true] Call SetNamespace;

if (isServer) then {
	//--- Base Patrols.
	if (paramBasePatrols) then {
		['WFBE_EASTBASEPATROLS_0',['Ins_Soldier_CO','Ins_Soldier_1','Ins_Soldier_2','Ins_Soldier_AR','Ins_Soldier_GL','Ins_Soldier_MG'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_1',['Ins_Soldier_CO','Ins_Soldier_1','Ins_Soldier_2','Ins_Soldier_MG','Ins_Soldier_AT','Ins_Soldier_Medic'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_2',['Ins_Soldier_CO','Ins_Soldier_1','Ins_Soldier_2','Ins_Soldier_AT','Ins_Soldier_AA','Ins_Soldier_Sniper'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_3',['Ins_Soldier_CO','Ins_Soldier_1','Ins_Soldier_AR','Ins_Soldier_AT','Ins_Soldier_AT','Ins_Soldier_GL'],true] Call SetNamespace;
	};
	
	//--- Paratroopers.
	['WFBE_EASTPARACHUTELEVEL1',['Ins_Soldier_CO','Ins_Soldier_AT','Ins_Soldier_1','Ins_Soldier_2','Ins_Soldier_AR','Ins_Soldier_Medic'],true] Call SetNamespace;
	['WFBE_EASTPARACHUTELEVEL2',['Ins_Soldier_CO','Ins_Soldier_AT','Ins_Soldier_AT','Ins_Soldier_AT','Ins_Soldier_AA','Ins_Soldier_MG','Ins_Soldier_Medic','Ins_Soldier_Sapper','Ins_Soldier_Sniper'],true] Call SetNamespace;
	['WFBE_EASTPARACHUTELEVEL3',['Ins_Soldier_CO','Ins_Soldier_AT','Ins_Soldier_AT','Ins_Soldier_AT','Ins_Soldier_AT','Ins_Soldier_Sapper','Ins_Soldier_AA','Ins_Soldier_AA','Ins_Soldier_MG','Ins_Soldier_Sab','Ins_Soldier_Sniper','Ins_Soldier_Sniper'],true] Call SetNamespace;
	
	//--- Paratroopers, Vehicle.
	['WFBE_EASTPARACARGO','Mi17_Ins',true] Call SetNamespace;
		
	//--- Repair Truck model.
	['WFBE_EASTREPAIRTRUCK','UralRepair_INS',true] Call SetNamespace;
	
	//--- Starting Vehicles.
	['WFBE_EASTSTARTINGVEHICLES',['BMP2_Ambul_INS','Ural_INS'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Ammunition.
	['WFBE_EASTPARAAMMO',['RUBasicAmmunitionBox','RUBasicWeaponsBox','RULaunchersBox'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Vehicle.
	['WFBE_EASTPARAVEHICARGO','BRDM2_INS',true] Call SetNamespace;
	
	//--- Supply Paradropping, Vehicle.
	['WFBE_EASTPARAVEHI','Mi17_Ins',true] Call SetNamespace;
	
	//--- Supply Paradropping, Parachute Model.
	['WFBE_EASTPARACHUTE','ParachuteMediumEast',true] Call SetNamespace;
	
	//--- Supply Truck model.
	['WFBE_EASTSUPPLYTRUCK','WarfareSupplyTruck_INS',true] Call SetNamespace;
};

if (local player) then {
	//--- Default Faction (Buy Menu), this is the faction name defined in core_xxx.sqf files.
	['WFBE_EASTDEFAULTFACTION','Insurgents',true] Call SetNamespace;
};
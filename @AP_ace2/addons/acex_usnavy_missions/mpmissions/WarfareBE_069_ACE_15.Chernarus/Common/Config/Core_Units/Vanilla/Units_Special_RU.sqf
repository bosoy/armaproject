//--- Radio Announcer.
['WFBE_EASTANNOUNCERS',['WFHQ_RU0','WFHQ_RU1','WFHQ_RU2'],true] Call SetNamespace;

//--- Crew model.
['WFBE_EASTCREW','RU_Soldier_Crew',true] Call SetNamespace;

//--- Pilot model.
['WFBE_EASTPILOT','RU_Soldier_Pilot',true] Call SetNamespace;

//--- Soldier model.
['WFBE_EASTSOLDIER','RU_Soldier',true] Call SetNamespace;

//--- Ambulances.
['WFBE_EASTAMBULANCES',['GAZ_Vodnik_MedEvac'],true] Call SetNamespace;

//--- Repair Trucks.
['WFBE_EASTREPAIRTRUCKS',['KamazRepair'],true] Call SetNamespace;

//--- Salvage Trucks.
['WFBE_EASTSALVAGETRUCK',['WarfareSalvageTruck_RU'],true] Call SetNamespace;

//--- Supply Trucks.
['WFBE_EASTSUPPLYTRUCKS',['WarfareSupplyTruck_RU'],true] Call SetNamespace;

//--- UAV.
['WFBE_EASTUAV','Pchela1T',true] Call SetNamespace;

if (isServer) then {
	//--- Base Patrols.
	if (paramBasePatrols) then {
		['WFBE_EASTBASEPATROLS_0',['RU_Soldier_SL','RU_Soldier','RU_Soldier','RU_Soldier_AR','RU_Soldier_GL','RU_Soldier_MG'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_1',['RU_Soldier_SL','RU_Soldier','RU_Soldier','RU_Soldier_MG','RU_Soldier_LAT','RU_Soldier_Medic'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_2',['RU_Soldier_SL','RU_Soldier','RU_Soldier','RU_Soldier_AT','RU_Soldier_AA','RU_Soldier_Marksman'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_3',['RU_Soldier_SL','RU_Soldier','RU_Soldier_AR','RU_Soldier_HAT','RU_Soldier_LAT','RU_Soldier_GL'],true] Call SetNamespace;
	};
	
	//--- Paratroopers.
	['WFBE_EASTPARACHUTELEVEL1',['RU_Soldier_SL','RU_Soldier_LAT','RU_Soldier','RU_Soldier2','RU_Soldier_AR','RU_Soldier_Medic'],true] Call SetNamespace;
	['WFBE_EASTPARACHUTELEVEL2',['RU_Soldier_SL','RU_Soldier_AT','RU_Soldier_AT','RU_Soldier_AT','RU_Soldier_AA','RU_Soldier_MG','RU_Soldier_Medic','RU_Soldier_Marksman','RUS_Soldier_Marksman'],true] Call SetNamespace;
	['WFBE_EASTPARACHUTELEVEL3',['MVD_Soldier_TL','RU_Soldier_HAT','RU_Soldier_HAT','RU_Soldier_HAT','RU_Soldier_HAT','RU_Soldier_HAT','RU_Soldier_AA','RU_Soldier_AA','MVD_Soldier_MG','RUS_Commander','MVD_Soldier_Sniper','RUS_Soldier_Marksman'],true] Call SetNamespace;
	
	//--- Paratroopers, Vehicle.
	['WFBE_EASTPARACARGO','Mi17_Ins',true] Call SetNamespace;
		
	//--- Repair Truck model.
	['WFBE_EASTREPAIRTRUCK','KamazRepair',true] Call SetNamespace;
	
	//--- Starting Vehicles.
	['WFBE_EASTSTARTINGVEHICLES',['GAZ_Vodnik_MedEvac','Kamaz'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Ammunition.
	['WFBE_EASTPARAAMMO',['RUBasicAmmunitionBox','RUBasicWeaponsBox','RULaunchersBox'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Vehicle.
	['WFBE_EASTPARAVEHICARGO','UAZ_RU',true] Call SetNamespace;
	
	//--- Supply Paradropping, Vehicle.
	['WFBE_EASTPARAVEHI','Mi17_Ins',true] Call SetNamespace;
	
	//--- Supply Paradropping, Parachute Model.
	['WFBE_EASTPARACHUTE','ParachuteMediumEast',true] Call SetNamespace;
	
	//--- Supply Truck model.
	['WFBE_EASTSUPPLYTRUCK','WarfareSupplyTruck_RU',true] Call SetNamespace;
};

if (local player) then {
	//--- Default Faction (Buy Menu), this is the faction name defined in core_xxx.sqf files.
	['WFBE_EASTDEFAULTFACTION','Russians',true] Call SetNamespace;
};
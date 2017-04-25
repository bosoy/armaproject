//--- Radio Announcer.
['WFBE_EASTANNOUNCERS',['WFHQ_TK0_EP1','WFHQ_TK1_EP1','WFHQ_TK2_EP1','WFHQ_TK3_EP1','WFHQ_TK4_EP1'],true] Call SetNamespace;

//--- Crew model.
['WFBE_EASTCREW','TK_Soldier_Crew_EP1',true] Call SetNamespace;

//--- Pilot model.
['WFBE_EASTPILOT','TK_Soldier_Pilot_EP1',true] Call SetNamespace;

//--- Soldier model.
['WFBE_EASTSOLDIER','TK_Soldier_EP1',true] Call SetNamespace;

//--- Ambulances.
['WFBE_EASTAMBULANCES',['M113Ambul_TK_EP1'],true] Call SetNamespace;

//--- Repair Trucks.
['WFBE_EASTREPAIRTRUCKS',['UralRepair_TK_EP1'],true] Call SetNamespace;

//--- Salvage Trucks.
['WFBE_EASTSALVAGETRUCK',['UralSalvage_TK_EP1'],true] Call SetNamespace;

//--- Supply Trucks.
['WFBE_EASTSUPPLYTRUCKS',['UralSupply_TK_EP1'],true] Call SetNamespace;

//--- UAV.
['WFBE_EASTUAV','',true] Call SetNamespace;

if (isServer) then {
	//--- Base Patrols.
	if (paramBasePatrols) then {
		['WFBE_EASTBASEPATROLS_0',['TK_Soldier_SL_EP1','TK_Soldier_EP1','TK_Soldier_EP1','TK_Soldier_AR_EP1','TK_Soldier_GL_EP1','TK_Soldier_MG_EP1'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_1',['TK_Soldier_SL_EP1','TK_Soldier_EP1','TK_Soldier_EP1','TK_Soldier_MG_EP1','TK_Soldier_LAT_EP1','TK_Soldier_Medic_EP1'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_2',['TK_Soldier_SL_EP1','TK_Soldier_EP1','TK_Soldier_EP1','TK_Soldier_AT_EP1','TK_Soldier_AA_EP1','TK_Soldier_Spotter_EP1'],true] Call SetNamespace;
		['WFBE_EASTBASEPATROLS_3',['TK_Soldier_SL_EP1','TK_Soldier_EP1','TK_Soldier_AR_EP1','TK_Soldier_HAT_EP1','TK_Soldier_LAT_EP1','TK_Soldier_GL_EP1'],true] Call SetNamespace;
	};
	
	//--- Paratroopers.
	['WFBE_EASTPARACHUTELEVEL1',['TK_Soldier_SL_EP1','TK_Soldier_LAT_EP1','TK_Soldier_EP1','TK_Soldier_LAT_EP1','TK_Soldier_AR_EP1','TK_Soldier_Medic_EP1'],true] Call SetNamespace;
	['WFBE_EASTPARACHUTELEVEL2',['TK_Soldier_SL_EP1','TK_Soldier_AT_EP1','TK_Soldier_AT_EP1','TK_Soldier_AT_EP1','TK_Soldier_AA_EP1','TK_Soldier_MG_EP1','TK_Soldier_Medic_EP1','TK_Soldier_Sniper_EP1','TK_Soldier_Spotter_EP1'],true] Call SetNamespace;
	['WFBE_EASTPARACHUTELEVEL3',['TK_Special_Forces_TL_EP1','TK_Soldier_HAT_EP1','TK_Soldier_HAT_EP1','TK_Soldier_HAT_EP1','TK_Soldier_HAT_EP1','TK_Soldier_HAT_EP1','TK_Soldier_AA_EP1','TK_Soldier_AA_EP1','TK_Special_Forces_MG_EP1','TK_Special_Forces_EP1','TK_Special_Forces_EP1','TK_Special_Forces_EP1'],true] Call SetNamespace;
	
	//--- Paratroopers, Vehicle.
	['WFBE_EASTPARACARGO','Mi17_TK_EP1',true] Call SetNamespace;
		
	//--- Repair Truck model.
	['WFBE_EASTREPAIRTRUCK','UralRepair_TK_EP1',true] Call SetNamespace;
	
	//--- Starting Vehicles.
	['WFBE_EASTSTARTINGVEHICLES',['M113Ambul_TK_EP1','V3S_TK_EP1'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Ammunition.
	['WFBE_EASTPARAAMMO',['TKBasicAmmunitionBox_EP1','TKBasicWeapons_EP1','TKLaunchers_EP1'],true] Call SetNamespace;
	
	//--- Supply Paradropping, Dropped Vehicle.
	['WFBE_EASTPARAVEHICARGO','UAZ_Unarmed_TK_EP1',true] Call SetNamespace;
	
	//--- Supply Paradropping, Vehicle.
	['WFBE_EASTPARAVEHI','Mi17_TK_EP1',true] Call SetNamespace;
	
	//--- Supply Paradropping, Parachute Model.
	['WFBE_EASTPARACHUTE','ParachuteMediumEast_EP1',true] Call SetNamespace;
	
	//--- Supply Truck model.
	['WFBE_EASTSUPPLYTRUCK','UralSupply_TK_EP1',true] Call SetNamespace;
};

if (local player) then {
	//--- Default Faction (Buy Menu), this is the faction name defined in core_xxx.sqf files.
	['WFBE_EASTDEFAULTFACTION','Takistani Army',true] Call SetNamespace;
};
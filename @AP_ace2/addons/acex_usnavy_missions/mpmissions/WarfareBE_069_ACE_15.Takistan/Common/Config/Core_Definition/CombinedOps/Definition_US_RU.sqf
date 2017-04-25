/* Arrowhead - US versus Russians */

/* Units Core */
WFBE_V_West_UnitsRootVersion = 'CombinedOps';
WFBE_V_West_Faction = 'US';
WFBE_V_East_UnitsRootVersion = 'CombinedOps';
WFBE_V_East_Faction = 'RU';
/* Loadout Core */
WFBE_V_West_LoadoutRootVersion = 'CombinedOps';
WFBE_V_West_Loadout = 'US';
WFBE_V_East_LoadoutRootVersion = 'CombinedOps';
WFBE_V_East_Loadout = 'RU';
/* Squads Core */
if (WF_Camo) then {
	WFBE_V_West_SquadsRootVersion = 'CombinedOps';
	WFBE_V_West_SquadsFaction = 'US_Camo';
} else {
	WFBE_V_West_SquadsRootVersion = 'Arrowhead';
	WFBE_V_West_SquadsFaction = 'US';
};
WFBE_V_East_SquadsRootVersion = 'Vanilla';
WFBE_V_East_SquadsFaction = 'RU';
/* Structures Core */
WFBE_V_West_StructuresRootVersion = 'CombinedOps';
WFBE_V_West_StructuresFaction = 'US';
WFBE_V_East_StructuresRootVersion = 'CombinedOps';
WFBE_V_East_StructuresFaction = 'TKA';
/* Artillery Core */
WFBE_V_West_ArtilleryRootVersion = 'CombinedOps';
WFBE_V_West_ArtilleryFaction = 'US';
WFBE_V_East_ArtilleryRootVersion = 'CombinedOps';
WFBE_V_East_ArtilleryFaction = 'RU';
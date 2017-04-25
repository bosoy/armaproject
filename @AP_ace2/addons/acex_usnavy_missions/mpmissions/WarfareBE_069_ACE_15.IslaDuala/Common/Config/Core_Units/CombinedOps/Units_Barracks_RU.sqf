Private ['_tiMode','_u'];

_tiMode = 'WFBE_THERMALIMAGING' Call GetNamespace;
_tiMode = if (_tiMode == 1 || _tiMode == 3) then {true} else {false};

//--- Russian Troops.
_u 			= ['RU_Soldier'];
_u = _u		+ ['RU_Soldier2'];
_u = _u		+ ['RU_Soldier_LAT'];
_u = _u		+ ['RU_Soldier_AT'];
_u = _u		+ ['RU_Soldier_HAT'];
_u = _u		+ ['RU_Soldier_AA'];
_u = _u		+ ['RU_Soldier_AR'];
_u = _u		+ ['RU_Soldier_MG'];
_u = _u		+ ['RU_Soldier_GL'];
_u = _u		+ ['RU_Soldier_Marksman'];
_u = _u		+ ['RU_Soldier_Spotter'];
_u = _u		+ ['RU_Soldier_Sniper'];
_u = _u		+ ['RU_Soldier_SniperH'];
_u = _u		+ ['RU_Soldier_Medic'];
_u = _u		+ ['RU_Soldier_TL'];
_u = _u		+ ['RU_Soldier_SL'];
_u = _u		+ ['RU_Soldier_Crew'];
_u = _u		+ ['RU_Soldier_Pilot'];
_u = _u		+ ['RUS_Soldier1'];
_u = _u		+ ['RUS_Soldier2'];
_u = _u		+ ['RUS_Soldier_GL'];
_u = _u		+ ['RUS_Soldier_Marksman'];
_u = _u		+ ['RUS_Soldier3'];
_u = _u		+ ['RUS_Soldier_TL'];
_u = _u		+ ['MVD_Soldier_GL'];
_u = _u		+ ['MVD_Soldier_MG'];
_u = _u		+ ['MVD_Soldier_Marksman'];
_u = _u		+ ['MVD_Soldier_AT'];
_u = _u		+ ['MVD_Soldier_Sniper'];
_u = _u		+ ['MVD_Soldier_TL'];
//--- Takistan Troops.
_u = _u		+ ['TK_Soldier_EP1'];
_u = _u		+ ['TK_Soldier_B_EP1'];
if (_tiMode) then {
	_u = _u		+ ['TK_Soldier_TWS_EP1'];
};
_u = _u		+ ['TK_Soldier_Engineer_EP1'];
_u = _u		+ ['TK_Soldier_LAT_EP1'];
_u = _u		+ ['TK_Soldier_AAT_EP1'];
_u = _u		+ ['TK_Soldier_AT_EP1'];
_u = _u		+ ['TK_Soldier_HAT_EP1'];
_u = _u		+ ['TK_Soldier_AA_EP1'];
_u = _u		+ ['TK_Soldier_AR_EP1'];
_u = _u		+ ['TK_Soldier_AMG_EP1'];
_u = _u		+ ['TK_Soldier_MG_EP1'];
_u = _u		+ ['TK_Soldier_GL_EP1'];
_u = _u		+ ['TK_Soldier_Spotter_EP1'];
_u = _u		+ ['TK_Soldier_Sniper_EP1'];
_u = _u		+ ['TK_Soldier_SniperH_EP1'];
_u = _u		+ ['TK_Soldier_Medic_EP1'];
_u = _u		+ ['TK_Special_Forces_EP1'];
_u = _u		+ ['TK_Special_Forces_TL_EP1'];
_u = _u		+ ['TK_Special_Forces_MG_EP1'];
_u = _u		+ ['TK_Soldier_Crew_EP1'];
_u = _u		+ ['TK_Soldier_Pilot_EP1'];
_u = _u		+ ['TK_Soldier_SL_EP1'];
_u = _u		+ ['TK_Soldier_Officer_EP1'];

_u
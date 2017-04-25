Private ['_u'];

//--- Russian Light Vehicles.
_u 			= ['MMT_Civ'];
_u = _u		+ ['TT650_Ins'];
_u = _u		+ ['UAZ_Unarmed_TK_EP1'];
_u = _u		+ ['UAZ_MG_TK_EP1'];
_u = _u		+ ['UAZ_AGS30_TK_EP1'];
_u = _u		+ ['UAZ_RU'];
_u = _u		+ ['PBX'];
_u = _u		+ ['UAZ_MG_INS'];
_u = _u		+ ['UAZ_AGS30_RU'];
_u = _u		+ ['UAZ_SPG9_INS'];
_u = _u		+ ['LandRover_MG_TK_EP1'];
_u = _u		+ ['LandRover_SPG9_TK_EP1'];
_u = _u		+ ['SUV_TK_EP1'];
_u = _u		+ ['Kamaz'];
_u = _u		+ ['V3S_TK_EP1'];
_u = _u		+ ['V3S_Open_TK_EP1'];
_u = _u		+ ['UralRepair_TK_EP1'];
_u = _u		+ ['UralReammo_TK_EP1'];
_u = _u		+ ['UralRefuel_TK_EP1'];
_u = _u		+ ['UralSalvage_TK_EP1'];
if (('WFBE_SUPPLYSYSTEM' Call GetNamespace) == 0) then {_u = _u		+ ['UralSupply_TK_EP1']};
_u = _u		+ ['KamazRepair'];
_u = _u		+ ['WarfareReammoTruck_RU'];
_u = _u		+ ['KamazRefuel'];
_u = _u		+ ['WarfareSalvageTruck_RU'];
if (('WFBE_SUPPLYSYSTEM' Call GetNamespace) == 0) then {_u = _u		+ ['WarfareSupplyTruck_RU']};
_u = _u		+ ['M113Ambul_TK_EP1'];
_u = _u		+ ['GAZ_Vodnik_MedEvac'];
_u = _u		+ ['BRDM2_TK_EP1'];
_u = _u		+ ['BRDM2_ATGM_TK_EP1'];
_u = _u		+ ['BRDM2_INS'];
_u = _u		+ ['BRDM2_ATGM_INS'];
_u = _u		+ ['GAZ_Vodnik'];
_u = _u		+ ['GAZ_Vodnik_HMG'];
_u = _u		+ ['BTR60_TK_EP1'];
_u = _u		+ ['Ural_ZU23_TK_EP1'];
_u = _u		+ ['Ural_ZU23_INS'];
_u = _u		+ ['BTR90'];
_u = _u		+ ['GRAD_TK_EP1'];
_u = _u		+ ['GRAD_RU'];

if (paramDLCPMC) then
{
	_u = _u		+ ['ArmoredSUV_PMC'];
};

_u
Private ['_u'];

//--- US Light Vehicles.
_u 			= ['MMT_USMC'];
_u = _u		+ ['M1030'];
_u = _u		+ ['M1030_US_DES_EP1'];
_u = _u		+ ['ATV_US_EP1'];
_u = _u		+ ['Zodiac'];
_u = _u		+ ['HMMWV_DES_EP1'];
_u = _u		+ ['HMMWV_M1035_DES_EP1'];
_u = _u		+ ['HMMWV_Terminal_EP1'];
_u = _u		+ ['HMMWV_MK19_DES_EP1'];
_u = _u		+ ['HMMWV_M998A2_SOV_DES_EP1'];
_u = _u		+ ['HMMWV_M1151_M2_DES_EP1'];
_u = _u		+ ['HMMWV_M998_crows_M2_DES_EP1'];
_u = _u		+ ['HMMWV_M998_crows_MK19_DES_EP1'];
_u = _u		+ ['HMMWV_TOW_DES_EP1'];
_u = _u		+ ['HMMWV_Avenger_DES_EP1'];
_u = _u		+ ['HMMWV_Ambulance_DES_EP1'];
_u = _u		+ ['HMMWV'];
_u = _u		+ ['HMMWV_M2'];
_u = _u		+ ['HMMWV_Armored'];
_u = _u		+ ['HMMWV_MK19'];
_u = _u		+ ['HMMWV_TOW'];
_u = _u		+ ['HMMWV_Avenger'];
_u = _u		+ ['HMMWV_Ambulance'];
_u = _u		+ ['MTVR_DES_EP1'];
_u = _u		+ ['MtvrRepair_DES_EP1'];
_u = _u		+ ['MtvrReammo_DES_EP1'];
_u = _u		+ ['MtvrRefuel_DES_EP1'];
_u = _u		+ ['MtvrSalvage_DES_EP1'];
if (('WFBE_SUPPLYSYSTEM' Call GetNamespace) == 0) then {_u = _u		+ ['MtvrSupply_DES_EP1']};
_u = _u		+ ['MTVR'];
_u = _u		+ ['MtvrRepair'];
_u = _u		+ ['WarfareReammoTruck_USMC'];
_u = _u		+ ['MtvrRefuel'];
_u = _u		+ ['WarfareSalvageTruck_USMC'];
if (('WFBE_SUPPLYSYSTEM' Call GetNamespace) == 0) then {_u = _u		+ ['WarfareSupplyTruck_USMC']};
_u = _u		+ ['RHIB'];
_u = _u		+ ['RHIB2Turret'];
_u = _u		+ ['LAV25'];
if (paramDLCBAF) then {
	_u = _u		+ ['BAF_ATV_W'];
	_u = _u		+ ['BAF_Offroad_W'];
	_u = _u		+ ['BAF_Jackal2_GMG_W'];
	_u = _u		+ ['BAF_Jackal2_L2A1_W'];
	_u = _u		+ ['BAF_ATV_D'];
	_u = _u		+ ['BAF_Offroad_D'];
	_u = _u		+ ['BAF_Jackal2_GMG_D'];
	_u = _u		+ ['BAF_Jackal2_L2A1_D'];
};

if (paramDLCPMC) then
{
	_u = _u		+ ['ArmoredSUV_PMC'];
};

_u
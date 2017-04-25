_unit = _this select 0;
_strLoadout = _this select 1;

if (!isServer) exitWith {};

removeAllWeapons _unit;
removeBackPack _unit;

switch (_strLoadout) do
{   

	case "TL":
	{
	      	{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
      		_unit addWeapon "ACE_SOC_M4A1_TWS";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellGreen";
		{_unit addMagazine "ACE_C4_M";} forEach [1,2];
		_unit addWeapon "ACE_M72A2";
		_unit addWeapon "NVGoggles";
	};
	
	case "medic":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "M4A3_CCO_EP1";
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellGreen";
		_unit addWeapon "NVGoggles";
	};
	
	case "Mark":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "ACE_HK416_D14_ACOG_PVS14";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addWeapon "ACE_M72A2";
		_unit addWeapon "NVGoggles";
	};
	
	case "SCARHSD":
	{
		{_unit addMagazine "20Rnd_762x51_B_SCAR";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "SCAR_H_CQC_CCO_SD";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addWeapon "ACE_M72A2";
		_unit addWeapon "NVGoggles";
	};
	
	case "HK416SD":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "ACE_HK416_D10_COMPM3_SD";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addWeapon "M136";
		_unit addWeapon "NVGoggles";
	};	
	
	case "M203":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		{_unit addMagazine "1Rnd_HE_M203"} forEach [1,2,3,4,5,6,7,8];
		_unit addWeapon "ACE_SOC_M4A1_GL_EOTECH";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addWeapon "ACE_M72A2";
		_unit addWeapon "NVGoggles";
	};
	
	case "M14":
	{
		{_unit addMagazine "20Rnd_762x51_DMR";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "M14_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addWeapon "M136";
		_unit addWeapon "NVGoggles";
	};
   
	case "MK48":
	{
		{_unit addMagazine "100Rnd_762x51_M240";} forEach [1,2,3,4];
		_unit addWeapon "Mk_48_DES_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addWeapon "NVGoggles";
	};
	
	case "M249TWS":
	{
		{_unit addMagazine "200Rnd_556x45_M249";} forEach [1,2,3,4];
		_unit addWeapon "M249_TWS_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addWeapon "NVGoggles";
	};
	
	case "SMAW":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "M4A3_CCO_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SMAW_HEAA";
		_unit addMagazine "ACE_SMAW_NE";
		{_unit addMagazine "ACE_SMAW_Spotting";} forEach [1,2];
		_unit addWeapon "SMAW";
		_unit addWeapon "NVGoggles";
	};
	
	
	case "AK103GLPSO":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7,8];
	      	{_unit addMagazine "1Rnd_HE_GP25";} forEach [1,2,3,4,5,6,7,8];
	      	//{_unit addMagazine "FlareWhite_GP25";} forEach [1,2,3];
      		_unit addWeapon "ACE_AK103_GL_PSO";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		_unit addWeapon "NVGoggles";
	};
	
	case "AK103PSO":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7,8];
      		_unit addWeapon "ACE_AK103_PSO";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		_unit addWeapon "NVGoggles";
	};
	
	case "AK103GL":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7,8];
      		_unit addWeapon "ACE_AK103_GL_Kobra";
		{_unit addMagazine "1Rnd_HE_GP25";} forEach [1,2,3,4,5,6,7,8];
	      	//{_unit addMagazine "FlareWhite_GP25";} forEach [1,2,3];
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		_unit addWeapon "NVGoggles";
	};
	
	case "AK103RPG27":
	{
		{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7,8];
	      	_unit addWeapon "ACE_AK103_Kobra";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		_unit addWeapon "NVGoggles";
		_unit addWeapon "ACE_RPG27";
	};
	
	case "RPK":
	{
		{_unit addMagazine "ACE_75Rnd_762x39_B_AK47";} forEach [1,2,3,4,5,6,7];
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addWeapon "ACE_RPK";
		_unit addWeapon "NVGoggles";
   	};
   	
	case "FAL":
	{
		{_unit addMagazine "20Rnd_762x51_FNFAL";} forEach [1,2,3,4,5,6,7,8];
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellBlue";
		_unit addWeapon "FN_FAL_ANPVS4";   	
   	};
   	
   	case "PKMNV":
   	{
   	      	{_unit addMagazine "100Rnd_762x54_PK";} forEach [1,2,3,4,5];
         	_unit addWeapon "PK";
   		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
   		_unit addWeapon "NVGoggles";
   	};
   	
   	case "SVDNV":
   	{
   	      	{_unit addMagazine "10Rnd_762x54_SVD";} forEach [1,2,3,4,5,6,7,8,9];
         	_unit addWeapon "SVD_NSPU_EP1";
   		_unit addMagazine "HandGrenade_East";
   		_unit addMagazine "SmokeShell";
   		_unit addMagazine "SmokeShellGreen";
   		_unit addWeapon "NVGoggles";
   		//{_unit addMagazine "30Rnd_9x19_UZI";} forEach [1,2];
   		//_unit addWeapon "UZI_EP1";
	};
};

if (!(_unit hasWeapon "itemGPS")) then
{
	_unit addWeapon "itemGPS";
};
if (!(_unit hasWeapon "LaserDesignator" || _unit hasWeapon "Binocular_Vector" || _unit hasWeapon "ACE_MX2A" || _unit hasWeapon "ACE_Rangefinder_OD" || _unit hasWeapon "Binocular")) then
{
	_unit addWeapon "binocular";
};
if (!(_unit hasWeapon "ACE_Earplugs")) then
{
	_unit addWeapon "ACE_Earplugs";
};
_unit addWeapon "ACE_GlassesLHD_glasses";

_primaryWeapon = primaryWeapon _unit;
_unit selectweapon _primaryWeapon;
// Fix for weapons with grenade launcher
_muzzles = getArray(configFile>>"cfgWeapons" >> _primaryWeapon >> "muzzles");
_unit selectWeapon (_muzzles select 0);
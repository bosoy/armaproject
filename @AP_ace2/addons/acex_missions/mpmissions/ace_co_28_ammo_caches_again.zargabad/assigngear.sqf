_unit = _this select 0;
_strLoadout = _this select 1;

if (!isServer) exitWith {};

removeAllWeapons _unit;
removeBackPack _unit;

switch (_strLoadout) do
{   

	case "FTL":
	{
	      	{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
      		_unit addWeapon "M4A3_CCO_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellGreen";
		{_unit addMagazine "ACE_C4_M";} forEach [1,2];
	};
	
	case "medic":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7,8];
		_unit addWeapon "M4A3_CCO_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		{_unit addMagazine "SmokeShellGreen";} forEach [1,2];
	};
	
	case "demo":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7,8];
		_unit addWeapon "M4A3_CCO_EP1";
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		{_unit addMagazine "PipeBomb";} forEach [1,2];
	};
	
	case "Mark":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7,8];
		_unit addWeapon "ACE_M4A1_ACOG";
		{_unit addMagazine "HandGrenade_West";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
	};

	case "M203":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7,8];
		{_unit addMagazine "1Rnd_HE_M203"} forEach [1,2,3,4,5,6,7,8];
		_unit addWeapon "ACE_M4A1_GL";
		{_unit addMagazine "HandGrenade_West";} forEach [1,2];;
		{_unit addMagazine "SmokeShell";} forEach [1,2];
	};
   
	case "M249":
	{
		{_unit addMagazine "200Rnd_556x45_M249";} forEach [1,2,3,4,5];
		_unit addWeapon "M249_EP1";
		{_unit addMagazine "HandGrenade_West";} forEach [1,2];
	};
	
	case "M24":
	{
		_unit addWeapon "M24";
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		{_unit addMagazine "5Rnd_762x51_M24"} forEach [1,2,3,4,5,6,7,8,9,10];
	};
	
	case "spotter":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		_unit addWeapon "M4A3_CCO_EP1";
		{_unit addMagazine "SmokeShell";} forEach [1,2,3];
		_unit addMagazine "HandGrenade_West";
		_unit addWeapon "ACE_Rangefinder_OD";
		_unit addMagazine "ACE_Battery_Rangefinder";
		_unit addWeapon "ACE_Spottingscope";
		_unit addWeapon "ACE_Kestrel4500";
	};
	
	case "AKM":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7,8];
      		_unit addWeapon "ACE_AKM";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellBlue";
	};
	
	case "RPG7":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7];
	      	{_unit addMagazine "PG7VL";} forEach [1,2];
      		_unit addWeapon "ACE_AKMS";
      		_unit addWeapon "RPG7V";
		_unit addMagazine "HandGrenade_East";
	};
	
	case "AKMGL":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7,8];
	      	{_unit addMagazine "1Rnd_HE_GP25";} forEach [1,2,3,4,5,6,7,8];
      		_unit addWeapon "ACE_AKM_GL";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
	};
	
	case "AK74PSO":
	{
	      	{_unit addMagazine "30Rnd_545x39_AK";} forEach [1,2,3,4,5,6,7,8];
      		_unit addWeapon "AKS_74_pso";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
	};
	
	case "RPK":
	{
		{_unit addMagazine "ACE_75Rnd_762x39_B_AK47";} forEach [1,2,3,4,5,6,7];
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addWeapon "ACE_RPK";
   	};
   	
	case "FAL":
	{
		{_unit addMagazine "20Rnd_762x51_FNFAL";} forEach [1,2,3,4,5,6,7,8];
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellBlue";
		_unit addWeapon "FN_FAL";   	
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
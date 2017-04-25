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
		if (random 1 < 0.33) then
		{
			_unit addWeapon "ACE_SOC_M4A1_Aim";
		}
		else
		{
			if (random 1 < 0.5) then
			{
				_unit addWeapon "ACE_SOC_M4A1_Eotech";
			}
			else
			{
				_unit addWeapon "ACE_SOC_M4A1_TWS";
			};
		};
		{_unit addMagazine "HandGrenade_West";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellGreen";
		_unit addWeapon "ACE_Rangefinder_OD";
		_unit addMagazine "ACE_Battery_Rangefinder";
		if (random 1 < 0.4) then
		{
			_unit addWeapon "ACE_M72A2";
		};
		_unit addWeapon "NVGoggles";
	};
	
	case "M4A1":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		if (random 1 < 0.44) then
		{
			_unit addWeapon "ACE_SOC_M4A1_Aim";
		}
		else
		{
			if (random 1 < 0.25) then
			{
				_unit addWeapon "ACE_SOC_M4A1_Eotech";
			}
			else
			{
				_unit addWeapon "ACE_SOC_M4A1_TWS";
			};
		};
		{_unit addMagazine "HandGrenade_West";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellGreen";
		_unit addWeapon "ACE_Rangefinder_OD";
		_unit addMagazine "ACE_Battery_Rangefinder";
		if (random 1 < 0.67) then
		{
			_unit addWeapon "ACE_M72A2";
		};
		_unit addWeapon "NVGoggles";
	};
	
	case "M14":
	{
		{_unit addMagazine "20Rnd_762x51_DMR";} forEach [1,2,3,4,5,6,7];
      		_unit addWeapon "M14_EP1";
		{_unit addMagazine "HandGrenade_West";} forEach [1,2,3];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		if (random 1 < 0.25) then
		{
			_unit addWeapon "ACE_M72A2";
		};
		_unit addWeapon "NVGoggles";
	};
   
	case "MarkH":
	{
		{_unit addMagazine "20Rnd_762x51_B_SCAR";} forEach [1,2,3,4,5,6,7];
      		if (random 1 < 0.8) then
      		{
      			_unit addWeapon "M110_NVG_EP1";
      		}
      		else
      		{
      			_unit addWeapon "M110_TWS_EP1";
      		};
		{_unit addMagazine "HandGrenade_West";} forEach [1,2,3];
		{_unit addMagazine "SmokeShell";} forEach [1,2];
		if (random 1 < 0.25) then
		{
			_unit addWeapon "ACE_M72A2";
		};
		_unit addWeapon "NVGoggles";
	};

	case "M4A1M203":
	{
		{_unit addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
		{_unit addMagazine "1Rnd_HE_M203"} forEach [1,2,3,4,5,6,7,8];
		if (random 1 < 0.6) then
		{
			_unit addWeapon "ACE_SOC_M4A1_RCO_GL";
		}
		else
		{
			_unit addWeapon "ACE_SOC_M4A1_GL_EOTECH";
		};
		_unit addMagazine "HandGrenade_West";
		_unit addMagazine "SmokeShell";
		_unit addWeapon "NVGoggles";
		if (random 1 < 0.25) then
		{
			_unit addWeapon "ACE_M72A2";
		};
	};
   
	case "M249":
	{
		{_unit addMagazine "200Rnd_556x45_M249";} forEach [1,2,3,4,5];
		if (random 1 < 0.35) then
		{
			_unit addWeapon "M249_EP1";
		}
		else
		{
			_unit addWeapon "M249_m145_EP1";
		};
		_unit addMagazine "HandGrenade_West";
		_unit addWeapon "NVGoggles";
	};
	
	
	case "AKM":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6];
      		_unit addWeapon "ACE_AKM";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellBlue";
	};
	
	case "medic":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6];
      		_unit addWeapon "ACE_AKMS";
		_unit addMagazine "HandGrenade_East";
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellBlue";
	};
	
	case "RPG7":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5];
	      	{_unit addMagazine "PG7VL";} forEach [1,2];
      		_unit addWeapon "ACE_AKMS";
      		_unit addWeapon "RPG7V";
		_unit addMagazine "HandGrenade_East";
	};
	
	case "AKMGL":
	{
	      	{_unit addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6];
	      	{_unit addMagazine "1Rnd_HE_GP25";} forEach [1,2,3,4];
	      	{_unit addMagazine "FlareWhite_GP25";} forEach [1,2,3,4];
      		_unit addWeapon "ACE_AKM_GL";
		_unit addMagazine "HandGrenade_East";
		_unit addMagazine "SmokeShell";
	};
	
	case "AK74PSO":
	{
	      	{_unit addMagazine "30Rnd_545x39_AK";} forEach [1,2,3,4,5,6];
      		_unit addWeapon "AKS_74_pso";
		{_unit addMagazine "HandGrenade_East";} forEach [1,2];
		_unit addMagazine "SmokeShell";
	};
	
	case "RPK":
	{
		{_unit addMagazine "ACE_75Rnd_762x39_B_AK47";} forEach [1,2,3,4,5];
		_unit addMagazine "HandGrenade_East";
		_unit addWeapon "ACE_RPK";
   	};
   	
	case "FAL":
	{
		{_unit addMagazine "20Rnd_762x51_FNFAL";} forEach [1,2,3,4,5,6];
		_unit addMagazine "HandGrenade_East";
		_unit addMagazine "SmokeShell";
		_unit addMagazine "SmokeShellBlue";
		_unit addWeapon "FN_FAL";   	
   	};
};

//if (!(_unit hasWeapon "itemGPS")) then
//{
//	_unit addWeapon "itemGPS";
//};
if (!(_unit hasWeapon "LaserDesignator" || _unit hasWeapon "Binocular_Vector" || _unit hasWeapon "ACE_MX2A" || _unit hasWeapon "ACE_Rangefinder_OD" || _unit hasWeapon "Binocular")) then
{
	_unit addWeapon "binocular";
};
if (!(_unit hasWeapon "ACE_Earplugs")) then
{
	_unit addWeapon "ACE_Earplugs";
};
//_unit addWeapon "ACE_GlassesLHD_glasses";

_primaryWeapon = primaryWeapon _unit;
_unit selectweapon _primaryWeapon;
// Fix for weapons with grenade launcher
_muzzles = getArray(configFile>>"cfgWeapons" >> _primaryWeapon >> "muzzles");
_unit selectWeapon (_muzzles select 0);
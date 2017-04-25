private ["_strLoadout", "_strLoadoutOptions", "_suffixes", "_tempLoadout", "_nightSights", "_flares"];

removeAllWeapons player;
removeBackPack player;
player setVariable ["ACE_WeaponOnBack", ""];

_varName = vehicleVarName player;

_nightSights = (nightSights>0) && (nightOrDay!=0);
_flares = (nightVision==0) && (nightorday>0);

_strLoadoutOptions = ["RifleUS", "GLUS", "SLUS", "MGUS", "MGscopeUS", "MarksmanUS", "RifleTK", "MGTK", "MGscopeTK", "SLTK", "MarksmanTK", "GLTK"];
_suffixes = ["", "A", "B", "C", "D", "E", "F", "a", "b", "c", "d", "e", "f", "1", "2", "3", "4", "5", "6"];
_strLoadout = "";
{
	_tempLoadout=_x;
	{
		if (_tempLoadout+_x == _varName) then
		{
			_strLoadout=_tempLoadout;
		};
	} forEach _suffixes;
} forEach _strLoadoutOptions;

switch (_strLoadout) do
{   
	case "SLUS":
	{
	      	{player addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				player addWeapon "ACE_M4A1_Eotech";
      			};
      			case 2:
      			{
      				player addWeapon "M16A2";
      			};
      		};
      		
		{player addMagazine "HandGrenade_West";} forEach [1,2,3];
		player addWeapon "ACE_M72A2";
		if (nightVision>1) then
		{
			player addWeapon "ACE_MX2A";
			player addMagazine "SmokeShellGreen";
		}
		else
		{
			if (nightVision>0) then
			{
				player addWeapon "ACE_Rangefinder_OD";
				player addMagazine "ACE_Battery_Rangefinder";
			}
			else
			{
				player addMagazine "SmokeShellGreen";
			};
		};
		player addMagazine "ACE_Claymore_M";
		if (_flares) then
		{
			{player addMagazine"ACE_SSWhite_FG";} forEach [1,2,3,4];
			player addWeapon "ACE_Flaregun";
		};
	};

	case "RifleUS":
	{
	      	{player addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				player addWeapon "ACE_M4A1_Eotech";
      			};
      			case 2:
      			{
      				player addWeapon "M16A2";
      			};
      		};
		{player addMagazine "HandGrenade_West";} forEach [1,2,3];
		player addMagazine "SmokeShell";
		player addMagazine "ACE_Claymore_M";
		player addWeapon "ACE_M72A2";
	};
	
	case "MGUS":
	{
		{player addMagazine "200Rnd_556x45_M249";} forEach [1,2,3,4];
		player addWeapon "M249_EP1";
		player addMagazine "HandGrenade_West";
	};
	
	case "MGscopeUS":
	{
		{player addMagazine "200Rnd_556x45_M249";} forEach [1,2,3,4];
      		switch (loadouts) do
      		{
      			case 1:
      			{
		      		if (_nightSights && nightSights>1) then
				{
					player addWeapon "M249_TWS_EP1";
				}
				else
				{
					player addWeapon "M249_m145_EP1";
				};
      			};
      			case 2:
      			{
      				player addWeapon "M249_EP1";
      			};
      		};
		player addMagazine "HandGrenade_West";
	};
	
	case "MarksmanUS":
	{
		{player addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7];
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				if (_nightSights) then
				{
					player addWeapon "ACE_HK416_D14_ACOG_PVS14";
				}
				else
				{
					player addWeapon "ACE_M4A1_ACOG";
				};
      			};
      			case 2:
      			{
      				player addWeapon "ACE_m16a2_scope";
      			};
      		};
		player addMagazine "HandGrenade_West";
		player addMagazine "SmokeShell";
		player addMagazine "ACE_Claymore_M";
		player addWeapon "ACE_M72A2";
	};
	
	case "GLUS":
	{
		if (_flares) then
		{
			{player addMagazine "1Rnd_HE_M203";} forEach [1,2,3,4,5];
			{player addMagazine "FlareWhite_M203";} forEach [1,2,3];
		}
		else
		{	      	
	      			{player addMagazine "1Rnd_HE_M203";} forEach [1,2,3,4,5,6,7,8];
	      	};
		{player addMagazine "30Rnd_556x45_Stanag";} forEach [1,2,3,4,5,6,7,8];
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				player addWeapon "ACE_SOC_M4A1_GL_AIMPOINT";
      			};
      			case 2:
      			{
      				player addWeapon "M16A2GL";
      			};
      		};
		player addMagazine "HandGrenade_West";
		player addMagazine "SmokeShell";
		player addMagazine "ACE_Claymore_M";
		player addWeapon "ACE_M72A2";	
	};
	
	case "GLTK":
	{
		if (_flares) then
		{
			{player addMagazine "1Rnd_HE_GP25";} forEach [1,2,3,4,5];
			{player addMagazine "FlareWhite_GP25";} forEach [1,2,3];
		}
		else
		{
			{player addMagazine "1Rnd_HE_GP25";} forEach [1,2,3,4,5,6,7,8];
		};
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				{player addMagazine "30Rnd_545x39_AK";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_AK74M_GL_Kobra";
      			};
      			case 2:
      			{
      				{player addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_AKM_GL";
      			};
      		};
      		player addMagazine "HandGrenade_East";
		player addMagazine "SmokeShell";
		player addMagazine "ACE_Claymore_M";
	};
	
	case "MarksmanTK":
	{
		{player addMagazine "30Rnd_545x39_AK";} forEach [1,2,3,4,5,6,7];
		if (_nightSights) then
		{
			player addWeapon "AKS_74_NSPU";
		}
		else
		{
			player addWeapon "ACE_AK74M_PSO";
		};
		player addMagazine "HandGrenade_East";
		player addMagazine "SmokeShell";
		player addMagazine "ACE_Claymore_M";
	};
	
	case "SLTK":
	{
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				{player addMagazine "30Rnd_545x39_AK";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_AK74M_Kobra";
      			};
      			case 2:
      			{
      				{player addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_AKM";
      			};
      		};

		{player addMagazine "HandGrenade_East";} forEach [1,2,3];
		if (nightVision>1) then
		{
			player addWeapon "ACE_MX2A";
			player addMagazine "SmokeShellBlue";
		}
		else
		{
			if (nightVision>0 && loadouts!=2) then
			{
				player addWeapon "ACE_Rangefinder_OD";
				player addMagazine "ACE_Battery_Rangefinder";
			}
			else
			{
				player addMagazine "SmokeShellBlue";
			};
		};
		player addMagazine "ACE_Claymore_M";
		if (_flares) then
		{
			{player addMagazine"ACE_SSWhite_FG";} forEach [1,2,3,4];
			player addWeapon "ACE_Flaregun";
		};
	};
	
	case "RifleTK":
	{
      		switch (loadouts) do
      		{
      			case 1:
      			{
      				{player addMagazine "30Rnd_545x39_AK";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_AK74M_Kobra";
      			};
      			case 2:
      			{
      				{player addMagazine "30Rnd_762x39_AK47";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_AKM";
      			};
      		};
      		{player addMagazine "HandGrenade_East";} forEach [1,2,3];
		player addMagazine "SmokeShell";
		player addMagazine "ACE_Claymore_M";
	};
	
	case "MGTK":
	{
      		switch (loadouts) do
      		{
      			case 1:
      			{
				{player addMagazine "75Rnd_545x39_RPK";} forEach [1,2,3,4,5,6,7,8,9,10];
				player addWeapon "ACE_RPK74M";
      			};
      			case 2:
      			{
      				{player addMagazine "ACE_75Rnd_762x39_B_AK47";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_RPK";
      			};
      		};
		player addMagazine "HandGrenade_East";
	};
	
	case "MGscopeTK":
	{
      		switch (loadouts) do
      		{
      			case 1:
      			{
		      		{player addMagazine "75Rnd_545x39_RPK";} forEach [1,2,3,4,5,6,7,8,9,10];
				player addWeapon "ACE_RPK74M_1P29";
      			};
      			case 2:
      			{
      				{player addMagazine "ACE_75Rnd_762x39_B_AK47";} forEach [1,2,3,4,5,6,7];
      				player addWeapon "ACE_RPK";
      			};
      		};
      		player addMagazine "HandGrenade_East";
	};

};

_primaryWeapon = primaryWeapon player;
if (_primaryWeapon!="") then
{
	player selectweapon _primaryWeapon;
	// Fix for weapons with grenade launcher
	_muzzles = getArray(configFile>>"cfgWeapons" >> _primaryWeapon >> "muzzles");
	player selectWeapon (_muzzles select 0);
};

if (nightVision>0) then
{
	player addWeapon "NVGoggles";
};

if (!(player hasWeapon "itemGPS")) then
{
	player addWeapon "itemGPS";
};
if (!(player hasWeapon "LaserDesignator" || player hasWeapon "Binocular_Vector" || player hasWeapon "ACE_MX2A" || player hasWeapon "ACE_Rangefinder_OD")) then
{
	player addWeapon "Binocular";
};
player addWeapon "ACE_GlassesLHD_glasses";
if (!(player hasWeapon "ACE_Earplugs")) then
{
	player addWeapon "ACE_Earplugs";
};

call compile preprocessFile "saveloadout.sqf";
private ["_addMagCount", "_grenade", "_defWeapon", "_defMag", "_flareSpaceLeft", "_flareCount"];

if (!isNil "_this") then
{
	// was called via action
	removeAllWeapons player;
	player setVariable ["ACE_WeaponOnBack", ""];
};

if (count magazines player<8 && (primaryWeapon player == "") && (secondaryWeapon player == "")) then
{
	_flareCount = 4 min (8 - (count magazines player));
	if (weaponTypes>2) then
	{
		_defWeapon = "ACE_M4A1_Eotech";
		_defMag = "30rnd_556x45_Stanag";
		if (playerSide == EAST) then
		{
			_defWeapon = "ACE_AK74M_Kobra";
			_defMag = "30Rnd_545x39_AK";
		};
	};
	if (weaponTypes==2) then
	{
		_defWeapon = "ACE_M1014_Eotech";
		_defMag = "8Rnd_B_Beneli_74Slug";
		if (playerSide == EAST) then
		{
			_defWeapon = "Saiga12K";
			_defMag = "8Rnd_B_Saiga12_74Slug";
		};	
	};
	if (weaponTypes==1) then
	{
		_defWeapon = "ACE_MP5A4";
		_defMag = "30Rnd_9x19_MP5";
		if (playerSide == EAST) then
		{
			_defWeapon = "Bizon";
			_defMag = "64Rnd_9x19_Bizon";
		};	
	};
	if ((weaponTypes == 0) && (count magazines player == 0)) then
	{
		_defWeapon = "M9";
		_defMag = "15rnd_9x19_m9";
		if (playerSide == EAST) then
		{
			_defWeapon = "Makarov";
			_defMag = "8Rnd_9x18_Makarov";
		};	
	};
	
	if ((weaponTypes>0) || (count magazines player == 0)) then
	{
		_addMagCount = 8 min (12-count magazines player);
		for "_i" from 1 to _addMagCount do
		{
			player addMagazine _defMag;
		};
		player addWeapon _defWeapon;
		player selectWeapon _defWeapon;
	};
	
	if (explosives>0) then
	{
		_grenade="Handgrenade_West";
		if (playerSide == EAST) then
		{
			_grenade="Handgrenade_East";
		};
		if (count magazines player < 12) then
		{
			_addMagCount = (1 max (11-count magazines player)) min 4;
			for "_i" from 1 to _addMagCount do
			{
				player addMagazine _grenade;
			};
		};
	};
	
	_addMagCount = (12-count magazines player) min 4;
	for "_i" from 1 to _addMagCount do
	{
		player addMagazine "SmokeShell";
	};
	
	if (launchers>0 && playerSide == WEST) then
	{
		player addWeapon "ACE_M72A2";
		if (player getVariable "ACE_WeaponOnBack" == "") then
		{
			player setVariable ["ACE_WeaponOnBack", "ACE_M72A2"];
		};
	};
	
	if (nightVision>0 && !(player hasWeapon "NVGoggles")) then
	{
		player addWeapon "NVGoggles";
	};
	
	if (!(player hasWeapon "itemGPS")) then
	{
		player addWeapon "itemGPS";
	};
	if (!(player hasWeapon "LaserDesignator" || player hasWeapon "Binocular_Vector" || player hasWeapon "ACE_MX2A" || player hasWeapon "ACE_Rangefinder_OD" || player hasWeapon "Binocular")) then
	{
		if (nightVision<2) then
		{
			player addWeapon "Binocular";
		}
		else
		{
			player addWeapon "ACE_MX2A"
		};
	};
	player addWeapon "ACE_GlassesLHD_glasses";
	if (!(player hasWeapon "ACE_Earplugs")) then
	{
		player addWeapon "ACE_Earplugs";
	};
	
	if (nightVision==0 && nightOrDay>0 && weaponTypes>0 && _flareCount>0) then
	{
		for "_i" from 1 to _flareCount do
		{
			player addMagazine"ACE_SSWhite_FG";
		};
		player addWeapon "ACE_Flaregun";
	};
};
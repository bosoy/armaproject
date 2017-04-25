//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script automatically gives the unit or crate the equipment for:
// RTFA - Automatic Rifleman
//////////////////////////////////////////////////////////////////

//INIT
private ["_object"];
_object = _this select 0;
waitUntil {!(isNull _object)};
waitUntil {_object == _object};

//GEARING
if (_object isKindOf "Man") then {
  
  removeAllWeapons _object; removeAllItems _object;
  
    // primary weapon
      _object addWeapon "M249_EP1";
      
      _object addMagazine "ACE_200Rnd_556x45_T_M249";
      _object addMagazine "ACE_200Rnd_556x45_T_M249";
      _object addMagazine "ACE_200Rnd_556x45_T_M249";
      _object addMagazine "ACE_200Rnd_556x45_T_M249";
      _object addMagazine "ACE_200Rnd_556x45_T_M249";
      _object addMagazine "ACE_200Rnd_556x45_T_M249";
     
    // secondary weapons      
      _object addWeapon "glock17_EP1";
      _object addMagazine "17Rnd_9x19_glock17";
      _object addMagazine "17Rnd_9x19_glock17";
      _object addMagazine "17Rnd_9x19_glock17";
      _object addMagazine "17Rnd_9x19_glock17";
    
    // items
      _object addWeapon "NVGoggles";
      //_object addWeapon "Binocular";
      _object addWeapon "ACE_Map";
      _object addWeapon "ItemMap";
      //_object addWeapon "ItemGPS";
      _object addWeapon "ItemCompass";
      _object addWeapon "ItemWatch";
      _object addWeapon "ItemRadio";
      //_object addWeapon "ACE_Map_Tools";
      _object addWeapon "ACE_KeyCuffs";
      _object addWeapon "ACE_EarPlugs";
    
    // medical (2x)
      _object addmagazine "ACE_morphine"; _object addmagazine "ACE_morphine";
      _object addmagazine "ACE_epinephrine"; _object addmagazine "ACE_epinephrine";
      _object addmagazine "ACE_bandage"; _object addmagazine "ACE_bandage";
      
  _object action ["WEAPONONBACK", _object];
  
  } else {
  
    if (_this select 1 != 1) then {clearWeaponCargo _object; clearMagazineCargo _object;};

    // primary weapon
      _object addWeaponCargo ["M249_EP1",1];
      
      _object addMagazineCargo ["ACE_200Rnd_556x45_T_M249",6];

    // secondary weapons      
      _object addWeaponCargo ["glock17_EP1",1];
      _object addMagazineCargo ["17Rnd_9x19_glock17",8];
    
    // items
      _object addWeaponCargo ["NVGoggles",1];
      _object addWeaponCargo ["Binocular",1];
      //_object addWeaponCargo ["ACE_Map",1];
      _object addWeaponCargo ["ItemMap",1];
      //_object addWeaponCargo ["ItemGPS",1];
      _object addWeaponCargo ["ItemCompass",1];
      _object addWeaponCargo ["ItemWatch",1];
      _object addWeaponCargo ["ItemRadio",1];
      //_object addWeaponCargo ["ACE_Map_Tools",1];
      _object addWeaponCargo ["ACE_KeyCuffs",1];
      _object addWeaponCargo ["ACE_EarPlugs",1];
    
    // medical (2x)
      _object addMagazineCargo ["ACE_morphine",4];
      _object addMagazineCargo ["ACE_epinephrine",4];
      _object addMagazineCargo ["ACE_bandage",4];
      
};

//END
if (!isMultiplayer && isServer) then {player globalChat "DEBUG: Gearing RTFA_AR complete"};
if (true) exitWith{};
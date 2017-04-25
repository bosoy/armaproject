waitUntil {!(isNull player)};
waitUntil {player==player};

_people = _this select 0;

{
if ((_x isKindOf "US_Soldier_Engineer_EP1") OR (_x isKindOf "BAF_Soldier_EN_MTP")) then {
  _title  = "<t color='#00ff00' size='1.2' shadow='1' shadowColor='#000000' align='center'>SITREP</t><br/><br/>";
  _text   = "Repair the truck and get the engineer to drive it, then escort the UNO forces to HOTEL.";
  hint parseText (_title + _text);
};
} forEach _people;

if (true) exitWith {};
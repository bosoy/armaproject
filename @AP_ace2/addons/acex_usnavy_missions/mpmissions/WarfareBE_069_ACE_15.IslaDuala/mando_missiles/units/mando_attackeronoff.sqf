/* 
 mando ArmA missile attacked activate/detactivate
 mando_attackeronoff.sqf v1.0
 June 2007 Mandoble

 Orders one or several attackers to activate or deactivate its/their automatic missile system

 Parameters:
    attacker or array of attackers
    activate or deactivate system (true/false)

    Example:
    [[launcher1, launcher2], true]execVM"mando_missiles\units\mando_attackeronoff.sqf";
*/

private ["_attacker", "_action"];
_attacker = _this select 0;
_action   = _this select 1;



if (typeName _attacker == "OBJECT") then
{
   if (!isNull _attacker) then
   {
      _attacker setVariable ["mando_missileattacker_on", _action, true];
   };
}
else
{
   if (typeName _attacker == "ARRAY") then
   { 
      {  
         _x setVariable ["mando_missileattacker_on", _action, true];
      } forEach _attacker;
   };
};


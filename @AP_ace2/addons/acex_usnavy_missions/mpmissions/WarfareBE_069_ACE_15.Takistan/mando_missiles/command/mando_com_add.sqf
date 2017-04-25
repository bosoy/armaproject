/* 
 mando_com_add.sqf

 Adds a unit to the list of commanded units of a side
 Sep 2007 Mandoble
*/

private ["_unit", "_side"];

_unit = _this select 0;
_side = _this select 1;

switch (_side) do
{
   case west:
   {
      mando_remote_command = format["_match=false;{if (((_x select 0)==%1) && ((_x select 1)
 == %2))then{_match=true}} forEach mando_commanded_west;if(!_match)then{mando_commanded_west = mando_commanded_west + [%3]};", _unit select 0, _unit select 1, _unit];
      publicVariable "mando_remote_command";
   };

   case east:
   {
      mando_remote_command = format["_match=false;{if (((_x select 0)==%1) && ((_x select 1)
==%2))then{_match=true}} forEach mando_commanded_east;if(!_match)then{mando_commanded_east = mando_commanded_east + [%3]};", _unit select 0, _unit select 1, _unit];
      publicVariable "mando_remote_command";
   };

   case resistance:
   {
      mando_remote_command = format["_match=false;{if (((_x select 0)==%1) && ((_x select 1)
==%2))then{_match=true}} forEach mando_commanded_res;if(!_match)then{mando_commanded_res = mando_commanded_res + [%3]};", _unit select 0, _unit select 1, _unit];
      publicVariable "mando_remote_command";
   };

   case civilian:
   {
      mando_remote_command = format["_match=false;{if (((_x select 0)==%1) && ((_x select 1)
==%2))then{_match=true}} forEach mando_commanded_civ;if(!_match)then{mando_commanded_civ = mando_commanded_civ + [%3]};", _unit select 0, _unit select 1, _unit];
      publicVariable "mando_remote_command";
   };
};
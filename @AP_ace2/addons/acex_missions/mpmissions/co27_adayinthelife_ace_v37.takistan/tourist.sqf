if (!isServer) exitWith {};

_busy = 0;
_people = position euroman1 nearObjects 10;

{
if ((_busy == 0) && (side _x == WEST)) then {
  [euroman1] join group _x;
  hint "VIP ready for transport";
  _busy = 1;
};
} forEach _people;


if (true) exitWith {};
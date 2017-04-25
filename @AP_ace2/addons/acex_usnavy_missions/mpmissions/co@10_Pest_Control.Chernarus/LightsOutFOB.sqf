{_x switchLight "OFF"} forEach ((getPos FOB) nearObjects ["StreetLamp",500]);

_objHouse = nearestObjects [FOB, ["House"], 500];

{
	for "_i" from 1 to 5 do {
					
					_x animate [format ["Lights_%1",_i],0];
	};
} forEach _objHouse;
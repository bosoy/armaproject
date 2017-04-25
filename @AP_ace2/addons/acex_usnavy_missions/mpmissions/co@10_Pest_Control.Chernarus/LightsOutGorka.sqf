{_x switchLight "OFF"} forEach ((getPos Gorka) nearObjects ["StreetLamp",1500]);

_objHouse = nearestObjects [Gorka, ["House"], 1500];

{
	for "_i" from 1 to 5 do {
					
					_x animate [format ["Lights_%1",_i],0];
	};
} forEach _objHouse;
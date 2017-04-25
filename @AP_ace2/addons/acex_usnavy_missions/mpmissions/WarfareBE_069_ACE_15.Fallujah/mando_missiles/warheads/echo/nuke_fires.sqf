private [
	"_pos",
	"_fuel",
	"_b1",
	"_b2"
];

_pos = _this select 0;
_fuel = _this select 1;

sleep random 5.0;

_b2 = "Bomb" createVehicle _pos;
_b2 setPos _pos;
_b2 setFuelCargo _fuel;
_b1 = "M_Ch29_AT" createVehicle (_b2 modelToworld [0,0,0]);

sleep 600*random 300;

deleteVehicle _b2;

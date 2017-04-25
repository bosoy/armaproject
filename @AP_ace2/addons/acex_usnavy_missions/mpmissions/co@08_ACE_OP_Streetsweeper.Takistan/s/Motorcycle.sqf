_bike = _this select 1;

hint "Creating Motorcycle, Please wait.";
sleep 0.5;
hint "Creating Motorcycle, Please wait. .";
sleep 0.5;
hint "Creating Motorcycle, Please wait. . .";
sleep 0.5;
hint "Creating Motorcycle, Please wait. . . .";

_bike = "TT650_TK_CIV_EP1" createVehicle (position player);
_bike setDir getDir player;
sleep 0.01;
player moveInDriver _bike;
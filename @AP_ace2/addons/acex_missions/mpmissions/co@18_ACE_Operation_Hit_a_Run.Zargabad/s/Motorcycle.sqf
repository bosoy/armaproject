_bike = _this select 1;

hint "Creating ATV, Please wait.";
sleep 0.5;
hint "Creating ATV, Please wait. .";
sleep 0.5;
hint "Creating ATV, Please wait. . .";
sleep 0.5;
hint "Creating ATV, Please wait. . . .";

_bike = "ATV_US_EP1" createVehicle (position player);
_bike setDir getDir player;
sleep 0.01;
player moveInDriver _bike;
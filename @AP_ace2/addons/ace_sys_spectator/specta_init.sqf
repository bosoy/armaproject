#include "script_component.hpp"
// Connect handler for spectating script, check if camera on seagull for first 10 seconds and launch spectating script
for "_i" from 0 to 20 do {
	if (!isNil QGVAR(no_seagull_spectating)) exitWith {};
	if (typeof cameraOn == "SeaGull") exitWith {[cameraOn,cameraOn,cameraOn] spawn COMPILE_FILE(specta)};
	sleep 0.5;
};

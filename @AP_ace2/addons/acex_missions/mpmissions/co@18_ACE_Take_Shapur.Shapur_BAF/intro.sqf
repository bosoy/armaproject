// Loadingtext
if (time < 10) then
{
	sleep 5;
    [] Spawn {
        waitUntil{!(isNil "BIS_fnc_init")};
        
        // Info text
        [str("Moerderhoschi presents") , str("[co18] Take Shapur")] spawn BIS_fnc_infoText;
        
        sleep 10;
    };
};
// Loadingtext
if (time < 10) then
{
	sleep 5;
    [] Spawn {
        waitUntil{!(isNil "BIS_fnc_init")};
        
        // Info text
        [str("Moerderhoschi presents") , str("[co08] OP Streetsweeper")] spawn BIS_fnc_infoText;
        
        sleep 10;
    };
};
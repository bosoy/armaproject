// Loadingtext
if (time < 10) then
{
    titleCut ["", "BLACK FADED", 999];
	sleep 15;
    [] Spawn {
        waitUntil{!(isNil "BIS_fnc_init")};
        
        // Info text
        [str("Moerderhoschi presents") , str("[co18] Operation Hit&Run")] spawn BIS_fnc_infoText;
        
        sleep 10;
        
        titleCut ["", "BLACK IN", 5]
    };
};
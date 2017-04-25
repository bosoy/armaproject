private ["_target", "_weapon", "_lockflag", "_testflag", "_sleep", "_topleft", "_bottomright"];

DisableSerialization;

// mando_hud_coords = [[-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2], [-2, -2]];
// mando_hud_colors = [[0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5], [0.5, 0.5, 0.5]];
mando_hud_aperture = 0.03;
mando_hud_max_alpha = 0.0;

	
while {!mando_exit_hud} do 
{
    if (cameraView != "GUNNER") then
	{
		mando_hud_max_alpha = 0;
	}
	else
	{
		mando_hud_max_alpha = 1.0;
	};
	
	Sleep 0.25;
};

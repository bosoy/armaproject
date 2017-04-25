_activateplayernvg = false;

if (daytime > 19.75 || daytime < 6.0) then {
	_activateplayernvg = true;
};

if (_activateplayernvg) then {
	player action ["NVGoggles",player];
};
playmusic "Short01_Defcon_Three";
sleep 8.0;
titleRsc ["SFtiteltext2", "PLAIN"];
sleep 5.0;
titleRsc ["SFtiteltext", "PLAIN"];
sleep 5.0;
TitleRsc["GFLogo","PLAIN"];

if (true) exitWith {};
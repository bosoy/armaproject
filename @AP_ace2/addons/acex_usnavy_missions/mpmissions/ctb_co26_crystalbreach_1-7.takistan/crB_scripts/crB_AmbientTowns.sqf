//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20100803
// Contact: http://creobellum.org
// Purpose: Setup MP compatible ambient town sounds
// Usage: 0 = [array of locs] execVM "crB_scripts\crB_AmbientTowns.sqf";
///////////////////////////////////////////////////////////////////
_locs = _this select 0;
_dist = 200;

_sounds = ["arabian_market_1", "arabian_market_2", "arabian_market_3", "arabian_market_4", "Muslim_prayer1", "Muslim_prayer2"];

//for each of the towns
{
	_snd = _sounds select floor(random count _sounds);
	_pos = position _x;
	_trg = createTrigger ["EmptyDetector", _pos];
	_trg setTriggerArea [_dist, _dist, 0, false];
	_trg setTriggerActivation ["WEST", "PRESENT", true];
	_trg setSoundEffect ["Env102", "", "", _snd];
} forEach _locs;
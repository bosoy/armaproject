/* ace_sys_spacebar | (c) 2009 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __MAXRECOGNIZEDISTANCE 30 // 60 Meter, BI setzt hier "unendlich" ein

private ["_target", "_viewDistance", "_distance", "_side", "_type", "_name", "_params"];

if (ACE_NO_RECOGNIZE || {!alive player}) exitWith {};

// Exit if not SPACEBAR Scanning and Spacebar desired key
if ( GVAR(spacebar) && {!((_this select 1) in actionKeys "forceCommandingMode")} ) exitWith {};

if (ace_sys_spectator_SPECTATINGON) exitWith {};

// Spieler im Fahrzeug
if (player != vehicle player) exitWith {
	(vehicle player) call FUNC(recognize_crew);
};

// Target player is holding crosshair on, when pressing spacebar/mousewheel moving
_target = cursorTarget;

//  Target does not exist or dead
if (isNull _target) exitWith { false; TRACE_1("No target found",""); };
if !(alive _target) exitWith { false; TRACE_1("Target dead",""); };

// Valve
if (GVAR(presstime) == time) exitwith { false };
GVAR(presstime) = time;

// Sichtweitenbestimmung abhängig der Wetterverhältnisse (Nebel)
_viewDistance = ((viewDistance/(viewDistance / 1200)) * (1-fog)); // Normalize VD upon base of 1200m - Reduce foggyness

// Entfernung zum Objekt
_distance = player distance _target;

// Abbruch wenn Sichtweite kleiner als die Entfernung ist
// oder wenn Entfernung größer als Erkennungsdistanz ist
if (_viewDistance < _distance) exitWith { false; TRACE_2("Viewdistance is to small",_viewDistance,_distance); };
if (_distance > __MAXRECOGNIZEDISTANCE) exitWith { false; TRACE_1("Target is too far away",""); };

// Verbündetenbestimmung
// Feindliche Einheiten werden nicht dargestellt
// Unbekannte Einheiten werden nicht dargestellt
_side = _target call FUNC(recognize_side);
if (_side == "HOSTILE") exitWith { false }; // Nur Verbündete werden dargestellt

// Typenbestimmung
// Bei Panzern wird es nur möglich sein Insassen zu erkennen sobald diese aus ihrer Luke herausschauen
// Alle anderen Fahrzeuge erlauben es auch Insassen zu erkennen (unabhängig von der Blickrichtung)
_type = _target call FUNC(recognize_type);
if (_type == "EXIT") exitWith { false }; // Kein Fahrzeug

// Namensdarstellung
_name = [_target,_type] call FUNC(recognize_name);

// Bildschirmdarstellung
_params = [];
{ PUSH(_params,_x) } forEach _name;
{ PUSH(_params,_x) } forEach [_target,__MAXRECOGNIZEDISTANCE];
_params spawn FUNC(recognize_display);

false

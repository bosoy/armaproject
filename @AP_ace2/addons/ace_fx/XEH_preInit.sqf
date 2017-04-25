#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

PREP(ring); // Ear Ring Effect
PREP(knockout); // Knockout
PREP(dizzy); // Dizzyness, Camshake - Alternative if Difficulty "Camshake" is disabled
PREP(deaf); // Deafen
PREP(cough); // Play coughing sounds
PREP(blurry); // Blur screen
PREP(blind); // Blind (Flash + Blurry)
PREP(blind_view); // Blind eyes
PREP(flash); // Flash
PREP(kick); // Kick head back

[QGVAR(ranim), {(_this select 0) switchMove (_this select 1)}] call CBA_fnc_addEventHandler;

ADDON = true;

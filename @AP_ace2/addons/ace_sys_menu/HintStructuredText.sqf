#include "script_component.hpp"
// Desc: Structured text hint example
//-----------------------------------------------------------------------------

// some structured text constants
_linebreak = "<br/>";
_color_black = "<t color = '#f0000000'>";
_color_white = "<t color = '#f0ffffff'>";
_color_red = "<t color = '#f0ff0000'>";
_color_green = "<t color = '#f000ff00'>";
_color_blue = "<t color = '#f00000ff'>";
_text_size = "<t size = '%1'>";
_text_normal = "</t>";
_image = "<img image = '%1'/>";

//-----------------------------------------------------------------------------
// example 1 - using composeText with parseText parameters
_StructuredText =
  composeText [
    "Hint 1 (using composeText): ", linebreak,
    linebreak,
    parseText (_color_green+"Action: "+_text_normal), image "\CA\ui\data\ui_action_repair_ca.paa", linebreak,
    parseText (_color_green+"Health: "+_text_normal), "injured", " ", image "\CA\ui\data\ui_action_heal_ca.paa"];

hint _StructuredText;
sleep 2;

//-----------------------------------------------------------------------------
// example 2 - using parseText. Demonstrates text & image enlarging.
_StructuredString =
  "Hint 2 (using parseText): "+_linebreak+
  _linebreak+
  _color_green+"Action: "+_text_normal+format[_image, "\CA\ui\data\ui_action_repair_ca.paa"]+_linebreak+
  format[_text_size, 1.9]+_color_green+"Health: "+_text_normal+_color_red+"injured"+_text_normal+" "+format[_image, "\CA\ui\data\ui_action_heal_ca.paa"]+_text_normal;

_StructuredText = parseText _StructuredString;

hint _StructuredText;
sleep 2;

//-----------------------------------------------------------------------------
// example 3 - using composeText

// vehicle stats: fuel, etc
_vehicle = player; // fake "vehicle"
_noAmmo = "0%"; if ((count weapons _vehicle > 0) && {(someAmmo _vehicle)}) then { _noAmmo = "some" };

_StructuredText = composeText
[
  "Hint 3 (using composeText): ", linebreak,
  linebreak,

  image "\CA\ui\data\ui_action_repair_ca.paa",
  format[" %1", round((1.0 - (damage _vehicle)) * 100) ]+"%", linebreak,

  image "\CA\ui\data\ui_action_refuel_ca.paa",
  format[" %1", round((fuel _vehicle) * 100) ]+"%", linebreak,

  image "\CA\ui\data\ui_action_reammo_ca.paa",
  format[" %1", _noAmmo ], linebreak,

  image "\CA\ui\data\ui_action_heal_ca.paa",
  format[" %1", round(1-(damage player))*100]+"%"
];

hint _StructuredText;
//-----------------------------------------------------------------------------

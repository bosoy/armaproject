//#define __DEBUG__
#define THIS_FILE "x_tasks.sqf"
#include "x_setup.sqf"
private "_current_target_index";

__TRACE("Before !isNull player")
waitUntil {!isNull player};
__TRACE("After !isNull player")
__TRACE("Before !isNil MaxNumAmmoboxes")
waitUntil {!isNil QGVAR(MaxNumAmmoboxes)};
__TRACE("After !isNil MaxNumAmmoboxes")

_dompic = "pics\dtwo.paa";
#define __BR "<br/>"
#define __BRBR "<br/><br/>"

_briefing = format [(localize "STR_DOM_MISSIONSTRING_23") + __BR + 
"  <img image='pics\domination.paa' width='300' height='40' />     <img image='" + _dompic + "' width='50' height='50' />" + __BRBR +
(localize "STR_DOM_MISSIONSTRING_24") + __BR + 
(localize "STR_DOM_MISSIONSTRING_25") + __BR + __BRBR +
(localize "STR_DOM_MISSIONSTRING_26") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_27") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_28") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_29") + __BR +
(localize "STR_DOM_MISSIONSTRING_30") + __BR +
(localize "STR_DOM_MISSIONSTRING_31") + __BR +
(localize "STR_DOM_MISSIONSTRING_32") + __BR +
(localize "STR_DOM_MISSIONSTRING_33") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_34") + __BR +
(localize "STR_DOM_MISSIONSTRING_35") + __BR +
(localize "STR_DOM_MISSIONSTRING_36") + __BR +
(localize "STR_DOM_MISSIONSTRING_37") + __BR +
(localize "STR_DOM_MISSIONSTRING_38") + __BRBR
,
#ifndef __TT__
GVAR(MaxNumAmmoboxes)
#else
format [(localize "STR_DOM_MISSIONSTRING_39"), GVAR(MaxNumAmmoboxes)]
#endif
];

_briefing = _briefing + (localize "STR_DOM_MISSIONSTRING_40") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_41") + __BR +
(localize "STR_DOM_MISSIONSTRING_42") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_43") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_44") + __BR +
(localize "STR_DOM_MISSIONSTRING_45") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_46") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_47") + __BR +
(localize "STR_DOM_MISSIONSTRING_48") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_49") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_50") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_51") + __BR +
(localize "STR_DOM_MISSIONSTRING_52") + __BR +
(localize "STR_DOM_MISSIONSTRING_53") + __BR +
(localize "STR_DOM_MISSIONSTRING_54") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_55") + __BR +
(localize "STR_DOM_MISSIONSTRING_56") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_57") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_58") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_59") + __BR +
(localize "STR_DOM_MISSIONSTRING_60") + __BRBR +
(localize "STR_DOM_MISSIONSTRING_61");

_diary1 = player createDiaryRecord ["Diary", ["Briefing",_briefing]];

waitUntil {!isNil {__XJIPGetVar(GVAR(current_target_index))}};
_current_target_index = __XJIPGetVar(GVAR(current_target_index));

GVAR(task1) = player createSimpleTask ["obj1"];
GVAR(task1) setSimpleTaskDescription [(localize "STR_DOM_MISSIONSTRING_62"),(localize "STR_DOM_MISSIONSTRING_62"),(localize "STR_DOM_MISSIONSTRING_62")];
if (_current_target_index == -1) then {
	GVAR(task1) settaskstate "Created";
} else {
	GVAR(task1) settaskstate "Succeeded";
};



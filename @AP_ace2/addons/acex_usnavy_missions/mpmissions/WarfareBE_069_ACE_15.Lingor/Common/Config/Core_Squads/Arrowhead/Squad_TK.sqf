Private ['_aiTeamTemplateRequires','_aiTeamTemplates','_aiTeamTypes','_aiTeamUpgrades','_d','_f','_l','_u'];

_aiTeamTemplates = [];
_aiTeamTemplateRequires = [];
_aiTeamTypes = [];
_aiTeamUpgrades = [];

_d		= ["Infantry - Infantry Squad"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_Spotter_EP1"];
_u = _u + ["TK_Soldier_AR_EP1"];
_u = _u + ["TK_Soldier_GL_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,false,false,false];
_l 		= [0,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d + ["Infantry - Infantry Section"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["TK_Soldier_AR_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_GL_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,false,false,false];
_l 		= [1,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Infantry Section (AT)"];
_u 		= ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,false,false,false];
_l 		= [1,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Infantry Section (HAT)"];
_u		= ["TK_Soldier_HAT_EP1"];
_u = _u + ["TK_Soldier_HAT_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,false,false,false];
_l 		= [3,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Infantry Section (AA)"];
_u		= ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,false,false,false];
_l 		= [2,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Infantry Section (AA/AT)"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,false,false,false];
_l 		= [2,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Infantry Section (MG)"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_GL_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_f 		= [true,false,false,false];
_l 		= [1,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Snipers Team"];
_u		= ["TK_Soldier_Spotter_EP1"];
_u = _u + ["TK_Soldier_Sniper_EP1"];
_f 		= [true,false,false,false];
_l 		= [2,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Infantry - Special Ops Team"];
_u		= ["TK_Special_Forces_EP1"];
_u = _u + ["TK_Special_Forces_TL_EP1"];
_u = _u + ["TK_Special_Forces_MG_EP1"];
_f 		= [true,false,false,false];
_l 		= [3,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [0];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Motorized Infantry - Motorized Infantry Squad"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["V3S_TK_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_Spotter_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_AR_EP1"];
_u = _u + ["TK_Soldier_GL_EP1"];
_u = _u + ["TK_Soldier_EP1"];
_f 		= [true,true,false,false];
_l 		= [1,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [1];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Motorized Infantry - Motorized Patrol Section"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["BRDM2_TK_EP1"];
_f 		= [true,true,false,false];
_l 		= [0,1,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [1];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Mechanized Infantry - Motor Rifles (BMP)"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["BMP2_TK_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_GL_EP1"];
_f 		= [true,false,true,false];
_l 		= [1,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [2];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Mechanized Infantry - Motor Rifles (BTR)"];
_u		= ["TK_Soldier_SL_EP1"];
_u = _u + ["BTR60_TK_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_AT_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_GL_EP1"];
_f 		= [true,true,false,false];
_l 		= [1,2,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [1];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Armor - IFV Platoon (Light)"];
_u		= ["BMP2_TK_EP1"];
_u = _u + ["BMP2_TK_EP1"];
_f 		= [false,false,true,false];
_l 		= [0,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [2];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Armor - Anti Air Platoon"];
_u		= ["ZSU_TK_EP1"];
_u = _u + ["ZSU_TK_EP1"];
_f 		= [false,false,true,false];
_l 		= [0,0,1,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [2];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Armor - Tank Platoon (Light)"];
_u		= ["T55_TK_EP1"];
_u = _u + ["T55_TK_EP1"];
_f 		= [false,false,true,false];
_l 		= [0,0,1,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [2];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Armor - Tank Platoon (Heavy)"];
_u		= ["T72_TK_EP1"];
_u = _u + ["T72_TK_EP1"];
_f 		= [false,false,true,false];
_l 		= [0,0,2,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [2];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Air - Mi-17 Squadron"];
_u		= ["Mi17_TK_EP1"];
_u = _u + ["TK_Soldier_SL_EP1"];
_u = _u + ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_AA_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_LAT_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_u = _u + ["TK_Soldier_MG_EP1"];
_f 		= [true,false,false,true];
_l 		= [2,0,0,0];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [3];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Air - Mi-24 Squadron"];
_u		= ["Mi24_D_TK_EP1"];
_u = _u + ["Mi24_D_TK_EP1"];
_f 		= [false,false,false,true];
_l 		= [0,0,0,1];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [3];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Air - L39 Squadron"];
_u		= ["L39_TK_EP1"];
_u = _u + ["L39_TK_EP1"];
_f 		= [false,false,false,true];
_l 		= [0,0,0,2];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [3];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

_d = _d	+ ["Air - Sukhoi 25 Squadron"];
_u		= ["Su25_TK_EP1"];
_u = _u + ["Su25_TK_EP1"];
_f 		= [false,false,false,true];
_l 		= [0,0,0,3];

_aiTeamTemplates = _aiTeamTemplates + [_u];
_aiTeamTemplateRequires = _aiTeamTemplateRequires + [_f];
_aiTeamTypes = _aiTeamTypes + [3];
_aiTeamUpgrades = _aiTeamUpgrades + [_l];

[_aiTeamTemplates,_aiTeamTemplateRequires,_aiTeamTypes,_aiTeamUpgrades,_d]
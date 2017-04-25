/*******************************************************************************
* BMD initialization                                                           *
*                                                                              *
* @param  object _bmd - BMD Object                                             *
* @return void                                                                 *
*                                                                              *
********************************************************************************
*                                                                              *
* $Id:: BMDinit.sqf 209 2010-03-09 16:01:51Z ist                            $: *
* author: ist <ist@redhammer.su>                                               *
*                                                                              *
* LICENSE:  This  program  is  free  software:  you can redistribute it and/or *
* modify it under the terms of the  GNU General Public License as published by *
* the Free Software Foundation, either version 3 of the License,  or  (at your *
* option) any later version.                                                   *
* This program is  distributed in the hope that it will be useful, but WITHOUT *
* ANY  WARRANTY;   without  even  the  implied  warranty of MERCHANTABILITY or *
* FITNESS FOR A PARTICULAR PURPOSE.   See  the  GNU General Public License for *
* more details.                                                                *
* You should have received a copy of the GNU General Public License along with *
* this program. If not, see <http://www.gnu.org/licenses/gpl.txt>.             *
*                                                                              *
*******************************************************************************/
#include "\x\acex\addons\c_veh_btr70\script_component.hpp"
private ["_btr","_path","_boardNum","_class","_habartype"];
PARAMS_1(_btr);

_habartype = 2;

if (isNil "cBTRFuncLoaded") then
{
	cBTRFuncLoaded = true;
	cBTRAddonName  = "x\acex\addons\c_veh_btr70";
	//cBTRVehicles             = ["sa_bmd2","sa_bmd2_rus1","sa_bmd2_rus2","sa_bmd2_rus3","sa_bmd2_rus4","sa_bmd2_des","sa_bmd2_ua","sa_bmd2_peace","sa_bmd2_cdf","sa_bmd2_chdkz","sa_bmd2k","sa_bmd2k_rus1","sa_bmd2k_rus2","sa_bmd2k_rus3","sa_bmd2k_rus4","sa_bmd2k_des","sa_bmd2k_peace"];
	//cBTRHasVariableClearance = ["sa_bmd2","sa_bmd2_rus1","sa_bmd2_rus2","sa_bmd2_rus3","sa_bmd2_rus4","sa_bmd2_des","sa_bmd2_ua","sa_bmd2_peace","sa_bmd2_cdf","sa_bmd2_chdkz","sa_bmd2k","sa_bmd2k_rus1","sa_bmd2k_rus2","sa_bmd2k_rus3","sa_bmd2k_rus4","sa_bmd2k_des","sa_bmd2k_peace"];
	cBTR3NumberPlaces = [9,10,11]; // Places for number
	cBTR2NumberPlaces = [10,11]; // Places for number
	cBTR2SideRoundelPlaces = [20]; // Places for 2 hull side roundels
	cBTRFrontPlatePlaces = [21]; // Places for front roundel
	cBTR4NumberPlaces = [12,13,14,15]; // Places for 4 number
	cBTRCDF4NumberPlaces = [16,17,18,19]; // Places for number
	cBTROMONSymbolPlaces = [2];   // Places for omon symbols
	cBTRBackArmSymPlaces = [4];     // Places for back army symbol
	cBTRFlagSymPlaces = [5];     // Places for back army symbol
	cBTRLeftGvardSymPlaces = [6];     // Places for back army symbol
	cBTRRightGvardSymPlaces = [7];     // Places for back army symbol
	cBTRPlnSymPlaces = [3,8];     // Places for platoon symbol
	//cBTRPlnRandSymPlaces = [8];     // Places for platoon symbol
};
/*******************************************************************************
* Paint & Spray =)                                                             *
*******************************************************************************/
private ["_params","_gvard1","_gvard2","_gvard3"];
_class = typeOf _btr;
_gvard1 = ["Label", cBTRBackArmSymPlaces, "Army", [6,1]];
_gvard2 = ["Label", cBTRLeftGvardSymPlaces, "Army", [6,1]];
_gvard3 = ["Label", cBTRRightGvardSymPlaces, "Army", [6,1]];

// RHS_Decals main script path:
_decal = "\RHS_Decals\Scripts\init.sqf";

// _btr animate ["driverViewHatch",1];
// _btr animate ["commanderViewHatch",1];

if ( (floor(random 100)) > 80) then {
	_gvard1 = ["Label", cBTRBackArmSymPlaces, "Army", 1];
}else{
	_gvard1 = ["Label", cBTRBackArmSymPlaces, "Army", 0];
};
if ( (floor(random 100)) > 80) then {
	_gvard2 = ["Label", cBTRLeftGvardSymPlaces, "Army", 1];
}else{
	_gvard2 = ["Label", cBTRLeftGvardSymPlaces, "Army", 0];
};
if ( (floor(random 100)) > 80) then {
	_gvard3 = ["Label", cBTRRightGvardSymPlaces, "Army", 1];
}else{
	_gvard3 = ["Label", cBTRRightGvardSymPlaces, "Army", 0];
};

switch (_class) do {
	case "ACE_BTR70_RU":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",8],    // Set Platoon
				_gvard1,  // Set Army symbol 2
				_gvard2,  // Set Army symbol 2
				_gvard3  // Set Army symbol 2
			]
		];
		_habartype = 2;
	};
	case "ACE_BTR70_RU_D":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",9],    // Set Platoon
				["Label", cBTRBackArmSymPlaces, "Army", [3,0]],
				["Label", cBTRLeftGvardSymPlaces, "Army", [3,2]],
				["Label", cBTRRightGvardSymPlaces, "Army", [3,2]]
			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_rus1":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",3],    // Set Platoon
				_gvard1,  // Set Army symbol 2 (VDV)
				_gvard2,  // Set Army symbol 2 (VDV)
				_gvard3  // Set Army symbol 2 (VDV)
			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_rus2":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",3],    // Set Platoon
				_gvard1,  // Set Army symbol 2 (VDV)
				_gvard2,  // Set Army symbol 2 (VDV)
				_gvard3  // Set Army symbol 2 (VDV)
			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_des":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				//["Label", cBTRPlnSymPlaces, "Platoon",3],
				["Label", cBTRLeftGvardSymPlaces, "Honor"],  // Set Army symbol 2 (VDV)
				["Label", cBTRRightGvardSymPlaces, "Honor"]  // Set Army symbol 2 (VDV)
			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_peace":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"]  // Set number (random)
			]
		];
	};
	case "rhs_btr70_peace2":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTR2SideRoundelPlaces, "Army",[16,0]],
				["Label", cBTRFrontPlatePlaces, "Army",[16,0]],
				["Label", cBTRLeftGvardSymPlaces, "Army",[16,0]],
				["Label", cBTRRightGvardSymPlaces, "Army",[16,0]],
				["Label", cBTRBackArmSymPlaces, "Army",[16,0]]
			]
		];
	};
	case "rhs_btr70_ichk":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTR2SideRoundelPlaces, "Army",[21,0]],
				["Label", cBTRFrontPlatePlaces, "Army",[21,0]],
				["Label", cBTRBackArmSymPlaces, "Army",[21,0]]
			]
		];
		_habartype = 0;
	};
	case "rhs_btr70_vmf1":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",9],    // Set Platoon
				["Label", cBTRFlagSymPlaces, "Army",3]    // Set Platoon

			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_vmf2":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",9],    // Set Platoon
				["Label", cBTRFlagSymPlaces, "Army",3]   // Set Platoon

			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_vmf3":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",9],    // Set Platoon
				["Label", cBTRFlagSymPlaces, "Army",3]    // Set Platoon

			]
		];
		_habartype = 2;
	};
	case "rhs_btr70_omon1":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTROMONSymbolPlaces, "Army",11],    // Set Platoon
				["Label", cBTRBackArmSymPlaces, "Army",11]  // Set Army symbol 2 (VDV)
			]
		];
		_habartype = 0;
	};
	case "rhs_btr70_omon2":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTROMONSymbolPlaces, "Army",12],    // Set Platoon
				["Label", cBTRBackArmSymPlaces, "Army",12]  // Set Army symbol 2 (VDV)
			]
		];
		_habartype = 0;
	};
	case "rhs_btr70_omon3":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTROMONSymbolPlaces, "Army",11],    // Set Platoon
				["Label", cBTRBackArmSymPlaces, "Army",11]  // Set Army symbol 2 (VDV)
			]
		];
		_habartype = 0;
	};
	case "ACE_BTR70_TK":{
		_params = [
			_btr,
			[
				["Number", cBTR3NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRFlagSymPlaces, "Army",17],    // Set Platoon
				["Label", cBTRBackArmSymPlaces, "Army",17]  // Set Army symbol 2
			]
		];
		_habartype = 0;
	};
	case "rhs_btr70_nva":{
		_params = [
			_btr,
			[
				["Number", cBTR4NumberPlaces, "Default"],
				["Label", cBTRLeftGvardSymPlaces, "Army", [23,0]],  // Set Army symbol 2
				["Label", cBTRRightGvardSymPlaces, "Army", [23,0]],  // Set Army symbol 2
				["Label", cBTRBackArmSymPlaces, "PlatoonGDR"]
			]
		];
		_habartype = 0;
	};
	case "rhs_btr70_belarus":{
		_params = [_btr,[["Number", cBTR3NumberPlaces, "Default"]]];
		_habartype = 0;
	};
	case "ACE_BTR70_CDF":{
		_params = [_btr,[["Number", cBTRCDF4NumberPlaces, "CDF"]]];
		_habartype = 0;
	};
	case "ACE_BTR70_UN":{
		_params = [_btr,[["Number", cBTR4NumberPlaces, "CDF"]]];
		_habartype = 0;
	};
	case "ACE_BTR70_INS":{
		_params = [_btr,[["Number", cBTR3NumberPlaces, "Handpaint"]]];
		_habartype = 0;
	};
	case "ACE_BTR70_GUE": {
		_params = [_btr,[["Number", cBTR2NumberPlaces, "HandpaintBlack"]]];
		_habartype = 0;
	};
	case "rhs_btr70": {
		_params = [
			_btr,
			[
				["Number", cBTR4NumberPlaces, "Default"],  // Set number (random)
				["Label", cBTRPlnSymPlaces, "Platoon",3],    // Set Platoon
				["Label", cBTRLeftGvardSymPlaces, "Honor"],  // Set Army symbol 2 (VDV)
				["Label", cBTRRightGvardSymPlaces, "Honor"]  // Set Army symbol 2 (VDV)
			]
		];
	};
	default {
		_params = [_btr,[]];
		_habartype = 0;
	};
};
private ["_h"];
//_h = _params execVM _decal; // Paint vehicle
_h = _params spawn COMPILE_FILE2(\RHS_Decals\Scripts\init.sqf); // Paint vehicle

//Habar
private ["_habarScr"];
_habarScr = [_btr,_habartype] spawn COMPILE_FILE2(\x\acex\addons\c_veh_btr70\scripts\bgr_btr_habar.sqf);

//Hatches
private ["_hatchScr"];
rhs_activeAutoHatches = false;
_hatchScr = [_btr] spawn COMPILE_FILE2(\x\acex\addons\c_veh_btr70\scripts\bgr_btr_hatch.sqf);

//Retread
private ["_RetreadScr"];
_RetreadScr = [_btr] spawn COMPILE_FILE2(\x\acex\addons\c_veh_btr70\scripts\bgr_btr_retread.sqf);

// Special FX secton
if (isNil "BTR70_Effects_Init") then {
	BTR70_Effects_Init = true;
	BTR70_Effects_EH_Fired = nil; //COMPILE_FILE2(\ca\Data\ParticleEffects\SCRIPTS\fired.sqf);
	BTR70_Effects_EH_Killed = nil; //COMPILE_FILE2(\ca\Data\ParticleEffects\SCRIPTS\killed.sqf);
	BTR70_Effects_HeavyCaliber=COMPILE_FILE2(\x\acex\addons\c_veh_btr70\scripts\heavycaliber.sqf);
};

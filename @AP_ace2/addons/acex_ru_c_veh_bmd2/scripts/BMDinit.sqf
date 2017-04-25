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

#include "\x\acex_ru\addons\c_veh_bmd2\script_component.hpp"

private ["_bmd","_path","_boardNum","_class","_habartype"];
_bmd = _this select 0;

_habartype = 2;

if (isNil "cBMD2FuncLoaded") then
{
	cBMD2FuncLoaded = true;
	cBMD2AddonName  = "sa_bmd2";
	cBMD2Vehicles             = ["ACE_BMD_2_RU","ACE_BMD_2_RUS1","ACE_BMD_2_RUS2","ACE_BMD_2_RUS3","ACE_BMD_2_RUS4","ACE_BMD_2_DES","ACE_BMD_2_UA","ACE_BMD_2_PEACE","ACE_BMD_2_CDF","ACE_BMD_2_CHDKZ","ACE_BMD_2K_RU","ACE_BMD_2K_RUS1","ACE_BMD_2K_RUS2","ACE_BMD_2K_RUS3","ACE_BMD_2K_RUS4","ACE_BMD_2K_DES","ACE_BMD_2K_PEACE"];
	cBMD2HasVariableClearance = ["ACE_BMD_2_RU","ACE_BMD_2_RUS1","ACE_BMD_2_RUS2","ACE_BMD_2_RUS3","ACE_BMD_2_RUS4","ACE_BMD_2_DES","ACE_BMD_2_UA","ACE_BMD_2_PEACE","ACE_BMD_2_CDF","ACE_BMD_2_CHDKZ","ACE_BMD_2K_RU","ACE_BMD_2K_RUS1","ACE_BMD_2K_RUS2","ACE_BMD_2K_RUS3","ACE_BMD_2K_RUS4","ACE_BMD_2K_DES","ACE_BMD_2K_PEACE"];
	cBMD2NumberPlaces = [0,1,2]; // Places for number
	cBMD2SymbolPlaces = [3,4];   // Places for symbols
	cBMD2ArmSymPlaces = [3];     // Places for army symbol
	cBMD2PlnSymPlaces = [4];     // Places for platoon symbol
	fBMD2SetClearance = compile (
		preprocessFileLineNumbers format [
			"\x\acex_ru\addons\c_veh_bmd2\Scripts\functions\%2.sqf",
			cBMD2AddonName,
			"setClearance"
		]
	);
};
/*******************************************************************************
* Paint & Spray =)                                                             *
*******************************************************************************/
private ["_params"];
_class = typeOf _bmd;

// RHS_Decals main script path:
_decal = "\RHS_Decals\Scripts\init.sqf";

switch (_class) do
{
	case "ACE_BMD_2_RU":
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Default"], // Set number (random)
				["Label", cBMD2ArmSymPlaces, "Army", 2],  // Set Army symbol 2 (VDV)
				["Label", cBMD2PlnSymPlaces, "PlatoonVDV"]   // Set platoon sign (random)
			]
		];
	};
/*	case "ace_bmd2_ua":
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Default"],  // Set number (random)
				["Label", cBMD2ArmSymPlaces, "Army", 5],    // Set Army symbol 5 (Ukraine)
				["Label", cBMD2PlnSymPlaces, "PlatoonVDV",0]   // Set platoon sign (random)
			]
		];
		_habartype = 0;
	};
	case "ace_bmd2_peace":
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Default"]  // Set number (random)
			]
		];
	};
*/
	case "ACE_BMD_2_CDF":
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "CDF"]  // Set number (random)
			]
		];
		_habartype = 0;
	};
	case "ACE_BMD_2_INS":
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Handpaint"]  // Set number (random)
			]
		];
		_habartype = 0;
	};
/*	case "ace_bmd2k_peace":
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Default"]  // Set number (random)
			]
		];
	};
*/
	default
	{
		_params = [
			_bmd,
			[
				["Number", cBMD2NumberPlaces, "Default"], // Set number (random)
				["Label", cBMD2ArmSymPlaces, "Army", 2],  // Set Army symbol 2 (VDV)
				["Label", cBMD2PlnSymPlaces, "PlatoonVDV"]   // Set platoon sign (random)
			]
		];
	};
};
private ["_h"];
_h = _params spawn COMPILE_FILE2(\RHS_Decals\Scripts\init.sqf); // Paint vehicle

/*******************************************************************************
* Habar				                                                         *
*******************************************************************************/
_habarScr = [_bmd,_habartype] spawn COMPILE_FILE2(\x\acex_ru\addons\c_veh_bmd2\scripts\bgr_bmd_habar.sqf);

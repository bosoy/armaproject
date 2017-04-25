/*******************************************************************************
* Index file.                                                                  *
********************************************************************************
*                                                                              *
* $Id:: index.sqf 2 2010-08-16 16:45:20Z ist                                $: *
* author: ist <ist@redhamer.su>                                                *
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
scriptName "HonorIndex";
private ["_index"];
_index = [
	[["no_ca.paa"]],		// Clear
	[						// Guard sign
		["guard_ca.paa"],
		[
			"su_guardia01_ca.paa",
			"su_guardia02_ca.paa",
			"su_guardia03_ca.paa"
		]
	]
];
_index 
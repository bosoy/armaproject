/*******************************************************************************
* Index file.                                                                  *
********************************************************************************
*                                                                              *
* $Id:: index.sqf 47 2010-08-27 01:59:55Z ist                               $: *
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
scriptName "PlatoonIndex";
private ["_index"];
_index = [
	[["no_ca.paa"]],			//   0 Clear
	[["circle_ca.paa"]],		//   1 Circle (target)
	[["square4_ca.paa"]],		//   2 Square with number
	[["triangle_d6_ca.paa"]],	//   3 Triangle (male) with number
	[["triangle_u3_ca.paa"]],	//   4 Triangle (female) with number
	[							//   5 Horizontal rhomb
		["romb_cl01_ca.paa","romb_cl02_ca.paa","romb_cl03_ca.paa"],
		["romb_dt01_ca.paa","romb_dt02_ca.paa","romb_dt03_ca.paa"],
		["romb_a01_ca.paa","romb_a02_ca.paa","romb_a03_ca.paa"]
	],
	[["no_ca.paa"]],			//   6 Vertical rhomb
	[["no_ca.paa"]],			//   7 Rectangle with sectors
	[							//   8 Oak leafs (broom) with number
		["oakleaf01a_ca.paa","oakleaf01b_ca.paa","oakleaf01c_ca.paa"],
		["oakleaf02a_ca.paa","oakleaf02b_ca.paa","oakleaf02c_ca.paa"],
		["oakleaf03a_ca.paa","oakleaf03b_ca.paa","oakleaf03c_ca.paa"],
		["oakleaf04a_ca.paa","oakleaf04b_ca.paa","oakleaf04c_ca.paa"],
		["oakleaf05a_ca.paa","oakleaf05b_ca.paa","oakleaf05c_ca.paa"],
		["oakleaf06a_ca.paa","oakleaf06b_ca.paa","oakleaf06c_ca.paa"],
		["oakleaf07a_ca.paa","oakleaf07b_ca.paa","oakleaf07c_ca.paa"],
		["oakleaf08a_ca.paa","oakleaf08b_ca.paa","oakleaf08c_ca.paa"],
		["oakleaf09a_ca.paa","oakleaf09b_ca.paa","oakleaf09c_ca.paa"]
	],
	[							//   9 Marines
		["marinesdolphin01a_ca.paa","marinesdolphin01b_ca.paa","marinesdolphin01c_ca.paa"],
		["wb01_ca.paa","wb02_ca.paa","wb03_ca.paa"]

	],
	[							//  10 Taxi
		["taxi01_ca.paa","taxi02_ca.paa","taxi03_ca.paa"]
	]
];
_index

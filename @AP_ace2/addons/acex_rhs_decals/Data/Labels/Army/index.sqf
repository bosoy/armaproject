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
scriptName "ArmyIndex";
private ["_index"];
_index = [
	[["no_ca.paa"]],		//   0 Clear
	[						//   1 Russian GRU
		["gru_ca.paa"],
		[
			"gru_logo01_ca.paa",
			"gru_logo02_ca.paa",
			"gru_logo03_ca.paa"
		],
		[
			"gru_logob01_ca.paa",
			"gru_logob02_ca.paa",
			"gru_logob03_ca.paa"
		],
		[
			"gru_spetsnaz01_ca.paa",
			"gru_spetsnaz02_ca.paa",
			"gru_spetsnaz03_ca.paa"
		],
		[
			"gru_spetsnazb01_ca.paa",
			"gru_spetsnazb02_ca.paa",
			"gru_spetsnazb03_ca.paa"
		]
	],
	[["vdv_ca.paa"]],		//   2 Russian VDV
	[						//   3 Russian VMF
		["vmf_ca.paa"],
		[
			"vmf-yakor01_ca.paa",
			"vmf-yakor02_ca.paa",
			"vmf-yakor03_ca.paa"
		],
		[
			"vmf-yakorb01_ca.paa",
			"vmf-yakorb02_ca.paa",
			"vmf-yakorb03_ca.paa"
		],
		[
			"vmf-yakorr01_ca.paa",
			"vmf-yakorr02_ca.paa",
			"vmf-yakorr03_ca.paa"
		]
	],
	[["iraqi_ca.paa"]],		//   4 Iraqi flag
	[						//   5 Ukrainian emblem
		["ua_ca.paa"],
		[
			"ukraina01_ca.paa",
			"ukraina02_ca.paa",
			"ukraina03_ca.paa"
		]
	],
	[						//   6 MVD Internal Forces
		["mvd_ca.paa"],
		[
			"mvd_vv01_ca.paa",
			"mvd_vv02_ca.paa",
			"mvd_vv03_ca.paa"
		]
	],
	[						//   7 MVD "ODON"
		[
			"mvd_odon01_ca.paa",
			"mvd_odon02_ca.paa",
			"mvd_odon03_ca.paa",
			"mvd_odon04_ca.paa"
		]
	],
	[						//   8 MVD "Moscow"
		[
			"mvd_moskva01_ca.paa",
			"mvd_moskva02_ca.paa",
			"mvd_moskva03_ca.paa"
		]
	],
	[						//   9 MVD "North West"
		[
			"mvd_piter01_ca.paa",
			"mvd_piter02_ca.paa",
			"mvd_piter03_ca.paa"
		]
	],
	[						//  10 MVD "North Caucasus"
		[
			"mvd_kavkaz01_ca.paa",
			"mvd_kavkaz02_ca.paa",
			"mvd_kavkaz03_ca.paa"
		]
	],
	[						//  11 MVD "Povoljie"
		[
			"mvd_povoljie01_ca.paa",
			"mvd_povoljie02_ca.paa",
			"mvd_povoljie03_ca.paa"
		]
	],
	[						//  12 MVD "Ural"
		[
			"mvd_ural01_ca.paa",
			"mvd_ural02_ca.paa",
			"mvd_ural03_ca.paa"
		]
	],
	[						//  13 MVD "Siberia"
		[
			"mvd_siberia01_ca.paa",
			"mvd_siberia02_ca.paa",
			"mvd_siberia03_ca.paa"
		]
	],
	[						//  14 MVD "Far East"
		[
			"mvd_vostok01_ca.paa",
			"mvd_vostok02_ca.paa",
			"mvd_vostok03_ca.paa"
		]
	],
	[						//  15 MVD "Spetsnaz"
		[
			"mvd_spetsnaz01_ca.paa",
			"mvd_spetsnaz02_ca.paa",
			"mvd_spetsnaz03_ca.paa"
		]
	],
	[						//  16 Peacemaker
		[					//     MC
			"peacemaker01_ca.paa",
			"peacemaker02_ca.paa",
			"peacemaker03_ca.paa"
		],
		[					//     UN (blue)
			"un_logo01_ca.paa",
			"un_logo02_ca.paa",
			"un_logo03_ca.paa"
		],
		[					//     UN (white)
			"un_logow01_ca.paa",
			"un_logow02_ca.paa",
			"un_logow03_ca.paa"
		],
		["un_logob01_ca.paa"],//     UN (black)
		["un_textb01_ca.paa"] //     UN letters (black)
	],
	[["taki_ca.paa"]],		//  17 Takistan
	[						//  18 MVD "Obespechenie voysk"
		[
			"mvd_oboz01_ca.paa",
			"mvd_oboz02_ca.paa",
			"mvd_oboz03_ca.paa"
		]
	],
	[						//  19 MVD "SOBR"
		[
			"mvd_sobr01_ca.paa",
			"mvd_sobr02_ca.paa",
			"mvd_sobr03_ca.paa"
		]
	],
	[						//  20 Spetsnaz signs
		[					//     Original Russian Spetsnaz symbol
			"spn_orig01_ca.paa",
			"spn_orig02_ca.paa",
			"spn_orig03_ca.paa"
		],
		[					//     MVD Spetsnaz (First Chechen war period)
			"spn_rosich01_ca.paa",
			"spn_rosich02_ca.paa",
			"spn_rosich03_ca.paa"
		],
		["mvdspn_010101_ca.paa"], // Vityaz		1 ПСН ВВ Витязь (Москва)
		["mvdspn_020101_ca.paa"],
		["mvdspn_010201_ca.paa"], // Merkuriy	25 ОСН ВВ Меркурий (Смоленск)
		["mvdspn_020201_ca.paa"],
		["mvdspn_010301_ca.paa"], // Svyatogor	24 ОСН ВВ Святогор (Владивосток)
		["mvdspn_020301_ca.paa"],
		["mvdspn_010401_ca.paa"], // Mechel		23 ОСН ВВ Мечел (Челябинск)
		["mvdspn_020401_ca.paa"],
		["mvdspn_010501_ca.paa"], // Tayfun		21 ОСН ВВ Тайфун (Хабаровск)
		["mvdspn_020501_ca.paa"],
		["mvdspn_010601_ca.paa"], // Ermak		9 ОСН ВВ Ермак (Новосибирск)
		["mvdspn_020601_ca.paa"],
		["mvdspn_010701_ca.paa"], // Skif		6 ОСН ВВ Скиф (Ростов)
		["mvdspn_020701_ca.paa"],
		["mvdspn_010801_ca.paa"], // Viyatich	15 ОСН ВВ Вятич (Армавир)
		["mvdspn_020801_ca.paa"],
		["mvdspn_010901_ca.paa"], // Rus'		8 ОСН ВВ Русь (Москва)
		["mvdspn_020901_ca.paa"],
		["mvdspn_011001_ca.paa"], // Rosich		7 ОСН ВВ Росич (Новочеркасск)
		["mvdspn_021001_ca.paa"],
		["mvdspn_011101_ca.paa"], // Ratnik		12 ОСН ВВ Ратник (Нижний Тагил)
		["mvdspn_021101_ca.paa"]
	],
	[						//  21  Islamists and islamic terrorists
		[
			"ch_ichcr01_ca.paa",
			"ch_ichcr02_ca.paa",
			"ch_ichcr03_ca.paa"
		],
		[
			"ch_ichemir01_ca.paa",
			"ch_ichemir02_ca.paa",
			"ch_ichemir03_ca.paa"
		],
		[
			"takbeer01_ca.paa",
			"takbeer02_ca.paa",
			"takbeer03_ca.paa"
		],
		[
			"takbeerb01_ca.paa",
			"takbeerb02_ca.paa",
			"takbeerb03_ca.paa"
		]
	],
	[						//  22  Resistance, insurgents, rebels, guerrillas
		[
			"slavic_militia01_ca.paa",
			"slavic_militia02_ca.paa",
			"slavic_militia03_ca.paa"
		]
	],
	[						//  23 DDR
		[
			"DDR_insignian01_ca.paa",
			"DDR_insignian02_ca.paa",
			"DDR_insignian03_ca.paa"
		],
		[
			"DDR_insigniao01_ca.paa",
			"DDR_insigniao02_ca.paa",
			"DDR_insigniao03_ca.paa"
		],
		[
			"DDR_insignia01_ca.paa",
			"DDR_insignia02_ca.paa",
			"DDR_insignia03_ca.paa"
		]
	],
	[						//  24 Finland
		[
			"fin_insignia01_ca.paa",
			"fin_insignia02_ca.paa",
			"fin_insignia03_ca.paa"
		]
	],
	[						//  25 Romania
		[
			"rom_insignia01_ca.paa",
			"rom_insignia02_ca.paa",
			"rom_insignia03_ca.paa"
		]
	],
	[						//  26 Poland
		[
			"pol01_ca.paa",
			"pol02_ca.paa",
			"pol03_ca.paa"
		]
	],
	[						//  27 CSLA
		[
			"csla01_ca.paa",
			"csla02_ca.paa",
			"csla03_ca.paa"
		]
	]
];
_index 
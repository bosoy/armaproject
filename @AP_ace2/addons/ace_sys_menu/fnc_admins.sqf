#include "script_component.hpp"
[
	["Admin",
		[
			["Caption", "Admin Commands (Use with care!)"],
			["Items",
				[
					[ ["Item", "Tools >"], ["SubMenu", "AdminTools"] ],
					[ ["Item", "-"] ],
					[ ["Item", "Month and Day Setting >"], ["SubMenu", "AdminDate"] ],
					[ ["Item", "Time of Day Setting (00:00-11:00) >"], ["SubMenu", "AdminTime0"] ],
					[ ["Item", "Time of Day Setting (12:00-23:00) >"], ["SubMenu", "AdminTime1"] ],
					[ ["Item", "Weather Overcast Setting >"], ["SubMenu", "AdminWeather0"] ],
					[ ["Item", "Weather Fog Setting >"], ["SubMenu", "AdminWeather1"] ],
					[ ["Item", "Weather Rain Setting >"], ["SubMenu", "AdminWeather2"] ],
					[ ["Item", "Weather Snow Setting >"], ["SubMenu", "AdminWeather3"] ],
					[ ["Item", "-"] ],
					[ ["Item", "Control Server Viewdistance >"], ["SubMenu", "AdminVD"] ],
					//[ ["Item", "Control DSAI >"], ["SubMenu", "AdminDSAI"] ],
					[ ["Item", "Control AI Skill (Experimental) >"], ["SubMenu", "AdminSkill"] ],
					[ ["Item", "Spawn Weapon Crates (Only at fun/training) >"], ["SubMenu", "AdminCrates"] ],
					[ ["Item", "Spawn Magazine Crates >"], ["SubMenu", "AdminCrates2"] ],
					[ ["Item", "Set Players to Leader Position >"], ["SubMenu", "AdminMove"]  ],
					[ ["Item", "-"] ],
					[ ["Item", "Options >"], ["SubMenu", "AdminOptions"] ],
					[ ["Item", "Debug >"], ["SubMenu", "AdminDebug"] ]
				]
			]
		]
	],
	["AdminOptions",
		[
			["Caption", "Control Options"],
			["Items",
				[
					[ ["Item", "dis/enable Spectator"], ["Action", "[1, 0] spawn ace_sys_menu_proc"], ["Close", false] ],
					[ ["Item", "dis/enable Respawn Civilian Group"], ["Action", "[1, 1] spawn ace_sys_menu_proc"], ["Close", false] ],
					[ ["Item", "dis/enable Character Switching"], ["Action", "[5, 3] spawn ace_sys_characters_menu"], ["Close", false] ],
					[ ["Item", "dis/enable Group management"], ["Action", "[15] call ace_sys_menu_proc"], ["Close", false] ]
				]
			]
		]
	],
	["AdminVD",
		[
			["Caption", "Control Server Viewdistance"],
			["Items",
				[
					[ ["Item", "300m"], ["Action", "[0, { setViewDistance 300 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "400m"], ["Action", "[0, { setViewDistance 400 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "500m"], ["Action", "[0, { setViewDistance 500 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "600m"], ["Action", "[0, { setViewDistance 600 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "1200m (Default)"], ["Action", "[0, { setViewDistance 1200 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "2000m"], ["Action", "[0, { setViewDistance 2000 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "3000m"], ["Action", "[0, { setViewDistance 3000 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "5000m"], ["Action", "[0, { setViewDistance 5000 }] call CBA_fnc_globalExecute"], ["Close", false] ],
					[ ["Item", "8000m"], ["Action", "[0, { setViewDistance 8000 }] call CBA_fnc_globalExecute"], ["Close", false] ]
				]
			]
		]
	],
	["AdminDSAI",
		[
			["Caption", "Control DSAI"],
			["Items",
				[
					[ ["Item", "Disable DSAI"], ["Action", "RUG_DSAI_TerminalDistance = -1;publicVariable 'RUG_DSAI_TerminalDistance'"], ["Close", false] ],
					[ ["Item", "Enable DSAI (150m)"], ["Action", "RUG_DSAI_TerminalDistance = 150;publicVariable 'RUG_DSAI_TerminalDistance'"], ["Close", false] ],
					[ ["Item", "Enable DSAI (300m, default)"], ["Action", "RUG_DSAI_TerminalDistance = 300;publicVariable 'RUG_DSAI_TerminalDistance'"], ["Close", false] ],
					[ ["Item", "Enable DSAI (600m)"], ["Action", "RUG_DSAI_TerminalDistance = 600;publicVariable 'RUG_DSAI_TerminalDistance'"], ["Close", false] ]
				]
			]
		]
	],
	["AdminMove",
		[
			["Caption", "Move Players to Leader Position (CAREFUL)"],
			["Items",
				[
					[ ["Item", "Move All Players to Leader Position"], ["Action", "[-1,{ player setPos (getPos (leader player)) }] call CBA_fnc_globalExecute"] ],
					[ ["Item", "Move All Players into Cargo of Leader Vehicle"], ["Action", "[-1,{ player moveInCargo (vehicle (leader player)) }] call CBA_fnc_globalExecute"] ],
					[ ["Item", "Move Players in your group to Leader Position"], ["Action", "[-1,{ if (player in (units _this)) then { player setPos (getPos (leader player)) } },player] call CBA_fnc_globalExecute"] ],
					[ ["Item", "Move Players in your group into Cargo of Leader Vehicle"], ["Action", "[-1,{ if (player in (units _this)) then { player moveInCargo (vehicle (leader player)) } },player] call CBA_fnc_globalExecute"] ]
				]
			]
		]
	],
	["AdminDate",
		[
			["Caption", "Date"],
			["Items",
				[
					[ ["Item", "January"], ["Action", "[[1]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "February"], ["Action", "[[2]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "March"], ["Action", "[[3]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "April"], ["Action", "[[4]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "May"], ["Action", "[[5]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "June"], ["Action", "[[6]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "July"], ["Action", "[[7]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "August"], ["Action", "[[8]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "September"], ["Action", "[[9]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "October"], ["Action", "[[10]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "November"], ["Action", "[[11]] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "December"], ["Action", "[[12]] call ace_sys_menu_fnc_date"], ["Close", false] ],

					[ ["Item", "Decrease by 1 day"], ["Action", "[[0, 1], 'dn'] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "Increase by 1 day"], ["Action", "[[0, 1], 'up'] call ace_sys_menu_fnc_date"], ["Close", false] ],
					[ ["Item", "Decrease by 1 year"], ["Action", "[[1], 'dn'] call ace_sys_menu_fnc_year"], ["Close", false] ],
					[ ["Item", "Increase by 1 year"], ["Action", "[[1], 'up'] call ace_sys_menu_fnc_year"], ["Close", false] ]
				]
			]
		]
	],
	["AdminTime0",
		[
			["Caption", "Time of Day, 0:00-11:00"],
			["Items",
				[
					[ ["Item", "0:00"], ["Action", "[[0]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "1:00"], ["Action", "[[1]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "2:00"], ["Action", "[[2]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "3:00"], ["Action", "[[3]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "4:00"], ["Action", "[[4]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "5:00"], ["Action", "[[5]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "6:00"], ["Action", "[[6]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "7:00"], ["Action", "[[7]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "8:00"], ["Action", "[[8]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "9:00"], ["Action", "[[9]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "10:00"], ["Action", "[[10]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "11:00"], ["Action", "[[11]] call ace_sys_menu_fnc_time"], ["Close", false] ],

					[ ["Item", "Decrease by 0.5hr"], ["Action", "[[0, 30], 'dn'] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "Increase by 0.5hr"], ["Action", "[[0, 30], 'up'] call ace_sys_menu_fnc_time"], ["Close", false] ]
				]
			]
		]
	],
	["AdminTime1",
		[
			["Caption", "Time of Day, 12:00-23:00"],
			["Items",
				[
					[ ["Item", "12:00"], ["Action", "[[12]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "13:00"], ["Action", "[[13]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "14:00"], ["Action", "[[14]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "15:00"], ["Action", "[[15]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "16:00"], ["Action", "[[16]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "17:00"], ["Action", "[[17]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "18:00"], ["Action", "[[18]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "19:00"], ["Action", "[[19]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "20:00"], ["Action", "[[20]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "21:00"], ["Action", "[[21]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "22:00"], ["Action", "[[22]] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "23:00"], ["Action", "[[23]] call ace_sys_menu_fnc_time"], ["Close", false] ],

					[ ["Item", "Decrease by 0.5hr"], ["Action", "[[0, 30], 'dn'] call ace_sys_menu_fnc_time"], ["Close", false] ],
					[ ["Item", "Increase by 0.5hr"], ["Action", "[[0, 30], 'up'] call ace_sys_menu_fnc_time"], ["Close", false] ]
				]
			]
		]
	],
	["AdminWeather0",
		[
			["Caption", "Weather Overcast"],
			["Items",
				[
					[ ["Item", "0"], ["Action", "[0] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["Item", "0.1"], ["Action", "[0.1] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.2"], ["Action", "[0.2] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.3"], ["Action", "[0.3] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.4"], ["Action", "[0.4] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.5"], ["Action", "[0.5] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.6"], ["Action", "[0.6] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.7"], ["Action", "[0.7] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.8"], ["Action", "[0.8] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "0.9"], ["Action", "[0.9] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["item", "1"], ["Action", "[1] call ace_sys_menu_fnc_overCast"], ["Close", false] ],

					[ ["Item", "Decrease by 0.01"], ["Action", "[0.01, 'dn'] call ace_sys_menu_fnc_overCast"], ["Close", false] ],
					[ ["Item", "Increase by 0.01"], ["Action", "[0.01, 'up'] call ace_sys_menu_fnc_overCast"], ["Close", false] ]
				]
			]
		]
	],
	["AdminWeather1",
		[
			["Caption", "Weather Fog"],
			["Items",
				[
					[ ["Item", "0"], ["Action", "[0] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["Item", "0.1"], ["Action", "[0.1] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.2"], ["Action", "[0.2] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.3"], ["Action", "[0.3] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.4"], ["Action", "[0.4] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.5"], ["Action", "[0.5] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.6"], ["Action", "[0.6] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.7"], ["Action", "[0.7] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.8"], ["Action", "[0.8] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "0.9"], ["Action", "[0.9] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["item", "1"], ["Action", "[1] call ace_sys_menu_fnc_fog"], ["Close", false] ],

					[ ["Item", "Decrease by 0.01"], ["Action", "[0.01, 'dn'] call ace_sys_menu_fnc_fog"], ["Close", false] ],
					[ ["Item", "Increase by 0.01"], ["Action", "[0.01, 'up'] call ace_sys_menu_fnc_fog"], ["Close", false] ]
				]
			]
		]
	],
	["AdminWeather2",
		[
			["Caption", "Weather Rain (Only effect when overCast > 0.7)"],
			["Items",
				[
					[ ["Item", "0"], ["Action", "[0] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["Item", "0.1"], ["Action", "[0.1] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.2"], ["Action", "[0.2] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.3"], ["Action", "[0.3] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.4"], ["Action", "[0.4] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.5"], ["Action", "[0.5] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.6"], ["Action", "[0.6] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.7"], ["Action", "[0.7] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.8"], ["Action", "[0.8] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "0.9"], ["Action", "[0.9] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["item", "1"], ["Action", "[1] call ace_sys_menu_fnc_rain"], ["Close", false] ],

					[ ["Item", "Decrease by 0.01"], ["Action", "[0.01, 'dn'] call ace_sys_menu_fnc_rain"], ["Close", false] ],
					[ ["Item", "Increase by 0.01"], ["Action", "[0.01, 'up'] call ace_sys_menu_fnc_rain"], ["Close", false] ]
				]
			]
		]
	],
	["AdminWeather3",
		[
			["Caption", "Weather Snow"],
			["Items",
				[
					[ ["Item", "0"], ["Action", "[0] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["Item", "0.1"], ["Action", "[0.1] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.2"], ["Action", "[0.2] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.3"], ["Action", "[0.3] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.4"], ["Action", "[0.4] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.5"], ["Action", "[0.5] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.6"], ["Action", "[0.6] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.7"], ["Action", "[0.7] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.8"], ["Action", "[0.8] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "0.9"], ["Action", "[0.9] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "1"], ["Action", "[1] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "1.5"], ["Action", "[1.5] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "2"], ["Action", "[2] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "3"], ["Action", "[3] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "4"], ["Action", "[4] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["item", "5"], ["Action", "[5] call ace_sys_menu_fnc_snow"], ["Close", false] ],

					[ ["Item", "Decrease by 0.01"], ["Action", "[0.01, 'dn'] call ace_sys_menu_fnc_snow"], ["Close", false] ],
					[ ["Item", "Increase by 0.01"], ["Action", "[0.01, 'up'] call ace_sys_menu_fnc_snow"], ["Close", false] ]
				]
			]
		]
	],
	["AdminSkill",
		[
			["Caption", "AI Skill (Experimental)"],
			["Items",
				[
					[ ["Item", "0"], ["Action", "0 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["Item", "0.1"], ["Action", "0.1 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.2"], ["Action", "0.2 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.3"], ["Action", "0.3 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.4"], ["Action", "0.4 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.5"], ["Action", "0.5 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.6"], ["Action", "0.6 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.7"], ["Action", "0.7 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.8"], ["Action", "0.8 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "0.9"], ["Action", "0.9 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "1"], ["Action", "1 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "1.5"], ["Action", "1.5 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "2"], ["Action", "2 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "3"], ["Action", "3 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "4"], ["Action", "4 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ],
					[ ["item", "5"], ["Action", "5 call ace_sys_ai_fApplySkillModifier"], ["Close", false] ]
				]
			]
		]
	],
	["AdminTools",
		[
			["Caption", "Tools"],
			["Items",
				[
					[ ["Item", "Open RTE at Player Position"], ["Action", "'' spawn { SIX_ION_POS = nil; sleep 1; [] spawn ION_RTE_pStartRTE }"] ],
					[ ["Item", "Open RTE at Specified Position"], ["Action", "hint 'Click on the map to start RTE'; '' spawn { sleep 1; [1] call ace_sys_menu_fnc_showMap; onMapSingleClick ""closedialog 0; _dum = _pos spawn { [] call ION_RTE_pStartRTE; sleep 3; [_this, 0] call ION_RTE_pMoveTo }; onmapSingleClick ''"" }"] ],
					[ ["Item", "Open Lost Key"], ["Action", "nul = [] spawn { sleep 1; if (isNil 'ace_blabla') then { ace_blabla = true; 'destroyObjects' addPublicVariableEventHandler { _objects = _this select 1; {_x setdammage 1} forEach _objects } }; _ActionParams = []; _actionUnit = player; call compile preProcessFileLineNumbers '\loki_lk\start.sqf' }"] ] //,
				]
			]
		]
	],
	["AdminRTE",
		[
			["Caption", "RTE"],
			["Items",
				[
					[ ["Item", "Open RTE at Player Position"], ["Action", "'' spawn { SIX_ION_POS = nil; sleep 1; [] spawn ION_RTE_pStartRTE }"] ],
					[ ["Item", "Open RTE at Specified Position"], ["Action", "hint 'Click on the Map to start RTE'; '' spawn { sleep 1; [1] call ace_sys_menu_fnc_showMap; onMapSingleClick ""closedialog 0; _dum = _pos spawn { [] call ION_RTE_pStartRTE; sleep 3; [_this, 0] call ION_RTE_pMoveTo }; onmapSingleClick ''"" }"] ]
				]
			]
		]
	],
//'USBasicAmmunitionBox', 'USLaunchersBox', 'USOrdnanceBox', , 'USSpecialWeaponsBox', 'USVehicleBox',
//, 'RULaunchersBox', 'RUOrdnanceBox', , 'RUSpecialWeaponsBox', 'RUVehicleBox',
//, , 'GuerillaCacheBox', 'SpecialWeaponsBox'
	["AdminCrates",
		[
			["Caption", "Weapon/Ammo Crates"],
			["Items",
				[
					[ ["Item", " == Weapons & Ammo == "], ["Close", false] ],
//					[ ["Item", "Generic Crate"], ["Action", "['SIX_WeaponBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ],
					[ ["Item", "West Crate"], ["Action", "['USBasicWeaponsBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ],
					[ ["Item", "East Crate"], ["Action", "['RUBasicWeaponsBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ],
					[ ["Item", "Guer Crate"], ["Action", "['LocalBasicWeaponsBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ]
//					[ ["Item", "Equipment Crate"], ["Action", "['SIX_EquipmentBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ]
				]
			]
		]
	],
	["AdminCrates2",
		[
			["Caption", "Ammo Crates"],
			["Items",
				[
					[ ["Item", " == Ammo == "], ["Close", false] ],
//					[ ["Item", "Generic Crate"], ["Action", "['SIX_AmmoBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ],
					[ ["Item", "West Crate"], ["Action", "['USBasicAmmunitionBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ],
					[ ["Item", "East Crate"], ["Action", "['RUBasicAmmunitionBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ],
					[ ["Item", "Guer Crate"], ["Action", "['LocalBasicAmmunitionBox', SIX_WCRATEPOS] call CBA_network_fnc_cV"], ["Close", false] ]
				]
			]
		]
	],
	["AdminDebug",
		[
			["Caption", "Admin Debug"],
			["Items",
				[
					[ ["Item", "Console"], ["Action", "[] spawn { sleep 1; createDialog 'ACE_MP_Debug_Console' }"] ],
					[ ["Item", "TroopMon"], ["Action", "nul = [] execVM '\CHN_TroopMon\scripts\MonInit.sqf'"] ],
					[ ["Item", "Teleport (shift+click on map)"], ["Action", "hint 'Shift-Click on the map to Teleport'; [1] call ace_sys_menu_fnc_showMap ; onMapSingleClick 'if (_shift) then { (vehicle player) setPos _pos;closeDialog 0;onMapSingleClick '''' }' "], ["Close", false] ],
					[ ["Item", "Open Spectator"], ["Action", "[] spawn ACE_fnc_startSpectator"] ]
				]
			]
		]
	]
];

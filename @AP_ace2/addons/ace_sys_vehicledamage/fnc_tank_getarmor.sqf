// find armor thickness for given selection, side and KE/CE type of ammo
// +
// era fx


#include "script_component.hpp"
#define __unitcfg configFile >> "cfgVehicles" >> typeof _unit
#define __ammocfg configFile >> "cfgAmmo" >> _ammo
#define __armorcoef [1,0.3,0.3,0.1,0.1,0.2]


private["_side","_s","_e","_armortype","_ammotype","_armor","_blocks","_initblocks","_coverage","_prob","_armor_era"];
PARAMS_5(_unit,_part,_injurer,_ammo,_angles);


//KE or CE
_ammotype = if (getNumber(__ammocfg >> "explosive") <= 0.1) then {
	0; //KE
} else {
	1; //CE
};

_armortype = if (_part == "turret") then { "turret" } else { "hull" };
_side = _angles select 0;

//kinda compatible with vehicles without ace_armor_*** entries
//(but better to have'em)
if (! isNumber(__unitcfg >> "ace_era")) then {
	_armor = getNumber(__unitcfg >> "armor");
	_armor = if (_ammotype == 0) then {
		(__armorcoef select _side)*_armor*0.7/(_angles select 3);
	} else {
		(__armorcoef select _side)*_armor/(_angles select 3);
	};
	_s = 0;	//era
} else {
	_armor = getArray(__unitcfg >> ("ace_armor_"+_armortype));
	TRACE_3("Armor script - Armor array",_armor,_side,_angles);
	_armor = _armor select _side;
	//effective thickness for part hit, ammo type and incidence angle
	_armor = (_armor select _ammotype)/(_angles select 3);
	_s = getNumber(__unitcfg >> "ace_era");
};

//era

if (_s == 1) then {
	_s = _unit getvariable "ace_era_blocks_hull";
	if (isNil "_s") then {
		_e = getArray(__unitcfg >> "ace_era_blocks_hull");
		_unit setVariable["ace_era_blocks_hull",_e];
		_e = getArray(__unitcfg >> "ace_era_blocks_turret");
		_unit setVariable["ace_era_blocks_turret",_e];
	};

	_armor_era = getArray(__unitcfg >> ("ace_era_"+_armortype));
	_armor_era = (_armor_era select _side) select _ammotype;
	TRACE_1("Armor script - CFG ERA",_armor_era);

	if (_armor_era == 0) exitwith {};

	_coverage = getArray(__unitcfg >> ("ace_era_coverage_"+_armortype));
	_coverage = _coverage select _side;
	TRACE_1("Armor script - CFG ERA",_coverage);

	if (_coverage == 0) exitwith {};

	_initblocks = getArray(__unitcfg >> ("ace_era_blocks_"+_armortype));
	_initblocks = _initblocks select _side; //initial amt of blocks on current part/side
	TRACE_1("Armor script - CFG ERA",_initblocks);

	if (_initblocks == 0) exitwith {};

	_blocksarray = _unit getvariable ("ace_era_blocks_"+_armortype);
	_blocks = _blocksarray select _side; //current amt of blocks on current part/side
	TRACE_1("Armor script",_blocks);

	if (_blocks == 0) exitwith {};

	_prob = _blocks*_coverage/_initblocks;
	TRACE_1("Armor script",_prob);

	//era block is hit
	if (_prob > random 1) then {
		_blocksarray set [_side,_blocks - 1];
		_unit setVariable[("ace_era_blocks_"+_armortype),_blocksarray];
		// if (_ammotype == 1) then
		// {
			if (getNumber(__ammocfg >> "ace_tandemheat") != 1) then {
				_armor = _armor + _armor_era;
			};
		// };
		TRACE_1("Armor script - ERA Hit Blocks left",(_blocks-1));
	};

};
TRACE_1("Armor script finished",_armor);

_armor
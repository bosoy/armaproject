private [
	"_unit",
	"_damage",
	"_cfgHits",
	"_cfgSection",
	"_cfgSectionName",
	"_numSects",
	"_SectionName"
]; 

_unit = _this select 0;
_damage = _this select 1;

_unit setDamage(_damage);

_cfgHits = configFile >> "CfgVehicles" >> typeOf(_unit) >> "HitPoints";
_numSects = count _cfgHits;

if ( _numSects > 0 ) then {
	sleep random 5.0;

	for "_i" from 0 to (_numSects - 1) do {
		_cfgSection = (_cfgHits) select _i;
		_cfgSectionName = _cfgSection >> "name";

		if ( isText(_cfgSectionName) ) then {
			_SectionName = getText _cfgSectionName;
			if ( (random 1) < _damage ) then {
				_unit setHit[_SectionName, 1];
			};
		};
	};
};

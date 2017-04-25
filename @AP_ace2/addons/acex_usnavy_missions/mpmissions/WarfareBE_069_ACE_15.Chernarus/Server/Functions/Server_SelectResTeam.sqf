Private ['_difficulty','_factor','_infAssign','_minInfSpawnRatio','_minVehSpawnRatio','_poolInf','_poolVeh','_ratioInfantry','_ranArr','_ratioVehicle','_teams','_try','_vehAssign'];

_difficulty = _this select 0;

_ratioVehicle = 0;
_ratioInfantry = 0;

_teams = [];
_poolInf = [];
_poolVeh = [];

_vehAssign = 0;
_infAssign = 0;
_minInfSpawnRatio = 0;
_minVehSpawnRatio = 0;
_try = 0;

switch (_difficulty) do {
	case 'light1': {
		_ratioVehicle = 10;
		_ratioInfantry = 90;
		_try = 3;
		_minInfSpawnRatio = 15;
		_minVehSpawnRatio = 35;
		
		_poolInf = ['Group','Patrol1','Patrol2','Militia'];
		_poolVeh = ['MotorizedGroup'];
	};
	case 'light2': {
		_ratioVehicle = 20;
		_ratioInfantry = 80;
		_try = 4;
		_minInfSpawnRatio = 20;
		_minVehSpawnRatio = 40;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','Patrol2','Militia'];
		_poolVeh = ['Technical'];
	};
	case 'medium1': {
		_ratioVehicle = 20;
		_ratioInfantry = 80;
		_try = 5;
		_minInfSpawnRatio = 18;
		_minVehSpawnRatio = 35;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault','SniperTeam'];
		_poolVeh = ['Technical'];
	};
	case 'medium2': {
		_ratioVehicle = 40;
		_ratioInfantry = 60;
		_try = 5;
		_minInfSpawnRatio = 22;
		_minVehSpawnRatio = 39;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault','AATeam'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','LightArmor','Technical','MotorizedGroup'];
	};
	case 'medium3': {
		_ratioVehicle = 30;
		_ratioInfantry = 70;
		_try = 5;
		_minInfSpawnRatio = 26;
		_minVehSpawnRatio = 32;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','MotorizedAATeam','LightArmor','Technical','MotorizedGroup'];
	};
	case 'medium4': {
		_ratioVehicle = 35;
		_ratioInfantry = 65;
		_try = 5;
		_minInfSpawnRatio = 28;
		_minVehSpawnRatio = 32;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault','AATeam'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','MotorizedAATeam','LightArmor','Technical','HeavyArmor'];
	};
	case 'large1': {
		_ratioVehicle = 30;
		_ratioInfantry = 70;
		_try = 5;
		_minInfSpawnRatio = 25;
		_minVehSpawnRatio = 35;
		
		_poolInf = ['GroupWeapons','ATTeam','GroupAssault','SniperTeam'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','LightArmor','LightArmor','HeavyArmor','Technical'];
	};
	case 'large2': {
		_ratioVehicle = 45;
		_ratioInfantry = 55;
		_try = 6;
		_minInfSpawnRatio = 25;
		_minVehSpawnRatio = 32;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault','AATeam','SniperTeam'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','MotorizedAATeam','LightArmor','HeavyArmor','HeavyArmor','Technical'];
	};
	case 'huge1': {
		_ratioVehicle = 50;
		_ratioInfantry = 50;
		_try = 6;
		_minInfSpawnRatio = 30;
		_minVehSpawnRatio = 35;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault','AATeam','SniperTeam'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','MotorizedAATeam','LightArmor','LightArmor','HeavyArmor','HeavyArmor','Technical'];
	};
	case 'huge2': {
		_ratioVehicle = 50;
		_ratioInfantry = 50;
		_try = 7;
		_minInfSpawnRatio = 35;
		_minVehSpawnRatio = 35;
		
		_poolInf = ['Group','GroupWeapons','ATTeam','GroupAssault','AATeam','SniperTeam'];
		_poolVeh = ['MechanizedGroup','MechanizedPatrol','MotorizedAATeam','LightArmor','LightArmor','HeavyArmor','HeavyArmor','Technical'];
	};
};

_try = _try * ('WFBE_TOWNRESISTANCEDIFFICULTY' Call GetNamespace);
_vehAssign = round(_try * (_ratioVehicle / 100));
_infAssign = round(_try * (_ratioInfantry / 100));

for [{_z = 0},{_z < _try},{_z = _z + 1}] do {
	if (_vehAssign > 0) then {
		_vehAssign = _vehAssign - 1;
		if (random 100 > _minVehSpawnRatio) then {
			_ranArr = round(random((count _poolVeh)-1));
			_teams = _teams + [_poolVeh select _ranArr];
		};
	};
	if (_infAssign > 0) then {
		_infAssign = _infAssign - 1;
		if (random 100 > _minInfSpawnRatio) then {
			_ranArr = round(random((count _poolInf)-1));
			_teams = _teams + [_poolInf select _ranArr];
		};
	};
};

if (count _teams < 1) then {_teams = ['Group']};

_teams
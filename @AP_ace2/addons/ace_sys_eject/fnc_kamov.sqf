//kamov.sqf
private ["_vehicle","_bigWasp","_smallWasp","_vectorDir", "_vectorUp", "_velocty","_blade1","_bladeOffset1","_worldPos1","_vectorDirBlade1","_posOffset1","_vbx1","_vby1","_vbz1","_blade2","_bladeOffset2","_worldPos2","_vectorDirBlade2","_posOffset2","_vbx2","_vby2","_vbz2"];
/* This script is executed by the "Eject" addAction command. Parts of this script are adapted from mando_ejectunit.sqf v1.1 by Mandoble.*/

// Argument(s) passed from addAction command. 0 = the vehicle the event handler is assigned to. 2 = the action index id for this particular addAction command.
_vehicle = _this;

//if ((local _vehicle) && (_vehicle isKindOf "Kamov_Base") && (isNull driver _vehicle) && (isNull gunner _vehicle) && !("500Rnd_TwinVickers" in magazines _vehicle)) then
if (local _vehicle && {(_vehicle isKindOf "Kamov_Base")} && {!("500Rnd_TwinVickers" in magazines _vehicle)}) then
{
	_vehicle addMagazine "500Rnd_TwinVickers";	// Prevents launching script double

	// let's make it automated - universal for most models
	_bigWasp = _vehicle selectionPosition "velka vrtule";
	_smallWasp = _vehicle selectionPosition "mala vrtule";

	//_vehicle setDamage 1; // currently the only successful method to cut the thrust of main rotor completely.
	_vehicle spawn {
		waitUntil {(isNull driver _this) && {(isNull gunner _this)}};
		_this setHit ["Glass3",1];
		_this setHit ["Glass4",1];
		_this setHit ["velka vrtule",1];	// Need hide animation
		_this setHit ["mala vrtule",1];
		_this setHit ["motor",1];
	};

	// idea for future: chopper plays kamovEjected animation which hides cockpit doors, some memory points, geometry sections and rotors. Script forces it downwards until it's dead.

	_bladeOffset1 = random 120;
	_bladeOffset2 = 60 - _bladeoffset1;

	// drop blades in pairs
	for "_x" from 1 to 3 do {
		_vectorDir = vectorDir _vehicle;
		_vectorUp = vectorUp _vehicle;
		_velocity = velocity _vehicle;

		_blade1 = "ACE_Ka52_Blade" createVehicle [random 100,100,100];
		_blade2 = "ACE_Ka52_Blade" createVehicle [100,random 100,100];

		_vectorDirBlade1 = [(cos _bladeOffset1), (sin _bladeOffset1), _vectorDir select 2];
		_vectorDirBlade2 = [(cos _bladeOffset2), (sin _bladeOffset2), _vectorDir select 2];

		_posOffset1 = [(_bigWasp select 0) + (8 * (cos _bladeOffset1)), (_bigWasp select 1) + (8 * (sin _bladeOffset1)), _bigWasp select 2];
		_posOffset2 = [(_smallWasp select 0) + (8 * (cos _bladeOffset2)), (_smallWasp select 1) + (8 * (sin _bladeOffset2)), _smallWasp select 2];

		_worldPos1 = _vehicle modelToWorld _posOffset1;
		_worldPos2 = _vehicle modelToWorld _posOffset2;

		_blade1 setPos _worldPos1;
		_blade2 setPos _worldPos2;

		_blade1 setVectorDirAndUp [_vectorDirBlade1, _vectorUp];
		_blade2 setVectorDirAndUp [_vectorDirBlade2, [-(_vectorUp select 0), -(_vectorUp select 1), -(_vectorUp select 2)]];

		_vbx1 = (_velocity select 0) + (100 * (_vectorDirBlade1 select 0));
		_vby1 = (_velocity select 1) + (100 * (_vectorDirBlade1 select 1));
		_vbz1 = (_velocity select 2) + (100 * (_vectorDirBlade1 select 2));

		_vbx2 = (_velocity select 0) + (100 * (_vectorDirBlade2 select 0));
		_vby2 = (_velocity select 1) + (100 * (_vectorDirBlade2 select 1));
		_vbz2 = (_velocity select 2) + (100 * (_vectorDirBlade2 select 2));

		_blade1 setVelocity [_vbx1,_vby1,_vbz1];
		_blade2 setVelocity [_vbx2,_vby2,_vbz2];

		drop ["\ca\data\KouleSvetlo","","Billboard",0.05,0.15,[0,-1,0],[_vbx1/4,_vby1/4,_vbz1/4],1,10,1,0.2,[1,1.5,0.8,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",_blade1];
		drop ["\ca\data\KouleSvetlo","","Billboard",0.05,0.1,[0,-1,0],[_vbx2/4,_vby2/4,_vbz2/4],1,10,1,0.2,[1,1.5,0.8,0.5],[[1,0.5,0,0.6],[1,1,1,0.5],[1,1,1,0.1]],[0],0,0,"","",_blade2];

		_bladeOffset1 = _bladeOffset1 + 120;
		_bladeOffset2 = _bladeOffset2 - 120;
	};
};

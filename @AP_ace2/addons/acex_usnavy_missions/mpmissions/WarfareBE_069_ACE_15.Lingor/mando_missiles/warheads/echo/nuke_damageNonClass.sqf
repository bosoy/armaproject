#define BLAST_SCALE 368.4
#define TREE_SCALE 0.8

private [
	"_pos",
	"_yield",
	"_c1",
	"_blast_radius",
	"_objects"
]; 

_pos = _this select 0;
_yield = _this select 1;

_c1 = _yield^(1/3);
_blast_radius = TREE_SCALE*BLAST_SCALE*_c1;

if ( _blast_radius > 0 ) then {
	_objects = (nearestObjects[_pos, [], _blast_radius]) - (nearestObjects[_pos, ["All"], _blast_radius]);
	{
		_x setDamage 1;
	} forEach _objects;
};

false;

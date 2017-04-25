private ["_bp","_bpItems"];
_bp = _this select 0;
_bpItems = _this select 1;

clearMagazineCargo _bp;

for '_u' from 0 to count(_bpItems select 0)-1 do {
	_bp addMagazineCargo [(_bpItems select 0) select _u, (_bpItems select 1) select _u];
};
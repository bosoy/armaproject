// result: string representing 6 digit numeric grid coords as "xxx-yyy"
private ["_r"];

_r = (_this select 0) call compile preprocessFileLineNumbers "Scripts\TeamStatusDialog\fn_PosToGrid.sqf";
_r = (_r select 0)+":"+(_r select 1);
_r

{
	(_this select 0) set [count (_this select 0), _x];
} foreach (_this select 1);
(_this select 0)
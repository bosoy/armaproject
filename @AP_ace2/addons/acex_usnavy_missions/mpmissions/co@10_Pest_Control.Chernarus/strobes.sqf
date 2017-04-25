Alpha enableIRLasers true;
Leader alpha sideChat "Turning IR strobes on now.";
playSound "beep"; 
playSound "radionoise1";
sleep 1;
if (!isNil "a1") then {
	["ace_sys_irstrobe_aradd", [a1]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a2") then {
	["ace_sys_irstrobe_aradd", [a2]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a3") then {
	["ace_sys_irstrobe_aradd", [a3]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a4") then {
	["ace_sys_irstrobe_aradd", [a4]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a5") then {
	["ace_sys_irstrobe_aradd", [a5]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a6") then {
	["ace_sys_irstrobe_aradd", [a6]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a7") then {
	["ace_sys_irstrobe_aradd", [a7]] call CBA_fnc_globalEvent;
};
sleep 0.1;
if (!isNil "a8") then {
	["ace_sys_irstrobe_aradd", [a8]] call CBA_fnc_globalEvent;
};
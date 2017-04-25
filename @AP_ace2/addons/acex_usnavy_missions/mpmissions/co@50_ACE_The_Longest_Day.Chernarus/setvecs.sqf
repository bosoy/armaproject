if (!isServer) exitWith {};

uh1 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
uh2 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
osp addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
bh1 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
bh2 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
osp2 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
vvv1 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];
vvv2 addeventhandler ["getin", {_this execVM "x_scripts\x_checkhelipilot.sqf";}];

sleep 3;

servicetrigger setPosASL [position servicetrigger select 0, position servicetrigger select 1, 15.9];

uh1 setDamage 0;
uh2 setDamage 0;
osp setDamage 0;
bh1 setDamage 0;
bh2 setDamage 0;
osp2 setDamage 0;

[uh1, 120] execFsm "fsms\VehicleRespawn.fsm";
[uh2, 120] execFsm "fsms\VehicleRespawn.fsm";
[osp, 120] execFsm "fsms\VehicleRespawn.fsm";
[bh1, 120] execFsm "fsms\VehicleRespawn.fsm";
[bh2, 120] execFsm "fsms\VehicleRespawn.fsm";
[osp2, 120] execFsm "fsms\VehicleRespawn.fsm";
[vvv1, 120] execFsm "fsms\VehicleRespawn.fsm";
[vvv2, 120] execFsm "fsms\VehicleRespawn.fsm";

if (true) exitWith {};
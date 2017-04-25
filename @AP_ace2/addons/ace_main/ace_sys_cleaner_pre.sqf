GVAR(clean_array) = [];

GVAR(fifologic) = "ACE_LogicDummy" createVehicleLocal [0, 0];
GVAR(sfifo_index) = [];
GVAR(sfifo_array) = [];

PREPMAIN(handleFifoExplosives);

FUNC(pushStack) = {
	{
		(_this select 0) set [count (_this select 0), _x];
	} foreach (_this select 1);
	(_this select 0)
};

execFSM QPATHTO_C(Cleaner.fsm);
execFSM QPATHTO_C(SlowFifo.fsm);
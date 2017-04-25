Private ['_r','_u'];

_r = 'WFBE_RESTRICTIONADVAIR' Call GetNamespace;

//--- US Aircraft Vehicles.
_u 			= ['MH6J_EP1'];
_u = _u		+ ['UH60M_EP1'];
_u = _u		+ ['UH60M_MEV_EP1'];
_u = _u		+ ['CH_47F_EP1'];
if (_r == 0 || _r == 1) then {
	_u = _u		+ ['AH6J_EP1'];
	_u = _u		+ ['AH64D_EP1'];
};
if (_r == 0) then {
	_u = _u		+ ['C130J_US_EP1'];
	_u = _u		+ ['A10_US_EP1'];
};
if (paramDLCBAF) then {
	_u = _u		+ ['BAF_Merlin_HC3_D'];
	_u = _u		+ ['CH_47F_BAF'];
	if (_r == 0 || _r == 1) then {
		_u = _u		+ ['AW159_Lynx_BAF'];
		_u = _u		+ ['BAF_Apache_AH1_D'];
	};
};

_u
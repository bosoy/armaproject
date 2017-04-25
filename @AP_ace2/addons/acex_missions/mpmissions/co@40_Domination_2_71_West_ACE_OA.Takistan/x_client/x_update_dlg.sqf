#define THIS_FILE "x_update_dlg.sqf"
#include "x_setup.sqf"
private ["_display","_mr1text","_mr2text","_mr1_available","_mr2_available"];

if (GVAR(x_loop_end)) exitWith {};

disableSerialization;

#define __CTRL(A) (_display displayCtrl A)

_display = __uiGetVar(X_TELE_DIALOG);

_mr1text = __CTRL(100105);
_mr2text = __CTRL(100106);

_mr1_available = true;
_mr2_available = true;

_mr1text ctrlSetText "";
_mr2text ctrlSetText "";

#ifdef __TT__
if (GVAR(player_side) == west) then {
#endif
switch (true) do {
	case (__XJIPGetVar(mr1_in_air)): {
		_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_592");
		_mr1_available = false;
	};
	case (speed MRR1 > 4): {
		_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_593");
		_mr1_available = false;
	};
	case (surfaceIsWater [(position MRR1) select 0,(position MRR1) select 1]): {
		_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_594");
		_mr1_available = false;
	};
	case (!(if (!isNil {GV(MRR1,ace_canmove)}) then {MRR1 call ace_v_alive} else {alive MRR1})): {
		_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_595");
		_mr1_available = false;
	};
	default {
		_depl = GV(MRR1,GVAR(MHQ_Deployed));
		if (isNil "_depl") then {_depl = false};
		if (!_depl) then {
			_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_596");
			_mr1_available = false;
		} else {
			_enear = GV(MRR1,GVAR(enemy_near));
			if (!isNil "_enear") then {
				if (_enear) then {
					_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_597");
					_mr1_available = false;
				};
			};
		};
	};
};
switch (true) do {
	case (__XJIPGetVar(mr2_in_air)): {
		_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_598");
		_mr2_available = false;
	};
	case (speed MRR2 > 4): {
		_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_599");
		_mr2_available = false;
	};
	case (surfaceIsWater [(position MRR2) select 0,(position MRR2) select 1]): {
		_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_600");
		_mr2_available = false;
	};
	case (!(if (!isNil {GV(MRR2,ace_canmove)}) then {MRR2 call ace_v_alive} else {alive MRR2})): {
		_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_601");
		_mr2_available = false;
	};
	default {
		_depl = GV(MRR2,GVAR(MHQ_Deployed));
		if (isNil "_depl") then {_depl = false};
		if (!_depl) then {
			_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_602");
			_mr2_available = false;
		} else {
			_enear = GV(MRR2,GVAR(enemy_near));
			if (!isNil "_enear") then {
				if (_enear) then {
					_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_603");
					_mr2_available = false;
				};
			};
		};
	};
};
#ifdef __TT__
} else {
	switch (true) do {
		case (__XJIPGetVar(mrr1_in_air)): {
			_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_592");
			_mr1_available = false;
		};
		case (speed MRRR1 > 4): {
			_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_593");
			_mr1_available = false;
		};
		case (surfaceIsWater [(position MRRR1) select 0,(position MRRR1) select 1]): {
			_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_594");
			_mr1_available = false;
		};
		case (!alive MRRR1): {
			_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_595");
			_mr1_available = false;
		};
		default {
			_depl = GV(MRRR1,GVAR(MHQ_Deployed));
			if (isNil "_depl") then {_depl = false};
			if (!_depl) then {
				_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_596");
				_mr1_available = false;
			} else {
				_enear = GV(MRRR1,GVAR(enemy_near));
				if (!isNil "_enear") then {
					if (_enear) then {
						_mr1text ctrlSetText (localize "STR_DOM_MISSIONSTRING_597");
						_mr1_available = false;
					};
				};
			};
		};
	};
	switch (true) do {
		case (__XJIPGetVar(mrr2_in_air)): {
			_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_598");
			_mr2_available = false;
		};
		case (speed MRRR2 > 4): {
			_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_599");
			_mr2_available = false;
		};
		case (surfaceIsWater [(position MRRR2) select 0,(position MRRR2) select 1]): {
			_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_600");
			_mr2_available = false;
		};
		case (!alive MRRR2): {
			_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_601");
			_mr2_available = false;
		};
		default {
			_depl = GV(MRRR2,GVAR(MHQ_Deployed));
			if (isNil "_depl") then {_depl = false};
			if (!_depl) then {
				_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_602");
				_mr2_available = false;
			} else {
				_enear = GV(MRRR2,GVAR(enemy_near));
				if (!isNil "_enear") then {
					if (_enear) then {
						_mr2text ctrlSetText (localize "STR_DOM_MISSIONSTRING_603");
						_mr2_available = false;
					};
				};
			};
		};
	};
};
#endif

if (GVAR(x_loop_end)) exitWith {};

if (!_mr1_available) then {
	__CTRL(100108) ctrlEnable false;
	if (GVAR(beam_target) == 1) then {
		GVAR(beam_target) = -1;
		__CTRL(100110) ctrlSetText "";
	};
} else {
	__CTRL(100108) ctrlEnable true;
};

if (!_mr2_available) then {
	__CTRL(100109) ctrlEnable false;
	if (GVAR(beam_target) == 2) then {
		GVAR(beam_target) = -1;
		__CTRL(100110) ctrlSetText "";
	};
} else {
	__CTRL(100109) ctrlEnable true;
};

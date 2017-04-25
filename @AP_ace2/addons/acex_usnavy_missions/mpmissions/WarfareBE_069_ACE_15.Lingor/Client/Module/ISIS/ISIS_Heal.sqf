Private ['_anim','_anims','_canBePlaceAt','_dy','_dx','_fPos','_healer','_healTime','_injured','_near','_nearA','_nearB','_placeAtA','_posA','_posB','_posh','_posi','_relPosA','_relPosB','_success'];

_injured = _this select 0;
_healer = _this select 1;

_posA = [0.75,0.15,0];
_posB = [-0.75,0.1,0];

_relPosA = _injured modelToWorld [((_injured worldToModel (getPos _injured)) select 0) +(0.75),((_injured worldToModel (getPos _injured)) select 1) + (0.15),0];
_relPosB = _injured modelToWorld [((_injured worldToModel (getPos _injured)) select 0) -(0.75),((_injured worldToModel (getPos _injured)) select 1) + (0.1),0];

_placeAtA = objNull;
_near = ((getPos _injured) nearEntities ["Man",10]) - [_healer,_injured];
_nearA = 0;
_nearB = 0;
if (count _near > 0) then {
	{
		_nearA = if (_x distance _relPosA < 1) then {1 + _nearA} else {0 + _nearA};
		_nearB = if (_x distance _relPosB < 1) then {1 + _nearB} else {0 + _nearB};
	} forEach _near;
};

if (_nearA > 0 && _nearB > 0) exitWith {};

_placeAtA = objNull;
if (_nearA == 0 && _nearB == 0) then {
	_placeAtA = if (_healer distance _relPosA < _healer distance _relPosB) then {true} else {false};
} else {
	if (_nearA > 0 && _nearB == 0) then {_placeAtA = false} else {true};
	if (_nearB > 0 && _nearA == 0) then {_placeAtA = true} else {false};
};

_fPos = if (_placeAtA) then {_posA} else {_posB};

_healer playAction "medicStartRightSide";
_healer attachTo [_injured, _fPos];
sleep 0.01;

_posh = _healer modelToWorld [0,0,0]; 
_posi = _injured modelToWorld [0,+0.08,0];
_dy = (_posh select 1) - (_posi select 1); _dx = (_posh select 0) - (_posi select 0);
_healer setDir (270- (_dy atan2 _dx) - direction _injured);

_healTime = time;
_anims = [
"ainvpknlmstpsnonwrfldnon_medic",
"ainvpknlmstpsnonwrfldnon_medic0s",
"ainvpknlmstpsnonwrfldnon_medic0",
"ainvpknlmstpsnonwrfldnon_medic1",
"ainvpknlmstpsnonwrfldnon_medic2",
"ainvpknlmstpsnonwrfldnon_medic3",
"ainvpknlmstpsnonwrfldnon_medic4",
"ainvpknlmstpsnonwrfldnon_medic5",
"ainvpknlmstpsnonwrfldr_medic0s",
"ainvpknlmstpsnonwrfldr_medic0",
"ainvpknlmstpsnonwrfldr_medic1",
"ainvpknlmstpsnonwrfldr_medic2",
"ainvpknlmstpsnonwrfldr_medic3",
"ainvpknlmstpsnonwrfldr_medic4",
"ainvpknlmstpsnonwrfldr_medic5",
"amovppnemstpsraswrfldnon_amovpknlmstpsraswrfldnon",
"ainvpknlmstpsnonwrfldnon_ainvpknlmstpsnonwrfldnon_medic"
];

sleep 2;

while {true} do {
	sleep 0.5;
	_anim = animationState _healer;
	if !(_anim in _anims) exitWith {diag_log Format["%1",animationState _healer]};
	if (!alive _injured || !(_injured getVariable "stunned")) exitWith {_healer playActionNow "medicStop"};
	if (time - _healTime > 40) exitWith {_healer playActionNow "medicStop";_injured setVariable ["stunned",false,true]};
	if !(alive _healer) exitWith {};
};

detach _healer;
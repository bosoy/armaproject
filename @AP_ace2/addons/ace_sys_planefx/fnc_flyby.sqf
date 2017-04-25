#define SLEEP_TIME 19

private ["_dist","_fnc_SoundFX", "_minSpeed"];

_minSpeed 	= 350;
_dist 		= 0;

_fnc_SoundFX =
{
	if (_dist > 99 && _dist <= 1000) 	then {playsound "ace_fx_jetflybyshort"; sleep SLEEP_TIME;};
	if (_dist > 1000 && _dist <= 1800) 	then {playsound "ace_fx_jetflybyfar"; 	sleep SLEEP_TIME;};
};

if(_this isKindOf "Su34" || _this isKindOf "ACE_T10" || _this isKindOf "L39_TK_EP1" || _this isKindOf "ACE_Su30" || _this isKindOf "ACE_Su34")then
{
	_fnc_SoundFX =
	{
		if (_dist > 99 && _dist <= 800) 	then {playsound "ace_fx_jetflybysu"; 	sleep SLEEP_TIME;};
		if (_dist > 800 && _dist <= 1800) 	then {playsound "ace_fx_jetflybyfar"; 	sleep SLEEP_TIME;};
	};
};

if(_this isKindOf "A10" || _this isKindOf "Su25_base")then
{
	_minSpeed = 180;
	_fnc_SoundFX =
	{
		if (_dist > 99 && _dist <= 500) 	then {playsound "ace_fx_jetflybya10"; 	sleep SLEEP_TIME;};
	};
};

if(_this isKindOf "AV8B2")then
{
	_fnc_SoundFX =
	{
		if (_dist > 99 && _dist <= 1000) 	then {playsound "ace_fx_jetflybyharrier"; 	sleep SLEEP_TIME;};
		if (_dist > 1000 && _dist <= 1800) 	then {playsound "ace_fx_jetflybyfar"; 		sleep SLEEP_TIME;};
	};
};

while {alive _this} do 
{
	sleep 2;
	if(!(vehicle player isKindOf "Plane"))then
	{
		if(speed _this > _minSpeed)then
		{
			_dist = player distance _this;
			_this call _fnc_SoundFX;
		};
	};
};

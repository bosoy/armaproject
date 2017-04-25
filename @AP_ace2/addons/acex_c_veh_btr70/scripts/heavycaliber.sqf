private ["_u", "_sh","_i","_no","_int","_vel","_p3d","_light","_li","_speed","_flashspeed"];
_u = _this select 0;
_sh = _this select 6;
_i=1;
_no=2;
_speed = velocity _u;
_flashspeed = [_speed select 0, _speed select 1, _speed select 2];
//Flash

drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32], //objecct
"",																//Animation name
"Billboard",													//Type
1,																//Timer periods
(0.12 + 0.015*_i), 												//Life time
[0,0.7,0.1], 													//Position
[0,1,0],														//move velocity
0, 																//rotation velocity
10,																//weight
0.5,															//volume
0.075,															//rubbing
[0.5, _i*1],														//size
[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]], 	//color
[3 + random 2],													//Animation Phase
0,																//Random dir
0, 																//Random dir intensity
"", 															//On timer
"", 															// before destroy
_sh];

// Night Light
_li = "#lightpoint" createVehicleLocal getpos _sh;
_li setLightBrightness 0.02;
_li setLightAmbient[0.8, 0.6, 0.2];
_li setLightColor[1, 0.5, 0.2];
//_li lightAttachObject [_u, [0,1.1,0.1]];


//Smoke
private ["_weh","_life"];
_u= _this select 0;
_sh = nearestobject [_u, _this select 4];
if ((_u iskindof "Helicopter") && (isengineOn _u)) then
	{
	_weh=1;
	_life= 0.8;
	} else {
	_weh = 0.104;
	_life= 1.3 + random 0.6;
	};

drop [["\ca\Data\ParticleEffects\Universal\Universal",16,12,8],
	"",

	"Billboard",
	1,
	_life,
	[0, 1.1, 0.1],
	[0, 5 + random 4, 0],
	0,
	_weh,
	0.08,
	0.2,
	[1.5, 5 + random 3],
	[[0.7, 0.7, 0.7, 0.2 + random 0.1],
	[0.8, 0.8, 0.8, 0]],
	[1/_life], 1, 0, "", "", _sh,random 360];

drop [["\ca\Data\ParticleEffects\Universal\Universal",16,12,8],
	"",
	"Billboard",
	1,
	0.3,
	[0, 1.1, 0.1],
	[0, 0, 0],
	0,
	_weh,
	0.08,
	0.5,
	[0.4, 2.5],
[[0.3, 0.3, 0.3, 0],[0.5, 0.5, 0.5, 0.25],[0.7, 0.7, 0.7, 0]],
 [2],
 1,
 0,
 "",
 "",
 _sh,
 random 360];

_li spawn
{
	sleep 0.05;
	deletevehicle _this;
};



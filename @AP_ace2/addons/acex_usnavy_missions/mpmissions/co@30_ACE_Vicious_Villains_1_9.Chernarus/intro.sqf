
setViewDistance 1600;
enableRadio false;

_camera = "camera" camCreate [(position camstart select 0), (position camstart select 1) + 2, 14];
_camera camSetTarget [(position camtarget select 0), (position camtarget select 1) , 15];
_camera camSetFov 1.5;
_camera cameraEffect ["INTERNAL", "Back"];
_camera camCommit 6;
waitUntil {camCommitted _camera};
sleep 6;
_camera = "camera" camCreate [(position camstart1 select 0), (position camstart1 select 1) + 2, 14];
_camera camSetTarget [(position camtarget1 select 0), (position camtarget1 select 1) , 15];
_camera camSetFov 1.5;
_camera cameraEffect ["INTERNAL", "Back"];
_camera camCommit 6;
waitUntil {camCommitted _camera};
sleep 7;
player cameraEffect ["terminate","back"];
camDestroy _camera;
closeDialog 0;
enableRadio true;
setViewDistance 1400;

if (true) exitWith {};
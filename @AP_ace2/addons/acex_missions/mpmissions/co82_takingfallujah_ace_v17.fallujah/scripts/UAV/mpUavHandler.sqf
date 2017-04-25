MP_UAV_Handler_CurrentUAV = objNull;
MP_UAV_Handler_Height = 500;
MP_UAV_Handler_Speed = 100;
if (isServer) then
{
    if (isNil "MP_UAV_Handler_INIT") then {
        "MP_UAV_Handler_Height" addPublicVariableEventHandler
            {_h = _this select 1; MP_UAV_Handler_CurrentUAV flyInHeight _h; };
        "MP_UAV_Handler_Speed" addPublicVariableEventHandler
            {_s = _this select 1; driver MP_UAV_Handler_CurrentUAV forceSpeed (_s / 3.6); };
        MP_UAV_Handler_INIT = true;
    };
}
else
{
    waitUntil {sleep 3.0; local player};
    [] spawn {
        private ["_uav", "_newHeight", "_newSpeed"];
        while {true} do {
            if (!(isNil "BIS_UAV_PLANE")) then {
                _uav = BIS_UAV_PLANE;
                if (_uav != MP_UAV_Handler_CurrentUAV) then {
                    MP_UAV_Handler_CurrentUAV = _uav;
                    publicVariable "MP_UAV_Handler_CurrentUAV";
                    sleep 2.0;
                };
                _newHeight = _uav getVariable "BIS_UAV_height";
                _newSpeed = _uav getVariable "BIS_UAV_speed";
                if (_newHeight != MP_UAV_Handler_Height) then {
                    MP_UAV_Handler_Height = _newHeight;
                    publicVariable "MP_UAV_Handler_Height";
                };
                sleep 0.2;
                if (_newSpeed != MP_UAV_Handler_Speed) then {
                    MP_UAV_Handler_Speed = _newSpeed;
                    publicVariable "MP_UAV_Handler_Speed";
                };
            };
            sleep 5.0;
        };
    };
};
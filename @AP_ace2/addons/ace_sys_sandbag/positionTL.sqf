#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __ANIMS ["extract_1","extract_2","extract_3","extract_4","extract_5","extract_6","extract_7","extract_8","extract_9","extract_10","extract_11"]

_ladder = _this;

{ _ladder animate [_x,0] } foreach __ANIMS;

player switchMove "amovpercmstpslowwrfldnon_player_idlesteady03";
_ladder attachTo [player,[0,0.75,0],""]; // Position ladder in front of player
_ladder setVariable [QGVAR(inUse),true,true]; // In Use!

_ladder animate ["rotate",0];
{ _ladder animate [_x,1] } foreach ["extract_1","extract_2","extract_3"]; // Extract ladder at head height (extract_3)

GVAR(ladder) = _ladder;
GVAR(currentStep) = 3;
GVAR(currentAngle) = 0;

call FUNC(ladderKey_add);

_action_drop = player addAction [localize "STR_ACE_DROP_TACLADDER","\x\ace\addons\sys_sandbag\cancelTLdeploy.sqf",_ladder];
_action_deploy = player addAction [localize "STR_ACE_DEPLOY_TACLADDER","\x\ace\addons\sys_sandbag\confirmTLdeploy.sqf",_ladder];

player setVariable [QGVAR(TLdeployAction),_action_deploy];
player setVariable [QGVAR(TLdropAction),_action_drop];

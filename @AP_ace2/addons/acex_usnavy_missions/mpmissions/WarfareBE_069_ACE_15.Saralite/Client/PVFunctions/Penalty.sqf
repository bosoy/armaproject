Private['_fee','_pfunds','_result'];

_fee = 'WFBE_CIVILIANPENALTY' Call GetNamespace;
Format[Localize "STR_WF_Penalty",_fee] Call GroupChatMessage;

_pfunds = Call GetPlayerFunds;
_result = _pfunds - _fee;
if (_result < 0) then {_fee = _fee + _result};
-(_fee) Call ChangePlayerFunds;
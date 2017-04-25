// displays flag capture message
// waits until message box isn't taken, send the message, wait 5 seconds and release the message box
// first parameter: flag captured.
// second parameter: capturing faction

waitUntil {msgFree};
msgFree=false;
titleText [format ["Flag %1 control taken by %2", (_this select 0)+1, _this select 1],"plain down"];
sleep 5;
msgFree=true;
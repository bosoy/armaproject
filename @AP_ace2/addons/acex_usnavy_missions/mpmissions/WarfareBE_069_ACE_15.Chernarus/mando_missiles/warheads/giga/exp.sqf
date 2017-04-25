_fallposx = _this select 0;
_fallposy = _this select 1;

[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_light.sqs";

[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_glare.sqs";

[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_hat.sqs";

[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_blast1.sqs";
Sleep 0.1;

[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_blast2.sqs";
Sleep 0.2;
[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_blast3.sqs";

[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\nuke_exp.sqs";

//[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\sndnuke.sqs";

Sleep 10;
[_fallposx,_fallposy] exec "mando_missiles\warheads\giga\rdoact.sqs";
/*
Sleep 60;
[_fallposx,_fallposy] exec "\GIG_Scud\rain.sqs";
*/


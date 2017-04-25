while {true} do
{
	waitUntil {showScore};
	waitUntil {msgFree};
	titleText [format ["US: %1 ... RU: %2", ScoreW, ScoreE],"plain down"];
	showScore=false;
};
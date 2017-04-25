private ["_i", "_condition"];
_i=0;

if (maxScore==-1) then
{
	_condition={true};
}
else
{
	_condition={scoreW<maxScore && scoreE<maxScore};
};

// update score every second and send it out every 30 seconds

showScore=true;

while _condition do
{	
	sleep 1;
	scoreW = scoreW + ({_x>0} count flags);
	scoreE = scoreE + ({_x<0} count flags);
	_i=_i+1;
	if (_i==30) then
	{
		showScore=true;
		publicVariable "scoreW";
		publicVariable "scoreE";
		publicVariable "showScore";
		_i=0;
	};
};

// game over!
if (scoreW>scoreE) then
{
	end1=true;
	publicVariable "end1";
	sleep 5;
	end1go=true;
};
if (scoreE>scoreW) then
{
	end2=true;
	publicVariable "end2";
	sleep 5;
	end2go=true;
}
else
{
	end3=true;
	publicVariable "end3";
	sleep 5;
	end3go=true;
};
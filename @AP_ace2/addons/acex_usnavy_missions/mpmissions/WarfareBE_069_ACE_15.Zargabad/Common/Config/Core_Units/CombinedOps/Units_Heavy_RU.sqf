Private ['_u'];

//--- Russian Heavy Vehicles.
_u 			= ['M113_TK_EP1'];
_u = _u		+ ['BMP2_INS'];
_u = _u		+ ['BMP2_TK_EP1'];
_u = _u		+ ['BMP3'];
_u = _u		+ ['ZSU_INS'];
_u = _u		+ ['ZSU_TK_EP1'];
_u = _u		+ ['T34_TK_EP1'];
_u = _u		+ ['T55_TK_EP1'];
_u = _u		+ ['T72_RU'];
_u = _u		+ ['T72_TK_EP1'];
_u = _u		+ ['2S6M_Tunguska'];

if (WF_ACE) then
{
	_u = _u + ["ACE_T90A"];
}
else
{
	_u = _u + ['T90'];
};

_u
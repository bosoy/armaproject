/* =============================================
	!R
	Hide area markers.
	
	create Game Logic Object
	put in initialization field:
	
		nul = call compile preprocessFile "scripts\UPSMON\!R\markerAlpha.sqf";
		
================================================= */

{ _x setMarkerAlphaLocal 0; } foreach ["m1", "m2", "m3"];
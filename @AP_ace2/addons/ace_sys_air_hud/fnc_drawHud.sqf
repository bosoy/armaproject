//fnc_drawHud.sqf
#include "script_component.hpp"
// _start = diag_tickTime;
if(cameraView == "INTERNAL" && {!visibleMap}) then {
	if((vehicle player) != GVAR(ccip_plane) || {!alive GVAR(ccip_plane)} || {!alive player} || {player call ace_sys_wounds_fnc_isUncon}) exitWith {
		[] call FUNC(cleanUp);
		GVAR(ccip_plane) = nil;
		(uiNamespace getVariable "ACE_HUD_RSC") closeDisplay 1;
	};
	/*
	Resize the map control canvas.
	*/
	_hudRsc = uiNamespace getVariable "ACE_HUD_RSC";
	_canvas = _this select 0;
	_canvas ctrlMapAnimAdd [0, 0.0001, [21,21]];
	ctrlMapAnimCommit _canvas;
	
	/*
	Convert the defined corners of the HUD to model space,
	then world space, and finally to screen space.
	*/
	_mUl = (GVAR(ccip_plane) selectionPosition "HUD LH");
	_mLl = (GVAR(ccip_plane) selectionPosition "HUD LD");
	_mUr = (GVAR(ccip_plane) selectionPosition "HUD PH");
	
	_wUl = (GVAR(ccip_plane) modelToWorld _mUl);
	_wLl = (GVAR(ccip_plane) modelToWorld _mLl);
	_wUr = (GVAR(ccip_plane) modelToWorld _mUr);

	_ul = worldToScreen _wUl;
	_ll = worldToScreen _wLl;
	_ur = worldToScreen _wUr;
	
	/*
	Since the canvas can resize when you are on different maps we
	need to make sure to figure out a multiplier ratio for what to
	offset all the measured drawing values by. The initial value here
	defined in MAGIC_SIZE is based on the canvas distance between the
	upper left and upper right edges of the HUD on a 20x20km map.
	*/
	if(isNil QGVAR(hudMagicRatio) && GVAR(hudInitSized)) then {
		_cUl = _canvas ctrlMapScreenToWorld _ul;
		_cUr = _canvas ctrlMapScreenToWorld _ur;
		_dif = (_cUr select 0)-(_cUl select 0);
		// This subtraction below is hackish, but it accounts for bugs when the display first appears and your camera is moving
		GVAR(hudMagicRatio) = (_dif/MAGIC_SIZE)-((_dif/MAGIC_SIZE)*0.25);
		// player sideChat format["ms: %1 mr: %2", MAGIC_SIZE, GVAR(hudMagicRatio)];
	};
	
	
	/*
	Make sure that we actually have all the points in the HUD...
	*/
	if((count _ul) == 0 || (count _ll) == 0 || (count _ur) == 0 || (count GVAR(dropPos)) == 0) then {
		_canvas ctrlSetPosition [0,0,0];
		_canvas ctrlCommit 0;
	} else {
		/*
		This code resizes the canvas to the width and height of the hud.
		*/
		_resize = [_ul select 0, _ul select 1, (_ur select 0)-(_ul select 0), (_ll select 1)-(_ul select 1)];
		_canvas ctrlSetPosition _resize;
		_canvas ctrlCommit 0;
		GVAR(hudInitSized) = true;
		
		/*
		This code defines some variables used in drawing.
		They scale correctly with the HUD so they should be
		used instead of using hardcoded values.
		*/
		_width = (((_ur select 0)-(_ul select 0))/2);
		_height = (((_ul select 1)-(_ll select 1))/2);
		_horzCenter = (_ul select 0)+_width;
		_vertCenter = (_ul select 1)+_height;
		_width = (_width/10)*GVAR(hudMagicRatio);
		_height = (_height/10)*GVAR(hudMagicRatio);
		
		/*
		The code below is for the Flight Path Marker, or FPM. The FPM
		shows on the HUD approximatly where your aircraft is headed in
		relation to its velocity. Basically if you enter a turn, your
		aircraft is not going to be going in the direction of the nose
		immediately. It's physical movement through space will lag as
		it shifts its momentum in the new direction.
		
		First we get our local vectors for the planes nose direction, and
		it's velocity.
		*/
		_velUnit = (velocity GVAR(ccip_plane));
		_d = (getDir GVAR(ccip_plane));
		_localVelVec = +_velUnit;
		// _localVelVec set [0, (cos _d)*(_velUnit select 0) - (sin _d)*(_velUnit select 1)];
		// _localVelVec set [1, (sin _d)*(_velUnit select 0) + (cos _d)*(_velUnit select 1)];
		
		_planeVec = vectorDir GVAR(ccip_plane);
		_localPlaneVec = +_planeVec;
		_localPlaneVec set [0, (cos _d)*(_planeVec select 0) - (sin _d)*(_planeVec select 1)];
		_localPlaneVec set [1, (sin _d)*(_planeVec select 0) + (cos _d)*(_planeVec select 1)];
		
		_mag = sqrt ((_localVelVec select 0)^2 + (_localVelVec select 1)^2 + (_localVelVec select 2)^2);
		/*
		Make magnify the local direction vector by the speed of the aircraft
		*/		
		_localPlaneVec = [
								(_localPlaneVec select 0)*_mag,
								(_localPlaneVec select 1)*_mag,
								(_localPlaneVec select 2)*_mag
							];
		/*
		And now create the offset vector from which we will project
		into world space.
		*/
		_offsetVec =
					[
						((_localVelVec select 0)-(_localPlaneVec select 0)),
						((_localVelVec select 1)-(_localPlaneVec select 1)),
						((_localVelVec select 2)-(_localPlaneVec select 2))
					];
		_pos = getPosASL GVAR(ccip_plane);
		_offsetVec =
					[
						((_pos select 0)+(_localVelVec select 0)),
						((_pos select 1)+(_localVelVec select 1)),
						((_pos select 2)+(_localVelVec select 2))
					];
		/*
		Project the offset vector into world space from model space, and then screen space.
		*/
		// _fpmWorldPos = (GVAR(ccip_plane) modelToWorld (ASLtoATL _offsetVec));
		_fpmScreenPos = (worldToScreen (ASLtoATL _offsetVec));
		/*
		If its empty exit drawing the HUD because it is obviously out of bounds
		*/
		if((count _fpmScreenPos) == 0) exitWith { };
		
		/*
		Now convert the screen space to the canvas and draw the FPM!
		*/
		_fpmPos = _canvas ctrlMapScreenToWorld _fpmScreenPos;
		_canvas drawEllipse [_fpmPos, _width*0.75, _width*0.75, 0, HUDCOLOR, ""];
		
		_fpm1 = [_fpmPos, _width*0.75, 0] call BIS_fnc_relPos;
		_fpm2 = [_fpmPos, (_width*0.75)+(_width*0.75), 0] call BIS_fnc_relPos;
		_canvas drawLine [_fpm1, _fpm2, HUDCOLOR];
		
		_fpm1 = [_fpmPos, _width*0.75, 90] call BIS_fnc_relPos;
		_fpm2 = [_fpmPos, (_width*0.75)+(_width*0.75), 90] call BIS_fnc_relPos;
		_canvas drawLine [_fpm1, _fpm2, HUDCOLOR];
		
		_fpm1 = [_fpmPos, _width*0.75, -90] call BIS_fnc_relPos;
		_fpm2 = [_fpmPos, (_width*0.75)+(_width*0.75), -90] call BIS_fnc_relPos;
		_canvas drawLine [_fpm1, _fpm2, HUDCOLOR];
		
		/*
		OK now we are into the weapons systems for the HUD symbology.
		*/
		_weaponMode = [] call FUNC(getWeaponMode);
		if(_weaponMode == "") exitWith { }; // exit if we are not in a weapon mode.
		
		/*
		First off, bombs. This includes guided bombs, CBU, and of course good old dumb bombs.
		*/
		if(_weaponMode == "bomb" || _weaponMode == "lgb") then {
			/*
			Call the CCIP impact calculations initially...
			*/
			[] call FUNC(ccip);
			// player sideChat format["_weaponMode: %1", _weaponMode];
			_currentTarget = nil;
			if(_weaponMode == "lgb") then {
				_results = [GVAR(ccip_plane), 1001, 60, _velUnit, [0,-2,0]] call ace_sys_missileguidance_fnc_findLaserDesignator;
				// player sideChat format["res: %1", _results];
				_found = _results select 0;
				if(_found) then {
					_currentTarget = _results select 1;
					_targetScreenPos = (worldToScreen (getPos _currentTarget));
					_p1 = [0,0];
					_p2 = [0,0];
					_offScreen = false;
					if(_targetScreenPos select 0 < _resize select 0) then {
						_offScreen = true;
						_p1 = [_resize select 0, _resize select 1];
						_p2 = [_resize select 0, (_resize select 0)+(_resize select 3)];
					} else {
						if(_targetScreenPos select 1 < _resize select 1) then {
							_offScreen = true;
							_p1 = [_resize select 0, _resize select 1];
							_p2 = [_resize select 0, (_resize select 1)+(_resize select 2)];
						} else {
							if(_targetScreenPos select 0 > (_resize select 0)+(_resize select 2)) then {
								_offScreen = true;
								_p1 = [(_resize select 0)+(_resize select 2), _resize select 1];
								_p2 = [(_resize select 0)+(_resize select 2), (_resize select 0)+(_resize select 3)];
							} else {
								if(_targetScreenPos select 1 > (_resize select 1)+(_resize select 3)) then {
									_offScreen = true;
									_p1 = [_resize select 0, (_resize select 1)+(_resize select 3)];
									_p2 = [(_resize select 0)+(_resize select 2), (_resize select 1)+(_resize select 3)];
								};
							};
						};
					};
					if(_offScreen) then {
						_p3 = [_horzCenter, _vertCenter];
						_p4 = _targetScreenPos;
						_intersect = [_p1, _p2, _p3, _p4] call FUNC(lineLineIntersect);
						//player sideChat format["intersect: %1 = %2", [_p1, _p2, _p3, _p4], _intersect];
						if(!isNil "_intersect") then {
							_targetScreenPos = _intersect;
						};
					};
					_targetPos = _canvas ctrlMapScreenToWorld _targetScreenPos;
					_canvas drawRectangle [_targetPos, _width*1.2, _width*1.2, 45, HUDCOLOR, ""];
					_canvas drawEllipse [_targetPos, _width/6, _width/6, 0, HUDCOLOR, ""];
				} else {
					_currentTarget = nil;
				};
			};
			
			/*
			If the pickle is not depressed then we need to calculate and show either
			the bomb release point (pipper) or whatever other target mode display we
			are in (steerpoint, laser spot, DTOSS, etc).
			*/
			if(!GVAR(CCRP_CONSENTING)) then {
				switch GVAR(CCIP_TARGET_TYPE) do {
					case "pipper": {
						/*
						Convert the world pos of the impact position to a screen pos.
						
						This will help determine if the system is in immediate CCIP release
						mode, or in consented CCRP release mode.
						*/
						_screenDropPos = (worldToScreen (ASLtoATL GVAR(dropPos)));
						// GVAR(dropPos) set[2, 0];
						
						if((count _screenDropPos) > 0) then { // if its not on the screen, don't draw it!
							/*
							Our first step is to determine if we are in CCIP immediate release or
							we are in CCIP to CCRP consented release mode.
							
							CCIP immediate release will show a solid line between the FPM and the
							pipper and when the pickle is depressed the bombs will shack with out
							any delay. 
							
							If the pipper is beyond lower edge of the HUD then the line from the 
							FPM to the pipper is dashed. When the pickle is depressed the system
							will then wait till the bombs are within range and release.
							
							Below we see if the pipper is below the HUD or not.
							*/
							_pipperPos = _canvas ctrlMapScreenToWorld _screenDropPos;
							_lowerLimit = _canvas ctrlMapScreenToWorld _ll;
							_disPos = [_fpmPos select 0, _lowerLimit select 1];
							_distance = _fpmPos distance _disPos;
							_dirToPipper = [_fpmPos, _pipperPos] call BIS_fnc_dirTo;
							_distance = _distance-(_distance/5);
							if((_fpmPos distance _pipperPos) > _distance) then {
								/*
								The pipper is below the HUD, so we need to make a new pipper pos
								that is aligned vertically with the real impact position, but hovers
								at the bottom of the HUD for use of designating a release point.
								*/
								_pipperPosNewPos = [_fpmPos, _distance, _dirToPipper] call BIS_fnc_relPos;
								_pipperPos = [_pipperPos select 0, _pipperPosNewPos select 1];
								_pipperScreenPos = _canvas ctrlMapWorldToScreen _pipperPos;
								_pipperWorldPos = ATLtoASL (screenToWorld _pipperScreenPos);
								
								/*
								We must assign the target position here based on the world position of
								the new pipper. This needs to update every time the pipper moves as it
								is used when the pickle is depressed to start running the release cal-
								culations.
								*/
								GVAR(CONSENT_TARGETPOS) = _pipperWorldPos;
								
								/*
								Make sure that we are NOT in an immeditate release mode.
								*/
								GVAR(CCIP_IMMEDIATE_RELEASE) = false;
								
								/*
								Draw the connecting line to the pipper from FPM, this is dashed in CCIP to CCRP.
								*/
								_dirToFall = [_pipperPos, _fpmPos] call BIS_fnc_dirTo;
								_connectPos = [_pipperPos, (_width*1.5), _dirToFall] call BIS_fnc_relPos;
								[_canvas, _fpmPos, _connectPos, _width*2] call FUNC(drawDashedLine);
							} else {
								/*
								The pipper is fully visible on our screen. Where you see the pipper
								is where the bombs will hit when the pickle is depressed.
								
								Lets clear the consent mode target position, since its not needed in
								this mode.
								*/
								GVAR(CONSENT_TARGETPOS) = [];
								/*
								We need to set the immediate release mode to true.
								*/
								GVAR(CCIP_IMMEDIATE_RELEASE) = true;
								
								/*
								Draw the line to the pipper from the FPM.
								*/
								_dirToFall = [_pipperPos, _fpmPos] call BIS_fnc_dirTo;
								_connectPos = [_pipperPos, (_width*1.5), _dirToFall] call BIS_fnc_relPos;
								_canvas drawLine [_fpmPos, _connectPos, HUDCOLOR];
							};
							/*
							Draw the pipper!
							*/
							_canvas drawEllipse [_pipperPos, _width*1.5, _width*1.5, 0, HUDCOLOR, ""];
							_canvas drawEllipse [_pipperPos, _width/4, _width/4, 0, HUDCOLOR, ""];
						};
					};
				};
			} else {
				/*
				We are in consented release mode.
				*/
				
				/*
				Lets get the targets screen position and convert it to
				the canvas position.
				*/
				_targetScreenPos = (worldToScreen (ASLtoATL GVAR(CONSENT_TARGETPOS)));
				_targetPos = _canvas ctrlMapScreenToWorld _targetScreenPos;
				
				/*
				Now we can draw the target position box. It is a rectangle with
				a dot inside of it.
				*/
				_canvas drawRectangle [_targetPos, _width*1, _width*1, 0, HUDCOLOR, ""];
				_canvas drawEllipse [_targetPos, _width/6, _width/6, 0, HUDCOLOR, ""];
				
				/*
				Now we handle the release mechanics of the system, including drawing
				the Bomb Release Cue, or BRC and the fall line.
				*/
				
				/*
				First we get the release distances.
				
				The first distance is the distance to releasing the weapon if we continued 
				flying the same flight path as we are now. The second is a distance to
				where the aircraft will enter a release envelope that allows the plane to
				loft the weapon.
				*/
				_releaseDistance = GVAR(CONSENT_TARGETPOS) distance GVAR(dropPos);
				_loftReleaseDistance = GVAR(CONSENT_TARGETPOS) distance GVAR(CCIP_LOFT_POS);
				/*
				The BRC ratio is how far up or down the fall line from the top to the FPM that
				the BRC will be drawn. The first ratio is based on the distance to the loft
				evenlope.
				*/
				_brcRatio = ((_fpmScreenPos select 1)+((_height)*(((_loftReleaseDistance/2500) max 0) min 1)));
				
				/*
				Now we check to see if we are in the loft envelope.
				*/
				if(_loftReleaseDistance > _releaseDistance || (GVAR(CCRP_LAST_LOFTRELEASECHECK) < _loftReleaseDistance)) then {
					/*
					If we are inside the envelope now can recalculate the BRC ratio based on the 
					release distance for our current flight profile. Right now the plane can be
					nosed up to a maximum of 40 degrees and the bombs will release sooner, as we
					are now inside the envelope for lofting the weapons.
					
					The BRC will usually now jump back up the fall line a distance.
					*/
					_brcRatio = ((_fpmScreenPos select 1)+((_height)*(((_releaseDistance/1500) max 0) min 1)));
					
					/*
					To show that we have entered the loft envelope we will flash the fall line and 
					BRC three times.
					*/
					if(!GVAR(CCIP_FLASH_MODE) && !GVAR(CCIP_FLASHED)) then {
						GVAR(CCIP_FLASH_MODE) = true;
						GVAR(CCIP_FLASHING) = true;
						GVAR(CCIP_FLASH_COUNT) = 0;
						GVAR(CCIP_FLASH_TIME) = diag_tickTime+CCIP_FLASHTIME;
						GVAR(CCIP_FLASHED) = false;
					};
				};
				
				/*
				If we are flashing the fall line, lets determine if we are flashing 
				it on or off.
				*/
				if(GVAR(CCIP_FLASH_MODE)) then {
					if(diag_tickTime >= GVAR(CCIP_FLASH_TIME)) then {
						GVAR(CCIP_FLASHING) = !GVAR(CCIP_FLASHING);
						GVAR(CCIP_FLASH_TIME) = diag_tickTime+CCIP_FLASHTIME;
						if(GVAR(CCIP_FLASHING)) then {
							GVAR(CCIP_FLASH_COUNT) = GVAR(CCIP_FLASH_COUNT) + 1;
						};
					};
				};
				
				/*
				If the fall line is not flashing lets show the fall line and BRC!
				*/
				if(!GVAR(CCIP_FLASHING)) then {
					_brcPos = _canvas ctrlMapScreenToWorld [_horzCenter, _brcRatio];
					_canvas drawLine [[(_targetPos select 0)-(_width*1.5), (_brcPos select 1)], [(_targetPos select 0)+(_width*1.5), (_brcPos select 1)], HUDCOLOR];
					_canvas drawLine [[_targetPos select 0, (_targetPos select 1)-160], [_targetPos select 0, (_targetPos select 1)+160], HUDCOLOR];
				};
				
				/*
				Check to see if we can exit flashing mode
				*/
				if(GVAR(CCIP_FLASH_MODE)) then {
					if(GVAR(CCIP_FLASH_COUNT) >= 3) then {
						GVAR(CCIP_FLASH_MODE) = false;
						GVAR(CCIP_FLASHING) = false;
						GVAR(CCIP_FLASHED) = true;
					};
				};
				
				/*
				Now that we have drawn the HUD symbology for the consented release
				mode, we can get to the mechanics of determining when the weapons
				will release.
				
				First we will determine a pickle range based off of the velocity
				of the aircraft, divided by the frames per second and then expanded
				to give a reasonable chance of accurate weapon release no matter the 
				frame rate.
				*/
				_velocityVec = velocity GVAR(ccip_plane);
				_Vx = _velocityVec select 0;
				_Vy = _velocityVec select 1;
				_Vz = _velocityVec select 2;
				_Vmag = sqrt (_Vx^2 + _Vy^2 + _Vz^2);
				_m = _Vmag/diag_fps;
				
				/*
				The pickle range will never be less than 25 meters, and will
				be twice the value of the velocity divided by the games's FPS.
				*/
				_pickleRange = (_m*2) max ((10*(diag_fps/30)) max 10);
				if(_weaponType == "lgb") then {
					_pickleRange = 400;
				};
				/*
				There are THREE checks for immediate bomb release, and a FOURTH check
				for releasing the weapon if the first three do not pass.
				
				First, we check if the distance between the impact position and the target
				position is less than the calculated pickle range above.
				
				Second, we check if the impact position has passed the target position, but
				the release distance is stil within range of one and half times the pickle
				range.
				
				Third, we check to see if this is an immediate release, which we check for
				in the else.
				*/
				// hintSilent format["%1 < %2\n%3", _releaseDistance, _pickleRange, GVAR(lastDropPos) distance GVAR(dropPos)];
				if(_releaseDistance < _pickleRange || ((GVAR(CCRP_LAST_RELEASECHECK) < _releaseDistance) && _releaseDistance < (_pickleRange*2.5)) || GVAR(CCIP_PREDICTEDRELEASE)) then {
					// hintSilent format["%1\n%2\n%3\n\n", _releaseDistance < _pickleRange, ((GVAR(CCRP_LAST_RELEASECHECK) < _releaseDistance) && _releaseDistance < (_pickleRange*1.5)), GVAR(CCIP_PREDICTEDRELEASE)];
					[] call FUNC(doBombRelease);
					[] call FUNC(cleanUp);
				} else {
					/*
					This double checks that we are not over shooting the drop pos
					by taking the distance between the current impact position and
					the last impact position and using that to see if the next frame
					will place the impact pos beyond the target position.
					*/					
					_sampleDistance = GVAR(lastDropPos) distance GVAR(dropPos);
					if((_sampleDistance > _releaseDistance)) then {
						GVAR(CCIP_PREDICTEDRELEASE) = true;
					} else {
						GVAR(CCIP_PREDICTEDRELEASE) = false;
					};
				};
				/*
				This is our check to see if we've irrecovarbly over shot the target
				position. We see if the plane is closer to the target than it is to
				the impact position, and if so then we check to make sure that the
				release distance is still not beyond a viable drop. If it is then
				we kill the consenting mode and reset the values that we need to
				reset.
				*/
				if((GVAR(ccip_plane) distance GVAR(CONSENT_TARGETPOS)) < (GVAR(ccip_plane) distance GVAR(dropPos))) then {
					if(_releaseDistance > (_pickleRange*2.5)) then {
						[] call FUNC(cleanUp);
					};
				} else {
					/*
					If we iterate again, update our data that we use
					to check the previous data.
					*/
					GVAR(CCRP_LAST_RELEASECHECK) = _releaseDistance;
					GVAR(CCRP_LAST_LOFTRELEASECHECK) = _loftReleaseDistance;
				};
			};
		};
		if(_weaponMode == "gun") then {
			_initSpeed = getNumber(configFile >> "CfgMagazines" >> GVAR(currentMagazineClass) >> "initSpeed");
			_vecDir = GVAR(ccip_plane) weaponDirection (currentWeapon GVAR(ccip_plane));
			_bulletVelVec = [
						(_vecDir select 0)*_initSpeed,
						(_vecDir select 1)*_initSpeed,
						(_vecDir select 2)*_initSpeed
					];
			// player sideChat format["v: %1", _bulletVelVec];
			_pos = GVAR(ccip_plane) modelToWorld (GVAR(ccip_plane) selectionPosition "kulomet");
			_pos = ATLtoASL _pos;
			_vel = (velocity GVAR(ccip_plane));
			_airFriction = getNumber(configFile >> "CfgAmmo" >> GVAR(currentAmmoClass) >> "airFriction");
			_draw = true;
			if(GVAR(smoothCount) == 5) then {
				GVAR(smoothCount) = 0;
				GVAR(currentGunImpactPos) = [_bulletVelVec, _pos, _airFriction, _vel] call FUNC(getImpactPos);
				GVAR(currentPipperPoint) = GVAR(nextPipperPoint);
				_screenPipperPos = (worldToScreen (ASLtoATL GVAR(currentGunImpactPos)));
				if((count _screenPipperPos) > 0) then {
					GVAR(nextPipperPoint) = _canvas ctrlMapScreenToWorld _screenPipperPos;
					GVAR(pipperDistance) = (GVAR(currentPipperPoint) distance GVAR(nextPipperPoint))/5;
				} else {
					_draw = false;
				};
			};
			if(_draw) then {
				_dirToSmooth = [GVAR(currentPipperPoint), GVAR(nextPipperPoint)] call BIS_fnc_dirTo;
				GVAR(currentPipperPoint) = [GVAR(currentPipperPoint), GVAR(pipperDistance), _dirToSmooth] call BIS_fnc_relPos;
				GVAR(smoothCount) = GVAR(smoothCount) + 1;
				_canvas drawEllipse [GVAR(currentPipperPoint), _width*3, _width*3, 0, HUDCOLOR, ""];
				_canvas drawEllipse [GVAR(currentPipperPoint), _width/4, _width/4, 0, HUDCOLOR, "\ca\ui\data\map_background2_co.paa"];
				_spokeCount = 8;
				for "_i" from 0 to _spokeCount-1 do {
					_sp1 = [GVAR(currentPipperPoint), _width*3, (_i*(360/_spokeCount))] call BIS_fnc_relPos;
					_sp2 = [GVAR(currentPipperPoint), (_width*3)+(_width/2), (_i*(360/_spokeCount))] call BIS_fnc_relPos;
					_canvas drawLine [_sp1, _sp2, HUDCOLOR];
				};
				_pos = screenToWorld (_canvas ctrlMapWorldToScreen GVAR(currentPipperPoint));
				_distance = _pos distance GVAR(ccip_plane);
				// _canvas drawIcon ["\ca\ui\data\markers\n_inf", HUDCOLOR, GVAR(currentPipperPoint), 1, 1, 0, "HI", 1];
				_ratio = floor(180*(((_distance/3500) min 1) max 0));
				// hintSilent format["r: %1", _ratio];
				for "_i" from 0 to _ratio-1 do {
					_pos = [GVAR(currentPipperPoint), _width*2.75, (_i*2)] call BIS_fnc_relPos;
					_canvas drawRectangle [_pos, _width/8, _width/4, (_i*2), HUDCOLOR, "\ca\ui\data\map_background2_co.paa"];
				};
				
			};
		};
	};
} else {
	_canvas ctrlSetPosition [0,0,0];
	_canvas ctrlCommit 0;
};
// _end = diag_tickTime;
// hintSilent format["t: %1", _end-_start];
////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:56 2013 : Created on Thu Jan 03 12:00:56 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_vectors : config.bin{
class CfgPatches
{
	class cba_vectors
	{
		units[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CBA_common","CBA_XEH"};
		version = "1.0.1.196";
		author[] = {"Vigilante"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class Extended_PreInit_EventHandlers
{
	class cba_vectors
	{
		init = "call ('\x\cba\addons\vectors\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgFunctions
{
	class CBA
	{
		class Vectors
		{
			class polar2vect
			{
				description = "Creates a vector based on a inputted magnitude, direction and elevation";
				file = "\x\cba\addons\vectors\fnc_polar2vect.sqf";
			};
			class scaleVect
			{
				description = "scales a specified vector by a specified factor.";
				file = "\x\cba\addons\vectors\fnc_scaleVect.sqf";
			};
			class scaleVectTo
			{
				description = "scales a vector so that its new Magnitude is equivalent to a specified value.";
				file = "\x\cba\addons\vectors\fnc_scaleVectTo.sqf";
			};
			class simplifyAngle
			{
				description = "Returns an equivalent angle to the specified angle in the range 0 to 360. This allows adjustment from negative angles and angles equal or greater to 360. If the inputted angle is in the range 0 - 360, it will be returned unchanged.";
				file = "\x\cba\addons\vectors\fnc_simplifyAngle.sqf";
			};
			class simplifyAngle180
			{
				description = "Returns an equivalent angle to the specified angle in the range -180 to 180. If the inputted angle is in the range -180 to 180, it will be returned unchanged.";
				file = "\x\cba\addons\vectors\fnc_simplifyAngle180.sqf";
			};
			class vect2polar
			{
				description = "Parameters:";
				file = "\x\cba\addons\vectors\fnc_vect2polar.sqf";
			};
			class vectAdd
			{
				description = "Returns the sum of two vectors.  Vectors can be 2D or 3D";
				file = "\x\cba\addons\vectors\fnc_vectAdd.sqf";
			};
			class vectCross
			{
				description = "Returns the cross product vector of two vectors.  Vectors must both be three dimensional.";
				file = "\x\cba\addons\vectors\fnc_vectCross.sqf";
			};
			class vectCross2D
			{
				description = "Returns the cross product vector of two 2D vectors. The result is an integer value (positive or negative), representing the magnitude of the height component.";
				file = "\x\cba\addons\vectors\fnc_vectCross2D.sqf";
			};
			class vectDir
			{
				description = "Returns the angle of a vector with the given i and k coordinates in the range 0 to 360.";
				file = "\x\cba\addons\vectors\fnc_vectDir.sqf";
			};
			class vectDot
			{
				description = "Returns the dot product of two vectors.  Vectors can be either two or three dimesions, but they must be the same dimension.";
				file = "\x\cba\addons\vectors\fnc_vectDot.sqf";
			};
			class vectElev
			{
				description = "Returns the angle of elevation of a 3D vector with the given i, j and k coordinates in the range -90 to 90.";
				file = "\x\cba\addons\vectors\fnc_vectElev.sqf";
			};
			class vectMagn
			{
				description = "Returns the magnitude of a 3D vector with the given i, j and k coordinates.";
				file = "\x\cba\addons\vectors\fnc_vectMagn.sqf";
			};
			class vectMagn2D
			{
				description = "Returns the magnitude of a vector with the given i and k coordinates or the magnitude of the i and k components of a 3D vector.";
				file = "\x\cba\addons\vectors\fnc_vectMagn2D.sqf";
			};
			class vectRotate2D
			{
				description = "Rotates a 2D vector around a given center, for rotating of a vector from its origin, use BIS_fnc_rotateVector2D";
				file = "\x\cba\addons\vectors\fnc_vectRotate2D.sqf";
			};
			class vectSubtract
			{
				description = "Returns the difference of two vectors.  Vectors can be 2D or 3D.";
				file = "\x\cba\addons\vectors\fnc_vectSubtract.sqf";
			};
		};
	};
};
//};

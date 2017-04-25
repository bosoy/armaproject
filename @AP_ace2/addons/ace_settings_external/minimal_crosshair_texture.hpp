/* ace_crosshair (.pbo) | (c) 2009 by rocko */

#define __DEFAULT texture = "\x\ace\addons\settings_external\ace_cursor_w_default_gs.paa"           // "\ca\ui\Data\cursor_w_default_gs.paa"
#define __EMPTY texture = "\ca\Weapons\Data\clear_empty"
#define __A 0.9

class CfgWeaponCursors {
	class RifleCursorCore;
	class MGCursorCore {
		__DEFAULT;
		color[] = { 0.6, 0.8392, 0.4706, __A };
	};
	class LawCursorCore;
	class RifleCursor: RifleCursorCore {
		__DEFAULT;
		color[] = { 0.6, 0.8392, 0.4706, __A };
	};
	class PistolCursor: RifleCursor {
		__DEFAULT;
		color[] = { 0.6, 0.8392, 0.4706, __A };
	};
	class GLCursor: RifleCursor {
		texture = "\ca\ui\Data\cursor_w_GL_gs";
	};
	class LawCursor: LawCursorCore {
		__DEFAULT;
		color[] = { 0.6, 0.8392, 0.4706, __A };
	};
	class Cannon: LawCursorCore {
		__DEFAULT;
		color[] = { 0.6, 0.8392, 0.4706, __A };
	};
	class ForeSight: Cannon {
		__EMPTY;
	};
	class Air_W_MG: Cannon {
		texture = "\ca\UI\data\cursor_w_airMG_gs";
	};
	class Air_E_MG: Cannon {
		texture = "\ca\UI\data\cursor_w_turret_gs";
	};
	class Air_Dot: Cannon {
		texture = "\ca\UI\Data\cursor_w_dot_gs";
	};
	class Vehicle_E_MG: Cannon {
		__DEFAULT;
	};
	class Vehicle_W_MG: Cannon {
		__DEFAULT;
	};
	class Vehicle_Grenade_W: Cannon {
		__DEFAULT;
	};
	class Vehicle_Grenade_E: Cannon {
		__DEFAULT;
	};
	class Laser: Cannon {
		texture = "\ca\ui\Data\cursor_w_laserlock_gs";
	};
	class Rocket: Cannon {
		__DEFAULT;
	};
	class Missile: Cannon {
		__DEFAULT;
	};
	class Stinger: Cannon {
		__DEFAULT;
	};
	class Javelin: Cannon {
		__DEFAULT;
	};
	class MGCursor: RifleCursor {};
};
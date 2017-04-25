/* ace_crosshair (.pbo) | (c) 2009 by rocko */

// TODO: Eval on vehicle mounted machineguns, i.e BMP3, Pickups, etc

#define __EMPTY texture = "\ca\Weapons\Data\clear_empty"

class CfgWeaponCursors {
	class RifleCursorCore;
	class MGCursorCore {
		__EMPTY;
	};
	class LawCursorCore;
	class RifleCursor: RifleCursorCore {
		__EMPTY;
	};
	class PistolCursor: RifleCursor {
		__EMPTY;
	};
	class GLCursor: RifleCursor {
		__EMPTY;
	};
	class LawCursor: LawCursorCore {
		__EMPTY;
	};
	class Cannon: LawCursorCore {
		__EMPTY;
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
		__EMPTY;
	};
	class Vehicle_W_MG: Cannon {
		__EMPTY;
	};
	class Vehicle_Grenade_W: Cannon {
		__EMPTY;
	};
	class Vehicle_Grenade_E: Cannon {
		__EMPTY;
	};
	class Laser: Cannon {
		__EMPTY;
	};
	class Rocket: Cannon {
		__EMPTY;
	};
	class Missile: Cannon {
		texture = "\ca\ui\Data\cursor_w_view_gs";
	};
	class Stinger: Cannon {
		__EMPTY;
	};
	class Javelin: Cannon {
		texture = "\ca\UI\Data\cursor_w_javellin_gs";
	};
	class MGCursor: RifleCursor {};
};
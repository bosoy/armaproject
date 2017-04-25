/* ace_c_ui (.pbo) | (c) 2009 by rocko */

	#define __ACE_SCALE_COMPASS 2.27

	class RscCompass: RscObject {
		enableZoom = 1;
		scale = (0.44 * __ACE_SCALE_COMPASS);
		#ifdef ACE_COMPASS
			model = "\x\ace\addons\m_compass\ace_compass.p3d";
			positionBack[] = {0,-0.02,0.08};
			direction[] = {0,0.15,0.5};
		#else
			model = "\x\ace\addons\m_compass\Compass.p3d";
		#endif
	};

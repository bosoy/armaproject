//#define TRACER_BALL_GREEN model = "\x\ace\addons\m_tracer\ace_TracerGreen2.p3d"
//#define TRACER_BALL_RED model = "\x\ace\addons\m_tracer\ace_TracerRed2.p3d"
#define TRACER_BALL_GREEN model = "\x\ace\addons\m_tracer\tracer_green_2.p3d"
#define TRACER_BALL_RED model = "\x\ace\addons\m_tracer\tracer_red_2.p3d"
#define TRACER_BALL_YELLOW model = "\x\ace\addons\m_tracer\tracer_yellow_2.p3d"

//class CfgAmmo {

	class Default;
	class BulletCore;
	class ShellCore;
	class BulletBase;
	class GrenadeBase;
	class ShellBase;

	class B_545x39_Ball: BulletBase {
		TRACER_BALL_GREEN;
	};
	class ACE_B_545x39_T: B_545x39_Ball {
		TRACER_BALL_GREEN;
	};
	class B_556x45_Ball: BulletBase {
		TRACER_BALL_RED;
	};
	class ACE_B_556x45_T: B_556x45_Ball {
		TRACER_BALL_RED;
	};
	class B_762x39_Ball: BulletBase {
		TRACER_BALL_GREEN;
	};
	class ACE_B_762x39_T: B_762x39_Ball {
		TRACER_BALL_GREEN;
	};
	class B_762x51_Ball: BulletBase {
		TRACER_BALL_RED;
	};
	class ACE_B_762x51_T: B_762x51_Ball {
		TRACER_BALL_RED;
	};
	class B_762x51_3RndBurst: B_762x51_Ball {
		TRACER_BALL_RED;
	};
	class B_762x54_Ball: BulletBase {
		TRACER_BALL_GREEN;
	};
	class ACE_B_762x54_T: B_762x54_Ball {
		TRACER_BALL_GREEN;
	};
	class B_303_Ball;
	class ACE_B_77x56_T: B_303_Ball {
		TRACER_BALL_YELLOW;
	};
	class B_77x56_Ball: BulletBase {
		TRACER_BALL_YELLOW;
	};
	class B_127x99_Ball: BulletBase {
		TRACER_BALL_RED;
	};
	class ACE_B_127x99_T: B_127x99_Ball {
		TRACER_BALL_RED;
	};
	class B_127x108_Ball: BulletBase {
		TRACER_BALL_RED;
	};
	class B_127x108_APHE: BulletBase {
		TRACER_BALL_RED;
	};
	class B_127x107_Ball: BulletBase {
		TRACER_BALL_RED;
	};
	class ACE_B_127x108_T: B_127x107_Ball {
		TRACER_BALL_RED;
	};
	class ACE_B_127x99_SLAP: B_127x99_Ball {
		TRACER_BALL_RED;
	};
	class B_145x115_AP: BulletBase {
		TRACER_BALL_RED;
	};
	class B_23mm_AA: BulletBase {
		TRACER_BALL_RED;
	};
	class B_23mm_APHE: BulletBase {
		TRACER_BALL_RED;
	};
	class B_30mm_AP: BulletBase {
		TRACER_BALL_RED;
	};
	class B_30mm_HE: BulletBase {
		TRACER_BALL_RED;
	};
	class B_30mm_AA: BulletBase {
		TRACER_BALL_RED;
	};
	class B_20mm_AA: BulletBase {
		TRACER_BALL_RED;
	};
	class B_20mm_AP: BulletBase {
		TRACER_BALL_RED;
	};
	class B_25mm_HE: BulletBase {
		TRACER_BALL_RED;
	};
	class B_25mm_HEI: B_25mm_HE {
		TRACER_BALL_RED;
	};
	class B_25mm_APDS: BulletBase {
		TRACER_BALL_RED;
	};
	class ACE_B_25mm_APFSDS: B_25mm_APDS {
		TRACER_BALL_RED;
	};
	class B_30mmA10_AP: BulletBase {
		TRACER_BALL_RED;
	};
	class B_30x113mm_M789_HEDP: B_30mm_HE {
		TRACER_BALL_RED;
	};
	class Sh_120_HE: ShellBase {
		TRACER_BALL_RED;
	};
	class Sh_120_SABOT: ShellBase {
		TRACER_BALL_RED;
	};
	class ACE_M900Round: Sh_120_SABOT {
		TRACER_BALL_RED;
	};
	class ACE_M456A2Round: Sh_120_HE {
		TRACER_BALL_RED;
	};
	class Sh_105_HESH : Sh_120_HE {
		TRACER_BALL_RED;
	};
	class Sh_105_APDS : Sh_120_SABOT {
		TRACER_BALL_RED;
	};
	class Sh_125_HE: ShellBase {
		TRACER_BALL_RED;
	};
	class Sh_125_SABOT: ShellBase {
		TRACER_BALL_RED;
	};
	class ACE_3BM42MRound: Sh_125_SABOT {
		TRACER_BALL_RED;
	};
	class ACE_3BM17MRound: Sh_125_SABOT {
		TRACER_BALL_RED;
	};
	class ACE_3BK29Round: Sh_125_SABOT {
		TRACER_BALL_RED;
	};
	class ACE_3BK18Round: ACE_3BK29Round {
		TRACER_BALL_RED;
	};
	class ACE_3BK29MRound: ACE_3BK29Round {
		TRACER_BALL_RED;
	};
	class Sh_85_HE: ShellBase {
		TRACER_BALL_RED;
	};
	class Sh_85_AP: ShellBase {
		TRACER_BALL_RED;
	};
	class ACE_BR365PRound: Sh_85_AP {
		TRACER_BALL_RED;
	};
	class Sh_105_HE;
	class Sh_100_HE: Sh_105_HE {
		TRACER_BALL_RED;
	};
	class Sh_100_HEAT : Sh_105_HE {
		TRACER_BALL_RED;
	};
	class ACE_3BM8Round: Sh_125_SABOT {
		TRACER_BALL_RED;
	};
	class ACE_BR412DRound: ACE_3BM8Round {
		TRACER_BALL_RED;
	};
	class ACE_OG15VRound: ShellBase {
		TRACER_BALL_RED;
	};
	class ACE_PG15VRound: ShellBase {
		TRACER_BALL_RED;
	};
//};
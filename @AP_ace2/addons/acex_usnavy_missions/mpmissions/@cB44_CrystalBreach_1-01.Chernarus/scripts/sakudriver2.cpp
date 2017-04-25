#define newsteerAheadSimul     0.55
#define newsteerAheadPlan      0.2
#define newpredictTurnSimul    4.4
#define newpredictTurnPlan     0.5
#define newbrakeDistance       3

class CfgPatches
{
	class sakudriver
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.00;
		requiredAddons[] = {"CAWheeled","CAWheeled2_MTVR"};
	};
};

class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};

	class Truck: Car
	{
		turnCoef = 5;
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};

	class HMMWV_Base: Car
	{
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};

	class UAZ_Base: Car
	{
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};

	class SkodaBase: Car
	{
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};

	class datsun1_civil_1_open: SkodaBase
	{
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};

	class MTVR: Truck
	{
		turnCoef = 5;
		steerAheadSimul = newsteerAheadSimul;
		steerAheadPlan = newsteerAheadPlan;
		predictTurnSimul = newpredictTurnSimul;
		predictTurnPlan = newpredictTurnPlan;
		brakeDistance = newbrakeDistance;
	};
};

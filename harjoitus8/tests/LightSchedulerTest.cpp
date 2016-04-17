extern "C" {
#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"
//#include "FakeRandomMinute.h"
}
#include "CppUTest/TestHarness.h"

TEST_GROUP(LightScheduler)
{
	void setup() {
		LightScheduler_Create();
		LightControllerSpy_Create();
	}

	void teardown() {
		LightScheduler_Destroy();
		LightControllerSpy_Destroy();
	}
};

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1199);

	LightScheduler_Wakeup();

	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
	LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1200);

	LightScheduler_Wakeup();

	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_ON, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOffEverydayItsTime)
{
	LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1200);

	LightScheduler_Wakeup();
	LONGS_EQUAL(3, LightControllerSpy_GetLastId());
	LONGS_EQUAL(LIGHT_OFF, LightControllerSpy_GetLastState());
}







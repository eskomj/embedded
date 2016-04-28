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

	void setTimeTo(int day, int minuteOfDay)
	{
		FakeTimeService_SetDay(day);
		FakeTimeService_SetMinute(minuteOfDay);
	}

	void checkLightState(int id, int level)
	{
		LONGS_EQUAL(id, LightControllerSpy_GetLastId());
		LONGS_EQUAL(level, LightControllerSpy_GetLastState());
	}
};

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
	LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
	FakeTimeService_SetDay(MONDAY);
	FakeTimeService_SetMinute(1199);

	LightScheduler_WakeUp();

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
	setTimeTo(MONDAY, 1200);

	LightScheduler_WakeUp();

	checkLightState(3,LIGHT_ON);
}

TEST(LightScheduler, ScheduleOffEverydayItsTime)
{
	LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
	setTimeTo(MONDAY, 1200);

	LightScheduler_WakeUp();
	checkLightState(3,LIGHT_OFF);
}

TEST(LightScheduler, ScheduleWeekEndItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
	setTimeTo(MONDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleTuesdayButItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
	setTimeTo(MONDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleTuesdayAndItsTuesday)
{
	LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
	setTimeTo(TUESDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleWeekendItsFriday)
{
	LightScheduler_ScheduleTurnOn(3,WEEKEND, 1200);
	setTimeTo(FRIDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleWeekendItsSaturday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
	setTimeTo(SATURDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleWeekendItsSunday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
	setTimeTo(SUNDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleWeekendItsMonday)
{
	LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
	setTimeTo(MONDAY, 1200);
	LightScheduler_WakeUp();
	checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST_GROUP(LightSchedulerInitAndCleanup)
{

};

TEST(LightSchedulerInitAndCleanup, CreateStartsOneMinuteAlarm)
{
	LightScheduler_Create();
	//POINTERS_EQUAL((void *)LightScheduler_WakeUp, (void *)FakeTimeService_GetAlarmCallback());
	LONGS_EQUAL(60, FakeTimeService_GetAlarmPeriod());
	LightScheduler_Destroy();
}







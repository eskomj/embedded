extern "C"
{
#include "LightScheduler.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LightScheduler)
{
    void setup()
    {
      LightScheduler_Create();
    }

    void teardown()
    {
       LightScheduler_Destroy();
    }
};

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
  LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
  //FakeTimeService_SetDay(MONDAY);
  //FakeTimeService_SetMinute(1199);
}

/*
TEST(LightScheduler, NoChangetoLightsDuringInitialization)
{
   LONGS_EQUAL(LIGHT_ID_UNKNOWN, LighControllerSpy_GetLastId());
   LONGS_EQUALS(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}
*/


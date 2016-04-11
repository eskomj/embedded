extern "C"
{
#include "FakeTimeService.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(FakeTimeService)
{
    void setup()
    {
      FakeTimeService_Create();
    }

    void teardown()
    {
       FakeTimeService_Destroy();
    }
};

TEST(FakeTimeService, Create)
{
  LONGS_EQUAL(-1, FakeTimeService_GetTime());
}

TEST(FakeTimeService, SetMinute)
{
  FakeTimeService_SetMinute(1200);
  LONGS_EQUAL(1200, FakeTimeService_GetTime());
}

TEST(FakeTimeService, SetDay)
{
  FakeTimeService_SetDay(TUESDAY);
  LONGS_EQUAL(TUESDAY, FakeTimeService_GetDay());
}


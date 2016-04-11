#include "CppUTest/TestHarness.h"
#include "harjoitus8BuildTime.h"

TEST_GROUP(harjoitus8BuildTime)
{
  harjoitus8BuildTime* projectBuildTime;

  void setup()
  {
    projectBuildTime = new harjoitus8BuildTime();
  }
  void teardown()
  {
    delete projectBuildTime;
  }
};

/*
TEST(harjoitus8BuildTime, Create)
{
  CHECK(1 != projectBuildTime->GetDateTime());
  //FAIL("Start here");
}
*/

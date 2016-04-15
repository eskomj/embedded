extern "C"
{
#include "LightControllerSpy.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LightControllerSpy)
{
    void setup()
    {
      LightControllerSpy_Create();
    }

    void teardown()
    {
       LightControllerSpy_Destroy();
    }
};

TEST(LightControllerSpy, Create)
{
  CHECK_EQUAL(1,1);
}


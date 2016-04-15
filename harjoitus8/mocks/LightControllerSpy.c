#include "LightControllerSpy.h"

int lastId, lastLevel;

void LightControllerSpy_Create(void)
{
	lastId = LIGHT_ID_UNKNOWN;
	lastLevel = LIGHT_STATE_UNKNOWN;
}

void LightControllerSpy_Destroy(void)
{
}

int LightControllerSpy_GetLastId(void)
{
    return lastId;
}

int LightControllerSpy_GetLastState(void)
{
    return lastLevel;
}

void LightController_TurnOn(int id)
{
	lastId = id;
	lastLevel = LIGHT_ON;
}

void LightController_TurnOff(int id)
{
	lastId = id;
	lastLevel = LIGHT_OFF;
}



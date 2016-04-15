#include "LightControllerSpy.h"

int lastId, lastLevel;

void LightControllerSpy_Create(void)
{
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



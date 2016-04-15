#ifndef D_LightControllerSpy_H
#define D_LightControllerSpy_H

#include "LightController.h"

/**********************************************************
 *
 * LightControllerSpy is responsible for ...
 *
 **********************************************************/

typedef enum
{
	LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1,
	LIGHT_OFF = 0, LIGHT_ON = 1
} LightState;

void LightControllerSpy_Create(void);
void LightControllerSpy_Destroy(void);
int LightControllerSpy_GetLastId(void);
int LightControllerSpy_GetLastState(void);
int LightControllerSpy_GetEventCounts(void);

#endif  /* D_FakeLightControllerSpy_H */

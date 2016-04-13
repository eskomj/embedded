#ifndef D_LightControllerSpy_H
#define D_LightControllerSpy_H

#include "LightController.h"

/**********************************************************
 *
 * LightControllerSpy is responsible for ...
 *
 **********************************************************/

void LightControllerSpy_Create(void);
void LightControllerSpy_Destroy(void);

void LightControllerSpy_On(int id);
void LightControllerSpy_Off(int id);
void LightControllerSpy_GetLastId(void);
void LightControllerSpy_GetState(void);

#endif  /* D_FakeLightControllerSpy_H */

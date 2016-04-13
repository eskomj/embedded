#ifndef D_LightControllerSpy_H
#define D_LightControllerSpy_H

/**********************************************************
 *
 * LightControllerSpy is responsible for ...
 *
 **********************************************************/

void LightControllerSpy_Create(void);
void LightControllerSpy_Destroy(void);

void LightControllerSpy_On(void);
void LightControllerSpy_Off(void);
void LightControllerSpy_GetLastId(void);
void LightControllerSpy_GetState(void);

#endif  /* D_FakeLightControllerSpy_H */

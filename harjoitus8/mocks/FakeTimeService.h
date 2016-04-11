#ifndef D_FakeTimeService_H
#define D_FakeTimeService_H

/**********************************************************
 *
 * FakeTimeService is responsible for ...
 *
 **********************************************************/

#include "TimeService.h"

void FakeTimeService_Create(void);
void FakeTimeService_Destroy(void);
void FakeTimeService_SetDay(int day);
void FakeTimeService_SetMinute(int minute);
int FakeTimeService_GetTime();

#endif  /* D_FakeFakeTimeService_H */

#ifndef D_LightScheduler_H
#define D_LightScheduler_H

/**********************************************************
 *
 * LightScheduler is responsible for ...
 *
 **********************************************************/

enum {FALSE, TRUE};

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_ScheduleTurnOn(int id, int day, int minute);
void LightScheduler_ScheduleTurnOff(int id, int day, int minute);
void LightScheduler_Wakeup(void);

#endif  /* D_FakeLightScheduler_H */

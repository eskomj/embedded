#ifndef D_LightScheduler_H
#define D_LightScheduler_H

/**********************************************************
 *
 * LightScheduler is responsible for ...
 *
 **********************************************************/

typedef enum Day {
    NOT_A_DAY=-4,
    EVERYDAY=-3, WEEKDAY=-2, WEEKEND=-1,
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
} Day;


void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_ScheduleTurnOn(int id, int day, int minute);

#endif  /* D_FakeLightScheduler_H */

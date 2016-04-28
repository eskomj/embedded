/*
 * TimeService.h
 *
 *  Created on: Apr 12, 2016
 *      Author: coder
 */

#ifndef INCLUDE_UTIL_TIMESERVICE_H_
#define INCLUDE_UTIL_TIMESERVICE_H_


typedef enum Day {
    NOT_A_DAY=-4,
    EVERYDAY=-3, WEEKDAY=-2, WEEKEND=-1,
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
} Day;

typedef enum Month {
    JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
} Month;

typedef struct Time Time;

struct Time
{
    int usec;
    int sec;
    int minuteOfDay;
    int minuteOfHour;
    Day dayOfWeek;
    int dayOfMonth;
    Month month;
};


void TimeService_Create(void);
void TimeService_Destroy(void);
int TimeService_GetMinute(void);
int TimeService_GetDay(void);

void TimeService_GetTime(Time *);
typedef void (*WakeUpCallback)(void);

void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeUpCallback);
void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeUpCallback);

#endif /* INCLUDE_UTIL_TIMESERVICE_H_ */

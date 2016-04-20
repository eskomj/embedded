#include "LightScheduler.h"
#include "LightController.h"
#include "TimeService.h"
#include <stdlib.h>
#include <string.h>

enum
{
    MAX_EVENTS = 128, UNUSED = -1
};

enum
{
    TURN_ON, TURN_OFF, DIM, RANDOM_ON, RANDOM_OFF
};

typedef struct
{
    int id;
    Day day;
    int minuteOfDay;
    int event;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void LightScheduler_Create(void)
{
	scheduledEvent.id = UNUSED;
}

static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
	scheduledEvent.id = id;
	scheduledEvent.day = day;
	scheduledEvent.minuteOfDay = minuteOfDay;
	scheduledEvent.event = event;
}

static void operateLight(ScheduledLightEvent * lightEvent)
{
	if (lightEvent->event == TURN_ON)
		LightController_TurnOn(lightEvent->id);
	if (lightEvent->event == TURN_OFF)
		LightController_TurnOff(lightEvent->id);
}

static void processEventDueNow(Time * time, ScheduledLightEvent * lightEvent)
{
	if (lightEvent->id == UNUSED) return;
	if (lightEvent->day != EVERYDAY && lightEvent->day != TimeService_GetDay()) return;
	if (lightEvent->minuteOfDay != time->minuteOfDay) return;
	operateLight(lightEvent);
}


void LightScheduler_Destroy(void)
{
}

void LightScheduler_Wakeup(void)
{
	Time time;
	TimeService_GetTime(&time);

	processEventDueNow(&time, &scheduledEvent);
}

void LightScheduler_ScheduleTurnOn(int id, int day, int minuteOfDay)
{
	scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id, int day, int minuteOfDay)
{
	scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}














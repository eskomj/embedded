#include "LightScheduler.h"
#include "LightController.h"
#include "TimeService.h"
#include <stdlib.h>
#include <string.h>

enum
{
    MAX_EVENTS = 128, UNUSED = -1
};

typedef struct
{
    int id;
    Day day;
    int minuteOfDay;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void LightScheduler_Create(void)
{
	scheduledEvent.id = UNUSED;
}

void LightScheduler_Destroy(void)
{
}

void LightScheduler_Wakeup(void)
{
	Time time;
	TimeService_GetTime(&time);

	if (scheduledEvent.id == UNUSED) return;
	if (time.minuteOfDay != scheduledEvent.minuteOfDay) return;

	LightController_TurnOn(scheduledEvent.id);
}

void LightScheduler_ScheduleTurnOn(int id, int day, int minuteOfDay)
{
	scheduledEvent.id = id;
	scheduledEvent.minuteOfDay = minuteOfDay;
}


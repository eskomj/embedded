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

void LightScheduler_Destroy(void)
{
}

void LightScheduler_Wakeup(void)
{
	Time time;
	TimeService_GetTime(&time);

	if (scheduledEvent.id == UNUSED) return;
	if (time.minuteOfDay != scheduledEvent.minuteOfDay) return;

	if (scheduledEvent.event == TURN_ON) LightController_TurnOn(scheduledEvent.id);
	else if (scheduledEvent.event == TURN_OFF) LightController_TurnOff(scheduledEvent.id);
}

void LightScheduler_ScheduleTurnOn(int id, int day, int minuteOfDay)
{
	scheduledEvent.id = id;
	scheduledEvent.event = TURN_ON;
	scheduledEvent.minuteOfDay = minuteOfDay;
}

void LightScheduler_ScheduleTurnOff(int id, int day, int minuteOfDay)
{
	scheduledEvent.id = id;
	scheduledEvent.minuteOfDay = minuteOfDay;
	scheduledEvent.event = TURN_OFF;
}


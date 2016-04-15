/*
 * LightController.h
 *
 *  Created on: Apr 13, 2016
 *      Author: esko
 */

#ifndef INCLUDE_UTIL_LIGHTCONTROLLER_H_
#define INCLUDE_UTIL_LIGHTCONTROLLER_H_

typedef enum
{
	LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1,
	LIGHT_OFF = 0, LIGHT_ON = 1
} LightState;

void LightController_TurnOn(int id);
void LightController_TurnOff(int id);

#endif /* INCLUDE_UTIL_LIGHTCONTROLLER_H_ */

/*
 * powerTask.c
 *
 *  Created on: 13.09.2018
 */
#include "powerTask.h"
#include "cubesatConstants.h"
#include "dataHandler.h"
#include "cmsis_os.h"

void vPowerTaskInit() {
	//Create main task with corresponding variables here
	void *taskParams;	//Set task-parameters here
	osThreadDef(powerTask, vPowerTaskMain(taskParams), 1, 1, 128);
	powerTaskHandle = osThreadCreate(osThread(powerTask), NULL);
}

void vPowerTaskMain(void *taskParams) {
	//taskParams not used so far
	bool lowPower = false;	//Switch for lowPower-mode
	int wakeUpCountdown = 0;	//Count-down of sleeping cycles for lowPower
	const int sleepCycles = 42;	//Number of cycles to skip when in low power
	const int cycleFrequency = pdMS_TO_TICKS(9000);//Set task-frequency in milliseconds per cycle here

	for (;;) {

		if (wakeUpCountdown <= 0) {
			//TODO define type and data - create method to easily build type information
			uint8_t type = 0;
			uint32_t data = 0;

			dataPacket *batteryStatusRequest = xDataHandlerPack(obcID, powerID,
					type, data);
			//TODO generate size
			vBusInterfaceSend(batteryStatusRequest, NULL, powerID);
			//TODO receive data from battery-PyBoard
			//TODO interpret received data
			//TODO send data to ground-control
			//TODO set power-mode based on received battery data
			if (lowPower)
				wakeUpCountdown = sleepCycles;
		} else {
			wakeUpCountdown--;
		}
		vTaskDelay(cycleFrequency);
	}
}


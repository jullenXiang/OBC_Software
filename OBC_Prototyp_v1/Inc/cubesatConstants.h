/**
  ******************************************************************************
  * @file           : cubesatConstants.h
  * @brief          : This file contains different constants that do not
  * 				  change during the entire mission.
  ******************************************************************************
 */

#ifndef CUBESATCONSTANTS_H_
#define CUBESATCONSTANTS_H_

/**
 * IDs of the different Subsystem used to identify them on the BUS.
 */
typedef enum {
	powerID,
	communicationID,
	obcID
} subsystemID;


typedef struct {
	subsystemID senderID;
	subsystemID receiverID;
	uint8_t type;
	uint32_t timestamp;
	uint8_t chksum;
} dataPacket;


#endif /* CUBESATCONSTANTS_H_ */

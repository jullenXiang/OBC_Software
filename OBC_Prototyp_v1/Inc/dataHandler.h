/**
  ******************************************************************************
  * @file           : dataHandler.h
  * @brief          : This handler provides functionality to pack rawdata into
  * 				  data packets.
  ******************************************************************************
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

/**
 * This class takes in the raw Sensor Data and packs it into
 * a format that can be send to the ground station.
 * Exact Format TBD
 */
dataPacket *xDataHandlerPack(subsystemID senderID, subsystemID reciverID, uint8_t type, uint32_t data);


#endif /* DATAHANDLER_H_ */

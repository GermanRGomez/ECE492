/*
 * emgInterface.cpp
 *
 *  Created on: 2014-01-28
 *      Author: gdhunter
 */

#include "emgInterface.h"
#include "altera_avalon_pio_regs.h"

/*
 * EMG sensor software interface constructor. Takes the base address of the
 * pin that the EMG sensor is connected to.
 */
emgInterface::emgInterface(int* baseAddr) {
	BaseAddress = baseAddr;

}

/*
 * Destructor for the emgIterface object
 */
emgInterface::~emgInterface() {

}

/*
 * Read data from the EMG sensor.
 */
long emgInterface::rawRead() {
	volatile long rawData;
	rawData = *IORD_ALTERA_AVALON_PIO_DIRECTION(BaseAddress);
	return rawData;
}

/*
 * Determing if data from the EMG sensor is greater than a set threshold.
 * Takes the threshold value and the raw EMG data.
 */
bool emgInterface::isOverThreshold(long threshold, int rawData) {
	if (threshold < rawData) {
		return true;
	} else {
		return false;
	}
}
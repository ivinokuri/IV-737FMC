#include "RpiSPIConnector.h"
#include "allocateMem.h"
#include "commandmessenger.h"

/* **********************************************************************************
    This is just the basic code to set up your custom device.
    Change/add your code as needed.
********************************************************************************** */

RpiSPIConnector::RpiSPIConnector(uint8_t Pin1, uint8_t Pin2)
{
    _pin1 = Pin1;
    _pin2 = Pin2;
}

void RpiSPIConnector::begin()
{
}

void RpiSPIConnector::attach(uint16_t Pin3, char *init)
{
    _pin3 = Pin3;
}

void RpiSPIConnector::detach()
{
    if (!_initialised)
        return;
    _initialised = false;
}

void RpiSPIConnector::set(int16_t messageID, char *setPoint)
{
    /* **********************************************************************************
        Each messageID has it's own value
        check for the messageID and define what to do.
        Important Remark!
        MessageID == -2 will be send from the board when PowerSavingMode is set
            Message will be "0" for leaving and "1" for entering PowerSavingMode
        MessageID == -1 will be send from the connector when Connector stops running
        Put in your code to enter this mode (e.g. clear a display)

    ********************************************************************************** */
    int32_t  data = atoi(setPoint);
    uint16_t output;

    // do something according your messageID
    switch (messageID) {
    case -1:
        // tbd., get's called when Mobiflight shuts down
    case -2:
        // tbd., get's called when PowerSavingMode is entered
    case 0:
        output = (uint16_t)data;
        data   = output;
        break;
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    default:
        break;
    }
}

void RpiSPIConnector::update()
{
    // Do something which is required regulary
}

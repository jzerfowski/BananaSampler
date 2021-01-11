#ifndef CapSenseButton_h
#define CapSenseButton_h
 
#include <CapacitiveSensor.h>

enum BUTTON_STATES { NOT_PRESSED, PRESSED};
enum BUTTON_ACTIONS { NO_ACTION, PRESSING, RELEASING, UNDEF_ACTION};

class CapSenseButton {
    // user-accessible "public" interface
    public:
        uint8_t sendPin, receivePin;
        uint8_t samples;
        long threshold;
        CapacitiveSensor capacitiveSensor = CapacitiveSensor(sendPin, receivePin);

        // methods
        CapSenseButton(uint8_t sendPin, uint8_t receivePin, uint8_t samples, long threshold);
        long getCapacitance();
        int pollState();
        void setState(int state);
        int getState();
        int updateState();

    private:
        int state;


};
 
#endif
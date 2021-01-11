#include <CapSenseButton.h>

CapSenseButton::CapSenseButton(uint8_t sendPin, uint8_t receivePin, uint8_t samples, long threshold) {
        this->sendPin = sendPin;
        this->receivePin = receivePin;
        this->samples = samples;
        this->threshold = threshold;
        this->capacitiveSensor = CapacitiveSensor(sendPin, receivePin);
}

long CapSenseButton::getCapacitance() {
    return capacitiveSensor.capacitiveSensor(samples);
    // return 100;
};

void CapSenseButton::setState(int newState) {
    this->state = newState;
};

int CapSenseButton::pollState() {
    int state;

    if (getCapacitance() > threshold) {
        state = PRESSED;
    } else {
        state = NOT_PRESSED;
    }
    return state;
};

int CapSenseButton::getState() {
    return this->state;
}

int CapSenseButton::updateState() {
    int oldState = this->state;
    int newState = this->pollState();

    int action;

    if (oldState == newState) {
        action = NO_ACTION;
    } else if (oldState == NOT_PRESSED && newState == PRESSED) {
        action = PRESSING;
    } else if (oldState == PRESSED && newState == NOT_PRESSED) {
        action = RELEASING;
    } else {
        action = UNDEF_ACTION;
    }

    this->state = newState;
    return action;
}

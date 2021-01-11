#include <Arduino.h>

#include <CapSenseButton.h>
#include <CapSenseKeyboard.h>
#include <MIDI.h>

// Create and bind the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

const int capSenseThreshold = 300;
const int capSenseSamples = 30;

CapSenseButton cb_4_2 = CapSenseButton(4, 2, capSenseSamples, capSenseThreshold);
CapSenseButton cb_4_12 = CapSenseButton(4, 12, capSenseSamples, capSenseThreshold);


CapSenseButton keys[] = {cb_4_2, cb_4_12};

CapSenseKeyboard keyboard = CapSenseKeyboard(&MIDI);


long start;
void setup(){
    // cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example
    MIDI.begin();

    // Serial.begin(9600);
    Serial.begin(115200);

    keyboard.addKey(4, 2, capSenseSamples, capSenseThreshold);
    keyboard.addKey(4, 12, capSenseSamples, capSenseThreshold);

    start = millis();
}

void loop(){

    keyboard.update();

    delay(1); // arbitrary delay to limit data to serial port


    // if (millis() - start > 10000) {
    //     keyboard.keyShiftOctaveDown();
    //     start = millis();
    // }
}
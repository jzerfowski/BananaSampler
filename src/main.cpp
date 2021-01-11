#include <Arduino.h>
#include <MIDI.h>

// Create and bind the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

#include <CapSenseButton.h>

const int capSenseThreshold = 300;
const int capSenseSamples = 30;

CapSenseButton cb_4_2 = CapSenseButton(4, 2, capSenseSamples, capSenseThreshold);
CapSenseButton cb_4_12 = CapSenseButton(4, 12, capSenseSamples, capSenseThreshold);


CapSenseButton keys[] = {cb_4_2, cb_4_12};



void setup(){
    // cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example
    // Serial.begin(9600);
    Serial.begin(115200);

}

void loop(){


    for (int i = 0; i < 2; i++) {
        CapSenseButton &button = keys[i];

        long start = millis();

        long total1 = button.getCapacitance();

        int action = button.updateState();

        // Serial.println(i);

        // Serial.print(millis() - start); // check on performance in milliseconds

        // Serial.print("\t"); // tab character for debug window spacing

        // Serial.print(total1); // print sensor output 1

        // Serial.print("\t");

        

        // Serial.print(button.getState());

        // Serial.print("\t Action: ");

        // Serial.print(action);

        // Serial.println("");


        if (action == PRESSING) {
            // Send note 42 with velocity 127 on channel 1
            MIDI.sendNoteOn(42+i, 127, 1);
        } else if (action == RELEASING) {
            MIDI.sendNoteOff(42+i, 127, 1);
        }
    }

    delay(10); // arbitrary delay to limit data to serial port

}
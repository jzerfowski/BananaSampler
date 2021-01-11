# Banana Sampler
This is the repository for a silly one-day project I built to prove my concept for a more advanced MIDI-Keyboard. Here, two bananas are used as capacitive touch sensors to trigger a serial MIDI signal to a computer which then plays cartoonish banana-peel-slipping-samples.

## Resources
### Tutorials
There have been many people before me who did a very similar thing and documented their efforts:
- [Instructable: Capacitive Sensing for Dummies](https://www.instructables.com/Capacitive-Sensing-for-Dummies/)
- [Instructable: Capacitive-Touch Arduino Keyboard Piano](https://www.instructables.com/Capacitive-Touch-Arduino-Keyboard-Piano/)
- [Instructable: How to Make a Cheap Arduino MIDI Controller](https://www.instructables.com/How-to-Make-a-Cheap-Arduino-MIDI-Controller/)

### Hardware
- 2 Bananas
- Arduino UNO (whichever Arduino should do the job)
- 2x 1MΩ resistor (1 for each banana)
- 5+ cables for connecting the Arduino
- Breadboard (optional, but makes life much easier)

### Arduino Libraries
Luckily, there's some libraries for Arduino which help a lot with this endeavour:

- [CapacitiveSensing Library (CapSense)](https://playground.arduino.cc/Main/CapacitiveSensor/) [github](https://github.com/PaulStoffregen/CapacitiveSensor)
- [Arduino MIDI Library](https://playground.arduino.cc/Main/MIDILibrary/) [github](https://github.com/FortySevenEffects/arduino_midi_library)

### Software
Since my Arduino doesn't have a reprogrammable USB-chip (see Additional Thoughts), I transmit the MIDI commands via the USB-Serial. The following two programs are necessary to transform the Serial data into a MIDI device which can be recognized by any sample player.

- [Hairless MIDI to Serial Bridge](https://projectgus.github.io/hairless-midiserial/)
- [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html)


### Samples
The samples I used can be found at (soundbible.com):
- [Banana Peel Slip Sound by suinho](http://soundbible.com/1438-Banana-Peel-Slip.html)
- [Slip on Banana Peel Sound](http://soundbible.com/84-Slip-On-Banana-Peel.html)

## Additional Thoughts
Unfortunately, the Arduino UNO sports the CH340G TTL-USB chip which cannot be reprogrammed.
For a next project I will try to get an Arduino DUE or MEGA with a ATmega-16U2. Read more [here](https://forum.arduino.cc/index.php?topic=469809.0).
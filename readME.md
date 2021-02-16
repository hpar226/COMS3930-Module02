Henry Hyun Park
Hp2380
COMS3930 
Module 02


Enclosed is a program to run a JamBox for fun making noises with a drum machine or a theremin. An analog joystick controls the pitch of a note produced through Sonic Pi and the 2 buttons make drum machine noises.
Media Output:

The SPDT switch is used to put the JamBox in either "active" mode or "inactive" mode, in "inactive" mode the analog stick and buttons will not produce any output (as shown in the first part of the video). In "active" mode, the analog stick is used to enable "theremin" mode and moving the controller will vary the pitch of a note. If a button is pressed in "active" mode, then the JamBox goes into "drum" mode and produces a bass drum sounds when the blue button is pressed and a cymbal sound when the red button is pressed.

Inside the enclosure is an ESP32 flashed with C code and is sending out serial messages read by a Python IDE (Thonny) on the Raspberry Pi. The Python IDE then routes the signal to Sonic Pi based on the state of the SPDT switch. There are 3 channels being sent to Sonic Pi:

/osc*/cymb          : this channel plays the cymbal
/osc*/bassDrum  : this channel plays the bass drum
/osc*/play_this    : this channel plays the theremin
Usage:

Install the sketch named Sketch_coms3939_mod02.ino onto an ESP32, open the file sonicpi_1.py on the Raspberry Pi, and open the file sonicpi_therem1.txt in Sonic Pi. To start the program, plug in the flashed ESP32 into the Raspberry Pi's USB, run the python code in Thonny and start both scripts on Sonic Pi. Plug outputs into audio interface and make noises to send via interwebs!!


Media Output:
The SPDT switch is used to put the JamBox in either “active” mode or “inactive” mode, in “inactive” mode the analog stick and buttons will not produce any output (as shown in the first part of the video). In “active” mode, the analog stick is used to enable “theremin” mode and moving the controller will vary the pitch of a note. If a button is pressed in “active” mode, then the JamBox goes into “drum” mode and produces a bass drum sounds when the blue button is pressed and a cymbal sound when the red button is pressed.

Inside the enclosure is an ESP32 flashed with C code and is sending out serial messages read by a Python IDE (Thonny) on the Raspberry Pi. The Python IDE then routes the signal to Sonic Pi based on the state of the SPDT switch. There are 3 channels being sent to Sonic Pi:

/osc*/cymb          : this channel plays the cymbal
/osc*/bassDrum  : this channel plays the bass drum
/osc*/play_this    : this channel plays the theremin
Usage:
Install the sketch named Sketch_coms3939_mod02.ino onto an ESP32, open the file sonicpi_1.py on the Raspberry Pi, and open the file sonicpi_therem1.txt in Sonic Pi. To start the program, plug in the flashed ESP32 into the Raspberry Pi’s USB, run the python code in Thonny and start both scripts on Sonic Pi. Plug outputs into audio interface and make noises to send via interwebs!!


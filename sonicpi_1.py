'''
this python code will listen for serial messages,
and pass that trigger on to SonicPi (code below) as an OSC message, triggering a sound
'''


from pythonosc import osc_message_builder
from pythonosc import udp_client
import serial
import sys
import time

# select the correct port and baud rate
ser = serial.Serial('/dev/cu.usbserial-14140', 9600)

sender = udp_client.SimpleUDPClient('127.0.0.1', 4560)

while True:
    try:
        ser_bytes = ser.readline()
        serialVal = str(ser_bytes, 'ascii').split('\t')

        zTmp = serialVal[3].split('\n')

        xVal = int(serialVal[0])
        yVal = int(serialVal[1])
        zVal = int(serialVal[2])
        buttonVal = int(zTmp[0])

        print(xVal, yVal, zVal, buttonVal)

        if (xVal < 1875 or xVal > 1890):
            pitch = (xVal/3000)*100
            sender.send_message('/play_this', [pitch, 70])
            #time.sleep(1)

        '''if (xVal > 1875):
            pitch = (xVal/3000)*100
            sender.send_message('/play_this', [70, pitch])
'''
        if (buttonVal == 0):
            sender = udp_client.SimpleUDPClient('127.0.0.1', 4560)
            sender.send_message('/trigger/prophet', [60, 75, 0])
            #time.sleep(2)
        '''
        if (serialVal == "0"):
            sender = udp_client.SimpleUDPClient('127.0.0.1', 4560)
            sender.send_message('/trigger/prophet', [70, 100, 1])
            time.sleep(2)
        '''
    except:
        print(sys.exc_info()[0])
        break

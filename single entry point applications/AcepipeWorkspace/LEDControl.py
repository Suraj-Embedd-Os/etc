from signal import signal, SIGINT
from sys import exit

import time
import atexit
import os
import sys
LED_OFF =-1
pwm_channel=1
# Import mavutil
from pymavlink import mavutil

def set_servo_pwm(servo_n, microseconds):
    """ Sets AUX 'servo_n' output PWM pulse-width.

    Uses https://mavlink.io/en/messages/common.html#MAV_CMD_DO_SET_SERVO

    'servo_n' is the AUX port to set (assumes port is configured as a servo).
        Valid values are 1-3 in a normal BlueROV2 setup, but can go up to 8
        depending on Pixhawk type and firmware.
    'microseconds' is the PWM pulse-width to set the output to. Commonly
        between 1100 and 1900 microseconds.

    """
    # master.set_servo(servo_n+8, microseconds) or:
    master.mav.command_long_send(
        master.target_system, master.target_component,
        mavutil.mavlink.MAV_CMD_DO_SET_SERVO,
        0,            # first transmission of this command
        servo_n+8,  # servo instance, offset by 8 MAIN outputs
        microseconds, # PWM pulse-width
        0,0,0,0,0     # unused parameters
    )
"""
#shut down when button press CTRL+C
def handler(signal_received, frame):        #added 
    #Handle any cleanup here
    print('SIGINT or CTRL-C detected. Exiting gracefully')
    #master = mavutil.mavlink_connection("/dev/ttyACM0", baud=115200)
    #master.wait_heartbeat()
    set_servo_pwm(1,1100)
    exit(0) 
"""	
def set_brightness():
	diameter = int(input("Enter Diameter of Pipe\n"))

	if diameter in range(1,49):
		set_servo_pwm(pwm_channel,1150) 
	elif diameter in range(49,73):
		set_servo_pwm(pwm_channel,1500) 
	elif diameter in range(73,91):
 		set_servo_pwm(pwm_channel,1900) 
	else:
            set_servo_pwm(pwm_channel,1900) 
	#	for us in range(1100,1900,100):
	#		set_servo_pwm(pwm_channel,us)
	#		time.sleep(1)


if __name__ == "__main__":
    #signal(SIGINT, handler)#added 
    print('Create the connection')
    master = mavutil.mavlink_connection("/dev/ttyACM1", baud=115200)

    print('Wait a heartbeat before sending commands')
    master.wait_heartbeat()

    print('heartbeat received')
#SHUTDOWN LED
    test_var=int(sys.argv[1])  #read  argument
    pwm_channel=int(sys.argv[2])  #read  argument
    
    set_servo_pwm(pwm_channel,1100)
    #print(test_var)
    #print(pwm_channel)
    
    if test_var==LED_OFF:
        print("Cree Led Going to OFF")
        set_servo_pwm(pwm_channel,1100)
    else:
        set_brightness()
    
  




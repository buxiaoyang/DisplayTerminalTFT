#!/usr/bin/env python
#--------------------------------------
#
# Pi-Lite Hello World Example
#
# Author : Matt Hawkins
# Date   : 01/10/2013
#
# http://www.raspberrypi-spy.co.uk/
#
#--------------------------------------

import sys
import serial
import time

def main():

	message = "BGI20140219,13:26,N,N,45,64,034,089,13,192.168.025.001STO"
	
	# Configure Pi serial port
	s = serial.Serial()
	s.baudrate = 2400
	s.timeout = 0
	s.port = "/dev/ttyAMA0"
	
	try:
	    # Open serial port
	    s.open()
	except serial.SerialException, e:
	    # There was an error
	    sys.stderr.write("could not open port %r: %s\n" % (port, e))
	    sys.exit(1)
	
	print "Serial port ready"    
	
	# Clear display
	s.write("$$$ALL,OFF\r")  
	
	while True:
		#Update Time
		timeString = time.strftime('%H:%M',time.localtime(time.time()))
		message = "BGI20140219,"+timeString+",N,N,45,64,034,089,13,192.168.025.001STO"
		print message
		s.write(message) 
		time.sleep(10)
	    
	 
main()
	

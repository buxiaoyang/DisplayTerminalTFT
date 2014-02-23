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
from __future__ import division
from subprocess import PIPE, Popen
import sys
import serial
import time
import datetime
import socket 
import fcntl 
import struct 
import psutil

def main():

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
	
	last_bytes_recv = 0
	last_bytes_sent = 0

	while True:
		now = datetime.datetime.now()
		#Update Time
		timeString = now.strftime("%H:%M")
		dateString = now.strftime("%Y%m%d")
		
		#Update net work flag
		ipString = ""
		try:
			ipString = get_local_ip('eth0')
		except:
			try:
				ipString = get_local_ip('wlan0')
			except:
				ipString = "0.0.0.0"
		if len(ipString) < 15:
			for i in range(0, 15-len(ipString)):
				ipString = ipString + " "
		
		#Update CPU usage
		cpu_usage = psutil.cpu_percent()
		cpu_usage = int(cpu_usage)
		cpuString = str(int(cpu_usage%100/10)) + str(int(cpu_usage%10))
		
		#Update RAM usage
		ram_usage = psutil.phymem_usage().percent
		ram_usage = int(ram_usage)
		ramString = str(int(ram_usage%100/10)) + str(int(ram_usage%10))
		
		#Update Temperature
		cpu_temperature = get_cpu_temperature()
		cpu_temperature = int(cpu_temperature)
		cpuTempString = str(int(cpu_temperature%100/10)) + str(int(cpu_temperature%10))
		
		#Update NetworkSpeed
		bytes_sent = long(psutil.network_io_counters().bytes_sent)
		bytes_recv = long(psutil.network_io_counters().bytes_recv)
		sentString = "000"
		recvString = "000"
		if last_bytes_recv == 0 or last_bytes_sent == 0:
			sentString = "000"
			recvString = "000"
		elif last_bytes_recv > bytes_recv or last_bytes_sent > bytes_sent:
			sentString = "000"
			recvString = "000"		
		else:
			sentSpeed = int((bytes_sent - last_bytes_sent)/5000)
			recvSpeed = int((bytes_recv - last_bytes_recv)/5000)
			#print sentSpeed KB/S
			#print recvSpeed KB/S
			if sentSpeed > 999:
				sentString = "999"
			else:
				sentString =  str(int(sentSpeed%1000/100)) + str(int(sentSpeed%100/10)) + str(int(sentSpeed%10))
			if recvSpeed > 999:
				recvString = "999"
			else:
				recvString =  str(int(recvSpeed%1000/100)) + str(int(recvSpeed%100/10)) + str(int(recvSpeed%10))
		last_bytes_recv = bytes_recv
		last_bytes_sent = bytes_sent
		#Build the command line
		command = "BGI"+dateString+","+timeString+",N,N,"+cpuString+","+ramString+","+sentString+","+recvString+","+cpuTempString+","+ipString+"STO"
		print command
		s.write(command) 
		time.sleep(5)
		
def get_local_ip(ethname):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        addr = fcntl.ioctl(sock.fileno(), 0x8915, struct.pack('256s', ethname))
        return socket.inet_ntoa( addr[20:24] )
        
def get_cpu_temperature():
    process = Popen(['vcgencmd', 'measure_temp'], stdout=PIPE)
    output, _error = process.communicate()
    return float(output[output.index('=') + 1:output.rindex("'")])	    
	 
main()
	

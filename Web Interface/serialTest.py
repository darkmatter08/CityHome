# serial i/o test
import serial
import time

ser = serial.Serial('/dev/tty.OIER-SPP', 9600)

print "presleep"
time.sleep(1)
print "postsleep"

# cur = 0
# while (time < 1):
# 	print ser.readlines()
# 	time.sleep(0.1)
# 	cur =  cur + 0.1

ser.write('1')
time.sleep(2)
ser.write('0')
time.sleep(2)
ser.write('-1')
time.sleep(2)

print "done"
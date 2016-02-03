from flask import Flask
import serial
from flask import render_template
app = Flask(__name__)

ser = serial.Serial('/dev/tty.OIER-SPP', 9600)

@app.route('/')
def home():
	return render_template('home.html')

@app.route('/fwd/')
def fwd():
	print "called fwd"
	ser.write('1')
	return "fwd"

@app.route('/stop/')
def stop():
	print "called stop"
	ser.write('0')
	return "stop"

@app.route('/bwd/')
def bwd():
	print "called bwd"
	ser.write('-1')
	return "bwd"

if __name__ == '__main__':
	app.run()
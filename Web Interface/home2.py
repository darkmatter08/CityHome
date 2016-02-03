from flask import Flask
import serial
from flask import render_template

from OpenSSL import SSL
context = SSL.Context(SSL.SSLv23_METHOD)
context.use_privatekey_file('ssl_key.key')
context.use_certificate_file('ssl_key.crt')

app = Flask(__name__)

ser = serial.Serial('/dev/tty.Hasiduino-SPP', 9600)

@app.route('/')
def home():
	return render_template('home2.html')

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

@app.route('/wall/')
def bwd():
	#print "called wall"
	ser.write('3')
	return "wall"

if __name__ == '__main__':
	app.run(host='127.0.0.1',port='5000', 
        debug = False/True, ssl_context=context)
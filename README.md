# Ultrasonic-Gesture-Control

Ultrasoinc gesture control

In this project, I explored the possibility of using a low-end sensor commonly known as an ultrasonic sensor to control a flappy bird through gestures. The idea is simple, use the ultrasonic sensor to find out the distance of the hand hovering above the sensor and when the distance decreases make the bird move up.

Ultrasonic sensor(HC-SR04) :
An ultrasonic sensor has a very interesting working principle, a burst of a high-frequency sound wave is transmitted from one of the two transducers (let's call it TX-transducers) and when the wave hits an object on its way, a part of the wave is traveled back to the sensor which is received/captured by the other transducer (let's call it RX-transducer). The time taken by the sound wave to travel back and forth determines the distance of the object how far it is located from the sensor. 

The sensor has 4 pins,
1) VCC, this pin dedicated 5V power supply. 
2) Trig, this a digital input pin, when a 10-microsecond positive electrical pulse is applied on this pin, the sensor starts a series of 8 sound pulses through the TX-transducer.
3) Echo, this is a digital output pin, the sensor pulls this pin HIGH at the same time when the sound pulses are generated through TX-transducer and pull it LOW when those pulses are received by the RX-transducer. The length of time this pin stays HIGH will be recorded by the Arduino board.
4) GND, this pin is dedicated to the ground connection.

Interfacing with Arduino :
It is very simple to interface this sensor with an Arduino board. Here is a simple trick you can do to avoid using connecting wires.
It is given in the datasheet of the sensor that it only requires 15mA of current and an Arduino's I/O pin can source up to 40mA of current so instead of connecting the VCC and the GND pin to the actual 5V and ground you can connect them to the regular I/O pins and program Arduino to pull the VCC connected pin high and the ground connected pin low. In this project, we are using pin-7 as VCC and pin-4 as ground. The other two pins 'Trig' and 'Echo' are connected to pin-6 and pin-5 respectively.

Game development(pygame) :
It looks overwhelming in the beginning but developing a game is quite easy if you have some programming skills and know what libraries to use. The python library pygame is utilized in this project to develop a flappy bird. If you are new then watch the following tutorial it will give you a great introduction to game development and in the end, you will have your own flappy bird. link: https://www.youtube.com/watch?v=UZg49z76cLw

Interfacing with PC :
Now we have a game running on PC and the sensor running on the Arduino board, we need some means of data transfer from the arduino board to the PC. A simple way to establish this communication is to write an Arduino sketch to send the sensor input over a serial cable and then read the serial data using the pySerial python library. It is very simple to use this library as it requires one line of code to set up a serial port, the baud rate, byte size, timeout, and the stop bit. Here is an example:

serial_data = serial.Serial(port = "COM11", 
                           baudrate = 115200, 
                           bytesize = 8, 
                           timeout = 0,
                           stopbits = serial.STOPBITS_ONE)

Change the com port with the number assigned to your Arduino board in the system and make sure to keep the same baud rate as it is set up in the Arduino. For more information on this library, click on the link https://github.com/pyserial/pyserial.

Programming :
The programming is simple as it is for a push-button, consider you are controlling the bird using a push button then you will write a code to move the bird up when the button is pressed and let the bird go down when the button is not pressed. Similarly, in the case of the ultrasonic sensor we are looking at the distance of the hand from the sensor, every time the distance decreases to a few centimeters then we will write a logic to move the bird up otherwise the bird will go down. Remember we have two programs, a python program running on the PC and an Arduino program running on the Arduino board so the movement of the hand or the decrease in distance will be detected by the Arduino board, the board will then send a logic "1" to the PC over the serial port which means a movement has been detected the python code on the PC will then make a necessary move to the bird (i.e go up).




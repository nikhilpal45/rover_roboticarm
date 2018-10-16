# rover_roboticarm
We created a rover with robotic arm over it.
We are using arduino mega 2560. Bluetooth module hc-05.
This code is created for a four powered wheel rover with robotic arm over it having two degree of freedom . This means we are using only two servo motors. We are going to control this with android phone using Bluetooth. 
Both sides of wheels are connected parallel to motor driver(L298 Motor Driver Module).
Connections for motor driver:
In1 to pin2
In2 to pin3
In3 to pin4
In4 to pin5
Connections for servo motors:
base motor to pin6
arm motor to pin7
Connections for bluetooth module:
Rx to pin10
Tx to pin11
make sure you are connecting all gnd to ground and vcc to 5 volt
This code is only for driving rover and two degree of rotation of arm.

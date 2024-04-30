# Weather-Monitoring-System
   +----------------------------------------------+
   |                  Arduino                     |
   |                                              |
   |        +---------------------------------+   |
   |        |                                 |   |
   |        |                                 |   |
   |        |   +-------------------------+   |   |
   |        |   |                         |   |   |
   |        +---| DHT11 (DHTPIN: 2)      |   |   |
   |        |   |                         |   |   |
   |        |   +-------------------------+   |   |
   |        |                                 |   |
   |        |   +-------------------------+   |   |
   |        |   |                         |   |   |
   |        +---| MQ-4 Gas Sensor        |   |   |
   |        |   | (Analog Pin: A0)       |   |   |
   |        |   +-------------------------+   |   |
   |        |                                 |   |
   |        |   +-------------------------+   |   |
   |        |   |                         |   |   |
   |        +---| YL-83 Moisture Sensor  |   |   |
   |        |   | (Analog Pin: A1)       |   |   |
   |        |   +-------------------------+   |   |
   |        |                                 |   |
   |        |   +-------------------------+   |   |
   |        |   |                         |   |   |
   |        |   |                         |   |   |
   |        |   |    LCD Display          |   |   |
   |        |   |                         |   |   |
   |        |   |                         |   |   |
   |        |   +-------------------------+   |   |
   |        |                                 |   |
   |        |   +-------------------------+   |   |
   |        |   |                         |   |   |
   |        |   |   ESP8266 WiFi Module   |   |   |
   |        |   |   (TX: 9, RX: 10)       |   |   |
   |        |   |                         |   |   |
   |        |   +-------------------------+   |   |
   |        |                                 |   |
   |        +---------------------------------+   |
   |                                              |
   +----------------------------------------------+

Here's what each component is connected to on the Arduino:

DHT11 Temperature and Humidity Sensor: Connected to a digital pin (DHTPIN).
MQ-4 Gas Sensor: Connected to an analog pin (mq4Pin).
YL-83 Moisture Sensor: Connected to an analog pin (yl83Pin).
LCD Display: Connected to digital pins for data and control (e.g., 7, 6, 5, 4, 3, 2).
ESP8266 WiFi Module: Connected to digital pins for serial communication (e.g., RX, TX).
Make sure to connect the components according to their pin configurations and adjust the pin numbers in the code if necessary. Also, don't forget to connect power (VCC) and ground (GND) for each component appropriately.

Connection:

DHT11:
VCC to 5V
GND to GND
Data to Digital Pin 2


MQ-4:
VCC to 5V
GND to GND
Analog Output to Analog Pin A0


YL-83:
VCC to 5V
GND to GND
Analog Output to Analog Pin A1


LCD Display:
VSS to GND
VDD to 5V
V0 to GND
RS to Digital Pin 7
RW to GND
E to Digital Pin 6
D4 to Digital Pin 5
D5 to Digital Pin 4
D6 to Digital Pin 3
D7 to Digital Pin 2


ESP8266:
VCC to 3.3V
GND to GND
TX to Digital Pin 9
RX to Digital Pin 10

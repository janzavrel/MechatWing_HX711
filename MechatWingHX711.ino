// MechatWingHX711.ino
// Mearuring 4 tensometers by HX711 module

#include <HX711.h>

HX711 scale1;
HX711 scale2;
HX711 scale3;
HX711 scale4;


long data1, data2, data3, data4; //data sensed from 4 tensometers

const int LOADCELL1_DOUT_PIN = 2; // DOUT pin for load cell 1
const int LOADCELL2_DOUT_PIN = 3;  
const int LOADCELL3_DOUT_PIN = 4;
const int LOADCELL4_DOUT_PIN = 5;

const int LOADCELL1_SCK_PIN = 10; // SCK pin for load cell 1
const int LOADCELL2_SCK_PIN = 10;
const int LOADCELL3_SCK_PIN = 10;
const int LOADCELL4_SCK_PIN = 10;  





/* 
Total Clock Pulses	Next Selected Channel	Programmable Gain
25 pulses	Channel A	128
26 pulses	Channel B	32

Hardware Wiring
Both channels share the same excitation voltage (E+ and E-):
• Load Cell 1: Connect Excitation to E+ / E- and Signal to A+ / A-.
• Load Cell 2: Connect Excitation to the same E+ / E- pins and Signal to B+ / B- 
*/


void setup(){

  Serial.begin(9600); // Start serial communication at 9600 baud rate

  scale1.begin(LOADCELL1_DOUT_PIN, LOADCELL1_SCK_PIN); // Initialize the HX711 module for load cell 1
  scale2.begin(LOADCELL2_DOUT_PIN, LOADCELL2_SCK_PIN);
  scale3.begin(LOADCELL3_DOUT_PIN, LOADCELL3_SCK_PIN);
  scale4.begin(LOADCELL4_DOUT_PIN, LOADCELL4_SCK_PIN);

  scale1.set_gain(128); // Set the gain for load cell 1 (128 for channel A) 
  scale2.set_gain(128);
  scale3.set_gain(128);
  scale4.set_gain(128);

    // Set your calibration factors here
  scale1.set_scale(2280.f); // Set the calibration factor for load cell 1
  scale2.set_scale(2280.f);
  scale3.set_scale(2280.f);
  scale4.set_scale(2280.f);

  scale1.tare(); // Reset the scale to 0
  scale2.tare();
  scale3.tare();
  scale4.tare();
}


void loop(){
    //sensing from HX711 module, channel A+B, gain 64
  // 1. Read Channel A (Gain 128 or 64)


  data1 = scale1.read(); 







}
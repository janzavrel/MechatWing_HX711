#include "HX711.h"

HX711 scale;

int dataPin=3;
int clockPin=4;
float f;

long int values = 0; 
void setup()
{

  scale.begin(dataPin, clockPin);
  scale.set_scale(10000);       // TODO you need to calibrate this yourself.
  scale.set_gain(128); //set gain to 128


  Serial.begin(115200); 
  //scale.tare();
}
 
void loop()
{
 values = scale.read(); 
//Serial.println(values); 
f = scale.get_units(1);
Serial.println(f);
//Serial.println(scale.get_units(10));
//Serial.println(scale.read());
//delay(50); 
}

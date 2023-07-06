//https://github.com/HelTecAutomation/Heltec_ESP32/blob/master/examples/OLED/OLED_rotate/OLED_rotate.ino
#include "heltec.h"
#include "Arduino.h"
#include "output.h"


//rotate only for GEOMETRY_128_64
SSD1306Wire display(0x3c, SDA_OLED, SCL_OLED, RST_OLED);
Output output(&display);

void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}

void VextOFF(void) //Vext default OFF
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, HIGH);
}

void setup() {

  // set serial baud rate to match platformio.ini monitor serial speed
  Serial.begin(115200);

  // initialize the OLED display
  VextON();
  delay(100);
  
  display.init();
  display.clear();
  display.display();
  display.setContrast(255);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  

}

void loop() {
  output.print("Test", CONSOLE);
  output.print("Test", OLED);
  output.print("Test", LOG);
  delay(1000);
  display.clear();
  display.display();
  delay(1000);
 }  
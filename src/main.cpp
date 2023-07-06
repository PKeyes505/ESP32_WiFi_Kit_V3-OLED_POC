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
  display.clear();
  display.display();
  display.screenRotate(ANGLE_0_DEGREE);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 32-16/2, "PK33_0");
  display.display();
  delay(2000);

  display.clear();
  display.display();
  display.screenRotate(ANGLE_90_DEGREE);
  display.setFont(ArialMT_Plain_10);
  display.drawString(32, 64-10/2, "ROTATE_90");
  display.display();
  delay(2000);

  display.clear();
  display.display();
  display.screenRotate(ANGLE_180_DEGREE);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 32-16/2, "ROTATE_180");
  display.display();
  delay(2000);

  display.clear();
  display.display();
  display.screenRotate(ANGLE_270_DEGREE);
  display.setFont(ArialMT_Plain_10);
  display.drawString(32, 64-10/2, "ROTATE_27a0");
  display.display();
  delay(2000);
}

void loop() {
  output.print("Hello, world!", CONSOLE);
  output.print("Hello, world!", OLED);
  output.print("Hello, world!", LOG);
  delay(1000);
 }
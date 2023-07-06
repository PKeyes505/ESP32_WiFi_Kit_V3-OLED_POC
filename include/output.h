#include <Arduino.h>
#include <Wire.h>
#include "heltec.h"

enum OutputType {
  CONSOLE,
  OLED,
  LOG
};

class Output {
  public:
    Output(SSD1306Wire* display) {
      _display = display;
    }

    void print(String message, OutputType type) {
      switch (type) {
        case CONSOLE:
          Serial.println(message);
          break;
        case OLED:
          _display->clear();
          _display->drawString(64, 32-16/2, message);
          _display->display();
          break;
        case LOG:
          // Log the message to a file or other storage
          break;
        default:
          break;
      }
    }

  private:
    SSD1306Wire* _display;
};
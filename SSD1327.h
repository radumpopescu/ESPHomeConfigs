#include "esphome.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SH1107_SEEED_96X96_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

class SSD1327 : public Component {
 public:
  void setup() override {
  u8g2.begin();
    
  }
  void loop() override {
    u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0,24,"Hello World!");
      ESP_LOGD("custom", "The GPIO pin 5 is HIGH!");
  } while ( u8g2.nextPage() );
  }
};



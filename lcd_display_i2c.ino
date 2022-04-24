#include <Wire.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

const int adc = 0 ;   //naming pin 0 of analog input side as ‘adc’

void setup()
{
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);

  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop()
{
  
  int adc  = analogRead(0) ;    //reading analog voltage and storing it in an integer
  adc = map(adc, 0, 1023, 0, 255);
  Serial.println(adc);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(adc);
  display.display();
  delay(2000);
}

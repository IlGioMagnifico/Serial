#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

// no reset pin
Adafruit_SSD1306 display(-1);

char inChar;
String OLed_String;

#if (SSD1306_LCDHEIGHT != 64)
  #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.display();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
   
  display.clearDisplay();
  display.display();
  Serial.println("Serial up and running.");
}

void loop() {

 if (Serial.available()){
  inChar=Serial.read();
  if (inChar!='\r'){
    Serial.print(inChar);
    OLed_String+=inChar;
    display.setCursor(0, 0);
    display.print(OLed_String);
  }
  else{
    OLed_String.remove(0);
    display.clearDisplay();
  }
  display.display();
 }

}




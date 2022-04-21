#include <controller/ArduinoController.hpp>

using namespace Controller;


void splashScreen()
{
    Controller::ArduinoController board;
    board.display.testdrawbitmap();
    delay(2000);

    for(;;)
    {
        board.display.testscrolltext(F("===="));
    }
    
}

void setup() 
{
    splashScreen();
}

void loop() 
{
    Serial.println("");
    Serial.println(".");
    Serial.println("..");
    Serial.println("...");
    Serial.println("....");
    Serial.println(".....");
    Serial.println("......");
}

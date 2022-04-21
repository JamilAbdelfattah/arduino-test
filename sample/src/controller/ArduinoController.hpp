#include <Arduino.h>
#include <controller/DisplayController.hpp>

#define ArduinoController_H

namespace Controller 
{
    class ArduinoController
    {   
        public:
            ArduinoController();
            Controller::DisplayController display;
    };
}
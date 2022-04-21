#include <controller/ArduinoController.hpp>

using namespace Controller;

ArduinoController::ArduinoController() {
    Serial.begin(9600);
    Controller::DisplayController display();
}
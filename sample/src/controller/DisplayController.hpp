#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <constant/display.hpp>

#define DisplayController_H

//dispaly config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C

namespace Controller 
{
    class DisplayController
    {   
        public:
            DisplayController();                                                // Contstructor
            void testdrawline();                                                // Draw many lines
            void testdrawrect();                                                // Draw rectangles (outlines)
            void testfillrect();                                                // Draw rectangles (filled)
            void testdrawcircle();                                              // Draw circles (outlines)
            void testfillcircle();                                              // Draw circles (filled)
            void testdrawroundrect();                                           // Draw rounded rectangles (outlines)
            void testfillroundrect();                                           // Draw rounded rectangles (filled)
            void testdrawtriangle();                                            // Draw triangles (outlines)
            void testfilltriangle();                                            // Draw triangles (filled)
            void testdrawchar();                                                // Draw characters of the default font
            void testdrawstyles();                                              // Draw 'stylized' characters
            void testscrolltext(String text);                                   // Draw scrolling text
            void testdrawbitmap();                                              // Draw a small bitmap image
            void testanimate(const uint8_t* bitmap, uint8_t w, uint8_t h);      // Draw multiple frames

        private:
            Adafruit_SSD1306 adafruit_SSD1306;
    };
}
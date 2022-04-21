#include <controller/DisplayController.hpp>
using namespace Controller;

Adafruit_SSD1306 adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DisplayController::DisplayController() {
    if (!adafruit_SSD1306.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }
    adafruit_SSD1306.clearDisplay();
}

void DisplayController::testdrawline() {
    int16_t i;

    adafruit_SSD1306.clearDisplay();  // Clear display buffer

    for (i = 0; i < adafruit_SSD1306.width(); i += 4) {
        adafruit_SSD1306.drawLine(0, 0, i, adafruit_SSD1306.height() - 1, SSD1306_WHITE);
        adafruit_SSD1306.display();  // Update screen with each newly-drawn line
        delay(1);
    }

    for (i = 0; i < adafruit_SSD1306.height(); i += 4) {
        adafruit_SSD1306.drawLine(0, 0, adafruit_SSD1306.width() - 1, i, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }
    delay(250);

    adafruit_SSD1306.clearDisplay();

    for (i = 0; i < adafruit_SSD1306.width(); i += 4) {
        adafruit_SSD1306.drawLine(0, adafruit_SSD1306.height() - 1, i, 0, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }
    for (i = adafruit_SSD1306.height() - 1; i >= 0; i -= 4) {
        adafruit_SSD1306.drawLine(0, adafruit_SSD1306.height() - 1, adafruit_SSD1306.width() - 1, i, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }
    delay(250);

    adafruit_SSD1306.clearDisplay();

    for (i = adafruit_SSD1306.width() - 1; i >= 0; i -= 4) {
        adafruit_SSD1306.drawLine(adafruit_SSD1306.width() - 1, adafruit_SSD1306.height() - 1, i, 0, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }
    for (i = adafruit_SSD1306.height() - 1; i >= 0; i -= 4) {
        adafruit_SSD1306.drawLine(adafruit_SSD1306.width() - 1, adafruit_SSD1306.height() - 1, 0, i, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }
    delay(250);

    adafruit_SSD1306.clearDisplay();

    for (i = 0; i < adafruit_SSD1306.height(); i += 4) {
        adafruit_SSD1306.drawLine(adafruit_SSD1306.width() - 1, 0, 0, i, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }
    for (i = 0; i < adafruit_SSD1306.width(); i += 4) {
        adafruit_SSD1306.drawLine(adafruit_SSD1306.width() - 1, 0, i, adafruit_SSD1306.height() - 1, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }

    delay(2000);  // Pause for 2 seconds
}

void DisplayController::testdrawrect(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = 0; i < adafruit_SSD1306.height() / 2; i += 2) {
        adafruit_SSD1306.drawRect(i, i, adafruit_SSD1306.width() - 2 * i, adafruit_SSD1306.height() - 2 * i, SSD1306_WHITE);
        adafruit_SSD1306.display();  // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}

void DisplayController::testfillrect(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = 0; i < adafruit_SSD1306.height() / 2; i += 3) {
        // The INVERSE color is used so rectangles alternate white/black
        adafruit_SSD1306.fillRect(i, i, adafruit_SSD1306.width() - i * 2, adafruit_SSD1306.height() - i * 2, SSD1306_INVERSE);
        adafruit_SSD1306.display();  // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}

void DisplayController::testdrawcircle(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = 0; i < max(adafruit_SSD1306.width(), adafruit_SSD1306.height()) / 2; i += 2) {
        adafruit_SSD1306.drawCircle(adafruit_SSD1306.width() / 2, adafruit_SSD1306.height() / 2, i, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }

    delay(2000);
}

void DisplayController::testfillcircle(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = max(adafruit_SSD1306.width(), adafruit_SSD1306.height()) / 2; i > 0; i -= 3) {
        // The INVERSE color is used so circles alternate white/black
        adafruit_SSD1306.fillCircle(adafruit_SSD1306.width() / 2, adafruit_SSD1306.height() / 2, i, SSD1306_INVERSE);
        adafruit_SSD1306.display();  // Update screen with each newly-drawn circle
        delay(1);
    }

    delay(2000);
}

void DisplayController::testdrawroundrect(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = 0; i < adafruit_SSD1306.height() / 2 - 2; i += 2) {
        adafruit_SSD1306.drawRoundRect(i, i, adafruit_SSD1306.width() - 2 * i, adafruit_SSD1306.height() - 2 * i, adafruit_SSD1306.height() / 4, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }

    delay(2000);
}

void DisplayController::testfillroundrect(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = 0; i < adafruit_SSD1306.height() / 2 - 2; i += 2) {
        // The INVERSE color is used so round-rects alternate white/black
        adafruit_SSD1306.fillRoundRect(i, i, adafruit_SSD1306.width() - 2 * i, adafruit_SSD1306.height() - 2 * i, adafruit_SSD1306.height() / 4, SSD1306_INVERSE);
        adafruit_SSD1306.display();
        delay(1);
    }

    delay(2000);
}

void DisplayController::testdrawtriangle(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = 0; i < max(adafruit_SSD1306.width(), adafruit_SSD1306.height()) / 2; i += 5) {
        adafruit_SSD1306.drawTriangle(adafruit_SSD1306.width() / 2, adafruit_SSD1306.height() / 2 - i, adafruit_SSD1306.width() / 2 - i, adafruit_SSD1306.height() / 2 + i, adafruit_SSD1306.width() / 2 + i, adafruit_SSD1306.height() / 2 + i, SSD1306_WHITE);
        adafruit_SSD1306.display();
        delay(1);
    }

    delay(2000);
}

void DisplayController::testfilltriangle(void) {
    adafruit_SSD1306.clearDisplay();

    for (int16_t i = max(adafruit_SSD1306.width(), adafruit_SSD1306.height()) / 2; i > 0; i -= 5) {
        // The INVERSE color is used so triangles alternate white/black
        adafruit_SSD1306.fillTriangle(adafruit_SSD1306.width() / 2, adafruit_SSD1306.height() / 2 - i, adafruit_SSD1306.width() / 2 - i, adafruit_SSD1306.height() / 2 + i, adafruit_SSD1306.width() / 2 + i, adafruit_SSD1306.height() / 2 + i, SSD1306_INVERSE);
        adafruit_SSD1306.display();
        delay(1);
    }

    delay(2000);
}

void DisplayController::testdrawchar(void) {
    adafruit_SSD1306.clearDisplay();

    adafruit_SSD1306.setTextSize(1);               // Normal 1:1 pixel scale
    adafruit_SSD1306.setTextColor(SSD1306_WHITE);  // Draw white text
    adafruit_SSD1306.setCursor(0, 0);              // Start at top-left corner
    adafruit_SSD1306.cp437(true);                  // Use full 256 char 'Code Page 437' font

    // Not all the characters will fit on the adafruit_SSD1306. This is normal.
    // Library will draw what it can and the rest will be clipped.
    for (int16_t i = 0; i < 256; i++) {
        if (i == '\n')
            adafruit_SSD1306.write(' ');
        else
            adafruit_SSD1306.write(i);
    }

    adafruit_SSD1306.display();
    delay(2000);
}

void DisplayController::testdrawstyles(void) {
    adafruit_SSD1306.clearDisplay();

    adafruit_SSD1306.setTextSize(1);               // Normal 1:1 pixel scale
    adafruit_SSD1306.setTextColor(SSD1306_WHITE);  // Draw white text
    adafruit_SSD1306.setCursor(0, 0);              // Start at top-left corner
    adafruit_SSD1306.println(F("Hello, world!"));

    adafruit_SSD1306.setTextColor(SSD1306_BLACK, SSD1306_WHITE);  // Draw 'inverse' text
    adafruit_SSD1306.println(3.141592);

    adafruit_SSD1306.setTextSize(2);  // Draw 2X-scale text
    adafruit_SSD1306.setTextColor(SSD1306_WHITE);
    adafruit_SSD1306.print(F("0x"));
    adafruit_SSD1306.println(0xDEADBEEF, HEX);

    adafruit_SSD1306.display();
    delay(2000);
}

void DisplayController::testscrolltext(String text) {
    adafruit_SSD1306.clearDisplay();

    adafruit_SSD1306.setTextSize(2);  // Draw 2X-scale text
    adafruit_SSD1306.setTextColor(SSD1306_WHITE);
    adafruit_SSD1306.setCursor(10, 0);
    adafruit_SSD1306.println(text);
    adafruit_SSD1306.display();  // Show initial text
    delay(100);

    // Scroll in various directions, pausing in-between:
    adafruit_SSD1306.startscrollright(0x00, 0x0F);
    delay(2000);
    adafruit_SSD1306.stopscroll();
    delay(1000);
    adafruit_SSD1306.startscrollleft(0x00, 0x0F);
    delay(2000);
    adafruit_SSD1306.stopscroll();
    delay(1000);
    adafruit_SSD1306.startscrolldiagright(0x00, 0x07);
    delay(2000);
    adafruit_SSD1306.startscrolldiagleft(0x00, 0x07);
    delay(2000);
    adafruit_SSD1306.stopscroll();
    delay(1000);
}

void DisplayController::testdrawbitmap(void) {

    for(int i = 15; i > 0; i--) {
        adafruit_SSD1306.clearDisplay();
        adafruit_SSD1306.display();
        delay(i * i);
        adafruit_SSD1306.drawBitmap((adafruit_SSD1306.width() - Constant::LOGO_WIDTH) / 2, (adafruit_SSD1306.height() - Constant::LOGO_HEIGHT) / 2, Constant::PIRATEBAY, Constant::LOGO_WIDTH, Constant::LOGO_HEIGHT, 1);
        adafruit_SSD1306.display();
    }

    adafruit_SSD1306.clearDisplay();
    adafruit_SSD1306.drawBitmap((adafruit_SSD1306.width() - Constant::LOGO_WIDTH) / 2, (adafruit_SSD1306.height() - Constant::LOGO_HEIGHT) / 2, Constant::KOPI_MI, Constant::LOGO_WIDTH, Constant::LOGO_HEIGHT, 1);
    adafruit_SSD1306.display();
    delay(1000);
}

#define XPOS 0  // Indexes into the 'icons' array in function below
#define YPOS 1
#define DELTAY 2

void DisplayController::testanimate(const uint8_t* bitmap, uint8_t w, uint8_t h) {
    int NUMFLAKES = 10;

    int8_t f, icons[NUMFLAKES][3];

    // Initialize 'snowflake' positions
    for (f = 0; f < NUMFLAKES; f++) {
        icons[f][XPOS] = random(1 - Constant::LOGO_WIDTH, adafruit_SSD1306.width());
        icons[f][YPOS] = -Constant::LOGO_HEIGHT;
        icons[f][DELTAY] = random(1, 6);
        Serial.print(F("x: "));
        Serial.print(icons[f][XPOS], DEC);
        Serial.print(F(" y: "));
        Serial.print(icons[f][YPOS], DEC);
        Serial.print(F(" dy: "));
        Serial.println(icons[f][DELTAY], DEC);
    }

    for (;;) {                   // Loop forever...
        adafruit_SSD1306.clearDisplay();  // Clear the display buffer

        // Draw each snowflake:
        for (f = 0; f < NUMFLAKES; f++) {
            adafruit_SSD1306.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, SSD1306_WHITE);
        }

        adafruit_SSD1306.display();  // Show the display buffer on the screen
        delay(200);         // Pause for 1/10 second

        // Then update coordinates of each flake...
        for (f = 0; f < NUMFLAKES; f++) {
            icons[f][YPOS] += icons[f][DELTAY];
            // If snowflake is off the bottom of the screen...
            if (icons[f][YPOS] >= adafruit_SSD1306.height()) {
                // Reinitialize to a random position, just off the top
                icons[f][XPOS] = random(1 - Constant::LOGO_WIDTH, adafruit_SSD1306.width());
                icons[f][YPOS] = -Constant::LOGO_HEIGHT;
                icons[f][DELTAY] = random(1, 6);
            }
        }
    }
}
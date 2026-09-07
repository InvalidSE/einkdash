#include "display.h"
#include "pins.h"
#include "initImage.h"
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// 2.9'' EPD Module
// 128x296 black/red
GxEPD2_3C<GxEPD2_290_C90c, GxEPD2_290_C90c::HEIGHT> display(GxEPD2_290_C90c(PIN_DISPLAY_CS, PIN_DISPLAY_DC, PIN_DISPLAY_RESET, PIN_DISPLAY_BUSY));

void displayInit() {
    Serial.println("Initializing display...");
    long display_startup_time = millis();

    display.init(115200, true, 50, false); // 50ms instead of 2 if this doesn't work
    renderBuffer(IMAGE_BOOT, UpdateMode::FullRefresh);

    display.setCursor(0, 0);
	display.fillScreen(GxEPD_WHITE);
	display.setRotation(3);
	display.setFont(&FreeMonoBold9pt7b);
	display.setTextColor(GxEPD_BLACK);
	int16_t tbx, tby; uint16_t tbw, tbh;
	display.getTextBounds("Hello", 0, 0, &tbx, &tby, &tbw, &tbh);
	// center the bounding box by transposition of the origin:
	uint16_t x = ((display.width() - tbw) / 2) - tbx;
	uint16_t y = display.height() - tbh;
	display.setCursor(x, y);
    // display.print("Hello");


	// Align to controller grid
	uint16_t x_r = (x/8) * 8;
	uint16_t y_r = ((y-tbh)/8) * 8;
	uint16_t w_r = tbw + (x - x_r);
	uint16_t h_r = tbh + (y - y_r);

	// display.displayWindow(x_r,y_r,w_r,h_r);




    long display_init_duration = millis() - display_startup_time;
    Serial.print("Display initialized in ");
    Serial.print(display_init_duration);
    Serial.println(" ms");
}

void renderBuffer(const unsigned char image_buffer[DISPLAY_HEIGHT * DISPLAY_WIDTH], UpdateMode update_mode) {
	display.writeImage(image_buffer, 0, 0, DISPLAY_HEIGHT, DISPLAY_WIDTH, false);
	if (update_mode == FullRefresh) {
		display.refresh(false);
	} else if (update_mode == LiveUpdate) {
		display.refresh(true);
	}
}

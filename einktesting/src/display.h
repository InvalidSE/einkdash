#pragma once

#define DISPLAY_WIDTH 296
#define DISPLAY_HEIGHT 128

enum UpdateMode {
    FullRefresh,
    LiveUpdate,
    NoUpdate
};

void displayInit();
void renderBuffer(const unsigned char image_buffer[DISPLAY_HEIGHT * DISPLAY_WIDTH], UpdateMode update_mode);
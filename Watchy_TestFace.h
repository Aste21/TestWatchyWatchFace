#ifndef WATCHY_TESTFACE_H
#define WATCHY_TESTFACE_H

#include <MyWatchy.h>
#include "icones.h"
#include "FreeMonoBold20pt7b.h"

class WatchyTestFace : public Watchy {
  using Watchy::Watchy;

public:
  void drawWatchFace() {
    display.fillScreen(GxEPD_WHITE);
    uint8_t direction = sensor.getDirection();
    int cursorCoordinates[2];  // 0-x 1-y
    int rotation = 0;
    bool turnOff = false;
    display.setRotation(0);
    switch (direction) {
      case DIRECTION_DISP_DOWN:
        turnOff = true;
        break;
      case DIRECTION_DISP_UP:
        cursorCoordinates[0] = DISPLAY_WIDTH / 2 - 60;
        cursorCoordinates[1] = DISPLAY_HEIGHT / 2 + 5;
        break;
      case DIRECTION_BOTTOM_EDGE:
        display.setRotation(2);
        display.drawBitmap(DISPLAY_WIDTH / 2 - 68 / 2, DISPLAY_HEIGHT / 2 - 90 / 2, arrow_down, 68, 90, GxEPD_BLACK);
        cursorCoordinates[0] = DISPLAY_WIDTH / 2 - 60;
        cursorCoordinates[1] = DISPLAY_HEIGHT - 20;
        break;
      case DIRECTION_TOP_EDGE:
        display.drawBitmap(DISPLAY_WIDTH / 2 - 68 / 2, DISPLAY_HEIGHT / 2 - 90 / 2, arrow_up, 68, 90, GxEPD_BLACK);
        cursorCoordinates[0] = DISPLAY_WIDTH / 2 - 58;
        cursorCoordinates[1] = 40;
        break;
      case DIRECTION_RIGHT_EDGE:
        display.drawBitmap(DISPLAY_WIDTH / 2 - 90 / 2, DISPLAY_HEIGHT / 2 - 68 / 2, arrow_right, 90, 68, GxEPD_BLACK);
        cursorCoordinates[0] = DISPLAY_WIDTH - 50;
        cursorCoordinates[1] = DISPLAY_HEIGHT / 2 - 5;
        break;
      case DIRECTION_LEFT_EDGE:
        display.drawBitmap(DISPLAY_WIDTH / 2 - 90 / 2, DISPLAY_HEIGHT / 2 - 68 / 2, arrow_left, 90, 68, GxEPD_BLACK);
        cursorCoordinates[0] = 5;
        cursorCoordinates[1] = DISPLAY_HEIGHT / 2 - 5;
        break;
      default:
        break;
    }
    display.setTextColor(GxEPD_BLACK);
    if(!turnOff)
    {
      display.setFont(&FreeMonoBold20pt7b);
    display.setCursor(cursorCoordinates[0], cursorCoordinates[1]);
    if (currentTime.Hour < 10) {
      display.print('0');
    }
    display.print(currentTime.Hour);
    if (direction == DIRECTION_RIGHT_EDGE) {
      display.setCursor(DISPLAY_WIDTH - 50, DISPLAY_HEIGHT / 2 + 25);
    } else if (direction == DIRECTION_LEFT_EDGE) {
      display.setCursor(5, DISPLAY_HEIGHT / 2 + 25);
    } else {
      display.print(':');
    }
    if (currentTime.Minute < 10) {
      display.print('0');
    }
    display.print(currentTime.Minute);
    } 
  }
};

#endif
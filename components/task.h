#include "../clay.h"
#include <string.h>

void drawTask(const char* task, Clay_Color bg, Clay_Color fg, int baseFontSize, int maxFontSize)
{
  CLAY_AUTO_ID({
    .layout = {
      .sizing = { .width = CLAY_SIZING_GROW(0) },
      .padding = { 4, 4, 4, 4 },
      .childAlignment = { .y = CLAY_ALIGN_Y_CENTER },
    },
    .cornerRadius = { 8, 8, 8, 8 },
    .backgroundColor = bg,
  }) {
    Clay_String t = {
      .isStaticallyAllocated = false,
      .length = strlen(task),
      .chars = task
    };

    CLAY_TEXT(t, CLAY_TEXT_CONFIG({ .fontId = 0, .textColor = fg, .fontSize = getFontSizeCustom(baseFontSize, maxFontSize) }));
  }
}

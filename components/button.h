#include "../clay.h"
#include "../utils.h"
#include <string.h>

void drawButton(const char* id, const char* label, uint8_t fontId, float fontSizePercent, float maxFontSize, Clay_Color bg, Clay_Color hovered, Clay_Color fg, Clay_Color border)
{
  Clay_String idStr = {
    .isStaticallyAllocated = false,
    .length = strlen(id),
    .chars = id
  };

  CLAY(CLAY_SID(idStr), {
    .layout = {
      .padding = { 18, 18, 6, 6 },
      .childAlignment = {
        .x = CLAY_ALIGN_X_CENTER,
        .y = CLAY_ALIGN_Y_CENTER,
      },
    },
    .backgroundColor = Clay_Hovered() ? hovered : bg,
    .cornerRadius = { 12, 12, 12, 12 },
    .border = { border, 4, 4, 4, 4 }
  }) {
    Clay_String label_str = {
      .isStaticallyAllocated = false,
      .length = strlen(label),
      .chars = label
    };

    CLAY_TEXT(label_str, CLAY_TEXT_CONFIG({ .fontId = fontId, .textColor = fg, .fontSize = getFontSizeCustom(fontSizePercent, maxFontSize) }));
  };
}

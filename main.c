#include "./raylib-5.5_linux_amd64/include/raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include "components/button.h"
#include "components/task.h"
#include <stdio.h>

#define RAYLIB_BACKGROUND CLITERAL(Color) { 175, 160, 128 }
#define BACKGROUND { .r = 238, .g = 218, .b = 167, .a = 255 }
#define BACKGROUND2 (Clay_Color) { .r = 208, .g = 178, .b = 137, .a = 255 }
#define BORDER (Clay_Color) { .r = 56, .g = 26, .b = 11, .a = 255 }
#define PC_BLACK (Clay_Color) { .r = 0, .g = 0, .b = 0, .a = 255 }
#define PC_RED (Clay_Color) { .r = 191, .g = 71, .b = 50, .a = 255 }
#define PC_ORANGE (Clay_Color) { .r = 236, .g = 128, .b = 50, .a = 255 }
#define PC_GREEN (Clay_Color) { .r = 167, .g = 175, .b = 63, .a = 255 }
#define PC_YELLOW (Clay_Color) { .r = 231, .g = 171, .b = 57, .a = 255 }
#define PC_BLUE (Clay_Color) { .r = 45, .g = 128, .b = 130, .a = 255 }
#define PC_LIGHT_BLUE (Clay_Color) { .r = 95, .g = 158, .b = 146, .a = 255 }

#define MAX_BODY_FONT_SIZE 24
#define MAX_HEADER_FONT_SIZE 32
#define MAX_TIMER_FONT_SIZE 80

#define DRAW_TASK(t) drawTask(t, BACKGROUND2, PC_BLACK, 15, MAX_BODY_FONT_SIZE);
#define DRAW_BUTTON(id, label, bg, bgHovered) drawButton(id, label, 0, 8, MAX_BODY_FONT_SIZE, bg, bgHovered, PC_BLACK, BORDER);

Texture2D logo;

void handleError(Clay_ErrorData errorText)
{
  printf("ERROR: %s\n", errorText.errorText.chars);
}

void DrawProgram(void)
{
  CLAY(CLAY_ID("MainContainer"), {
    .layout = {
      .sizing = {
        .width = CLAY_SIZING_GROW(0),
        .height = CLAY_SIZING_GROW(0),
      },
      .childAlignment = {
        .x = CLAY_ALIGN_X_CENTER,
        .y = CLAY_ALIGN_Y_CENTER,
      },
      .padding = { 24, 24, 24, 24 },
      .childGap = 8,
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
    },
  }) {
    CLAY(CLAY_ID("WorkContainer"), {
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_PERCENT(0.75)
        },
        .childAlignment = {
          .x = CLAY_ALIGN_X_CENTER,
          .y = CLAY_ALIGN_Y_CENTER,
        },
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
      },
      .cornerRadius = { 12, 12, 12, 12 },
      .backgroundColor = BACKGROUND,
      .border = { BORDER, 4, 4, 4, 4 }
    }) {
      CLAY_TEXT(CLAY_STRING("25:00"), CLAY_TEXT_CONFIG({ .fontId = 1, .textColor = PC_BLACK, .fontSize = getFontSizeCustom(15, MAX_TIMER_FONT_SIZE) }));

      CLAY(CLAY_ID("WorkContainerButtons"), {
        .layout = {
          .sizing = {
            .width = CLAY_SIZING_GROW(0),
            .height = CLAY_SIZING_PERCENT(0.15),
          },
          .childAlignment = {
            .x = CLAY_ALIGN_X_CENTER,
            .y = CLAY_ALIGN_Y_CENTER,
          },
          .layoutDirection = CLAY_LEFT_TO_RIGHT,
          .childGap = 8,
        },
      }) {
        DRAW_BUTTON("ResetButton", "Reset", PC_BLUE, PC_LIGHT_BLUE);
        DRAW_BUTTON("StartButton", "Start", PC_GREEN, PC_YELLOW);
        DRAW_BUTTON("StopButton", "Stop", PC_RED, PC_ORANGE);
      }
    };

    CLAY(CLAY_ID("MiscContainer"), {
      .layout = {
        .sizing = {
          .width = CLAY_SIZING_GROW(0),
          .height = CLAY_SIZING_GROW(0),
        },
        .childGap = 8,
      },
    }) {
      CLAY(CLAY_ID("MiscTaskContainer"), {
        .layout = {
          .sizing = {
            .width = CLAY_SIZING_GROW(0),
            .height = CLAY_SIZING_GROW(0)
          },
          .layoutDirection = CLAY_TOP_TO_BOTTOM,
          .childAlignment = {
            .y = CLAY_ALIGN_Y_CENTER,
          },
          .padding = { 16, 16, 16, 16}
        },
        .cornerRadius = { 12, 12, 12, 12 },
        .backgroundColor = BACKGROUND,
        .border = { BORDER, 4, 4, 4, 4 }
      }) {
        CLAY_TEXT(CLAY_STRING("Task List"), CLAY_TEXT_CONFIG({ .fontId = 1, .textColor = PC_BLACK, .fontSize = getFontSizeCustom(15, MAX_HEADER_FONT_SIZE) }));
        CLAY(CLAY_ID("Tasks"), {
          .layout = {
            .sizing = {
              .width = CLAY_SIZING_GROW(0),
              .height = CLAY_SIZING_GROW(0)
            },
            .layoutDirection = CLAY_TOP_TO_BOTTOM,
            .padding = { 8, 8, 8, 8},
            .childGap = 4,
            .childAlignment = {
            },
          },
        }) {
          DRAW_TASK("TASK 1");
        };
        CLAY(CLAY_ID("MiscTaskActionContainer"), {
          .layout = {
            .sizing = { .width = CLAY_SIZING_GROW(0) },
            .childAlignment = { .x = CLAY_ALIGN_X_CENTER },
          },
        }) {
          DRAW_BUTTON("AddTaskButton", "Add Task", PC_GREEN, PC_YELLOW);
        };
      };

      /* CLAY(CLAY_ID("AnalyticsContainer"), { */
      /*   .layout = { */
      /*     .sizing = { */
      /*       .width = CLAY_SIZING_PERCENT(0.25), */
      /*       .height = CLAY_SIZING_GROW(0) */
      /*     }, */
      /*     .layoutDirection = CLAY_TOP_TO_BOTTOM, */
      /*     .childAlignment = { */
      /*       .x = CLAY_ALIGN_X_CENTER, */
      /*       .y = CLAY_ALIGN_Y_CENTER, */
      /*     }, */
      /*     .padding = { 16, 16, 16, 16} */
      /*   }, */
      /*   .cornerRadius = { 12, 12, 12, 12 }, */
      /*   .backgroundColor = BACKGROUND, */
      /*   .border = { BORDER, 4, 4, 4, 4 } */
      /* }) { */
      /*   const float logoSize = (16.0 * (float)GetScreenHeight()) / 100; */
      /*   CLAY(CLAY_ID("logo"), { .layout = { .sizing = { .width = CLAY_SIZING_FIXED(logoSize), .height = CLAY_SIZING_FIXED(logoSize) } }, .image = { .imageData = &logo }}) {} */
      /* }; */
    };
  };
}

int main(void)
{
  uint32_t minMemoryRequired = Clay_MinMemorySize();
  Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(minMemoryRequired, malloc(minMemoryRequired));
  Clay_Initialize(arena,
  (Clay_Dimensions) {
    (float)GetScreenWidth(), (float)GetScreenHeight()
  },
  (Clay_ErrorHandler) {
    handleError, 0
  });
  Clay_Raylib_Initialize(800, 600, "PomoClay", FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_MSAA_4X_HINT);
  SetExitKey(KEY_Q);

  Font fonts[2];
  fonts[0] = LoadFontEx("CabinFont/Cabin-Regular.ttf", 24, 0, 400);
  fonts[1] = LoadFontEx("CabinFont/Cabin-Bold.ttf", 80, 0, 400);
  SetTextureFilter(fonts[0].texture, TEXTURE_FILTER_TRILINEAR);
  SetTextureFilter(fonts[1].texture, TEXTURE_FILTER_TRILINEAR);
  Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);
  bool debugEnabled = false;

  logo = LoadTexture("logo.png");

  while(!WindowShouldClose()) {
    SetTargetFPS(60);

    Vector2 mouseWheelDelta = GetMouseWheelMoveV();
    float mouseWheelX = mouseWheelDelta.x;
    float mouseWheelY = mouseWheelDelta.y;
    Clay_UpdateScrollContainers(true, (Clay_Vector2) {
      mouseWheelX, mouseWheelY
    }, GetFrameTime());

    bool clicking = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
    Clay_Vector2 position = (Clay_Vector2) {
      GetMousePosition().x, GetMousePosition().y
    };
    Clay_SetPointerState(position, clicking);

    if(IsKeyPressed(KEY_D)) {
      debugEnabled = !debugEnabled;
      Clay_SetDebugModeEnabled(debugEnabled);
    }

    Clay_SetLayoutDimensions((Clay_Dimensions) {
      (float)GetScreenWidth(), (float)GetScreenHeight()
    });

    Clay_BeginLayout();
    DrawProgram();
    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    BeginDrawing();
    ClearBackground(RAYLIB_BACKGROUND);
    Clay_Raylib_Render(renderCommands, fonts);
    EndDrawing();
  }

  Clay_Raylib_Close();

  return 0;
}

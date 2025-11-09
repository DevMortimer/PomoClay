#include "./raylib-5.5_linux_amd64/include/raylib.h"
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include "components/button.h"
#include <stdio.h>

#define RAYLIB_BACKGROUND CLITERAL(Color) { 175, 160, 128 }
#define BACKGROUND { .r = 238, .g = 218, .b = 167, .a = 255 }
#define BORDER { .r = 56, .g = 26, .b = 11, .a = 255 }
#define PC_BLACK { .r = 0, .g = 0, .b = 0, .a = 255 }
#define PC_RED { .r = 191, .g = 71, .b = 50, .a = 255 }
#define PC_ORANGE { .r = 236, .g = 128, .b = 50, .a = 255 }
#define PC_GREEN { .r = 167, .g = 175, .b = 63, .a = 255 }
#define PC_YELLOW { .r = 231, .g = 171, .b = 57, .a = 255 }
#define PC_BLUE { .r = 45, .g = 128, .b = 130, .a = 255 }
#define PC_LIGHT_BLUE { .r = 95, .g = 158, .b = 146, .a = 255 }

#define MAX_BODY_FONT_SIZE 24
#define MAX_HEADER_FONT_SIZE 32
#define MAX_TIMER_FONT_SIZE 80

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
                drawButton("ResetButton", "Reset", 0, 8, MAX_BODY_FONT_SIZE, (Clay_Color) PC_BLUE, (Clay_Color) PC_LIGHT_BLUE, (Clay_Color) PC_BLACK, (Clay_Color) BORDER);
                drawButton("StartButton", "Start", 0, 8, MAX_BODY_FONT_SIZE, (Clay_Color) PC_GREEN, (Clay_Color) PC_YELLOW, (Clay_Color) PC_BLACK, (Clay_Color) BORDER);
                drawButton("StopButton", "Stop", 0, 8, MAX_BODY_FONT_SIZE, (Clay_Color) PC_RED, (Clay_Color) PC_ORANGE, (Clay_Color) PC_BLACK, (Clay_Color) BORDER);
            };
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
                        .width = CLAY_SIZING_PERCENT(0.75),
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
                            .height = CLAY_SIZING_GROW(0)
                        },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                        .padding = { 8, 8, 8, 8},
                        .childGap = 4,
                        .childAlignment = {
                            .y = CLAY_ALIGN_Y_CENTER,
                        },
                    },
                }) {
                    CLAY_TEXT(CLAY_STRING("Task 1"), CLAY_TEXT_CONFIG({ .fontId = 0, .textColor = PC_BLACK, .fontSize = getFontSizeCustom(15, MAX_BODY_FONT_SIZE) }));
                    CLAY_TEXT(CLAY_STRING("Task 2"), CLAY_TEXT_CONFIG({ .fontId = 0, .textColor = PC_BLACK, .fontSize = getFontSizeCustom(15, MAX_BODY_FONT_SIZE) }));
                    CLAY_TEXT(CLAY_STRING("Task 3"), CLAY_TEXT_CONFIG({ .fontId = 0, .textColor = PC_BLACK, .fontSize = getFontSizeCustom(15, MAX_BODY_FONT_SIZE) }));
                };
            };

            CLAY(CLAY_ID("AnalyticsContainer"), {
                .layout = {
                    .sizing = {
                        .width = CLAY_SIZING_PERCENT(0.25),
                        .height = CLAY_SIZING_GROW(0)
                    },
                    .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    .childAlignment = {
                        .x = CLAY_ALIGN_X_CENTER,
                        .y = CLAY_ALIGN_Y_CENTER,
                    },
                    .padding = { 16, 16, 16, 16}
                },
                .cornerRadius = { 12, 12, 12, 12 },
                .backgroundColor = BACKGROUND,
                .border = { BORDER, 4, 4, 4, 4 }
            }) {
                const float logoSize = (16.0 * (float)GetScreenHeight()) / 100;
                CLAY(CLAY_ID("logo"), { .layout = { .sizing = { .width = CLAY_SIZING_FIXED(logoSize), .height = CLAY_SIZING_FIXED(logoSize) } }, .image = { .imageData = &logo }}) {}
            };
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

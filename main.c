#include <stdio.h>
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include "./raylib-5.5_linux_amd64/include/raylib.h"

#define BACKGROUND CLITERAL(Color){ 69, 69, 69 }

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
            .padding = { 16, 16, 16, 16 },
            .childGap = 8,
            .layoutDirection = CLAY_TOP_TO_BOTTOM,
        },
    }) {
        CLAY_TEXT(CLAY_STRING("PomoClay"), CLAY_TEXT_CONFIG({ .fontSize = 24, .textColor = { 255, 255, 255, 255 }}));
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
    Clay_Raylib_Initialize(800, 600, "PomoClay", FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    SetExitKey(KEY_Q);

    Font fonts[1];
    fonts[0] = GetFontDefault();
    Clay_SetMeasureTextFunction(Raylib_MeasureText, fonts);

    Image image = LoadImage("logo.png");

    bool debugEnabled = false;

    while(!WindowShouldClose()) {
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
        ClearBackground(BACKGROUND);
        Clay_Raylib_Render(renderCommands, fonts);
        EndDrawing();
    }

    Clay_Raylib_Close();

    return 0;
}

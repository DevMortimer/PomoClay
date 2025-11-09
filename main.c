#include <stdio.h>
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "clay_renderer_raylib.c"
#include "./raylib-5.5_linux_amd64/include/raylib.h"

void handleError(Clay_ErrorData errorText)
{
  printf("ERROR: %s\n", errorText.errorText.chars);
}

int main(void)
{
  uint32_t minMemoryRequired = Clay_MinMemorySize();
  Clay_Arena arena = Clay_CreateArenaWithCapacityAndMemory(minMemoryRequired, malloc(minMemoryRequired));
  Clay_Initialize(arena,
                  (Clay_Dimensions){ (float)GetScreenWidth(), (float)GetScreenHeight() },
                  (Clay_ErrorHandler){ handleError, 0 });
  Clay_Raylib_Initialize(800, 600, "PomoClay", FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);

  Font font = GetFontDefault();

  while (!WindowShouldClose()) {
    Clay_BeginLayout();

    
    
    Clay_RenderCommandArray renderCommands = Clay_EndLayout();
    
    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(renderCommands, &font);
    EndDrawing();
  }

  Clay_Raylib_Close();
  
  return 0;
}

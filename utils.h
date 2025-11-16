#if defined(__APPLE__)
#include "./raylib-5.5_macos/include/raylib.h"
#elif defined(__linux__)
#include "./raylib-5.5_linux_amd64/include/raylib.h"
#else
// This will stop compilation if the OS is not recognized
#error "Unsupported operating system. This code only supports macOS and Linux."
#endif

float getFontSizeCustom(float base, float max)
{
    const float buff = (base * GetScreenWidth()) / 100;
    float titleFontSize = buff > max ? max : buff;
    return titleFontSize;
}

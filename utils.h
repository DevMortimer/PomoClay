#include "./raylib-5.5_linux_amd64/include/raylib.h"

float getFontSizeCustom(float base, float max)
{
    const float buff = (base * GetScreenWidth()) / 100;
    float titleFontSize = buff > max ? max : buff;
    return titleFontSize;
}

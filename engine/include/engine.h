#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "util.h"
#include "maths.h"

uint32_t w_flags;

void pe_init(void);

void pe_createWindow(const char *name, int width, int height, uint32_t *flags);

void pe_createRenderer(void);

void pe_clearScreen(int r, int g, int b, int a);

void pe_startRender(void);

void pe_endRender(void);

void pe_drawCircle(int centerX, int centerY, int radius);

void pe_getInput(void);

void pe_uninit(void);
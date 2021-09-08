#include "../include/engine.h"
#include <stdio.h>
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int imgFlags = IMG_INIT_PNG;
uint32_t w_flags = 0;

void pe_init(void){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        SDL_Log("Failed to Initialize SDL: %s", SDL_GetError());
    }
    else if ((IMG_Init(imgFlags) & imgFlags) != imgFlags){
        SDL_Log("Failed to Initialize SDL_img: %s", IMG_GetError());
    }
}

void pe_uninit(void){
    printf("uniniting renderer, window, SDL\n");
    SDL_DestroyRenderer(renderer);
    printf("renderer uninited\n");
    SDL_DestroyWindow(window);
    printf("window uninited\n");
    IMG_Quit();
    printf("SDL_IMG uninited\n");
    SDL_Quit();
    printf("SDL uninited\n");
}

void pe_createWindow(const char *title, int width, int height, uint32_t *flags){
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, *flags);
    if (!window){
        fprintf(stderr, "ERROR INITIALIZING WINDOW.\n");
    }
}


void pe_createRenderer(void){
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer){
        fprintf(stderr, "ERROR INITIALIZING RENDERER.\n");
    }
}

void pe_clearScreen(int r, int g, int b, int a){
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void pe_startRender(void){
    SDL_RenderClear(renderer);
}

void pe_endRender(void){
    SDL_RenderPresent(renderer);
}

void pe_drawCircle(int centerX, int centerY, int radius){
       const int diameter = (radius * 2);

       int x = (radius - 1);
       int y = 0;
       int tx = 1;
       int ty = 1;
       int error = (tx - diameter);

       while (x >= y) {
	
	  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	  /*  Each of the following renders an octant of the circle */
	  SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
	  SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
	  SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
	  SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
	  SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
	  SDL_RenderDrawPoint(renderer,centerX + y, centerY + x);
	  SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
	  SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);

	  if (error <= 0) {
	     ++y;
	     error += ty;
	     ty += 2;
	  }

	  if (error > 0) {
	     --x;
	     tx += 2;
	     error += (tx - diameter);
	  }
    }
}

void pe_getInput(void){

}

#include "SDL.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  SDL_Window *window = SDL_CreateWindow
    ( "SDL .app demo"
    , SDL_WINDOWPOS_UNDEFINED
    , SDL_WINDOWPOS_UNDEFINED
    , 800
    , 600
    , 0 // SDL_WINDOW_ALLOW_HIGHDPI
    );
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  SDL_Renderer *render = SDL_CreateRenderer(window, -1, 0);
  if (render == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
  }

  while (1) {
    bool user_quit = false;
    SDL_Event test_event;
    while (SDL_PollEvent(&test_event)) {
      if (test_event.type == SDL_QUIT) {
        user_quit = true;
      }
    }
    if (user_quit) break;

    SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);
    SDL_Delay(16);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

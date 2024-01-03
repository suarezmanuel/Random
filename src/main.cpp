#include <iostream>
#include <SDL2/SDL.h>

#define WIDTH 600
#define HEIGHT 600

int main (int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    if (window == NULL) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    }

    SDL_Event windowEvent;

    
    int count = 0;

    for (int g = 0; g < 256; g++) {
        for (int b = 0; b < 256; b++) {
        
            SDL_SetRenderDrawColor(renderer, 255-b, g, b, 255);
            
            for (int i = 0; i < 5; i++)
            {
                int randx = rand() % WIDTH;
                int randy = rand() % HEIGHT;
                // looping code here, let's first do it ugly and afterwards use functions for this.
                SDL_RenderDrawPoint(renderer, randx, randy);
                SDL_RenderPresent(renderer);
            }
        }
    }

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
                if (SDL_QUIT == windowEvent.type) {
                    break;
                }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
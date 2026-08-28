#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <SDL.h>
using namespace std;
typedef int32_t i32; 

constexpr i32 WIDTH = 900;
constexpr i32 HEIGHT = 600;

int main(int argc, const char *argv[])
{
    i32 num_agents{0};
    if (argc == 1)
    {
        num_agents = 5; 
    } else if (argc == 2)
    {
        num_agents = atoi(argv[1]);
    }
    else
    {
        cout << "Usage: "  << num_agents << endl; 
    }
    SDL_Window *pwindow = SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
     SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    SDL_Rect rect = (SDL_Rect) {50, 50, 50, 50};
    SDL_Delay(300);

    i32 app_running =  1; 
    while(app_running) 
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) 
            {
                app_running = 0; 
            }
        }
        SDL_FillRect(psurface, &rect, 0xFFFFFF);
        SDL_UpdateWindowSurface(pwindow);
    }
}







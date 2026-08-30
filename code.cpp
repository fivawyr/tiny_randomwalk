#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include <time.h>
#include <vector>

using namespace std;
typedef int32_t i32; 

constexpr i32 WIDTH = 900;
constexpr i32 HEIGHT = 600;

struct Velocity 
{
    i32 vx, vy; 
};

Velocity get_rand_velocity() 
{
    i32 opts = rand() % 4; 
    switch (opts) 
    {
        case 0: return (Velocity) {0, -1};
        case 1: return (Velocity) {0, 1};
        case 2: return (Velocity) {-1, 0};
        case 3: return (Velocity) {1, 0};
    }
    fprintf(stderr, "impossible value %d\n", opts);
    exit(-1);
}

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
        return -1; 
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        cerr << "couldnt init SDL" << SDL_GetError() << "\n";
        return -1;
    }
    srand(time(NULL));
    SDL_Window *pwindow = SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    vector<SDL_Rect> agents; 
    agents.reserve(num_agents);
    for (i32 i = 0; i < num_agents; i++) 
    {
        i32 start_x = WIDTH / 2 - 5 / 2;
        i32 start_y = HEIGHT / 2 - 5 / 2; 
        agents.push_back((SDL_Rect) {start_x,start_y, 5, 5});
    }
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
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) app_running = 0;
        }

        for (SDL_Rect &agent : agents) 
        {
            Velocity v = get_rand_velocity();
            agent.x += v.vx * 2; 
            agent.y+= v.vy * 2;
            if (agent.x < 0) agent.x = 0; 
            if (agent.x > WIDTH - agent.w) agent.x = WIDTH - agent.w; 
            if (agent.y < 0) agent.y = 0; 
            if (agent.y > HEIGHT - agent.h) agent.y = HEIGHT - agent.h;
            SDL_FillRect(psurface, &agent, 0xFFFFFF);
        }
        vector<uint32_t> colors;
        colors.reserve(num_agents);
        for (i32 i = 0; i < num_agents; i++) 
        {
            uint8_t r = rand() % 256;
            uint8_t g = rand() & 256; 
            uint8_t b = rand() & 256; 
            colors.push_back(SDL_MapRGB(psurface->format, r, g, b));
        }
        for (size_t i = 0; i < agents.size(); i++) 
        {
            SDL_Rect &agent = agents[i];
            Velocity v = get_rand_velocity();
            agent.x += v.vy * 2; 
            agent.y += v.vy * 2;
            SDL_FillRect(psurface, &agent, colors[i]);
        }
        
        SDL_UpdateWindowSurface(pwindow);
        SDL_Delay(16);
    }
    SDL_DestroyWindow(pwindow);
    SDL_Quit(); 
    return 0; 
}







#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <raylib.h>

using namespace std;
typedef int32_t i32; 
typedef float f32;

constexpr f32 WIDTH = 900.0f;
constexpr f32 HEIGHT = 600.0f;

struct Velocity {
    f32 vx, vy; 
};

struct TracePoint {
    Rectangle rect;
    Color color;
};

f32 get_levy_step(f32 gamma = 1.5f, f32 base_step = 2.0f, f32 max_step = 100.0f) {
    f32 u = (static_cast<f32>(rand()) + 1.0f) / (RAND_MAX + 1.0f);
    f32 step = base_step * powf(u, -1.0f / gamma);
    if (step > max_step) step = max_step; 
    return step;
}

Velocity get_levy_velocity() {
    f32 step = get_levy_step(1.5f, 2.0f, 80.0f);
    i32 opts = rand() % 4; 
    switch (opts) {
        case 0: return Velocity{0.0f, -step};
        case 1: return Velocity{0.0f, step};
        case 2: return Velocity{-step, 0.0f};
        case 3: return Velocity{step, 0.0f};
    }
    return Velocity{0.0f, 0.0f};
}

int main(int argc, const char *argv[]) {
    vector<TracePoint> trace;
    i32 num_agents{0};

    if (argc == 1) num_agents = 5; 
    else if (argc == 2) num_agents = atoi(argv[1]);
    else return -1; 
    srand(time(NULL));

    InitWindow(WIDTH, HEIGHT, "Levy Flight Random Walk");
    SetTargetFPS(60); 

    vector<Rectangle> agents; 
    agents.reserve(num_agents);
    for (i32 i = 0; i < num_agents; i++)  {
        f32 start_x = static_cast<f32>(WIDTH / 2 - 5.0f / 2);
        f32 start_y = static_cast<f32 >(HEIGHT / 2 - 5.0f / 2); 
        agents.push_back(Rectangle{start_x, start_y, 5.0f, 5.0f});
    }
    vector<Color> colors;
    for (i32 i = 0; i < num_agents; i++) {
        colors.push_back(Color{
            static_cast<unsigned char>(rand() % 256),
            static_cast<unsigned char>(rand() % 256),
            static_cast<unsigned char>(rand() % 256),
            255
        });
    }
    while (!WindowShouldClose()) {
        for (size_t i = 0; i < agents.size(); ++i) {
            Rectangle &agent = agents[i];
            Velocity v = get_levy_velocity();
            agent.x += v.vx; 
            agent.y += v.vy;
            if (agent.x < 0) agent.x = 0; 
            if (agent.x > WIDTH - agent.width) agent.x = WIDTH - agent.width; 
            if (agent.y < 0) agent.y = 0; 
            if (agent.y > HEIGHT - agent.height) agent.y = HEIGHT - agent.height;
            trace.push_back(TracePoint{agent, colors[i]});
        }
        BeginDrawing();
        ClearBackground(BLACK); 
        for (const TracePoint &t : trace) {
            DrawRectangleRec(t.rect, t.color);
        }
        for (size_t i = 0; i < agents.size(); ++i) {
            DrawRectangleRec(agents[i], colors[i]);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0; 
}

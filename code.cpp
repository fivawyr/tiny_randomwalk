#include <cstdint>
#include <SDL.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
typedef int32_t i32; 

constexpr i32 WIDTH = 900;
constexpr i32 HEIGHT = 600;

int main(int argc, const char *argv[])
{
    i32 num_agents;
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
}

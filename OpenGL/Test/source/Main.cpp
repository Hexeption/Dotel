//
// Created by Keirb on 12/11/2017.
//

#include <Window.h>

int main(int argc, char* argv[])
{
    Dotel::Window window(800, 600, "Dotel Example!");

    while(!window.shouldClose())
    {
        window.clear();
        window.update();
    }
    return 0;
}
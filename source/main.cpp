#include <cstdlib>
#include "Window.h"

int main(void) {

    Window *pWindow = new Window(1280, 720, false);
    pWindow->Create();

    while (pWindow->ShouldClose()) {

        pWindow->Render();

    }

    pWindow->Destory();

    exit(EXIT_SUCCESS);
}
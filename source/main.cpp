#include "Window.h"

int main() {
    Window window(1280, 720, "Vox", false);

    while (!window.ShouldClose()) {
        window.PrepareRender();
        /*
         * Do Renderering stuff
         */
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        window.UpdateDisplay();
    }

    return 0;
}
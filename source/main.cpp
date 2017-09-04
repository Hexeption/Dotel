#include "D_Window.h"
#include "D_Triangle.h"

int main() {
    D_Window window(1280, 720, "Vox", false);

    while (!window.ShouldClose()) {
        window.PrepareRender();
        /*
         * Do Renderering stuff
         */
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

		glBegin(GL_TRIANGLES);

		D_Triangle(-0.6f, -0.4f,  0.0f,  1.f,  0.f,  0.f,  1.0f).Draw();
		D_Triangle( 0.6f, -0.4f,  0.0f,  0.f,  1.f,  0.f,  1.0f).Draw();
		D_Triangle( 0.0f,  0.6f,  0.0f,  0.f,  0.f,  1.f,  1.0f).Draw();

		glEnd();

        window.UpdateDisplay();
    }

    return 0;
}
#include <vector>
#include "D_Window.h"
#include "D_Triangle.h"
#include "D_Renderer.h"

int main() {
    D_Window window(1280, 720, "Vox", false);
	D_Renderer renderer;

	std::vector<D_Triangle> triangles;

	triangles.push_back(D_Triangle(-0.6f, -0.4f, 0.0f, 1.f, 0.f, 0.f, 1.0f));
	triangles.push_back(D_Triangle(0.6f, -0.4f, 0.0f, 0.f, 1.f, 0.f, 1.0f));
	triangles.push_back(D_Triangle(0.0f, 0.6f, 0.0f, 0.f, 0.f, 1.f, 1.0f));

    while (!window.ShouldClose()) {
        window.PrepareRender();
        renderer.RotatePitch(window.getDeltaTime() * 50.f);
		renderer.Render(triangles);
        window.UpdateDisplay();
    }

    return 0;
}
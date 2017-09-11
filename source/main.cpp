#include "D_Window.h"
#include "D_Mesh.h"
#include "D_ShaderLoader.h"
#include "D_Texture.h"

int main()
{
    D_Window window(800, 600, "Dotel 2.0 Example");

    D_Vertex vertices[]
            {
                    D_Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
                    D_Vertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec2(0.0, 1.0)),
                    D_Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)),

                    D_Vertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec2(0.0, 1.0)),
                    D_Vertex(glm::vec3(0.5, 0.5, 0.0), glm::vec2(1.0, 1.0)),
                    D_Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0))
            };

    D_ShaderLoader shader("../assets/shaders/core.vs.glsl", "../assets/shaders/core.frag.glsl");
    D_Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    D_Texture texture("../assets/images/Tux.png");

    while (!window.shouldClose())
    {
        window.clear();

        shader.Use();
        texture.Bind(0);
        mesh.Draw();

        window.update();
    }

    return 0;
}
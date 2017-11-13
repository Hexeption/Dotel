//
// Created by Keirb on 12/11/2017.
//

#include <Window.h>
#include <glm/glm.hpp>
#include <Mesh.h>
#include <ShaderLoader.h>
#include <Texture.h>

using namespace Dotel;

int main(int argc, char *argv[])
{
    Window window(800, 600, "Dotel Example!");

    Vertex vertices[]
            {
                    Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
                    Vertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec2(0.0, 1.0)),
                    Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0)),

                    Vertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec2(0.0, 1.0)),
                    Vertex(glm::vec3(0.5, 0.5, 0.0), glm::vec2(1.0, 1.0)),
                    Vertex(glm::vec3(0.5, -0.5, 0.0), glm::vec2(1.0, 0.0))
            };
    ShaderLoader shader("data/shaders/core.vs.glsl", "data/shaders/core.frag.glsl");
    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Texture texture("data/images/Tux.png");

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
//
// Created by Keirb on 12/11/2017.
//

#include "../include/Window.h"

void error_callback(int error, const char *description);

Dotel::Window::Window(int width, int height, const std::string &title)
{
    if (!glfwInit())
    {
        Logger().Log("Failed to Initialize Windowing Library", true);
    }

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (m_Window == NULL)
    {
        Logger().Log("Failed to create Window!", true);
    }

    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        Logger().Log("Failed to Initialize OpenGL", true);
    }

    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

Dotel::Window::~Window()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void Dotel::Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Dotel::Window::update()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

bool Dotel::Window::shouldClose()
{
    return glfwWindowShouldClose(m_Window);

}

void error_callback(int error, const char *description)
{
    Dotel::Logger().Log(description, false);
}
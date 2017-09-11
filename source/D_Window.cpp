#include "D_Window.h"

void error_callback(int error, const char *description);

D_Window::D_Window(int width, int height, const std::string &title)
{
    if (!glfwInit())
    {
        D_Logger().Log("Failed to Initilize Windowing Library", true);
    }

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (m_window == NULL)
    {
        D_Logger().Log("Failed to create Window!", true);
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        D_Logger().Log("Failed to Initilize OpenGL", true);
    }

    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

D_Window::~D_Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool D_Window::shouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void D_Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void D_Window::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void error_callback(int error, const char *description)
{
    D_Logger().Log(description, false);
}
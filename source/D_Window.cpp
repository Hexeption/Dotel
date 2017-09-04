//
// Created by Keir on 16/08/2017.
//

#include <iostream>
#include "D_Window.h"

//The method called when the Window is resized
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

D_Window::D_Window(int width, int height, const std::string &windowTitle, bool fullscreen) {
    m_pFullscreen = fullscreen;

    m_windowTitle = windowTitle;
    m_windowWidth = width;
    m_windowHeight = height;
    m_oldWindowWidth = m_windowWidth;
    m_oldWindowHeight = m_windowHeight;

    Create();
}

D_Window::~D_Window() {
    Destroy();
}

void D_Window::SetupModernOpenGL() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void D_Window::SetupForOSX() {
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void D_Window::Create() {
    /* Initialize the window library */
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        std::exit(-1);
    }

    /* Create a windowed mode window and it's OpenGL context */
    m_pWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), NULL, NULL);
    if (!m_pWindow) {
        std::cerr << "Failed to create Window, Possible cause: Not Enough Memory" << std::endl;
        glfwTerminate();
        std::exit(-1);
    }

    glfwMakeContextCurrent(m_pWindow);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        std::exit(-1);
    }

	#ifdef D_MODERN_OPENGL
	SetupModernOpenGL();
	#ifdef D_OSX
	SetupForOSX();
	#endif
	#endif

    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

    glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);
}

void D_Window::Destroy() {
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
}

void D_Window::Update(float dt) {
}

void D_Window::InitializeProjectionMatrix() {
    float ratio = m_windowWidth / (float) m_windowHeight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void D_Window::UpdateWindowVariables() {
    glfwGetWindowSize(m_pWindow, &m_windowWidth, &m_windowHeight);
}

void D_Window::ClearDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void D_Window::UpdateDisplay() {
    glfwSwapBuffers(m_pWindow);
    glfwPollEvents();
}

void D_Window::PrepareRender() {
    ClearDisplay();
    UpdateWindowVariables();
    InitializeProjectionMatrix();
}

bool D_Window::ShouldClose() {
    return static_cast<bool>(glfwWindowShouldClose(m_pWindow));
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

double D_Window::getDeltaTime()
{
	return glfwGetTime();
}
//
// Created by Keir on 16/08/2017.
//

#include <cassert>
#include "Window.h"

Window::Window(int width, int height, bool fullscreen) {
    m_pFullscreen = fullscreen;

    m_windowWidth = width;
    m_windowHeight = height;
    m_oldWindowWidth = m_windowWidth;
    m_oldWindowHeight = m_windowHeight;
}

Window::~Window() {

}

void Window::Create() {
    /* Initialize the window library */
    if (!glfwInit())
        exit(EXIT_FAILURE);

    /* Create a windowed mode window and it's OpenGL context */
    m_pWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, "Vox", NULL, NULL);
    if (!m_pWindow) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_pWindow);
    glfwSwapInterval(1);
}

void Window::Destory() {
    glfwTerminate();
}

void Window::Update(float dt) {

}

void Window::Render() {
    float ratio;
    int width, height;
    glfwGetFramebufferSize(m_pWindow, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    glfwSwapBuffers(m_pWindow);
    glfwPollEvents();
}


bool Window::ShouldClose() {
    return !static_cast<bool>(glfwWindowShouldClose(m_pWindow));
}

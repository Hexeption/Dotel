//
// Created by Keir on 16/08/2017.
//

#ifndef DOTEL_WINDOW_H
#define DOTEL_WINDOW_H


#include <GLFW/glfw3.h>

class Window {

public:
    Window(int width, int height, bool fullscreen);

    ~Window();

    void Create();

    void Destory();

    void Update(float dt);

    void Render();

    void InitializeWindowContext(GLFWwindow *window);

    bool ShouldClose();

private:
    GLFWwindow *m_pWindow;

    bool m_pFullscreen;


    int m_windowWidth;
    int m_windowHeight;
    int m_oldWindowWidth;
    int m_oldWindowHeight;
};


#endif //DOTEL_WINDOW_H

//
// Created by Keir on 16/08/2017.
//

#ifndef DOTEL_WINDOW_H
#define DOTEL_WINDOW_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <string>
#include "D_Logger.h"

class D_Window
{
public:
    D_Window(int width, int height, const std::string &title);

    ~D_Window();

    void clear();

    void update();

    bool shouldClose();

protected:
private:
    GLFWwindow *m_window;
};

#endif //DOTEL_WINDOW_H

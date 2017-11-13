//
// Created by Keirb on 12/11/2017.
//

#ifndef DOTEL_WINDOW_H
#define DOTEL_WINDOW_H

#include <string>

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include "Logger.h"

namespace Dotel
{
    class Window
    {
    public:
        Window(int width, int height, const std::string &title);

        ~Window();

        void clear();

        void update();

        bool shouldClose();

    private:
        GLFWwindow *m_Window;
    };
}


#endif //DOTEL_WINDOW_H

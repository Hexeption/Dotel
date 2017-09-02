//
// Created by Keir on 16/08/2017.
//

#ifndef DOTEL_WINDOW_H
#define DOTEL_WINDOW_H

#include <string>
#include <GLFW\glfw3.h>

class Window {

public:
    Window(int width, int height, const std::string& windowTitle, bool fullscreen);
    ~Window();

    void Create();
    void Destroy();
    void Update(float dt);
    void PrepareRender();
	void UpdateDisplay();
	void SetupModernOpenGL();
	void SetupForOSX();
	void InitializeProjectionMatrix();
	void UpdateWindowVariables();
	void ClearDisplay();
    bool ShouldClose();
private:
    GLFWwindow *m_pWindow;

    bool m_pFullscreen;

	std::string m_windowTitle;
    int m_windowWidth;
    int m_windowHeight;
    int m_oldWindowWidth;
    int m_oldWindowHeight;
};


#endif //DOTEL_WINDOW_H

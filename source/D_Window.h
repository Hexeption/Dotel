//
// Created by Keir on 16/08/2017.
//

#ifndef DOTEL_WINDOW_H
#define DOTEL_WINDOW_H

#include <string>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW\glfw3.h>

class D_Window {

public:
    D_Window(int width, int height, const std::string& windowTitle, bool fullscreen);
    ~D_Window();

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
	double getDeltaTime();
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

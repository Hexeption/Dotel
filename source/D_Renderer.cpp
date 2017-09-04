#include "D_Renderer.h"
#include <GL\glew.h>

D_Renderer::D_Renderer()
{

}

D_Renderer::~D_Renderer()
{
	
}

void D_Renderer::RotateRoll(float angle)
{
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
}

void D_Renderer::RotateYaw(float angle)
{
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
}

void D_Renderer::RotatePitch(float angle)
{
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
}

void D_Renderer::Render(std::vector<D_Triangle> triangles)
{
	glBegin(GL_TRIANGLES);
	for (auto triangle : triangles)
	{
		triangle.Draw();
	}
	glEnd();
}

void D_Renderer::Translate(float x, float y, float z)
{
	glTranslatef(x, y, z);
}
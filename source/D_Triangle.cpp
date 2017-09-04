#include "D_Triangle.h"
#include <GL\glew.h>

D_Triangle::D_Triangle(float x, float y, float z, float r, float g, float b, float a) {
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
	this->m_r = r;
	this->m_g = g;
	this->m_b = b;
	this->m_a = a;

	#ifdef D_MODERN_OPENGL
	//Setup triangle for ModernOpenGL
	#endif
}

D_Triangle::~D_Triangle() {
}

void D_Triangle::Draw() {
	#ifdef D_MODERN_OPENGL
	//Do modern OpenGL triangle drawing
	return;
	#endif

	glColor4f(m_r, m_g, m_b, m_a);
	glVertex3f(m_x, m_y, m_z);
}
#pragma once
class D_Triangle
{
public:
	D_Triangle(float x, float y, float z, float r, float b, float g, float a);
	~D_Triangle();

	void Draw();
protected:
private:
	float m_x = 0;
	float m_y = 0;
	float m_z = 0;
	float m_r = 0;
	float m_b = 0;
	float m_g = 0;
	float m_a = 0;
};


#pragma once

#include <vector>
#include "D_Triangle.h"

class D_Renderer
{
public:
	D_Renderer();
	~D_Renderer();

	void Render(std::vector<D_Triangle> triangles);

	void Translate(float x, float y, float z);

	void RotateRoll(float angle);
	void RotatePitch(float angle);
	void RotateYaw(float angle);
protected:
private:
};


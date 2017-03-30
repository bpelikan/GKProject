#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

static class Transformation
{
public:
	Transformation();
	~Transformation();

	static void Rotate(GLfloat *wsp, float angle);
	static void RotateX(GLfloat *wsp, float angle);
	static void RotateY(GLfloat *wsp, float angle);
	static void RotateZ(GLfloat *wsp, float angle);
};


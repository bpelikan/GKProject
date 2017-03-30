#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Walec
{
public:
	Walec();
	Walec(GLfloat wsp[3]);
	Walec(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Walec();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw(GLfloat r, GLfloat h);
};


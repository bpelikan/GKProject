#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Stozek
{
public:
	Stozek();
	Stozek(GLfloat wsp[3]);
	Stozek(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Stozek();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw(GLfloat rg = 10, GLfloat rd = 40, GLfloat h1 = 15, GLfloat h2 = 10);
};


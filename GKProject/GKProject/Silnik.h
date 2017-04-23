#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Silnik
{
public:
	Silnik();
	Silnik(GLfloat wsp[3]);
	Silnik(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Silnik();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw(GLfloat rg = 10, GLfloat rd = 40, GLfloat h1 = 15, GLfloat h2 = 10);
};
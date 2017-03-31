#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Nozki
{
public:
	Nozki();
	Nozki(GLfloat wsp[3]);
	Nozki(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Nozki();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw(GLfloat h, GLfloat r, GLfloat dl , int kat);
};


#pragma once
#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Antena
{
public:
	Antena();
	Antena(GLfloat wsp[3]);
	Antena(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Antena();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw();
};


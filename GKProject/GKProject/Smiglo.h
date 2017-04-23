#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Smiglo
{
public:
	Smiglo();
	Smiglo(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Smiglo();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw();
};


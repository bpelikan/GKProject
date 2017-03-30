#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Sfera
{
public:
	Sfera();
	Sfera(GLfloat wsp[3]);
	Sfera(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Sfera();
	void Draw(GLfloat angleA, GLfloat angleB, GLfloat r, GLfloat scaleX=1.0f, GLfloat scaleY = 1.0f, GLfloat scaleZ = 1.0f, GLfloat dens = 15.0f);
private:
	GLfloat wspPoczatkowe[3];
};


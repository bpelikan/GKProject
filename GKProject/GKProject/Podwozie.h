#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL

class Podwozie
{
public:
	Podwozie();
	Podwozie(GLfloat wsp[3]);
	Podwozie(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Podwozie();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw();
};


#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Dron
{
public:
	Dron();
	Dron(GLfloat wsp[3]);
	Dron(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	~Dron();
private:
	GLfloat wspPoczatkowe[3];
public:
	void Draw();
	void ChangePosition(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z);
	void ChangeRotation(GLfloat rot_X, GLfloat rot_Y, GLfloat rot_Z);
};


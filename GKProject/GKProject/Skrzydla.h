#pragma once


#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>

class Skrzydla
{
public:
	Skrzydla();
	~Skrzydla();
	void Draw();
private:
	static GLfloat rotateValueInc;
	static GLfloat rotateValue;
public:
	void SetRotate(GLfloat temp=0);
};


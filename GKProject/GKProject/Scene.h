#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>
#include <gl\glu.h> 

#include "Coordinate.h"
#include "Dron.h"
#include "Bieznia.h"
#include "Lampa.h"
#include "Drzewo.h"
#include "Stadion.h"
#include <stdio.h>

class Scene
{
public:
	Scene();
	Scene(GLfloat wspX, GLfloat wspY, GLfloat wspZ, GLfloat tp, GLfloat rotX, GLfloat rotY);
	~Scene();
public:
	void RenderScene();
private:
	static GLfloat wsp_X;
	static GLfloat wsp_Y;
	static GLfloat wsp_Z;
	static GLfloat prop;
	static GLfloat temp;
	static GLfloat dronRotX;
	static GLfloat dronRotY;
};


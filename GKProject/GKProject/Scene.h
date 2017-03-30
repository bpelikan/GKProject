#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>
#include <gl\glu.h> 

#include "Szescian.h"
#include "Coordinate.h"
#include "Stozek.h"
#include "Walec.h"
#include "Sfera.h"

class Scene
{
public:
	Scene();
	~Scene();
	void RenderScene();
};


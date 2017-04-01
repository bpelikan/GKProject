#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>
#include <gl\glu.h> 

#include "Szescian.h"
#include "Coordinate.h"
#include "Silnik.h"
#include "Walec.h"
#include "Sfera.h"
#include "Smiglo.h"
#include "Nozki.h"

class Scene
{
public:
	Scene();
	~Scene();
	void RenderScene();
};


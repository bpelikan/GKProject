#pragma once
#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>
#include "Scene.h"
#include "tekstura.h"
#define _CRT_SECURE_NO_WARNINGS
class Stadion
{
public:
	Stadion();
	~Stadion();
	void Rysuj();
	float PI = 3.1415;
};


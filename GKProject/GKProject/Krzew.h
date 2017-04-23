#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include "Walec.h"
#include "Trapez.h"
class Krzew
{
public:
	Krzew();
	~Krzew();
	void Rysuj(int x,int y,int z);
	float PI = 3.1415;
};


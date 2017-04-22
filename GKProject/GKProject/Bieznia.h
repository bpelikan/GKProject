#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>
#include "lampa.h"
#include "Drzewo.h"
class Bieznia
{
public:
	Bieznia();
	~Bieznia();
	void Rysuj(int R, int r);
	float PI = 3.1415;
};


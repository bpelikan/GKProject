#pragma once

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include "Walec.h"
#include "Trapez.h"
class Drzewo
{
public:
	Drzewo();
	~Drzewo();
	void Rysuj(int x,int y,int z);
};


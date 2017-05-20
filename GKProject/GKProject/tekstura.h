#pragma once
#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL
#include <math.h>
#include <gl\glu.h> 
#include <stdio.h>
#define  _CRT_SECURE_NO_WARNINGS

class tekstura
{


public:
	tekstura();
	~tekstura();
	static unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);

};


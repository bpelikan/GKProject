#include "Trapez.h"



Trapez::Trapez()
{
}


Trapez::~Trapez()
{
}

void Trapez::Rysuj(int pods1, int pods2, int h)
{
	glBegin(GL_QUADS);
	glVertex3d(-pods1 / 2, 0, 0);
	glVertex3d(pods1 / 2, 0, 0);
	glVertex3d(pods2 / 2, 0,h );

	glVertex3d(-pods2 / 2, 0,h);
	glEnd();
}
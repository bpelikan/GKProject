#include "Cialo.h"

#include "Sfera.h"

Cialo::Cialo()
{
}


Cialo::~Cialo()
{
}


void Cialo::Draw()
{
	Sfera sfera;

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 1.0f);
	glTranslated(-50, 55, 55);
	sfera.Draw(360, 360, 66, 0.4f);	//(360,360,60,0.5f)
	glPopMatrix();
}

#include "Transformation.h"



Transformation::Transformation()
{
}


Transformation::~Transformation()
{
}


void Transformation::Rotate(GLfloat *wsp, float angle)
{
	GLfloat x = wsp[0] * cos(angle * 3.14 / 180.0f) - wsp[1] * sin(angle * 3.14 / 180.0f);
	GLfloat y = wsp[0] * sin(angle * 3.14 / 180.0f) + wsp[1] * cos(angle * 3.14 / 180.0f);
	wsp[0] = x;
	wsp[1] = y;
}

void Transformation::RotateX(GLfloat *wsp, float angle)
{
	GLfloat y = wsp[1] * cos(angle * 3.14 / 180.0f) - wsp[2] * sin(angle * 3.14 / 180.0f);
	GLfloat z = wsp[1] * sin(angle * 3.14 / 180.0f) + wsp[2] * cos(angle * 3.14 / 180.0f);
	wsp[1] = y;
	wsp[2] = z;
}

void Transformation::RotateY(GLfloat *wsp, float angle)
{
	GLfloat x = wsp[2] * sin(angle * 3.14 / 180.0f) + wsp[0] * cos(angle * 3.14 / 180.0f);
	GLfloat z = wsp[2] * cos(angle * 3.14 / 180.0f) - wsp[0] * sin(angle * 3.14 / 180.0f);
	wsp[0] = x;
	wsp[2] = z;
}

void Transformation::RotateZ(GLfloat *wsp, float angle)
{
	GLfloat x = wsp[0] * cos(angle * 3.14 / 180.0f) - wsp[1] * sin(angle * 3.14 / 180.0f);
	GLfloat y = wsp[0] * sin(angle * 3.14 / 180.0f) + wsp[1] * cos(angle * 3.14 / 180.0f);
	wsp[0] = x;
	wsp[1] = y;
}

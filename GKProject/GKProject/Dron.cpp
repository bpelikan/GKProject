#include "Dron.h"
#include "Smiglo.h"
#include "Silnik.h"
#include "Walec.h"
#include "Podwozie.h"
#include "Sfera.h"
#include "Cialo.h"
#include "Skrzydla.h"
#include "Antena.h"
#include "Coordinate.h"

Dron::Dron()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Dron::Dron(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Dron::Dron(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}


Dron::~Dron()
{
}


void Dron::Draw()
{
	Coordinate coordinate(true);
	coordinate.Draw();

	glRotated(-90, 0, 1, 0);
	glScalef(0.2, 0.2, 0.2);

	Antena antena;
	antena.Draw();
	
	glTranslated(25, -25, -25);	//do ustawienia œrodka przy obrocie dronem

	Podwozie podwozie;
	podwozie.Draw();

	Cialo cialo;
	cialo.Draw();

	Skrzydla skrzydla;
	skrzydla.Draw();
}

void Dron::ChangePosition(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	glTranslated(wsp_X, wsp_Y, wsp_Z);
}

void Dron::ChangeRotation(GLfloat rot_X, GLfloat rot_Y, GLfloat rot_Z)
{
	glRotated(rot_X, 1, 0, 0);
	glRotated(rot_Y, 0, 1, 0);
	glRotated(rot_Z, 0, 0, 1);
}

void Dron::SetRotate(GLfloat temp)
{
	Skrzydla skrzydla;
	skrzydla.SetRotate(temp);
}
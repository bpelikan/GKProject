#include "Antena.h"
#include "Walec.h"
#include "Silnik.h"

Antena::Antena()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Antena::Antena(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Antena::Antena(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}


Antena::~Antena()
{
}

void Antena::Draw()
{
	GLfloat wysokoscAnteny = 40;

	Walec podstawaAnteny;
	Stozek stozek;


	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glColor3f(0,0,0);
	//glTranslated(50, 25, 0);
	podstawaAnteny.Draw(0.4f, wysokoscAnteny);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);	
	glTranslated(0, 0, wysokoscAnteny);
	glScalef(0.6f, 0.6f, 0.6f);
	stozek.Draw(1, 2, 2, 1);

	glPopMatrix();

}

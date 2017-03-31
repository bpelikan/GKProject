#include "Nozki.h"
#include "Walec.h"
#include "WygietePoloczenie.h"
Nozki::Nozki()
{
	for(int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Nozki::Nozki(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Nozki::Nozki(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}


Nozki::~Nozki()
{
}


void Nozki::Draw(GLfloat h, GLfloat r, GLfloat dl)
{
	GLfloat PI = 3.1415;



	WygietePoloczenie wyg1;
	glColor3f(1.0f, 0.5f, 0.5f);
	wyg1.Draw(r);

	glPushMatrix();
	glColor3f(1.0f, 0.5f, 0.5f);
	WygietePoloczenie wyg2;
	glTranslated(-dl, 0, 0);
	glRotated(180, 0, 1, 0);
	wyg2.Draw(r);
	glPopMatrix();

	Walec walecPionowy;
	Walec walecPoziomy;
	Walec walecPionowy2;



	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glRotated(15, 1, 0, 0);

	glTranslated(r, 0, -1);
	walecPionowy.Draw(r, h);
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glRotated(15, 1, 0, 0);
	glTranslated(-r - dl, 0, -1);
	walecPionowy2.Draw(r, h);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 0, 1, 0);

	glTranslated(0 ,r, -1);
	walecPoziomy.Draw(r, dl+2);
	glPopMatrix();


}






	


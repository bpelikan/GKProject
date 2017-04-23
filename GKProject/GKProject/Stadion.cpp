#include "Stadion.h"



Stadion::Stadion()
{
}


Stadion::~Stadion()
{
}

void Stadion::Rysuj()
{
	glColor3ub(115,	84,	47);

	glBegin(GL_TRIANGLE_STRIP);
	for (float kat = 0.0; kat < 2 * PI; kat += PI / 20)
	{	
		glVertex3f(100 * sin(kat), 100 * cos(kat), 0);
		glVertex3f(170* sin(kat), 170 * cos(kat), 0);
	}
	glEnd();
	glColor3ub(138, 164, 183);



	glBegin(GL_TRIANGLE_STRIP);
	for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
	{
		glVertex3f(100 * sin(kat), 100 * cos(kat), 0);
		glVertex3f(100 * sin(kat), 100 * cos(kat), 20);
	}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
	{
		glVertex3f(170 * sin(kat), 170 * cos(kat), 0);
		glVertex3f(170 * sin(kat), 170 * cos(kat), 60);
	}
	glEnd();
	


	for (int i = 100,h=25; i < 170; i += 10,h+=5)
	{
		glColor3ub(138, 164, 183);
		glBegin(GL_TRIANGLE_STRIP);
		for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
		{
			glVertex3f(i * sin(kat), i * cos(kat), h);
			glVertex3f((i+10) * sin(kat), (i+10) * cos(kat), h);
		}
		glEnd();
		glColor3ub(192, 192, 192);

		glBegin(GL_TRIANGLE_STRIP);
		for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
		{
			glVertex3f( (i) * sin(kat), (i) * cos(kat), h);
			glVertex3f( (i) * sin(kat), (i) * cos(kat), h-5);
		}
		glEnd();
	}

}

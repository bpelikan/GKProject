#include "Drzewo.h"



Drzewo::Drzewo()
{
}


Drzewo::~Drzewo()
{
}

void Drzewo::Rysuj(int x ,int y, int z)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	float PI = 3.1415;
	glPushMatrix();
	glTranslated(x, y, z);
	Trapez trapez;
	glColor3ub(112, 56, 0);
	int h = 15;
	Walec walec;
	walec.Draw(1, h/5);
	glColor3ub(0, 96, 0);
	for (float i = h / 5; i < h; i += 4)
	{
	for (float kat = 0.0f; kat < 180; kat += 180/5)
		{
		glPushMatrix();
			glTranslated(0, 0, i);
			glRotatef(kat, 0, 0, 1);
			trapez.Rysuj(10, 7, 4);
			glPopMatrix();

		}
	}
	for (float kat = 0.0f; kat < 180; kat += 180 / 5)
	{
		glPushMatrix();
		glTranslated(0, 0, h);
		glRotatef(kat, 0, 0, 1);
		glBegin(GL_TRIANGLES);
		glVertex3f(-2.5, 0, 0);
		glVertex3f(2.5, 0, 0);
		glVertex3f(0, 0, 4);
		glEnd();
		glPopMatrix();
	}
	glPopMatrix();
}

#include "Bieznia.h"



Bieznia::Bieznia()
{
}


Bieznia::~Bieznia()
{
}
void Bieznia::Rysuj(int R , int r)
{
	Lampa lampa;
	Drzewo drzewo;
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75, 0.3, 0.05);
	for (float kat = 0.0; kat <= 2*PI; kat +=  PI /20)
	{
		glVertex3f(R * sin(kat), R * cos(kat), 0);
		glVertex3f(r * sin(kat), r * cos(kat), 0);
	}
	glEnd();


	for (float kat = 0.0; kat <= 2 * PI; kat += PI /2)
	{
		lampa.Rysuj(R*sin(kat), R*cos(kat), 0);
		lampa.Rysuj((r+2) * sin(kat), (r+2) * cos(kat), 0);
		drzewo.Rysuj((r / 2)*sin(kat), (r / 2)*cos(kat), 19);


	}
	glEnd();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0, 0.8, 0.2);
	float wysokosc = 0.0f;
	for (int i = r; i >0; i -=5)
	{
		for (float kat = 0.0; kat < 2 * PI; kat += PI / 20)
		{
			
			glVertex3f(i*sin(kat), i*cos(kat),wysokosc);
			glVertex3f((i-5)*sin(kat), (i-5)*cos(kat), wysokosc +log2(i/5)  );

		}
		wysokosc += log2(i/5);
	}glEnd();
}
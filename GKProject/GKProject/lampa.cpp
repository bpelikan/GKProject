#include "lampa.h"

#include "Walec.h"
#include "Sfera.h"



Lampa::Lampa()
{
}


Lampa::~Lampa()
{
}
void Lampa::Rysuj(int x , int y, int z)
{
	Walec PodstawaLampy;

	glPushMatrix();
	glTranslated(x, y, z);
	glColor3ub(150, 75, 50);
	PodstawaLampy.Draw(1,30);
	glColor3ub(255,204,51);
	glPushMatrix();
	glTranslated(0, 0, 30);
	Sfera sfera;
	sfera.Draw(360,360, 2, 1, 1, 1, 15);

	glPopMatrix();
	glPopMatrix();
}
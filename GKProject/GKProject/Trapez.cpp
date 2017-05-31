#include "Trapez.h"
#include "tekstura.h"


Trapez::Trapez()
{
}


Trapez::~Trapez()
{
}

void Trapez::Rysuj(int pods1, int pods2, int h)
{


	//glDisable(GL_TEXTURE_1D);
	//glEnable(GL_TEXTURE_2D);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);

	glVertex3d(-pods1 / 2, 0, 0);
	glTexCoord2f(1,0);

	glVertex3d(pods1 / 2, 0, 0);
	glTexCoord2f(1,1);

	glVertex3d(pods2 / 2, 0,h );
	glTexCoord2f(0, 1);


	glVertex3d(-pods2 / 2, 0,h);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
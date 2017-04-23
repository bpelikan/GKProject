#include "Krzew.h"



Krzew::Krzew()
{
}


Krzew::~Krzew()
{
}
void Krzew::Rysuj(int x,int y,int z)
{
	for (float kat = 0.0f; kat < 180; kat += 180 / 5)
	{
		glPushMatrix();
		glTranslated(x, y, z);

		glRotatef(kat, 0, 0, 1);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0, 0, 0);
		for (float kat2 = 0.5*PI; kat2 < 1.5*PI; kat2 += PI / 10)
		{
			glVertex3f(10 * sin(kat2), 0, 10 * cos(kat2));
		}
		glEnd();
		glPopMatrix();

	}
}


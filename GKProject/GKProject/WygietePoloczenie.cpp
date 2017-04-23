#include "WygietePoloczenie.h"

WygietePoloczenie::WygietePoloczenie()
{
}

WygietePoloczenie::~WygietePoloczenie()
{
}

void WygietePoloczenie::Draw(GLfloat r)
{
	GLfloat PI = 3.1415f;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	for (float kat = 0; kat <= 2 * PI; kat += PI / 40)
	{
		glBegin(GL_TRIANGLE_STRIP);

		for (float kat2 = 0; kat2 <= 0.5* PI; kat2 += PI / 20)
		{
			glVertex3f((r + r * cos(kat))*cos(kat2), (r + r* cos(kat))*sin(kat2), r* sin(kat));
			glVertex3f((r + r * cos(kat + PI / 20))*cos(kat2 + PI / 20), (r + r * cos(kat + PI / 20))*sin(kat2 + PI / 20), r * sin(kat + PI / 20));
		}
		glEnd();
	}
}


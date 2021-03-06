#include "Smiglo.h"

Smiglo::Smiglo()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Smiglo::Smiglo(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}

Smiglo::~Smiglo()
{
}

void Smiglo::Draw()
{
	float PI = 3.1415;
	int j = 30;
	glColor3b(73, 73, 73);
	for (int i = 0; i < 27; i = i + 10)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float kat = 0.7f; kat <= 2.4; kat = kat + PI / 10)
		{
			glVertex3f((j * sin(kat) / 4) + wspPoczatkowe[0], (j * cos(kat) / 4) + wspPoczatkowe[1], i + 10 + wspPoczatkowe[2]);
			glVertex3f(((j - 5) * sin(kat) / 4) + wspPoczatkowe[0], (j - 5) * cos(kat) / 4 + wspPoczatkowe[1], i + 20 + wspPoczatkowe[2]);
		}
		glEnd();
		j = j - 5;
	}
	j = 30;
	for (int i = 0; i < 27; i = i + 10)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float kat = 0.7f; kat <= 2.4; kat = kat + PI / 10)
		{
			glVertex3f((j * sin(kat) / 4) + wspPoczatkowe[0], (j * cos(kat) / 4) + wspPoczatkowe[1], -(i + 10) + wspPoczatkowe[2]);
			glVertex3f(((j - 5) * sin(kat) / 4) + wspPoczatkowe[0], (j - 5) * cos(kat) / 4 + wspPoczatkowe[1], -(i + 20) + wspPoczatkowe[2]);
		}
		glEnd();
		j = j - 5;
	}

	glColor3b(50, 50, 50);

	j = 30;
	for (int i = 0; i > -27 / 5; i = i - 4)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float kat = 0.7f; kat <= 2.4; kat = kat + PI / 10)
		{
			glVertex3f(j * sin(kat) / 4 + wspPoczatkowe[0], j * cos(kat) / 4 + wspPoczatkowe[1], i + 10 + wspPoczatkowe[2]);
			glVertex3f((j - 10) * sin(kat) / 4 + wspPoczatkowe[0], (j - 10) * cos(kat) / 4 + wspPoczatkowe[1], i + 6 + wspPoczatkowe[2]);
		}
		glEnd();
		j = j - 10;
	}

	j = 30;
	for (int i = 0; i > -27 / 5; i = i - 4)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float kat = 0.7f; kat <= 2.4; kat = kat + PI / 10)
		{
			glVertex3f(j * sin(kat) / 4 + wspPoczatkowe[0], j * cos(kat) / 4 + wspPoczatkowe[1], -(i + 10) + wspPoczatkowe[2]);
			glVertex3f((j - 10) * sin(kat) / 4 + wspPoczatkowe[0], (j - 10) * cos(kat) / 4 + wspPoczatkowe[1], -(i + 6) + wspPoczatkowe[2]);
		}
		glEnd();
		j = j - 10;
	}
}



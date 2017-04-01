#include "Silnik.h"

Silnik::Silnik()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Silnik::Silnik(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Silnik::Silnik(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}

Silnik::~Silnik()
{
}

void Silnik::Draw(GLfloat rg, GLfloat rd, GLfloat h1, GLfloat h2)
{
	//wype�nienie dziury w g�rnym sto�ku
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(wspPoczatkowe[0], wspPoczatkowe[1], wspPoczatkowe[2] + h1);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] + rg * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] + rg * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] + h1);
	}
	glEnd();

	//g�rny sto�ek
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] + rg * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] + rg * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] + h1);

		glVertex3f(wspPoczatkowe[0] + rd * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] + rd * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] + 0);
	}
	glEnd();

	//cz�� �rodkowa
	glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] - rd * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] - rd * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] - h2);

		glVertex3f(wspPoczatkowe[0] - rd * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] - rd * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] + 0);
	}
	glEnd();

	//dolny sto�ek
	glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] - rg * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] - rg * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] - h1 - h2);

		glVertex3f(wspPoczatkowe[0] - rd * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] - rd * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] - h2);
	}
	glEnd();

	//wype�nienie dziury w dolnym sto�ku
	glColor3f(1.0f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(wspPoczatkowe[0], wspPoczatkowe[1], wspPoczatkowe[2] - h1 - h2);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] + rg * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] + rg * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] - h1 - h2);
	}
	glEnd();
}

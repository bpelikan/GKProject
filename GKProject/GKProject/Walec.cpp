#include "Walec.h"


Walec::Walec()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Walec::Walec(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Walec::Walec(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}


Walec::~Walec()
{
}

void Walec::Draw(GLfloat r, GLfloat h)
{
	glColor3f(0.5f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] + r * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] + r * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2] + h);

		glVertex3f(wspPoczatkowe[0] + r * cos((i*3.14f) / 180.0f),
			wspPoczatkowe[1] + r * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2]);
	}
	glEnd();


	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3fv(wspPoczatkowe);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] + r * cos((i*3.14f) / 180.0f), 
			wspPoczatkowe[1] + r * sin((i*3.14f) / 180.0f), 
			wspPoczatkowe[2]);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(wspPoczatkowe[0], wspPoczatkowe[1], wspPoczatkowe[2] + h);
	for (float i = 0; i <= 360; i += 0.1f)
	{
		glVertex3f(wspPoczatkowe[0] + r * cos((i*3.14f) / 180.0f),
			wspPoczatkowe[1] + r * sin((i*3.14f) / 180.0f),
			wspPoczatkowe[2] + h);
	}
	glEnd();
}

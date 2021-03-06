#include "Sfera.h"

Sfera::Sfera()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Sfera::Sfera(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Sfera::Sfera(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}

Sfera::~Sfera()
{
}

void Sfera::Draw(GLfloat angleA, GLfloat angleB, GLfloat r, GLfloat scaleX, GLfloat scaleY, GLfloat scaleZ, GLfloat dens)
{
	GLfloat x1, y1, z1;

	//glColor3f(1.0f, 0.0f, 1.0f);
	glScalef(scaleX, scaleY, scaleZ);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	
	for (GLfloat i = 0; i < angleA; i += dens)
	{
		for (GLfloat j = 0; j < angleB; j += dens)
		{	
			//4 punkty tworz�ce kwadrat/prostok�t
			glVertex3f(r * cos(i*3.14f / 180.0f) * sin(j*3.14f / 180.0f),
				r * cos(j*3.14f / 180.0f),
				r * sin(i*3.14f / 180.0f) * sin(j*3.14f / 180.0f));

			glVertex3f(r * cos(i*3.14f / 180.0f) * sin((j + dens)*3.14f / 180.0f),
				r * cos((j + dens)*3.14f / 180.0f),
				r * sin(i*3.14f / 180.0f) * sin((j + dens)*3.14f / 180.0f));

			glVertex3f(r * cos((i + dens)*3.14f / 180.0f) * sin((j + dens)*3.14f / 180.0f),
				r * cos((j + dens)*3.14f / 180.0f),
				r * sin((i + dens)*3.14f / 180.0f) * sin((j + dens)*3.14f / 180.0f));

			glVertex3f(r * cos((i + dens)*3.14f / 180.0f) * sin(j*3.14f / 180.0f),
				r * cos(j*3.14f / 180.0f),
				r * sin((i + dens)*3.14f / 180.0f) * sin(j*3.14f / 180.0f));
		}
	}
	glEnd();
}

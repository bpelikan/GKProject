#include "Coordinate.h"

#include <windows.h>            // Window defines
#include <gl\gl.h>              // OpenGL

Coordinate::Coordinate(bool v)
	//: visible(false)
{
	visible = v;
}


Coordinate::~Coordinate()
{
}


void Coordinate::Draw()
{
	if (visible == true) {
		GLfloat sa[3] = { 0.0f,0.0f,0.0f };
		GLfloat sb[3] = { 20.0f,0.0f,0.0f };
		GLfloat sc[3] = { 0.0f,40.0f,0.0f };
		GLfloat sd[3] = { 0.0f,0.0f,80.0f };

		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glEnd();

		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex3fv(sa);
		glVertex3fv(sc);
		glEnd();

		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
		glVertex3fv(sa);
		glVertex3fv(sd);
		glEnd();
	}
}

#include "Skrzydla.h"
#include "Smiglo.h"
#include "Silnik.h"
#include "Walec.h"


Skrzydla::Skrzydla()
{
}


Skrzydla::~Skrzydla()
{
}

void Skrzydla::Draw()
{

	Smiglo smiglo;
	Silnik stozekPodSmiglem;
	Walec walecPodSmiglem;

	//1 skrzydlo
	glPushMatrix();
	glTranslated(-12, 0, 0);
	glRotated(-45, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();

	glPushMatrix();
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();


	//2 skrzydlo
	glPushMatrix();
	glTranslated(-12, 110, 0);
	glRotated(45, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 110, 0);
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();


	//3 skrzydlo
	glPushMatrix();
	glTranslated(-12, 110, 110);
	glRotated(135, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 110, 110);
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();


	//4 skrzydlo
	glPushMatrix();
	glTranslated(-12, 0, 110);
	glRotated(-135, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 110);
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();
}
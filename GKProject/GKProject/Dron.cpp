#include "Dron.h"

#include "Nozki.h"
#include "Smiglo.h"
#include "Silnik.h"
#include "Walec.h"
#include "Podwozie.h"
#include "Sfera.h"
#include "Cialo.h"

Dron::Dron()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Dron::Dron(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Dron::Dron(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}


Dron::~Dron()
{
}


void Dron::Draw()
{
	Podwozie podwozie;
	podwozie.Draw();

	Cialo cialo;
	cialo.Draw();


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


	//////////////////////////////////////
	///do usuniecia
	//Nozka nozka;

	////nó¿ki drona
	//glScaled(0.5, 0.5, 0.5);
	//glPushMatrix();
	//glRotated(90, 0, 0, 1);
	//glTranslated(75, 100, 0);
	//nozka.Draw(40, 3, 40, -15);   // parametry to wysokoœæ , promieñ i d³ugoœæ nó¿ek i kat ( gdy damy za du¿y k¹t to utracimy 
	//glPopMatrix();				// po³¹czenie pomiêdzy wygiêtym walcem a tym ale i tak powinnien on byæ ma³y

	//glPushMatrix();
	////Podwozie nozki2;
	//glRotated(90, 0, 0, 1);
	//glTranslated(75, 100, 110);
	//nozka.Draw(40, 3, 40, 15);
	//glPopMatrix();

	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	/*Smiglo smiglo2;
	Silnik stozekPodSmiglem2;
	Smiglo smiglo3;
	Silnik stozekPodSmiglem3;
	Smiglo smiglo4;
	Silnik stozekPodSmiglem4;*/

	/*Walec walecPodSmiglem2;
	Walec walecPodSmiglem3;
	Walec walecPodSmiglem4;*/

	/*glPushMatrix();		//niepotrzebne?
	smiglo.Draw();
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();*/
}

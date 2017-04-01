#include "Podwozie.h"

#include "Nozki.h"

Podwozie::Podwozie()
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = 0;
	}
}

Podwozie::Podwozie(GLfloat wsp[3])
{
	for (int i = 0; i < 3; i++) {
		wspPoczatkowe[i] = wsp[i];
	}
}

Podwozie::Podwozie(GLfloat wsp_X, GLfloat wsp_Y, GLfloat wsp_Z)
{
	wspPoczatkowe[0] = wsp_X;
	wspPoczatkowe[1] = wsp_Y;
	wspPoczatkowe[2] = wsp_Z;
}


Podwozie::~Podwozie()
{
}


void Podwozie::Draw()
{
	Nozka nozka;

	//nó¿ki drona
	glScaled(0.5, 0.5, 0.5);
	glPushMatrix();
	glRotated(90, 0, 0, 1);
	glTranslated(75, 100, 0);
	nozka.Draw(40, 3, 40, -15);   // parametry to wysokoœæ , promieñ i d³ugoœæ nó¿ek i kat ( gdy damy za du¿y k¹t to utracimy 
	glPopMatrix();				// po³¹czenie pomiêdzy wygiêtym walcem a tym ale i tak powinnien on byæ ma³y

	glPushMatrix();
	glRotated(90, 0, 0, 1);
	glTranslated(75, 100, 110);
	nozka.Draw(40, 3, 40, 15);
	glPopMatrix();
}

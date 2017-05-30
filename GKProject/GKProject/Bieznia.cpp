#include "Bieznia.h"


Bieznia::Bieznia()
{
}


Bieznia::~Bieznia()
{
}
void Bieznia::Rysuj(int R , int r)
{
	/*BITMAPINFOHEADER    bitmapInfoHeader;   // nag³ówek obrazu
	unsigned char*      bitmapData;         // dane tekstury
	unsigned int        texture[4];         // obiekt tekstury

	glGenTextures(2, &texture[1]);                  // tworzy obiekt tekstury

	tekstura Teksture;

	bitmapData = Teksture.LoadBitmapFile("trawa.bmp", &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// tworzy obraz tekstury
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

	if (bitmapData)
		free(bitmapData);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	*/

	
	Lampa lampa;
	Drzewo drzewo;
	Krzew krzew;
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75, 0.3, 0.05);


	for (float kat = 0.0; kat <= 2*PI; kat +=  PI /20)
	{
		glVertex3f(R * sin(kat), R * cos(kat), 0);
		glVertex3f(r * sin(kat), r * cos(kat), 0);
	}
	glEnd();


	for (float kat = 0.0; kat <= 2 * PI; kat += PI /2)
	{
		lampa.Rysuj(R*sin(kat), R*cos(kat), 0);
		lampa.Rysuj((r+2) * sin(kat), (r+2) * cos(kat), 0);
		glPushMatrix();

		glScaled(2, 2, 2);
		drzewo.Rysuj((r / 4)*sin(kat), (r / 4)*cos(kat), 10);
		glPopMatrix();


	}
	glEnd();

	for (float kat = 0.0; kat <= 2 * PI; kat += PI / 3)
	{
		glPushMatrix();
		glRotated(180, 1, 0, 0);
		krzew.Rysuj((r - 5)*sin(kat), (r - 5)*cos(kat), 0);
		glPopMatrix();

	}
	glEnd();


	glColor3f(0, 0.8, 0.2);
	float wysokosc = 0.0f;


//	glDisable(GL_TEXTURE_1D);
	//glEnable(GL_TEXTURE_2D);
	for (int i = r; i >0; i -=5)
	{
		int ii = 0;
		int jj = 0;
		glBegin(GL_TRIANGLE_STRIP);

		for (float kat = 0.0; kat < 2* PI; kat += PI / 20)
		{
			
		//	glTexCoord2f(ii, jj);

			glVertex3f(i*sin(kat), i*cos(kat), wysokosc);

		/*	jj++;
			if (jj == 2)
				jj = 0;

			glTexCoord2f(ii, jj);
*/
			glVertex3f((i - 5)*sin(kat), (i - 5)*cos(kat), wysokosc + log2(i / 5));

		/*	ii++;
			if (ii == 2)
				ii = 0;

		*/

		}
		wysokosc += log2(i/5);
	}glEnd();
	glDisable(GL_TEXTURE_2D);

}
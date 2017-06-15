#include "Bieznia.h"


Bieznia::Bieznia()
{
}


Bieznia::~Bieznia()
{
}

void Bieznia::Rysuj(int R , int r)
{
	BITMAPINFOHEADER    bitmapInfoHeader;   // nag³ówek obrazu
	unsigned char*      bitmapData;         // dane tekstury
	unsigned int        texture[5];         // obiekt tekstury

	glGenTextures(2, &texture[0]);                  // tworzy obiekt tekstury

	tekstura Teksture;

	bitmapData = Teksture.LoadBitmapFile("trawa.bmp", &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury
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




	glGenTextures(2, &texture[2]);                  // tworzy obiekt tekstury


	bitmapData = Teksture.LoadBitmapFile("bieznia3.bmp", &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, texture[2]);       // aktywuje obiekt tekstury
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




	glGenTextures(2, &texture[3]);                  // tworzy obiekt tekstury



	bitmapData = Teksture.LoadBitmapFile("drzewo.bmp", &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, texture[3]);       // aktywuje obiekt tekstury
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// tworzy obraz tekstury
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

	if (bitmapData)
		free(bitmapData);

	glBindTexture(GL_TEXTURE_2D, texture[2]);       // aktywuje obiekt tekstury

	Lampa lampa;
	Drzewo drzewo;
	Krzew krzew;

	
	glDisable(GL_TEXTURE_1D);
	glEnable(GL_TEXTURE_2D);

	int ii = 0;
	int jj = 0;
	glBegin(GL_TRIANGLE_STRIP);

	
		for(int zm =60 ; zm<100 ; zm+=10)
		for (float kat = 0.0; kat <= 2 * PI; kat += PI / 20)
		{

			glTexCoord2f(ii, jj);
			glVertex3f(zm*sin(kat), zm* cos(kat), 0);

			jj++;
			if (jj == 2)
				jj = 0;

			glTexCoord2f(ii, jj);
			glVertex3f((zm+10)* sin(kat), (zm + 10)* cos(kat), 0);

			ii++;
			if (ii == 2)
				ii = 0;	
		}
	glEnd();

	glDisable(GL_TEXTURE_2D);

	for (float kat = 0.0; kat <= 2 * PI; kat += PI /2)
	{
		lampa.Rysuj(R*sin(kat), R*cos(kat), 0);
		lampa.Rysuj((r+2) * sin(kat), (r+2) * cos(kat), 0);
		glPushMatrix();

		glScaled(2, 2, 2);

		glBindTexture(GL_TEXTURE_2D, texture[3]);       // aktywuje obiekt tekstury
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

	glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

	glColor3f(0, 0.8, 0.2);
	float wysokosc = 0.0f;
	glDisable(GL_TEXTURE_1D);
	glEnable(GL_TEXTURE_2D);
	for (int i = r; i >0; i -=5)
	{
		int ii = 0;
		int jj = 0;
		glBegin(GL_TRIANGLE_STRIP);

		for (float kat = 0.0; kat < 2* PI; kat += PI / 20)
		{
			
			glTexCoord2f(ii, jj);

			glVertex3f(i*sin(kat), i*cos(kat), wysokosc);

			jj++;
			if (jj == 2)
				jj = 0;

			glTexCoord2f(ii, jj);

			glVertex3f((i - 5)*sin(kat), (i - 5)*cos(kat), wysokosc + log2(i / 5));

			ii++;
			if (ii == 2)
				ii = 0;

		

		}
		wysokosc += log2(i/5);
	}glEnd();
	glDisable(GL_TEXTURE_2D);

}
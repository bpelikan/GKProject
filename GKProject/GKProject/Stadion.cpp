#include "Stadion.h"



Stadion::Stadion()
{
}


Stadion::~Stadion()
{
}

void Stadion::Rysuj()
{

	//BITMAPINFOHEADER    bitmapInfoHeader;   // nag³ówek obrazu
	//unsigned char*      bitmapData;         // dane tekstury
	//unsigned int        texture[4];         // obiekt tekstury

	//glGenTextures(2, &texture[0]);                  // tworzy obiekt tekstury

	//tekstura Teksture;

	//bitmapData = Teksture.LoadBitmapFile("tekst3.bmp", &bitmapInfoHeader);
	//glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//// tworzy obraz tekstury
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
	//	bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

	//if (bitmapData)
	//	free(bitmapData);

	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);


	////glGenTextures(2, &texture[1]);                  // tworzy obiekt tekstury
	////bitmapData = Teksture.LoadBitmapFile("tekst2", &bitmapInfoHeader);
	////glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury

	//glGenTextures(2, &texture[1]);                  // tworzy obiekt tekstury


	//bitmapData = Teksture.LoadBitmapFile("tekst4.bmp", &bitmapInfoHeader);
	//glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//// tworzy obraz tekstury
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
	//	bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

	//if (bitmapData)
	//	free(bitmapData);

	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);


	// tworzy obraz tekstury

	// ustalenie trybu teksturowania
	// w³¹czenie teksturowania

	glDisable(GL_TEXTURE_1D);
	glEnable(GL_TEXTURE_2D);


 



	


	

	glBegin(GL_TRIANGLE_STRIP);
	for (float kat = 0.0; kat < 2 * PI; kat += PI / 20)
	{	
		glVertex3f(100 * sin(kat), 100 * cos(kat), 0);
		
		glVertex3f(170* sin(kat), 170 * cos(kat), 0);
	
	}
	glEnd();
	glColor3ub(138, 164, 183);



	
	glBegin(GL_TRIANGLE_STRIP);
		int jj = 0;
		int ii = 0;
	for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
	{


	

		if (kat <1.9*PI)
		glTexCoord2f(ii, jj);
		glVertex3f(100 * sin(kat), 100 * cos(kat), 0);
		ii++;
		if (ii == 2)
			ii = 0;

		
		if (kat <1.9*PI)
		glTexCoord2f(jj,ii);
		glVertex3f(100 * sin(kat), 100 * cos(kat),20 );
		jj++;
		if (jj == 2)
			jj = 0;


	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
       // aktywuje obiekt tekstury
	jj = 0;
	 ii = 0;
	for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
	{


		if (kat <1.9*PI)
		glTexCoord2f(ii, jj);
		glVertex3f(170 * sin(kat), 170 * cos(kat), 0);

		jj++;
		if (jj == 2)
			jj = 0;
		if(kat <1.9*PI)
		glTexCoord2f(ii, jj);
		glVertex3f(170 * sin(kat), 170 * cos(kat), 55);
		ii++;
		if (ii == 2)
			ii = 0;
	}
	glEnd();

	
	//glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

	for (int i = 100,h=25; i < 170; i += 10,h+=5)
	{

		//glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

		int jj = 0;
		int ii = 0;
		glBegin(GL_TRIANGLE_STRIP);
	
		for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
		{
			

			glTexCoord2f(ii, jj);
			glVertex3f(i * sin(kat), i * cos(kat), h);
			jj++;
			if (jj == 2)
				jj = 0;
			
			glTexCoord2f(ii, jj);
			glVertex3f((i+10) * sin(kat), (i+10) * cos(kat), h);
			ii++;
			if (ii == 2)
				ii = 0;
		}
		glEnd();

		glColor3ub(192, 192, 192);
		//glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury
		glBegin(GL_TRIANGLE_STRIP);

		ii = 0;
		jj = 0;
	



		for (float kat = 0.0; kat < 1.9 * PI; kat += PI / 20)
		{
			glTexCoord2f(ii, jj);

			glVertex3f( (i) * sin(kat), (i) * cos(kat), h);

			jj++;
			if (jj == 2)
				jj = 0;
			glTexCoord2f(ii, jj);

			glVertex3f( (i) * sin(kat), (i) * cos(kat), h-5);

						ii++;
			if (ii == 2)
				ii = 0;
		}
		glEnd();
	}	

	glDisable(GL_TEXTURE_2D);
}		


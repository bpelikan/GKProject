#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::RenderScene()
{
	Coordinate coordinate(true);		
	coordinate.Draw();

	glScaled(0.5, 0.5, 0.5);
	glPushMatrix();
	Nozki nozki;
	glRotated(90, 0, 0, 1);
	glTranslated(75, 100, 0);
	nozki.Draw(40, 3, 40,-15);   // parametry to wysokoœæ , promieñ i d³ugoœæ nó¿ek i kat ( gdy damy za du¿y k¹t to utracimy 
	glPopMatrix();				// po³¹czenie pomiêdzy wygiêtym walcem a tym ale i tak powinnien on byæ ma³y

	glPushMatrix();
	Nozki nozki2;
	glRotated(90, 0, 0, 1);
	glTranslated(75, 100, 110);
	nozki.Draw(40, 3, 40, 15);
	glPopMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	Smiglo smiglo;
	Silnik stozekPodSmiglem;
	Smiglo smiglo2;
	Silnik stozekPodSmiglem2;
	Smiglo smiglo3;
	Silnik stozekPodSmiglem3;
	Smiglo smiglo4;
	Silnik stozekPodSmiglem4;

	Walec walecPodSmiglem;
	Walec walecPodSmiglem2;
	Walec walecPodSmiglem3;
	Walec walecPodSmiglem4;



	glPushMatrix();
	glTranslated(-12, 0, 0);
	glRotated(-45, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-12, 110, 0);
	glRotated(45, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-12, 110, 110);
	glRotated(135, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-12, 0, 110);
	glRotated(-135, 1, 0, 0);
	glRotated(-45, 0, 1, 0);
	walecPodSmiglem.Draw(5, 35);
	glPopMatrix();


	glPushMatrix();
	smiglo.Draw();
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();

	glPushMatrix();
	smiglo.Draw();
	glRotatef(90, 0, 1, 0);					
	stozekPodSmiglem.Draw(4, 6, 8, 8);
	glPopMatrix();


	

	glPushMatrix();
	glTranslated(0, 110, 0);
	smiglo2.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem2.Draw(4, 6, 8, 8);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0, 110, 110);
	smiglo2.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem2.Draw(4, 6, 8, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, 110);
	smiglo2.Draw();
	glRotatef(90, 0, 1, 0);
	stozekPodSmiglem2.Draw(4, 6, 8, 8);
	glPopMatrix();
}

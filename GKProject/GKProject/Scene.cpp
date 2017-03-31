#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}


void Scene::RenderScene()
{
	//Coordinate coordinate = new Coordinate(false); <- nie dzia³a, nie wiem dlaczego 2 razy siê wywo³uje konstruktor i 
									//za drugin razem przypisuje visible = true, nawet jak nie ma domyœlnego parametru
	Coordinate coordinate(true);		
	coordinate.Draw();

	/*Szescian szescian;
	szescian.Draw();*/

	//Stozek stozek;
	////stozek.Draw(10, 40, 15, 10);
	//stozek.Draw();

	/*Walec walec(10, 10, 5);
	walec.Draw(5, 10);*/


	/*GLfloat x, y, z;
	GLfloat r = 9;
	for (GLfloat i = 0; i < 180; i += 0.1f)
	{
		x = r*cos()	
	}*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	Smiglo smiglo;
	Stozek stozekPodSmiglem;

	Smiglo smiglo2;
	Stozek stozekPodSmiglem2;

	Smiglo smiglo3;
	Stozek stozekPodSmiglem3;

	Smiglo smiglo4;
	Stozek stozekPodSmiglem4;

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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	//Uzyskanie siatki
	//Sfera sfera(0, 0, 0);
	//glTranslatef(20, 30, 20);
	//sfera.Draw(180, 180, 40, 1.0f, 1.0f, 0.6f);
	//sfera.Draw(180, 180, -40, 1.0f, 1.0f, 0.6f);
	//sfera.Draw(360, 360, 40, 1.0f, 1.0f, 0.4f);
}

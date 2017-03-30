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

	Sfera sfera(0, 0, 0);
	//glTranslatef(20, 30, 20);
	sfera.Draw(180, 180, 40, 1.0f, 1.0f, 0.6f);
	sfera.Draw(180, 180, -40, 1.0f, 1.0f, 0.6f);
	
}

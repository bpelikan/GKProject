#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}


void Scene::RenderScene()
{
	//Coordinate coordinate = new Coordinate(false); <- nie dzia�a, nie wiem dlaczego 2 razy si� wywo�uje konstruktor i 
									//za drugin razem przypisuje visible = true, nawet jak nie ma domy�lnego parametru
	Coordinate coordinate(true);		
	coordinate.Draw();

	/*Szescian szescian;
	szescian.Draw();*/

	//Stozek stozek;
	////stozek.Draw(10, 40, 15, 10);
	//stozek.Draw();

	Walec walec(10, 10, 5);
	walec.Draw(5, 10);

	
	
}

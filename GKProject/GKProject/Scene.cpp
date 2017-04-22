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

	Dron dron;


	Bieznia bieznia;
	bieznia.Rysuj(100,60);

	dron.Draw();


}

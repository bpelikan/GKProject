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
	dron.Draw();
}

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
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glScalef(0.6, 0.6, 0.6);
	Dron dron;
	Stadion stadion;
	Bieznia bieznia;

	stadion.Rysuj();
	bieznia.Rysuj(100,60);
	dron.Draw();


}

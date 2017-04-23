#include "Scene.h"

GLfloat Scene::wsp_X = 10;
GLfloat Scene::wsp_Y = 0;
GLfloat Scene::wsp_Z = 0;
GLfloat Scene::prop = 0.3f;
GLfloat Scene::temp = 40;

Scene::Scene()
{
}

Scene::Scene(GLfloat wspX, GLfloat wspY, GLfloat wspZ, GLfloat tp)
{
	wsp_X = wspX;
	wsp_Y = wspY;
	wsp_Z = wspZ;
	temp = tp;
}

Scene::~Scene()
{
}

void Scene::RenderScene()
{
	gluLookAt(4 + wsp_X*prop, 4 + wsp_Y*prop, 4 + wsp_Z*prop,
		wsp_X*prop, wsp_Y*prop, wsp_Z*prop,
		0, 0, 1);

	Coordinate coordinate(true);		
	coordinate.Draw();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	

	glPushMatrix();
	glScaled(prop, prop, prop);
	glTranslated(wsp_X, wsp_Y, wsp_Z);
	Dron dron;
	dron.Draw();
	glPopMatrix();

	
	Stadion stadion;
	stadion.Rysuj();

	Bieznia bieznia;
	bieznia.Rysuj(100, 60);


}

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

	GLfloat sa[3] = { 0.0f,0.0f,0.0f };
	GLfloat sb[3] = { 10.0f,0.0f,0.0f };
	GLfloat sc[3] = { 10.0f,10.0f,0.0f };
	GLfloat sd[3] = { 0.0f,10.0f,0.0f };

	float angle = 10;
	Transformation::RotateZ(sa, angle);
	Transformation::RotateZ(sb, angle);
	Transformation::RotateZ(sc, angle);
	Transformation::RotateZ(sd, angle);

	// Sciany skladowe
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(sa);
	glVertex3fv(sb);
	glVertex3fv(sc);
	glVertex3fv(sd);

	glEnd();
	
}

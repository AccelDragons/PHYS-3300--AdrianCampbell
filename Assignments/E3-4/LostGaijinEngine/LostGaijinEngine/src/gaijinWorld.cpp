
#include "gaijinWorld.h"

//se crea la variable de gravedad cuya fuerza sera definida en el main.
void gWorld::setGravity(const vec2D& g)
{
	gravity = g;
}

//se crea la funcion que permite que se agregue un cuerpo al world.
void gWorld::addBody(gBody* b)
{
	bodies.push_back(b);
}

//Creamos la funcion step que hace que la simulacion corra cuando encuentre un cuerpo en el world.
void gWorld::Step(float dt)
{
	//Usando el metodo de Euler permite que el cuerpo actue conforme a la gravedad ajustada en el main.
	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->velocity.x += (gravity.x + bodies[counter]->force.x * bodies[counter]->invMass) * dt;
		bodies[counter]->velocity.y += (gravity.y + bodies[counter]->force.y * bodies[counter]->invMass) * dt;
	}

	//Hace lo mismo de arriba, utilizando el metodo de Euler, pero revisando con posicion y velocidad del cuerpo.
	//Tambien ajusta la fuerza en cero.
	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->position.x += bodies[counter]->velocity.x * dt;
		bodies[counter]->position.y += bodies[counter]->velocity.y * dt;

		bodies[counter]->force.setZero();
	}
}
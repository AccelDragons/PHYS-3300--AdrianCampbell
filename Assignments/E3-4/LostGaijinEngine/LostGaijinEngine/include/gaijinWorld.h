#ifndef GAIJINWORLD_H
#define GAIJINWORLD_H

#include "gaijinBody.h"
#include <vector>

struct gWorld
{
	// Definimos el constructor de la clase. 
	gWorld() {}
	gWorld(vec2D gravity) : gravity(gravity) {}

	// Declaramos la variable gravedad del world. 
	vec2D gravity;

	// Declaramos un vector que contenga todos los cuerpos en este world. 
	std::vector<gBody*> bodies;

	// Creamos una función para establecer la gravedad del world. 
	void setGravity(const vec2D& g);

	// Creamos una función para agregar un cuerpo a este world. 
	void addBody(gBody* b);

	// Creamos la función Step. Esta es la encargada de la simulación.
	void Step(float dt); //El dt suele ser el tiempo que toma pasar de un frame al otro. 

};

#endif
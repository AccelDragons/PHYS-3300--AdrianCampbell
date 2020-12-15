#include "gaijinWorld.h"

int main()
{
	//FirstSimulation Primero simula que el mundo tiene la gravedad de la tierra
	gWorld firstSimulation(vec2D(0.0f, 9.81f));
	//Esto es la declaracion de el mapa y el personaje en la simulacion.
	gBody firstBody;
	gBody secondBody;
	//Esta es la declaracion en que parte del mapa se ubicara y la velocidad que se movera el personaje de la simulacion.
	secondBody.position = vec2D(5.0f, 10.0f);
	secondBody.velocity = vec2D(7.5f, 3.8f);

	//Se agrega el cuerpo y el personaje en la simulacion.
	firstSimulation.addBody(&firstBody);
	firstSimulation.addBody(&secondBody);

	float frameTime = 0.5f; // Esto normalmente se mide con SDL.
	int counter = 0; //variable que empieza el while siguiente desde cero.

	//Repite diez veces por segundo la informacion de la masa, posicion y velocidad.
	while (counter < 10) {
		firstBody.displayBodyInfo();
		secondBody.displayBodyInfo();
		firstSimulation.Step(frameTime);
		counter++;
	}

	return 0;
}
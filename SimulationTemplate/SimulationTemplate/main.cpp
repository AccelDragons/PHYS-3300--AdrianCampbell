
/*
Este es la plantilla que usaremos para todos los proyectos de simulaciones f�sicas.
Esta es una plantilla com�n para crear juegos simples en C++ usando SDL.
Este template actualizado tiene la l�gica del poolEvent, teclado.
*/

/*
	PARA ASEGURARSE DE QUE EL TEMPLATE EST� FUNCIONANDO, AL CORRER ESTO EN UN PROYECTO LE DEBE MOSTRAR UNA VENTANA
	CON EL ROBOT EN MEDIO Y EL FONDO ESPACIAL.
*/

#include "Simulation.h"

int main(int argc, char* args[])
{
	const float FPS = 60;
	const float frameDelay = 1000 / FPS;

	Uint32 frameStart;
	Uint32 frameEnd;
	float frameTime;

	Simulation* simulation = nullptr;
	simulation = new Simulation();

	// Puedes cambiar el t�tulo y las dimensiones de la pantalla.
	simulation->init("LostGaijin Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	/*
		Este es el ciclo donde todo ocurre. Esto es lo que llamamos un "frame".
	*/
	while (simulation->running()) {

		// Medimos los ticks (tiempo) al inicio del frame.
		frameStart = SDL_GetTicks();

		/*
			Leemos entradas por teclado, modificamos la posici�n de los objetos si es necesario
			y dibujamos cada objeto en su nueva posici�n.
		*/
		simulation->handleEvents();
		simulation->update();
		simulation->render();

		// Medios los ticks (tiempo) al finalizar la simulaci�n. 
		frameEnd = SDL_GetTicks();

		/*
			Calculamos el tiempo que dura el frame haciendo Tiempo final - Tiempo inicial.
			Este tiempo lo usamos para hacer los c�lculos en el engine.
		*/
		frameTime = frameEnd - frameStart;

		// Esto nos limita el FPS al n�mero que hayamos definido anteriormente.
		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	simulation->clean();

	return 0;
}
#include "gaijinWorld.h"

int main()
{
	// Creamos un cuerpo llamado magicalBox
	gBody magicalBox;
	magicalBox.displayBodyInfo();

	// Si el usuario desea, puede cambiar las propiedades DEFAULT del cuerpo.
	magicalBox.setMass(0.5f);
	magicalBox.position.Set(1.5f, -3.1f);
	magicalBox.velocity.Set(-0.5f, -0.7f);
	magicalBox.displayBodyInfo();

	// Creamos otro cuerpo.
	gBody magicalPlatform;

	// Creamos un world. 
	gWorld mainWorld(vec2D(0.0f, 9.81f));
	mainWorld.addBody(&magicalBox);
	mainWorld.addBody(&magicalPlatform);

	// Creamos otro world. 
	gWorld secondaryWorld;
	secondaryWorld.gravity = vec2D(0.0f, 9.81f); // Esta es más directa que la de abajo.
	secondaryWorld.setGravity(vec2D(0.0f, 9.81f));


	return 0;
}
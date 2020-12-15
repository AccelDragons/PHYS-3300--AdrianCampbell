#include "gaijinBody.h"

//Declaracion de funcion para agregar el cuerpo a la simulacion.
//Le da al cuerpo valores temporales de posicion, velocidad, fuerza y masa.
gBody::gBody()
{
	position.setZero();

	velocity.setZero();

	force.setZero();

	mass = 1.0f;
	invMass = 1.0f; //1/mass
}

//Declaracion de la funcion que la da valores definitivos de masa a los cuerpos que se agregaran a la simulacion.
void gBody::setMass(const float& m)
{
	mass = m;
	invMass = 1 / m;
}

//Declaracion de funcion que corre en el main.
//Escribe le formate para demostrar las especificaciones del objeto que se agrega a la simulacion.
void gBody::displayBodyInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "Inv mass: " << invMass << std::endl;
	std::cout << "pos: ", position.displayVector();
	std::cout << "vel: ", velocity.displayVector();
	std::cout << "\n" << std::endl;
}

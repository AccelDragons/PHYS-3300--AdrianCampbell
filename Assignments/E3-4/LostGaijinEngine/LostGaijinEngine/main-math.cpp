#include "gaijinMath.h"

int main()
{
	// Vectores de prueba.
	vec2D a1(1.0f, 1.0f);
	vec2D a2(-1.0f, -5.0f);

	// Trabajamos primero con v1.
	vec2D v1(1.5f, -3.2f);
	v1.displayVector();

	v1 += a1;
	v1.displayVector();

	v1 -= a1;
	v1.displayVector();

	v1 *= 5;
	v1.displayVector();

	// Imprimo un espacio. 
	std::cout << "\n" << std::endl;

	// Trabajamos con v2.
	vec2D v2;
	v2 = a1 + a2;
	v2.displayVector();

	v2 = a2 - a1;
	v2.displayVector();

	v2 = a1 - a2;
	v2.displayVector();

	v2 = 5 * a1;
	v2.displayVector();

	// Imprimo un espacio. 
	std::cout << "\n" << std::endl;

	// Trabajamos con v3.
	vec2D v3(-5.0f, 4.7f);
	v3.displayVector();

	v3.x = -7.0f;
	v3.y = 4.0f;
	v3.displayVector();

	v3.Set(-7.0f, 4.0f);
	v3.displayVector();

	v3.Set(-10.0f, 8.551f);
	v3.displayVector();

	v3.setZero();
	v3.displayVector();

	return 0;
}
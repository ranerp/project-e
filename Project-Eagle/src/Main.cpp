#include "Renderer.h"
#include <SFML/Window.hpp>

int main( void )
{
	Renderer renderer;
	bool init;

	init = renderer.initialize();

	if(init == true)
	{
		renderer.run();
	}

	return EXIT_SUCCESS;
}
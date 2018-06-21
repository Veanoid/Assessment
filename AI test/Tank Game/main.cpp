#include "Tank_GameApp.h"

int main() {
	
	// allocation
	auto app = new Tank_GameApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}
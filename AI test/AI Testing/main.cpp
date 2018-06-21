#include "AI_TestingApp.h"

int main() {
	
	// allocation
	auto app = new AI_TestingApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}
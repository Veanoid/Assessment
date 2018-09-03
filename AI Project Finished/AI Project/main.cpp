#include "AI_ProjectApp.h"

int main() {
	
	// allocation
	auto app = new AI_ProjectApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}
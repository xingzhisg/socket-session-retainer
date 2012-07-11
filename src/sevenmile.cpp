//============================================================================
// Name        : sevenmile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <application.hpp>

int main(int argc, char * argv[]) {
	std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!

	miu::application app(argc, argv);
	app.run();

	return 0;
}

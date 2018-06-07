#include "unittest.h"
#include <iostream>

int main() {

	Matrix2 m1(1, 0, 0, 1);
	m1.setRotate(3.1415f * 0.5f);
	Matrix2 m2(1, 0, 0, 1);


	Matrix2 result = m1 * m2;

	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;

	return 0;
}
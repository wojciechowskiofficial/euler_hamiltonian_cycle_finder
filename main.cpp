#include <iostream>

#include "Utility.h"
#include "Generator.h"

int main() {
	Generator * test = new Generator(10, 0.3);
	delete test;
	std::cout << test->v_nr << std::endl;
	return 0;
}

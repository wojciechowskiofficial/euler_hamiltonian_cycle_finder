#include <iostream>

#include "Utility.h"
#include "Generator.h"
#include "Eulerian_cycle.h"
#include "Handle.h"

int main() {
	Generator * test = new Generator(10, 0.9);
	test->euler_generate();
	delete test;
	return 0;
}

#include "Handle.h"
#include "Eulerian_cycle.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

void Handle::euler_handle() {
	std::fstream output;
	output.open("euler.txt", std::ios::out);
	Eulerian_cycle * euler;
	int v = 1000;
	output << "0.2" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.2);
		output << euler->perform() << std::endl;
		v += 1000;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;

	v = 1000;
	output << "0.3" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.3);
		output << euler->perform() << std::endl;
		v += 1000;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	std::cout << "0.3" << std::endl;

	v = 1000;
	output << "0.4" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.4);
		output << euler->perform() << std::endl;
		v += 1000;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;


	v = 1000;
	output << "0.6" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.6);
		output << euler->perform() << std::endl;
		v += 1000;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;

	v = 1000;
	output << "0.8" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.8);
		output << euler->perform() << std::endl;
		v += 1000;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	std::cout << "0.8" << std::endl;

	v = 1000;
	output << "0.95" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.95);
		output << euler->perform() << std::endl;
		v += 1000;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	output.close();
}

#include "Handle.h"
#include "Eulerian_cycle.h"
#include "Hamiltonian_cycle.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

void Handle::euler_handle() {
	std::fstream output;
	output.open("nowy.txt", std::ios::out);
	Eulerian_cycle * euler;
	int v = 100;
	output << "0.2" << std::endl;
	std::cout << "0.2" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.2);
		euler->load();
		output << euler->perform() << std::endl;
		v += 100;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;

	v = 100;
	output << "0.3" << std::endl;
	std::cout << "0.3" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.3);
		euler->load();
		output << euler->perform() << std::endl;
		v += 100;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	std::cout << "0.3" << std::endl;

	v = 100;
	output << "0.4" << std::endl;
	std::cout << "0.4" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.4);
		euler->load();
		output << euler->perform() << std::endl;
		v += 100;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;

	v = 100;
	output << "0.6" << std::endl;
	std::cout << "0.6" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.6);
		euler->load();
		output << euler->perform() << std::endl;
		v += 100;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	v = 100;
	output << "0.8" << std::endl;
	std::cout << "0.8" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.8);
		euler->load();
		output << euler->perform() << std::endl;
		v += 100;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	
 	v = 100;
	output << "0.95" << std::endl;
	std::cout << "0.9" << std::endl;
	for (int i = 0; i < 10; i++) {
		euler = new Eulerian_cycle(v, 0.95);
		euler->load();
		output << euler->perform() << std::endl;
		v += 100;
		delete euler;
		euler = NULL;
	}
	delete euler;
	euler = NULL;
	output << "#" << std::endl;
	output.close();
}

void Handle::hamilton_handle() {
	std::fstream output;
	output.open("hamilton.txt", std::ios::out);
	double acc = 0.0;
	double tmp_measuring;
	int v = 100;
	output << "0.2" << std::endl;
	std::cout << "0.2" << std::endl;
	Hamiltonian_cycle * hamilton;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			hamilton = new Hamiltonian_cycle(v, 0.2);
			hamilton->load();
			tmp_measuring = hamilton->perform();
			std::cout << v << " " << tmp_measuring << std::endl;
			acc += tmp_measuring;
			delete hamilton;
			hamilton = NULL;
		}
		acc /= 10;
		output << v << " " << acc << std::endl;
		std::cout << "srednia " << v << " " << acc << std::endl;
		acc = 0.0;
		v += 100;
	}
	output.close();
}

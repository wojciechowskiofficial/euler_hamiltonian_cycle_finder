#include "Eulerian_cycle.h"
#include <cstdlib>
#include <iostream>
#include "Generator.h"

Eulerian_cycle::Eulerian_cycle(int v_nr, float saturation) {
	this->v_nr = v_nr;
	this->saturation = saturation;
	this->graph = new int * [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		this->graph[i] = new int [this->v_nr];
		for (int j = 0; j < this->v_nr; j++) {
			this->graph[i][j] = 0;
		}
	}
}

Eulerian_cycle::~Eulerian_cycle() {
	if (this->graph != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			delete [] this->graph[i];
			this->graph[i] = NULL;
		}
		delete [] this->graph;
		this->graph = NULL;
	}
}

bool Eulerian_cycle::add(int a, int b) {
	if (a < 0 || b < 0 || a > this->v_nr || b > this->v_nr) {
		return false;
	}
	else {
		this->graph[a][b] = 1;
		this->graph[b][a] = 1;
	}
}

bool Eulerian_cycle::is_edge(int a, int b) {
	if (this->graph[a][b] == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Eulerian_cycle::display() {
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			std::cout << this->graph[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Eulerian_cycle::load() {
	Generator * gen = new Generator(this->v_nr, this->saturation);
	bool tmp_bool;
	tmp_bool = gen->euler_generate();
	while (!tmp_bool) {
		gen->euler_generate();
	}
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			if (gen->is_edge(i, j)) {
				this->add(i, j);
			}
		}
	}
	this->e_nr = gen->e_nr;
	gen->display();
	std::cout << std::endl;
	this->display();
	delete gen;
	gen = NULL;
}

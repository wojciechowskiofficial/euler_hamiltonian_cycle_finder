#include "Hamiltonian_cycle.h"
#include "Generator.h"
#include <list>
#include <iostream>
#include <ctime>

Hamiltonian_cycle::Hamiltonian_cycle(int v_nr, float saturation) {
	this->v_nr = v_nr;
	this->saturation = saturation;
	this->out = new std::list<int> [this->v_nr];
	this->possible = new bool [this->v_nr + 1];
	this->output_arr = new int [this->v_nr + 2];
	for (int i = 0; i < this->v_nr + 1; i++) {
		this->possible[i] = true;
	}
	this->stop = false;
}

Hamiltonian_cycle::~Hamiltonian_cycle() {
	if (this->out != NULL) {
		delete [] this->out;
		this->out = NULL;
	}
	if (this->possible != NULL) {
		delete [] this->possible;
		this->possible = NULL;
	}
	if (this->output_arr != NULL) {
		delete [] this->output_arr;
		this->output_arr = NULL;
	}
	this->begin = 0;
	this->end = 0;
	this->stop = false;
}

void Hamiltonian_cycle::display() {
	for (int i = 0; i < this->v_nr; i++) {
		for (std::list<int>::iterator it = this->out[i].begin(); it != this->out[i].end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

bool Hamiltonian_cycle::load() {
	Generator * gen = new Generator(this->v_nr, this->saturation);
	bool tmp_bool = gen->hamilton_generate();
	while (!tmp_bool) {
		delete gen;
		gen = NULL;
		gen = new Generator(this->v_nr, this->saturation);
		tmp_bool = gen->hamilton_generate();
	}
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			if (gen->graph[i][j] == 1) {
				this->out[i].push_back(j);
			}
		}
	}
	delete gen;
	gen = NULL;
	for (int i = 0; i < this->v_nr; i++) {
		if (this->out[i].size() == 0) {
			return false;
		}
	}
	return true;
}

bool Hamiltonian_cycle::perform_util(int k) {
	for (std::list<int>::iterator i = this->out[this->output_arr[k - 1]].begin();!this->stop && i != this->out[this->output_arr[k - 1]].end(); ++i) {
		this->end = clock();
		if ((double (this->end - this->begin) / CLOCKS_PER_SEC) >= 300.0) {
			this->stop = true;
			return false;
		}
		int y = *i;
		if (k == this->v_nr + 1 && y == this->v0 && !this->stop) {
			this->output_arr[k] = this->v0;
			this->stop = true;
			return true;
		}
		else if (this->possible[y] && !this->stop) {
			this->output_arr[k] = y;
			this->possible[y] = false;
			this->perform_util(k + 1);
			this->possible[y] = true;
		}
	}
}

double Hamiltonian_cycle::perform() {
	this->begin = clock();
	this->v0 = 1;
	this->output_arr[1] = this->v0;
	this->possible[this->v0] = false;
	this->perform_util(2);
	this->end = clock();
	return double (this->end - this->begin) / CLOCKS_PER_SEC;
}

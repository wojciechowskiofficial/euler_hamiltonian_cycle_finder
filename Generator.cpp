#include "Generator.h"

#include <iostream>
#include <math.h>

Generator::Generator(int v_nr, float saturation) {
	this->v_nr = v_nr;
	this->e_nr = round(saturation * this->v_nr * (this->v_nr - 1) / 2);
	this->graph = new int * [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		this->graph[i] = new int [this->v_nr];
		for (int j = 0; j < this->v_nr; j++) {
			this->graph[i][j] = 0;
		}
	}
}

Generator::~Generator() {
	if (this->graph != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			delete [] this->graph[i];
			this->graph[i] = NULL;
		}
		delete [] this->graph;
		this->graph = NULL;
	}
}

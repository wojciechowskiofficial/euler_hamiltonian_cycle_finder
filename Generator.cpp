#include "Generator.h"

#include <iostream>
#include <math.h>
#include <stack>

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

//todo: robimy posortowana liste wszystkich indeksow wierzcholkow
        //shufflujemy O(n) te liste
        //robimy z niej stos w sumie
        //popujemy 1 element i dodajemy go do listy zrobionych
        //dopoki pierwsza lista jest nie pusta robimy:
        //pop
        //bierzemy radnom indeks z listy zrobionych i laczymy z popem
        //zwiekszamy pointer o jeden na zrobionych i spopowany vertex

void Generator::euler_generate() {
	int * unvisited = new int [this->v_nr];
	
}

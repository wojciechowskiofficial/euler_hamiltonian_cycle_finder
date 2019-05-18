#include "Generator.h"
#include "Utility.h"

#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

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

bool Generator::add(int a, int b) {
	if (a < 0 || b < 0 || a > this->v_nr || b > this->v_nr) {
		return false;
	}
	else {
		this->graph[a][b] = 1;
		this->graph[b][a] = 1;
	}
}

//TODO: robimy posortowana liste wszystkich indeksow wierzcholkow
        //shufflujemy O(n) te liste
        //robimy z niej stos w sumie
        //popujemy 1 element i dodajemy go do listy zrobionych
        //dopoki pierwsza lista jest nie pusta robimy:
        //pop
        //bierzemy radnom indeks z listy zrobionych i laczymy z popem
        //zwiekszamy pointer o jeden na zrobionych i spopowany vertex

void Generator::euler_generate() {
	int * unvisited = new int [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		unvisited[i] = i;
	}
	Utility * utility = new Utility();
	utility->shuffle(unvisited, this->v_nr);
	std::stack<int> stack;
	for (int i = this->v_nr - 1; i >= 0; i--) {
		stack.push(unvisited[i]);
	}
	delete [] unvisited;
	unvisited = NULL;
	std::vector<int> vector;
	vector.push_back(stack.top());
	stack.pop();
	vector.push_back(stack.top());
	stack.pop();
	this->add(vector.at(0), vector.at(1));
	srand(time(NULL));
	while (stack.size() > 0) {
		//TODO: moze trzeba dodac jakas tablice degree do vertecies
		this->add(stack.top(), vector.at(rand() % vector.size()));
		vector.push_back(stack.top());
		stack.pop();
	}
}

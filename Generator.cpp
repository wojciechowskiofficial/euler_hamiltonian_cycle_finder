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

void Generator::euler_generate() {
	int * unvisited = new int [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		unvisited[i] = i;
	}
	Utility * utility = new Utility();
	utility->shuffle(unvisited, this->v_nr);
	delete utility;
	utility = NULL;
	std::stack<int> unvisited_stack;
	for (int i = this->v_nr - 1; i >= 0; i--) {
		unvisited_stack.push(unvisited[i]);
	}
	delete [] unvisited;
	unvisited = NULL;
	
	int parity_pointer = 1;
	this->parity = new int * [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		this->parity[i] = new int [2];
		this->parity[i][0] = i;
		this->parity[i][1] = 0;
	}
	this->parity[0][0] = unvisited_stack.top();
	unvisited_stack.pop();
	this->parity[1][0] = unvisited_stack.top();
	unvisited_stack.pop();
	this->add(this->parity[0][0], this->parity[1][0]);
	this->parity[0][1]++;
	this->parity[1][1]++;
	srand(time(NULL));
	int rand_tmp;
	while (unvisited_stack.size() > 0) {
		rand_tmp = rand() % parity_pointer + 1;
		this->add(unvisited_stack.top(), this->parity[rand_tmp][0]);
		this->parity[rand_tmp][1]++;
		parity_pointer++;
		this->parity[parity_pointer][0] = unvisited_stack.top();
		this->parity[parity_pointer][1]++;
		unvisited_stack.pop();
	}
	//TODO:
	//*robimy vector dwuelementowych tablic:
	//	elementy vectora reprezentuja wierzcholki
	//	2D to tablica dwuelementowa
	//		t[0] indeks nieparzystosci
	//		t[1] to ilosc sasiadow
	//*@obliczamy ile jeszcze mamy doddac edgow ze wzoru this->e_nr - (this->v_nr) + 1
	//*dodajemy tyle edgow laczac 2 randomowe, rozne, nieparzyste wierzcholki majace wiecej niz 1 sasiadow
	//*zwiekszamy licznik sasiadow na tych wierzcholkach o jeden
	//*jezeli vector nieparzystych wierzcholkow jest <= 2 to konczymy
	//*jezeli nie to wykonujemy procedure "usun" i powtarzamy kroki od @
	
}

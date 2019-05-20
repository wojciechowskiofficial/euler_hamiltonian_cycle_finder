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
	if (this->parity != NULL) {
		for (int i = 0; i < this->v_nr; i++) {
			delete this->parity[i];
			this->parity[i] = NULL;
		}
		delete [] this->parity;
		this->parity = NULL;
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
	this->parity = new int * [this->v_nr];
	for (int i = 0; i < this->v_nr; i++) {
		unvisited[i] = i;
		this->parity[i] = new int [2];
		this->parity[i][0] = 0;
		this->parity[i][1] = i;
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
		this->add(stack.top(), vector.at(rand() % vector.size()));
		vector.push_back(stack.top());
		stack.pop();
	}

	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			std::cout << this->graph[i][j] << " ";
			if (this->graph[i][j] == 1) {
				parity[i][0]++;
			}
		}
		std::cout << parity[i][0] << std::endl;
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

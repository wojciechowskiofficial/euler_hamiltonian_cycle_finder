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
	this->saturation = saturation;
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
	if (a < 0 || b < 0 || a >= this->v_nr || b >= this->v_nr) {
		return false;
	}
	else {
		this->graph[a][b] = 1;
		this->graph[b][a] = 1;
	}
}

bool Generator::del(int a, int b) {
	if (a < 0 || b < 0 || a >= this->v_nr || b >= this->v_nr) {
		return false;
	}
	else {
		this->graph[a][b] = 0;
		this->graph[b][a] = 0;
	}
}

bool Generator::is_edge(int a, int b) {
	if (this->graph[a][b] == 1) {
		return true;
	}
	else {
		return false;
	}
}

void Generator::display() {
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			std::cout << this->graph[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool Generator::connected_generate() {
	int * unvisited = new int [this->v_nr - 1];
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

	int * visited = new int [this->v_nr];
	visited[0] = unvisited_stack.top();
	unvisited_stack.pop();
	visited[1] = unvisited_stack.top();
	unvisited_stack.pop();
	this->add(visited[0], visited[1]);
	int visited_pointer = 2;
	srand(time(NULL));
	int rand_tmp;
	while (unvisited_stack.size() > 0) {
		rand_tmp = rand() % visited_pointer;
		this->add(unvisited_stack.top(), visited[rand_tmp]);
		visited[visited_pointer++] = unvisited_stack.top();
		unvisited_stack.pop();

	}
	return this->is_connected();
}

bool Generator::euler_generate() {
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			if (i == j) {
				continue;
			}
			this->graph[i][j] = 1;
		}
	}
	int edge_count = this->v_nr * (this->v_nr - 1) / 2;
	if (this->v_nr % 2 == 0) {
		for (int i = this->v_nr - 1; i >= 0; i--) {
			this->del(i, this->v_nr - 1 - i);
		}
		edge_count = this->v_nr * (this->v_nr - 2) / 2;
	}
	int triangle[3];
	int odd_counter = 0;
	while (edge_count - this->e_nr >= 2) {
		triangle[0] = rand() % this->v_nr;
		triangle[1] = rand() % this->v_nr;
		triangle[2] = rand() % this->v_nr;
		while (!this->is_edge(triangle[0], triangle[1]) || !this->is_edge(triangle[1], triangle[2]) || !this->is_edge(triangle[2], triangle[0]) || triangle[0] == triangle[1] || triangle[1] == triangle[2] || triangle[2] == triangle[0]) {
			triangle[odd_counter % 3] = rand() % this->v_nr;
			odd_counter++;
		}
		this->del(triangle[0], triangle[1]);
		this->del(triangle[1], triangle[2]);
		this->del(triangle[2], triangle[0]);
		edge_count -= 3;
	}
	return this->is_eulerian();
}

bool Generator::is_eulerian() {
	int odd_counter = 0;
	for (int i = 0; i < this->v_nr; i++) {
		for (int j = 0; j < this->v_nr; j++) {
			if (this->graph[i][j] == 1) {
				odd_counter++;
			}
		}
		if (odd_counter % 2 != 0 || odd_counter == 0) {
			return false;
		}
		odd_counter = 0;
	}
	return true;
}

bool Generator::is_connected() {
	bool tmp;
	for (int i = 0; i < this->v_nr; i++) {
		tmp = 0;
		for (int j = 0; j < this->v_nr; j++) {
			if (this->is_edge(i, j)) {
				tmp = 1;
				break;
			}
		}
		if (!tmp) {
			return false;
		}
	}
	return tmp;
}

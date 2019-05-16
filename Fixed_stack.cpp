#include <iostream>

#include "Fixed_stack.h"
#include "Utility.h"

Fixed_stack::Fixed_stack(int size) {
	this->size = size;
	this->stack = new int [this->size];
}

Fixed_stack::~Fixed_stack() {
	if (this->stack != NULL) {
		delete [] this->stack;
		this->stack = NULL;
	}
}

void Fixed_stack::euler_stack_generate() {
	for (int i = 0; i < this->size; i++) {
		this->stack[i] = i;
	}
	Utility * util = new Utility();
	util->shuffle(this->stack, this->size);
	delete util;
	util = NULL;
	for (int i = 0; i < this->size; i++) {
		std::cout << this->stack[i] << std::endl;
	}
}

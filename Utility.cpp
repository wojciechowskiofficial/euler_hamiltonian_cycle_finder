#include "Utility.h"

#include <cstdlib>
#include <algorithm>
#include <time.h>

void Utility::shuffle(int * a, int size) {
	srand(time(NULL));
	for (int i = size - 1; i >= 0; i--) {
		std::swap(a[i], a[rand() % (i + 1)]);
	}
}

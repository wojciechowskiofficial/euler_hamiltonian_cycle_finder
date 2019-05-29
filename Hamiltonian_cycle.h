#include <list>
#include <ctime>

class Hamiltonian_cycle {
	public:
		Hamiltonian_cycle(int v_nr, float saturation);
		~Hamiltonian_cycle();
		int v_nr, e_nr;
		float saturation;
		clock_t begin, end;
		bool stop;
		std::list<int> * out;
		int * output_arr;
		int v0;
		bool * possible;
		void display();
		bool load();
		bool perform_util(int k);
		double perform();
};

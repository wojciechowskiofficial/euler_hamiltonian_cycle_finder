#include <vector>

class Eulerian_cycle {
	public:
		int ** graph;
		Eulerian_cycle(int v_nr, float saturation);
		int v_nr, e_nr;
		float saturation;
		~Eulerian_cycle();
		bool is_edge(int a, int b);
		bool add(int a, int b);
		void display();
		void load();
		std::vector<int> seq;
		bool are_adjecent(int a);
		int first_adjecent(int a);
		bool del_edge(int a, int b);
		double perform();
};

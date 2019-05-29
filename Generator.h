class Generator {
	public:
		Generator(int v_nr, float saturation);
		~Generator();
		int v_nr, e_nr;
		float saturation;
		int ** graph;
		bool add(int a, int b);
		bool del(int a, int b);
		bool connected_generate();
		bool euler_generate();
		bool hamilton_generate();
		bool is_edge(int a, int b);
		void display();
		bool is_eulerian();
		bool is_connected();
};

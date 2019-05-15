class Generator {
	public:
		Generator(int v_nr, float saturation);
		~Generator();
		int v_nr, e_nr;
		float saturation;
		int ** graph;
		void test();
};

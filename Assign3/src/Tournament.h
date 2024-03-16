#pragma once

class Population;

class Tournament {
private:

public:
	Tournament() {}
	~Tournament() {}
	void single_Tournament(Population* p);
	void regular_Tournament(Population* p);
};


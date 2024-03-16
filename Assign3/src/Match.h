#pragma once

class LinkedList;
class Agent;

class Match {
private:
	LinkedList* a_history;
	LinkedList* b_history;
public:
	Match();
	~Match();
	void single_Match(int Round_number, Agent* a, Agent* b, int character);
	void regular_Match(Agent* a, Agent* b);
	void Add_Round_data(Agent* a, Agent* b);
	void print_character(int character);
};


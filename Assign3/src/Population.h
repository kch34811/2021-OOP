#pragma once
#include "LinkedList.h"

class Agent;
class Iterator;

class Population : public LinkedList {
private:
	
public:
	Population() {}
	~Population() {}
	void Add(int character_sort, int character_number);
	void Eliminate();
	void Reproduce();
	void sort();
	void print_Tot_Reward_single(Agent* a, Agent* b, int character);
	void print_Tot_Reward();
	void swap(Iterator& a, Iterator& b);
};


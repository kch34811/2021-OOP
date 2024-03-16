#pragma once
#include"Agent.h"

class LinkedList;

class Cheater :public Agent {
private:

public:
	Cheater() {}
	~Cheater(){}
	void act(const LinkedList*);
};


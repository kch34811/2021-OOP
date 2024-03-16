#pragma once
#include "Agent.h"

class LinkedList;

class Cooperator :public Agent {
private:

public:
	Cooperator(){}
	~Cooperator(){}
	void act(const LinkedList*);
};

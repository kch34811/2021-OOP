#pragma once
#include "Agent.h"

class LinkedList;

class Copycat :public Agent {
private:

public:
	Copycat() {}
	~Copycat() {}
	void act(const LinkedList*);
};


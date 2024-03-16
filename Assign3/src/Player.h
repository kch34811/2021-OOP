#pragma once
#include "Agent.h"

class LinkedList;

class Player :public Agent {
private:

public:
	void act(const LinkedList*);
};

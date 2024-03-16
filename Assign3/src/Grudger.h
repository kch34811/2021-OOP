#pragma once
#include "Agent.h"

class LinkedList;

class Grudger :public Agent {
private:
	int check_op; //상대방이 배신을 했는지 check하기 위한 변수
public:
	Grudger();
	~Grudger();
	void act(const LinkedList*);
};


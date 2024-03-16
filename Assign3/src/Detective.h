#pragma once
#include "Agent.h"

class LinkedList;

class Detective :public Agent {
private:
	int check_op; //상대방이 배신을 했는지 check하기 위한 변수
public:
	Detective();
	~Detective();
	void act(const LinkedList*);
};

#pragma once
#include "Agent.h"

class LinkedList;

class Grudger :public Agent {
private:
	int check_op; //������ ����� �ߴ��� check�ϱ� ���� ����
public:
	Grudger();
	~Grudger();
	void act(const LinkedList*);
};


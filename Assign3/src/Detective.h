#pragma once
#include "Agent.h"

class LinkedList;

class Detective :public Agent {
private:
	int check_op; //������ ����� �ߴ��� check�ϱ� ���� ����
public:
	Detective();
	~Detective();
	void act(const LinkedList*);
};

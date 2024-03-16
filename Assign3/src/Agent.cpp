#include<iostream>
#include "LinkedList.h"
#include"Agent.h"

//action���� ���ǹ��� ������ 0,1�� ���Ƿ� -1�� �ʱ�ȭ
Agent::Agent() {
	history = new LinkedList;
	action = -1;
	reward = 0;
	//history�� data�� action�� �����ϴµ� pFirst�� pLast�� data���� -1�� ����
	history->get_pFirst()->data = -1;
	history->get_pLast()->data = -1;
}

//�Ҹ���
Agent::~Agent() {
	delete history;
}

//getter
int Agent::get_action() const {
	return action;
}
int Agent::get_reward() const {
	return reward;
 }
LinkedList* Agent::get_history() const {
	return history;
}

//setter
void Agent::set_action(int act) {
	action = act;
}
void Agent::set_reward(int re) {
	reward = re;
}

//history�� action�� ����� ����
void Agent::set_history_action(int act) {
	history->Add(act);
}

//history�� ���
void Agent::reset_history() {
	history->reset();
}

//1, 0���� ������ action�� �ܾ�� ���
void Agent::print_action() {
	if (action == 1)
		std::cout << "Cooperatring!" << std::endl;

	else if (action == 0)
		std::cout << "Cheating!" << std::endl;
}

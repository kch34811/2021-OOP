#include<iostream>
#include "LinkedList.h"
#include"Agent.h"

//action에는 유의미한 값으로 0,1이 들어가므로 -1로 초기화
Agent::Agent() {
	history = new LinkedList;
	action = -1;
	reward = 0;
	//history의 data에 action을 저장하는데 pFirst와 pLast의 data에는 -1을 저장
	history->get_pFirst()->data = -1;
	history->get_pLast()->data = -1;
}

//소멸자
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

//history에 action의 결과를 저장
void Agent::set_history_action(int act) {
	history->Add(act);
}

//history를 비움
void Agent::reset_history() {
	history->reset();
}

//1, 0으로 저장한 action을 단어로 출력
void Agent::print_action() {
	if (action == 1)
		std::cout << "Cooperatring!" << std::endl;

	else if (action == 0)
		std::cout << "Cheating!" << std::endl;
}

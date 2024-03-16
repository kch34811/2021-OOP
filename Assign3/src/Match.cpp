#include "Match.h"
#include "LinkedList.h"
#include "Agent.h"
#include "Round.h"
#include "Population.h"
#include <iostream>

using namespace std;

//생성자
Match::Match() {
	a_history = new LinkedList;
	b_history = new LinkedList;
}

//소멸자
Match::~Match() {
	delete a_history;
	delete b_history;
}

//1.single Match에서 호출
void Match::single_Match(int Round_number, Agent* a, Agent* b, int character) {
	Population* p = new Population;
	for (int i = 1; i <= Round_number; i++) {
		cout << "==========Round " << i << "==========" << endl;
		Round* r = new Round;
		r->play_round(a, b);
		cout << "Player: ";
		a->print_action();
		print_character(character);
		cout << ": ";
		b->print_action();
		Add_Round_data(a, b);
		p->print_Tot_Reward_single(a, b, character);
		delete r;
	}
	cout << "================================" << endl;
	if (a->get_reward() > b->get_reward()) {
		cout << "The winner is Player" << endl;
	}
	else if (a->get_reward() < b->get_reward()) {
		cout << "The winner is";
		print_character(character);
		cout << endl;
	}
	else if (a->get_reward() == b->get_reward()) {
		cout << "Duce!" << endl;
	}
	cout << "================================" << endl;
	delete p;
}

//1.single Match 외의 일반 Match에서 호출
void Match::regular_Match(Agent* a, Agent* b) {
	for (int i = 1; i <= 10; i++) {
		Round* r = new Round;
		r->play_round(a, b);
		Add_Round_data(a, b);
		delete r;
	}
	a->reset_history();
	b->reset_history();
}

//Round의 결과를 history에 저장, Agent들의 reward에 저장
void Match::Add_Round_data(Agent* a, Agent *b) {
	if (a->get_action() == 1 && b->get_action() == 1) {
		a->set_reward(a->get_reward() + 2);
		b->set_reward(b->get_reward() + 2);
		a_history->Add(2);
		b_history->Add(2);
	}
	else if (a->get_action() == 1 && b->get_action() == 0) {
		a->set_reward(a->get_reward() - 1);
		b->set_reward(b->get_reward() + 3);
		a_history->Add(-1);
		b_history->Add(3);
	}
	else if (a->get_action() == 0 && b->get_action() == 1) {
		a->set_reward(a->get_reward() + 3);
		b->set_reward(b->get_reward() - 1);
		a_history->Add(3);
		b_history->Add(-1);
	}
	else if (a->get_action() == 0 && b->get_action() == 0) {
		a_history->Add(0);
		b_history->Add(0);
	}
}

//숫자에 따라 직업 이름을 출력
void Match::print_character(int character) {
	if (character == 1) {
		cout << "Copycat";
	}
	else if (character == 2) {
		cout << "Cheater";
	}
	else if (character == 3) {
		cout << "Cooperator";
	}
	else if (character == 4) {
		cout << "Grudger";
	}
	else if (character == 5) {
		cout << "Detective";
	}
}
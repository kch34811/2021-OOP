#include<iostream>
#include "Population.h"
#include "Iterator.h"
#include "Copycat.h"
#include "Cheater.h"
#include "Cooperator.h"
#include "Grudger.h"
#include "Detective.h"
#include "Match.h"
#include "Agent.h"


using namespace std;

//Add
void Population::Add(int character_sort, int character_number) {
	
	//Copycat를 가리키는 node 추가
	if (character_sort == 1) {
		for (int i = 0; i < character_number; i++) {
			NodeType* pnode = new NodeType;
			pnode->character = new Copycat;
			pnode->data = 1;
			pnode->next = get_pLast();
			pnode->prev = get_pLast()->prev;
			get_pLast()->prev->next = pnode;
			get_pLast()->prev = pnode;
			set_length(get_length() + 1);
		}
	}
	
	//Cheater를 가리키는 node 추가
	else if (character_sort == 2) {
		for (int i = 0; i < character_number; i++) {
			NodeType* pnode = new NodeType;
			pnode->character = new Cheater;
			pnode->data = 2;
			pnode->next = get_pLast();
			pnode->prev = get_pLast()->prev;
			get_pLast()->prev->next = pnode;
			get_pLast()->prev = pnode;
			set_length(get_length() + 1);
		}
	}

	//Cooperator를 가리키는 node 추가
	else if (character_sort == 3) {
		for (int i = 0; i < character_number; i++) {
			NodeType* pnode = new NodeType;
			pnode->character = new Cooperator;
			pnode->data = 3;
			pnode->next = get_pLast();
			pnode->prev = get_pLast()->prev;
			get_pLast()->prev->next = pnode;
			get_pLast()->prev = pnode;
			set_length(get_length() + 1);
		}
	}

	//Grudger를 가리키는 node 추가
	else if (character_sort == 4) {
		for (int i = 0; i < character_number; i++) {
			NodeType* pnode = new NodeType;
			pnode->character = new Grudger;
			pnode->data = 4;
			pnode->next = get_pLast();
			pnode->prev = get_pLast()->prev;
			get_pLast()->prev->next = pnode;
			get_pLast()->prev = pnode;
			set_length(get_length() + 1);
		}
	}

	//Detective를 가리키는 node 추가
	else if (character_sort == 5) {
		for (int i = 0; i < character_number; i++) {
			NodeType* pnode = new NodeType;
			pnode->character = new Detective;
			pnode->data = 5;
			pnode->next = get_pLast();
			pnode->prev = get_pLast()->prev;
			get_pLast()->prev->next = pnode;
			get_pLast()->prev = pnode;
			set_length(get_length() + 1);
		}
	}
}

//Eliminate
void Population::Eliminate() {
	for (int i = 0; i < 5; i++) {
		NodeType* pnode;
		pnode = get_pLast()->prev;
		pnode->prev->next = get_pLast();
		get_pLast()->prev = pnode->prev;
		delete pnode;
		set_length(get_length() - 1);
	}
}

//Reproduce
void Population::Reproduce() {
	
	for (int i = 0; i < 5; i++) {
		NodeType* pnode = new NodeType;
		pnode->data = get_pFirst()->next->data;
		if (pnode->data == 1)
			pnode->character = new Copycat;
		else if (pnode->data == 2)
			pnode->character = new Cheater;
		else if (pnode->data == 3)
			pnode->character = new Cooperator;
		else if (pnode->data == 4)
			pnode->character = new Grudger;
		else if (pnode->data == 5)
			pnode->character = new Detective;

		pnode->next = get_pFirst()->next->next;
		pnode->prev = get_pFirst()->next;
		get_pFirst()->next->next->prev = pnode;
		get_pFirst()->next->next = pnode;
		set_length(get_length() + 1);
	}

	Iterator itor(*this);
	itor.get_pCurPointer();
	itor.Next();

	while (itor.get_pCurPointer() != get_pLast()) {
		itor.get_pCurPointer()->character->set_reward(0);
		itor.Next();
	}
}

//sort
void Population::sort() {
	Iterator itor_i(*this);
	itor_i.get_pCurPointer();
	
	Iterator itor_j(*this);
	itor_j.get_pCurPointer();
	itor_j.Next();

	Iterator itor_max(*this);
	itor_max.get_pCurPointer();
	
	for (itor_i.Next(); itor_i.get_pCurPointer() != get_pLast()->prev; itor_i.Next()) {
		itor_max = itor_i;
		for (itor_j.set_pCurPointer(itor_i.GetCurrentNode().next); itor_j.get_pCurPointer() != get_pLast(); itor_j.Next()) {
			if (itor_j.get_pCurPointer()->character->get_reward() > itor_max.get_pCurPointer()->character->get_reward()) {
				itor_max = itor_j;
			}
		}
		swap(itor_i, itor_max);
	}
}

//single match에서 Total Reward를 출력
void Population::print_Tot_Reward_single(Agent* a, Agent* b, int character) {
	cout << "--------------------------------" << endl;
	cout << "Total Reward" << endl;
	cout << "1. Player:" << a->get_reward() << endl;
	Match* m = new Match;
	cout << "2. ";
	m->print_character(character);
	cout << ": ";
	cout << b->get_reward() << endl;
	delete m;
}

//regular match에서 Total Reward를 출력
void Population::print_Tot_Reward() {
	Iterator itor(*this);
	itor.get_pCurPointer();
	itor.Next();
	
	int i = 0;
	while (itor.get_pCurPointer() != get_pLast()) {
		i++;
		cout << i << ". ";
		if (itor.get_pCurPointer()->data == 1)
			cout << "Copycat: ";
		else if (itor.get_pCurPointer()->data == 2)
			cout << "Cheater: ";
		else if (itor.get_pCurPointer()->data == 3)
			cout << "Cooperator: ";
		else if (itor.get_pCurPointer()->data == 4)
			cout << "Grudger: ";
		else if (itor.get_pCurPointer()->data == 5)
			cout << "Detective: ";

		cout << itor.get_pCurPointer()->character->get_reward() << endl;
		itor.Next();
	}
}

//두 Iterator가 가리키는 node의 character, data를 바꿈
void Population::swap(Iterator& a, Iterator& b) {
	NodeType* temp = new NodeType;
	temp->character = a.get_pCurPointer()->character;
	temp->data = a.get_pCurPointer()->data;
	a.get_pCurPointer()->character = b.get_pCurPointer()->character;
	a.get_pCurPointer()->data = b.get_pCurPointer()->data;
	b.get_pCurPointer()->character = temp->character;
	b.get_pCurPointer()->data = temp->data;
}
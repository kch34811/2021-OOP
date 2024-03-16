#include"Tournament.h"
#include "Population.h"
#include "Match.h"
#include "Iterator.h"
#include<iostream>

using namespace std;

//2.Single Tournament에서 호출
void Tournament::single_Tournament(Population* p) {
	
	Match* match = new Match;

	Iterator itor_a(*p);
	itor_a.get_pCurPointer();
	for (int i = 1; i < p->get_length(); i++) {
		
		itor_a.Next();
		Iterator itor_b(*p);
		itor_b.set_pCurPointer(itor_a.get_pCurPointer());
		for (int j = i + 1; j <= p->get_length(); j++) {
			itor_b.Next();
			cout << "==========" << i << " vs " << j << "==========" << endl;
			//match를 계속할지 결정
			match->regular_Match(itor_a.get_pCurPointer()->character, itor_b.get_pCurPointer()->character);
			p->print_Tot_Reward();
			
			cout << "--------------------------------" << endl;
			cout << "Continue(1) or Stop(0)" << endl;
			int Continue_decision;
			do {
				cin >> Continue_decision;
				if (!(Continue_decision == 0 || Continue_decision == 1)) {
					std::cout << "Invalid Input!" << std::endl;
				}
				if (Continue_decision == 0) {
					delete match;
					return;
				}
			} while (!(Continue_decision == 0 || Continue_decision == 1));
		}
	}
	delete match;
}

//2. single Tournament 외의 일반 Tournament에서 호출
void Tournament::regular_Tournament(Population* p) {
	
	Match* match = new Match;

	Iterator itor_a(*p);
	itor_a.get_pCurPointer();
	for (int i = 1; i < p->get_length(); i++) {
		itor_a.Next();
		Iterator itor_b(*p);
		itor_b.set_pCurPointer(itor_a.get_pCurPointer());
		for (int j = i + 1; j <= p->get_length(); j++) {
			itor_b.Next();
			match->regular_Match(itor_a.get_pCurPointer()->character, itor_b.get_pCurPointer()->character);
		}
	}
	delete match;
}
#include "Game.h"
#include"Population.h"
#include "Player.h"
#include "Match.h"
#include "Tournament.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

//생성자
Game::Game() {
	Command = 0;
}

//소멸자
Game::~Game() {

}

//시작 메뉴화면 출력
void Game::print_menuscreen() {
	cout << "================================" << endl;
	cout << "Select Menu" << endl;
	cout << "================================" << endl;
	cout << "1. Single Match" << endl;
	cout << "2. Single Toutnament" << endl;
	cout << "3. Repeated Tournament" << endl;
	cout << "4. Exit" << endl;
	cout << "================================" << endl;
	cout << "Command: ";
	
	//1, 2, 3, 4 외 다른 입력 받을 경우
	do {
		cin >> Command;
		if (!(Command == 1 || Command == 2 || Command == 3 || Command == 4)) {
			cout << "Invalid Input!" << endl;
		}
	} while (!(Command == 1 || Command == 2 || Command == 3 || Command == 4));
}

//게임 진행
int Game::play_game() {
	
	//1. Single Match
	if (Command == 1) {
		
		int Total_Round_Number;
		cout << "Total Round Number: ";
		do {
			cin >> Total_Round_Number;
			if (!(Total_Round_Number >= 1 && Total_Round_Number <= 50)) {
				cout << "Invalid Input!" << endl;
			}
		} while (!(Total_Round_Number >= 1 && Total_Round_Number <= 50));
		
		
		cout << "Select an Opponent! Copycat(1), Cheater(2), Cooperator(3), Grudger(4), Detective(5)" << endl;
		
		int Character;
		do {
			cin >> Character;
			if (!(Character == 1 || Character == 2 || Character == 3 || Character == 4 || Character == 5)) {
				cout << "Invalid Input!" << endl;
			}
		} while (!(Character == 1 || Character == 2 || Character == 3 || Character == 4 || Character == 5));
		

		Population* p = new Population;
		Player* me = new Player;

		if (Character == 1) {
			p->Add(1, 1);
		}
		else if (Character == 2) {
			p->Add(2, 1);
		}
		else if (Character == 3) {
			p->Add(3, 1);
		}
		else if (Character == 4) {
			p->Add(4, 1);
		}
		else if (Character == 5) {
			p->Add(5, 1);
		}

		Match* match = new Match;
		match->single_Match(Total_Round_Number, me, p->get_pFirst()->next->character, Character);

		delete p;
		delete me;
		delete match;

		return 1;
	}

	//2. Single Tournament
	else if (Command == 2) {
		
		//Decide Population
		cout << "Decide Population " << endl;
		Population* p = new Population;
		Decide_Populatoin(p);
		
		//전체 인원이 2 미만 또는 50초과일 경우
		if (p->get_length() < 2 || p->get_length() > 50) {
			do {
				p->reset();
				Decide_Populatoin(p);
			} while (p->get_length() < 2 || p->get_length() > 50);
		}

		cout << "--------------------------------" << endl;
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
				delete p;
				return 1;
			}
		} while (!(Continue_decision == 0 || Continue_decision == 1));

		Tournament* t = new Tournament;
		t->single_Tournament(p);

		cout << "================================" << endl;
		p->sort();
		p->print_Tot_Reward();

		delete p;
		delete t;

		return 1;
	}

	//3. Repeated Tournament
	else if (Command == 3) {
		
		int Total_Tournament_Number;
		cout << "Total Tournament Number: ";
		do {
			cin >> Total_Tournament_Number;
			if (!(Total_Tournament_Number >= 1 && Total_Tournament_Number <= 50)) {
				cout << "Invalid Input!" << endl;
			}
		} while (!(Total_Tournament_Number >= 1 && Total_Tournament_Number <= 50));
		
		cout << "Decide Population " << endl;
		Population* p = new Population;
		Decide_Populatoin(p);

		if (p->get_length() < 6 || p->get_length() > 50) {
			do {
				p->reset();
				Decide_Populatoin(p);
			} while (p->get_length() < 6 || p->get_length() > 50);
		}

		cout << "--------------------------------" << endl;
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
				delete p;
				return 1;
			}
		} while (!(Continue_decision == 0 || Continue_decision == 1));

		Tournament* t = new Tournament;

		int Eliminate_decision;
		int Reproduce_decision;

		for (int i = 1; i <= Total_Tournament_Number; i++) {
			cout << "==========Tournament " << i << "===========" << endl;
			t->regular_Tournament(p);
			p->sort();
			p->print_Tot_Reward();
			
			cout << "--------------------------------" << endl;
			cout << "Eliminate(1) or Stop(0)" << endl;
			cin >> Eliminate_decision;
			if (Eliminate_decision == 1) 
				p->Eliminate();
			else if (Eliminate_decision == 0) {
				delete p;
				delete t;
				return 1;
			}
			
			cout << "--------------------------------" << endl;
			cout << "Reproduce(1) or Stop(0)" << endl;
			cin >> Reproduce_decision;
			if (Reproduce_decision == 1)
				p->Reproduce();
			else if (Reproduce_decision == 0) {
				delete p;
				delete t;
				return 1;
			}

			cout << "--------------------------------" << endl;
			p->print_Tot_Reward();
			
			if (i == Total_Tournament_Number) {
				delete p;
				delete t;
				return 1;
			}

			cout << "--------------------------------" << endl;
			cout << "Continue(1) or Stop(0)" << endl;
			int Continue_decision;
			do {
				cin >> Continue_decision;
				if (!(Continue_decision == 0 || Continue_decision == 1)) {
					std::cout << "Invalid Input!" << std::endl;
				}
				if (Continue_decision == 0) {
					delete p;
					delete t;
					return 1;
				}
			} while (!(Continue_decision == 0 || Continue_decision == 1));
		}

		delete p;
		delete t;
		return 1;
	}
	
	//4. Exit
	else if (Command == 4) {
	    return 0;
    }

}

//Population의 LinkedList에 node 추가
void Game::Decide_Populatoin(Population* p) {
	
	//Copycat 추가
	cout << "Copycat: ";
	int Copycat_number;
	do {
		cin >> Copycat_number;
		if (!(Copycat_number >= 0 && Copycat_number <= 50)) {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (!(Copycat_number >= 0 && Copycat_number <= 50));
	p->Add(1, Copycat_number);

	//Cheater 추가
	cout << "Cheater: ";
	int Cheater_number;
	do {
		cin >> Cheater_number;
		if (!(Cheater_number >= 0 && Cheater_number <= 50)) {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (!(Cheater_number >= 0 && Cheater_number <= 50));
	p->Add(2, Cheater_number);

	//Cooperator 추가
	cout << "Cooperator: ";
	int Cooperator_number;
	do {
		cin >> Cooperator_number;
		if (!(Cooperator_number >= 0 && Cooperator_number <= 50)) {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (!(Cooperator_number >= 0 && Cooperator_number <= 50));
	p->Add(3, Cooperator_number);

	//Grudger 추가
	cout << "Grudger: ";
	int Grudger_number;
	do {
		cin >> Grudger_number;
		if (!(Grudger_number >= 0 && Grudger_number <= 50)) {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (!(Grudger_number >= 0 && Grudger_number <= 50));
	p->Add(4, Grudger_number);

	//Detective 추가
	cout << "Detective: ";
	int Detective_number;
	do {
		cin >> Detective_number;
		if (!(Detective_number >= 0 && Detective_number <= 50)) {
			std::cout << "Invalid Input!" << std::endl;
		}
	} while (!(Detective_number >= 0 && Detective_number <= 50));
	p->Add(5, Detective_number);
}
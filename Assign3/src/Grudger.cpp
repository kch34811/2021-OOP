#include "Grudger.h"
#include"LinkedList.h"

Grudger::Grudger()
{
	check_op = 1;
}

Grudger::~Grudger() {}

void Grudger::act(const LinkedList* opponent) {
	//처음엔 협력
	if (opponent->get_pLast()->prev->data == -1) {
		set_action(1);
		check_op = 1;
	}

	if (check_op == 1) {
		//처음 혹은 계속 협력 시 협력
		if (opponent->get_pLast()->prev->data == 1) {
			set_action(1);
		}
		//상대방이 배신하는 순간부터 배신
		else if (opponent->get_pLast()->prev->data == 0) {
			set_action(0);
			check_op = 0;
		}
	}
	//이후에는 계속 배신
	else {
		set_action(0);
	}
}


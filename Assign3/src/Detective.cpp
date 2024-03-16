#include "Detective.h"
#include"LinkedList.h"

Detective::Detective() {
	check_op = 1;
}

Detective::~Detective() {

}

void Detective::act(const LinkedList* opponent) {

	if (opponent->get_pLast()->prev->data == 0)
		check_op = 0;

	//협력-배신-협력-협력으로 시작
	if (get_history()->get_length() == 0) {
		set_action(1);
		check_op = 1;
	}
	else if (get_history()->get_length() == 1)
		set_action(0);
	else if (get_history()->get_length() == 2)
		set_action(1);
	else if (get_history()->get_length() == 3)
		set_action(1);
	//4Round 이후부터는 상대방에 따라 결정
	else {
		//한 번이라도 배신했다면 따라쟁이처럼 행동 
		if (check_op == 0) {
			int op_act = opponent->get_pLast()->prev->data;
			set_action(op_act);
		}
		//항상 협력만 했다면 항상배신자처럼 행동
		else if (check_op == 1) {
			set_action(0);
		}
	}
}
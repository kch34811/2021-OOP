#include "Copycat.h"
#include "LinkedList.h"

void Copycat::act(const LinkedList* opponent) {
	int op_act = opponent->get_pLast()->prev->data;
	//협력으로 시작
	if (op_act == -1) {
		set_action(1);
	}
	//상대방 이전 행동 따라함
	else {
		set_action(op_act);
	}
}





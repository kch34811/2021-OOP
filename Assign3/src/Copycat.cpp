#include "Copycat.h"
#include "LinkedList.h"

void Copycat::act(const LinkedList* opponent) {
	int op_act = opponent->get_pLast()->prev->data;
	//�������� ����
	if (op_act == -1) {
		set_action(1);
	}
	//���� ���� �ൿ ������
	else {
		set_action(op_act);
	}
}





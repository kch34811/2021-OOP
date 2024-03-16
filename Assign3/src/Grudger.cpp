#include "Grudger.h"
#include"LinkedList.h"

Grudger::Grudger()
{
	check_op = 1;
}

Grudger::~Grudger() {}

void Grudger::act(const LinkedList* opponent) {
	//ó���� ����
	if (opponent->get_pLast()->prev->data == -1) {
		set_action(1);
		check_op = 1;
	}

	if (check_op == 1) {
		//ó�� Ȥ�� ��� ���� �� ����
		if (opponent->get_pLast()->prev->data == 1) {
			set_action(1);
		}
		//������ ����ϴ� �������� ���
		else if (opponent->get_pLast()->prev->data == 0) {
			set_action(0);
			check_op = 0;
		}
	}
	//���Ŀ��� ��� ���
	else {
		set_action(0);
	}
}


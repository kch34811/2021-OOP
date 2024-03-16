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

	//����-���-����-�������� ����
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
	//4Round ���ĺ��ʹ� ���濡 ���� ����
	else {
		//�� ���̶� ����ߴٸ� ��������ó�� �ൿ 
		if (check_op == 0) {
			int op_act = opponent->get_pLast()->prev->data;
			set_action(op_act);
		}
		//�׻� ���¸� �ߴٸ� �׻�����ó�� �ൿ
		else if (check_op == 1) {
			set_action(0);
		}
	}
}
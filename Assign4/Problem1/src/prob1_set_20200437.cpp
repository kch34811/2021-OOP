#include "prob1_set_20200437.h"

//�ʱⰪ ���� ������
MySet::MySet() {
	pFirst = new Node;
	pLast = new Node;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
}

//�ʱⰪ �ִ� ������
MySet::MySet(int* array, int S_number) {
	
	pFirst = new Node;
	pLast = new Node;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
	
	for (int i = 0; i < S_number; i++) {
		Node* pnode;
		pnode = new Node;
		pnode->data = array[i];
		pnode->next = pLast;
		pnode->prev = pLast->prev;
		pLast->prev->next = pnode;
		pLast->prev = pnode;
		length++;
	}
}

//�Ҹ���
MySet::~MySet() {
	//MySet ���
	Node* pnode;
	Node* iter;
	iter = pFirst->next;

	while (iter != pLast) {
		pnode = iter;
		iter = iter->next;
		delete pnode;
	}

	delete pFirst;
	delete pLast;
}

//���������
MySet::MySet(const MySet& copyFrom) {
	pFirst = new Node;
	pLast = new Node;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
	
	Node* iter = copyFrom.pFirst->next;
	while (iter != copyFrom.pLast) {
		Node* pnode;
		pnode = new Node;
		pnode->data = iter->data;
		pnode->next = pLast;
		pnode->prev = pLast->prev;
		pLast->prev->next = pnode;
		pLast->prev = pnode;
		length++;
		iter = iter->next;
	}
}

//������ ���
MySet MySet::operator+(const MySet& S2) {
	MySet S;
	S = *this;

	Node* iter_S2 = S2.pFirst->next;

	for (int i = 0; i < S2.length; i++) {
		int check = 0; //MySet�� S2�� �ߺ��Ǵ� ���Ұ� �ִ��� �˻��ϴ� �뵵
		Node* iter = pFirst->next;
		for (int j = 0; j < length; j++) {
			if (iter->data == iter_S2->data) {
				check = 1;
				break;
			}
			iter = iter->next;
		}
		
		//�ߺ��Ǵ� ���Ұ� �ƴ϶�� S�� �߰�
		if (check == 0) {
			S = S + iter_S2->data;
		}
		iter_S2 = iter_S2->next;
	}
	
	return S;
}

//���� �߰�
MySet MySet::operator+(const int E1) {
	MySet S;
	S = *this;

	if (S.contains(E1) == false) {
		Node* pnode;
		pnode = new Node;
		pnode->data = E1;
		pnode->next = S.pLast;
		pnode->prev = S.pLast->prev;
		S.pLast->prev->next = pnode;
		S.pLast->prev = pnode;
		S.length++;
	}

	return S;
	
}

//������ ���
MySet MySet::operator-(const MySet& S2) {
	MySet S;
	S = *this;

	//MySet�� S2 ������ Inter_S
	MySet Inter_S;
	Inter_S = (*this) * S2;
	
	//S���� Inter_S ���� ����
	Node* iter = Inter_S.pFirst->next;
	for (int i = 0; i < Inter_S.length; i++) {
		S = S - iter->data;
		iter = iter->next;
	}
	return S;
}

//���� ����
MySet MySet::operator-(const int E1) {
	
	MySet S;
	S = *this;
	Node* iter = S.pFirst->next;

	while (iter != pLast) {
		if (iter->data == E1) {
			iter->next->prev = iter->prev;
			iter->prev->next = iter->next;
			break;
		}
		iter = iter->next;
	}
	S.length--;
	
	delete iter;
	return S;
}

//������ ���
MySet MySet::operator*(const MySet& S2) {
	
	MySet S;

	Node* iter_S2 = S2.pFirst->next;

	for (int i = 0; i < S2.length; i++) {
		int check = 0; //MySet�� S2�� �ߺ��Ǵ� ���Ұ� �ִ��� �˻��ϴ� �뵵
		Node* iter = pFirst->next;
		for (int j = 0; j < length; j++) {
			if (iter->data == iter_S2->data) {
				check = 1;
				break;
			}
			iter = iter->next;
		}

		if (check == 1) {
			S = S + iter_S2->data;
		}
		iter_S2 = iter_S2->next;
	}

	return S;
}

//���� ����
MySet& MySet::operator=(const MySet& S2) {

	//MySet ���
	Node* pnode;
	Node* iter;
	iter = pFirst->next;

	while (iter != pLast) {
		pnode = iter;
		iter = iter->next;
		delete pnode;
	}
	pFirst->next = pLast;
	pLast->prev = pFirst;

	//MySet�� S2 ���� �ϳ��� �߰�
	iter = S2.pFirst->next;
	for (int i = 0; i < S2.length; i++) {
		Node* pnode;
		pnode = new Node;
		pnode->data = iter->data;
		pnode->next = pLast;
		pnode->prev = pLast->prev;
		pLast->prev->next = pnode;
		pLast->prev = pnode;
		iter = iter->next;
	}
	length = S2.length;

	return *this;
}

//���� ���� ���� ��ȯ
bool MySet::operator==(const MySet& S2) {
	Node* iter = pFirst->next;
	Node* iter_S2 = S2.pFirst->next;
	
	if (length != S2.length)
		return false;
	
	for (int i = 0; i < length; i++) {
		if (iter->data != iter_S2->data) {
			return false;
		}
		iter = iter->next;
		iter_S2 = iter_S2->next;
	}

	return true;
}

//���� ���� ���� ��ȯ
bool MySet::contains(const MySet& S2) {
	//MySet�� S2�� ������ Union_S
	MySet Union_S = *this + S2;
	
	//MySet�� Union_S�� ������
	if (*this == Union_S)
		return true;
	else return false;
}

//���� ���� ���� ��ȯ
bool MySet::contains(const int E1) {
	Node* iter = pFirst->next;
	for (int i = 0; i < length; i++) {
		if (iter->data == E1)
			return true;
		iter = iter->next;
	}
	return false;
}

//������ ���� ��ȯ
bool MySet::isEmpty() {
	if (length == 0)
		return true;
	else return false;
}

//���Ұ��� ��ȯ
int MySet::getSize() {
	return length;
}

//MySet�� string���� ��ȯ
string MySet::toString() {
	string s, s_temp;
	Node* iter;
	iter = pFirst->next;

	while (iter != pLast) {
		s_temp = to_string(iter->data);
		if (iter == pLast->prev)
			s += s_temp;
		else
			s += s_temp + ' ';
		iter = iter->next;
	}

	return s;
}
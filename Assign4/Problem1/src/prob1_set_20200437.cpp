#include "prob1_set_20200437.h"

//초기값 없는 생성자
MySet::MySet() {
	pFirst = new Node;
	pLast = new Node;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
}

//초기값 있는 생성자
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

//소멸자
MySet::~MySet() {
	//MySet 비움
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

//복사생성자
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

//합집합 계산
MySet MySet::operator+(const MySet& S2) {
	MySet S;
	S = *this;

	Node* iter_S2 = S2.pFirst->next;

	for (int i = 0; i < S2.length; i++) {
		int check = 0; //MySet에 S2와 중복되는 원소가 있는지 검사하는 용도
		Node* iter = pFirst->next;
		for (int j = 0; j < length; j++) {
			if (iter->data == iter_S2->data) {
				check = 1;
				break;
			}
			iter = iter->next;
		}
		
		//중복되는 원소가 아니라면 S에 추가
		if (check == 0) {
			S = S + iter_S2->data;
		}
		iter_S2 = iter_S2->next;
	}
	
	return S;
}

//원소 추가
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

//차집합 계산
MySet MySet::operator-(const MySet& S2) {
	MySet S;
	S = *this;

	//MySet과 S2 교집합 Inter_S
	MySet Inter_S;
	Inter_S = (*this) * S2;
	
	//S에서 Inter_S 원소 제거
	Node* iter = Inter_S.pFirst->next;
	for (int i = 0; i < Inter_S.length; i++) {
		S = S - iter->data;
		iter = iter->next;
	}
	return S;
}

//원소 제거
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

//교집합 계산
MySet MySet::operator*(const MySet& S2) {
	
	MySet S;

	Node* iter_S2 = S2.pFirst->next;

	for (int i = 0; i < S2.length; i++) {
		int check = 0; //MySet에 S2와 중복되는 원소가 있는지 검사하는 용도
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

//집합 변경
MySet& MySet::operator=(const MySet& S2) {

	//MySet 비움
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

	//MySet에 S2 원소 하나씩 추가
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

//집합 동일 여부 반환
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

//집합 포함 유무 반환
bool MySet::contains(const MySet& S2) {
	//MySet과 S2의 합집합 Union_S
	MySet Union_S = *this + S2;
	
	//MySet과 Union_S가 같은지
	if (*this == Union_S)
		return true;
	else return false;
}

//원소 포함 유무 반환
bool MySet::contains(const int E1) {
	Node* iter = pFirst->next;
	for (int i = 0; i < length; i++) {
		if (iter->data == E1)
			return true;
		iter = iter->next;
	}
	return false;
}

//공집합 유무 반환
bool MySet::isEmpty() {
	if (length == 0)
		return true;
	else return false;
}

//원소개수 반환
int MySet::getSize() {
	return length;
}

//MySet을 string으로 반환
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
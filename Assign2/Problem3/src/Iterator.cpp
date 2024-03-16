#include<iostream>
#include"Iterator.h"

//������
Iterator::Iterator(const DoublyLinkedList& list) : dList(list) {
	pCurPointer = list.getpFirst();
}

//�Ҹ���
Iterator::~Iterator() {}

//getter
const DoublyLinkedList& Iterator::getdList() {
	return dList;
}
NodeType* Iterator::getpCurPointer() {
	return pCurPointer;
}

//setter
void Iterator::setpCurPointer(NodeType* pPointer) {
	pCurPointer = pPointer;
}

//���� ���Ұ� null����
bool Iterator::NotNull() {
	if (pCurPointer == NULL)
		return false;
	else return true;
}

//���� ���Ұ� null����
bool Iterator::NextNotNull() {
	if (pCurPointer->next == NULL)
		return false;
	else return true;
}

bool Iterator::PrevNotNull() {
	if (pCurPointer->prev == NULL)
		return false;
	else return true;
}

ItemType Iterator::First() {
	//ó�� ��带 ���̳��� �ξ��� ������
	NodeType* pF = dList.getpFirst()->next;
	return pF->data;
}

ItemType Iterator::Next() {
	pCurPointer = pCurPointer->next;
	return pCurPointer->data;
}

ItemType Iterator::Prev() {
	pCurPointer = pCurPointer->prev;
	return pCurPointer->data;
}

NodeType Iterator::GetCurrentNode() {
	return *pCurPointer;
}

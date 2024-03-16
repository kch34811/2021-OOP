#include<iostream>
#include"Iterator.h"

//생성자
Iterator::Iterator(const DoublyLinkedList& list) : dList(list) {
	pCurPointer = list.getpFirst();
}

//소멸자
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

//현재 원소가 null인지
bool Iterator::NotNull() {
	if (pCurPointer == NULL)
		return false;
	else return true;
}

//다음 원소가 null인지
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
	//처음 노드를 더미노드로 두었기 때문에
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

#include"Iterator.h"
#include "LinkedList.h"
#include<iostream>

Iterator::Iterator(const LinkedList& list) : dList(list) {
	pCurPointer = list.get_pFirst();
}

//¼Ò¸êÀÚ
Iterator::~Iterator() {}

NodeType* Iterator::Next() {
	pCurPointer = pCurPointer->next;
	return pCurPointer;
}

//getter
const LinkedList& Iterator::get_dList() {
	return dList;
}
NodeType* Iterator::get_pCurPointer() {
	return pCurPointer;
}

//setter
void Iterator::set_pCurPointer(NodeType* pPointer) {
	pCurPointer = pPointer;
}

NodeType Iterator::GetCurrentNode() {
	return *pCurPointer;
}

Iterator& Iterator::operator=(const Iterator& i) {
	pCurPointer = i.pCurPointer;
	return *this;
}
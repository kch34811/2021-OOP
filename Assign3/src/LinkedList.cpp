#pragma once
#include<iostream>
#include "LinkedList.h"
#include "Agent.h"
#include"Copycat.h"
#include"Cheater.h"
#include"Cooperator.h"
#include"Grudger.h"
#include"Detective.h"
#include"Player.h"
#include "Iterator.h"

//생성자
LinkedList::LinkedList() {
	pFirst = new NodeType;
	pLast = new NodeType;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
}

//소멸자
LinkedList::~LinkedList() {
	delete pFirst;
	delete pLast;
}

//data를 저장한 node를 맨 끝에 삽입
void LinkedList::Add(int data) {
	NodeType* pnode = new NodeType;
	pnode->character = NULL;
	pnode->data = data;
	pnode->next = pLast;
	pnode->prev = pLast->prev;
	pLast->prev->next = pnode;
	pLast->prev = pnode;
	length++;
}

//LinkedList를 비움
void LinkedList::reset() {
	NodeType* pnode;
	Iterator itor(*this);
	itor.get_pCurPointer();
	itor.Next();


	while (itor.get_pCurPointer() != pLast)
	{
		pnode = itor.get_pCurPointer(); // itor가 가리키는 위치의 노드 pItem
		itor.Next(); // itor가 다음 노드를 가리키도록
		delete pnode; // pItem 노드를 삭제
	}

	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
	
	return;
}

//getter
NodeType* LinkedList::get_pFirst() const {
	return pFirst;
}
NodeType* LinkedList::get_pLast() const {
	return pLast;
}
int LinkedList::get_length() const {
	return length;
}

//setter
void LinkedList::set_pFirst(NodeType* pF) {
	pFirst = pF;
}
void LinkedList::set_pLast(NodeType* pL) {
	pLast = pL;
}
void LinkedList::set_length(int len) {
	length = len;
}
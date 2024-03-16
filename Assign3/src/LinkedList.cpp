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

//������
LinkedList::LinkedList() {
	pFirst = new NodeType;
	pLast = new NodeType;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
}

//�Ҹ���
LinkedList::~LinkedList() {
	delete pFirst;
	delete pLast;
}

//data�� ������ node�� �� ���� ����
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

//LinkedList�� ���
void LinkedList::reset() {
	NodeType* pnode;
	Iterator itor(*this);
	itor.get_pCurPointer();
	itor.Next();


	while (itor.get_pCurPointer() != pLast)
	{
		pnode = itor.get_pCurPointer(); // itor�� ����Ű�� ��ġ�� ��� pItem
		itor.Next(); // itor�� ���� ��带 ����Ű����
		delete pnode; // pItem ��带 ����
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
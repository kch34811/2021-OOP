#include<iostream>
#include "DoublyLinkedList.h"
#include "Iterator.h"
#include "ItemType.h"

using namespace std;


//생성자, 소멸자
DoublyLinkedList::DoublyLinkedList() {
	pFirst = new NodeType;
	pLast = new NodeType;
	pFirst->next = pLast;
	pLast->prev = pFirst;
	length = 0;
}

DoublyLinkedList::~DoublyLinkedList(){
	delete pFirst;
	delete pLast;
}

//getter, setter 함수
NodeType* DoublyLinkedList::getpFirst() const {
	return pFirst;
}
NodeType* DoublyLinkedList::getpLast() const {
	return pLast;
}
int DoublyLinkedList::getlength() const {
	return length;
}
void DoublyLinkedList::setpFirst(NodeType* pF) {
	pFirst = pF;
}
void DoublyLinkedList::setpLast(NodeType* pL) {
	pLast = pL;
}
void DoublyLinkedList::setlength(int l) {
	length = l;
}

//리스트 비어있는지 확인
bool DoublyLinkedList::IsEmpty() const {
	if (length == 0)
		return true;
	else return false;
}

//리스트를 빈 리스트로 만듦 -> 더미노드는 있는 상태
void DoublyLinkedList::MakeEmpty() {
	
	NodeType* pItem;
	Iterator itor(*this); // this 포인터를 이용하여 Iterator 선언
	itor.getpCurPointer();
	itor.Next();
	

	while (itor.getpCurPointer() != pLast) 
	{
		pItem = itor.getpCurPointer(); // itor가 가리키는 위치의 노드 pItem
		itor.Next(); // itor가 다음 노드를 가리키도록
		delete pItem; // pItem 노드를 삭제
	}

	pFirst->next = pLast;
	pLast->prev = pFirst;

	return;
}

//리스트가 보유하고 있는 레코드의 개수
int DoublyLinkedList::GetLength()const {
	return length;
}

//item을 리스트에 추가
int DoublyLinkedList::Add(ItemType item) {

	if (IsEmpty() == true) {
		NodeType* pItem = new NodeType;
		pItem->data = item;
		pFirst->next = pItem;
		pLast->prev = pItem;
		pItem->prev = pFirst;
		pItem->next = pLast;
		length++;
		return 1;
	}
	else {

		Iterator itor(*this);
		itor.getpCurPointer();
		itor.Next();

		while (itor.getpCurPointer() != pLast) // itor가 가리키는 현재 위치가 pLast가 되기 전까지
		{

			if ((item == itor.getpCurPointer()->data) == true) { //이미 존재하는 id를 가진 item일 때
				cout << "item with same id" << endl;
				return 0;
			}
		
			if (((item < itor.getpCurPointer()->data) == true) && ((item > itor.getpCurPointer()->prev->data) == true)|| (item == itor.getpCurPointer()->prev->data) == true) {
				NodeType* pItem = new NodeType;
				pItem->data = item;
				itor.getpCurPointer()->prev->next = pItem; //이전 노드와 pItem 연결
				pItem->prev = itor.getpCurPointer()->prev;
				itor.getpCurPointer()->prev = pItem;
				pItem->next = itor.getpCurPointer();
				length++;
				return 1;
			}
			itor.Next();// itor가 다음 노드를 가리키도록
		}

		//가장 마지막 노드 바로 전에 삽입
		NodeType* pItem = new NodeType;
		pItem->data = item;
		itor.getpCurPointer()->prev->next = pItem; //이전 노드와 pItem 연결
		pItem->prev = itor.getpCurPointer()->prev;
		itor.getpCurPointer()->prev = pItem;
		pItem->next = itor.getpCurPointer();
		length++;
		return 1;
	}
	return 0;
}

//기존 레코드 삭제
int DoublyLinkedList::Delete(ItemType item) {

	Iterator itor(*this);
	itor.getpCurPointer();
	itor.Next();
	NodeType* pointer;
	
	int i = 0;
	while (itor.getpCurPointer() != pLast) 
	{
		if (item == itor.getpCurPointer()->data) {
			itor.getpCurPointer()->next->prev = itor.getpCurPointer()->prev;
			itor.getpCurPointer()->prev->next = itor.getpCurPointer()->next;
			length--;
			i++;
			pointer = itor.getpCurPointer();
			itor.Next();
			delete pointer;
			itor.Prev();
		}
		itor.Next();
	}
	if (i == 0) //하나도 삭제하지 못했으면 0 반환
		return 0;
	else return 1; //하나라도 삭제하였다면 1 반환
}

//기존 레코드 갱신
int DoublyLinkedList::Replace(ItemType item) {

	Iterator itor(*this);
	itor.getpCurPointer();
	itor.Next();
	int i = 0;
	while (itor.getpCurPointer() != pLast) // itor가 가리키는 현재 위치가 pLast가 되기 전까지
	{
		if ((item == itor.getpCurPointer()->data) == true) {
			itor.getpCurPointer()->data = item;
			i++;
		}
		itor.Next(); // itor가 다음 노드를 가리키도록
	}
	if (i == 0) //하나도 삭제하지 못했으면 0 반환
		return 0;
	else return 1; //하나라도 삭제하였다면 1 반환
}


int DoublyLinkedList::Get(ItemType& item) {
	Iterator itor(*this);
	itor.getpCurPointer();
	itor.Next();
	int i = 0;
	while (itor.getpCurPointer() != pLast) // itor가 가리키는 현재 위치가 pLast가 되기 전까지
	{
		if ((item == itor.getpCurPointer()->data) == true) {
			item = itor.getpCurPointer()->data;
			i++;
		}
		itor.Next();// itor가 다음 노드를 가리키도록
	}
	if (i == 0) //하나도 삭제하지 못했으면 0 반환
		return 0;
	else return 1; //하나라도 삭제하였다면 1 반환
}
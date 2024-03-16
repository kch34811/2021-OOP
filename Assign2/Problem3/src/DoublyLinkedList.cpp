#include<iostream>
#include "DoublyLinkedList.h"
#include "Iterator.h"
#include "ItemType.h"

using namespace std;


//������, �Ҹ���
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

//getter, setter �Լ�
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

//����Ʈ ����ִ��� Ȯ��
bool DoublyLinkedList::IsEmpty() const {
	if (length == 0)
		return true;
	else return false;
}

//����Ʈ�� �� ����Ʈ�� ���� -> ���̳��� �ִ� ����
void DoublyLinkedList::MakeEmpty() {
	
	NodeType* pItem;
	Iterator itor(*this); // this �����͸� �̿��Ͽ� Iterator ����
	itor.getpCurPointer();
	itor.Next();
	

	while (itor.getpCurPointer() != pLast) 
	{
		pItem = itor.getpCurPointer(); // itor�� ����Ű�� ��ġ�� ��� pItem
		itor.Next(); // itor�� ���� ��带 ����Ű����
		delete pItem; // pItem ��带 ����
	}

	pFirst->next = pLast;
	pLast->prev = pFirst;

	return;
}

//����Ʈ�� �����ϰ� �ִ� ���ڵ��� ����
int DoublyLinkedList::GetLength()const {
	return length;
}

//item�� ����Ʈ�� �߰�
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

		while (itor.getpCurPointer() != pLast) // itor�� ����Ű�� ���� ��ġ�� pLast�� �Ǳ� ������
		{

			if ((item == itor.getpCurPointer()->data) == true) { //�̹� �����ϴ� id�� ���� item�� ��
				cout << "item with same id" << endl;
				return 0;
			}
		
			if (((item < itor.getpCurPointer()->data) == true) && ((item > itor.getpCurPointer()->prev->data) == true)|| (item == itor.getpCurPointer()->prev->data) == true) {
				NodeType* pItem = new NodeType;
				pItem->data = item;
				itor.getpCurPointer()->prev->next = pItem; //���� ���� pItem ����
				pItem->prev = itor.getpCurPointer()->prev;
				itor.getpCurPointer()->prev = pItem;
				pItem->next = itor.getpCurPointer();
				length++;
				return 1;
			}
			itor.Next();// itor�� ���� ��带 ����Ű����
		}

		//���� ������ ��� �ٷ� ���� ����
		NodeType* pItem = new NodeType;
		pItem->data = item;
		itor.getpCurPointer()->prev->next = pItem; //���� ���� pItem ����
		pItem->prev = itor.getpCurPointer()->prev;
		itor.getpCurPointer()->prev = pItem;
		pItem->next = itor.getpCurPointer();
		length++;
		return 1;
	}
	return 0;
}

//���� ���ڵ� ����
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
	if (i == 0) //�ϳ��� �������� �������� 0 ��ȯ
		return 0;
	else return 1; //�ϳ��� �����Ͽ��ٸ� 1 ��ȯ
}

//���� ���ڵ� ����
int DoublyLinkedList::Replace(ItemType item) {

	Iterator itor(*this);
	itor.getpCurPointer();
	itor.Next();
	int i = 0;
	while (itor.getpCurPointer() != pLast) // itor�� ����Ű�� ���� ��ġ�� pLast�� �Ǳ� ������
	{
		if ((item == itor.getpCurPointer()->data) == true) {
			itor.getpCurPointer()->data = item;
			i++;
		}
		itor.Next(); // itor�� ���� ��带 ����Ű����
	}
	if (i == 0) //�ϳ��� �������� �������� 0 ��ȯ
		return 0;
	else return 1; //�ϳ��� �����Ͽ��ٸ� 1 ��ȯ
}


int DoublyLinkedList::Get(ItemType& item) {
	Iterator itor(*this);
	itor.getpCurPointer();
	itor.Next();
	int i = 0;
	while (itor.getpCurPointer() != pLast) // itor�� ����Ű�� ���� ��ġ�� pLast�� �Ǳ� ������
	{
		if ((item == itor.getpCurPointer()->data) == true) {
			item = itor.getpCurPointer()->data;
			i++;
		}
		itor.Next();// itor�� ���� ��带 ����Ű����
	}
	if (i == 0) //�ϳ��� �������� �������� 0 ��ȯ
		return 0;
	else return 1; //�ϳ��� �����Ͽ��ٸ� 1 ��ȯ
}
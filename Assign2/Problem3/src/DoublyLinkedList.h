#pragma once
#include"ItemType.h"

struct NodeType {
	ItemType data;
	NodeType* prev;
	NodeType* next;
};


class DoublyLinkedList 
{
private:
	NodeType* pFirst;
	NodeType* pLast;
	int length;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	NodeType* getpFirst()const;
	NodeType* getpLast()const;
	int getlength()const;
	void setpFirst(NodeType* pF);
	void setpLast(NodeType* pL);
	void setlength(int l);

	bool IsEmpty() const;
	void MakeEmpty();
	int GetLength()const;
	int Add(ItemType item);
	int Delete(ItemType item);
	int Replace(ItemType item);
	int Get(ItemType& item);
};
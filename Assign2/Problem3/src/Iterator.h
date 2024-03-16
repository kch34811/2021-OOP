#pragma once
#include"DoublyLinkedList.h"


class Iterator 
{
private:
	const DoublyLinkedList& dList;
	NodeType* pCurPointer;
public:
	Iterator(const DoublyLinkedList& list);
	~Iterator();
	const DoublyLinkedList& getdList();
	NodeType* getpCurPointer();
	void setpCurPointer(NodeType* pPointer);
	bool NotNull();
	bool NextNotNull();
	bool PrevNotNull();
	ItemType First();
	ItemType Next();
	ItemType Prev();
	NodeType GetCurrentNode();
};
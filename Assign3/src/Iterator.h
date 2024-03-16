#pragma once

class LinkedList;
struct NodeType;

class Iterator
{
private:
	const LinkedList& dList;
	NodeType* pCurPointer;
public:
	Iterator(const LinkedList& list);
	~Iterator();
	const LinkedList& get_dList();
	NodeType* get_pCurPointer();
	void set_pCurPointer(NodeType* pPointer);
	NodeType* Next();
	NodeType GetCurrentNode();
	Iterator& operator=(const Iterator& i);
};
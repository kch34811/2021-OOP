#pragma once

class Agent;

struct NodeType {
	NodeType* next;
	Agent* character;
	int data;
	NodeType* prev;
};

class LinkedList {

private:
	NodeType* pFirst;
	NodeType* pLast;
	int length;

public:
	LinkedList();
	~LinkedList();
	void Add(int);
	void reset();
	NodeType* get_pFirst()const;
	NodeType* get_pLast()const;
	int get_length() const;
	void set_pFirst(NodeType* pF);
	void set_pLast(NodeType* pL);
	void set_length(int len);
};

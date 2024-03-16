#pragma once
#include <string>

using namespace std;

struct Node {
	int data;
	Node* next, * prev;
};

class MySet {
private:
	Node* pFirst;
	Node* pLast;
	int length;
public:
	MySet();
	MySet(int* array, int S_number);
	~MySet();
	MySet(const MySet& copyFrom);
	MySet operator+(const MySet& S2);
	MySet operator+(const int E1);
	MySet operator-(const MySet& S2);
	MySet operator-(const int E1);
	MySet operator*(const MySet& S2);
	MySet& operator=(const MySet& S2);
	bool operator==(const MySet& S2);
	bool contains(const MySet& S2);
	bool contains(const int E1);
	bool isEmpty();
	int getSize();
	string toString();
};
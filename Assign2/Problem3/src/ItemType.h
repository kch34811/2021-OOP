#pragma once

#include<string>

using namespace std;

class ItemType 
{
private:
	int id = -1;
	string name;

public:
	//생성자와 소멸자
	ItemType();
	~ItemType();
	ItemType(const ItemType& copyFrom);
	
	//getter, setter함수
	int getid() const;
	string getname() const;
	void setid(int i);
	void setname(string s);

	//연산자 오버로딩
	bool operator<(const ItemType& item) const;
	bool operator>(const ItemType& item) const;
	bool operator==(const ItemType& item) const;
	ItemType& operator=(const ItemType& item);

};
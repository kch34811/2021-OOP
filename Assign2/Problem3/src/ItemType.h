#pragma once

#include<string>

using namespace std;

class ItemType 
{
private:
	int id = -1;
	string name;

public:
	//�����ڿ� �Ҹ���
	ItemType();
	~ItemType();
	ItemType(const ItemType& copyFrom);
	
	//getter, setter�Լ�
	int getid() const;
	string getname() const;
	void setid(int i);
	void setname(string s);

	//������ �����ε�
	bool operator<(const ItemType& item) const;
	bool operator>(const ItemType& item) const;
	bool operator==(const ItemType& item) const;
	ItemType& operator=(const ItemType& item);

};
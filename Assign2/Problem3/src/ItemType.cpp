#include<iostream>
#include"ItemType.h"

//������
ItemType::ItemType(){}

ItemType::~ItemType() {}

ItemType::ItemType(const ItemType& copyFrom) {
	id = copyFrom.id;
	name = copyFrom.name;
}

//getter
int ItemType::getid() const {
	return id;
}
string ItemType::getname() const {
	return name;
}

//setter
void ItemType::setid(int i) {
	id = i;
}
void ItemType::setname(string s) {
	name = s;
}

//������ �����ε�
bool ItemType::operator<(const ItemType& item) const {
	if (id < item.id)
		return true;
	else return false;
}

bool ItemType::operator>(const ItemType& item) const {
	if (id > item.id)
		return true;
	else return false;
}

bool ItemType::operator==(const ItemType& item) const {
	if (id == item.id)
		return true;
	else return false;
}

ItemType& ItemType::operator=(const ItemType& item) {
	id = item.id;
	name = item.name;
	return *this;
}
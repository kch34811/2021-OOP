#include <iostream>
#include"Application.h"
#include "DoublyLinkedList.h"
#include "Iterator.h"

using namespace std;

//생성자, 소멸자
Application::Application() {
	dList = new DoublyLinkedList();
	mCommand = 0;
}

Application::~Application() {
	delete dList;
}


void Application::Run() {
	
	do {
		
		int success = -1;

		mCommand = GetCommand();//command 저장

		//올바르지 않은 command에 대해 오류 메세지
		if (!(mCommand >= 0 && mCommand <= 6)) {
			cout << "Wrong command!" << endl;
			return;
		}

		if (mCommand == 1)
			success = AddItem();
		else if (mCommand == 2)
			success = DeleteItem();
		else if (mCommand == 3)
			success = UpdateItem();
		else if (mCommand == 4)
			success = SearchItem();
		else if (mCommand == 5)
			DisplayAllItem();
		else if (mCommand == 6)
			MakeEmptyList();

		if (success == 0) {
			cout << "Fail!" << endl;
		}
	
	} while (mCommand != 0);
	
	return;
}

int Application::GetCommand() {
	int command;

	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t 1 : Add new item" << endl;
	cout << "\t 2 : Delete item" << endl;
	cout << "\t 3 : Update item" << endl;
	cout << "\t 4 : Search item by ID" << endl;
	cout << "\t 5 : Print all on screen" << endl;
	cout << "\t 6 : Make empty list" << endl;
	cout << "\t 0 : Quit" << endl;
	
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	
	return command;
}

//item을 받아 리스트에 추가
int Application::AddItem() {
	
	int addSuccess = 0;

	int item_id;
	string item_name;
	
	cout << "Input item id :";
	cin >> item_id;
	cout << "Input item name :";
	cin >> item_name;
	
	ItemType item;
	item.setid(item_id);
	item.setname(item_name);

	addSuccess = dList->Add(item);

	return addSuccess;
}


int Application::DeleteItem() {

	int deleteSuccess = 0;

	int item_id;

	cout << "Item id that you want to delete :";
	cin >> item_id;

	ItemType item;
	item.setid(item_id);

	deleteSuccess = dList->Delete(item);

	return deleteSuccess;

}
int Application::UpdateItem() {

	int updateSuccess = 0;
	int getSuccess = 0;

	int item_id; 
	string item_name;

	cout << "Item id that you want to update :";
	cin >> item_id;
	cout << "Item name that you want to replace :";
	cin >> item_name;

	ItemType item;
	item.setid(item_id);
	item.setname(item_name);

	updateSuccess = dList->Replace(item);
	
	return updateSuccess;

}

int Application::SearchItem() {

	int searchSuccess = 0;

	int item_id;

	//입력받는 거 성공하지 못했을 때
	cout << "Item id that you want to search :";
	cin >> item_id;

	ItemType item;
	item.setid(item_id);

	searchSuccess = dList->Get(item);

	if (searchSuccess == 0) {
		cout << "Can't find item";
		return 0;
	}
	
	cout << "Find item. Item id :" << item.getid() << ", Item name : " << item.getname();
	return 1;
}

void Application::DisplayAllItem() {
	
	Iterator itor(*dList);
	itor.getpCurPointer();
	itor.Next();
	if (itor.getpCurPointer() == dList->getpLast())
		return;
	
	while (itor.getpCurPointer() != dList->getpLast()) {
		cout << "Item id : " << itor.getpCurPointer()->data.getid();
		cout << ", Item name : " << itor.getpCurPointer()->data.getname() << endl;
		itor.Next();
	}
}

void Application::MakeEmptyList() {

	dList->MakeEmpty();
	
}
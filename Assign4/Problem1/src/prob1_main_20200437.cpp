#include "prob1_set_20200437.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <sstream>

void save_Set(MySet*&);
void save_Element(int*&);
int find_number(string S);
void change_Sfile(int, MySet&);

using namespace std;

int main() {
	
	MySet* Set_array;
	save_Set(Set_array);
	
	int* Element_array;
	save_Element(Element_array);

	string first, second, third; //������ ���� Set,Element ����
	string operation, operation_2; //������ ����
	
	ifstream infile;
	infile.open("input_p1.txt");
	ofstream outfile;
	outfile.open("output_p1_20200437.txt");

	if (infile.is_open()) {
		while (!infile.eof()) {
			string line;
			getline(infile, line);
			
			stringstream stream(line);
			stream >> first;
			stream >> operation;
			stream >> second;

			//������ 1.
			if (operation == "+" && second[0] == 'S') {
				int S_first = find_number(first);
				int S_second = find_number(second);
				MySet S = Set_array[S_first - 1] + Set_array[S_second - 1];
				outfile << S.toString() << endl;
			}
			else if (operation == "-" && second[0] == 'S') {
				int S_first = find_number(first);
				int S_second = find_number(second);
				MySet S = Set_array[S_first - 1] - Set_array[S_second - 1];
				outfile << S.toString() << endl;
			}
			else if (operation == "*" && second[0] == 'S') {
				int S_first = find_number(first);
				int S_second = find_number(second);
				MySet S = Set_array[S_first - 1] * Set_array[S_second - 1];
				outfile << S.toString() << endl;
			}
			else if (operation == "==" && second[0] == 'S') {
				int S_first = find_number(first);
				int S_second = find_number(second);
				int T_F = (Set_array[S_first - 1] == Set_array[S_second - 1]);
				if (T_F == 1)
					outfile << "true" << endl;
				else if (T_F == 0)
					outfile << "false" << endl;
			}
			else if (operation == "+" && second[0] == 'E') {
				int S_first = find_number(first);
				int E_second = find_number(second);
				MySet S = Set_array[S_first - 1] + Element_array[E_second - 1];
				outfile << S.toString() << endl;
			}
			else if (operation == "-" && second[0] == 'E') {
				int S_first = find_number(first);
				int E_second = find_number(second);
				MySet S = Set_array[S_first - 1] - Element_array[E_second - 1];
				outfile << S.toString() << endl;
			}
			
			//������ 2. 
			if (operation == "=") {
				stream >> operation_2; //���� S1=S2�̸�?
				stream >> third;
				if (operation_2 == "+" && third[0] == 'S') {
					int S_first = find_number(first);
					int S_second = find_number(second);
					int S_third = find_number(third);
					Set_array[S_first - 1] = Set_array[S_second - 1] + Set_array[S_third - 1];
					outfile << Set_array[S_first - 1].toString() << endl;
					change_Sfile(S_first, Set_array[S_first - 1]);
				}
				else if (operation_2 == "-" && third[0] == 'S') {
					int S_first = find_number(first);
					int S_second = find_number(second);
					int S_third = find_number(third);
					Set_array[S_first - 1] = Set_array[S_second - 1] - Set_array[S_third - 1];
					outfile << Set_array[S_first - 1].toString() << endl;
					change_Sfile(S_first, Set_array[S_first - 1]);
				}
				else if (operation_2 == "*" && third[0] == 'S') {
					int S_first = find_number(first);
					int S_second = find_number(second);
					int S_third = find_number(third);
					Set_array[S_first - 1] = Set_array[S_second - 1] * Set_array[S_third - 1];
					outfile << Set_array[S_first - 1].toString() << endl;
					change_Sfile(S_first, Set_array[S_first - 1]);
				}
				else if (operation_2 == "+" && third[0] == 'E') {
					int S_first = find_number(first);
					int S_second = find_number(second);
					int E_third = find_number(third);
					Set_array[S_first - 1] = Set_array[S_second - 1] + Element_array[E_third - 1];
					outfile << Set_array[S_first - 1].toString() << endl;
					change_Sfile(S_first, Set_array[S_first - 1]);
				}
				else if (operation_2 == "-" && third[0] == 'E') {
					int S_first = find_number(first);
					int S_second = find_number(second);
					int E_third = find_number(third);
					Set_array[S_first - 1] = Set_array[S_second - 1] - Element_array[E_third - 1];
					outfile << Set_array[S_first - 1].toString() << endl;
					change_Sfile(S_first, Set_array[S_first - 1]);
				}
				else {
					int S_first = find_number(first);
					int S_second = find_number(second);
					Set_array[S_first - 1] = Set_array[S_second - 1];
					outfile << Set_array[S_first - 1].toString() << endl;
					change_Sfile(S_first, Set_array[S_first - 1]);
				}
			}

			//������ 3.
			else if (operation == "contain" && second[0] == 'S') {
				int S_first = find_number(first);
				int S_second = find_number(second);
				int T_F = Set_array[S_first - 1].contains(Set_array[S_second - 1]);
				if (T_F == 1)
					outfile << "true" << endl;
				else if (T_F == 0)
					outfile << "false" << endl;
			}
			else if (operation == "contain" && second[0] == 'E') {
				int S_first = find_number(first);
				int E_second = find_number(second);
				int T_F = Set_array[S_first - 1].contains(Element_array[E_second - 1]);
				if (T_F == 1)
					outfile << "true" << endl;
				else if (T_F == 0)
					outfile << "false" << endl;
			}
			//������ 4.
			else if (first == "isEmpty") {
				int S_first = find_number(operation);
				int T_F = Set_array[S_first - 1].isEmpty();
				if (T_F == 1)
					outfile << "true" << endl;
				else if (T_F == 0)
					outfile << "false" << endl;
			}
			//������ 5.
			else if (first == "size") {
				int S_first = find_number(operation);
				int size = Set_array[S_first - 1].getSize();
				outfile << size << endl;
			}
		}
	}
	
	infile.close();
	outfile.close();
	delete[]Set_array;
	delete[]Element_array;

	return 0;
}

//S#.txt�� ���� Set �о�� Set_array�� �����ϴ� �Լ�
void save_Set(MySet*& Set_array) {
	
	int Set_number = 0; //Set�� ������ �����ϴ� ����

	//Set�� ���� ���
	for (unsigned int i = 1; i <= 1000000; i++) {
		string file_number = to_string(i);
		string S_filename = 'S' + file_number + ".txt";

		ifstream infile;
		infile.open(S_filename);

		if (infile.is_open()) {
			Set_number++;
		}
		else {
			break;
		}
	}

	//Set���� �����ϴ� �迭
	Set_array = new MySet[Set_number];

	//S#���κ��� Set �о�� �� ����
	for (int i = 0; i < Set_number; i++) {
		string file_number = to_string(i + 1);
		string S_filename = 'S' + file_number + ".txt";

		ifstream infile;
		infile.open(S_filename);

		if (infile.is_open()) {
			while (!infile.eof()) {

				string S;
				getline(infile, S);

				//string�� �ִ� ���� int array�� ����
				int S_number = (S.length() + 1) / 2; //������ ���� ������ �����ϴ� ����
				int* array = new int[S_number];
				
				int num;
				stringstream stream(S);
				int j = 0;
				while (stream >> num) {
					array[j] = num;
					j++;
				}

				//Set ���� �� Set_array�� ����
				MySet Set(array, S_number);
				Set_array[i] = Set;
			}
		}
		infile.close();
	}
}

//E#.txt�� ���� Element �о�� Element_array�� �����ϴ� �Լ�
void save_Element(int*& Element_array) {
	
	int Element_number = 0; //Element�� ������ �����ϴ� ����

	//Element�� ���� ���
	for (unsigned int i = 1; i <= 1000000; i++) {
		string file_number = to_string(i);
		string E_filename = 'E' + file_number + ".txt";

		ifstream infile;
		infile.open(E_filename);

		if (infile.is_open()) {
			Element_number++;
		}
		else {
			break;
		}
	}

	//Element���� �����ϴ� �迭
	Element_array = new int[Element_number];

	for (int i = 0; i < Element_number; i++) {
		string file_number = to_string(i + 1);
		string E_filename = 'E' + file_number + ".txt";

		ifstream infile;
		infile.open(E_filename);

		if (infile.is_open()) {
			while (!infile.eof()) {
				infile >> Element_array[i];
			}
		}

		infile.close();
	}
}

//S#�� E#���� #�� int������ �����ִ� �Լ�
int find_number(string S) {
	string S_number;
	for (unsigned int i = 1; i < S.length(); i++) {
		S_number += S[i];
	}
	int num = stoi(S_number);
	return num;
}

//S# ������ ������ �ٲٴ� �Լ�
void change_Sfile(int M_number, MySet& S) {
	
	string file_number = to_string(M_number);
	string S_filename = 'S' + file_number + ".txt";

	ofstream outfile;
	outfile.open(S_filename);

	if (outfile.is_open()) {
		outfile << S.toString();
	}

}
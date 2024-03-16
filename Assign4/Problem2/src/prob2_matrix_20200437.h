#pragma once
#pragma once
#include<string>

using namespace std;

template<typename T>
class MyMatrix {
private:
	T** m;
	int N;
	int file_number = 0;
	int Not_Square = 0;
	int Lost_Element = 0;
public:
	MyMatrix();
	MyMatrix(T** m_array, int n);
	MyMatrix(int n);
	MyMatrix(const MyMatrix& copyFrom);
	~MyMatrix();
	MyMatrix operator+(const MyMatrix& M2);
	MyMatrix operator-(const MyMatrix& M2);
	MyMatrix operator*(const MyMatrix& M2);
	MyMatrix& operator=(const MyMatrix& M2);
	MyMatrix transpose();
	string toString();
	//getter �Լ� �߰� ����
	T** get_m();
	int get_N();
	int get_file_number();
	int get_Not_Square();
	int get_Lost_Element();
	//setter �Լ� �߰� ����
	void set_Not_Square(int check);
	void set_Lost_Element(int check);
	void set_file_number(int num);
};
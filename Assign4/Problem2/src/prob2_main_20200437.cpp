#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <sstream>
#include"prob2_matrix_20200437.h"
#include "prob2_matrix_20200437.cpp"

int save_Matrix(MyMatrix<long long>*&);
int find_number(string S, MyMatrix<long long>*& Matrix_array, int Matrix_number);
void change_Mfile(MyMatrix<long long>& M);

using namespace std;

int main() {

	int Matrix_number;
	MyMatrix<long long>* Matrix_array;
	Matrix_number = save_Matrix(Matrix_array);

	string first, second, third; //연산자 사이 Matrix 저장
	string operation, operation_2; //연산자 저장

	ifstream infile;
	infile.open("input_p2.txt");
	ofstream outfile;
	outfile.open("output_p2_20200437.txt");

	if (infile.is_open()) {
		while (!infile.eof()) {
			string line;
			getline(infile, line);

			stringstream stream(line);
			stream >> first;
			stream >> operation;
			stream >> second;

			//연산목록 1.
			//1.1
			if (operation != "=") {
				if (operation == "+" && second != "TRANS") {
					int M_first = find_number(first, Matrix_array, Matrix_number);
					int M_second = find_number(second, Matrix_array, Matrix_number);
					//error handling
					if (M_first == Matrix_number || M_second == Matrix_number)
						outfile << "NO_MATRIX" << endl;
					else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
						outfile << "NOT_SQUARE" << endl;
					else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
						outfile << "LOST_ELEMENT" << endl;
					else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
						outfile << "UNAVAILABLE_OPERATION" << endl;
					else {
						MyMatrix<long long> M = Matrix_array[M_first] + Matrix_array[M_second];
						outfile << M.toString() << endl;
					}
				}
				else if (operation == "-"&& second != "TRANS") {
					int M_first = find_number(first, Matrix_array, Matrix_number);
					int M_second = find_number(second, Matrix_array, Matrix_number);
					if (M_first == Matrix_number || M_second == Matrix_number)
						outfile << "NO_MATRIX" << endl;
					else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
						outfile << "NOT_SQUARE" << endl;
					else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
						outfile << "LOST_ELEMENT" << endl;
					else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
						outfile << "UNAVAILABLE_OPERATION" << endl;
					else {
						MyMatrix<long long> M = Matrix_array[M_first] - Matrix_array[M_second];
						outfile << M.toString() << endl;
					}
				}
				else if (operation == "*" && second != "TRANS") {
					int M_first = find_number(first, Matrix_array, Matrix_number);
					int M_second = find_number(second, Matrix_array, Matrix_number);
					if (M_first == Matrix_number || M_second == Matrix_number)
						outfile << "NO_MATRIX" << endl;
					else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
						outfile << "NOT_SQUARE" << endl;
					else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
						outfile << "LOST_ELEMENT" << endl;
					else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
						outfile << "UNAVAILABLE_OPERATION" << endl;
					else {
						MyMatrix<long long> M = Matrix_array[M_first] * Matrix_array[M_second];
						outfile << M.toString() << endl;
					}
				}

				//1.3
				else if (second == "TRANS") {
					string trans = second;
					stream >> second;
					if (operation == "+") {
						int M_first = find_number(first, Matrix_array, Matrix_number);
						int M_second = find_number(second, Matrix_array, Matrix_number);
						if (M_first == Matrix_number || M_second == Matrix_number)
							outfile << "NO_MATRIX" << endl;
						else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
							outfile << "NOT_SQUARE" << endl;
						else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
							outfile << "LOST_ELEMENT" << endl;
						else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
							outfile << "UNAVAILABLE_OPERATION" << endl;
						else {
							MyMatrix<long long> M = Matrix_array[M_first] + Matrix_array[M_second].transpose();
							outfile << M.toString() << endl;
						}
					}
					else if (operation == "-") {
						int M_first = find_number(first, Matrix_array, Matrix_number);
						int M_second = find_number(second, Matrix_array, Matrix_number);
						if (M_first == Matrix_number || M_second == Matrix_number)
							outfile << "NO_MATRIX" << endl;
						else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
							outfile << "NOT_SQUARE" << endl;
						else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
							outfile << "LOST_ELEMENT" << endl;
						else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
							outfile << "UNAVAILABLE_OPERATION" << endl;
						else {
							MyMatrix<long long> M = Matrix_array[M_first] - Matrix_array[M_second].transpose();
							outfile << M.toString() << endl;
						}
					}
					else if (operation == "*") {
						int M_first = find_number(first, Matrix_array, Matrix_number);
						int M_second = find_number(second, Matrix_array, Matrix_number);
						if (M_first == Matrix_number || M_second == Matrix_number)
							outfile << "NO_MATRIX" << endl;
						else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
							outfile << "NOT_SQUARE" << endl;
						else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
							outfile << "LOST_ELEMENT" << endl;
						else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
							outfile << "UNAVAILABLE_OPERATION" << endl;
						else {
							MyMatrix<long long> M = Matrix_array[M_first] * Matrix_array[M_second].transpose();
							outfile << M.toString() << endl;
						}
					}
				}

				else if (first == "TRANS") {
					string trans = first;
					first = operation;
					operation = second;
					stream >> second;
					//1.4
					if (second == "TRANS") {
						string trans_2 = second;
						stream >> second;
						if (operation == "+") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose() + Matrix_array[M_second].transpose();
								outfile << M.toString() << endl;
							}
						}
						else if (operation == "-") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose() - Matrix_array[M_second].transpose();
								outfile << M.toString() << endl;
							}
						}
						else if (operation == "*") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose() * Matrix_array[M_second].transpose();
								outfile << M.toString() << endl;
							}
						}
					}

					//1.2
					else {
						if (operation == "+") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose() + Matrix_array[M_second];
								outfile << M.toString() << endl;
							}
						}
						else if (operation == "-") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose() - Matrix_array[M_second];
								outfile << M.toString() << endl;
							}
						}
						else if (operation == "*") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1 || Matrix_array[M_second].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1 || Matrix_array[M_second].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_first].get_N() != Matrix_array[M_second].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose() * Matrix_array[M_second];
								outfile << M.toString() << endl;
							}
						}
						//연산목록 3.
						else {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							if (M_first == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else {
								MyMatrix<long long> M = Matrix_array[M_first].transpose();
								outfile << M.toString() << endl;
							}
						}
					}
				}
			}
	
			//연산목록 2.
			if (operation == "=") {
				stream >> operation_2;
				stream >> third;
				if (second == "TRANS") {
					string trans = second;
					second = operation_2;
					operation_2 = third;
					stream >> third;
					//2.4
					if (third == "TRANS") {
						string trans_2 = third;
						stream >> third;
						if (operation_2 == "+") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose() + Matrix_array[M_third].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "-") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose() - Matrix_array[M_third].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "*") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose() * Matrix_array[M_third].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
					}
					else {
						//2.2
						if (operation_2 == "+") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose() + Matrix_array[M_third];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "-") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose() - Matrix_array[M_third];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "*") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose() * Matrix_array[M_third];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						//2.5
						else {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_first].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_first].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
					}
				}
				else {
					//2.3
					if (third == "TRANS") {
						string trans = third;
						stream >> third;
						if (operation_2 == "+") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second] + Matrix_array[M_third].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "-") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second] - Matrix_array[M_third].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "*") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second] * Matrix_array[M_third].transpose();
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
					}
					//2.1
					else {
						if (operation_2 == "+") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second] + Matrix_array[M_third];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "-") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second] - Matrix_array[M_third];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						else if (operation_2 == "*") {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							int M_third = find_number(third, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number || M_third == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second].get_Not_Square() == 1 || Matrix_array[M_third].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second].get_Lost_Element() == 1 || Matrix_array[M_third].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else if (Matrix_array[M_second].get_N() != Matrix_array[M_third].get_N())
								outfile << "UNAVAILABLE_OPERATION" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second] * Matrix_array[M_third];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
						//2.6
						else {
							int M_first = find_number(first, Matrix_array, Matrix_number);
							int M_second = find_number(second, Matrix_array, Matrix_number);
							if (M_first == Matrix_number || M_second == Matrix_number)
								outfile << "NO_MATRIX" << endl;
							else if (Matrix_array[M_second - 1].get_Not_Square() == 1)
								outfile << "NOT_SQUARE" << endl;
							else if (Matrix_array[M_second - 1].get_Lost_Element() == 1)
								outfile << "LOST_ELEMENT" << endl;
							else {
								Matrix_array[M_first] = Matrix_array[M_second];
								outfile << Matrix_array[M_first].toString() << endl;
								change_Mfile(Matrix_array[M_first]);
							}
						}
					}
				}
			}
		}
	}

	infile.close();
	outfile.close();
	delete[]Matrix_array;

	return 0;
}

//M#.txt로부터 Matrix 읽어와 Matrix_array에 저장하는 함수
int save_Matrix(MyMatrix<long long>*& Matrix_array) {

	int Matrix_number = 0; //Matrix의 갯수를 저장하는 변수

	//Matrix의 갯수 계산
	for (int i = 1; i <= 1000000; i++) {
		
		string file_number = to_string(i);
		string M_filename = 'M' + file_number + ".txt";

		ifstream infile;
		infile.open(M_filename);

		if (infile.is_open()) {
			Matrix_number++;
		}
		infile.close();
	}

	//M#파일 중 #에 해당하는 숫자만 저장하는 배열
	int* M_file_number = new int[Matrix_number];
	int a = 0;
	for (unsigned int i = 1; i <= 1000000; i++) {
		string file_number = to_string(i);
		string M_filename = 'M' + file_number + ".txt";

		ifstream infile;
		infile.open(M_filename);

		if (infile.is_open()) {
			M_file_number[a] = i;
			a++;
		}
		infile.close();
	}

	//Matrix들을 저장하는 배열
	Matrix_array = new MyMatrix<long long>[Matrix_number];

	//M#으로부터 Matrix 읽어온 후 저장
	for (int i = 0; i < Matrix_number; i++) {
		string file_number = to_string(M_file_number[i]);
		string M_filename = 'M' + file_number + ".txt";

		ifstream infile;
		infile.open(M_filename);

		//총 행의 크기 계산
		int row = 0;
		if (infile.is_open()) {
			while (!infile.eof()) {
				string S;
				getline(infile, S);
				row++;
			}
		}
		infile.close();

		//각 행의 크기 계산
		infile.open(M_filename);
		int* each_row = new int[row];
		for (int i = 0; i < row; i++) {
			int col = 0;
			string S;
			getline(infile, S); 
			stringstream stream(S);
			long long temp;
			while (stream >> temp) {
				col++;
			}
			each_row[i] = col;
		}
		infile.close();

		//NOT_SQUARE와 LOST_ELEMENT
		int check = 0;
		for (int i = 0; i < row; i++) {
			if (each_row[i] != row)
				check++;
		}
		if (check == row) {
			MyMatrix<long long> Matrix;
			Matrix_array[i] = Matrix;
			Matrix_array[i].set_Not_Square(1);
			Matrix_array[i].set_file_number(M_file_number[i]);
		}
		else if (check != 0) {
			MyMatrix<long long> Matrix;
			Matrix_array[i] = Matrix;
			Matrix_array[i].set_Lost_Element(1);
			Matrix_array[i].set_file_number(M_file_number[i]);
		}
		//정상 Matrix
		else {
			int N = row;
			long long** m_array = new long long* [N];
			for (int j = 0; j < N; j++) {
				m_array[j] = new long long[N];
			}

			int m = 0;

			infile.open(M_filename);
			if (infile.is_open()) {
				while (!infile.eof()) {
					string S;
					getline(infile, S);
					long long temp;
					stringstream stream(S);
					int n = 0;
					while (stream >> temp) {
						m_array[m][n] = temp;
						n++;
					}
					m++;
				}
			}
			MyMatrix<long long> Matrix(m_array, N);
			Matrix_array[i] = Matrix;
			Matrix_array[i].set_file_number(M_file_number[i]);

			infile.close();
		}
		delete[]each_row;
		
	}
	delete[]M_file_number;
	return Matrix_number;
}

//input 파일의 M#에서 #을 찾아 Matrix_array에 #번호의 배열숫자를 찾아 return
int find_number(string S, MyMatrix<long long>*& Matrix_array, int Matrix_number) {
	string S_number;
	for (unsigned int i = 1; i < S.length(); i++) {
		S_number += S[i];
	}
	int num = stoi(S_number);
	int i;
	for (i = 0; i < Matrix_number; i++) {
		if (Matrix_array[i].get_file_number() == num) {
			break;
		}
	}
	return i;
}

//M# 파일의 내용을 바꾸는 함수
void change_Mfile(MyMatrix<long long>& M) {
	
	int num = M.get_file_number();
	
	string file_number = to_string(num);
	string M_filename = 'M' + file_number + ".txt";
	
	ofstream outfile;
	outfile.open(M_filename);

	if (outfile.is_open()) {
		for (int i = 0; i < M.get_N(); i++) {
			for (int j = 0; j < M.get_N(); j++) {
				outfile << M.get_m()[i][j] << " ";
			}
			outfile << endl;
		}
	}
}
	

	


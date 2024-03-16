#include"prob2_matrix_20200437.h"
#include<string>
#include<iostream>


using namespace std;

//초기화 값이 없는 생성자
template<typename T>
MyMatrix<T>::MyMatrix() {
	N = 1;
	m = new T * [N];
	for (int i = 0; i < N; i++) {
		m[i] = new T[N];
	}
	m[0][0] = 0;
}

//초기화 값이 있는 생성자
template<typename T>
MyMatrix<T>::MyMatrix(T** m_array, int n) {
	N = n;
	m = m_array;
}

//행렬크기만 정해져 있는 생성자
template<typename T>
MyMatrix<T>::MyMatrix(int n) {
	N = n;
	m = new T * [N];
	for (int i = 0; i < N; i++) {
		m[i] = new T[N];
	}
}

//복사생성자
template<typename T>
MyMatrix<T>::MyMatrix(const MyMatrix& copyFrom) {
	N = copyFrom.N;
	m = new T * [N];
	for (int i = 0; i < N; i++) {
		m[i] = new T[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = copyFrom.m[i][j];
		}
	}
}

//소멸자
template<typename T>
MyMatrix<T>::~MyMatrix() {
	for (int i = 0; i < N; i++) {
		delete[] m[i];
	}
	delete[] m;
}

template<typename T>
MyMatrix<T> MyMatrix<T>:: operator+(const MyMatrix& M2) {
	MyMatrix<T> M(M2.N);
	for (int i = 0; i < M.N; i++) {
		for (int j = 0; j < M.N; j++) {
			M.m[i][j] = m[i][j] + M2.m[i][j];
		}
	}
	return M;
}

template<typename T>
MyMatrix<T> MyMatrix<T>::operator-(const MyMatrix& M2) {
	MyMatrix<T> M(M2.N);
	for (int i = 0; i < M.N; i++) {
		for (int j = 0; j < M.N; j++) {
			M.m[i][j] = m[i][j] - M2.m[i][j];
		}
	}
	return M;
}

template<typename T>
MyMatrix<T> MyMatrix<T>::operator*(const MyMatrix& M2) {
	MyMatrix<T> M(M2.N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M.m[i][j] = 0;
		}
	}

	for (int i = 0; i < M.N; i++) {
		for (int j = 0; j < M.N; j++) {
			for (int k = 0; k < M.N; k++) {
				M.m[i][j] += (m[i][k] * M2.m[k][j]);
			}
		}
	}
	return M;
}

template<typename T>
MyMatrix<T>& MyMatrix<T>::operator=(const MyMatrix& M2) {

	//동적할당 해제 후 M2 size로 다시 동적할당
	for (int i = 0; i < N; i++) {
		delete[] m[i];
	}
	delete[] m;

	N = M2.N;
	
	m = new T * [N];
	for (int i = 0; i < N; i++) {
		m[i] = new T[N];
	}

	//M2와 동일하게 행렬 변환
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = M2.m[i][j];
		}
	}

	return *this;
}

template<typename T>
MyMatrix<T> MyMatrix<T>::transpose() {
	MyMatrix<T> M(N);
	for (int i = 0; i < M.N; i++) {
		for (int j = 0; j < M.N; j++) {
			M.m[i][j] = m[j][i];
		}
	}
	return M;
}

template <typename T>
string MyMatrix<T>::toString() {
	string s;
	string s_temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			s_temp = to_string(m[i][j]);
			if (i == N - 1 && j == N - 1) {
				s += s_temp;
			}
			else {
				s += s_temp + ' ';
			}
		}
		if (i != N - 1) {
			s += "| ";
		}
	}

	return s;
}

template <typename T>
T** MyMatrix<T>::get_m() {
	return m;
}

template <typename T>
int MyMatrix<T>::get_N() {
	return N;
}

template <typename T>
int MyMatrix<T>::get_file_number() {
	return file_number;
}

template <typename T>
int MyMatrix<T>::get_Not_Square() {
	return Not_Square;
}

template <typename T>
int MyMatrix<T>::get_Lost_Element() {
	return Lost_Element;
}

template <typename T>
void MyMatrix<T>::set_Not_Square(int check) {
	Not_Square = check;
}

template <typename T>
void MyMatrix<T>::set_Lost_Element(int check) {
	Lost_Element = check;
}

template <typename T>
void MyMatrix<T>::set_file_number(int num) {
	file_number = num;
}
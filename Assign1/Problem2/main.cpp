#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<sstream>
#include<climits>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void division(unsigned int left, unsigned int right, vector <int>& number);
void combine(unsigned int left, unsigned int right, vector <int>& number);

int main() {
	
	string sort_type;
	string data;

	ifstream infile;
	infile.open("input.txt");

	FILE* outfile = fopen("output.txt", "w");

	if (infile.is_open()) {
		while (!infile.eof()) {

			getline(infile, sort_type);
			getline(infile, data);

			unsigned int temp;
			unsigned int i = 0;
			vector <int> number;

			stringstream line(data);
			while (line >> temp) {
				number.push_back(temp);
				i++;
			}
			unsigned int data_size = i;

			division(0, data_size - 1, number);

			fprintf(outfile, "\n");
			if (sort_type == "UP") {
				for (unsigned int j = 0; j < data_size; j++) {
					fprintf(outfile, "%d ", number[j]);
				}
			}
			else if (sort_type == "DOWN") {
				for (unsigned int j = data_size - 1; j >= 0; j--) {
					fprintf(outfile, "%d ", number[j]);
				}
			}
			fprintf(outfile, "\n");
			
		}
		infile.close();
		fclose(outfile);
	}
	return 0;
}

void division(unsigned int left, unsigned int right, vector <int>& number) {

	unsigned int middle;
	if (left < right) {

		middle = left + (right - left) / 2; 
		division(left, middle, number);
		division(middle + 1, right, number);
		combine(left, right, number);
	}

}

void combine(unsigned int left, unsigned int right, vector <int>& number) {

	vector <int> sort_number(right + 1);
	unsigned int middle = left + (right - left) / 2;

	unsigned int i = left;
	unsigned int j = middle + 1;
	unsigned int k = left;

	while (i <= middle && j <= right) {
		if (number[i] < number[j]) {
			sort_number[k] = number[i];
			i++;
			k++;
		}
		else {
			sort_number[k] = number[j];
			j++;
			k++;
		}
	}

	if (j > right) {
		for (unsigned int m = i; m <= middle; m++) {
			sort_number[k] = number[m];
			k++;
		}
	}
	if (i > middle) {
		for (unsigned int m = j; m <= right; m++) {
			sort_number[k] = number[m];
			k++;
		}
	}

	for (unsigned int m = left; m <= right; m++) {
		number[m] = sort_number[m];
	}

}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cmath>

void binary_to_decimal(unsigned int binary, unsigned int* decimal);

int main() 
{
	unsigned int binary(0);
	unsigned int decimal(0);

	FILE* infile = fopen("input.txt", "r");
    FILE* outfile = fopen("output.txt", "w");


    if (infile == NULL) {
        printf("could not open input file\n");
        return 0; 
    }
    

    while (fscanf(infile, "%d", &binary) != EOF) {

        binary_to_decimal(binary, &decimal);
        fprintf(outfile, "%d\n", decimal);

    }
   
    fclose(infile);
    fclose(outfile);

    return 0;

}

void binary_to_decimal(unsigned int binary, unsigned int* decimal) {

    unsigned int digit = 0;
    *decimal = 0;
    unsigned int i = binary; 

    while (i!=0) { 

        i = i / 10; 
        digit++; 

    }

    for (int j = digit - 1; j >= 0; j--) {

        int number = binary / pow(10, j);

        if (number == 1) {
            binary -= pow(10, j);
            *decimal += pow(2, j);
        }
    }
}
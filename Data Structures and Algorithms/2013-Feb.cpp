#include <iostream>
#include <stdio.h>


bool hasPattern(int a[], int N);

int main() {
	// Problem #1
	int a1[] = { 1,2,12,5,3 };
	int a2[] = { 0,0,0,0,0,0,0 };
	int a3[] = { 1,0,0 };
	int a4[] = { 1,1,1,1 };
	int a5[] = { 1,1,1,0,0 };
	int a6[] = { 1,1,1,0,1,0,0 };
	int N1 = 5;
	int N2 = 7;
	int N3 = 3;
	int N4 = 4;
	int N5 = 5;
	int N6 = 7;
	if (hasPattern(a1, N1)) std::cout << "The array follows the pattern.\n";
	else std::cout << "The array does not follow the pattern.\n";
	if (hasPattern(a2, N2)) std::cout << "The array follows the pattern.\n";
	else std::cout << "The array does not follow the pattern.\n";
	if (hasPattern(a3, N3)) std::cout << "The array follows the pattern.\n";
	else std::cout << "The array does not follow the pattern.\n";
	if (hasPattern(a4, N4)) std::cout << "The array follows the pattern.\n";
	else std::cout << "The array does not follow the pattern.\n";
	if (hasPattern(a5, N5)) std::cout << "The array follows the pattern.\n";
	else std::cout << "The array does not follow the pattern.\n";
	if (hasPattern(a6, N6)) std::cout << "The array follows the pattern.\n";
	else std::cout << "The array does not follow the pattern.\n";
}

/*
Problem #1 (4 points). Return true if the array follows the pattern 1 | 1 | ... | 0 | 0
*/
bool hasPattern(int a[], int N) {

	if (N == 0 || N == 1) return true;

	bool hasPattern = true;
	bool ones = true;

	int i = 0;
	while (i < N && hasPattern) {
		if (a[i] != 0 && a[i] != 1) hasPattern = false;
		else if (a[i] == 0) ones = false;
		else if (a[i] == 1 && !ones) hasPattern = false;
		i++;
	}

	return hasPattern;
}
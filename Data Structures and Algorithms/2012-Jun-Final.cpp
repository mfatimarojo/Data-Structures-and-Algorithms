#include <iostream>
#include <stdio.h>

int longestLength(int a[], int N);


int main() {

	// Problem #1
	int a1[] = { 1,2,12,5,3 };
	int N1 = 5;
	int a2[] = { 1,2,3,4,5 };
	int N2 = 5;
	int a3[] = { 1,2,5,4,3,4,5,6 };
	int N3 = 8;
	std::cout << "The length of the longest segment with consecutive elements in increasing order is " << longestLength(a1, N1) << std::endl;
	std::cout << "The length of the longest segment with consecutive elements in increasing order is " << longestLength(a2, N2) << std::endl;
	std::cout << "The length of the longest segment with consecutive elements in increasing order is " << longestLength(a3, N3) << std::endl;

	/*int a2[] = { 1,2,3,4,3,2,1 };
	int a3[] = { 3,2,1 };
	int a4[] = { 1,2,3,4 };
	int N2 = 7;
	int N3 = 3;
	int N4 = 4;


	int a5[] = { -4,-2, 2, 6, 7 };
	int a6[] = { 1, 2, 3, 4, 5 };
	int N5 = 5;

}

/*
Problem  #1. (4 points) Given an array of integers n>0, return the length of the longest segment with consecutive elements
			 in increasing order <=
*/
int longestLength(int a[], int N) {
	if (N == 0) return 0;
	if (N == 1) return 1;

	int i = 0;
	int length = 0;
	int maxLength = 0;
	while (i < N - 1) {
		if (a[i] <= a[i + 1]) {
			if (i == N-2) length+=2;
			else length++;
			if (length > maxLength) maxLength = length;
		}
		else {
			length = 0;
		}
		i++;
	}

	return maxLength;
}

/*
Problem #2. (2 points) Implement a function in Arbus.h that, given a key K that it is known to be in the tree,
			returns the next key in increasing order. Use recursion. Do not use other data structures nor Iterator*/
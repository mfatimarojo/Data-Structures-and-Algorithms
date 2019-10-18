#include <iostream>
#include <stdio.h>


/*
Problem  #4. (0.5 points) The following alogrithms receive an array of integers with n>=2 elements.
				1. Return boolean b if there is an element in the array which index is 3 times its value.
				2. Return an integer s which represents the max sum between two different elements of the array.
*/
bool isElementThreeTimesIndex(int a[], int N) {
	int i = 0;
	while (i < N) {
		if (a[i] == 3 * i) return true;
		i++;
	}

	return false;
}

int maxSumOfTwoElements(int a[], int N) {
	if (N == 0 || N == 1) return 0;

	int s = 0;
	int i = 0;
	int j = 1;

	while (i < N - 1) {
		if ((a[i] != a[j]) && ((a[i] + a[j]) > s)) {
			s = a[i] + a[j];
			j++;
		}
		else j++;

		if (j == N) {
			i++;
			j = i + 1;
		}
	}

	return s;
}

int main() {
	int a[] = {1,2,12,5,3};
	int N = 5;

	// Problem #4.1
	if (isElementThreeTimesIndex(a,N)) std::cout << "There is at least one element which value is three times its index\n";
	else std::cout << "There is no element which value is three times its index\n";
		
	// Problem #4.2
	std::cout << "The max sum of two different elements is: " << maxSumOfTwoElements(a, N) << std::endl;

	return 0;
}
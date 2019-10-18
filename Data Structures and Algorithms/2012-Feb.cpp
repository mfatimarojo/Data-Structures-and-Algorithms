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

/*
Problem #5. (4 points) It is said that an array of integers with n>=1 elements is "mountain" if its values increase
strictly up to a certain index called "summit", and then decrease strictly. Mountain arrays whose summit is the first
or the last index are allowed. Implement an interative algorithm which, given a mountain array, returns its summit.
*/
int summit(int a[], int N) {
	if (N == 0) return -1;
	if (N == 1) return 0;

	bool increase = true;
	int i = 0;
	
	//Remember, we are assuming that the array given is already a mountain array
	while (i < N-1) {
		if (a[i] > a[i + 1]) return i;
		i++;
	}

	return i;
}


int main() {
	int a1[] = {1,2,12,5,3};
	int N1 = 5;

	// Problem #4.1
	if (isElementThreeTimesIndex(a1,N1)) std::cout << "There is at least one element which value is three times its index\n";
	else std::cout << "There is no element which value is three times its index\n";
		
	// Problem #4.2
	std::cout << "The max sum of two different elements is: " << maxSumOfTwoElements(a1, N1) << std::endl;

	// Problem #5
	int a2[] = { 1,2,3,4,3,2,1 };
	int a3[] = { 3,2,1 };
	int a4[] = { 1,2,3,4};
	int N2 = 7;
	int N3 = 3;
	int N4 = 4;
	std::cout << "The summit of the array is: " << summit(a2, N2) << std::endl;
	std::cout << "The summit of the array is: " << summit(a3, N3) << std::endl;
	std::cout << "The summit of the array is: " << summit(a4, N4) << std::endl;

	return 0;
}
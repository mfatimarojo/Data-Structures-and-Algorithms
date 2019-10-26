#include <iostream>
#include <stdio.h>
#include <string>
#include "TADs/Arbin.h"

typedef string Character;

int repMinElement(int a[], int N);

void main() {
	int a1[] = { 1,2,12,5,3 };
	int a2[] = { 1,2,3,4,3,2,1 };
	int a3[] = { 3,2,1 };
	int a4[] = { 1,2,3,4 };
	int a5[] = { -4,-2, 2, 6, 7 };
	int a6[] = { 1, 2, 3, 4, 5 };
	int N1 = 5;
	int N2 = 7;
	int N3 = 3;
	int N4 = 4;
	int N5 = 5;
	// Problem #1
	std::cout << "The minimum number appears " << repMinElement(a1, N1) << " times.\n";
	std::cout << "The minimum number appears " << repMinElement(a2, N2) << " times.\n";
	std::cout << "The minimum number appears " << repMinElement(a3, N3) << " times.\n";
	std::cout << "The minimum number appears " << repMinElement(a4, N4) << " times.\n";
	std::cout << "The minimum number appears " << repMinElement(a5, N5) << " times.\n";
	std::cout << "The minimum number appears " << repMinElement(NULL, 0) << " times.\n";
}

/*
Problem #1	(3.5 points). Implement an iterative algorithm O(n) which receives a non-empty array of integers
			and returns the number of times that the minimum element appears.
*/
int repMinElement(int a[], int N) {
	if (N == 0) return 0;
	if (N == 1) return 1;

	int min = a[0];
	int result = 1;

	int i = 1;
	while (i < N) {
		if (a[i] == min) result++;
		else if (a[i] < min) {
			min = a[i];
			result = 1;
		}
		i++;
	}

	return result;
}

/*
Problem #2	(3 points). There is an Arbin<Character> tree which nodes can be "dragon", "princess" or none of them.
			It is said that a node is "accessible" if there is path from the root to a pricess-node with no dragons
			in between.
			1.	Implement a function that returns the number of accessible princess-nodes
			2.	Implement a function that returns the accessible princess-node closest to the root
*/
/*int numAccessiblePrincessNodes(Arbin<Character> a, int result, bool dragon) {
	int izq = 0;
	int dcho = 0;
	if (a.esVacio() || a.raiz() == "Dragon") return 0;

	else {
		if (a.raiz() == "Princesa") result++;
		if (!a.hijoIz().esVacio())
			izq += numAccessiblePrincessNodes(a.hijoIz(), result, dragon);
		if (!a.hijoDer().esVacio())
			dcho += numAccessiblePrincessNodes(a.hijoDer(), result, dragon);
	}
	
	result += izq + dcho;

	return result;
}*/
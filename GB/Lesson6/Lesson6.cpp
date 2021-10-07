// TestProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

void _fastcall PrintArray(int *pArr, size_t dwSize)
{
	for (size_t i = 0; i < dwSize; i++)
		printf("%d\t", pArr[i]);
	printf("\n");
}

// ------------------------------------------
// TASK 6.1----------------------------------
// ------------------------------------------

#define SwapINT(a, b) {(a) ^= (b); (b) ^= (a); (a) ^= (b);}

/// 6.1 Task
// buble sort
void task6_1()
{
	printf("\nTask 6.1\n");
	int nArr[]{ 1, 9, 2, 5, 7, 6, 4, 3, 8 };
	int nLength = sizeof(nArr) / sizeof(nArr[0]);


	PrintArray(nArr, nLength);

	// Sort in ascending order
	for (size_t i = 1; i < nLength; i++)
	{
		for (size_t j = 0; j < nLength; j++)
		{
			if (nArr[i] < nArr[j])
				SwapINT(nArr[i], nArr[j]);
		}
	}

	PrintArray(nArr, nLength);
}

// ------------------------------------------
// TASK 6.3----------------------------------
// ------------------------------------------

// Function: f(x) = sqrt(|x|) + 5*x**3
float FuncTPK(float x)
{
	return x;
}


// Тask 6.3
void task6_3()
{
	/*/
	printf("\nTask 4.2.1\n");

	int nExpo = ExpoVarOne(5, 5);
	// 3125
	printf("nExpo = %d\n", nExpo);

	nExpo = ExpoVarOne(2, 16);
	// 65536
	printf("nExpo = %d", nExpo);
	*/
}

int main()
{
	setlocale(0, "");

	// Тask 6.1
	task6_1();

	// Тask 6.3
	task6_3();

    return 0;
}


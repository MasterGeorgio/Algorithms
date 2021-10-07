// TestProject.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

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
	size_t nLength = sizeof(nArr) / sizeof(nArr[0]);


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
float FuncTPK(float fX)
{
	return sqrt(fabs(fX)) + 5 * pow(fX, 3);
}

#define LENGTH 11

// Тask 6.3
void task6_3()
{
	printf("\nTask 6.3\n");

	float nArr[LENGTH]{0};

	for (size_t i = 0; i < LENGTH; i++)
	{
		printf("Enter number: ");
		scanf_s("%f", &nArr[i]);
	}

	for (int i = LENGTH - 1; i >= 0; i--)
	{
		if (FuncTPK(nArr[i]) > 400.)
			printf("Excess result for %.2f\n", nArr[i]);
	}
}
/*Example
Task 6.3
Enter number: 80
Enter number: 1
Enter number: 50
Excess result for 50,00
Excess result for 80,00
*/
// ------------------------------------------

int main()
{
	setlocale(0, "");

	// Тask 6.1
	task6_1();

	// Тask 6.3
	task6_3();

    return 0;
}


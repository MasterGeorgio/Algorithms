// TestProject.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void _fastcall PrintArray(int *pArr, size_t dwSize)
{
	for (size_t i = 0; i < dwSize; i++)
		printf("%d  ", pArr[i]);
	printf("\n");
}

void _fastcall swapInt(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

// ------------------------------------------
// TASK 7.1 ---------------------------------
// ------------------------------------------

// Quick sort
void qs(int *pnArr, int nFirst, int nLast)
{
	int nLeft  = nFirst;
	int nRigth = nLast;

	int nPivot = pnArr[(nFirst + nLast) / 2];

	// One step
	do
	{
		while (pnArr[nLeft]  < nPivot) nLeft++;
		while (pnArr[nRigth] > nPivot) nRigth--;

		if (nLeft <= nRigth)
		{
			swapInt(&pnArr[nLeft], &pnArr[nRigth]);
			nLeft++;
			nRigth--;
		}

	} while (nLeft <= nRigth);

	// Two step
	if (nLeft < nLast)
		qs(pnArr, nLeft, nLast);
	if (nFirst < nRigth)
		qs(pnArr, nFirst, nRigth);
}



// Quick sort Enhancement
void qsEnhancement(int *pnArr, size_t dwLength)
{
	int nFirst  = pnArr[0];
	int nLast   = pnArr[dwLength - 1];

	if (dwLength <= 10)
	{
		//.. sort insert
		return;
	}

	int nCentr = (nFirst + nLast) / 2;
	int nMiddle = pnArr[nCentr];

	// Define median
	if ((nMiddle <= nFirst) && (nFirst <= nLast))
	{
		swapInt(&pnArr[0], &pnArr[nCentr]);
		swapInt(&nFirst, &nMiddle);
	}
	if ((nMiddle <= nLast) && (nLast <= nFirst))
	{
		swapInt(&pnArr[dwLength - 1], &pnArr[nCentr]);
		swapInt(&nLast, &nMiddle);
	}

	qs(pnArr, 0, dwLength - 1);
}

/// 7.1 Task
// sort
void task7_1()
{
	printf("\nTask 6.1\n");
	int anArr[]{ 1, 9, 2, 5, 7, 6, 4, 7, 6, 4, 3, 8, 3, 8 };
	size_t dwLength = sizeof(anArr) / sizeof(anArr[0]);

	PrintArray(anArr, dwLength);

	/**
	qs(anArr, 0, dwLength - 1);

	PrintArray(anArr, dwLength);
	/**/

	qsEnhancement(anArr, dwLength);

	PrintArray(anArr, dwLength);
}


// ------------------------------------------
// TASK 7.2 ---------------------------------
// ------------------------------------------
// Bucket sort
void bucketSort(int *pnArr, size_t dwLength)
{
	const size_t len = dwLength;
	const size_t b   = 10;


}


/// 7.2 Task
// sort
void task7_2()
{

	 
}

#define T uint8_t

#define SIZE 1000

T g_Stack[SIZE] = { 0 };
int g_nCursor = -1;

bool push(T ucData)
{
	if (g_nCursor < SIZE)
	{
		g_Stack[++g_nCursor] = ucData;
		return true;
	}

	return false;
}

T pop()
{
	if (g_nCursor != -1)
		return g_Stack[g_nCursor--];

	return 0;
}

void Tack9_2()
{
	int nValue = 22;

	while (nValue != 0)
	{

		if (g_nCursor != -1)
			push(nValue & 1);

		nValue >>= 1;
	}

	printf("Value dec: %d\n", nValue);
	printf("Value bin: ");
	while (g_nCursor != -1)
		printf("%d", pop());

}



int main()
{
	setlocale(0, "");

	// Тask 9.2
	Tack9_2();

	system("pause");
    return 0;
}


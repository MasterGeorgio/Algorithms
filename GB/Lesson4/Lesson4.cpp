// TestProject.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

// TASK 4.1----------------------------------
// dec to hex
void DecToHex(uint32_t dwValue)
{
	if (!dwValue)
		return ;

	// Move down to end
	DecToHex(dwValue >>= 1);
	// Move up to beg, therefore print
	printf("%d", dwValue & 1);
}

// �ask 1
void task4_1()
{
	printf("\nTask 4.1\n");
	// ���� 01110110
	DecToHex(118);
	printf("\n");
}

// TASK 4.2.1--------------------------------
// Recursively
int ExpoVarOne(int a, int b)
{
	if (b == 0)
		return 1;
	b--;

	return a * ExpoVarOne(a, b);
}

// �ask 4.2.1
void task4_2_1()
{
	printf("\nTask 4.2.1\n");

	int nExpo = ExpoVarOne(5, 5);
	// 3125
	printf("nExpo = %d\n", nExpo);

	nExpo = ExpoVarOne(2, 16);
	// 65536
	printf("nExpo = %d", nExpo);
}

// TASK 4.2.2--------------------------------
// Recursively, using the degree parity property
int ExpoVarTwo(int a, int b)
{
	if (b == 0)
		return 1;

	if (!(b & 1))
		return a * ExpoVarTwo(a, b - 1);

	int nRes = ExpoVarTwo(a, b >> 1);
	return nRes * nRes;
}
// Task 4.2.2
void task4_2_2()
{
	printf("\n\nTask 4.2.2\n");

	int nExpo = ExpoVarOne(5, 5);
	// 3125
	printf("nExpo = %d\n", nExpo);

	nExpo = ExpoVarOne(2, 16);
	// 65536
	printf("nExpo = %d", nExpo);

}

// TASK 4.3----------------------------------
// Task 4.3
void task4_3()
{
	printf("\n\nTask 4.3\n");
}


int main()
{
	setlocale(0, "");

	// �ask 1
	task4_1();

	// �ask 4.2.1
	task4_2_1();

	// Task 4.2.2
	task4_2_2();

	// Task 4.3
	task4_3();

    return 0;
}


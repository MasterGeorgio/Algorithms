
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdint.h>


//-----------------
// Task 15.1
//-----------------
uint8_t Checksum8(uint8_t *pucData, size_t dwSize)
{
	uint8_t ucRes = 0;
	while (dwSize--)
		ucRes += *pucData++;

	return ucRes;
}

//-----------------
void task15_1()
{
	printf("Task 15.1\n");

	uint8_t *mass = new uint8_t[4];

	for (size_t i = 0; i < sizeof(mass); i++)
	{
		mass[i] = i << 1;
		printf("%02X\t", mass[i]);
	}
	printf("\n");

	printf("Result: %02X", Checksum8(mass, sizeof(mass)));
	printf("\n");
}
//-----------------


//-----------------
// Task 15.1
//-----------------
void task15_2()
{
	printf("Task 15.2\n");

	int nCoin[] = { 50, 10, 5, 2, 1 };

	int nPrice = 98;

	for (size_t i = 0; i < sizeof(nCoin) / sizeof(int); i++)
	{
		if (nPrice / nCoin[i])
		{
			printf("Coin: %d. Count %d. Price %d\n", nCoin[i], nPrice / nCoin[i], nPrice % nCoin[i]);
			nPrice %= nCoin[i];
		}

	}
}
//-----------------

int main()
{
	setlocale(0, "");

	// Òask 15.1
	task15_1();

	// Òask 15.2
	task15_2();

	system("pause");
	return 0;
}